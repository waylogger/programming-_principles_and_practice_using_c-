#include <iostream>


using namespace std;

class Error {};

namespace My_nsc
{
	int strlen(const char* c) // аналог библиотечной функции
{
	int n = 0;
	
	while(*c) //встречаем 0 = прекращаем
	{
		
		++c;
		++n;
	}
	
	return n;
	
}



}


int char_to_int(const char& q)
{
switch(q)
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
return -1;
}




char* strdup ( const char* c, int i)
{
	
	
	char* b = new char(0); //не  nullptr, чтобы можно было применить оператор разыменовывания
	
	char* const bb = b; //сохраняем адрес
	char* a = nullptr;
	
	int count = 0;
	while (count<i)
	{
		a = new char(*c); //инициализируем а динамически
		*b = *a;
		++b;
		++c;
		++count;

	}
	a = new char(0); //создаем С строку
	*b=*a;
	
	return  bb; //возвращаем сохраненный адрес
}

void print(char* a)
{
	
	while(*a)
	{
		cout << *a;
		++a;
	}
}

char* deep_copy_cstr(const char* s) // выполняем глубокое копирование
{
	char* dest = new char[My_nsc::strlen(s)]; //выделяем память равную размеру исходной С строки
	char* buffer = dest;
	
	
	while(*s) // копируем   s in dest
	{
		*dest = *s;
		++dest;
		++s;

	}
	
	*dest=char(0); // to finish C-string
	
	

	return buffer; //return from memory
}


char* findx (const char* s, const char* x, int i)
{
	char* ns = deep_copy_cstr(s);
	char* nx = deep_copy_cstr(x);
	int c =0;
	while (c<i)
		
	{
		int count = 0; //счетчик
		++c;
		while (*ns == *nx)
		{ 
		
		++count;
		if (count == My_nsc::strlen(x)) 
			{
				return ns-(count-1); // если совпадений по числу искомой строки минус единица
			}
		++ns;
		++nx;
		++c;
		if (*ns != *nx) //если совпадений недостаточно для возврата значения
			{
			nx=nx-count; //откат в начало искомой строки
			break;
			}
		
		}
		++ns;

}
	delete[] nx;
	
	return nullptr;	
}


int srtcmp(const char* s1, const char* s2, const int& m)
{
	 
	if (char_to_int(*s1) < char_to_int(*s2)) 		return 1; //   если первые символы различны, то возврат

	else if (char_to_int(*s1) > char_to_int(*s2)) 	return -1;
	
	int ls1 = My_nsc::strlen(s1); // берем размеры
	int ls2 = My_nsc::strlen(s2);
	
	if (ls1 > m) ls1=m;
	if (ls2 > m) ls2=m;
	
	for (int i = 1; i < ls1 || i < ls2; ++i)
	{
		
		++s1;
		++s2;
		if (*s1 != *s2) //наконец-то находим разные символы
		{
			cout << "qwe" << '\n';
			if 		(char_to_int(*s1) < char_to_int(*s2)) 		return 1;
			else if (char_to_int(*s1) > char_to_int(*s2)) 		return -1;
		}
	
	
	}
	
	if 		(My_nsc::strlen(s1) < My_nsc::strlen(s2)) 		return 1; //если слово короче, то главнее
	else if (My_nsc::strlen(s1) > My_nsc::strlen(s2)) 		return -1;
	
	return 0;
}

char* non_cstr(const char* c)
{
	char* r = new char[My_nsc::strlen(c)];
	char* rr = r;
	while (*c)
	{
		*r=*c;
		++c;
		++r;
	}
	
	return rr;
}

int main ()
try
{

char* q = strdup ("qwer",2);

print (q);


char c;
cin >>c;

}


catch (...)
{
	cerr << "Unknown error";
	char c = ' ';
	cin >> c;
}