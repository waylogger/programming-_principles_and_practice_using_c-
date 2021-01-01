#include <iostream>

using namespace std;


class vector
{
	private:
	int sz;
	double* elem;
	public:
	explicit vector (int i) : sz(i), elem(new double[i])
	{
		for (int i =0; i < sz; ++i)
			elem[i]=0;
	}
	double& operator[] (int i) {return elem[i];}
	double operator[] (int i) const {return elem[i];}
	};
	
	
	int main()
	{
		const vector v (5);
		//v[2]=5;
		double b = v[2];
		cout << v[2] << '\n';
		char c;
		cin >> c;
	}