#include <std_lib_facilities.h>

int main ()
{
	setlocale(0,"Russian");
	cout << setw(35) << "�������� ������ ������������" 	<< "|\t" 	<< setw(19)	<< "�����������" <<"|\n";
	cout << setw(35) << "��������� ������� ������������"<< "|\t" 	<< setw(19)	<< "����� ������" <<"|\n";
	cout << setw(35) << "���������� ��������� ��������" << "|\t"	<< setw(19)	<< "������" <<"|\n";
	cout << setw(35) << "��������� ����� ����������" 	<< "|\t"	<< setw(19)	<< "������" <<"|\n";
	cout << setw(35) << "������� ������� ����������"	<< "|\t" 	<< setw(-1)	<< "���� ����� ��������" <<"|\n";

	keep_window_open();
}