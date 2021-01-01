#include <std_lib_facilities.h>


const char verb = 'v';
const char noun = 'n';
const char unions = 'u';
const char unknown = 'k';

ifstream read_libraries(char c)
{
	ifstream ist;
	string name;
	if (c==verb)
	{
		string name = "D:\\Programms\\Ch10\\try\\G\\Data\\verbs.txt";
		ifstream ist {name};
		if (!ist) error ("Cant open file", name);
		return ist;
	}
	if (c==noun)
	{		
			string name = "D:\\Programms\\Ch10\\try\\G\\Data\\nouns.txt";
			ifstream ist {name};
			if (!ist) error ("Cant open file", name);
			return ist;
	}
	if (c==unions)
	{		
			string name = "D:\\Programms\\Ch10\\try\\G\\Data\\unions.txt";
			ifstream ist {name};
			if (!ist) error ("Cant open file", name);
			return ist;
	}
	error ("Unknown source", c);
	return ist;
}


	


class Words
{
	public:
	string word;
	char type;
	Words(string w, char t) : word (w), type (t) {}
};

class Storage 
{
	public:
	string get();
	vector<Words>table_of_words;
	void set_word(string s, char c);
	void get_type(string s);
	bool is_insert(string s, char c);
};

istream& operator >> (istream& is, Words& w)
{
	string s;
	char c;
	is >> s >> c;
	w = Words(s,c);
	return is;
}

ostream& operator << (ostream& os, const Words& w)
{
	os << w.word;
	if (w.type==verb) os << " - it is verb\n";
	if (w.type==noun) os << " - it is noun\n";
	if (w.type==unions) os << " - it is union\n";
	
	return os;
}
string Storage::get()
{
	char c = ' ';
	char t = ' ';
	string s;

	while (true)
	{
			cin.get(c);
			if (c=='\n') {cout << s << '\n'; return s;}
			if (isalpha(c)) s+=c;
			else error ("Bad word");
	}
	error ("Bad word");
}

Words find_unions (const string& w)
{
	Words s = {w,unknown};
	
	ifstream& ist = read_libraries(unions);
	
	for (string d; getline(ist,d);) 
	{
		//cout << d << '\n';
		if (d==w) 
		{
			cout << Words(w,unions);
			return Words(w,unions);
		}
		//cout << d << '\n';
	}
	return s;
}

Words find_verb(const string& w)
{
	Words s = find_unions(w);
	
	ifstream& ist = read_libraries(verb);
	
	for (string d; getline(ist,d);) 
	{
		//cout << d << '\n';
		if (d==w) 
		{
			cout << Words(w,verb);
			return Words(w,verb);
		}
		//cout << d << '\n';
	}
	return s;
}
	
Words find_noun(const string& w)
{
	Words s = find_verb(w);
	
	ifstream& ist = read_libraries(noun);
	
	for (string d; getline(ist,d);) 
	{
		//cout << d << '\n';
		if (d==w) 
		{
			cout << Words(w,noun);
			return Words(w,noun);
		}
		//cout << d << '\n';
	}
	if (s.type==unknown) error ("Cant find the word - ", w);
	return s;
}
	
void find_word(const string& w)
{
	find_noun(w);
}
	
	
int main ()
try
{
	string name = "D:\\Programms\\Ch10\\try\\G\\Data\\text.txt";
	ifstream ist {name};
	if (!ist) error ("Cant open file", name);
	for (string s; ist >> s;)
	{
	find_word(s);
	}
	
	keep_window_open();

}
catch (exception& e)
{
	cerr << e.what() << '\n';
	keep_window_open();
}

















