/*
Antonuyk I.V. 26/04/2018
По дороге из Н.Новгорода в МСК
Курский Вокзал, в ожидании поезда на Белгород

binary search

requiment of B.Stroustrop in 26.1 PPP C++
*/

#include <iostream>

using namespace std;
template <typename Iter, typename Elem>
int binary_search( Iter begin, Iter end, Elem elem ){
	
	int right_border = 0;
	int left_border = 0;

	for (auto f = begin; f != end; ++f){
		++right_border;
	}
	
	if (*begin == elem)
		return 0;
	
	else if ( * (end - 1) == elem)
		return right_border;
	while (left_border < right_border-1){
		int midle = (left_border+right_border) /2;
		
		if ( * ( begin + midle ) == elem ){
			return midle;
		}
		
		if ( * ( begin + midle ) < elem ){
			left_border = midle;
		}
		else if (* ( begin + midle ) > elem){
			right_border = midle;
		}
						
	}
	
	return right_border == elem ? right_border : -99999;
}


int main(){
	
	constexpr int S = 50;
	int a[S];
	
	for (int i =0; i < S; ++i)
		a[i] = i;
	
	cout << binary_search(&a[0],&a[S-1],28);
	
	
	char end;
	cin >> end;
}












