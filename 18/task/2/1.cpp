#include <iostream>
#include <vector>

using namespace std;



vector <int>gv{1,2,3,4,5,6,7,8,9,10};

void f(const vector<int>& v)
{
	vector<int>v1(v.size());
	
	v1=gv;
	
	for (int i =0; i < v1.size(); ++i)
	{cout << v1[i] << '\n';}

	vector<int>v2 = v;
	
	for (int i =0; i < v2.size(); ++i)
	{cout << v2[i] << '\n';}


	
}


int fac(int n)
{
return {n>1 ? n*fac(n-1) : 1};
}

int main ()
{
	
	
	f(gv);
	vector<int>vv {fac(1),fac(2),fac(3),fac(4),fac(5),fac(6),fac(7),fac(8),fac(9),fac(10)};
	f(vv);
	
	
	char c;
	cin >> c;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}