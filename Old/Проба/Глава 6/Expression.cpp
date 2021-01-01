#include <std_lib_facilities.h>
class Token
{
	public:
	char kind;
	double value;
	
	Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }    
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

Token get_token()
{
	char ch;
	cin >> ch;
	
	switch (ch)
		{
			case '(':
			case ')':
			case '-':
			case '+':
			case '*':
			case '/':
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
        {    
            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin >> val;              // read a floating-point number
            return Token('8',val);   // let '8' represent "a number"
        }
    default:
        error("Bad token");
    }
};
			
double expression ()
{

Token t = get_token();
Token term = get_token();	
double left = term;
while (true) {
	switch (t.kind) {
		case '+':
			left += term;
			t = get_token();
		break;
		case '-':
			left -= term;
			t = get_token ();
		break;
	defaulf:
		return left;
	}
	}
};

int main ()
try
{
	
	while (cin)
	{
        cout << expression() << '\n';
	}
}

catch (exception& e)
{
	cerr << e.what ();
}
