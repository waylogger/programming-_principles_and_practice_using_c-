#include <std_lib_facilities.h>

 
int main ()
{
	setlocale(0, "");
	cout << "������� ����� ����� �����\n";
	
	int ib1 = 0; // ��������� ����� �1
	int ib2 = 0; // ��������� ����� �2
	int ib3 = 0; // ��������� ����� �3
	int ib4 = 0; // ��������� ����� �4
	char sb1[16] = " "; //��������� ������� �1
	char sb2[2] = " "; //��������� ������� �2
	char sb3[2] = " "; //��������� ������� �3
	char sb4[2] = " "; //��������� ������� �4
	int a=0;
	int n =0;
	while (a!=631)
	{
	cin >> n;
	
	srand(n); // ��������� ����� �1
	ib1 = rand () %10;
	itoa(ib1, sb1, 10);
	
	n=n*n;
	srand(n); // ��������� ����� �2
	ib2 = rand () %10;
	itoa(ib2, sb2, 10);
	
	n=n/n;
	srand(n); // ��������� ����� �3
	ib3 = rand () %10;
	itoa(ib3, sb3, 10);
	
	n=n/n+641;
	srand(n); // ��������� ����� �4
	ib4 = rand () %10;
	itoa(ib4, sb4, 10);
	
	
	strcat(sb1,sb2);
	strcat(sb1,sb3);
	strcat(sb1,sb4);
	cout << sb1 << " " << sb2 << " "  << sb3  << " " << sb4 << "\n";
	cin >> a;
	}
	//ib2 = srand(n); // ��������� ����� �2
	//ib3 = srand(n); // ��������� ����� �3
	//ib3 = srand(n); // ��������� ����� �4
	//cout << ib1 << ib2 << ib3 << ib4 << " - ��� ������� \n";
	
//srand ( time (NULL) );
//cout << "����� ������ �����: " << rand()  << "\n";
}