#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>

/*
пока не ясно отчего в программе такие тормоза

*/
int main () try {
Simple_window win{Point{20,20},800,600,"Kansas"};

Image im {Point{40,150},"D:\\Programms\\16\\ex\\7 - airplane\\data\\1.jpg"};
win.attach(im);
bool c {false};
win.wait_for_button();

while (true)
{
	
	im.move(1,0);
		
		while (!c)
		{
		Sleep(1);
		Fl::wait(); 
		c = true;
		} 
		c = false;
	
	
	
}





}
catch (exception& e){
	cerr << e.what() << '\n';
	keep_window_open();
}
catch (...){
	cerr << "Unknown error" << '\n';
	keep_window_open();
}