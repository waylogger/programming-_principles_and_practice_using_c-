#include <iostream>
//#include <vector>
#include <string>

using namespace std;

template <typename T>
struct Represent
{
	T* elem = nullptr;
	int sz = 0;
	int space = 0;
	
	Represent(int i = 0) : elem {new T[i]}, space {i}, sz{i}
		{
			for (int k =0; k < i; ++k)
			{
				elem[k] = T{};
			}
		}
		
	void reserve (int newalloc)
	{
		if (newalloc <= space) return;
		T* e = new T[newalloc];
		for (int i =0; i < sz;++i)
		{
			e[i] = elem[i];
		}
		delete[] elem;
		elem = e;
		space = newalloc;
	}
	
	void resize(int newsize)
	{
		if (newsize >= sz) reserve(newsize);
		
		for (int i = sz; i < newsize;++i )
		{
			elem[i] = T{};
		}
		sz = newsize;
	}
		
};


template <typename T>
struct vector
{
	Represent<T>* represent = nullptr;
	vector(int i) : represent {new Represent<T>{i}}
		{}
		
		
	void reserve(int newalloc) {represent->reserve(newalloc);}	
	void resize(int newsize) {represent->resize(newsize);}
		
	};


int main()
{
	
vector<int> q(5);	
q.reserve(24);
q.resize(424);

cout << q.represent->sz << '\n';
cout << q.represent->space << '\n';

char c;
cin >> c;
	
}