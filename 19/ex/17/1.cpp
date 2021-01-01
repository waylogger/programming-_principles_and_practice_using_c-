#include <iostream>
#include <vector>

using namespace std;

template<typename T>
struct Represent
{
	Represent(int i) : elem {new T[i]}, space{i}
		{
			
		}
	T* elem;
	int size = 0;
	int space;
};



template <typename T>
struct Vector
{
	Represent<T>* rep;
	Vector(int i) : rep(new Represent<T>(i)) 
	{
		
	}	
	void push_back(T t)
	{
		rep->elem[rep->size] = t;
	}
};

int main ()
{
	cout << sizeof(Vector<int>) << '\n';
	cout << sizeof(int*) << '\n';
	
	
	Vector<int> v(223);
	v.push_back(233);
	
	cout << v.rep->elem[0] << '\n';
	
	
	
	char c;
	cin >>c;
}