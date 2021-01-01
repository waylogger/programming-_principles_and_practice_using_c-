/*

Antonuyk I.V.

05/05/2018

Stariy Oskol

PPP C++ B.Stroustrup

class Document whith test

*/


#include 		<		iostream		>
#include 		<		fstream			>
#include		<		sstream			>
#include 		<		vector			>
#include 		<		list			>
#include		<		string			>
#include		<		regex			>
#include		<		My\\test.h		>

using	namespace	std;
using	Line		= vector<char>;



class Text_iterator{
	list<Line>::iterator	ln;
	Line::iterator 			pos;
	
	public:
	
	Text_iterator	(	list<Line>::iterator ll,	Line::iterator p	) :
					ln{ll}, pos{p} {}
					
	char&	operator	*	()	{	return *pos;	}
	bool	operator	==	(	const	Text_iterator&		other	)
							{		return 	(	other.ln	==	ln	)
											&&
											(	other.pos	==	pos	);
							}
	bool	operator	!=	(	const	Text_iterator&		other)
							{		return	!(	*this 		== 	other);}
							
							
	Text_iterator&
			operator	++	(){
							++pos;
							if	(	pos	==	(*ln).end()	) {
									++ln;
									pos	=	(*ln).begin();	
							}
									return 		*this;
			}

			
			

};

struct Document{
	list<Line>lines;
	Document(){}
	
	Text_iterator	begin	(){
		return Text_iterator{
							lines.begin(),
							(*lines.begin()).begin()
		};
	}
	
	Text_iterator	end		(){
		return Text_iterator{
							lines.end(),
							(*lines.end()).end()
		};
	}
	

};


istream&	operator	>>	(istream& ist, Document& d){
	
	d.lines.push_back(Line{});
	
	for (char c = 0; ist.get(c);){
											d.lines.back().push_back(c);
		if (c == '\n')//--------------------------------
											d.lines.push_back(Line{});
		
	}
	
		if (d.lines.back().size())//--------------------
											d.lines.push_back(Line{' '});
	
	return ist;
}


ostream&	operator	<< (ostream& ost,  Document d){
			
			for (auto f : d){
				ost << f;
			}
			return ost;
}

template <typename Forwarditerator>
bool match(Forwarditerator begin, Forwarditerator end, Forwarditerator b){
	
	for (auto f = begin; f != end; ++f, ++b){
		if (*f != *b)
			return false;
	}
	
	return true;
}



template <typename ForwardIterator>
int count(ForwardIterator begin, ForwardIterator end, const string& s){
	int c = 0;
	for (	auto  d = begin; d != end; ++d	)
		if ( *d == s[0] ){//------------------------------------------
							bool	status 				= true;
							auto	d2 					= d;
							for (	int i = 0; i < s.size(); ++i, ++d2	)	{
							if (d2 == end)//--------------------------
													{return c;}
							if (s[i] != *d2){//-----------------------
													status = false;
													break;
											}//-----------------------
										}
							if (status)//-----------------------------
													{++c;}
		}//-----------------------------------------------------------
													return c;
	}
	


	
struct Test{
	string label;
	bool res;
	string seq;
	struct val{int a = 0; int b = 0;};
	val v;

};


istream& operator >> 	(	istream& ist, Test& t	){
	
	regex				reg	{	R"((\w+)	\{	\{	(\w+)	\}	(\d+)	(\d+)	([10])	\})"	};
	
	string 				line;
	smatch				match;

	getline(ist,line);
	if (regex_match(line,match,reg)){
		t.label = 	match[1];
		t.seq 	=	match[2];
		t.res 	=	MY::from_string_to<bool>(match[5]);
		t.v.a = MY::from_string_to<int>(match[3]);
		t.v.b = MY::from_string_to<int>(match[4]);
	}			
	
	
	return ist;
}


ostream& operator << (ostream& ost, const Test& t){
	
	ost << 	t.label << '\t' << '{' << '\t' << '{' << '\t'
		<<	t.seq	<< '\t'	<< '}' << '\t' << t.v.a << '\t' << t.v.b << '\t'
		<< 	t.res	<< '\t' << '}';
	
	
	return ost;
}


void f()
{
	cout << 1;
}


vector<Test> get_tests(){
	
	vector<Test> tests;
	Document d1;
	
	ifstream ifs {"C:\\data\\26\\7\\1.txt"};
	ifs >> d1;
	
	string s1;
	for (auto s : d1){
		s1 += s;
	}
	
	
	ostringstream ost {s1};
	
	istringstream ist {ost.str()};
	
	for (Test t;ist >> t;){
		tests.push_back(t);
	}
	
	return tests;
}


void testing(vector<Test>& t){
	int fail = 0;
	for (auto z : t){
		int a = count(z.seq.begin(),z.seq.end(),string("a"));
		int b = count(z.seq.begin(),z.seq.end(),string("b"));
		
		
		if (a != z.v.a || b != z.v.b)
			++fail;
		
		
		
		
	}
	
	
	cout << fail << " of fail\n";
	
	
	
	
	
	
	
}

int main(){
	
	auto p = get_tests();

	testing(p);
	
	

	
	char end;
	cin >> end;
}


	