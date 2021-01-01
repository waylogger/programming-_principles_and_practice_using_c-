#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>
#include <D:\\Programms\\16\\ex\\8- Val\\value.cpp>

class Conv_window : public Window
{
	public:
	Conv_window(Point p, int w, int h, const string&s);
	
	static void cb_quit(Address,Address pw) {reference_to<Conv_window>(pw).quit();}
	static void cb_clear(Address,Address pw) {reference_to<Conv_window>(pw).clear();}
	
	static void cb_first_conv(Address,Address pw) {reference_to<Conv_window>(pw).first_conv();}
	static void cb_second_conv(Address,Address pw) {reference_to<Conv_window>(pw).second_conv();}
	static void cb_third_conv(Address,Address pw) {reference_to<Conv_window>(pw).thrird_conv();}
	static void cb_fourth_conv(Address,Address pw) {reference_to<Conv_window>(pw).fouth_conv();}
	
	
	void first_conv() 	{int i = val.get_int(); res.put(i*b.num(0).see_forward());}
	void second_conv() 	{int i = val.get_int(); res.put(i*b.num(1).see_forward());}
	void thrird_conv() 	{int i = val.get_int(); res.put(i*b.num(2).see_forward());}
	void fouth_conv() 	{int i = val.get_int(); res.put(i*b.num(3).see_forward());}
	
	
	void quit() {hide();}
	void clear() { quit();}
	private:
	Value::Val b{"D:\\Programms\\16\\ex\\8- Val\\data\\1.txt"};
	In_box val;
	Out_box res;
	Menu bank;
	Button button_quit;
	Button button_clear;
	
};

Conv_window::Conv_window(Point p, int w, int h, const string&s)
: 
Window{p,w,h,s},
button_quit{Point{w-70,0},70,20,"quit",cb_quit},
val{Point{100,0},100,100,"Insert val"},
res{Point{300,0},100,100,"See result"},
bank{Point{100,100},200,20,Menu::vertical,"Bank"},
button_clear{Point{300,100},100,80,"Clear",cb_clear}
{
	
	attach(button_quit);
	attach(val);
	attach(res);
	if (b.number_of_val()>0)
	bank.attach(new Button{Point{0,0},0,0,b.num(0).see_first()+" to " + b.num(0).see_second(),cb_first_conv});
	if (b.number_of_val()>1)
	bank.attach(new Button{Point{0,0},0,0,b.num(1).see_first()+" to " + b.num(1).see_second(),cb_second_conv});
	if (b.number_of_val()>2)
	bank.attach(new Button{Point{0,0},0,0,b.num(2).see_first()+" to " + b.num(2).see_second(),cb_third_conv});
	if (b.number_of_val()>3)
	bank.attach(new Button{Point{0,0},0,0,b.num(3).see_first()+" to " + b.num(3).see_second(),cb_fourth_conv});

	attach(bank);
	attach(button_clear);
	
	
}

int main () try {
	Conv_window cw {Point{20,20},800,600,"Kansas"};
	
	gui_main();
	
	
	
	




}
catch (exception& e){
	cerr << e.what() << '\n';
	keep_window_open();
}
catch (...){
	cerr << "Unknown error" << '\n';
	keep_window_open();
}