

#include <iostream>

using namespace std;

template<typename T>
class unique_ptr
{
	public:
	T* t = nullptr;
	
	unique_ptr(const T& tt) : t(new T(tt)) {}
	~unique_ptr() {delete[] t;}
	T& operator* () {return *t;};
	unique_ptr* operator->() {return this;};
	T* release() const {return t;}
	
};

void f()
{
	unique_ptr<int>q(531);
	cout << *q->t << '\n';
}

int main ()
{
	
	
	f();
	char c;
	cin >> c;
	
}