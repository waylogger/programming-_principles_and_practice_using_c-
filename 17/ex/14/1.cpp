#include <iostream>

#include <string>

using namespace std;


class Link
{
	private:
	Link* succ;
	string value;
	public:
	string show_name() const {return value;}
	void set_name(const string& s) {value = s;}
	Link(string v, Link* s=nullptr) : value{v}, succ{s} {}
	
	Link* next () {return succ;}
	void set_next(Link* const p) {succ=p;}
	Link* insert(Link* const n);
	
};

Link* Link::insert(Link* n)
{
	if (this == nullptr) return n;
	if (n == nullptr) return this;
	n->succ=this;
	return n;
}

Link* erase(Link*  p, Link* const n)
{
	
	while (p->next()->show_name() != n->show_name())
	{
		
		if (p->next()) p=p->next();
		if (!p->next()) return nullptr;
	}
	
	p->set_next(p->next()->next());

	return n;
	
	
		
}


void print(Link* const p)
{
	Link* n = p;
		cout << '{';
	while (n)
	{
		cout << n->show_name() << " ";
		
		if (n->next()) n=n->next();
		else 
		{
			cout << "}\n";
			return;
	}
		}
}

Link* find (Link* p, string s)
{
	while (p)
	{
		if (p->show_name()==s) return p;
		if (p->next()) p=p->next();
		else return nullptr;
	}
	return nullptr;
}


int main ()
{
	
	Link* norse_gods = new Link{"Thor"};
	norse_gods = norse_gods->insert(new Link {"Odin"});
	norse_gods = norse_gods->insert(new Link {"Zeus"});
	norse_gods = norse_gods->insert(new Link {"Freia"});
	
	
	
	Link* greek_gods = new Link{"Hera"};
	greek_gods = greek_gods->insert(new Link {"Athena"});
	greek_gods = greek_gods->insert(new Link {"Mars"});
	greek_gods = greek_gods->insert(new Link {"Poseidon"});
	
	Link* p = find(greek_gods,"Mars");
	p->set_name("Ares");
	
	
	Link* p2 = norse_gods;
	
	if (p2)
	{
		if (p2==norse_gods->next()) norse_gods=p2->next()->next();
		
		greek_gods=greek_gods->insert(erase(p2,new Link{"Zeus"}));

	}
	
	print(norse_gods);
	print(greek_gods);
	
	
	char c;
	cin >> c;
	
	
	
	
}









