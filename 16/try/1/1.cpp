#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>

class New_window : Window
{
	public:
	New_window(const Point& p, const int& w, const int& h, const string& s) 
	:	Window (p,w,h,s), b(Point{w/2,h/2},50,50,"Kansas", [] (Address, Address pw)
		{
			reference_to<New_window>(pw).wait();
		}) 
	{
		
	}
	void wait() { cout << "5\n"; while (true) Fl::wait();}
	private:
	Button b;
	
};


int main () try {

New_window nw {Point{20,20},800,600,"Kansas"};
nw.wait();

}
catch (exception& e){
	cerr << e.what() << '\n';
	keep_window_open();
}
catch (...){
	cerr << "Unknown error" << '\n';
	keep_window_open();
}