#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>

class B1 {
	public:
	virtual void vf() {cout << "B1::vf() ";}
	virtual void pvf()=0 {cout << "B1::pvf() ";}
	void f() {cout << "B1::f() ";}
};

class D1 : public B1
{
	public:
	void vf() override {cout << "D1::vf() ";}
	void pvf() override {cout << "D1::pvf() ";}
	void f() {cout << "D1::f() ";}
	
};

class D2 : public D1
{
	public:
	void vf() override {cout << "D2::vf() ";}
	void pvf() override {cout << "D2::pvf() ";}
	void f() {cout << "D2::f() ";}
}; 


int main () 
try
{
/*B1 b1;
b1.vf();
b1.f();

D1 d1;
d1.vf();
d1.f();
cout << '\n';
B1& b2 = d1;
b2.vf();
b2.f();*/

D2 d2;
d2.vf();
d2.f();
d2.pvf();

keep_window_open();
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