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
:full(false), buffer()
{	
}

void words::putback(string s)
{
if (full)

error ("Buffer is full!\n");
buffer = s;
full = true;
};

string words::get ()
{
	if (full)
	{
		full=false;
		return buffer;
	}
	
	string ch;
	cin >> ch;
	
	if (ch=="and"||ch=="or"||ch=="but"||ch=="birds"||ch=="fish"||ch=="C++"
		||ch=="rules"||ch=="fly"||ch=="swim"||ch==" . ")
		return ch;
	else
		error ("Mistake");
	
	
};

words sw; // Инициализация основной переменной

int main ()
try
{
	
	string g = sw.get ();
	
	if (g=="birds")	cout << "\n" << g << "\n";
	sw.putback(g);
	if (g=="fish")	cout << "\n" << g << "\n";
	sw.putback(g);
	if (g=="C++")	cout << "\n" << g << "\n";

	keep_window_open ();
	}

catch (exception& e)
{ 
cerr << "Ups.....\n" << e.what (); 
keep_window_open ();
}