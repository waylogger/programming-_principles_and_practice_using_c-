#include <std_lib_facilities.h>


class A 
{
	string a;
	public:
	A(string aa) : a(aa) {see_a();}
	void set_a (const string& e) {a = e;}
	void see_a() {cout << a << '\n';}
};


int main () 
{
	string s = "a";
	A a{s};
	a.set_a("b");
	a.see_a();
	keep_window_open();
	
}