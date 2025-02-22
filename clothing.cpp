#include <string>
#include <sstream>
#include <iostream> 
#include "clothing.h"
#include "product.h"
#include "util.h"

using namespace std;


//Initializes Book object using Product, with present category
Clothing::Clothing(string name, double price, int quantity, string brand, string size) : Product("clothing", name, price, quantity)
{
    brand_ = brand;
    size_ = size;
}

set<string> Clothing::keywords() const
{
   set<string> brandSet = parseStringToWords(brand_);
   set<string> keyWords = parseStringToWords(name_);
   keyWords = setUnion(brandSet, keyWords);
   keyWords.insert(size_);

   return keyWords;
}

string Clothing::displayString() const
{
    ostringstream oss;
    oss << name_ << "\n";
    oss << "Size: " << size_ << " Brand: " << brand_ << "\n";
    oss << price_ << " USD, " << qty_ << " left.\n";
    return oss.str();
}

void Clothing::dump(std::ostream& os) const 
{
    os << "clothing\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << size_ << "\n" << brand_ << "\n";
}