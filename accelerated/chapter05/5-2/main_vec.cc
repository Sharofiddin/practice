#include <iomanip>
#include <algorithm>
#include "Student_info.h"
#include "grade.h"

using std::cin;		using std::cout;
using std::max;		using std::vector; 
using std::sort;	using std::string;
using std::endl;	using std::setw;
vector<Student_info> extract_fails( std::vector<Student_info>& );
void print(const vector<Student_info> &, string::size_type);
int main()
{
	vector<Student_info> vs;
	Student_info s;
	string::size_type maxlen = 0;
	while(read( cin, s)){
		maxlen = max( maxlen, s.name.size());
		vs.push_back(s);
		}
	vector<Student_info> fails = extract_fails(vs);
	sort(fails.begin(), fails.end(), compare);
	print(fails, maxlen);
	return 0;
}


vector<Student_info> extract_fails( vector<Student_info>& students)
{
	vector<Student_info> fail;
	vector<Student_info>::iterator iter = students.begin();
	while( iter != students.end()){
		if( fgrade(*iter)){
			fail.push_back(*iter);
			iter = students.erase(iter);
		} else
			iter++;
	}
	return fail;
}

void print(const vector<Student_info>& vs, string::size_type maxlen)
{
	cout << endl;
	for(vector<Student_info>::const_iterator iter = vs.begin(); iter != vs.end(); iter++){
		cout << setw(maxlen) << iter->name <<' '<< grade(*iter) << endl;
	}
}
