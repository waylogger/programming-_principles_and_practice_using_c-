
/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

#include "std_lib_facilities.h"

struct Token { //Создаем тип для образования лексем
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string n) :kind(ch), name(n) { }
	Token(string s) : name(s) { }
};

class Token_stream { // Класс обслуживающий поток лексем
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }
	Token get();
	void unget(Token t) { buffer=t; full=true; }
	void ignore(char);
};
const char print = ';';// вводим символические константы
const char number = '8';
const char name = 'a';


Token Token_stream::get() //основной член
{
	if (full) { full=false; return buffer; } //проверяем буффер
	char ch;
	cin >> ch;
	switch (ch) { //каждый символ представляет себя
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case ',':
	case '#':
	case '~~':
		return Token(ch);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.unget(); //возвращаем переменную в поток
		double val;
		cin >> val;
		return Token(number,val);
	}
	default:
		if (isalpha(ch)) { //Обнаруживаем строку
			string s;
			s += ch;
			
			while(cin.get(ch) && (isalpha(ch) || isdigit(ch))) s+=ch; //посимвольная конкантенация, чтобы исключить все кроме чисел и букв 
			cin.unget();
			if (s == "exit") return Token(s);
			if (s == "pow") return Token(s);
			if (s == "sqrt") return Token(s);			
			return Token(name,s);
			
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c) //Восстановление программы после перехвата исключений
{
	if (full && c==buffer.kind) { 
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin>>ch)
		if (ch==c) return;
}

struct Variable { //создаем класс переменных
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names; //вектор для хранения таблицы переменных

double get_value(string s) //выводим значения из вектора
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ",s);
}
 
void set_value(string s, double d) //вводим значения в вектор
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ",s);
}

bool is_declared(string s) //переменная объявлена
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts;

double expression();

double primary() //первичное_выражение
{
	Token t = ts.get();
	if (t.name=="sqrt") { //вычисляем квадратный корень
		t=ts.get();
		if (t.kind!='(') error("'(' expected");
		double d = expression ();
		if (d<0) error ("sqrt:: Sub zero");
		d = sqrt(d);
		t=ts.get();
		if (t.kind!=')') error("')' expected");
		return d; 
	}
	if (t.name=="pow") { //возводим в степень
		t=ts.get();
		if (t.kind!='(') error("'(' expected");
		double d = expression ();
		t=ts.get();
		if (t.kind!=',') error ("',' expected");
		t=ts.get();
		int c = narrow_cast<int>(t.value);
		t=ts.get();
		if (t.kind!=')') error("')' expected");
		d = pow(d,c);
		return d; 
	}
	switch (t.kind) {
	case '(':
	{	double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		else return d;
	}
	case '-':
		return - primary();
	case '+':
		return + primary();
	
	
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	default:
		error("primary expected");
	}
}

double term() //Терм
{
	double left = primary();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		}
		case '%':
		{
			int i1 = narrow_cast<int>(left);
			int i2 = narrow_cast<int>(primary());
			if (i2==0) error("Mod by zero");
			left = i1%i2;
			break;
		}

		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression() //Выражение
{
	double left = term();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration() //объявляем переменные
{
	Token t = ts.get();
	if (t.kind != 'a') error ("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of " ,name);
	double d = expression();
	names.push_back(Variable(name,d)); //вносим в вектор
	return d;
}

double statement() //условия
{
	Token t = ts.get();
	switch(t.kind) {
	case '#':
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess() //восстановление программы пока не встретишь print
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate() //блок вычислений
{
	while(true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t=ts.get();
		if (t.name == "exit") return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch(runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()

	try {
		names.push_back(Variable("k",1000));
		calculate();
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >>c&& c!=';') ;
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (cin>>c && c!=';');
		return 2;
	}