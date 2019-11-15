#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::copy;
using std::back_inserter;
int main()
{
	vector<int> u(2000000, 100);
	vector<int> v;
	std::cout << "before copy" << std::endl; 
	v.resize(u.size());
	copy(u.begin(), u.end(), v.begin());
	std::cout <<"after copy" <<std::endl;
	return 0;
}
/*
real    0m0.025s
user    0m0.021s
sys     0m0.004s
*/