#include <string>
#include <vector>
#include <iostream>

using namespace std;

int num_of_char (const char c)
{
	switch(c)
	{
		case 'A': case 'a': return 0;
		case 'B': case 'b': return 1;
		case 'C': case 'c': return 2;
		case 'D': case 'd': return 3;
		case 'E': case 'e': return 4;
		case 'F': case 'f': return 5;
		case 'G': case 'g': return 6;
		case 'H': case 'h': return 7;
		case 'I': case 'i': return 8;
		case 'J': case 'j': return 9;
		case 'K': case 'k': return 10;
		case 'L': case 'l': return 11;
		case 'M': case 'm': return 12;
		case 'N': case 'n': return 13;
		case 'O': case 'o': return 14;
		case 'P': case 'p': return 15;
		case 'Q': case 'q': return 16;
		case 'R': case 'r': return 17;
		case 'S': case 's': return 18;
		case 'T': case 't': return 19;
		case 'U': case 'u': return 20;
		case 'V': case 'v': return 21;
		case 'W': case 'w': return 22;
		case 'X': case 'x': return 23;
		case 'Y': case 'y': return 24;
		case 'Z': case 'z': return 25;
	}
	return 0;
}


struct Token
{
	int num;
	char letter;
	Token (char l) : letter(l), num(num_of_char(l)) {};
};

bool lexigraph_last (const string& s1, const string& s2)
{
	for (int i =0, j =0; i < s1.size() || j < s2.size(); ++i, ++j)
	{
		if (s1[i]!=s2[j])
		{
			Token f {s1[i]};
			Token s {s2[j]};
			if (f.num>s.num) 		return true;
			else if(f.num<s.num) 	return false;
		}
	}
	return false; 
}



void ordered_insert(vector<string>& v, const string& s1)
{
	string s2 = "";
	for (int i =0; i < v.size();++i)
	{
		if (lexigraph_last(s1,v[i])) 
		{
		s2 = v[i];
		break;
		}
	}
	
	for (int i =0; i < v.size(); ++i)
	{
		if (lexigraph_last(v[i],s2) && lexigraph_last(s1,v[i])) s2 = v[i];
	}
	cout << s2 << '\n';
}

int main ()
{

vector<string> v = {"A","B","C","D","F","G"};
ordered_insert(v,"H");



	
	
	char c;
	cin >> c;
		}


















