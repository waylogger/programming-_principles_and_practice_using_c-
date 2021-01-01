#include <std_lib_facilities.h>


double file_stream_in ()
{
	double sum = 0;
	string iname;
	cin >> iname;
	ifstream ist {iname};
	for (double d; ist >> d;) {sum+=d;}
	return sum;
}

int main ()
{
	vector<double>p;
	double s = file_stream_in();
	cout << s << '\n';
	keep_window_open();
	
}