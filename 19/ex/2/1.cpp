#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Bad_multiply
{
	private:
	string s;
	public:
	Bad_multiply(string ss) : s(ss) {}
	
	string what() const {return s;}
};

void compare(int a, int b)
try
{
	if (a != b ) throw Bad_multiply("Vector is not eqaul");
}
catch (Bad_multiply& e)
{
	cerr << e.what() << '\n';
}


template <typename T, typename U>
T f(vector<T> v1, vector<U> v2)
{
	if (v1.size() < v2.size()) v1.resize(v2.size());
	else if (v2.size() < v1.size()) v2.resize(v1.size());
	
	compare(v1.size(),v2.size());
	T r = T();
	for (int i = 0; i < v1.size() ;++i)
	{
		r += (v1[i]*v2[i]);
	}
	
	
	return r;
}

int main()
{
	
	vector <int>a = {1,2,3,4,5,8,9,9};
	vector <int>b = {5,4,3,2,1,155,5515,1551,515};
	
	
	cout << f<int,int>(a,b) << '\n';
	
	char c;
	cin >> c;
	
};














