#ifndef CLOTHING_H
#define CLOTHING_H

#include <string>
#include <iostream>

class Clothing: public Product
{
public: 
    Clothing(string size, string brand);
private:
    string size;
    string brand;
};

#endif