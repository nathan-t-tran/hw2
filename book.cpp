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

set<string> Book::keywords()
{
   set<string> authorSet = parseStringToWords(author_);
   set<string> nameSet = parseStringToWords(name_);
   authorSet = setUnion(authorSet, nameSet);
   keyWords_ = setUnion(keyWords_, authorSet);
   keyWords_.insert(ISBN_);

   return keyWords_;
}

string Book::displayString()
{
    
}