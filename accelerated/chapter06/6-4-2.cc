#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using std::vector;
using std::copy;
using std::back_inserter;
int main()
{
	vector<int> u(10, 100);
	vector<int> v;
	std::cout << "before copy" << std::endl; 
	v.resize(u.size());
	copy(u.begin(), u.end(), v.begin());
	std::cout <<"after copy" <<std::endl;
	for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++){
		std::cout << *it << std::endl;
	}
	return 0;
}
