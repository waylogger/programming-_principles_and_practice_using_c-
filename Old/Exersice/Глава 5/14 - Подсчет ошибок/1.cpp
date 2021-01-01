//Название программы: Подсчет отвергнутых значений
//Цель программы:Подсчет отвергнутых значений
//Автор: Антонюк И.В.
//Дата начала написания: 04.11.2016
//Дата окончания написания: 04.11.2016
//Номер версии: 1.0
//Фрагменты кода, которые могут вызвать проблемы: Ввод значений дня и последующее правильное определение необходимого вектора
//Основные идеи проекта: Распределение значений одной переменной по 7 векторам и подсчет количеств ошибок
//Способ организации кода: функция main, ввод значения-внесение в вектор
//Предположения о вводных данных: целочисленные и строчные

#include <std_lib_facilities.h>

int main ()
try
{
setlocale (0, "");
//..................7 групп под распределение
vector<int>monday;
vector<int>tuesday;
vector<int>wensday;
vector<int>thursday;
vector<int>friday;
vector<int>saturday;
vector<int>sunday;
//..................
int value = 0; // число
string day = " ";// день
int sum = 0; //сумма
int z =0; // Счетчик ошибок
//..................

while (value!=13666)
	{
	if (value==0) {cout << "Укажите день недели\n";	cin >> day;}
	while (day!=" "&&
	day!="Monday"&&
	day!="Mon"&&
	day!="monday"&&
	day!="mon"&&
	day!="MON"&&
	day!="m"&&
	day!="M"&&
	day!="Tuesday"&&
	day!="Tu"&&
	day!="tuesday"&&
	day!="tue"&&
	day!="TUE"&&
	day!="tu"&&
	day!="TU"&&
	day!="Wensday"&&
	day!="Wen"&&
	day!="wensday"&&
	day!="wen"&&
	day!="WEN"&&
	day!="w"&&
	day!="W"&&
	day!="Thursday"&&
	day!="Thr"&&
	day!="thursday"&&
	day!="thr"&&
	day!="THR"&&
	day!="th"&&
	day!="TH"&&
	day!="Friday"&&
	day!="Fri"&&
	day!="friday"&&
	day!="fri"&&
	day!="FRI"&&
	day!="f"&&
	day!="F"&&
	day!="Saturday"&&
	day!="Sat"&&
	day!="saturday"&&
	day!="sat"&&
	day!="SAT"&&
	day!="st"&&
	day!="ST"&&
	day!="Sunday"&&
	day!="Sun"&&
	day!="sunday"&&
	day!="sun"&&
	day!="SUN"&&
	day!="SU"&&
	day!="su") 
		{
			cout << "Некорректное значение, повторите ввод \n";
			++z;
			cin >> day;
		}
		
	if (value==0) cout << "Укажите число\n";
	cin >> value;
	
//..................понелельник
	if (day=="Monday"||day=="Mon"||day=="monday"||day=="mon"||day=="MON"||day=="m"||day=="M")
	if (value!=13666)
	monday.push_back(value);

//..................
//..................
//..................вторник

	if (day=="Tuesday"||day=="Tu"||day=="tuesday"||day=="tue"||day=="TUE"||day=="tu"||day=="TU")
	if (value!=13666)
	tuesday.push_back(value);

	
//..................среда

if (day=="Wensday"||day=="Wen"||day=="wensday"||day=="wen"||day=="WEN"||day=="w"||day=="W")
	if (value!=13666)
	wensday.push_back(value);

//..................четверг

if (day=="Thursday"||day=="Thr"||day=="thursday"||day=="thr"||day=="THR"||day=="th"||day=="TH")
	if (value!=13666)
	thursday.push_back(value);

//..................пятница
if (day=="Friday"||day=="Fri"||day=="friday"||day=="fri"||day=="FRI"||day=="f"||day=="F")
	if (value!=13666)
	friday.push_back(value);


//..................суббота
if (day=="Saturday"||day=="Sat"||day=="saturday"||day=="sat"||day=="SAT"||day=="st"||day=="ST")
	if (value!=13666)
	saturday.push_back(value);

//..................воскресенье
if (day=="Sunday"||day=="Sun"||day=="sunday"||day=="sun"||day=="SUN"||day=="SU"||day=="su")
	if (value!=13666)
	sunday.push_back(value);



}
//...............................вывод
//..................понедельник
if (monday.size()>0)
{
cout << "Понедельник\n";
for (int i=0; i<monday.size ();++i)
	{
	cout << monday[i] << "\n";
	sum+=monday[i];
	}
cout << "Сумма всех значений = " << sum << "\n";
sum=0;
}
//..................вторник
if (tuesday.size()>0)
{
	cout << "Вторник\n";
for (int i=0; i<tuesday.size ();++i)
	{
	cout << tuesday[i] << "\n";
	sum+=tuesday[i];
	}
cout << "Сумма всех значений = " << sum << "\n";
sum=0;
}
//..................среда
if (wensday.size()>0)
{
cout << "Среда\n";
for (int i=0; i<wensday.size ();++i)
	{
	cout << wensday[i] << "\n";
	sum+=wensday[i];
	}
cout << "Сумма всех значений = " << sum << "\n";
sum=0;
}
//..................четверг
if (thursday.size()>0)
{
cout << "Четверг\n";
for (int i=0; i<thursday.size ();++i)
	{
	cout << thursday[i] << "\n";
	sum+=thursday[i];
	}
cout << "Сумма всех значений = " << sum << "\n";
sum=0;
}
//..................пятница
if (friday.size()>0)
{
cout << "Пятница\n";
for (int i=0; i<thursday.size ();++i)
	{
	cout << friday[i] << "\n";
	sum+=friday[i];
	}
cout << "Сумма всех значений = " << sum << "\n";
sum=0;
}
//..................суббота
if (saturday.size()>0)
{
cout << "Суббота\n";
for (int i=0; i<saturday.size ();++i)
	{
	cout << saturday[i] << "\n";
	sum+=saturday[i];
	}
cout << "Сумма всех значений = " << sum << "\n";
sum=0;
}
//..................воскресенье
if (sunday.size()>0)
{
cout << "Воскресенье\n";
for (int i=0; i<sunday.size ();++i)
	{
	cout << sunday[i] << "\n";
	sum+=sunday[i];
	}
cout << "Сумма всех значений = " << sum << "\n";
sum=0;
}
cout << "Всего при вводе данных допущено ошибок -  " << z << "\n";
keep_window_open("~");
}

catch (exception& e)
{
cerr << e.what () << "\n";
}
