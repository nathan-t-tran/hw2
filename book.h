#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

class Book: public Product
{
public:
    Book(string name, double price, int quantity, string author, string ISBN);
    set<string> keywords() const override;
    string displayString() const override;
    void dump(ostream& os) const override;

private:
    string author_;
    string ISBN_;
};

#endif