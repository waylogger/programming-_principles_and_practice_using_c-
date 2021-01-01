#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>

class A
{
public:
A() {see();}
void seem () {cout << s << '\n';}
protected:
virtual void see () =0; //{s = "Punk not dead";}
string s;
};

class B : public A
{
	
	public:
	void see () override {s = "Coy alive!";}
};


int main () try {


//vector<A>va;
B b;
b.see();
//va.push_back(b);
b.seem();


char s;
cin >> s;

}
catch (exception& e){
	cerr << e.what() << '\n';
	keep_window_open();
}
catch (...){
	cerr << "Unknown error" << '\n';
	keep_window_open();
}