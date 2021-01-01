#include <std_lib_facilities.h>

int main () {

int c_1 = 0;
int c_5 = 0;
int c_10 = 0;
int c_25 = 0;
int c_50 = 0;
double double_sum = 0;
int int_sum = 0;

cout << "How much 1-cents coin you have?\n";
cin >> c_1;

cout << "\nHow much 5-cents coin you have?\n";
cin >> c_5;

cout << "\nHow much 10-cents coin you have?\n";
cin >> c_10;

cout << "\nHow much 25-cents coin you have?\n";
cin >> c_25;

cout << "\nHow much 50-cents coin you have?\n";
cin >> c_50;


if (c_1==1)
	cout << "You have " << c_1 << " 1-cent coin\n";
else
	cout << "You have " << c_1 << " 1-cents coin\n";


if (c_5==1)
	cout << "You have " << c_5 << " 5-cent coin\n";
else
	cout << "You have " << c_5 << " 5-cents coin\n";


if (c_10==1)
	cout << "You have " << c_10 << " 10-cent coin\n";
else
	cout << "You have " << c_10 << " 10-cents coin\n";


if (c_25==1)
	cout << "You have " << c_25 << " 25-cent coin\n";
else
	cout << "You have " << c_25 << " 25-cents coin\n";


if (c_50==1)
	cout << "You have " << c_50 << " 50-cent coin\n";
else
	cout << "You have " << c_50 << " 50-cents coin\n";

double_sum=(c_1)+(c_5*5)+(c_10*10)+(c_25*25)+(c_50*50);
int_sum=(c_1)+(c_5*5)+(c_10*10)+(c_25*25)+(c_50*50);

cout 	<< "\nVsego ti imeesh = "
	<< double_sum
	<< " cents \n"
	<< "or\n"
	<< double_sum/100
	<< " dollars\n"
	<< "or\n"
	<< int_sum/100
	<< " dollars "
	<< "and "
	<< int_sum%100
	<< " cents\n";

keep_window_open ();
}




