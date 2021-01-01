/*
Усовершенствовать функцию 
print_unlit_(), протестировать ее

Какие наборы данных лучше 
всего подходят для тестирования?
Почему?

Записать функцию print_until_(), 
которая выводит строки, пока не 
обнаружит второе вхождение строки
аргумента quit 


void print_until_s(vector<string>v, string quit)
{
for (int s : v) {
	if (v[i]==quit) return;
	cout << v[i] << '\n';
}
}*/
#include <std_lib_facilities.h>
void print_until_s(vector<string>v, string quit)
{ //print_
int q =0;
for (int i =0; i<v.size();++i) 
{//for 25

if (v[i]==quit) ++q;
if (q>=2) return;
cout << v[i] << '\n';

}//for 25
} //print



int main () 
{ //main
	vector<string>v{"1","2","3","4","5","quit","6","864","quit","64"};
	string quit = "quit";
	print_until_s(v, quit);
	keep_window_open();
	return 0;
	} //main




