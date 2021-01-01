#include <iostream>


using namespace std;


int a[100];


void f ()
{
	int* pa = new int [100];
	for (int i = 100; i >= 0 ; --i)
	{
		cout << pa;
		if (pa>(pa-1)) cout << " - Less\n";
		else cout << "- More\n";
		++pa;
		
		
	}
}

int main()
{
	f();
	
	
	char c;
	cin >>c;
}