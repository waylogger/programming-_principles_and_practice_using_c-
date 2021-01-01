#include <std_lib_facilities.h>



int main ()
{
	string oname = "D:\\Programms\\Ch11\\ex\\15\\data\\1.txt";
	ofstream ost {oname};
	for (double d = 1; d<300000;++d) ost << d << ' ';
	
}