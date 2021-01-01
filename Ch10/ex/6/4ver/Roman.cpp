#include <std_lib_facilities.h>

const char new_line = '\n';

int roman_to_int (string& s);

class Roman
{
	private:
	int i;
	char num;
	string full_num;
	int sum;
	public:
	Roman(char n, int ii) : num (n), i(ii) {}
	Roman(string fn) : full_num(fn) {};
	Roman(string fn, int s) : full_num(fn), sum(s) {};
	Roman () {}
	
	string see_num () const {return full_num;}
	int as_int () {return sum;}
	int see_i() {return i;}

	
	
};

bool operator > (Roman& r, Roman& rr)
{
	if (r.see_i()>rr.see_i()) return true;
	return false; 
}

bool operator < (Roman& r, Roman& rr)
{
	if (r.see_i()<rr.see_i()) return true;
	return false; 
}

istream& operator >> (istream& is, Roman& r)
{
	string s;
	is >> s;
	int i = roman_to_int(s);
	r = Roman(s,i);
	return is;
}

ostream& operator << (ostream& os, const Roman& r)
{
	return os << r.see_num();
}
int what_val(char& c)
{
	int v = 0;
	switch(c)
	{
			case 	'I': v = 1; 		break;
			case 	'V': v = 5; 		break;
			case 	'X': v = 10; 		break;
			case 	'L': v = 50; 		break;
			case 	'C': v = 100; 		break;
			case 	'D': v = 500; 		break;
			case 	'M': v = 1000; 		break;
			case	new_line: v=0;	break;
			default:
				error ("Unexpective charaster", c);
	}
	return v;
}


bool currect_roman (const char& c)
{
		switch (c)
		{
		case 	'I':
		case 	'V':
		case 	'X':
		case 	'L':
		case 	'C':
		case 	'D':
		case 	'M':
		case	new_line:
		return true;
		}
		return false;
}


string get_char ()
{
	char c = ' ';
	string s;
	while (true)
	{
		cin.get(c);
		if (!currect_roman(c)) { cerr << c; error (" is unexpective charaster");}
		if (c!=' ') s+=c;
		if (c=='\n') return s;
		
	}
	return s;
}

int roman_to_int (string& s)
{
	int val =0;
	int val2 = 0;
	int sum = 0;
	Roman r;
	Roman rr;
	for (int i =0; i<s.size();++i) 
	{
		if(i+1>=s.size()) 
		{
			s[i+1]=s[i];
		}
		val = what_val(s[i]);
		val2 = what_val(s[i+1]);
		r = {s[i],val};
		rr = {s[i+1],val2};
		if (r<rr) r = Roman(s[i],val=-val);
		sum+=r.see_i();
	}
	//cout << sum << '\n';
	return sum;
		
} 

string roman_back(double i) //Переводим арабские цифры в римские
{
	string sum = "";
	

	char M = 'M';	char D = 'D';
	char C = 'C';	char L = 'L';
	char X = 'X';	char V = 'V';
	char I = 'I';
	
		
	while (i>=1000)	{i=i-1000;	sum+=M;} //Вычленяем тысячи
	while (i>=500)	{ 
		if (i>900 && i < 1000) {sum+="CM"; i=i-900; break;}
					 i=i-500;	sum+=D;}
	while (i>=100)	{
		if (i >400 && i < 500) {sum+="CD"; i=i-400; break;}
					 i=i-100;	sum+=C;}
	while (i>=50)	{
		if (i==90) {sum+="XC"; i=i-90; break;}
					 i=i-50;	sum+=L;	}
	while (i>=10)	{
		if (i>40 && i < 50) {sum+="XL"; i=i-40; break;}
					 i=i-10;	sum+=X;}
	while (i>=5)	{
		if (i==9) {sum+="IX"; i=i-9; break;}
					 i=i-5;		sum+=V;}
	while (i>=1)	{
		if (i==4) {sum+="IV"; i=i-4; break;}
					 i=i-1;		sum+=I;}
	return sum;
}

/*
int main ()
try
{
	Roman r;
	cin >> r;
	cout << "Romans - " << r << " - it is - " << r.as_int() << '\n';
	int i = 0;
	cin >> i;
	cout << "Arabian - " << i << " = it is - " << roman_back(i) << '\n'; 
	keep_window_open();
}

catch (exception& e)
{
	cerr << e.what() << '\n';
	keep_window_open("~~");
}

*/












