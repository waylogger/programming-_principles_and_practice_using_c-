// Решение квадратных уравнений
#include <std_lib_facilities.h>

int main () {
double a = 1;
double b = 1;
double c = 1;
double D = 1;

double x = 1;
double x1 = 1;
double x2 = 1;

cout << "Vvedite ishodnie znacheniya\n";
cout << "a= ";
cin >> a;
'\n';

cout << "b= ";
cin >> b;
'\n';

cout << "c= ";
cin >> c;
'\n';

cout 	<< "Uravnenuie tipa - ax^2+bx+c=0\n"
		<< "Formula - D=b^2-4ac\n"
		<< "IF D>0\n"
		<< "Formula kornya x1=(-b+sqrl(D))/2a \n"
		<< "Formula kornya x2=(-b-sqrl(D))/2a \n"
		<< "IF D=0\n"
		<< "Formula kornya x=(-b-+sqrl(D))/2a\n"
		<< "IF D<0\n"
		<< "Uravnenuie tipa - ax^2+bx+c=0 ne imeet deystvitelnih korney\n";

		
cout	<< a << "x^2 + " << b << "x +" << c << " = 0\n";
D=(b*b)-(4*a*c);
cout 	<< "D=" << b << "^2-4*" << a << "*" << c << " = " << D << "\n";

if (a==0)
cout << "Uravnenie ne mozhet bit resheno, tak kak bolshiy chlen raven 0\n";

if (a!=0)
if (D<0)
	cout << "Uravnenuie ne imeet deystvitelnih korney\n";

if (a!=0)
if (D>0)
	x1=(-b+sqrt(D))/(2*a);

if (a!=0)
if (D>0)
	
	x2=(-b-sqrt(D))/(2*a);
	
if (a!=0)
if (D>0)
cout 	<< "x1 = " 
		<< " (-" 
		<< b 
		<< "+" 
		<< "sqrt" 
		<< "(" 
		<< D
		<< "))"
		<< "/(2*"
		<< a
		<< ")"
		<< " = "
		<< x1
		<< "\nx2 = (" 
		<< "-" 
		<< b 
		<< "-" 
		<< "sqrt" 
		<< "(" 
		<< D
		<< "))"
		<< "/(2*"
		<< a
		<< ")"
		<< " = "
		<< x2
		<< "\n";
	
	if (a!=0)		
	if (D=0)
	x=(-b-sqrt(D))/(2*a);

	if (a!=0)
	if (D>0)
cout 	<< "x = " 
		<< " (-" 
		<< b 
		<< "+-" 
		<< "sqrt" 
		<< "(" 
		<< D
		<< "))"
		<< "/(2*"
		<< a
		<< ")"
		<< " = "
		<< x
		<< "\n";
		
keep_window_open ();
	
}