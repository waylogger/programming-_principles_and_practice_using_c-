#include <iostream>
#include <vector>

using namespace std;



template <typename T>
class counted_ptr
{
	T* t = nullptr;
	int* count = nullptr;
	public:
	
	counted_ptr(T tt) : t(new T(tt)), count(new int(1)) {}
	
	counted_ptr(T* tt, int* c) : t(tt), count(c) {++*count;}
		
	~counted_ptr()
	{
		 if (*count > 1)
		{
			--*count;
			return;
		}
		//cout << "Destr\n";
		delete t; 
		delete count;
	}
	counted_ptr(const counted_ptr<T>&);
	counted_ptr* operator-> () 	{return this;}
	counted_ptr& operator=(const counted_ptr<T>&);
	
	T& operator*() {return *t;};
	
	T& operator[](int q) {return t[q];}
	
	T* release() 
	{
		*count = *count+1;
		return t;
	}
	
	int get_c() const {return *count;}
	int* get_pc() {return count;}
	T* get() const {return t;}
	void set(T k) 
	
	{
		*t = k;

	}
	
	
};

template <typename T>
 counted_ptr<T>::counted_ptr(const counted_ptr<T>& t)
{
	this->t = t.t;
	this->count = t.count;
	++*count;
}

template <typename T>
counted_ptr<T>& counted_ptr<T>::operator=(const counted_ptr<T>& t)
{
 	delete this->t;
	delete count;
	this->t = t.t;
	this->count = t.count;
	++*count; 
	return *this;
	
}


struct Client
{
	counted_ptr<bool> s;
	Client(counted_ptr<bool> ss, bool c) : s(ss) {s.set(c);};
	void off() {s.set(false);}
	
	
};
 
void f ()
{
		counted_ptr<bool> s(true);
	

	Client c1 = {s,true};
	Client c2 = {s,true};
	Client c3 = {s,false};
	Client c4 = {s,true};
	Client c5 = {s,true};
	c5.off();
	if (!*s->get()) cout << "OFF\n";
	if (*s->get()) cout << "ON\n";
	
	
	//cout << s->get_c() << '\n';
}

int main ()

{
f();
	
	
	char c; cin >>c;
	
	
	
}