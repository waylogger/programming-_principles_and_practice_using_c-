/*
Антонюк И.В.

07.12.2016

Написать функцию maxv (), 
которая возвращает
 наибольший элемент вектора, 
передаваемого в качестве аргумента
*/
#include<std_lib_facilities.h>
void maxv (vector<double>&maxi) 
{ // открывает функцию maxv
double d = 0;
for (int i=0;i<maxi.size();++i)
{ //открывает for
if (d<maxi[i]) d=maxi[i];
}//закрывает for
cout << "Biggest member of maxi - " << d <<'\n';
}//закрывает функцию maxv


int main () 
{ //omain
vector<double>maxi{1,2,3,4,5,6,7,8,9};
maxv(maxi);
keep_window_open();
} //cmain


	