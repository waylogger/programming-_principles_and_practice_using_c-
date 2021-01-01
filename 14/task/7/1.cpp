#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>


class B2 {
	public:
	virtual void pvf()=0 {}
};

class D21 : public B2 {
	void pvf () override { cout << s << '\n';}
	private:
	string s;
};

class D22 : public B2 {
	void pvf () override { cout << i << '\n';}
	private:
	int i;
};

void f(B2& b2)
{
	b2.pvf();
}


int main () 
try
{
D21 d21;
D22 d22;
f(d21);
f(d22);

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