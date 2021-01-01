/*
1. Общее правило - римские цифры складываются слева направо;
2. Цифры складываются попарно.
3. Если правая цифра больше левой, то левая вычитается из правой;
4. Сначала выполняются все вычитания.

*/
#include<std_lib_facilities.h>

class Roman_int
{
	private:
	int d = 0;
	char c = ' ';
	vector<Roman_int>ri;
	public:
	
	Roman_int(int dd, char cc) : d(dd), c(cc) {}
	Roman_int() {}
	int as_int();
	
	void in_vec (Roman_int& d) {ri.push_back(d);}
	int size_of() {return ri.size();}
	
};

int Roman_int::as_int()
{
	vector<Roman_int>r;
	return 0;
	
}
int romans_translater(char& c)
{
	int i =0;
	switch (c)
	{
	case 'I':  	i=1; break;
	case 'V': 	i=5; break;
	case 'X': 	i=10; break;
	case 'L':  	i=50; break;
	case 'C': 	i=100; break;
	case 'D':  	i=500; break;
	case 'M': 	i=1000; break;
	default: error ("unexpective char"); 
	}
	return i;
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
	while (true)
	{
		c = get_char(c);
		if (c=='\n') break;
		int i = romans_translater(c);
		r=Roman_int(i,c);
		r.in_vec(r);
		
	}
	return is;
}

ostream& operator << (ostream& os, Roman_int& r)
{
	return os;
}


int main ()
try
{
	Roman_int r;
	cin >> r;
	keep_window_open();
	//cout << "Roman " << " it's " << r.as_int() << '\n'; 
}
catch (exception& e)
{
	cerr<< e.what() << '\n';
	keep_window_open();
	
}
