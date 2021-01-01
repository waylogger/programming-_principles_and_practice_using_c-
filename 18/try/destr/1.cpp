#include <iostream>

using namespace std;


struct Del_me
{
	
	Del_me* a {nullptr};
	Del_me* b {nullptr};
	
	int num;
	
	Del_me(int i,Del_me* q =0, Del_me* qq=0) : num(i), a(q), b(qq) {}
	
	~Del_me();
	
	
	
	
};

Del_me::~Del_me()
{
	delete a;
	delete b;
}

void f(Del_me* q)

{
	Del_me* e = q;
	Del_me* a = new Del_me{e->num,e->a,e->b};
	delete a;
	delete e;
}

int main ()

{
	
	while (true) f(new Del_me(13232));
	
	
	
}