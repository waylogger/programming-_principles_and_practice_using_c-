
#include <std_lib_facilities.h>

int main ()
try
{
setlocale (0, "");
cout << "Число для вычисления факториала\n";
int x= 0;
int y= 1;


cin >> x;
if (x<0) error ("Неположительный x\n");

while (x>0)
{
y*=x;
--x;
}

if (x=0) y=1;

cout << "Факториал x = " << y << "\n";

}

catch (exception& e)
{
cerr << e.what ();
}