#include <std_lib_facilities.h>



string roman_back(int i) //Переводим арабские цифры в римские
{
	string sum = "";
	

	char M = 'M';	char D = 'D';
	char C = 'C';	char L = 'L';
	char X = 'X';	char V = 'V';
	char I = 'I';
	
		
	while (i>=1000)	{i=i-1000;	sum+=M;} //Вычленяем тысячи
	while (i>=500)	{ 
		if (i>900 && i < 1000) {sum+="CM"; i=i-900; break;}
					 i=i-500;	sum+=D;}
	while (i>=100)	{
		if (i >400 && i < 500) {sum+="CD"; i=i-400; break;}
					 i=i-100;	sum+=C;}
	while (i>=50)	{
		if (i==90) {sum+="XC"; i=i-90; break;}
					 i=i-50;	sum+=L;	}
	while (i>=10)	{
		if (i>40 && i < 50) {sum+="XL"; i=i-40; break;}
					 i=i-10;	sum+=X;}
	while (i>=5)	{
		if (i==9) {sum+="IX"; i=i-9; break;}
					 i=i-5;		sum+=V;}
	while (i>=1)	{
		if (i==4) {sum+="IV"; i=i-4; break;}
					 i=i-1;		sum+=I;}
	return sum;
}

int main () 
{
	
	string s = "";
	s = roman_back(873);
	cout << s << '\n';
	

	keep_window_open();
}
















