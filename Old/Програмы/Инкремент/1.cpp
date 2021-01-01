#include <std_lib_facilities.h>

int 	main () 
{	
int 	a = 0;
int 	b = 0;
int	c = 0;
cin >> a;
while (b<a) 
{
++b;
c=++a;
}
cout << "\n" << c << "\n";
keep_window_open ();	
}