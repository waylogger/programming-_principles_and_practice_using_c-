#include <std_lib_facilities.h>

int main () {

	double max = 0.00001;
	double min = 9800000;
	string izm = " ";
	double a = 0.0001;
	int number = 0;
	
	

	vector <double> qwerty;

	
	while (max||min) {
	
	cout << "Vvelite a i Vvelite edinitsu izm"<< "\n";
	cin >> a;
	qwerty.push_back(a);
	cin >> izm;
	
	
	while (izm!="cm"&&izm!="m"&&izm!="in"&&izm!="ft") 
	{
	cout << "Vvelite a i Vvelite edinitsu izm"<< "\n";
	cin >> a >> izm;
	}

	++number;

	if (izm=="m")
	a=a;
	
	else if (izm=="in")
	a=(a*2.54)/100;

	else if (izm=="ft")
	a=((a*12)*2.54)/100;
	
	else if (izm=="cm")
	a=a/100;	
	
	if (a>max)
	cout<< "Maximum" << "\n";
	
	else
	cout << " " << "\n";

	if (a>max)	
	max=a;
		
	if (a<min)
	cout << "Minimun" << "\n";
	else
	cout << " " << "\n";
	
	if (a<min)	
	min=a;
	
	int i = 0;
	

	cout 	<< number << "\n"
		<< "max= " << max << "\n"
		<< "min= " << min << "\n"
		<< "max+min= " << min+max << "\n";

	sort (qwerty);	
	for (int i =0; i<qwerty.size();++i)
	cout << qwerty[i] << "\n";	
	}
	
}