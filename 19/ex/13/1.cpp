#include <iostream>
#include <string>

using namespace std;



struct Tracer
{
	string init;
	string del;
	string copy;
	string copy_operator;
	
	Tracer(string i, string d,string c,string co) : init(i), del(d), copy(c), copy_operator(co)
	{
		cout << init << '\n';
	}
	Tracer(const Tracer&t)
	{
				init = t.init;
				del = t.del;
				copy = t.copy;
				copy_operator = t.copy_operator;
				
				cout << copy_operator << '\n';
		cout << copy << '\n';
	}
	
	Tracer& operator= (const Tracer&t) 
	{
				init = t.init;
				del = t.del;
				copy = t.copy;
				copy_operator = t.copy_operator;
				
				cout << copy_operator << '\n';
				
				return *this;
	}
	~Tracer()
	{
		cout << del << '\n';
	}
	
};


Tracer q = {"initialization in global","destruction in global","copy in global","copy_operator in global"};
Tracer qq = q;


struct A
{
	Tracer q = {"initialization in class","destruction in class","copy in class","copy_operator in class"};
	A() {};
};


int main ()

{
	A a;
	
	Tracer* t = new Tracer{"initialization in poiner","destruction in poiner","copy in poiner","copy_operator in poiner"};
	delete t;
	q = qq;
	
	char c;
	cin >> c;
	
}