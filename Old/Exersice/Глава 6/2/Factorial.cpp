
#include <std_lib_facilities.h>

int main ()
try
{
setlocale (0, "");
cout << "����� ��� ���������� ����������\n";
int x= 0;
int y= 1;


cin >> x;
if (x<0) error ("��������������� x\n");

while (x>0)
{
y*=x;
--x;
}

if (x=0) y=1;

cout << "��������� x = " << y << "\n";

}

catch (exception& e)
{
cerr << e.what ();
}