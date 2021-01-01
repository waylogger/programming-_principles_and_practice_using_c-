//#include <std_lib_facilities.h>

#include <iostream>

using namespace std;

/*
class vector
{
	private:
	int sz;
	double* elem;
	public:
	vector(int s) : sz{s}, elem { new double[s]}
	{
			for (int i  =0; i < s ; ++i)
			{
				elem[i]=0;
			}
		}
	int size() {return sz;}
	~vector() {delete elem;}
	
	double get(const int& i) {return elem[i];}
	void set(const int& i, const double& d) {elem[i]=d;}
};

*/

class Register { public: int i =0;};

void f(const double& d)
{
double b = const_cast<double>(d);
}

int main () 

{
	
Register* in;
in = reinterpret_cast<Register*>(0xff);
cout << in->i << '\n';
char c;
cin >> c;



}
