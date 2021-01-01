
/*
Модерницация и деградация калькулятора из главы 7

Деградация - потому что это выдержки из той программы, она не приведена полностью потому что я ее не копировал, 
а старался написать по-памяти используя оригинал как шпаргалку, поэтому полностью я ее не переписал.

Модерницация - в функции get_string() которая позволяет получать поток лексемм из строки
*/

namespace Calcs 
{
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
	Token get_cin(); //получаем данные из консоли
	Token get_string(); //получаем данные из строки
	int cur_ch = 0; //перемещение по строке
	string stream = ""; //для инициализации потока
	ostringstream ost {stream}; //инициализация потока
	bool what_ios {false}; //откуда считываем?
	bool full;
	Token buffer;
};

Token Token_stream::get_cin() //как и раньше в Token::get();
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
	
	char c = ost.str()[cur_ch]; //берем символ из строки
	++cur_ch; //итерируем индекс
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
		int bc = cur_ch-1; //берем индекс до итерации
		char ic = ost.str()[bc]; //берем соответствующий символ
		while (isdigit(ic))
		{
			s+=ic;
			++bc;
			ic = ost.str()[bc];
		}
		cur_ch=bc; //восстанавливаем индекс
		//cout << s << '\n';
		istringstream ist {s}; //отправляем получившуюся строку в поток
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
	if (what_ios == false) //читай консоль
		return get_cin();
	if (what_ios == true)
		return get_string(); //читай виджет
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

} //end of calcs
