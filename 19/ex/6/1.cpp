
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
class Number
{
	T num;
	public:
	Number(T n) : num (n) {};
	Number() : num(T()) {};
	T get_num() const {return num;}
	void print()
	{
		cout << num;
	}

};


template <typename T>
Number<T> operator+ (const Number<T> t1, const Number<T> t2)
{
	return Number<T>(t1.get_num()+t2.get_num());
}

template <typename T>
Number<T> operator- (const Number<T> t1, const Number<T> t2)
{
	return Number<T>(t1.get_num()-t2.get_num());
}

template <typename T>
Number<T> operator* (const Number<T> t1, const Number<T> t2)
{
	return Number<T>(t1.get_num()*t2.get_num());
}

template <typename T>
Number<T> operator/ (const Number<T> t1, const Number<T> t2)
{
	return Number<T>(t1.get_num()/t2.get_num());
}

template <typename T>
Number<T> operator% (const Number<T> t1, const Number<T> t2)
{
	return Number<T>(t1.get_num()%t2.get_num());
}
template <typename T>
ostream& operator<< (ostream& ost, const Number<T>& t)
{
	cout << t.get_num();
	return ost;
}

template <typename T>
istream& operator>> (istream& ist, Number<T>& t)
{
	
	T q = T();
	ist >> q;
	
	if (!ist)
	{
		ist.clear();
		string s;
		cin >> s;
	}
	
	t = Number<T>(q);
	
	return ist;
}

template <typename T, typename U>
Number<T> summary(vector<Number<T>> n, vector<Number<U>> u)
{
	if (n.size() > u.size()) u.resize(n.size());
	else if (n.size() < u.size()) n.resize(u.size());
	Number<T> sum = Number<T>();
	for (int i =0; i < u.size() || i < n.size(); ++i)
	{
		sum=sum+(u[i]+n[i]);
	}
	return sum;
}




int main()
{

vector<Number<int>>q;
for (int i =0; i < 5; ++i)
{
	q.push_back(Number<int>(i));
}

vector<Number<int>>wq;
for (int i =0; i < 5; ++i)
{
	wq.push_back(Number<int>(i));
}

cout << summary(q,wq) << '\n';

	
	char c;
	cin >>c;
}














