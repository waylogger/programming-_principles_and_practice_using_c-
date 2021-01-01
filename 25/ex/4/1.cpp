#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cctype>
using namespace std;

const double sym = -999999;
const double bad_num = -9999999;
const char not_good = 'G';
const char number = '8';
const char empt = 'E';
const char newline = '\n';
const char quit = 'q';
const char let = 'L';
const char key = 'K';
const char space = ' ';

const string prompt = "> ";
const string result = "= ";
const string declkey = "let";


//------------------------------------------------------------------------


struct Token{
	char kind;
	double val = 0;
	string name;
	
	explicit Token(char c) : kind{c}, val {sym} {}
	explicit Token(double d) : val{d}, kind{number} {}
	explicit Token(string s) : kind{key}, name{s} {}
};


//------------------------------------------------------------------------


struct Token_stream{
	
	istream& ist;
	bool status;
	Token buffer;
	Token_stream(istream& i = cin) : ist{i}, full{false}, buffer{empt}, status{true} {}
	Token get();
	
	bool get_status() {return status;}
	void set_status(bool s) {status = s;}
	
	bool full;
	void putback(Token c);
	
};


//------------------------------------------------------------------------



void token_stream_issue(Token_stream& ts, const string& s){
	ts.set_status(false);
	
	ts.ist.clear();
	const int in_buff = ts.ist.rdbuf()->in_avail();
	ts.ist.ignore(in_buff);
	
	cerr << s << '\n';
	if (!ts.ist) 
		exit(0);

} 


//------------------------------------------------------------------------


void Token_stream::putback(Token c){
			
		if (!status)
			return;
		else if (!full){
			buffer = c;
			full = true;
		}
		
		else{
			token_stream_issue(*this,"Buffer is full");	
		}
				
	}

	
//------------------------------------------------------------------------



Token Token_stream::get(){
	if (!status)
		return Token{bad_num};
	
	if (full){
		full = false;
		return buffer;
	}
	char c;
	ist.get(c);
	switch(c){
		case '0': case '1': case '2':
		case '3': case '4': case '5':
		case '6': case '7': case '8':
		case '9':{
			ist.putback(c);
			double d = 0;
			ist >> d;
			return Token{d};		
		}
		case space: 
		case newline:
		case '+': 
		case '-': 
		case '=':
		case '*': 
		case '/':
		case '(':
		case ')':
		case '%':
		case quit:
		case '~':
		case '&':
		case '|':
		case '^':
			return Token{c};
		default:
		//------------------------------------------------------------------------
			if (isalpha(c)){
				string s;
				s += c;
				while (ist.get(c) && (isalpha(c) || isdigit(c))){
					s += c;
				}
				if (s == declkey){
					ist.putback(c);
					return Token{let};
					}
				else 
					ist.putback(c);
					return 	Token{s};
				
			}
		//------------------------------------------------------------------------
			token_stream_issue(*this,"Unknown charasters is stream");
			return Token{not_good};
	}
	return Token{0.0};
}


//------------------------------------------------------------------------
double expression(Token_stream&ts, map<string,double>& var_table);
//------------------------------------------------------------------------
bool mantissa(double d){
	int i = d;
	
	return d - i > 0 ? true : false;
}

double primary(Token_stream&ts, map<string,double>& var_table){
	if (!ts.get_status())
		return bad_num;
	//------------------------------------------------------------------------
	Token t = ts.get();
	switch(t.kind){
		case '(':{
			
			double d = expression(ts,var_table);
			t = ts.get();
			if (t.kind != ')'){
				token_stream_issue(ts,"Unexpected sequence - ')' - is expected	");
				return bad_num;
			}
			return d;
		}
		case number:
			return t.val;
		case '-':
			return -primary(ts,var_table);
		case '+':
			return +primary(ts,var_table);
		case key:{
			auto f = var_table.find(t.name);
			if (f == var_table.end())
				token_stream_issue(ts,"Varaible is not defined");
			else 
				return (*f).second;
			
		}
		case '~':{
			double d = primary(ts,var_table);
			if (mantissa(d))
				token_stream_issue(ts,"Lost of data");
			return ~int(d);
		}
			
		default:
			
			token_stream_issue(ts,"primary - is expected");
	}	
	return t.val;
}


//------------------------------------------------------------------------



double term(Token_stream& ts, map<string,double>& var_table){
	if (!ts.get_status())
		return bad_num;
	//------------------------------------------------------------------------
	double left = primary(ts,var_table);
	Token t = ts.get();
	while (true){
		switch(t.kind){
			case '*':{
				left *= primary(ts,var_table);
				t = ts.get();
			break;
			}
			case '/':{
				double d = primary(ts,var_table);
				if (d == 0)
					token_stream_issue(ts,"devide on zero");
				left /= d;
				t = ts.get();
			break;
			}
			case '%':{
				double d = primary(ts,var_table);
				if (d == 0)
					token_stream_issue(ts,"devide on zero");
				left = fmod(left,d);
				t = ts.get();
				break;
			}
			default:
				ts.putback(t);
				return left;
		}
	}
	return left;
}


//------------------------------------------------------------------------



double expression(Token_stream&ts, map<string,double>& var_table){
	if (!ts.get_status())
		return bad_num;
	//------------------------------------------------------------------------
	double left = term(ts,var_table);
	Token t = ts.get();
	while (true){
		switch(t.kind){
			case '+':{
				double d = term(ts,var_table);
				left += d;
				t = ts.get();
			break;	
			}
			case '-':{
				left -= term(ts,var_table);
				t = ts.get();
			break;
			}
			default:
			ts.putback(t);
			return left;
		}
	}
	return left;
}


//------------------------------------------------------------------------

double bits_op_and(Token_stream&ts, map<string,double>& var_table){
	if (!ts.get_status())
		return bad_num;
	//------------------------------------------------------------------------
	double left = expression(ts,var_table);
	Token t = ts.get();
	while (true){
		switch(t.kind){
			case '&':{
				double d = expression(ts,var_table);
				
				if (mantissa(d) || mantissa(left))
					token_stream_issue(ts,"Lost of data");
					t = ts.get();
				left = int(d)&int(left); 
			}
			default:{
				ts.putback(t);
				return left;
			}
			
			
		}
	}
	
	
}


//------------------------------------------------------------------------



double bits_op_xor(Token_stream&ts, map<string,double>& var_table){
	if (!ts.get_status())
		return bad_num;
	//------------------------------------------------------------------------
	double left = bits_op_and(ts,var_table);
	Token t = ts.get();
	while (true){
		switch(t.kind){
			case '^':{
				double d = bits_op_and(ts,var_table);
				
				if (mantissa(d) || mantissa(left))
					token_stream_issue(ts,"Lost of data");
					t = ts.get();
				left = (int(d))^(int(left)); 
			}
			default:{
				ts.putback(t);
				return left;
			}
			
			
		}
	}
	
	
}


//------------------------------------------------------------------------


double bits_op_or(Token_stream&ts, map<string,double>& var_table){
	if (!ts.get_status())
		return bad_num;
	//------------------------------------------------------------------------
	double left = bits_op_xor(ts,var_table);
	Token t = ts.get();
	while (true){
		switch(t.kind){
			case '|':{
				double d = bits_op_xor(ts,var_table);
				
				if (mantissa(d) || mantissa(left))
					token_stream_issue(ts,"Lost of data");
					t = ts.get();
					left = int(d)|int(left); 
			}
			default:{
				ts.putback(t);
				return left;
			}
			
			
		}
	}
	
	
}



//------------------------------------------------------------------------

double start_expr(Token_stream&ts, map<string,double>& var_table){
	return bits_op_or(ts,var_table);
}


//------------------------------------------------------------------------


bool is_declared(string name,map<string,double>& var_table){
	
	for ( const auto& a : var_table){
		if (a.first == name)
			return true;
	}
	return false;
}


//------------------------------------------------------------------------



bool define_name(string name, double val,map<string,double>& var_table){
	
	if (!is_declared(name,var_table)){
		var_table.insert(pair<string,double>{name,val});
		return true;
	}
	else
		return false;
	
}


//------------------------------------------------------------------------



double declaration(Token_stream& ts, map<string,double>& var_table){
	
	Token t = ts.get();
	if (t.kind != space){
		token_stream_issue(ts,"Expected space");
		return bad_num;
	}
	t = ts.get();
	if (t.kind != key){
		token_stream_issue(ts,"Expected name of varaible");
		return bad_num;
	}
	string name = t.name;
	
	Token t2 = ts.get();
	if (t2.kind != '='){
			
		token_stream_issue(ts,"Expected '=' ");
		return bad_num;
	}
	
	double d = start_expr(ts,var_table);
	if (ts.get_status())
		if (!define_name(name,d,var_table))
			token_stream_issue(ts,"variable is defined");

	return d;
	
}



//------------------------------------------------------------------------



double statement(Token_stream& ts, map<string,double>& var_table){
	Token t = ts.get();
	switch(t.kind){
		case let:
			return declaration(ts,var_table);
		default:
		ts.putback(t);
		return bits_op_or(ts,var_table);
	}
	
}


//------------------------------------------------------------------------



void calculate(){
	map<string,double>var_table;
	Token_stream ts{cin};
	//------------------------------------------------------------------------
	for (int i =0; i < 20; ++i){
		cout << "> ";		
		Token t = ts.get();
		if (t.kind == quit)
			break;
		else
			ts.putback(t);
	
		double d = statement(ts,var_table);
			
		if (ts.full && ts.buffer.kind != newline){
			token_stream_issue(ts,"Unexpected sequence");
			ts.full = false;
		}			
		else 
			ts.full = false;
		
		
		if (ts.get_status()) cout << result << d << '\n';
		else
			ts.set_status(true);
		
		
		
	}
	
}


//------------------------------------------------------------------------



int main(){
	
	calculate();
	
	
	
	
		
}







