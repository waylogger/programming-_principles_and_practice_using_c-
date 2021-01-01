#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>

class A{
protected:
A() {}
};

class A1 : A {
public:
A1 () {}
};

int main () try {

A1 a;


}
catch (exception& e){
	cerr << e.what() << '\n';
	keep_window_open();
}
catch (...){
	cerr << "Unknown error" << '\n';
	keep_window_open();
}