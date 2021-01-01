
#include <std_lib_facilities.h>

string get ()
{

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

string unions ()
{
string s = get();
	if (
		s=="and"
		||s=="or"
		||s=="but")
		{
		return s;
		string s = get();
		}
	};

string substantive ()
{
string s = get();
	if (
		s=="birds"
		||s=="The birds"
		||s=="fish"
		||s=="The fish"
		||s=="C++"
		||s=="The C++")
		{
		return s;
		string s = get();
		}
	
};

string verb ()
{
	string s = get();
	if 	(
		s=="rules"
		||s=="fly"
		||s=="swim"
		)
		{
		return s;
		string s = get();
		};

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