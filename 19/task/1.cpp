#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
class S
{
	private:
	T val;
	public:
	explicit S(T v) : val(v) {}
	const T& get() const ;
	T& get() ;
	void set(T&);
	void read_val();
	
	T& operator= (const T&);
};

template<typename T>
const T& S<T>::get() const
{
	return val;
}

template<typename T>
T& S<T>::get()
{
	return val;
}

template <typename T>
void S<T>::set(T& t)
{
	val = t;
}

template<typename T>
T& S<T>::operator=(const T& t)
{
	val = t.val;
	return *this;
}


template <typename T>
void S<T>::read_val()
{
	T c;
	cin >> c;
	val = c;
}


template <typename T>
ostream& operator << (ostream& ost, const vector<T>v)
{
	ost << "{ ";
	for (int i =0, j = 1; i < v.size(); ++i, ++j)
	{
		ost << v[i] << ' ';
	if (j%3 == 0) ost << '}' << '\n' << "{ ";
	}
	ost << '}';
	
	return ost;
}


template <typename T>
istream& operator >> (istream& ist,vector<T>& v)
{
	for (T c = T(); ; ) 
	{
	if (!cin) 
	{
		
		cin.clear();
		cin.putback(c);
		string s;
		cin >> s;
	return ist;	
	}
	cin >> c;
	if (cin)v.push_back(c);
	}
	return ist;
}

int main ()
{
	

	S<vector<int>>sv = S<vector<int>>(vector<int>{5});
		
	
	
	cin >> sv.get();
	
	cout << sv.get() << '\n';
	
	
	
	
	
	
	
	
	
	char c;
	cin >> c;
	
	
}



