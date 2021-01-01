#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>
class Scale
{
	int cbase;
	int vbase;
	double scale;
	public:
	Scale(int b,int vb, double s) :cbase(b), vbase(vb), scale(s)
	{}
	int operator () (int v) 
	{return cbase+(v-vbase)*scale;}
};

int main () try {




}
catch (exception& e){
	cerr << e.what() << '\n';
	keep_window_open();
}
catch (...){
	cerr << "Unknown error" << '\n';
	keep_window_open();
}