#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::vector;
using std::string;
using page_iterator = std::vector<string>::iterator;
/*
Порядок
1. Необходима функция сравнения двух строк, которая возвращает лексиграфически большую строку
2. Обычная функция поиска большего.


*/

class num_char
{
	private:
	char c;
	int i;
	int num_of_char(char q);
	public:
	
	num_char(char cc) : c{cc}, i{num_of_char(cc)}
		{
		}
		
	
	int num() const {return i;}
	int ch() const {return c;}
};

int num_char::num_of_char(char c)
{
	switch(c)
	{
		case 'a': return 0;		case 'A': return 0;
		case 'b': return 1;		case 'B': return 1;
		case 'c': return 2;		case 'C': return 2;
		case 'd': return 3;		case 'D': return 3;
		case 'e': return 4;		case 'E': return 4;
		case 'f': return 5;		case 'F': return 5;
		case 'g': return 6;		case 'G': return 6;
		case 'h': return 7;		case 'H': return 7;
		case 'i': return 8;		case 'I': return 8;
		case 'j': return 9;		case 'J': return 9;
		case 'k': return 10;	case 'K': return 10;
		case 'l': return 11;	case 'L': return 11;
		case 'm': return 12;	case 'M': return 12;
		case 'n': return 13;	case 'N': return 13;
		case 'o': return 14;	case 'O': return 14;
		case 'p': return 15;	case 'P': return 15;
		case 'q': return 16;	case 'Q': return 16;
		case 'r': return 17;	case 'R': return 17;
		case 's': return 18;	case 'S': return 18;
		case 't': return 19;	case 'T': return 19;
		case 'u': return 20;	case 'U': return 20;
		case 'v': return 21;	case 'V': return 21;
		case 'w': return 22;	case 'W': return 22;
		case 'x': return 23;	case 'X': return 23;
		case 'y': return 24;	case 'Y': return 24;
		case 'z': return 25;	case 'Z': return 25;
		
	}
	
	return -1;
}

page_iterator lexigraph_compair(page_iterator first, page_iterator second)

{
	if (first == second) return first;
	if (*first == *second) return first;
	const string s1 = *first;
	const string s2 = *second;
	
	for (int i =0, j = 0; i < s1.size() && j < s2.size(); ++i, ++j)
	{
		if (s1[i] != s2[j])

		{	
			
			return num_char{s1[i]}.num() > num_char{s2[j]}.num() ? first : second;
		}
	}
	//Если до выхода из цикла функция не вернула значение, значит, 
	//строки имеют разные размеры, при этом большая начинается с меньшей
	// например "пап" и "папа"
	// тогда возвращаем как лексиграфически большую ту в которой больше символов
	return s1.size() > s2.size() ?  first :  second;
}

page_iterator lexigraph_last_string(page_iterator first, page_iterator last)
{
	
	page_iterator lex_last = first;
	
	for (page_iterator i = first; i != last; ++i)
	{
		lex_last = lexigraph_compair(lex_last,i);
	}
	
	
	return lex_last;
}


int main ()
{
vector<string>a;

a.push_back("Burger kings");
a.push_back("Burger king");
a.push_back("Factorial");
a.push_back("Zohan");
a.push_back("Smith");
a.push_back("Gothic");

auto p = lexigraph_last_string(a.begin(),a.end());

cout << *p << '\n';


char c;
std::cin >> c;



	
}