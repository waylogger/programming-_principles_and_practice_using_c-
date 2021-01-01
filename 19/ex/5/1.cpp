#include <iostream>
#include <string>

using namespace std;



class INT
{
	private:
	int a;
	public:
	INT(int aa) : a(aa) {};
	INT(double d) : a(int(d)) {};
	INT () : a(0) {};
	
	int num() const {return a;}
	INT& operator= (const INT&);
	void set(int i) { a = i;}
};

INT operator+(const INT a, const INT b)
{
	return INT(a.num() + b.num());
}

INT operator-(const INT a, const INT b)
{
	return INT(a.num() - b.num());
}

INT operator*(const INT a, const INT b)
{
	return INT(a.num() * b.num());
}

INT operator/(const INT a, const INT b)
{
	return INT(a.num() / b.num());
}

INT& INT::operator= (const INT& i)
{
	this->a = i.a;
	return *this;
}

ostream& operator<<(ostream& ost, const INT& i)
{
	ost << i.num();
	return ost;
}


istream& operator>>(istream& ist, INT& i)
{
	int q = 0;
	ist >> q;
	
	if (!ist)
	{
		ist.clear();
		string s;
		cin >> s;
	}
	
	i = INT(q);
	
	return ist;
}
 

int main ()
{
INT a = 56;
cin >> a;

cout << a;


char c;
cin >>c;	

};













