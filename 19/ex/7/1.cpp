
#include <D:\\Programms\\19\\ex\\7\\1.h>


template <typename T>
 VECTOR<T>::VECTOR(const VECTOR& v) : s{v.s}, elem{new T[s]}
{
	copy(v.elem,v.elem+s,elem);
}


template <typename T>
VECTOR<T>& VECTOR<T>::operator= (const VECTOR& v)
{
	if (this == &v) return *this;
	if (v.s <= this->space)
	{
		
		for (int i = 0; i < v.s; ++i)
		{
			
			elem[i] = v.elem[i];
			
		}
		s = v.s;
		return *this;
	}
	
	allocator<T> a;
	T *p = a.allocate(v.size());
	
 	for (int i = 0; i < v.s; ++i)
		{
			a.construct(&p[i],v[i]);
		}
	
	for (int i =0; i < s;++i) a.destroy(&elem[i]);
		
	elem = p;
	space = s = v.s; 

	return *this;
}

template <typename T>
 VECTOR<T>::VECTOR(VECTOR&& v) : elem{v.elem}, s{v.s}
{
	v.elem = nullptr;
	v.s = 0;
}

 template <typename T>
 VECTOR<T>&  VECTOR<T>::operator= (VECTOR&& v)
{
	delete[] elem;
	
	elem = v.elem;
	s = v.s;
	
	v.elem = nullptr;
	v.s = 0;
	
	return *this;
}

template <typename T>
void copy( VECTOR_base<T>& vb1, VECTOR_base<T>& vb2 )
{
	
	for (int i = 0; i < vb1.s; ++i )
	{
		vb2.elem[i] = vb1.elem[i];
	}
	
	vb2.s = vb1.s;
	
}


template <typename T>
void  VECTOR<T>::reserve(int newalloc)
{
	if (newalloc <= this->space) return;
	
	vector<T> b (newalloc);
	copy<T>(*this,b);
	
	swap<VECTOR_base<T>>(*this,b);

}




template <typename T>
void  VECTOR<T>::resize(int newsize)
{
	this->reserve(newsize);
	for (int i = s; i < newsize; ++i)
	{
		elem[i] = T();
	}
		
	s = newsize;
}

template <typename T>
void  VECTOR<T>::resize(int newsize,const T& t)
{
	this->reserve(newsize,t);
	for (int i = s; i < newsize; ++i)
	{
		elem[i] = t;
	}
	
	s = newsize;
}

template <typename T>
void  VECTOR<T>::push_back(const T& d)
{
	
	if (space == 0) reserve(8);
	else if (s == space) 
	{
		reserve(2*space);
	}
	++s;
	
	elem[s-1] = d;
	
}

template <typename T>
void print(const  VECTOR<T>&v)
{
	for (int i =0; i < v.size(); ++i)
	{
		cout << v[i] << '\n';
	}
}

void f()

{
	vector<int> q(0);
	for (int i =0; i < 100;++i)
		q.push_back(i);
	
	vector<int> nq(0);
	for (int i =0; i < 1000 ;++i)
		nq.push_back(i*2);
	
	//print(nq);
	
	q = nq;
	
	print(q);
	
}


int main ()
try
{

f();
char c;
cin >> c;

}

catch( Range_error& e)
{
	cerr << e.what() << "-" << e.inx() << '\n';
	char c; cin >> c;
}