#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

#include "Student_info.h"
#include "grade.h"

//driver program for grade partitioning examples

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::string;
using std::vector;
using std::max;
bool did_all_hw(const Student_info& student);
vector<Student_info> extract_by_creteria(vector<Student_info>& v, bool creteria(const Student_info&));

int main()
{
        vector<Student_info> vs;
        Student_info s;
        string::size_type maxlen = 0;
        while (read(cin, s)) {
                maxlen = max(maxlen, s.name.size());
                vs.push_back(s);
        }

        sort(vs.begin(), vs.end(), compare);

	vector<Student_info> extracted = extract_by_creteria(vs, pgrade);

	for (int i = 0; i < extracted.size(); ++i)
		cout << extracted[i].name << " " << grade(extracted[i]) << endl;

	return 0;
}
