#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>
#include <D:\\Programms\\16\\ex\\9 -calc\\calc.cpp>

/*
Зерно программы не в интерфейсе, а в модернизации калькулятора, путем добавления функции трансформирующей строку,
полученную из виджета In_box в поток лексемм - функция double Calcs::calculation(string& s);

*/



struct Calc_window : Window
{
	Calc_window(Point p, int w, int h, const string& s);
	
	static void cb_quit (Address, Address pw) {reference_to<Calc_window>(pw).quit();}
	void quit () {hide();}
	
	static void cb_calc (Address, Address pw) {reference_to<Calc_window>(pw).calc();}
	void calc ();
	private:
	Button button_calc;
	Button button_quit;
	In_box interf;
	Out_box res;
	
};

void Calc_window::calc ()
{
	string s = interf.get_string();
	double d = Calcs::calculation(s);
	res.put(d);
	
}

Calc_window::Calc_window(Point p, int w, int h, const string& s) :
Window{p,w,h,s},
button_quit{Point{w-70,0},70,20,"quit",cb_quit},
interf{Point{w/2-100,0},400,50,"expression"},
res{Point{w/2-100,50},400,50,"result"},
button_calc{Point{w/2-200,100},400,50,"calculation",cb_calc}
{
	attach(button_quit);
	attach(res);
	attach(interf);
	attach(button_calc);
}


int main () try {

Calc_window cw{Point{20,20},800,600,"Kansas"};

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