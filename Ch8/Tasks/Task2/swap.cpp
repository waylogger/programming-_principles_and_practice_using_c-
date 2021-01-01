#include <std_lib_facilities.h>

void swap_v (int a ,int b ) 	{

int temp;

temp = a, a=b;
b=temp;
			}


void swap_r (int&a,int&b) {
int temp;
temp = a, a=b;
b=temp;
			}

void swap_cr (const int&a,const int&b) 	{
int temp;
int x = a;
int y = b;
temp = x, x=y;
y=temp;
			}

int main () {
	int x =7;
	int y =9;
	const int cx =7;
	const int cy =9;
	double dx = 7.7;
	double dy = 9.9;
	swap_cr(7.7,9.9);
	cout << "x - " << dx
		 << " y - " << dy << '\n';
	keep_window_open();
	
}