#include <std_lib_facilities.h>

int main () {

double SUM = 1; // �����
string VAL1; // �������������� ������
string VAL2; // ������ �����������

// ���� ������������ ������  1) ����� 2) ��� ������

// ��� ���� ����� �� ����� ���� ������ ��� ������������� ���������

	while (SUM) 
{
	cout << "\nVvedite summu\n";
	cin >> SUM;
	
	cout << "Vvedite convertiruemu valutu \n      USD\n      EUR      \n      RUB\n";

	cin >> VAL1;
	cout << "Vvedite valutu convertacii \n      USD\n      EUR      \n      RUB\n";

	cin >> VAL2;
	

// ����������: �����, �������������� ������ � ������ �����������, ����� ������� ������� ���������� ������ � ���������

// ������������ ������ � ����� � ����

if (VAL1 == "USD" && VAL2 == "RUB")
	cout << SUM * 63.8642 << "\nKurs=1 for 63.8642";

else if (VAL1 == "USD" && VAL2 == "EUR")
	cout << SUM*0.8909 << "\nKurs=1 - 0,8909";

else if (VAL1 == "USD" && VAL2 == "USD")
	cout << SUM *1 << "\nKurs=1 for 1"; // �������� �� ������ ������� ����������� ������ � �� �� ������

// ������������ ���� � ����� � �������
else if (VAL1 == "EUR" && VAL2 == "RUB")
	cout << SUM*71.915 << "\nKurs=1 for 71,915";

else if (VAL1 == "EUR" && VAL2 == "USD")
	cout << SUM*1.1227 << "\nKurs=1 for 1.1227";

else if (VAL1 == "EUR" && VAL2 == "EUR")
	cout << SUM *1 << "\nKurs=1 for 1";  // �������� �� ������ ������� ����������� ������ � �� �� ������

// ������������ ����� � ������� � ����
else if (VAL1 == "RUB" && VAL2 == "EUR")
	cout << SUM*0.0139 << "\nKurs=1 for 0.0139";

else if (VAL1 == "RUB" && VAL2 == "USD")
	cout << SUM*0.0156 << "\nKurs=1 for 0.0156";

else if (VAL1 == "RUB" && VAL2 == "RUB")
	cout << SUM *1 << "\nKurs=1 for 1"; // �������� �� ������ ������� ����������� ������ � �� �� ������

// ������� �������� �� EUR, USD, RUB
	else if (VAL1 != "RUB"||"USD"||"EUR")
cout << "Nepravilno ukazana valuta - povrorite vvod";

	else if (VAL2 !="RUB"||"USD"||"EUR")
cout << "Nepravilno ukazana valuta - povrorite vvod";
}
} 
