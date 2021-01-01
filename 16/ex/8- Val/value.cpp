namespace Value
{
	
	class Val
{
	double fval;
	double sval;
	string first;
	string second;
	double mul_Forward;
	vector<Val>v;
	Val() {}
	public:
	Val(string a, string b, double fv, double sv);
	Val (const string& s);
	string see_first() const {return first;}
	string see_second() const {return second;}
	double see_forward() const {return mul_Forward;}
	Val num(const int& i) {return v[i];}
	int number_of_val() {return v.size();}
	
};

ifstream& operator >> (ifstream& ist, Val& v);

Val::Val(string a, string b, double fv, double sv)
	: first(a), second(b), fval(fv), sval(sv), mul_Forward{sv/fv}
	{
		
	}
	
	Val::Val (const string& s)
	{
	ifstream ist {s};
	
	for (int i=0; i < 4; ++i)
	{
	Val b; 
	ist >> b;
	if (!ist) break;
	v.push_back(b);
	}
	}

void readinchar(istream& ist, char c ,const string&s)
{
	ist >> c;
	
	if (!ist)
	{
	ist.ios_base::clear();
	string trash;
	ist >> trash;
	error(s);
	}
}

void readinstring (istream& ist, string& r)
{
	char ch2 = 0;
	while (ist >> ch2)
	{
		if (ch2!='(') r+=ch2;
		if (ch2=='(') break;
	}
}

void readindigit (istream& ist, double& r, const string& s)
{
	ist >> r;
	if (!ist)
	{
	ist.ios_base::clear();
	string trash;
	ist >> trash;
	error(s);
	}
}
	




ifstream& operator >> (ifstream& ist, Val& v)
{
	string f,s;
	char ch1 =0,  ch3=0, ch4=0, ch5=0, ch6=0, ch7=0, ch8=0;
	double to =0;
	double back =0;
	ist >> ch1;
	if (!ist) {ist.eof(); return ist;}
	ist.unget();
		
	readinchar (ist,ch1,"1 - Expected '{'");
	
	readinstring(ist,f);
	
	readindigit(ist,to,"4 - Expected double in ()");
	
	readinchar (ist,ch3,"5 - Expected ')'");
	
	readinchar (ist,ch4,"5 - Expected '='");
	
	readinstring(ist,s);
	
	readindigit(ist,back,"8 - Expected double in ()");
	
	readinchar (ist,ch7,"9 - Expected ')'");
	
	readinchar (ist,ch8,"10 - Expected '}'");

	v = Val{f,s,to,back};
	return ist;
}

} //end of value