#include <Graph.h>
#include <Simple_window.h>
#include <std_lib_facilities.h>

const char unknown = '?';
const char cnumber = '8';




struct Token
{
	char kind;
	int number;
	Token(char k, int i) : kind(k), number(i) {}
	Token(char k) : kind(k), number (0) {}

};



class Token_stream 
{
	public:
	Token_stream () : full {false}, buffer(0) {}
	Token get();
	void putback(Token t);
	void ignore (Token t);
	void init_string (const string& s) 
	{
		what_ios = true; ost << s;
	}
	private:
	Token get_cin();
	Token get_string();
	int cur_ch = 0;
	string stream = "";
	ostringstream ost {stream};
	bool what_ios {false};
	bool full;
	Token buffer;
};

Token Token_stream::get_cin()
{
	if (full)
	{
		full = false;
		return buffer;
	}
	char c = 0;
	cin >> c;
	switch (c)
	{
	case '+': 
	case '*':
	case '=':
	case '-':
	case '/':
	case '(':
	case ')':
	return Token{c};
	
	case '1':	case '2':
	case '3':	case '4':
	case '5':	case '6':
	case '7':	case '8':
	case '9':	case '0':
	{
		
		cin.putback(c);
		int i =0;
		cin >> i;
		return Token{cnumber,i};
		
		
		
	}
		default:
		error ("!!");
	}
	return Token(unknown);
}

Token Token_stream::get_string() 
{
		if (full)
	{
		full = false;
		return buffer;
	}
	
	char c = ost.str()[cur_ch];
	++cur_ch;
	//cout << c << '\n';
		
	switch (c)
	{
	case '+': 
	case '*':
	case '=':
	case '-':
	case '/':
	case '(':
	case ')':
	return Token{c};
	
	case '1':	case '2':
	case '3':	case '4':
	case '5':	case '6':
	case '7':	case '8':
	case '9':	case '0':
	{
		string s;
		int i =0;
		int bc = cur_ch-1;
		char ic = ost.str()[bc];
		while (isdigit(ic))
		{
			s+=ic;
			++bc;
			ic = ost.str()[bc];
		}
		cur_ch=bc;
		//cout << s << '\n';
		istringstream ist {s};
		ist >> i;
		//cout << i << '\n';
		return Token{cnumber,i};
				
	}
		default:
		//cout << c << '\n';
		error ("Unknown token");
	}
	return Token(unknown);
	
}

void Token_stream::putback(Token t)
{
	if (full) error("putback() into a full buffer");
	full = true;
	buffer = t;
}



double expression(Token_stream& ts);

Token Token_stream::get()
{
	if (what_ios == false)
		return get_cin();
	if (what_ios == true)
		return get_string();
	return Token(unknown);
	
}

double primary (Token_stream& ts)
{
	
	Token t = ts.get();
	switch (t.kind)
	{
		case cnumber:
		return t.number;
		case '(':
		{
		double d = expression(ts);
		t = ts.get();
		if (t.kind!=')') error (") expected");
		return d;
		}
		case '=':
		{
		double d = expression(ts);
		return d;
		}
		break;
		case '-':
		return -primary(ts);
		case '+':
		return primary(ts);
		default:
		error ("prm");
	}
	return 0;
}

double term(Token_stream& ts)
{
	double a = primary(ts);
	Token t = ts.get();

	while (true)
	{
		switch(t.kind)
		{
			case '*':
			a*=primary(ts);
			t=ts.get();
			break;
			case '/':
			a/=primary(ts);
			t=ts.get();
			break;
			default:
			ts.putback(t);
			return a;
			
		}
	}
}

double expression(Token_stream& ts)
{
	double a = term(ts);
	Token t = ts.get();
	while (true)
	{
	switch (t.kind)
	{
		case '+':
		a+=term(ts);
		t=ts.get();
		break;
		case '-':
		a-=term(ts);
		t=ts.get();
		break;
		default:
		ts.putback(t);
		return a;
	}
	
	}
	return a;
}

void calculation()
{
	Token_stream ts;
	double d = expression(ts);
}

double calculation(const string& s)
{
	Token_stream ts;
	ts.init_string(s);
	double d = expression(ts);
	return d;
}


int main () try {
cout << calculation("564-811+321584=") << '\n';
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