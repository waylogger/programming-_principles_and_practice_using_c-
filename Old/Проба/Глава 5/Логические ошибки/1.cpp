#include <std_lib_facilities.h>

int main ()
try
{

vector<double>temps;

for (double temp = 0; cin >> temp;)
temps.push_back (temp);

double sum = 0;
double max = -271;
double min = 1000000000;

int no_of_temps = 0;

for (int x : temps)
{
++no_of_temps;
if (x > max) max = x;
if (x < min) min = x;
sum += x;
}

cout 	<< "\nMax = " << max << "\n"
	<< "Min = " << min << "\n"
	<< "Sum = " << sum/no_of_temps << "\n";
}
catch (...)
{
cerr << "Ups....\n";
}
