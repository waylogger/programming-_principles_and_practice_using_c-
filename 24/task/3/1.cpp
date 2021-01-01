#include <iostream>
#include <Matrix\\Matrix.h>

using Numeric_lib::Matrix;
using namespace std;


void f(){
	int i = 0;
	cout << "Insert integer number\n";
	
	cin >> i;
	if (!cin){
		
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		return;
	}
	errno = 0;
	double d = 0;
	d = sqrt(i);
	
	if (errno)
		cout << "I cant calc sqrt of this number\n";
	else 
		cout << "SQRT of " << i << " is " << d << '\n';
}

int main()
{
	
	
	while (true)f();

	char end;
	cin >> end;
}