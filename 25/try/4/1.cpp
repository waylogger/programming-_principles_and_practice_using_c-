#include <iostream>


using namespace std;


void infinite(){
	unsigned char max = 160;
	
	for (signed char i = 0; i < max; ++i){
		cout << int(i) << '\n';
	}
}


int main(){
	
	infinite();
	
}