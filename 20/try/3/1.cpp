#include <iostream>
#include <memory>

using namespace std;
namespace My{

template<typename T, typename A = allocator<T>>
class vector_base
{
	A alloc;
	T* elem;
	int sz;
	int space;

	
	public:
	
	vector_base(A& a, int n) : alloc{a}, elem{a.allocate(n)}, sz{0},space{n}
		{};
	
	~vector_base()
	{
		alloc.deallocate(elem,space);
		//cout << "destructor - " << space << '\n';
	}
	
	int size_base() const {return sz;}
	int space_base() const {return space;}
	A allocate() {return alloc;}
	T* element() {return elem;}
	void newsize(int i) {sz = i;}
	void newspace(int i) {space = i;}
	
	vector_base& operator=(const vector_base& vb) 
	{
		this->sz = vb.sz;
		this->space = vb.space;
		this->alloc = vb.alloc;
		this->elem = alloc.allocate(space);
		
		for (int i =0; i <sz; ++i)
		{
			this->alloc.construct(&this->elem[i],vb.elem[i]);
		}
		
		return *this;
	}

	
};

template <typename T, typename A = allocator<T>>
class vector : private vector_base<T,A>
{
	A a;
	public:
	vector(int n = 0) : vector_base<T,A>(a,n)
	{
		
	}
	
	void reserve(int newalloc);
	void resize(int newsize);
	void push_back(T t);
	void push_front(T t);
	int size() const {return this->size_base();}
	
	T& operator[] (int n) {return this->element()[n];}
	const T& operator[](int n) const {return this->element()[n];}
};

template <typename T, typename A = allocator<T>>
void vector<T,A>::reserve(int newalloc)

{
if (newalloc <= this->space_base()) return;

vector_base<T,A> b
{this->allocate(),newalloc};
b.newsize(this->size());

 uninitialized_copy(this->element(),&this->element()[this->size_base()],b.element());



 for (int i =0; i < this->size_base(); ++i)
	 this->allocate().destroy(&this->element()[i]);

 swap<vector_base<T,A>>(*this,b);

}



template<typename T, typename A = allocator<T>>
void vector<T,A>::resize(int newsize)
{
	reserve(newsize);
	
	for (int i = this->size_base(); i < newsize; ++i)
	{
		
		this->allocate().construct(&this->element()[i],T{});
		
	}
	this->newsize(newsize);
}


template <typename T, typename A = allocator<T>>
void vector<T,A>::push_back(T t)
{
	if (this->space_base() == 0)
	{
		this->reserve(8);
	}		
	else if (this->size_base() == this->space_base()) 
	{
	
		this->reserve(this->size_base()*2);
	
	}
	allocate().construct(&element()[this->size_base()],t);
	this->newsize(this->size_base()+1);
	
	
}


template<typename T, typename A = allocator<T>>
void vector<T,A>::push_front(T t)
{
	if (this->space_base() == 0) 
	{
		this->reserve(8);	
	}
	else if(this->space_base() == this->size_base()) 
		this->reserve(this->space_base()*2);
	
	for (int i = size_base(), j = i-1; j >= 0; --i, --j)
	{
		this->allocate().destroy(&this->element()[i]);
		this->allocate().construct(&this->element()[i],this->element()[j]);
	}
	
	this->allocate().construct(&this->element()[0],t);
	
	this->newsize(this->size_base()+1);
}

}

using My::vector;
int main ()
{
	vector<int>q;
	
	for (int i =0 ; i < 500; ++i)
	{
		q.push_front(i);
	}
	
	 for (int i =0; i <q.size(); ++i)
	{
		cout << q[i] << ' ';
	}
	 
	char c;
	cin >> c;
}