#include <std_lib_facilities.h>

const char breaking = '\n';
class Roman
{
	private:
	char kind;
	int value;
	int total_sum =0;
	string expression;
	public:	
	Roman get_roman();
	int as_int();
	bool comparison (const Roman& a, const Roman&b);
	Roman(char k, int v) : kind(k), value(v) {}
	Roman () {}
};

char get_char (char c)
{
	while (cin.get(c))
	{
		if (c==' ') {cin.clear(); cin.get(c);}
		return c;
	}
	return 'a';
}

Roman Roman::get_roman()
{
	char c = get_char(c);
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
			case	breaking: v=0;	break;
			default:
				error ("Unexpective charaster", c);
	}
	Roman r = {c,v};
	return r;
}

int Roman::as_int()
{
	int a = 0;
	vector<int>box;
	while (true)
	{
	Roman k = get_roman();
	if (k.kind=='\n') break;
	box.push_back(k.value);
	}
	for (int i =0; i<box.size();++i)
	{
		if(i+1>=box.size()) {a+=box[box.size()-1]; break;}
		if (box[i]<box[i+1]) 
		{
			box [i+1]=box[i+1]-box[i];
			box[i]=0;
		}
		a+=box[i];
		
	}
	total_sum=a;
	
	return total_sum;
}

istream& operator >> (istream& is, Roman& r)
{
	
}


int main () 
try 
{
	Roman r;
	
	keep_window_open();
}
catch (exception& e)
{
	cerr << e.what () << '\n';
	keep_window_open("~~");
}