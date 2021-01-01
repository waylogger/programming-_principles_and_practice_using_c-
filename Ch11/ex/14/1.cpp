#include <std_lib_facilities.h>

fstream read_file(string& s)
{
	fstream ist {s, ios_base::in};
	if (!ist) error ("Cant open file");
	return ist;
}

fstream write_file(string& s)
{
	fstream ost {s, ios_base::out};
	if (!ost) error ("Cant open file");
	return ost;
}

fstream& operator >> (fstream& ist, string s)
{
	char ch;
	
	int space =0;	int alpha=0;	int digit=0;
	int xdigit=0;	int upper=0;	int lower=0;
	int alnum=0;	int cntrl=0;	int punct=0;
	int print=0;	int graph=0;
	
	while (ist.get(ch))
	{
		
		if (isspace (ch)) 	++space;		if (isalpha(ch)) 	{++alpha;}	 
		if (isdigit(ch))	++digit; 		if (isxdigit(ch))	++xdigit;
		if (isupper(ch))	++upper;		if (islower(ch))	++lower;
		if (isalnum(ch))	++alnum;		if (iscntrl(ch))	++cntrl;		
		if (ispunct(ch))	++punct;		if (isprint(ch))	++print;
		if (isgraph(ch))	++graph;
		
		
	}
	string oname = "D:\\Programms\\Ch11\\ex\\14\\data\\2.txt";
	fstream ost = write_file(oname);
	ost << "isspace - " 	<< 	 space 	<< '\n'
		<< "isalpha - " 	<< 	 alpha 	<< '\n'	 
		<< "isdigit - "		<<	 digit 	<< '\n'
		<< "isxdigit - " 	<< 	 xdigit << '\n' 
		<< "isupper - " 	<< 	 upper 	<< '\n' 
		<< "islower  - " 	<<	 lower 	<< '\n' 
		<< "isalnum  - " 	<<	 alnum 	<< '\n' 
		<< "iscntrl  - " 	<<	 cntrl 	<< '\n' 
		<< "ispunct  - " 	<<	 punct 	<< '\n' 
		<< "isprint  - " 	<<	 print 	<< '\n' 
		<< "isgraph  - " 	<<	 graph 	<< '\n';
		return ist;
}


int main ()
{
	setlocale(0,"");
	string s;
	string iname = "D:\\Programms\\Ch11\\ex\\14\\data\\1.txt";
	fstream ist {iname};
	ist >> s;

	
	
}