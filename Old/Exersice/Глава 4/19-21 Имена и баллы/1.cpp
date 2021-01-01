// »мена и баллы

#include <std_lib_facilities.h>

class nameandscore {
	public:
	string name;
	int score;
};

vector<nameandscore>ns;






















int main () 
try
{


string name = " ";
int score = 0;

int ino = 0;
int ino2 = 0;

int ch1 =0;
int ch2 =0;

//..................................................	
//..................................................
//..................................................
//..................................................
while (cout << "Input - 1, output -2\n" && cin >> ino) 
{

if (ino==1)
while (cout << "Name, scores\n" && cin >> name >> score && name!="noname")
	{
for (int ch1 =0; ch1 < names.size (); ++ch1 )
if (name==names[ch1]) error("Povtor: ", name);
names.push_back(name);
scores.push_back (score);
	}
//..................................................	
//..................................................
//..................................................
//..................................................
if (ino==2)
cout << " All list - 1\n Search for name - 2\n Search for score - 3\n";
if (ino==2)
cin >> ino2;
//..................................................	
//..................................................
//..................................................
//..................................................

if (ino2==1)
for (int ch1 = 0; ch1 < names.size (); ++ch1) 
	{
cout << ch1+1 << " - " << names[ch1] << " | " << scores[ch1] << "|\n";
	}
//..................................................	
//..................................................
//..................................................
//..................................................
name = " ";
if (ino2==2)
	while (name!="noname")
		{
		cout << "Insert name\n";
		cin >> name;
	
				for (int ch1 = 0; ch1 < names.size ();++ch1)
		{
		if (name==names[ch1])
		cout << "\nScores of " << names[ch1] << " - " << scores[ch1] << "|\n";
		if (name!=names[ch1])
			++ch2;
		}
		if (ch2==names.size ())
		if (name!="noname")
		cout << "Takogo imeni net\n";
		ch2=0;
	}

//..................................................	
//..................................................
//..................................................
//..................................................
score=1;
if (ino2==3)
while (score!=0)
{
cout << "Vvedite chislo ballow = \n";
cin >> score;

	for (int ch1 =0; ch1 < names.size (); ++ch1) 
	{
	if (score==scores[ch1])
	cout <<  score << " - " << names[ch1] << "|\n";
	if (score!=scores[ch1]) 
	++ch2;
	}
if (ch2==scores.size ())
if (score!=0)
	cout << "Takogo chisla ballow net\n";
		ch2=0;
	}
//..................................................	
//..................................................
//..................................................
//..................................................
}
}
catch (runtime_error e) 
{
	cout << e.what () << '\n';
	keep_window_open ("~");
}
catch (...) {
	cout << "Exiting\n"; 
	keep_window_open ("~");
}

