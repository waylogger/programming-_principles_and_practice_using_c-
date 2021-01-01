#include <iostream>
#include <bitset>

using namespace std;



int main(){
	
	unsigned int init1 = 0;
	unsigned int init2 = ~init1;
	unsigned int init3 = 0;
	
	for (int i = 0 ; i < 31; ++i)
		init3 = ~init3 <<  1;
	
	unsigned int init4 = ~init3;
	
	unsigned int init5 = 0;
	
	for (int i = 0 ; i < 31; ++i)
		init5 = ~init5 <<  2;
	
	unsigned int init6 = ~init5;
	unsigned int init7 = 0;
	
	
	for (int i = 0; i < 3; ++i)
	init7 = ~init7<<8;
	init7 = ~init7;
	
	
	bitset<32> a  = init1;
	cout << a << '\n';
	cout << init1 << '\n';
	
	
	
	
	
	char end;
	cin >> end;
	
}















