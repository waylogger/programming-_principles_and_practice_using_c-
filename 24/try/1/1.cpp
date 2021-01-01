#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	
	float x1 = 1;
	float x2 = 333;
	float x = x1/x2;
	float sum = 0;
	for (int i =0; i < 333; ++i)
		sum += x;
	
	cout << setprecision(15) << "sum = " << sum << '\n';
	
	
	cout << sizeof(float)*8 << '\n';
	
	char c;
	cin >> c;
}