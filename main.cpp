#include <iostream>
#include "util.cpp"

using namespace std;

int main()
{
    //cout << "hello world" << endl;
    string insert = "baby one two three";
    string insert2 = "baby three four one";

    set<string> s1;
    set<string> s2;

    s1 = parseStringToWords(insert);
    s2 = parseStringToWords(insert2);

    cout << "s1: " << endl;
    for (set<string>:: iterator it = s1.begin(); it != s1.end(); ++it)
    {
        cout << *it << endl;
    }

    cout << "s2: " << endl;
    for (set<string>::iterator it = s2.begin(); it != s2.end(); ++it)
    {
        cout << *it << endl;
    }

    set<string> unionSet = setUnion(s1, s2);

    cout << "unionSet: " << endl;

    for (set<string>::iterator it = unionSet.begin(); it != unionSet.end(); ++it)
    {
        cout << *it << endl;
    }

    set<string> intersectionSet = setIntersection(s1, s2);

    cout << "intersectionSet: " << endl;

    for (set<string>::iterator it = intersectionSet.begin(); it != intersectionSet.end(); ++it)
    {
        cout << *it << endl;
    }

    cout << "done" << endl;
}
