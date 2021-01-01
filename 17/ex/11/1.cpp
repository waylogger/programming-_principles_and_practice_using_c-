#include <iostream>
#include <string>

#include <D:\GD\Storage\Programming\Practice\C++\17\ex\link.h>
#include <D:\GD\Storage\Programming\Practice\C++\17\ex\lex.cpp>

const int big_number = 999999;
const int less_number = -999999;
using namespace std; 


Link* Link::first()
{
	Link*p = this;
	if (!p->prev) return p;
	
	while (p->prev) p = p->prev;
	return p;
}

Link* Link::last()
{
	Link*p = this;
	if (!p->succ) return p;
	
	
	while (p->succ) p = p->succ;
	return p;
}



void Link::print_all()
{
	Link* g=this;
	if (g==nullptr) return;
	g=g->first();
	while (g)
	{
		cout 	<< g->god->name 		
				<< " " 
				<< g->god->story 
				<< " " 
				<< g->god->transport 	
				<< " " 
				<< g->god->weapon 
				<< '\n';
		
		if (g->succ) g=g->succ;
		else break;
		
	}
	
}


Link* Link::insert(Link*p, Link*n)
{
	if (p==nullptr) return n;
	if (n==nullptr) return p;
	n->succ=p;
	if (p->prev) p->prev->succ=n;
	n->prev=p->prev;
	p->prev=n;
	return n;
	
}

Link* Link::erase(Link* p)
{
	if (p==nullptr) return nullptr;
	
	if (p->succ)p->succ->prev=p->prev;
	if (p->prev)p->prev->succ=p->succ;
	
	return p->succ;

}

Link* Link::find_name(Link* p, const string& s)
{
	if (p==nullptr) return nullptr;	
	
	p=p->first();
	Link* n = nullptr;
	
	while(p)
	{
		if (p->god->name==s) n=p;
		
		p=p->succ;
	}
	return n;
	
}

Link* Link::find_country(Link* p, const string& s)
{
	if (p==nullptr) return nullptr;
	
	//p=p->first();
	while(p)
	{
		if (p->god->story==s) return p;
		p=p->succ;
	}
	return nullptr;
}

Link* Link::advice(Link*p, int n)
{
	if (p==nullptr) return nullptr;
	
	if (n>0)
	{
		while(--n)
		{
			if (p->succ==nullptr) return nullptr;
			p=p->succ;
		}
	
	}
	else if (0>n)
		while(++n)
		{
			if (p->prev==nullptr) return nullptr;
			p=p->prev;			
		}
		return p;
}

Link* Link::add(Link*p, Link*n)
{
	if (p==nullptr) return n;
	if (n==nullptr) return p;
	
	n->prev=p;
	
	if (p->succ) 
	{
		p->succ->prev=n;
		n->succ=p->succ;
	}
	
	p->succ=n;
	
	return n;
	
}


bool sub_or_more (Link* p, string s)
{
	p=p->first();
	while (p)
	{
		string ps = p->show_god()->name;
		int i = lexigraph_dif(s,ps);
		
		if (i>=0) 
		{
			return true;
		}
		if (p->next()) p=p->next();
		else 
		{
		return false;	
		}
	}
	
	return false;
}


Link* Link::add_ordered(Link* p, Link* n)
{
	if (p==nullptr) return n;
	if (n==nullptr) return p;
	p=p->first();
	int idx = big_number;
	int i = 0;
	string fs, ps;
	const string& ns = n->god->name;
	bool c = sub_or_more(p,ns);
	p=p->first();
	if (c) 
	{
		while (p)
	{
		ps = p->god->name;	
		i = lexigraph_dif(ns,ps);
		
		if (i>=0 && idx>=i) {idx = i; fs = ps;}
		if (p->succ) p = p->succ;
		else break;
	}
		
		return add(find_name(p,fs),n);
	}
	if (!c) 
	{
		idx = -idx;
		while (p)
	{
		
		ps = p->god->name;
		
		i = lexigraph_dif(ns,ps);
		if (idx < i) 	{ idx = i; fs = ps; }
		if (p->succ) p = p->succ;
		else break;
	}
		
		return add(n,find_name(p,fs));
	}
		return add(p,n);
}



 


int main () 
{
Link* common = new Link{new God{"Zeus","Greese","","Flash"}};
common = common->add_ordered(common,new Link{new God{"Ares","Greese","","Spear"}});
common = common->add_ordered(common,new Link{new God{"Afina","Greese","","Spear"}});
common = common->add_ordered(common,new Link{new God{"Jupiter","Rome","","Staff"}});
common = common->add_ordered(common,new Link{new God{"Mars","Rome","","Sword"}});
common = common->add_ordered(common,new Link{new God{"Minerva","Rome","","Spear"}});
common = common->add_ordered(common,new Link{new God{"Thor","Norway","","Hammer"}});
common = common->add_ordered(common,new Link{new God{"Odin","Norway","","Spear"}});
common = common->add_ordered(common,new Link{new God{"Freia","Norway","","Cats"}});


Link* greese = nullptr;
Link* norway = nullptr;
Link* rome = nullptr;
common=common->first();
God* g;
while(common)
{
	g = common->show_god();
	if (g->story=="Greese")
	greese = greese->add_ordered(greese,new Link{g});
	else if (g->story=="Rome")
	rome = rome->add_ordered(rome,new Link{g});
	else if (g->story=="Norway")
	norway = norway ->add_ordered(norway,new Link{g});
	
	
	if (common->next()) common=common->next();
	else break;
}

	rome->print_all();
	norway->print_all();
	greese->print_all();








	char c;
	cin >> c;
	
	
	
	
	
	
	
	
}