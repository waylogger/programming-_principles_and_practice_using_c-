#include <iostream>
#include <memory>
#define T_Elem_A template <typename Elem, typename A>

using std::cout;
using std::cin;


template <typename Elem, typename A = std::allocator<Elem>>
struct Link {
	Link* prev = nullptr;
	Link* succ = nullptr;
	Elem* val = nullptr;
	A alloc;
	
	Link(Elem a, Link* p = nullptr, Link* s = nullptr) 
		:  val{alloc.allocate(sizeof(Elem))}, prev{p}, succ(s)
	{
		alloc.construct(val,a);
	}

	Link(const Link& l) {
		Link* t = this;
		t->val = alloc.allocate(sizeof(Link<Elem>));
		alloc.construct(t->val,*l.val);

	}
	~Link();
	
	Link* insert(Link* p, Link*n);
	Link* erase(Link* p);
	void breaking_back(Link * p);
	
};

T_Elem_A void Link<Elem,A>::breaking_back(Link* p){
			p->prev = nullptr;
			while (p) p = p->erase(p);
}

T_Elem_A Link<Elem,A>* Link<Elem,A>::insert(Link* p, Link*n)	{
		if (!p) return n;
		if (!n) return p;
		
		if (p->succ) breaking_back(p->succ);
				
		if (n->prev)
		{
			
			n->prev->succ = p;
			p->prev = n->prev;
		}
		
		p->succ = n;
		n->prev = p;	
		
		
		
		return p;
	}
T_Elem_A Link<Elem,A>* Link<Elem,A>::erase(Link* p){
	
if(!p) return p;

if (!p->prev && !p->succ){
	alloc.destroy(p->val);
	alloc.deallocate(p->val,sizeof(Elem));
	p->val = nullptr;
	return p;
}

else if(p->prev && !p->succ) {
	
	alloc.destroy(p->val);
	alloc.deallocate(p->val,sizeof(Elem));
	p->prev->succ = nullptr;
	p = p->prev;
	return p;
}

else if (!p->prev && p->succ) {
	if (!p->val) return p;
	alloc.destroy(p->val);
	alloc.deallocate(p->val,sizeof(Elem));
	p->val = nullptr;
	p->succ->prev = nullptr;
	
	//cout << "I am here - " << p->val  << "\n";
	
	p = p->succ;
	

	return p;
}

else if (p->prev && p->succ) {
	alloc.destroy(p->val);
	alloc.deallocate(p->val,sizeof(Elem));
	p->prev->succ = p->succ;
	p->succ->prev = p->prev;
	p = p->prev;
	return p;
}
return p;
}
T_Elem_A Link<Elem,A>::~Link()	{
		auto d = this;
		//cout << "destruct\n";
			d = d->erase(d);

	}