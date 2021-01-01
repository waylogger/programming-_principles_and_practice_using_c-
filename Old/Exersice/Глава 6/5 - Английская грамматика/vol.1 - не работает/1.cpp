
#include <std_lib_facilities.h>

class stream_string
{
	public:
	//string stream_strings ();
	string get();
	void putback(string s);
	private:
	bool full;
	string buffer;
};

/*stream_string::stream_strings()
:full {false}, buffer(0)
	{}*/
	
	
void stream_string::putback (string s)
{
if (full) error ("putback buffer is full");
buffer = s;
full = true;
}

string stream_string::get ()
{
	if (full)
	{
		full=false;
		return buffer;
	}
	

while (cin)
	{
	string s;
	cin >> s;
	if (
		s=="and"
		||s=="or"
		||s=="but"
		||s=="birds"
		||s=="The birds"
		||s=="fish"
		||s=="The fish"
		||s=="C++"
		||s=="The C++"
		||s=="rules"
		||s=="fly"
		||s=="swim"
		||s==" . ")
		return s;
	else
		error ("Непредвиденное значение");
	}
	
};

stream_string ss;


string unions ()
{
string s = ss.get();
	if (
		s=="and"
		||s=="or"
		||s=="but")
		{
		return s;
		string s = ss.get();
		}
	else
		ss.putback(s);
};

string substantive ()
{
string s = ss.get();
	if (
		s=="birds"
		||s=="The birds"
		||s=="fish"
		||s=="The fish"
		||s=="C++"
		||s=="The C++")
		{
		return s;
		string s = ss.get();
		}
	else
		ss.putback(s);
};

string verb ()
{
	string s = ss.get();
	if 	(
		s=="rules"
		||s=="fly"
		||s=="swim"
		)
		{
		return s;
		string s = ss.get();
		}
	else
		ss.putback(s);

};

string sentence ()
{
string s = " ";
	if (unions().size()>0)
	{
	string s = sentence () + unions () + sentence ();
	return s;
	}

	if (unions().size() == 0)
	{
	string s = substantive () + verb ();
	return s;
	}

};

int main ()
try
{
cout << "Insert \n";
string s = sentence ();

	if 	(
		s[s.size()-1] == ' '
		&& s[s.size ()-2] == '.' 
		&& s[s.size ()-3] == ' '
		)
		cout << "YEEEEEESSSS!!!!!!!!!!!!\n";
	else
		cout << "NOOOOO.....(((\n";
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