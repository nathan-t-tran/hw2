#include <string>
#include <sstream>
#include <iostream> 
#include "movie.h"
#include "product.h"
#include "util.h"

using namespace std;

Movie::Movie(string name, double price, int quantity, string genre, string rating) : Product(category_, name, price, quantity)
{
    genre_ = genre;
    rating_ = rating;
}

set<string> Movie::keywords() const
{
    set<string> genreSet = parseStringToWords(genre_);
    set<string> keyWords = setUnion(keyWords, genreSet);
    keyWords.insert(rating_);

    return keyWords;
}

string Movie::displayString() const
{
    ostringstream oss;
    oss << name_ << "\n";
    oss << "Genre: " << genre_ << " Rating: " << rating_ << "\n";
    oss << price_ << " USD, " << qty_ << " left.\n";
    return oss.str();
}

void Movie::dump(ostream& os) const
{
    os << "moving\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << "\n";
}