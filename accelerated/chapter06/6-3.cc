#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::copy;
int main()
{
	vector<int> u(10, 100);
	vector<int> v;
	std::cout << "before copy" << std::endl; 
	copy(u.begin(), u.end(), v.begin());
	std::cout <<"after copy" <<std::endl;
	for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++){
		std::cout << *it << std::endl;
	}
	return 0;
}
