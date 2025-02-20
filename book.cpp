#include <string>
#include <sstream>
#include <iostream> 
#include "book.h"
#include "product.h"
#include "util.h"

using namespace std;


//Initializes Book object using Product, with present category
Book::Book(string name, double price, int quantity, string author, string ISBN) : Product(category_, name, price, quantity)
{
    author_ = author;
    ISBN_ = ISBN;
}

set<string> Book::keywords() const
{
   set<string> authorSet = parseStringToWords(author_);
   set<string> nameSet = parseStringToWords(name_);
   authorSet = setUnion(authorSet, nameSet);
   set<string> keyWords = setUnion(keyWords, authorSet);
   keyWords.insert(ISBN_);

   return keyWords;
}

string Book::displayString() const
{
    ostringstream oss;
    oss << name_ << "\n";
    oss << "Author: " << author_ << " ISBN: " << ISBN_ << "\n";
    oss << price_ << " USD, " << qty_ << " left in stock.\n";
    return oss.str();
}

void Book::dump(std::ostream& os) const 
{
    os << "book\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << ISBN_ << "\n" << author_ << "\n";
}