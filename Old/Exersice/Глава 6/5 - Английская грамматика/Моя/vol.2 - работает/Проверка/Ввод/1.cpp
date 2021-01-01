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
	while (true)
	{
	string g = sw.get ();
	cout << "\n" << g;
	g = sw.get ();
	cout << "\n" << g << "\n";
	}
	}

catch (...)
{ 
cerr << "Ups.....\n";
}