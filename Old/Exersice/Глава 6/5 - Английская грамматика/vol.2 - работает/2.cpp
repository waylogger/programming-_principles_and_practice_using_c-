
#include <std_lib_facilities.h>

class words
{
public:
	words();
	string get ();
	void putback(string s);
	
private:
	bool full;
	string buffer;
	
};

words::words()
:full(false), buffer(" ")
{}

void words::putback(string s)
{
if (full) error ("Buffer is full!");
buffer = s;
full = true;
};

string words::get ()
{
	if (full)
	{
		full = false;
		return buffer;
	}
	
	string ch;
	cin >> ch;
	
	if (
	  ch=="and"||ch=="or"||ch=="but"||ch=="birds"||ch=="fish"
	||ch=="C++"||ch=="rules"||ch=="fly"||ch=="swim"||ch=="."
	||ch=="x"
	||ch=="and."||ch=="or."||ch=="but."||ch=="birds."||ch=="fish."
	||ch=="C++."||ch=="rules."||ch=="fly."||ch=="swim.")
		return ch;
	else
		error ("Mistake");
	
	
};

words sw; // Инициализация основной переменной

/*string unions ()
{
string s = sw.get();
	if (s=="and"||s=="or"||s=="but")
	return s;
	else	
	sw.putback(s);
	return s;
};
string substantive ()
{
string s = sw.get();
	if (s=="birds"||s=="fish"||s=="C++")	return s;
	else	
	sw.putback(s);
	return s;
};

string verb ()
{
	string s = sw.get();
	if 	(s=="rules"||s=="fly"||s=="swim")	return s;
	else	
	sw.putback(s);
	return s;

};
*/


string sentence ()
{
	string s = sw.get ();
	return s;
};

int main ()
try
{
bool c = {false};
string s = sw.get ();
	
while (s!="x"&&s!=".")
{
s = sw.get ();
}
if (s==".") cout << "It is sentence\n";
if (s!=".") cout << "It is no sentence\n";
keep_window_open("~");
}

catch (exception& e)
{
cerr << e.what ();
}

catch (...)
{
cerr << "/nI'am dont know what happened!\n";
keep_window_open("~");
}