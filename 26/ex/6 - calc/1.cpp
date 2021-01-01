/*
Antonyuk I.V. 01/05/2018
Stariy Oskol
PPP C++ B.Stroustrup
ex. 26.6
*/

#include 		<	iostream	>
#include		<	fstream		>
#include		<	typeinfo	>
#include		<	regex		>
#include		<	cctype		>
#include		<	MY\\test.h	>



using namespace std;

//-----------------------------------------------------------------------------

template <typename Func>
void error(const string& s, istream& ist,Func f){
	
	cerr << s;

	
	if (!f(ist)){
			cout << "Stream can not be restored\n";
			char c;
			cin >> c;
			exit(1);
	}
	else 
		cout << "Stream was restored\n";
	
}


//-----------------------------------------------------------------------------


void error(const string& s){
	
	cerr << s;
	char c;
	cin >> c;
}


//-----------------------------------------------------------------------------


struct Token{
	double 					val;
	char 					kind;
	string 					key;
	
	Token( 	const char k, const double v,const string& ky ) : 
							kind { k },	val { v }, key{ ky } {} 
				
	Token(  const char k) :
							kind {k}, val{-1}, key{"kind"} {}
							
	Token(  const double v) :
							kind {'8'}, val{v}, key{"val"} {}
							
	Token(  const string& s) :
							kind {'K'}, val{-2}, key{s} {}
				
	Token() {}
	
	
};


//-----------------------------------------------------------------------------


ostream& operator << (ostream& ost, const Token& t){
	
	if (t.kind != 's')
	ost << "Kind:\t" 	<< t.kind 	<< '\t' 
		<< "Value:\t" 	<< t.val 	<< '\t' 
		<< "Key:\t" 	<< t.key 	<< "\n";
	
	return ost;
}


//-----------------------------------------------------------------------------


struct Token_stream{
	Token 				buffer;
	bool 				full 		= 		false;
	std::istream& 		ist;
	Token 				get();
	
	void 				putback				(const Token& t);
	Token_stream		(istream& i) : 		ist {i} {}
};


//-----------------------------------------------------------------------------


bool restore( istream & ist ){
	
	char c = ' ';
	
	while ( c != '\n' && ist ){
		ist.get( c );
	}
	
	if (c == '\n')
		return true;

	return false;
	
}

//-----------------------------------------------------------------------------


void Token_stream::putback( const Token & t ){
		if ( full ){
			 error("Buffer is full");
			 return;
		}
			full = true;
			buffer = t;
	}
	
	
//-----------------------------------------------------------------------------


Token Token_stream::get(){
	if ( full ){ //buffer managment
		full = false;
		return buffer;
	}
//-----------------------------------------------------------------------------
	char c;
	if ( ! ist.get( c ) )
						return Token{ 's' };
	switch(c){
		case '0': case '1': case '2': 
		case '3': case '4': case '5':
		case '6': case '7': case '8':
		case '9':
		{
			double 		d = 0;
						ist.putback(c);
						ist >> d;
						return Token{d};
		}
		case '\n':
		case ' ':
						return Token{'s'};
		case '+':
		case '-':
		case '(':
		case ')':
		case '*':
		case '/':
		case '%':
		case '|':
		case '&':
		case '~':
		case '=':
		case '>':
						return Token{c};
		default:
			if ( isalpha( c ) ){
								ist.putback( c );
								string s;
				for (; ist.get( c ) && ( isalpha( c ) || isdigit( c ) ) ; ){
						
								s += c;
				}
								ist.putback(c);
				if ( s == "let" )
						return Token( 'd' );
				else
						return Token( s );
			}
			error("Unexpecting charaster\n",ist,restore);
	}
	return Token{ 's' };

}

double expression( Token_stream & ts );

double primary( Token_stream & ts ){
	Token t = ts.get();
	switch(t.kind){
	case 's':
		return primary(ts);
	case '8':
		return t.val;
	case '-':
		return -primary(ts);
	case '+':
		return +primary(ts);
	case '(':
	{
		double d = expression(ts);
		t = ts.get();
		if (t.kind != ')'){
			error(") is expected",ts.ist,restore);
			return 0;
		}
		return d;
	}
	}
	
	return 0;
	
}


double term( Token_stream & ts ){
	
	double left = primary( ts );
	
	Token t = ts.get();
	
	while (true){
		switch(t.kind){
			case '*':
			{
				double d = primary(ts);
				left *= d;
				t = ts.get();
				break;
			}
			
			case '/':
			{
				double d = primary(ts);
				if (d == 0){
					error("Devide by zero\n",ts.ist,restore);
					return 0;
				}
				left /= d;
				t = ts.get();
				break;
			}
			
			default:{
				ts.putback(t);
				return left;
			}
		}
	}
	
	return left;
	
}






double expression( Token_stream & ts ){
	double left  = term(ts);
	
	Token t = ts.get();
	while (true){
		
		switch(t.kind){
			case '+':{
				double d = term(ts);
				left += d;
				t = ts.get();
				break;
			}
			
			default:{
				ts.putback(t);
				return left;
			}
		}
		
		
		
	}

	return left;
	
}



struct Test{
	string name;
	string seq;
	
	double val;
	bool res;	
};

istream& operator >> (istream & ist, Test& t){
	
	
	string pat = R"(\{	(\w+)	(-?\d+(\.\d+)?)	\{	([\(\)0-9+-/\*]+)	\}	([1|0])	\})";
	
	regex reg {pat};
	
	smatch match;
	string line;
	
	getline(ist,line);
	
	if (regex_match(line,match,reg)){
		t.name = match[1];
		t.val = MY::from_string_to<double>(match[2]);
		t.seq = match[4];
		int r =  MY::from_string_to<int>(match[5]);
		if (r)
			t.res = true;
		else
			t.res = false;
		
		
	}
	
	
	return ist;
}

ostream& operator << (ostream& ost, const Test& t){
	
	cout 	<< "{\t" << t.name 	<< '\t' 
			<< t.val << '\t' 	<< '{' 
			<< '\t' << t.seq 	<< '\t' 
			<< '}' 	<< '\t' 	<< t.res 	
			<< '\t' << '}'; 
	
	return ost;
}


double calculation(const string& s){
	
	istringstream ist {s};
	Token_stream ts{ist};
	return expression(ts);
}

void testing(ostream& ost){
	ifstream ist {"C:\\Data\\26\\6\\1.txt"};

	Test t;	
	ost << "----------------------------------------------------------------\n";
	while(ist >> t){
		
		ost << "Testname:\t" 	<< t.name << '\n'
			<< "Expect val:\t"	<< t.val << '\n'
			<< "Sequence:\t" 	<< t.seq << '\n'
			<< "Expect result:\t" 	<< t.res << '\n';
		ost << "----------------------------------------------------------------\n";
		double d = calculation(t.seq);
		if ( d == t.val)
			ost << "\t\t\t\tResult : " << d << " : Test is passed\n";
		else
			ost << "\t\t\t\tResult : " << d << " : Test is failed\n";
		ost << "----------------------------------------------------------------\n";
		
	}
	
	
}


int main(){
	
	
	
	
	
	
	testing(cout);
	
	
	
	
	
	char end;
	cin >> end;
}