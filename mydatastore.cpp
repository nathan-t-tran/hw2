#include <iostream>
#include "mydatastore.h"
#include "util.h"

using namespace std;

MyDataStore::MyDataStore(){}

MyDataStore::~MyDataStore()
{
    //deletes products from vector
    for (vector<Product*>::iterator it = products_.begin(); it != products_.end(); ++it)
    {
        delete *it;
    }

    //deletes users
    for (map<string, User*>:: iterator it = users_.begin(); it != users_.end(); ++it)
    {
        delete it->second;
    }
}

void MyDataStore::addProduct(Product* p)
{
    products_.push_back(p); //inserts product
    set<string> keywords = p->keywords(); //gets product keywords

    for (set<string>::iterator it = keywords.begin(); it != keywords.end(); ++it) 
    {
        keywordMap_[*it].insert(p);  // Map keyword to product
    }
}

void MyDataStore::addUser(User* u)
{
    users_.insert({u->getName(), u}); //inserts user with name
}

vector<Product*> MyDataStore::search(vector<string>& terms, int type) 
{
    if (terms.empty()) return vector<Product*>();  // No terms provided

    set<Product*> resultSet; //set to return with results
    bool firstTerm = true;  // Helps with AND search

    for (vector<string>::iterator it = terms.begin(); it != terms.end(); ++it) 
    {
        string term = convToLower(*it);

        if (keywordMap_.find(term) == keywordMap_.end()) 
        {
            if (type == 0) return vector<Product*>();  // AND search: no match
            continue;  // OR search: skip this term
        }

        set<Product*> keywordResults = keywordMap_[term];

        if (firstTerm) 
        {
            resultSet = keywordResults;  // Initialize first term result
            firstTerm = false;
        } else 
        {
            if (type == 0) resultSet = setIntersection(resultSet, keywordResults); // AND
            else resultSet = setUnion(resultSet, keywordResults);  // OR
        }
    }

    return vector<Product*>(resultSet.begin(), resultSet.end()); //returns result of search
}


void MyDataStore::dump(ostream& ofile)
{
    //gets products
    ofile << "<products>\n";
    for (vector<Product*>::iterator it = products_.begin(); it != products_.end(); ++it) 
    {
        (*it)->dump(ofile);
    }
    ofile << "</products>\n";

    //gets users
    ofile << "<users>\n";
    for (map<string, User*>::iterator it = users_.begin(); it != users_.end(); ++it) {
        it->second->dump(ofile);
    }
    ofile << "</users>\n";
}

void MyDataStore::addToCart(string username, Product* p) 
{
    map<string, User*>::iterator userIt = users_.find(username);
    if (userIt == users_.end()) 
    {
        cout << "Invalid request" << endl;
        return;
    }
    carts_[username].push_back(p);  
}

void MyDataStore::viewCart(string username) 
{
    if (carts_.find(username) == carts_.end()) 
    {
        cout << "Invalid username" << endl;
        return;
    }

    vector<Product*>& cart = carts_[username];
    for (size_t i = 0; i < cart.size(); ++i) 
    {
        cout << "Item " << (i + 1) << ":" << endl;
        cout << cart[i]->displayString() << endl;
    }
}

void MyDataStore::buyCart(string username) 
{
    if (users_.find(username) == users_.end()) 
    {
        cout << "Invalid username" << endl;
        return;
    }

    User* user = users_[username]; //gets the user
    vector<Product*>& cart = carts_[username]; //gets the cart under the user
    vector<Product*> newCart;  // Holds products that couldn't be purchased

    for (vector<Product*>::iterator it = cart.begin(); it != cart.end(); ) {
        Product* p = *it;
        if (p->getQty() > 0 && user->getBalance() >= p->getPrice()) 
        {
            p->subtractQty(1);
            user->deductAmount(p->getPrice());
            it = cart.erase(it); 
        } 
        else 
        {
            ++it; // 
        }
    }
    

    carts_[username] = newCart;  // Update cart with unpurchased items
}


