#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>

#include <D:\\Programms\\16\\ex\\6 - cloack\\Turn.h>
#include <D:\\Programms\\16\\ex\\6 - cloack\\Time.h>


int main () try {

Time::Watch_window ww{Point{20,20},800,600,"Kansas"};

gui_main();

keep_window_open();
	}



catch (exception& e){
	cerr << e.what() << '\n';
	keep_window_open();
}
catch (...){
	cerr << "Unknown error" << '\n';
	keep_window_open();
}