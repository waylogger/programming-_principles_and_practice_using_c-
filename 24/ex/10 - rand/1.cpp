/*
Antonyuk I.V. 
08/04/18
PPP C++ ex. 24.10

default_random_engine;

*/


#include <iostream>
#include <random>
#include <map>
#include <std_lib_facilities.h>

using namespace std;



int main(){
	while (true){
	int n =0;
	int d =0;

	map<int,int>s;
	
	cout << "Insert n\n";
	cin >> n;
	cout << "Insert d\n";
	cin >> d;
	
	for (int i =0; i < d;++i)
	{
		int x = randint(n);
		++s[x];
	}
	
	for (auto& a : s){
		cout << a.first << '\t' << a.second << '\n';
	}
	
	}
	
	char c;
	cin >> c;
	
}