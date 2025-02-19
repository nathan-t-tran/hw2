#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

class Book: public Product
{
public:
    Book(string name, double price, int quantity, string category, string author, string ISBN);
    set<string> keywords();
    string displayString();

private:
    string author;
    string ISBN;
};

#endif