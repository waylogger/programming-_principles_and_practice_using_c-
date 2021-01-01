#include <std_lib_facilities.h>

const string log_of_errors = "D:\Programms\Ch10\try\basic-fstream\4.txt";
struct Reading
{
	int hour;
	double temperaturs;
};


int main ()
try
{
cout << "Insert file name\n";
string iname;
cin >> iname;
ifstream ist{iname};
if(!ist) error ("Cant open file", iname);

cout << "Insert file name for output\n";
string oname;
cin >> oname;
ofstream ost{oname};
if (!ost) error ("Cant open file", oname);


vector<Reading> temps;
int hour;
double temperature;
while (ist >> hour >> temperature)
{
	if (hour < 0 || 23 < hour) error ("Uncorrect time");
	temps.push_back(Reading{hour,temperature});
}
for (int i = 0; i<temps.size();++i)
	ost << '(' << temps[i].hour << ','
		<< temps[i].temperaturs << ")\n";
}

catch (exception& e)
{
	ofstream er {string log_of_errors};
	er << e.what();
}

catch (...)
{
	ofstream er {string log_of_errors};
	er << "Unknown exception\n";
}



