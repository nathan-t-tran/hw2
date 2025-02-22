#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include "datastore.h"
#include "product.h"
#include "user.h"
#include <vector>
#include <map>
#include <set>

using namespace std;

class MyDataStore : public DataStore 
{
public:
    MyDataStore();
    ~MyDataStore();

    void addProduct(Product* p) override;
    void addUser(User* u) override;
    vector<Product*> search(vector<string>& terms, int type) override;
    void dump(ostream& ofile) override;

    void addToCart(string username, Product* p);
    void viewCart(std::string username);
    void buyCart(std::string username);

private:
    vector<Product*> products_;  // Stores all products
    map<string, User*> users_;  // Maps usernames to users
    map<string, vector<Product*>> carts_;  // Shopping carts
    map<string, set<Product*>> keywordMap_; //holds the keywords
};

#endif
