#include <FLTK\\FLTK.h>
#include <FLTK\\Window.h>
#include <FLTK\\GUI.h>
#include <FLTK\\Graph.h>
#include <sstream>
#include <cctype>
#include <iostream>
#include <My\\my_gauss.h>
using namespace Graph_lib;


//------------------------------------------------------------------------


template <typename A, typename B>
B changes (const A& a){
	B b;
	ostringstream ost;
	ost << a;
	istringstream ist {ost.str()};
	ist >> b;
	return b;
	
}


//------------------------------------------------------------------------


double correction_dim(const string& arg){
	string s = arg;
	
	if (s.size() == 0)
				return -999999;
	else if(s.size() == 1 && !isdigit(s[0]))
				return -999999;
	for (int i = 0; i < s.size(); ++i){
		if (i > 0 && !isdigit(s[i])){
				return -999999;
		}
		else if (i == 0 && !isdigit(s[i]) && s[i] != '-'){
				return -999999;
		}
	}
	
	double val = changes<string,double>(s);
	if (val > 10) val = 10;
	else if (val < 2) val = 2;
	
	return val;	
}


//-----------------------------------------------------------------------
double correction_elem(const string& arg){
	string s = arg;
	
	if (s.size() == 0)
				return -999999;
	else if(s.size() == 1 && !isdigit(s[0]))
				return -999999;
	for (int i = 0; i < s.size(); ++i){
		if (i > 0 && !isdigit(s[i])){
				return -999999;
		}
		else if (i == 0 && !isdigit(s[i]) && s[i] != '-'){
				return -999999;
		}
	}
	
	double val = changes<string,double>(s);

	
	return val;	
}



//------------------------------------------------------------------------

struct Gauss_window : Window{
	
	Vector_ref<In_box>v;
	Vector_ref<In_box>in_mat;
	Vector_ref<In_box>in_vec;
	Vector_ref<Button>buttons;
	Out_box* process_box = nullptr;
//------------------------------------------------------------------------
	Gauss_window() : Window{Point{500,200},800,600,"Gauss_window"} {
		size_range(800,600,800,600);
		v.push_back(new In_box{Point{0,0},100,25,""});
		buttons.push_back(new Button{Point{0,25},100,25,"Build",cb_build});
		buttons.push_back(new Button{Point{x_max()-100,0},100,25,"Exit",cb_exit});
		buttons.push_back(new Button{Point{x_max()-100,140},100,100,"Apply",cb_calc});
		process_box = new Out_box{Point{100,360},590,220,""};
		
		attach(*process_box);
		for (int i =0; i < v.size(); ++i)
			attach(v[i]);
		
		for (int i =0; i < buttons.size(); ++i)
			attach(buttons[i]);
		
		
	}
	
~Gauss_window(){delete process_box;}
	
//------------------------------------------------------------------------
	void w_exit(){exit(0);}
	void build();
	void clear_of_box();
	void calc();
//------------------------------------------------------------------------
	static void cb_exit(Address, Address pw) {reference_to<Gauss_window>(pw).w_exit();}
	static void cb_build(Address, Address pw) {reference_to<Gauss_window>(pw).build();}
	static void cb_calc(Address, Address pw) {reference_to<Gauss_window>(pw).calc();}
	
};


//------------------------------------------------------------------------


void Gauss_window::clear_of_box(){
	if (in_mat.size() != 0) {
		for (int i = 0; i < in_mat.size(); ++i)
			detach(in_mat[i]);
		in_mat.erase();
	}
	
	if (in_vec.size() != 0) {
		for (int i = 0; i < in_vec.size(); ++i)
			detach(in_vec[i]);
		in_vec.erase();
	}
}


void Gauss_window::build(){
	process_box->put("");
	int val = correction_dim(v[0].get_string());
	//------------------------------------------
	clear_of_box();
	//------------------------------------------
	int x = 50;
	int y = 50;
	const int x_step = 50;
	const int y_step = 30;
	//------------------------------------------
	for (int i =0; i < val; ++i)
	{
		for (int j = 0; j < val; ++j){
			in_mat.push_back(new In_box{Point{x+=x_step,y},x_step,y_step,""});
		}
		y += y_step;
		x = x_step	;
	}
		y = 50;
		x = 140 + val * x_step;
	for (int i =0; i < val; ++i){
		in_vec.push_back(new In_box{Point{x,y},x_step,y_step," = "});
		y += y_step;
	}
	//------------------------------------------
	for (int i =0 ; i < in_vec.size(); ++i)
		attach(in_vec[i]);
	for (int i =0 ; i < in_mat.size(); ++i)
		attach(in_mat[i]);
	redraw();
}


struct Bad_input{
	Bad_input(Out_box* ob, const string& m = "\t\t\t\t\t\t\t\tBad_input\n"){
		ob->put(m);
	}
};



string vec_input(const vector<double>& d) {
	string s;
	vector<string>vs;
	for (int i =0; i < d.size(); ++i){
		vs.push_back(changes<double,string>(d[i]));
	}
	
	s += "\t\t\t\t";
	for (int i =0; i < vs.size(); ++i){
		s += vs[i] += '\t';
	}
	s += '\n';
	
	return s;
}




void Gauss_window::calc()try {
	process_box->put("");
	const int dim = in_vec.size();
	double* m = new double[in_mat.size()];
	double* v = new double[in_vec.size()];
	for (int i =0; i < in_mat.size(); ++i){
		double k = correction_elem(in_mat[i].get_string());
		if (k != -999999) {
			m[i] = k; 
		}
		else throw Bad_input{process_box};
	}
	for (int i =0; i < in_vec.size(); ++i){
		double k = correction_elem(in_vec[i].get_string());
		if (k != -999999) {
			v[i] = k;
		}
		else throw Bad_input{process_box};
	}

	vector<string>text_var;
	vector<string>right;
	auto p = uses_of_gauss(m,v,dim,text_var,right);
	string output = vec_input(p);
	
	vector<string> mat;
	
	for (int i =0, j = 0, k =0; i < text_var.size(); ++i, ++j){
		mat.push_back(text_var[i]);	
		if (j == dim-1){
			mat.push_back(right[k]);
			j = -1;
			++k;
		}
	}
	
	for (int i = right.size()-dim; i < right.size(); ++i){
		mat.push_back(right[i]);
	}
			
	
	string res;
	int n = dim;
	
	
	for (int i =0, j =0, k = 0; i < mat.size(); ++i, ++j){
			res += mat[i] += '\t';
			
			if (j == n){
				res += '\n';
				j = -1;
				++k;
			}
			if (k == n){
				res += "\n";
				k = 0;
			}
		
		}
			
	process_box->put(res);
	
}
catch(Bad_input& b){
}

 

int main(){
	
Gauss_window gw;	
	
gui_main();	
	
	
	
	
	
}
