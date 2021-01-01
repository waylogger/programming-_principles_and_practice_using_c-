	#include <iostream>
	
	using namespace std;
	
	int main(){
		
		
		int zero = 0;
		int one = 1;
		int two = one << 1;
		int three = two | one;
		int four = two << 1;
		int five = four | one;
		int six = four | two;
		int seven = four | three;
		int eight = one << three;
		int nine = eight | one;
		int A = eight | two;
		int B = A | one;
		int C = eight | four;
		int D = C | one;
		int E = C | two;
		int F = C | three;
		
		
		short unsigned int a = F; //1111
		short unsigned int b = one; //0001
		short unsigned int c = eight; //1000
		short unsigned int d = (F<<1)|1; //0001 1111
		short unsigned int e = (F<<four)|1; //1111 0001
		short unsigned int f = five; //0101
		short unsigned int g = A; //1010
		
		cout << "In hexidimal\n";
		cout << hex;
		cout << "1111 - is " << a << '\n';
		cout << "0001 - is " << b << '\n';
		cout << "1000 - is " << c << '\n';
		cout << "0001 1111 - is " << d << '\n';
		cout << "1111 0001 - is " << e << '\n';
		cout << "0101 - is " << f << '\n';
		cout << "1010 - is " << g << '\n';
		
		cout << "In decimal\n";
		cout << dec;
		cout << "1111 - is " << a << '\n';
		cout << "0001 - is " << b << '\n';
		cout << "1000 - is " << c << '\n';
		cout << "0000 1111 - is " << d << '\n';
		cout << "1111 0000 - is " << e << '\n';
		cout << "0101 - is " << f << '\n';
		cout << "1010 - is " << g << '\n';
		
	
		
		
		
		char end;
		cin >> end;
	}
