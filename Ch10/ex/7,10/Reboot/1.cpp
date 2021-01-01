/*

Вычисление
Утверждение
Печать
Выход
Вычисление Утверждение



Утверждение
Определение
Выражение

Определения
"let" Имя "=" Выражение
"const" Имя "=" Выражение

Печать
\n

Выход
quit

Выражение:
Терм
Выражение + Терм
Выражение - Терм



Терм:
Первичное выражение
Терм * Первичное выражение
Терм / Первичное выражение
Терм % Первичное выражение

Первичные выражения:
Число
( Выражение )
! Выражение
| Выражение
Имя = Выражение
Имя
+ Первичное выражение
- Первичное выражение

Число
Число с плавающей точкой

Имя
Латинские символы обоих регистров
Целые Числа от 0 до 9

*/
#include <std_lib_facilities.h>
#include <D:\GD\Storage\Programming\Practice\C++\Rep\Roman\Roman.h>

const string Help = "Help";
const string help = "help";
const char quit   = 'q';    
const char let    = 'L';    // declaration token
const char con    = 'C';    // const declaration token
const char name   = 'a'; 
const string declkey = "let";		
const string constkey = "const";
const string qt = "quit";
const char Hp = 'H';
const char hp = 'h';
const char number = '8';
const char print  = '\n'; 
const string result  = "= ";
const string prompt  = "> ";
const char way = 'd';
const double invisible = 9848428477598;


ifstream file_input(string s)
{
	ifstream ist {s};
	if (!ist) error ("Cant open file!");
	return ist;
}

ofstream file_output(string s)
{
	ofstream ost {s};
	if (!ost) error ("Cant open file!");
	return ost;
}


class Token
{
	public:
	char kind;
	double value;
	string name;
	string adress;
	Token () {}
	Token (string a) : adress(a), kind(way) {}
	Token (char c) : kind(c), value(0) {}
	Token (char c, double v) : kind (c), value (v) {}
	Token (char c, string n) : kind (c), name (n) {}
	
};


class Token_stream 
{
	public:
	Token_stream();
	Token get(ifstream& ist, bool fstream);
	void putback (Token t);
	void ignore (char c);
	private:
	bool full;
	Token buffer;
};

Token_stream::Token_stream() : full(false), buffer (0) 
{
	
}

void Token_stream::putback(Token t)
{
	if (full) error ("putback() into a full buffer");
	buffer = t;
	full = true;

}

Token Token_stream::get(ifstream& ist, bool fstream) 
{

	if (full)
	{
		full=false;
		return buffer;
	}
	char c = ' ';
	if (!fstream) {cin.get(c);}
	if (fstream)	{ist.get(c);}

	
	switch (c)
	{
		case '(': case ')':
		case '+': case '-': 
		case '*': case '/': 
		case '%': case '=':
		case ' ':
		case new_line:
							{
								return Token (c);
							}
		
		case '0': case '1': case '2':
		case '3': case '4': case '5':
		case '6': case '7': case '8':
		case '9':
		case '.':
		{
			int val;
			if (!fstream ) {cin.putback(c);	cin >> val;}
			if (fstream ) {ist.putback(c);	ist >> val;}
								return Token(number, val);
		}
		
		case 'I': case 'V': case 'X':
		case 'L': case 'C': case 'D':
		case 'M':
			{
				int i =0;
				if (!fstream)
				{
				cin.putback(c);	string s = "";	while (cin.get(c) && isalpha(c)) s+=c;
				cin.putback(c);	 i= roman_to_int (s);
				}
				if (fstream)
				{
				ist.putback(c);	string s = "";	while (ist.get(c) && isalpha(c)) s+=c;
				ist.putback(c);	i = roman_to_int (s);
				}
								return Token(number,i);
			
			
			}
		
		
		default:
		if (isalpha(c))
		{
			string s;
			s+=c;
			if (!fstream)	 	while (cin.get(c) && (isalpha(c) || isdigit(c) || c=='_')) {s+=c; }
			if (fstream) 		while (ist.get(c) && (isalpha(c) || isdigit(c) || c=='_')) {s+=c; }
								
			if (!fstream) 		cin.putback(c);
			if (fstream) 		ist.putback(c);
			if (s==declkey) 	return Token(let);
			if (s==constkey) 	return Token (con);
			if (s==Help) 		return Token (Hp, name);
			if (s==help)		return Token (hp, name);
			if (s==qt) 			return Token (quit, name);
			if (s=="from")		{return Token (way);}
			
								return Token(name,s);
				
		}
			error ("Bad token");
		}
	return Token(c);
}


void Token_stream::ignore(char c)
{
	if (full & c==buffer.kind )
	{
		full = false;
		return;
	}
	full=false;
	
	char ch;
	while (cin>>ch)
		if (ch==c) return;
}

class Variable
{
	public:
	string name;
	double value;
	bool var;
Variable(string n, double v, bool va = true) : name(n), value (v), var(va) {}
};

class Symbol_table
{
	public:
	vector<Variable>var_table;
	double get_value(string s);
	void set_value(string s, double d);
	bool is_declared(string var);
	double define_name(string s, double val, bool var = true);
};

double Symbol_table::get_value(string s)
{
	for (int i =0; i <var_table.size();++i) 
		if (var_table[i].name == s)
		{
			return var_table[i].value;
		}
		return -1;
		error ("get:: underfined variable ", s);
}

void Symbol_table::set_value(string s, double d)
{
	for (int i = 0; i<var_table.size();++i)
	{
		if (var_table[i].name == s)
		{
			if (var_table[i].var == false) error (s, " is constant");
			var_table[i].value = d;
			return;
		}
	}
		error ("set: underfined variable ", s);
}

bool Symbol_table::is_declared(string var)
{
	for (int i = 0; i<var_table.size();++i)
	{
		if (var_table[i].name==var) return true;
	}
	return false;
}


double Symbol_table::define_name(string s, double val, bool var)
{
	if (is_declared(s)) error (s, " declared twice");
	var_table.push_back(Variable(s,val,var));
	return var;
}


void print_var (Symbol_table st)
{
	for  (int i =0; i<st.var_table.size();++i) 
	{
		cout << st.var_table[i].name << " - " <<st.var_table[i].value;
		if (st.var_table[i].var == true) cout << " variable\n";
		else cout << " const\n";
	}
}

void write_path(string& oname, string& iname,ifstream&ist, ofstream& ost, Token_stream& ts, bool fstream)

{
	string to;
	cin >> iname;
	cin >> to;
	if (to!="to") error ("to a expected");
	cin >> oname;
}

void calculate (Token_stream& ts, Symbol_table& st, Token k, ifstream&ist, ofstream& ost, bool fstream);
double expression(Token_stream& ts, Symbol_table& st, ifstream&ist, bool fstream);

double primary(Token_stream& ts, Symbol_table& st, ifstream&ist, bool fstream){
	Token t = ts.get(ist,fstream);
	switch (t.kind)	{
	case ' ': t=ts.get(ist,fstream); break;
	case '(': {
		double d = expression(ts,st,ist,fstream);	t=ts.get(ist,fstream);
		if (t.kind!=')') error (" ')' - expected");	return d;}
	case number:									return t.value;
	case name:	{
			Token next = ts.get(ist,fstream);
			if (next.kind=='=') 		{
					double d = expression(ts,st,ist,fstream);
					st.set_value(t.name, d);		return d;	}
			else{
					ts.putback(next);
													return st.get_value(t.name);	}				
		}
	case '-':										return - primary(ts,st,ist,fstream);
	case '+':										return primary(ts,st,ist,fstream);
	case way:
		{
			Token_stream ts; Symbol_table st;Token t;
			string oname, iname;ifstream ist; ofstream ost;
			write_path(oname,iname,ist,ost,ts,false);
			bool fstream = {true};
			ist = file_input (iname);ost = file_output (oname);
			calculate (ts,st,t,ist,ost,fstream);
		}
	case '\n':										return invisible;
	default: 
													error ("Primary expected");	}
return t.value;}





double term(Token_stream& ts, Symbol_table& st, ifstream&ist, bool fstream)
{
	double left = primary(ts,st,ist,fstream);
	Token t = ts.get(ist,fstream);
	
	while (true)
	{
		switch(t.kind)
		{
			case '*':
			left*=primary(ts,st,ist,fstream);
			t = ts.get(ist,fstream);
			break;
			case '/':
			{
				double d = primary (ts,st,ist,fstream);
				if (d==0) error ("divide by zero");
				left/=d;
				t = ts.get(ist,fstream);
				break;
			}
		default :
		
		ts.putback(t);
		return left;
		}
	}
}

double expression (Token_stream& ts, Symbol_table& st, ifstream&ist, bool fstream)
{
	double left = term(ts,st,ist,fstream);
	Token t = ts.get(ist,fstream);
	
	while (true)
	{
		switch (t.kind)
		{
			case '+':
			left+=term(ts,st,ist,fstream);
			t = ts.get(ist,fstream);
			break;
			case '-':
			left-=term(ts,st,ist,fstream);
			t = ts.get(ist,fstream);
			break;
			default:
			ts.putback(t);
			return left;
		}	
	}
}

double declaration (Token_stream& ts, Symbol_table& st, Token k, ifstream&ist, bool fstream)
{

	Token t = ts.get(ist,fstream);
	if (t.kind == ' ') t=ts.get(ist,fstream);
	if (t.kind != name) error ("name expected in declaration");
	string var_name = t.name;
	
	Token t2 = ts.get(ist,fstream);
	if (t2.kind == ' ') t2=ts.get(ist,fstream);
	if (t2.kind != '=') error ("= missing in declaration of ", var_name);
	
	double d = expression (ts, st,ist,fstream);
	st.define_name(var_name,d,k.kind==let);
	return d;
}

double statement (Token_stream& ts, Symbol_table& st, Token k, ifstream&ist, bool fstream)
{
	Token t = ts.get(ist,fstream);
	switch (t.kind)
	{
		case let:
		case con:
		return declaration(ts,st,k,ist,fstream);
	default:
	ts.putback(t);
	return expression(ts,st,ist,fstream);
	}
}

void clean_up_mess(Token_stream& ts)
{
	ts.ignore(print);
}

void calculate (Token_stream& ts, Symbol_table& st, Token k, ifstream&ist, ofstream& ost, bool fstream)
{
if (!fstream)	while (true)
	try {
		cout << prompt;
		Token t = ts.get(ist,fstream);
		while (t.kind == print) t=ts.get(ist,fstream);
		if (t.kind == quit) return;
		ts.putback(t);
		double d = statement(ts,st,k,ist,fstream);
		if (d!=invisible) cout 	<< result <<  d  << '\n';
		if (d!=invisible) cout 	<< result <<  roman_back(d) << '\n';
		
	}
	catch (exception& e)	
	{
		Token_stream ts;
		cerr << e.what() << endl;
		clean_up_mess(ts);
	}

if (fstream)	while (true)
	try {
		double d = statement(ts,st,k,ist,fstream);
		
		if (d!=invisible) ost 	<< result <<  d << '\n';
		if (d!=invisible) ost 	<< result <<  roman_back(d) << '\n';
		if (ist.eof()) break;
		
	}
	catch (exception& e)	
	{
		Token_stream ts;
		cerr << e.what() << endl;
		clean_up_mess(ts);
	}
}
int main ()
try
{
Token_stream ts;
Symbol_table st;
Token t;
bool fstream = {false};
ifstream ist;
ofstream ost;

calculate (ts,st,t,ist,ost,fstream);

	
	keep_window_open();
}
catch (exception& e)
{
	cerr << e.what () << '\n';
	keep_window_open();
}



























