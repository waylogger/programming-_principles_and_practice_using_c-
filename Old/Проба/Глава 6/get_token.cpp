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
            return Token('8',val);   // let '8' represent "a number"
        }
    default:
        error("Bad token");
    }
}