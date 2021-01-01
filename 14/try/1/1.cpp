#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>

struct B 
{
virtual void f() const { cout << "B::f "; }
void g() const  { cout << "B::g "; }	
};

struct D : B
{
	void f() const override { cout << "D::f "; }
	void g() const { cout << "D::g "; }	
};

struct DD : D
{
	void f() { cout << "DD::f "; }
	void g() const { cout << "DD::g "; }	
};

void call (const B& b)
{
	b.f();
	b.g();
}

int main () 
try
{
	B b;
	D d;
	DD dd;
	
	call(b);
	call(d);
	call(dd);
	
	b.f();
	b.g();
	
	d.f();
	d.g();
	
	dd.f();
	dd.g();
	
	
}
catch (exception& e)
{
	cerr << e.what() << '\n';
	keep_window_open();
}

catch (...)
{
	cerr << "Unknown error" << '\n';
	keep_window_open();
}