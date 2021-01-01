#include <iostream>

using namespace std;

class Vector
{
	double* elem;
	int sz;
	public:
	Vector(int s) : sz{s}, elem {new double[s]}
		{
			for (int i =0; i < s;++i)
			{
				elem[i]=0;
			}
		}
	~Vector() {delete[] elem;}
	int size() {return sz;}
	void set(int i, double d) {elem[i]=d;}
	double get(int i) {return elem[i];}
	void print(ostream& ost) { for (int i=0; i<size();++i) ost << elem[i] << ' ';}
	
};




int main()
{
Vector v(10);
int a = 1;
for (int i = 0; i < v.size(); ++i)
{
	v.set(i,a);
	if (a==1) ++a;
	else a*=2;
}

Vector v2(10);
v2=v;
v2.print(cout);
	char c;
	cin >> c;
	
}