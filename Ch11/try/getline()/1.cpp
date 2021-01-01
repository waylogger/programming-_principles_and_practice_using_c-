#include <std_lib_facilities.h>


int main ()
{
	setlocale(0,"");
	string a = "";
	getline(cin,a);
	stringstream aa {a};
	vector <string>words;
	
	for (string s; aa>>s;)
		words.push_back(s);
	cout << a << '\n';
	
	for (int i =0; i<words.size();++i)
		cout << words[i] << '\n';
	keep_window_open();
}
