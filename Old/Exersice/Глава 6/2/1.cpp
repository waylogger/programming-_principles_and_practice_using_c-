#include <std_lib_facilities.h>

class Token
{
public:
char kind;
double value;
Token(char ch):kind(ch), value(0) { }    
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

Token get_token()    // read a token from cin
{
    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    	case '(':
	case ')': 
	case '+': 
	case '-': 
	case '*': 
	case '/': 
    return Token(ch);        // let each character represent itself
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
            return Token('8',val);   
		}
	}
 };



int main ()
try
{
vector<Token>tok;
setlocale (0, "");
while (cin)
{
Token t = get_token ();
tok.push_back(t);
}
for (int i = 0; i<tok.size (); i++)
{
cout << tok[i].kind << "\n";
cout << tok[i].value<< "\n";
}

keep_window_open (); 
}

catch (exception& e)
{
cerr << e.what ();
}