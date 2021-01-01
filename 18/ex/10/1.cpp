#include <iostream>
#include <string>

using namespace std;
bool is_palindrome(const char s[])
{
	int first = 0;
	int last = strlen(s)-1;
	
	while (first < last)
	{
		if (s[first] != s[last]) return false;
		++first;
		--last;	
	}
	return true;
}

istream& read_word (istream& ist, char* c)
{
		 
	ist >> c; 
	return ist;
}
int main ()
{
	
 
	constexpr int  n = 5;
	for (char c[n]; read_word(cin,c);)
	{
		
		cout << c << " is a";
		if (!is_palindrome(c)) cout << " not";
		cout << " palindrome\n";
	}
	
	
	
	char q;
	cin >> q;
	
	
	
}