
#include <D:\\Programms\\19\\1.h>



template <typename T, typename A = allocator<T> >
V::vector<T,A>::vector(const vector& v) : s{v.s}, elem{new T[s]}
{
	copy(v.elem,v.elem+s,elem);
}


template <typename T, typename A = allocator<T> >
V::vector<T,A>& V::vector<T,A>::operator= (const vector& v)
{
	if (this == &v) return *this;
	
	if (v.s <= this->space)
	{
		for (int i = 0; i < v.s; ++i)
		{
			elem[i] = v.elem[i];
			s = v.s;
			
			return *this;
		}
	}
	
	
	T *p = new T[v.s];
	for (int i = 0; i < v.s; ++i)
		{
			p[i] = v.elem[i];
		}
	delete[] elem;
	elem = p;
	space = s = v.s;

	return *this;
}

template <typename T, typename A = allocator<T> >
V::vector<T,A>::vector(vector&& v) : elem{v.elem}, s{v.s}
{
	v.elem = nullptr;
	v.s = 0;
}

 template <typename T, typename A = allocator<T> >
V::vector<T,A>& V::vector<T,A>::operator= (vector&& v)
{
	delete[] elem;
	
	elem = v.elem;
	s = v.s;
	
	v.elem = nullptr;
	v.s = 0;
	
	return *this;
}
 
template <typename T, typename A = allocator<T> >
void V::vector<T,A>::reserve(int newalloc,const T& t)
{
	if (newalloc <= this->space) return;
	
	vector_base<T,A>
	b{this->alloc,newalloc};
	uninitialized_copy(b.elem,&b.elem[this->s],this->elem);
	for (int i =0; i<this->sz;++i)
	{
		this->alloc.destroy(&this->elem[i]);
	}
	swap<vector_base<T,A>>(*this,b);
}

template <typename T, typename A = allocator<T> >
void V::vector<T,A>::reserve(int newalloc)
{
	if (newalloc <= this->space) return;
	
	unique_ptr<T>d[newallic] {T()}; 
	for (int i =0; i < s;++i) alloc.construct(&d[i],elem[i]);
	for (int i =0; i < s;++i) alloc.destroy(elem[i]);
	alloc.deallocate(elem,space);
	elem = d;
	space = newalloc;
	
	
}
template <typename T, typename A = allocator<T> >
void V::vector<T,A>::resize(int newsize)
{
	this->reserve(newsize);
	for (int i = s; i < newsize; ++i)
	{
		alloc.construct(&elem[i],T())
	}
	for (int i = newsize; i < s; ++i)
	{
		alloc.destroy(&elem[i]);
	}
	s = newsize;
}

template <typename T, typename A = allocator<T> >
void V::vector<T,A>::resize(int newsize,const T& t)
{
	this->reserve(newsize,t);
	for (int i = s; i < newsize; ++i)
	{
		alloc.construct(&elem[i],t)
	}
	
	for (int i = newsize; i < s; ++i)
	{
		alloc.destroy(&elem[i]);
	}
	s = newsize;
}

template <typename T, typename A = allocator<T> >
void V::vector<T,A>::push_back(const T& d)
{
	if (space == 0) reserve(8);
	else if (s == space) reserve(2*space);
	alloc.construct(&elem[s],d);
	++s;
}

template <typename T, typename A = allocator<T> >
void print(const vector<T>&v)
{
	for (int i =0; i < v.size(); ++i)
	{
		cout << v[i] << '\n';
	}
}
struct No_def
{
	int q = 0;
	No_def(int s ) : q(s) {};
};




int main ()
try
{
	
	
	vector<double>s (25);
	
	s.push_back(35);
	
	cout << s[s.size()-1];
	
char c;
cin >> c;	
}

catch(V::Range_error& e)
{
	cerr << e.what() << "-" << e.inx() << '\n';
	keep_window_open();
}