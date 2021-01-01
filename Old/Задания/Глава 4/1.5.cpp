#include <std_lib_facilities.h>

int main () {

	double max = 0.0001;
	double min = 0.0001;

	while (max||min) {
	double a = 0.0001;
	
	cout << "Vvelite a "<< "\n";
	cin >> a;

	if (a>max)
	cout<< "Maximum" << "\n";
	else
	cout << "  " << "\n";

	if (a>max)	
	max=a;
		
	if (a<min)
	cout << "Minimun" << "\n";
	else
	cout << "  " << "\n";
	
	if (a<min)	
	min=a;
	
	
	}
}