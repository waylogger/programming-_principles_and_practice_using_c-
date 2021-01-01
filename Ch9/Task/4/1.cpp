/*
/*1. ���������� ������ ������ Date 
� ������ today. ������������������ ����� 
19 �� 1963 ����.

2. ���������� ������ ������ Date � ������ 
tomorrow � ��������� ��� ��������, 
���������� � ���� ������ today � �������� 
��� ���� �� ������� � ������� ������� add_day();

3. ������� �� ������ ������� today � 
tomorrow, �������� �������� <<
 ������������ � ������� 9.8*/
#include <std_lib_facilities.h>

enum class Month {
jan = 1, feb, mar,apr,may,jun,jul,aug,sep,oct,nov,dec
};	

class Date {
public:
Date(int d, Month m, int y) : d(d), m(m), y(y) {};
int day() const {return d;}
Month month () const {return m;}
int year () const {return y;}
int add_day (int n);
private:
int y;
Month m;
int d;
};

int Date::add_day(int n) 
{
	return n=n+1;
}

ostream& operator << ( ostream& os, Date d)
{
return os << '(' << d.day()	
	  << ',' << int(d.month())
	  << ',' << d.year() << ')';
}


int main () {
	Date today = {23,Month::may,1963};
	Date tomorrow = {today.add_day(today.day()), today.month(), today.year()};
	cout << today << '\n';
	cout << tomorrow << '\n';
	keep_window_open();
	
}