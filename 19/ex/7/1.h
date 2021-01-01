

#include <iostream>
#include <string>
#include <cstdlib>
#include <memory>

#define vector VECTOR

using namespace std;


template <typename T>
class VECTOR_base
{
	public:
	int s = 0;
	int space =0;
	T* elem;
	
	VECTOR_base(int n) : elem{(T*)malloc(sizeof(T)*n)}, s(0),space(n) 
	{
		for (int i =0; i < n; ++i)
		{
			elem[i] = T();
		}
	}
	VECTOR_base() : s(0), space(0), elem(nullptr) {}
	
		
};


class Range_error
{
	string e = "Range error";
	int i =0;
	public:
	Range_error(int ii) : i(ii) {}  
	string what() const {return e;}
	int inx() const {return i;};
};
	
	

template <typename T>
class VECTOR : public VECTOR_base<T>
{

	public:
	
	using VECTOR_base<T>::VECTOR_base;
	
		
	void reserve(int newalloc);
	void resize(int newsize);
	void resize(int newsize, const T&);
	void push_back(const T& d);
	
	VECTOR(const VECTOR& q);
	VECTOR& operator= (const VECTOR&);
	~VECTOR()
	{
		free(elem);
	}
	
	
	VECTOR(VECTOR&&);
	VECTOR& operator= (VECTOR&&);
	
	
	T get(int i)  const {return elem[i];};
	void set(int i, T& d) {elem[i] = d;}
	
	T& operator[] (int n) { 
	if (n < 0 || n >= space) throw Range_error{n};
	return elem[n];
	}
	T& operator[] (int n) const {
		if (n < 0 || n >= space) throw Range_error{n};
		return elem[n];
		}
 	
	int size() const {return s;}
	int capacity() const {return space;}
};
