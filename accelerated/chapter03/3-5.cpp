#include <iostream>
#include <ios>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using std::cin;		using std::vector;
using std::cout;	using std::streamsize;
using std::endl;	using std::sort;
using std::string;	using std::setprecision;
int main()
{
	vector<string> names;
	vector<double> grades;
	typedef vector<double>::size_type vec_sz;
	string name;
	vec_sz homework_size;
	cout << "Enter count of homework grades: ";
	cin >> homework_size;
	cout << endl;
	cout << "Enter student name: ";
	while( cin >> name ){
		names.push_back(name);
		cout << endl;
		double midterm , final;
		cout << "Enter midterm and  final exam grades for student: ";
		cin >> midterm >> final;
		cout << endl;
		cout  << "Enter homework grades: ";
		vector<double> homework;
		double x;
		vec_sz hw_count = 0;
		while( hw_count < homework_size ){
			cin >> x;
			homework.push_back(x);
			hw_count++;
			}
		cout << endl;
		vec_sz size = homework.size();
		if( size == 0 ){
			cout << "Please, enter homework grades." <<endl;
			return 1;
		}
		cout << endl;
		vec_sz mid = size / 2;
		sort(homework.begin(), homework.end());
		double midean = size % 2 == 0 ?  (homework[mid] + homework[mid -1 ] ) / 2 : homework[mid];

		grades.push_back( 0.4 * final + 0.2 * midterm + 0.4 * midean );
		cout << "Enter another student name (or end of file for exit): ";
	}

	vec_sz size = grades.size();
	if( size == 0)
	{
		cout << "Please, enter student informations." << endl;
		return 1;
	}
	cout << endl;
	streamsize prec = cout.precision(3);
	for( vec_sz i = 0; i < size; i++ ){
		cout <<"Final grade of  " << names[i] <<" = " << grades[i] << endl;
	}
	cout.precision(prec);
	return 0;
}
	

