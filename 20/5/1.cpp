#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::cin;
using std::istream;
using std::ostream;
using std::string;

template <typename T>
istream& operator >> (istream& ist,vector<T>&v)

{
	T a;
	ist >> a;
	v.push_back(a);
	return ist;
}

template <typename T>
ostream& operator << (ostream& ost, const vector<T>& v)
{
	auto b = v.begin();
	auto e = v.end();
	int num = 0;
	while(b != e)
	{
		ost << *b << ' ';
		
		++num;
		++b;
		if (num == 10) 
		{
			num = 0;
			ost << '\n';
		}
	}
	return ost;
}


int main()
{
	vector<int>p;
	for (int i =0; i < 20;++i)
	cin >> p;

	cout << p << '\n';
	char c;
	cin >> c;
}