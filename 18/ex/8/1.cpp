

#include <iostream>
#include <string>

using namespace std;


bool is_palindrome(const string& s)
{
	int first = 0;
	int last = s.length()-1;
	
	while (first < last)
	{
		if (s[first] != s[last]) return false;
		++first;
		--last;
	}
	return true;
}


bool is_palindrome(const char s[], int max)
{
	int first = 0;
	int last = max-1;
	
	while (first < last)
	{
		if (s[first] != s[last]) return false;
		++first;
		--last;	
	}
	return true;
}

istream& read_word(istream& is, char* buffer, int max)
{
	is.width(max);
	is >> buffer;
	return is;
}

bool is_palindrome (const char* first, const char* last)
{
	while (first < last)
	{
		if (*first != *last) return false;
		--last;
		++first;
	}
	return true;
}



string to_back(const string& s)
{
	string ss = "";
	
	for (int j = s.length()-1; j >= 0; --j)
	{
		ss += s[j];
	}
	
	
	return ss;
}

char* to_back(const char* s)
{
	char* ss = new char[strlen(s)];
	char* vs = ss;
	for (int i = strlen(s)-1; i >= 0; --i)
	{
		*ss = s[i];
		++ss;
	}
	*ss=char(0);
	return vs;
}




int main ()
{
	constexpr int max = 128;
	/*
	for (string s; cin>>s && s!="0"; )
	{
		cout << s  << " and " << to_back(s) << " is ";
		if (! is_palindrome(s) || !  is_palindrome(to_back(s)) ) cout << "not a ";
		cout << "palindrome\n";
	}
	*/

	for (char s[max]; read_word(cin,s,max);)
	
	{
		
		cout << s  << " and " << to_back(s) << " is ";
		char* f = to_back(s);
		if (! is_palindrome(&s[0],&s[strlen(s)-1]) || 
			!is_palindrome(&f[0],&f[strlen(f)-1])) cout << "not a ";
		cout << "palindrome\n";
	}
	
	
	
	
	char c;
	cin >> c;
	
	
}
