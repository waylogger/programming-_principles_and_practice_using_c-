#include <iostream>
#include <string>

using namespace std;

bool is_higth(const char& c)
{
	switch(c)
	{
		case 'A': case 'B': case 'C': case 'D':
		case 'E': case 'F': case 'G': case 'H':
		case 'I': case 'J': case 'K': case 'L': 
		case 'M':
		case 'N': case 'O': case 'P': case 'Q':
		case 'R': case 'S': case 'T': case 'U':
		case 'V': case 'W': case 'X': case 'Y': 
		case 'Z':
		return true;
		default:
		return false;
	}
	return false;
}

char to_lower(const char& c)
{
	switch(c)
	{
		case 'A':	return 'a';
		case 'B':	return 'b'; 	 
		case 'C':	return 'c'; 
		case 'D':	return 'd';
		case 'E':	return 'e';
		case 'F':	return 'f';
		case 'G':	return 'g';
		case 'H':	return 'h';
		case 'I':	return 'i';
		case 'J':	return 'j';
		case 'K':	return 'k';
		case 'L':	return 'l';
		case 'M':	return 'm';
		case 'N':	return 'n';
		case 'O':	return 'o';
		case 'P':	return 'p';
		case 'Q':	return 'q';
		case 'R':	return 'r';
		case 'S':	return 's';
		case 'T':	return 't';
		case 'U':	return 'u';
		case 'V':	return 'v';
		case 'W':	return 'w';
		case 'X':	return 'x';
		case 'Y':	return 'y';
		case 'Z':	return 'z';
	}
	return 0;
}

void to_lower(char* c)
{
	for (int i =0; c[i]!='0';++i)
	{
		if (is_higth(c[i])) c[i]=to_lower(c[i]);
	}
}


class Cstr
{
	char* ch;
	unsigned int sz;
	public:
	Cstr(const string& s) : ch{new char(s.size())}, sz{s.size()}
	{
		for (int i =0; i < s.size(); ++i)
		{
			ch[i]=s[i];
		}
		ch[s.size()]='0';
	}	
	~Cstr() {delete[] ch;}
	int size() {return sz;}
	char* get() {return ch;}
};

char* strdup(const char*c)

{
	int n = 0;
	char* cc = new char;
	
	for (int i = 0; c[i]!='0';++i)
	{
		cc[i]=c[i];
	}
	
	return cc;
}

char* findx (const char* s, const char* x)
{
	//if (s==nullptr || x ==nullptr) error ("findx-nullptr");
	
	char* p = new char('!');
	
	for (int i = 0; s[i]!='0';++i)
	{
	for (int j = 0; x[j]!='0';++j)
	{
		if (s[i]==x[j]) 
		{
			p=strdup(s+i);
			return p;
		}
	}
	}
	return p;
	
}

char* read(istream& ist)
{
	string s = "";
	ist >> s;
	s+='!';
	char* c = new char;
	for (int i =0; i < s.size();++i)
	{
		c[i]=s[i];
	}
	
	return c;
	
}

int main ()

{

char* c1 = read(cin);


int k = 0;
for (;c1[k]!='!';++k);

for (int i =0; i<k;++i)
{
	cout << c1[i];
}


	

	char c;
	cin >> c;
}