#include <std_lib_facilities.h>
int main ()
{
	vector<string> words;
	string ava = " ";
	cout << "Vvelite tekst" << "\n";
	for (string ava = " "; cin >> ava;)
	words.push_back (ava);
string i = " ";
for (string i : words)
if (i=="broke")
cout << "censored" << "\n";
else
cout << i << "\n";	
keep_window_open ();
}
