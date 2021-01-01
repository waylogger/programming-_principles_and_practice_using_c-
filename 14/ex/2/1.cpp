#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>



int main () try {

Graph_lib::Circle c {Point {100,100},250};
Graph_lib::Circle d = c;


}
catch (exception& e){
	cerr << e.what() << '\n';
	keep_window_open();
}
catch (...){
	cerr << "Unknown error" << '\n';
	keep_window_open();
}