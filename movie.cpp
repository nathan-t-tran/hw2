#include <string>
#include <sstream>
#include <iostream> 
#include "movie.h"
#include "product.h"
#include "util.h"

using namespace std;

Movie::Movie(string name, double price, int quantity, string genre, string rating) : Product("movie", name, price, quantity)
{
    genre_ = genre;
    rating_ = rating;
}

set<string> Movie::keywords() const
{
    set<string> genreSet = parseStringToWords(genre_);
    set<string> keyWords = parseStringToWords(name_);
    keyWords = setUnion(genreSet, keyWords);
    keyWords.insert(rating_);

    return keyWords;
}

string Movie::displayString() const
{
    ostringstream oss;
    oss << name_ << "\n";
    oss << "Genre: " << genre_ << "Rating: " << rating_ << "\n";
    oss << price_ << " USD, " << qty_ << " left.\n";
    return oss.str();
}

void Movie::dump(ostream& os) const
{
    os << "movie\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << "\n";
}