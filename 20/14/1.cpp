#include <D:\\Programms\\20\\14\\List_base.h>

template <typename Elem, typename A = std::allocator<List_base<Elem>>>
class List
{
	public:
	List_base<Elem>* lb = nullptr;
	List();
	~List();
	//-----------------------------------------------
	class iterator;
		
	iterator insert(iterator p, const Elem& e);
	iterator insert(const Elem& e);
	iterator erase (iterator p);
	iterator erase (iterator b, iterator e);
	iterator begin();
	iterator end();
	//-----------------------------------------------
	void push_back(const Elem& e);
	void pop_front();
	
	//-----------------------------------------------
	int size() const {return lb->size();}
	Elem& front() {return first;}
	Elem& back() {return *last->val;}
};

//-----------------------------------------------

T_Elem_A List<Elem,A>::List() {
		A alloc;
		lb = alloc.allocate(sizeof(List_base<Elem>));
		alloc.construct(lb,List_base<Elem>{});
}

//-----------------------------------------------

T_Elem_A List<Elem,A>::~List() {
		A alloc;
		alloc.destroy(lb);
		alloc.deallocate(lb,sizeof(List_base<Elem>));

}

//-----------------------------------------------


T_Elem_A class List<Elem,A>::iterator {
	Link<Elem>* curr;
	public:
	Link<Elem>* current() {return curr;}
	void set_current(Link<Elem>* q) {curr = q;}
	
	explicit iterator(Link<Elem>* p) : curr{p} {}
	
	iterator& operator++() {curr = curr->succ; return *this;}
	iterator& operator+(const int k) {for (int i = 0; i < k; ++i) curr=curr->succ; return *this;}
	
	Elem& operator*() {return *curr->val;}
	
	bool operator == (const iterator& b) const 
	{return curr == b.curr;}
	
	bool operator != (const iterator& b) const
	{return curr != b.curr;}
};

//-----------------------------------------------

T_Elem_A typename List<Elem,A>::iterator List<Elem,A>::begin() {
return iterator{lb->begin()};
}

//-----------------------------------------------

T_Elem_A typename List<Elem,A>::iterator List<Elem,A>::end() {
return iterator{lb->end()};
}

//-----------------------------------------------

T_Elem_A typename List<Elem,A>::iterator  List<Elem,A>::insert(const Elem& e){
if (begin() == end()) return iterator{lb->init_first(e)};
else
	return end();

}

//-----------------------------------------------

T_Elem_A typename List<Elem,A>::iterator  List<Elem,A>::insert(iterator n, const Elem& e){
if (begin() == end()) return insert(e);
else
	return iterator{lb->insert(n.current(),e)};
}


//-----------------------------------------------


T_Elem_A void List<Elem,A>::push_back(const Elem& e) { 
	insert(begin()+(size()-1),e);
}

//-----------------------------------------------

T_Elem_A typename List<Elem,A>::iterator  List<Elem,A>::erase(iterator n) {
	
	return iterator{e};
}

//-----------------------------------------------


int main ()
try
{


List<int>a;

for (int i = 0; i < 100; ++i) a.push_back(i);

for (auto b : a) cout << b << '\n';

char c;
cin >> c;
	
}
catch(Smth_bad& s)
{
	cout << s.s << '\n';
	char c;
	cin >> c;
}



	/*
	




	


T_Elem_A typename List<Elem,A>::iterator  List<Elem,A>::erase(iterator b, iterator e) {
	
	for (auto p = b; p != e; ++p)
	{
		erase(p);
	}
	return e;
}
	
	
	
	*/
	
	
	





