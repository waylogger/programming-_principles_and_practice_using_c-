#include <iostream>
#include <iomanip>

using namespace std;


void f(int i, double fpd){
	cout << "integer - " << i << '\n';
	char c = i;
	cout << "type char after init by integer - " << c << '\n';
	
	i = i+1;
	cout << "i=i+1 - " << i << '\n';
	
	long lg = i*i;
	cout << "long lafter init by int*int - " << lg << '\n';
	float fps = fpd;
	cout << "float after init by double - " << fps << '\n';
	i = fpd;
	cout << "int after init by double - " << i << '\n';
	fps = i;
	cout << "float after init by int - " << fps << '\n';
}

void g(){
	char ch = 0;
	for (int i = 0; i < 500; ++i)
		cout << int(ch++) << '\t';
}

int main()
{
	double d = 0;
	for (int i = 5; i < 50; ++i, d += 0.5)
	{
		f(i*5,d);
	}
	g();
	
	char c;
	cin >> c;
}