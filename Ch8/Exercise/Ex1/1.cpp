// Bjarne Stroustrup 4/25/2009
// Chapter 7 Exercises 1-3

/*
	I decided to roll the solutions to exercises 1-3 into one.
	I start with the code from section 7.8.3 (with names and prefedined names)

	Exercise 1: allow underscores in names

	Exercise 2: provide an assignment operator =

	Exercise 3: introduce constants

	The three exercises are of significantly different complexities:

		Exercise 1: allow underscores in names. This requires just a minor change to
			the lexical analysis: a very minor change to one line of Token::get()

		Exercise 2: provide an assignment operator =. This is much harder and if
			constants would havemade any sense without assignment should have come
			after exercise 3.
			
			The main problem is to decide where in the grammar to put an assignment "N=2".
			We can't just call primary() from statement() to find the name "N" because
			primary() only returns the value of what it finds (and we need the name
			so that we can change its value). The other obvious solution is to look
			for a name followed by a =. If we find that we have the start of an assignment
			and if not, we can put the name and the = tokens back and call primary().
			To do that we would have to modify Token_stream to handle two putback()s.
			That could be done, but I chose a third solution: I added NAME = Expression
			to Primary. This gives us a bit more than we wanted (e.g. x=y=10 assigns 10
			to both x and y), but the modification is localized.
	
		Exercise 3: introduce constants. This involves defining "const" as a token,
			modifying declarations() to recognize it, modifying Variable to hold
			constant/variable information, and a check in set_value to refurse to
			assign to a constent.
*/


//
// This is example code from Chapter 7.8.3 "Predefined names" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

/*
    Simple calculator

    Revision history:

        Facilities added by Bjarne Stroustrup April 2009
			(underscores, assignment, and constants)
		Revised by Bjarne Stroustrup May 2007
        Revised by Bjarne Stroustrup August 2006
        Revised by Bjarne Stroustrup August 2004
        Originally written by Bjarne Stroustrup
            (bs@cs.tamu.edu) Spring 2004.

    This program implements a basic expression calculator.
    Input from cin; output to cout.

    The grammar for input is:

    Calculation:
        Statement
        Print
        Quit
        Calculation Statement
    
    Statement:
        Declaration
        Expression
    
    Declaration:
        "let" Name "=" Expression
        "const" Name "=" Expression

    Print:
        ;

    Quit:
        q 

    Expression:
        Term
        Expression + Term
        Expression - Term
    Term:
        Primary
        Term * Primary
        Term / Primary
        Term % Primary
    Primary:
        Number
        Name
		Name = Expression
        ( Expression )
        - Primary
        + Primary
    Number:
        floating-point-literal
	Name:
		[a-zA-Z][a-zA-Z_0-9]*	// a letter followed by zero or more letters, underscores, and digits
								// note that I decided not to start a namewith an underscore
								// just because I consider it ugly)

        Input comes from cin through the Token_stream called ts.
*/

// Note that I updated the grammar; keeping comments up-to-data is part of modifying code

//------------------------------------------------------------------------------

const char number = '8';    // t.kind==number means that t is a number Token
const char quit   = 'q';    // t.kind==quit means that t is a quit Token
const char print  = ';';    // t.kind==print means that t is a print Token
const char name   = 'a';    // name token
const char let    = 'L';    // declaration token
const char con    = 'C';    // const declaration token
const string declkey = "let";		// declaration keyword 
const string constkey = "const";	// const keyword
const string prompt  = "> ";
const string result  = "= "; // used to indicate that what follows is a result
const string Help = "Help";
const string help = "help";
const string qt = "quit";
const string csin = "sin";
const string ccos = "cos";
const string ctan = "tan";
const string cctan = "ctan";
const char Hp = 'H';
const char hp = 'h';
const char sinus = 's';
const char cosinus = 'c';
const char tangens = 'tn';
const char ctn1 = 'ct';



//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    string name;      // for names: name itself
    Token(char ch)             : kind(ch), value(0)   {}
    Token(char ch, double val) : kind(ch), value(val) {}
    Token(char ch, string n)   : kind(ch), name(n)    {}
	
	
};

//------------------------------------------------------------------------------

class Token_stream {
public: 
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
    void ignore(char c);      // discard tokens up to an including a c
	istream& str;
	Token_stream(istream& arg) :str(arg), full(0), buffer(' ') {};
	private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------
/*
// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream(istream& arg)
:str(arg), full(false), buffer(0)    // no Token in buffer
{
}
*/
//------------------------------------------------------------------------------


// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

char get_sym (char ch) { //считываем из потока всё кроме пробелов
	while(cin.get(ch)) {
	if (ch!=' ')  return ch;
  
  }
}
//------------------------------------------------------------------------------

Token Token_stream::get() // read characters from cin and compose a Token
{
    if (full) {         // check if we already have a Token ready
        full=false;
        return buffer;
    }  

    char ch;
	ch=get_sym(ch);          // note that >> skips whitespace (space, newline, tab, etc.)
	if (ch=='\n') return Token (print); //если обнаруживаем символ перехода на новую строку, то выводим результат
	switch (ch) {
    case quit:
    //case print:
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/': 
    case '%':
    case '=':
	case print:
	    return Token(ch); // let each character represent itself

    case '.':             // a floating-point literal can start with a dot
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':    // numeric literal
    {
        cin.putback(ch);// put digit back into the input stream
        int val;
        cin >> val;     // read a floating-point number
		
        return Token(number,val);
    }
    default:
		    if (isalpha(ch)) {	// start with a letter
            string s;
            s += ch;
            while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch=='_')) s+=ch;	// letters digits and underscores
            cin.putback(ch);
            if (s == declkey) return Token(let); // keyword "let"
            if (s == constkey) return Token(con); // keyword "const"
			if (s == Help) return Token(Hp, name);
			if (s == help) return Token (hp, name);
			if (s == qt) return Token (quit, name);
			if (s == csin)return Token (sinus);
			if (s == ccos)return Token (cosinus);
			if (s == ctan)return Token (tangens);
			if (s == cctan)return Token (ctn1);
	
			return Token(name,s);
		}
		if (isspace(ch)&&ch=='\n') return Token (print);
		
		error("Bad token");
    }
}

//------------------------------------------------------------------------------

void Token_stream::ignore(char c)
    // c represents the kind of a Token
{
    // first look in buffer:
    if (full && c==buffer.kind) {
        full = false;
        return;
    }
    full = false;

    // now search input:
    char ch;
    while (cin>>ch)
        if (ch==c) return;
}

//------------------------------------------------------------------------------

Token_stream ts(cin);        // provides get() and putback() 

//------------------------------------------------------------------------------

class Variable {
public:
    string name;
    double value;
	bool var;	// variable (true) or constant (false)
    Variable (string n, double v, bool va = true) :name(n), value(v), var(va) { }
};

class Symbol_table { // упражнение 4 главы 7, собираем функции связанные с переменными в 1 класс
public:
vector<Variable> var_table;
double get_value(string s);
void set_value(string s, double d);
bool is_declared(string var);	
double define_name(string s, double val, bool var=true);
};

Symbol_table st;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

double Symbol_table::get_value(string s)
    // return the value of the Variable names s
{
    for (int i = 0; i<var_table.size(); ++i)
        if (var_table[i].name == s) return var_table[i].value;
    error("get: undefined variable ", s);
}

//------------------------------------------------------------------------------

void Symbol_table::set_value(string s, double d)
    // set the Variable named s to d
{
    for (int i = 0; i<var_table.size(); ++i)
        if (var_table[i].name == s) {
			if (var_table[i].var==false) error(s," is a constant");
            var_table[i].value = d;
            return;
        }
    error("set: undefined variable ", s);
}

//------------------------------------------------------------------------------

bool Symbol_table::is_declared(string var)
    // is var already in var_table?
{
    for (int i = 0; i<var_table.size(); ++i)
        if (var_table[i].name == var) return true;
    return false;
}

//------------------------------------------------------------------------------

double Symbol_table::define_name(string s, double val, bool var)
    // add (s,val,var) to var_table
{
    if (is_declared(s)) error(s," declared twice");
    var_table.push_back(Variable(s,val,var));
    return val;
}

//------------------------------------------------------------------------------




double expression(Token_stream& ts);    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary(Token_stream& ts)
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':           // handle '(' expression ')'
        {
            double d = expression(ts);
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
    case number:    
        return t.value;    // return the number's value
    case name:
		{
			Token next = ts.get();
			if (next.kind == '=') {	// handle name = expression
				double d = expression(ts);
				st.set_value(t.name,d);
				return d;
			}
			else {
				ts.putback(next);		// not an assignment: return the value
				return st.get_value(t.name); // return the variable's value
			}
		}
	case Hp:
	case hp:
		return 0;
	case sinus:
		{	
			Token next = ts.get();
			if (next.kind!='(') error ("'(' expected");
			next = ts.get();
			double d = sin(d);
			next = ts.get();
			if (next.kind!=')') error ("')' expected");
			return d;
			next = ts.get();
		}
	case cosinus:
		{	
			Token next = ts.get();
			if (next.kind!='(') error ("'(' expected");
			next = ts.get();
			double d = cos(d);
			next = ts.get();
			if (next.kind!=')') error ("')' expected");
			return d;
			next = ts.get();
		}
	case tangens:
		{	
			Token next = ts.get();
			if (next.kind!='(') error ("'(' expected");
			next = ts.get();
			double d = tan(d);
			next = ts.get();
			if (next.kind!=')') error ("')' expected");
			return d;
			next = ts.get();
		}
	case ctn1:
		{	
			Token next = ts.get();
			if (next.kind!='(') error ("'(' expected");
			next = ts.get();
			double d = 1/tan(d);
			next = ts.get();
			if (next.kind!=')') error ("')' expected");
			return d;
			next = ts.get();
		}
    case '-':
        return - primary(ts);
    case '+':
        return primary(ts);
	default:
        error("primary expected");
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term(Token_stream& ts)
{
    double left = primary(ts);
    Token t = ts.get(); // get the next token from token stream

    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary(ts);
            t = ts.get();
            break;
        case '/':
            {    
                double d = primary(ts);
                if (d == 0) error("divide by zero");
                left /= d; 
                t = ts.get();
                break;
            }
        case '%':
            {    
                int i1 = narrow_cast<int>(left);
                int i2 = narrow_cast<int>(term(ts));
                if (i2 == 0) error("%: divide by zero");
                left = i1%i2; 
                t = ts.get();
                break;
            }
        default: 
            ts.putback(t);        // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression(Token_stream& ts)
{
    double left = term(ts);      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while(true) {
		
		switch(t.kind) {
        case '+':
            left += term(ts);    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term(ts);    // evaluate Term and subtract
            t = ts.get();
            break;
			
        default: 
            ts.putback(t);     // put t back into the token stream
            return narrow_cast<int>(left);       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

double declaration(Token k)
    // handle: name = expression
    // declare a variable called "name" with the initial value "expression"
	// k will be "let" or "con"(stant)
{
    Token t = ts.get();
    if (t.kind != name) error ("name expected in declaration");
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=') error("= missing in declaration of ", var_name);

    double d = expression(ts);
    st.define_name(var_name,d,k.kind==let);
    return d;
}

//------------------------------------------------------------------------------

double statement()
{
    Token t = ts.get();
    switch (t.kind) {
    case let:
	case con:
        return declaration(t.kind);
    default:
		ts.putback(t);
        return expression(ts);
    }
}

//------------------------------------------------------------------------------

void clean_up_mess()
{ 
    ts.ignore(print);
}

//------------------------------------------------------------------------------
void view_help () {
setlocale(0,"");
cout << "Указанная программа является инженерным калькулотором ограниченной функциональности, она поддерживает стандартные арифметические операторы:\n"
<<"+\n"
<<"-\n"
<<"*\n"
<<"/\n"
<< "Кроме того, существует возможность объ¤вдени¤ переменных и констант:\n"
<< "let a = 5 - объ¤вление переменной\n"
<< "const a = 5 - объ¤вление константы\n"
<< "Для выполнени¤ введенного действи¤, просим нажать <Enter>\n";
return;
};


void calculate()
{
    while (cin)
      try {
        cout << prompt;
        Token t = ts.get();
        while(t.kind == print) t=ts.get();    // first discard all "prints"
        if (t.kind == quit) return;        // quit
		if (t.kind == Hp||t.kind == hp) view_help();
        ts.putback(t);
		cout << result << statement() << endl;
    }
    catch (exception& e) {
        cerr << e.what() << endl;        // write error message
        clean_up_mess();
    }
}

//------------------------------------------------------------------------------

int main()
try {
    // predefine names:
    st.define_name("pi",3.1415926535,false);	// these pre-defiend names are constants
    st.define_name("e",2.7182818284,false);
    calculate();
	
    keep_window_open("~~");    // cope with Windows console mode
    return 0;
}
catch (exception& e) {
    cerr << e.what() << endl;
    keep_window_open("~~");
    return 1;
}
catch (...) {
    cerr << "exception \n";
    keep_window_open("~~");
    return 2;
}

//------------------------------------------------------------------------------

/*
	Oh, yes, once I had assignment and constants, I immediately made "pi" and "e"
	were constants. I really don't want anyone to redefine pi to be 3 :-)

	If we liked, we could predefine variables (e.g. x, y, and z), but would that be a good idea?

	When I added an argument in declaration() and Variable::Variable()), I used default arguments
	to ensure that older calls still worked correctly.
	Указанный калькулятор содержит доработки внесенные входе выполнения упражнений, а именно:
	1. Добавлена справка при вводе help || Help
	2. Выход с q заменен на quit
	3. Вывод осуществляется при обнаружении знака перехода на новую строку
*/