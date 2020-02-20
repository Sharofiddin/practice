#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using std::vector;
using std::copy;
using std::back_inserter;
int main()
{
	vector<int> u(2000000, 100);
	vector<int> v;
	std::cout << "before copy" << std::endl; 
	copy(u.begin(), u.end(), back_inserter(v));
	std::cout <<"after copy" <<std::endl;
	
	return 0;
}
/*
real    0m0.066s
user    0m0.054s
sys     0m0.012s
*/