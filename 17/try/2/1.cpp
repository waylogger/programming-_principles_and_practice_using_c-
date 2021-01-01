#include <iostream>

using namespace std;
int main ()
{
	int* a = new int(564);
	
	int* b = a;
	
	*b = 5;
	
	cout << a << ' ' << b << '\n';
	
	char c;
	cin >>c;
}