

#include <std_lib_facilities.h>

namespace V
{

template <typename T, typename A = allocator<T>>
class vector_base
{
	public:
	int s;
	int space;
	T* elem;
	A alloc;
	
	vector_base(const A& a, int n) : alloc{a}, elem{a.allocate(n)},s(n),space(n) {}
	
	~vector_base () { alloc.dealloccate(elem,space);}
	
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
	
	

template <typename T, typename A = allocator<T> >
class vector : public vector_base<T,A>
{
/* 	private:
	int s;
	int space;
	T* elem;
	A alloc; */
	public:
	
	explicit vector(int a) : s{a}, space(a), elem{new T[a]} 
	{
		for (int i =0; i < a; ++i)
		elem[i] = T();
	};
	
	vector(initializer_list<T> lst) : s(lst.size()), space(lst.size()), elem{new T[s]}
		{
			copy(lst.begin(),lst.end(),elem);
		}
		
	vector() : s{0}, space {0}, elem{nullptr} {};
	
	void reserve(int newalloc);
	void reserve(int newalloc,const T&);
	void resize(int newsize);
	void resize(int newsize, const T&);
	void push_back(const T& d);
	
	vector(const vector& q);
	vector& operator= (const vector&);
	
	
	vector(vector&&);
	vector& operator= (vector&&);
	
	
	~vector() {delete[] elem;}
	
	T get(int i)  const {return elem[i];};
	void set(int i, T& d) {elem[i] = d;}
	
	T& operator[] (int n) { 
	if (n < 0 || n >= s) throw Range_error{n};
	return elem[n];
	}
	T& operator[] (int n) const {
		if (n < 0 || n >= s) throw Range_error{n};
		return elem[n];
		}
 	
	int size() const {return s;}
	int capacity() const {return space;}
};

}