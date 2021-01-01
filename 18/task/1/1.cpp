#include <iostream>

using namespace std;
int ga[] {1,2,4,8,16,32,64,128,256,215};

void f(int ai[], int max)
{
	int la[10];
	for (int i =0; i < 10; ++i)
	la[i]=ai[i];

	for (int i =0; i < 10; ++i) cout << la[i] << '\n';
	
	int* p = new int [max];
	for (int i =0; i < max; ++i)
	{
		p[i]=ai[i];
	}
	
	for (int i =0; i < max;++i)
	{
		cout << p[i] << '\n';
	}
	
	delete[] p;
	
	
}



int fac (int n)
{
return {n>1 ? n*fac(n-1) : 1};
}

int main ()
{
	
	f(ga,10);
	
	int aa[] {fac(1),fac(2),fac(3),fac(4),fac(5),fac(6),fac(7),fac(8),fac(9),fac(10)};
	
	f(aa,10);
	
	
	char c;
	cin >>c;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}