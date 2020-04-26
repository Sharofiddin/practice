#include <vector>
#include <iostream>
#include <string>

#include "8-2.h"
using std::cerr;
using std::cout;
using std::string;
using std::vector;

bool test_equal()
{
    cout << "testing equal ...\n";
    vector<int> src;
    src.push_back(1);
    src.push_back(1);
    src.push_back(3);

    vector<int> tar;
    tar.push_back(1);
    tar.push_back(2);
    tar.push_back(3);

    if (equal(src.begin(), src.end(), tar.begin()))
    {
        cerr << "{1,1,3} comapring to {1,2,3} returning true";
        return false;
    }

    tar.clear();
    tar.push_back(1);
    tar.push_back(1);
    tar.push_back(3);

    if (!equal(src.begin(), src.end(), tar.begin()))
    {
        cerr << "{1,1,3} comapring to {1,1,3} returning false\n";
        return false;
    }

    return true;
}

bool test_find()
{
    cout << "testing find ...\n";
    string src = "assalom";
    char tar = 's';
    string::iterator it = find(src.begin(), src.end(), tar);
    if (it == src.end())
    {
        cerr << "Test failed find(\"assalom\", 's') returning end()\n";
        return false;
    }

    tar = 'r';
    it = find(src.begin(), src.end(), tar);
    if (it != src.end())
    {
        cerr << "Test failed find(\"assalom\", 'r') is not returning end()\n";
        return false;
    }

    return true;
}

bool test_copy()
{
    cout << "testing copy ... \n";
    string tar;
    string src = "qwerty";
    tar.resize(src.size());
    copy(src.begin(), src.end(), tar.begin());
    return tar == src;
}

int main(int argc, char const *argv[])
{
    if (!test_equal())
    {
        cerr << "equal( b , e, d ) function test is failed\n";
        return 1;
    }
    else
    {
        cout << "equal( b , e, d ) function test is passed\n";
    }

    if (!test_find())
    {
        cerr << "find( b , e, t ) function test is failed\n";
        return 1;
    }
    else
    {
        cout << "find( b , e, t ) function test is passed\n";
    }

    if (!test_copy())
    {
        cerr << "copy(b,e,d) function test is failed\n";
        return 1;
    }
    else
    {
        cout << "copy( b , e, d ) function test is passed\n";
    }
    

    return 0;
}