//��������� �������� ���� �� ��������� �����
#include <std_lib_facilities.h>

int main () {

double i = 1; // ����� ������
double r = 1; // ���������� ���� �� ������
double f = 1; // ������� ���������� ����
cout << "Vvedite iskomoe kolichestvo risa\n";
cin >> f;

while (r<=f) {
++i;

if (r==1)
r=r+1;
else r=r*r;

if (f==1)
cout 	<< "Kletka nomer - 1"  
	<< "\nKolichestvo risa - 1\n";

else 
cout 	<< "Kletka nomer - " 
	<< i 
	<< "\nKolichestvo risa - "
	<< r
	<< "\n";
}
keep_window_open ();
}

//double = 11 ������, int = 6