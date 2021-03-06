#include "../std_lib_facilities.h"

const double m_to_cm = 100;
const double in_to_cm = 2.54;
const double ft_to_in = 12;

int main()
{
	double val;
	string unit;
	double cm = 0;
	double m = 0;
	double in = 0;
	double ft = 0.0;
	
	vector<double> units;
	while( cin >> val ){
		if(val <= 0 ){
			cout << "Please eneter positive value.\n";
			continue;
		}
		cin >> unit;
		if( unit == "cm" ){
			cm = val;
			m = val / m_to_cm;
			in = val / in_to_cm;
			ft = in / ft_to_in;
		} else if(unit == "in"){
			in = val;
			cm = in * in_to_cm;
			ft = in / ft_to_in;
			m = cm / m_to_cm;
		} else if(unit == "ft"){
			ft = val;
			in = ft * ft_to_in;
			cm = in * in_to_cm;
			m = cm / m_to_cm;
		} else if(unit == "m"){
			m = val;
			cm = m * m_to_cm;
			in = cm / in_to_cm;
		        ft = in / ft_to_in;
		} else{
			 cout << "please enter correct unit (cm, m, ft, in)\n";
			 continue; 
		}

		units.push_back(m);
		cout <<"Entered: "<< val << " " << unit << endl;
		cout <<"Convertation results: " << cm << " cm, " << m << " m, " << ft << " ft, " << in << " in.\n";
	}
	sort(units.begin(), units.end());
	cout <<"All enetered units(sorted):\n";
	for(vector<double>::const_iterator it= units.begin(); it != units.end(); it++){
		cout << *it <<"m\n";
	}
	cout <<"Max enetered: " << *(units.end()-1) << "m" << endl;
	cout <<"Min enetered: " << *(units.begin()) << "m" << endl;
	cout <<"Sum: " << accumulate(units.begin(), units.end(), 0) << "m" << endl;
	return 0;
}
       				


			
			
