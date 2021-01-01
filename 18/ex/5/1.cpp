#include <iostream>


using namespace std;

namespace My_nsp
{
	
	int strlen(const char* s)
	{
		int count = 0;
		while(*s)
		{
			++count;
			++s;
		}
		s=s-count;
		return count;
	}
	
	
}
char* add(char* r, const char* s )
{
	
	while (*s)
	{
		
		*r = *s ;
		++r;
		++s;
	}
	
	return r;
}

char* cat_dog (const char* s1, const char* s2, const char* m)
{
	
	int size = My_nsp::strlen(s1)+My_nsp::strlen(s2)+My_nsp::strlen(m);
	
	char* r = new char[size];
	char* rr = r;
	r=add(r,s1);
	r=add(r,m);
	r=add(r,s2);
	*r = char(0);
	
	return rr;
	
	
	
	
}

void print (const char* p)
{
	while (*p)
	{
		cout << *p;
		++p;
	}
		
}

int main ()
{
	char* a = nullptr;
while (true)
{
	a = cat_dog("qwertyuiop","asdfghjk","zxcvbn");
	//print(a);
	delete a;	
}
	char c;
	cin >> c;
}