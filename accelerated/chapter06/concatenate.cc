#include <iostream>
#include <vector>
#include <numeric>

using std::cin; using std::cout;
using std::vector; using std::accumulate;
using std::string;


int main()
{
    vector<string> parts;

    for(string s; cin >> s;){
        parts.push_back(s);
    }

    string s = accumulate(parts.begin(), parts.end(), string(""));

    cout << s;
    return 0;
   
}
