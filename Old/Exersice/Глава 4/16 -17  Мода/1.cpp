// вы€вление моды

#include <std_lib_facilities.h>

int main () {

int ch1 = 0;
int ch2 = 0;

int max = 0;
int max2 =0;
string absmax = "-9999999";
string min = "9999999";


string i = " ";


//.............................................

vector<string>rpt;

//.............................................
for 	(string i = " "; cin >> i;)
	rpt.push_back (i);


sort (rpt);
while (ch2<rpt.size ()&&ch1<rpt.size ())
{
	cout 	<< ch1 << " - "
			<< rpt[ch1] << " - "
			<< ch2 << " " << "\n";
				
	if (ch1<rpt.size ()-1)
	if (rpt[ch1]==rpt[ch1+1])
	++ch2;

	if (ch2>max2)
		max=ch1;
	
	if (ch2>max2)
		max2=ch2;

	if (ch1<rpt.size ()-1)
	if (rpt[ch1]!=rpt[ch1+1])
	ch2=0;

if (ch1<rpt.size ()-1)
if (rpt[ch1]>absmax)
	absmax=rpt[ch1];

if (ch1<rpt.size ()-1)
if (rpt[ch1]<min)
	min=rpt[ch1];

	
	++ch1;
}
	
cout << "moda - " << rpt[max] << "\n";
cout << "max - " << absmax << "\n";
cout << "min - " << min << "\n";
keep_window_open ();
}