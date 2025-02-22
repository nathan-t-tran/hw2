#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iostream>
#include "product.h"

using namespace std;

class Movie: public Product
{
public:
    Movie(string name, double price, int quantity, string genre, string rating);
    set<string> keywords() const override;
    string displayString() const override;
    void dump(ostream& os) const override;

private:
    string genre_;
    string rating_;
    string category_ = "movie";
};

#endif