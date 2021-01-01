#include <std_lib_facilities.h>

 
int main ()
{
	setlocale(0, "");
	cout << "Введите любое целое число\n";
	
	int ib1 = 0; // случайная цифра №1
	int ib2 = 0; // случайная цифра №2
	int ib3 = 0; // случайная цифра №3
	int ib4 = 0; // случайная цифра №4
	char sb1[16] = " "; //строковая загадка №1
	char sb2[2] = " "; //строковая загадка №2
	char sb3[2] = " "; //строковая загадка №3
	char sb4[2] = " "; //строковая загадка №4
	int a=0;
	int n =0;
	while (a!=631)
	{
	cin >> n;
	
	srand(n); // случайная цифра №1
	ib1 = rand () %10;
	itoa(ib1, sb1, 10);
	
	n=n*n;
	srand(n); // случайная цифра №2
	ib2 = rand () %10;
	itoa(ib2, sb2, 10);
	
	n=n/n;
	srand(n); // случайная цифра №3
	ib3 = rand () %10;
	itoa(ib3, sb3, 10);
	
	n=n/n+641;
	srand(n); // случайная цифра №4
	ib4 = rand () %10;
	itoa(ib4, sb4, 10);
	
	
	strcat(sb1,sb2);
	strcat(sb1,sb3);
	strcat(sb1,sb4);
	cout << sb1 << " " << sb2 << " "  << sb3  << " " << sb4 << "\n";
	cin >> a;
	}
	//ib2 = srand(n); // случайная цифра №2
	//ib3 = srand(n); // случайная цифра №3
	//ib3 = srand(n); // случайная цифра №4
	//cout << ib1 << ib2 << ib3 << ib4 << " - это загадка \n";
	
//srand ( time (NULL) );
//cout << "—нова первое число: " << rand()  << "\n";
}