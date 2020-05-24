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

bool pred( char c ){
    return c == 's';
}

char func( char c ){
    return ++c;
}
void test_remove_copy_if()
{
    cout << "testing remove copy if\n";
    string s1 = "sariq";
    string s2;
    s2.resize(s1.size());
    remove_copy_if(s1.begin(), s1.end(), s2.begin(), pred);
    cout << "s2 " << s2 << "\n";
    cout << "end.\n";

}

void test_transform()
{
    cout << "test transform\n";
    string s1 = "abc";
    string s2;
    s2.resize(s1.size());
    transform(s1.begin(), s1.end(), s2.begin(), func);
    cout << "s2 " << s2 << "\n";
    cout << "end\n";
}

void test_accumulate()
{
    cout << "test accumulate ...\n";
    vector<int> vec;
    vec.push_back(10);
    vec.push_back(100);
    vec.push_back(1000);
    int res  = accumulate(vec.begin(), vec.end(), 0);
    if( res == 1110 ){
        cout << "passed\n";
    } else {
        cout <<"not passed\n";
    }
    cout << "end\n";
}

void test_search()
{
    cout <<"testing search ... \n";
    string s1 = "salom";
    string s2 = "alo";
    string s3 =  "mm";
    bool valid = search(s1.begin(), s1.end(), s2.begin(), s2.end())!= s1.end();
    if(!valid)
    {
            cout << "not passed != end() \n";
            return;
    }
    valid = !(search(s1.begin(), s1.end(), s3.begin(), s3.end()) == s1.end());
        if(valid)
        {
            cout << "not passed == end()\n";
            return;
        } 
    vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7 };
    vector<int> v2 = { 3, 4, 5 }; 
    valid = search(v1.begin(), v1.end(), v2.begin(), v2.end()) != v1.end();
    if( !valid )
    {
        cout <<"not passed \n";
        return;
    }
    vector<int> v3 = {9,8};
    valid = search(v1.begin(), v1.end(), v3.begin(), v3.end()) == v1.end();
    if( !valid )
    {
        cout <<"not passed \n";
        return;
    }
    cout << "passed\nend\n";
}

bool find_if_pred_t(string s)
{
    return s == "salom";
}

bool find_if_pred_f(string s)
{
    return s == "xx"; 
}

void test_find_if()
{
    cout << "testing find_if ...\n";
    vector<string> vec = {"salom", "qalay", "hh"};
    if( find_if(vec.begin(), vec.end(), find_if_pred_t) == vec.end())
    {
        cout << "not passed\n";
        return;
    } 
    if( find_if(vec.begin(), vec.end(), find_if_pred_f) != vec.end())
    {
        cout << "not passed\n";
        return;
    } 

    cout << "passed\nend\n";
}

void test_remove_copy()
{
     cout << "testing remove copy ...\n";
     int myints[] = {10,20,30,30,20,10,10,20};               // 10 20 30 30 20 10 10 20
     std::vector<int> myvector (8);

     remove_copy(myints,myints+8,myvector.begin(),20);
     if (find(myvector.begin(), myvector.end(),20) != myvector.end())
     {
         cout << "not passed\n";
         return;
     }

     if(find(myvector.begin(), myvector.end(),30) == myvector.end())
     {
         cout << "not passed\n";
         return;
     }
     cout << "passed\nend\n";
}

void test_remove()
{
    cout << "testing remove ...\n";
    vector<int> vec = {10,20,30,30,20,10,10,20};      // 10 20 30 30 20 10 10 20

    vector<int>::iterator removal_point = remove (vec.begin(), vec.end(), 20);         // 10 30 30 10 10 ?  ?  ?
    vec.erase(removal_point, vec.end());
    for(auto val : vec)
    {
        cout <<" " << val;
    }
    cout <<'\n';
    if( vec.size() != 5 ){
        cout << "not passed\n";
    } else {
        cout << "passed\nend\n";
    }
}

bool IsOdd (int i) { return (i%2)==1; }

void test_partition()
{
    cout << "testing partition ... \n";
    std::vector<int> myvector;

    // set some values:
    for (int i=1; i<8; ++i) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9

    std::vector<int>::iterator bound;
    bound = partition(myvector.begin(), myvector.end(), IsOdd);

    // print out content:
    std::cout << "odd elements:";
    for (std::vector<int>::iterator it=myvector.begin(); it!=bound; ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << "even elements:";
    for (std::vector<int>::iterator it=bound; it!=myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

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
    
    test_remove_copy_if();
    test_transform();
    test_accumulate();
    test_search();
    test_find_if();
    test_remove_copy();
    test_remove();
    test_partition();
    return 0;
}