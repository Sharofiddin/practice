#include <iostream>
#include <vector>
#include <ios>
#include <iomanip>
#include <algorithm>

using std::cout;
using std::cin;
using std::streamsize;
using std::setprecision;
using std::sort;
using std::endl;
using std::vector;
int main()
{
	vector<double> values;
	cout << "Enter elements :";
	double x;
	while(cin >> x){
		values.push_back(x);
	}
	cout << endl;
	typedef vector<double>::size_type vec_sz;

	vec_sz size  = values.size();
	if( size == 0 ){
		cout << "Please, enter values.";
		return 1;
	}
	sort(values.begin(), values.end());
	vec_sz mid = size / 2;
	vec_sz lower_quartile = ( mid + 1 ) / 2;
	vec_sz upper_quartile = size - lower_quartile;

	double q1 = mid % 2 == 0 && size % 2 != 0 ? values[lower_quartile] : (values[lower_quartile] + values[lower_quartile -1]) / 2;
        double q2 = size % 2 == 0 ? ( values[mid] + values[ mid -1] ) / 2 : values[mid];
        double q3 = mid % 2 == 0 && size % 2 != 0 ? values[upper_quartile -1] : (values[upper_quartile] + values[upper_quartile - 1]) / 2;	
	streamsize prec = cout.precision();

	cout << "Lower quartile =  " <<  setprecision(3) << q1 << " Median = " << q2 << " Upper quartile = " << q3 << setprecision(prec) << endl;

	return 0;
}

