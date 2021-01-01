#include <iostream>
#include <string>
#include <vector>

using namespace std;



template<typename T, typename A>
class Pair
{
	private:
	T t;
	A a;
	public:
	Pair(const T& tt, const A& aa) : t(tt), a(aa) {}
	
	const T& first()	const 	{return t;}
	const A& second()	const	{return a;}
};


int main()
{
	
	vector<Pair<string, double>>s;
	
	
	
	for (double i =0; i < 100; ++i)
	{
		Pair<string,double>q = {"Number",i};
		s.push_back(q);
	}
	
	
	for (int i =0; i < s.size(); ++i)
	{
		cout << s[i].first() << ' ' << s[i].second() << '\n';
	}
	
	char c;
	cin >>c;
}