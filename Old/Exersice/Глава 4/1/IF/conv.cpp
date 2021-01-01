#include <std_lib_facilities.h>

int main () {

double SUM = 1; // сумма
string VAL1; // конвертируемая валюта
string VAL2; // валюта конвертации

// ниже предлагается ввести  1) сумму 2) вид валюты

// для того чтобы не нужно было каждый раз перезапускать программу

	while (SUM) 
{
	cout << "\nVvedite summu\n";
	cin >> SUM;
	
	cout << "Vvedite convertiruemu valutu \n      USD\n      EUR      \n      RUB\n";

	cin >> VAL1;
	cout << "Vvedite valutu convertacii \n      USD\n      EUR      \n      RUB\n";

	cin >> VAL2;
	

// Определены: сумма, конвертируемая валюта и валюта конвертации, далее следует вводить инструкцию выбора и выражение

// конвертируем доллар в рубли и евро

if (VAL1 == "USD" && VAL2 == "RUB")
	cout << SUM * 63.8642 << "\nKurs=1 for 63.8642";

else if (VAL1 == "USD" && VAL2 == "EUR")
	cout << SUM*0.8909 << "\nKurs=1 - 0,8909";

else if (VAL1 == "USD" && VAL2 == "USD")
	cout << SUM *1 << "\nKurs=1 for 1"; // вводится на случай попытки конвертации валюты в ту же валюту

// конвертируем евро в рубли и доллары
else if (VAL1 == "EUR" && VAL2 == "RUB")
	cout << SUM*71.915 << "\nKurs=1 for 71,915";

else if (VAL1 == "EUR" && VAL2 == "USD")
	cout << SUM*1.1227 << "\nKurs=1 for 1.1227";

else if (VAL1 == "EUR" && VAL2 == "EUR")
	cout << SUM *1 << "\nKurs=1 for 1";  // вводится на случай попытки конвертации валюты в ту же валюту

// конвертируем рубли в доллары и евро
else if (VAL1 == "RUB" && VAL2 == "EUR")
	cout << SUM*0.0139 << "\nKurs=1 for 0.0139";

else if (VAL1 == "RUB" && VAL2 == "USD")
	cout << SUM*0.0156 << "\nKurs=1 for 0.0156";

else if (VAL1 == "RUB" && VAL2 == "RUB")
	cout << SUM *1 << "\nKurs=1 for 1"; // вводится на случай попытки конвертации валюты в ту же валюту

// убиваем отличные от EUR, USD, RUB
	else if (VAL1 != "RUB"||"USD"||"EUR")
cout << "Nepravilno ukazana valuta - povrorite vvod";

	else if (VAL2 !="RUB"||"USD"||"EUR")
cout << "Nepravilno ukazana valuta - povrorite vvod";
}
} 
