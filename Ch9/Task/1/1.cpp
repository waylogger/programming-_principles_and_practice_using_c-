/*1. ���������� ������ ������ Date 
� ������ today. ������������������ ����� 
19 ��� 1963 ����.

2. ���������� ������ ������ Date � ������ 
tomorrow � ��������� ��� ��������, 
���������� � ���� ������ today � �������� 
��� ���� �� ������� � ������� ������� add_day();

3. ������� �� ������ ������� today � 
tomorrow, ��������� �������� <<
 ������������ � ������� 9.8*/

#include <std_lib_facilities.h>
struct Date {
	int d;
	int m;
	int y;
};

Date add_day(Date i) {
	i.d=i.d+1;
	return i;
}

int main () 
{
	Date today {19,05,1963};
	Date tomorrow {add_day(today)};
	cout << today.d << ' ' << today.m << ' ' << today.y << '\n';
	cout << tomorrow.d << ' ' << tomorrow.m << ' ' << tomorrow.y << '\n'; 	
	keep_window_open();
};


