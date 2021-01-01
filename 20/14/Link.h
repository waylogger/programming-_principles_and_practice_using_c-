#include <iostream>
#include <memory>
#define T_Elem_A template <typename Elem, typename A>

using std::cout;
using std::cin;


template <typename Elem, typename A = std::allocator<Elem>>
struct Link {
	Link* succ = nullptr;
	Elem* val = nullptr;
	A alloc;
	
	Link(Elem a, Link* s = nullptr) 
		:  val{alloc.allocate(sizeof(Elem))}, succ(s)
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
};


T_Elem_A Link<Elem,A>* Link<Elem,A>::insert(Link* p, Link*n)	{
		if (!p) return n;
		if (!n) return p;
		
		if (p->succ){
		n->succ = p->succ;
		}
		p->succ = n;	
		return n;
	}
	
	
T_Elem_A Link<Elem,A>* Link<Elem,A>::erase(Link* p){
	
	if (!p) return nullptr;
	
	if (!p->succ) {
		if (p->val) {
		alloc.destroy(p->val);
		alloc.deallocate(p->val,sizeof(Elem));
		p->val = nullptr;
		}
		return p;
	}
		
	else {
		alloc.destroy(p->val);
		alloc.deallocate(p->val,sizeof(Elem));
		p->val = nullptr;
		return p;
	}
	
	

}

T_Elem_A Link<Elem,A>::~Link()	{
		auto d = this;
		d = d->erase(d);

	}
	
	
