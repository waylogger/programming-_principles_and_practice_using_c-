#include <iostream>

using namespace std;


class vector
{
	private:
	int sz;
	double* elem;
	public:
	vector(int s) : sz(s), elem(new double[s]) {for (int i =0; i < sz;++i) elem[i]=0.0;}
	~vector() {delete[] elem;}
	
	vector(initializer_list<double> ist) : sz{int(ist.size())}, elem{new double[sz]}
		{copy(ist.begin(),ist.end(),elem);}
		
	vector(const vector& arg);
	vector& operator= (const vector& s);
	
	vector(vector&&);
	vector& operator= (vector&&);
	void set(int i, double d) {elem[i]=d;}
	void push_back(double d) {sz+=1; elem[sz-1]=d;}
	double get(int i) const {return elem[i];}
	int size() const {return sz;}
	void clean_size() {sz=0;}
	double* elements() {return elem;}
};



vector::vector(vector&& a) : sz{a.sz}, elem{a.elem}
{
	a.sz=0;
	a.elem=nullptr;
}

vector& vector::operator= (vector&& a)
{
delete[] elem;
sz=a.sz;
elem=a.elem;
a.sz=0;
a.elem = nullptr;

return *this;
}





vector& vector::operator= (const vector& a)
{
	double* p = new double(a.size());
	for(int i =0; i < a.size(); ++i)
		p[i]=a.get(i);
	delete[] elem;
	elem = p;
	sz=a.size();
	return *this;
	}
vector::vector(const vector& arg) : sz(arg.size()), elem(new double(arg.size()))
{
	for (int i =0; i < sz; ++i)
	{
		elem[i]=arg.get(i);
	}
	
	
}

void f ()
{
	vector v(5);
	
	v.set(2,2.2);
	
	vector v2(5);
	v2=v;
	v.set(1,5);
	v2=v2;
	for (int i =0; i < v2.size(); ++i) cout << v2.get(i) << '\n';
}

int main ()
{
		
	f( );
	
	char c;
	cin >>c;
	
	
}