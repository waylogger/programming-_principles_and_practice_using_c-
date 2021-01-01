#include <D:\\Programms\\20\\12\\Link.h>
	
struct Smth_bad {
	char s[10] = "Smth bad\n";
};
	
	
template <typename Elem, typename A = std::allocator<Link<Elem>>>
struct List_base {
	Link<Elem>* first = nullptr;
	Link<Elem>* last = nullptr;
	A alloc = A();
	int sz = 0;
	
	public:
	List_base();
	~List_base();
	
	Link<Elem>* begin() {
		while (first->prev) first = first->prev;
		return first;
	}
	
	List_base(const List_base& k) {	
	if (k.first == k.last){
		last = alloc.allocate(sizeof(Link<Elem>));
		last->prev = nullptr;
		last->succ = nullptr;
		first = last;
		return;
	}
		throw Smth_bad{};
	}		
	
	
	
};


T_Elem_A List_base<Elem,A>::List_base() : sz{0}, last{alloc.allocate(sizeof(Link<Elem>))} {
	last->val = nullptr;
	last->prev = nullptr;
	last->succ = nullptr;
	first = last;

}

T_Elem_A List_base<Elem,A>::~List_base(){
	
		size_t st = sizeof(Link<Elem>);
		if (sz == 0) 		{
			alloc.deallocate(last,st);
			return;
		}
		
		for (auto b = begin(); b != last; ){
			auto res = b->succ;
			
			alloc.destroy(b);
			alloc.deallocate(b,st);
			b = res;
			
		}
		alloc.deallocate(last,st);
		
}

template <typename Elem, typename A = std::allocator<List_base<Elem>>>
class List
{
	public:
	List_base<Elem>* lb = nullptr;
	List(){
		A alloc;
		lb = alloc.allocate(sizeof(List_base<Elem>));
		alloc.construct(lb,List_base<Elem>{});
		
	}
	
	~List() {
		A alloc;
		//cout << "Dest of List - " << lb->last->prev << '\n';
		alloc.destroy(lb);
		alloc.deallocate(lb,sizeof(List_base<Elem>));
	}
	
	class iterator;
		
	iterator insert(const Elem& e, iterator p);
	iterator erase (iterator p);
	iterator erase (iterator b, iterator e);
	iterator begin();
	iterator end();
	
	void push_back(const Elem& e) {insert(e,end());};
	void push_front(const Elem& e) {insert(e,begin());};
	void push_first(const Elem& e);
	void pop_front() {erase(begin());}
	void pop_back() {erase(--end());}
	
	int size() const {return sz;}
	Elem& front() {return first;}
	Elem& back() {return *last->val;}
};


T_Elem_A class List<Elem,A>::iterator {
	Link<Elem>* curr;
	public:
	Link<Elem>* current() {return curr;}
	void set_current(Link<Elem>* q) {curr = q;}
	
	explicit iterator(Link<Elem>* p) : curr{p} {}
	
	iterator& operator++() {curr = curr->succ; return *this;}
	iterator& operator--() {curr = curr->prev; return *this;}
	iterator& operator+(const int k) {for (int i = 0; i < k; ++i) curr=curr->succ; return *this;}
	iterator& operator-(const int k) {for (int i = 0; i < k; ++i) curr=curr->prev; return *this;}
	
	Elem& operator*() {return *curr->val;}
	
	bool operator == (const iterator& b) const 
	{return curr == b.curr;}
	
	bool operator != (const iterator& b) const
	{return curr != b.curr;}
};

T_Elem_A typename List<Elem,A>::iterator List<Elem,A>::begin() {
	
while (lb->first->prev) lb->first = lb->first->prev;	
return iterator{lb->first};
}

T_Elem_A typename List<Elem,A>::iterator List<Elem,A>::end() {
return iterator{lb->last};
}

T_Elem_A 
void List<Elem,A>::push_first(const Elem& e) {
	
	if (lb->sz != 0) return;
		
	lb->first = lb->alloc.allocate(sizeof(Link<Elem>));
	lb->alloc.construct(lb->first,Link<Elem>{e});
	lb->first = lb->first->insert(lb->first,lb->last);
	
	++lb->sz;
}

T_Elem_A typename List<Elem,A>::iterator  List<Elem,A>::insert(const Elem& e, iterator n){

if (lb->sz == 0){
		push_first(e);
		
		return iterator{lb->first};
}

Link<Elem>* a = n.current();
Link<Elem>* b = lb->alloc.allocate(sizeof(Link<Elem>));
lb->alloc.construct(b,Link<Elem>{e});
b = b->insert(b,a);

++lb->sz;

return iterator{b};	

}
	
T_Elem_A typename List<Elem,A>::iterator  List<Elem,A>::erase(iterator n) {
	
	bool fst = false;
	if (n.current() == lb->first) fst = true;
	else if (n == end()) return n;
		
	auto e = n.current();
	e = e->erase(e);
	if (fst) lb->first = e;
	--lb->sz;
	return iterator{e};
}

T_Elem_A typename List<Elem,A>::iterator  List<Elem,A>::erase(iterator b, iterator e) {
	
	for (auto p = b; p != e; ++p)
	{
		erase(p);
	}
	return e;
}
	
	
int main ()
try
{

cout << sizeof(List<int>);

char c;
cin >>c;

	
}
catch(Smth_bad& s)
{
	cout << s.s << '\n';
	char c;
	cin >> c;
}



	
	
	
	





