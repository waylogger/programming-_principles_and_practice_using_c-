#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void f()
{
	vector<T>v1;
	v1.resize(100,100);
	vector<T>v2;
	v2.resize(200,200);
	v1.resize(v2.size());
	for (int i =0; i < v1.size(); ++i)
	{
		v1[i]+=v2[i];
	}
	
	for (int i =0; i < v1.size();++i)
	cout << v1[i] << '\n';
	
	
}


int main ()
{
	f<int>();
	
	
	char c;
	cin >>c;
};