//Название программы: Исключение - ошибка диапазона
//Цель программы: Протестировать поимку исключения - ошибки диапазона
//Автор: Антонюк И.В.
//Дата начала написания: 28.10.2016
//Дата окончания написания:
//Номер версии: 1
//Фрагменты кода, которые могут вызвать проблемы: функуция catch
//Основные идеи проекта: Протестировать поимку исключения - ошибки диапазона
//Способ организации кода: 1. Main; 2; Catch
//Предположения о вводных данных: Integer

#include <std_lib_facilities.h>

int main ()
try
{
double sum = 0;
int n = -1;
cout << "Pls...insert how much numbers need to sum\n";
cin >> n;
	if (n<1) error ("n - must be a positive integer\n");
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||
cout << "Pls.....insert numbers (press '|' to stop)\n";
vector <double> nums;
double num;

	while (cin>>num)
	{
	nums.push_back(num);
	}
	
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||

	for (int i = 0; i<n; ++i)
	{
	sum += nums[i];
	cout << nums[i] << "  \n";
	}
	
	cout << "\nSumma ukazannih chisel = " << sum << "  \n";
	
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||

	vector <double> chs;
	double ch =0;
	for (int i = 0; i<nums.size ()-1; i=i+2)
	{
	ch=nums[i]-nums[i+1];
	chs.push_back (ch);
	
	}
	for (int i2 = 0; i2<chs.size (); ++i2)
		cout << "Raznost deystvitelnih chisel = \n" << chs[i2] << "\n";
		
	keep_window_open ("~");
	
}


catch (out_of_range)
{
	cout << "\nUps...out_of_range";
}
catch (...)
{
	cout << "\nUps...";
}


