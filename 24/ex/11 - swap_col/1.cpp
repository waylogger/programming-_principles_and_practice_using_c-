/*
08/04/2018

Antonuyk I.V.

PPP C++ 24.11

*/
#include <Matrix\\Matrix.h>
#include <Matrix\\Matrixio.h>
#include <iostream>
#include <std_lib_facilities.h>
using namespace std;


Numeric_lib::Matrix<int,2> randmat(const int s,const int x){
	int d1 = randint(s);
	int d2 = d1;
	Numeric_lib::Matrix<int,2> a (d1,d2);
	
	for (int i =0; i < d1; ++i){
		for(int j = 0; j < d2; ++j){
			a(i,j) = randint(x);
		}
	}
	return a;
	
}



int main(){
	
	Numeric_lib::Matrix<int,2> a = randmat(20,50);
	
	
	
	cout << a << '\n';
	a.swap_columns(0,7);
	cout << a << '\n';
	
	
	char c;
	cin >> c;
	
}