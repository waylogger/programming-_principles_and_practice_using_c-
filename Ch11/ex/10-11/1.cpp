#include <std_lib_facilities.h>


bool stoped (const char& ch, const string& w)
{
	for (char c : w) if(ch==c) return true;
	return false;
}


vector<string>split (const string& s,const string& w)
{
	vector<string>vs;
	istringstream v(s);
	string buf;
	
	char ch;
	string big;
	while (v.get(ch))
	{
		
	if (!stoped(ch,w)) {big+=ch;}
	
	else 
		{
		vs.push_back(big);
		big.erase();
		}
	}
	
	vs.push_back(big);
	return vs;
	
}


int main ()
{
	string s = "babcaascccccc sad ";
	string w = "";
	vector<string>vs=split(s,w);
	for (int i = 0; i<vs.size();++i) cout << vs[i] << ' ';
	cout << '\n';
	keep_window_open();
}