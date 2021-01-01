/*
1. Общее правило - римские цифры складываются слева направо;
2. Цифры складываются попарно.
3. Если правая цифра больше левой, то левая вычитается из правой;
4. Сначала выполняются все вычитания.


Грамматика:
Выражение:
Число<Числа Вычитание
Число>Числа Сложение

Сложение
Число+Число

Вычитание
Число-Число

Число:
I
V
X
L
C
D
M

*/
#include<std_lib_facilities.h>

class Roman_int
{
	private:
	int digit = 0;
	string c = " ";
	public:
	int get_dig() const {return digit;}
	Roman_int() {}
	Roman_int(string cc) : c(cc) {digit = as_int ();}
	int as_int();
};
int rome_to_int (char ch)
	
{	
	int num =0;
	switch (ch)
		{
			case 	'I': num = 1; 		break;
			case 	'V': num = 5; 		break;
			case 	'X': num = 10; 		break;
			case 	'L': num = 50; 		break;
			case 	'C': num = 100; 	break;
			case 	'D': num = 500; 	break;
			case 	'M': num = 1000; 	break;
		}
	return num;
}

int Roman_int::as_int()
{
	vector<int>forsum;
	char ch = ' ';
	int num = 0;
	int sum = 0;
	for (int i = 0; i < c.size(); ++i)
	{
	num = rome_to_int(c[i]);
	forsum.push_back(num);
	}
	for (int v : forsum) cout << v << ' ';
	return num;
}
bool correct_get(char& c)
{
	switch (c)
	{
	case 'I': 
	case 'V': 
	case 'X':
	case 'L': 
	case 'C':
	case 'D': 
	case 'M':
		return true;
		break;
	default: 
		return false;
	}
	return false;
}

char get_char (char c)
{
	while (cin.get(c))
	{
		if (c==' ') {cin.clear(); cin.get(c);}
		return c;
	}
	return 'a';
}

istream& operator >> (istream& is, Roman_int& r)
{
	char c = ' ';
	string s = "";
	int i = 0;
	while (true)
	{
		c=get_char(c);
		if (c=='\n') break;
		if (!correct_get(c))error ("Unexpective char");
		s+=c;
	}
	r = Roman_int(s);
	return is;
}

ostream& operator << (ostream& os, Roman_int& r)
{
	
	int i = r.get_dig();
	os << i;
	return os;
}


int main ()
try
{
	Roman_int r;
	
	cin >> r;
	//cout << r << '\n';
	
	keep_window_open();
	//cout << "Roman " << " it's " << r.as_int() << '\n'; 
}
catch (exception& e)
{
	
}
