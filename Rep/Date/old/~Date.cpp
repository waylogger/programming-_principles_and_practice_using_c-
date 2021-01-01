#include <std_lib_facilities.h>
/*
планируемые улучшения:
1. Обработка исключений инструкцией throw
2. Проверка типов аргументов через enum class Month и class Year
*/
class Date {
	int d =0;
	int m =0;
	int y =0;
	bool corr_date_day(int d);
	bool corr_date_month(int d, int m);
	bool corr_date_year(int d, int m, int y);
	public:
	Date indate ();
	};

	
enum class Month {
	jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};
bool Date::corr_date_day(int d) {
	/*убираем отрицательные числа и больше 31*/
	if (!cin) {cin.clear(); error ("Unccorrect char  - day");}
	if (d<1||d>31) error ("Unccorrect date  - day");
	else return true;
	return true;
}
bool Date::corr_date_month(int d, int m) {
	if (!cin) {cin.clear(); 	error ("Unccorrect date  - month");	}
	if (m<int(Month::jan)||m>int(Month::dec)) 	error ("Unccorrect char  - month");
	/*проверяем корректность указания 31 дня*/
	if(d==31&&m!=int(Month::jan)&&m!=int(Month::mar)&&m!=int(Month::jun)
		&&m!=int(Month::aug)&&m!=int(Month::oct)&&m!=int(Month::dec))	 
		error ("Unccorrect quantity of days for this month");
	/*проверяем корректность  30 дня для февраля, для остальных не требуется*/
	if (d==30&&m==int(Month::feb)) error ("Unccorrect quantity days for february");
	else return true;
	return true;
}
bool Date::corr_date_year(int d, int m, int y) {
	if (!cin) {	cin.clear(); 	error ("Unccorrect char  - year");	}
	if (y<0) 	error ("Unccorrect date - year");
	/*проверяем учитывем високосные года*/
	if (d==29&&m==int(Month::feb)&&y%4==0) return true;
	if (d>28&&m==int(Month::feb)&&y%4!=0) error ("Unccorrect quantity days for february");
	else return true;
	return true;
}

Date Date::indate (){
	Date t;
	cout << "Insert date\n";
	cout << "Day : ";
	cin >> t.d; //вводим день
	corr_date_day(t.d); //проверяем корректность ввода дня
	cout << "Month : ";
	cin >> t.m; //вводим месяц
	corr_date_month(t.d,t.m); //проверяем корректность ввода месяца
	cout << "Year : ";
	cin >> t.y;
	corr_date_year(t.d, t.m, t.y); //проверяем корректность ввода года
	if (corr_date_year(t.d, t.m, t.y)) return t; //если все норм, то возвращаем
	return t;
}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	