#include <iostream>
#include <vector>
using std::vector;
int main()
{
	vector<int> u(2000000, 100);
	vector<int> v;
	std::cout << "before copy" << std::endl; 
	v.insert(v.begin(), u.begin(), u.end());
	std::cout <<"after copy" <<std::endl;

	return 0;
}
/*
real    0m0.018s
user    0m0.014s
sys     0m0.005s
*/