#include <std_lib_facilities.h>

int main () {

	double s = 1; // сумма
	char val = 'a'; // конвертируемая валюта
	

// ниже предлагается ввести  1) сумму 2) вид валюты

	cout << "\nVvedite summu\n";
	cin >> s;
	
	cout << "Vvedite valutu \n      USD-u\n      EUR-e      \n      RUB-r\n";

	cin >> val;
		
// Определены: сумма и валюта

// конвертируем доллар в рубли и евро

	switch (val) 
{
		case 'u':
			cout 	<< "\n" 
				<< s*63.8642 
				<< " RUB" 
				<< "\nKurs=1 for 63.8642\n"
				<< s*0.8909
				<< " EUR"
				<< "\nKurs=1 for 0,8909\n";
		break;

// конвертируем евро в рубли и доллары		
		
		case 'e':
			cout 	<< "\n" 
				<< s*71.915 
				<< " RUB" 
				<< "\nKurs=1 for 71.915\n"
				<< s*1.1227
				<< " USD"
				<< "\nKurs=1 for 1.1227\n";
		break;

// конвертируем рубли в доллары и евро		

		case 'r':
			cout 	<< "\n" 
				<< s*0.0139 
				<< " EUR" 
				<< "\nKurs=1 for 0.0139\n"
				<< s*0.0156
				<< " USD"
				<< "\nKurs=1 for 0.0156\n";
		break;
}
keep_window_open ();				
} 
