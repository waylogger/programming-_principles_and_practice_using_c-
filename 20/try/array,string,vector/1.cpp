#include <vector>
#include <iostream>
#include <list>
#include <string>

char lex(char a, char b)
{
	return 'e';
}


void comparation(char* c, int k)
{
std::cout << "Number of chars - " << k-1 << '\n';
char cc[6] = "Hello";
for (int i =0; i < k; ++i)
	{
	if (cc[i] != c[i])
		{
		std::cout << "Argument is not a 'Hello' \n";
		return;
		}
	} 
std::cout << "Argument is 'Hello' \n";

char o[6] = "Howdy";
for (int i = 0; i < k;++i)
{
	if (o[i] != c[i])
	{
		char m = lex(o[i],c[i]);
		if (m == o[i]) std::cout << "Howdy is elder\n";
		else std::cout << "Hello is older\n";
		break;	
	}	
}

char cop[6];
for (int i = 0; i < k;++i)
cop[i] = c[i];
} 

void comparation(std::vector<char> c)
{
std::cout << "Number of chars is = " << c.size() << '\n';
std::vector<char> nc = {'H','e','l','l','o'};
for (int i =0; i < c.size();++i)
	{
	if (c[i] != nc[i]) 
		{
			std::cout << "Argument is not a 'Hello' \n";
			return;
		}
	
	}
std::cout << "Argument is 'Hello' \n";

std::vector<char>ncc {'H','o','w','l','y'};

for (int i = 0; i < c.size();++i)
{
	if (c[i] != ncc[i])
	{
		char m = lex(c[i],ncc[i]);
		if (m == ncc[i]) std::cout << "Howdy is elder\n";
		else std::cout << "Hello is older\n";
		break;	
	}
	

}

std::vector<char>q;
q = c;

}

void comparation(std::string  s)
{
std::cout << "Number of chars in string = " << s.size() << '\n';

std::string s1 = "Hello";
if (s != s1)
{
	std::cout << "Word is not a 'Hello'\n";	
	return;
}
std::cout << "Word is 'Hello'\n";

std::string s2 = "Howdy";

for (int i = 0; i < s.size();++i)
{
	if (s[i] != s2[i])
	{
		char m = lex(s[i],s2[i]);
		if (m == s2[i]) std::cout << "Howdy is elder\n";
		else std::cout << "Hello is older\n";
		break;	
	}
	

}

std::string s3 = s;


}

void comparation(std::list<char> lc)
{
std::list<char>lc2;
lc2.push_back('H');
lc2.push_back('e');
lc2.push_back('l');
lc2.push_back('l');
lc2.push_back('o');
std::cout << "Number of chars in list - " << lc.size() << '\n';

for (int i =0; i < lc.size(); ++i)
	{
		if (*lc.begin()+i != *lc2.begin()+i)
			{
			std::cout << "Word is not a 'Hello'\n";
			return;
			}
	}
std::cout << "In list word is 'Hello' \n";

std::list<char>lc3 {'H','o','w','d','y'};
std::list<char>::iterator it3 = lc3.begin();
std::list<char>::iterator it = lc.begin();

for (int i =0; i < lc.size();++i)
{
	char a = *it;
	char b = *it3;
	
	if (a != b)
	{
	char m = lex(a,b);
	if (m == b) std::cout << "Howdy is elder\n";
	else 
		{
		std::cout << "Hello is elder\n";
		break;
		}
	
	}
++it;
++it3;
}

std::list<char>cl4;
cl4 = lc;

}

int main()
{

char a[6] = "Hello";
std::vector<char> vc;
vc.push_back('H');
vc.push_back('e');
vc.push_back('l');
vc.push_back('l');
vc.push_back('o');
std::string s = "Hello";
std::list<char>lc;
lc.push_back('H');
lc.push_back('e');
lc.push_back('l');
lc.push_back('l');
lc.push_back('o');


comparation(&a[0],6);
comparation(vc);
comparation(s);
comparation(lc);


return 0;
}
