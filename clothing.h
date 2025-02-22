#ifndef CLOTHING_H
#define CLOTHING_H

#include <string>
#include <iostream>
#include "product.h"

using namespace std;

class Clothing: public Product
{
public: 
    Clothing(string name, double price, int quantity, string brand, string size);
    set<string> keywords() const override;
    string displayString() const override;
    void dump(std::ostream& os) const override;
private:
    string size_;
    string brand_;
    string category_ = "clothing";
};

#endif