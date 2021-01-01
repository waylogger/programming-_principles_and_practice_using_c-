#include <D:\\Programms\\20\\14\\Link.h>
	
struct Smth_bad {
	char s[10] = "Smth bad\n";
};
	
template <typename Elem, typename A = std::allocator<Link<Elem>>>
struct List_base {
	private:
	Link<Elem>* first = nullptr;
	Link<Elem>* last = nullptr;
	A alloc = A();
	int sz = 0;
	
	//-----------------------------------------------------------------------------------
	public:
	List_base();
	~List_base();
	List_base(const List_base& k);
	Link<Elem>* begin();
	Link<Elem>* end();
	Link<Elem>* init_first(const Elem& e);
	Link<Elem>* insert(Link<Elem>*,const Elem& e);
	Link<Elem>* erase(Link<Elem>*);
	//-----------------------------------------------------------------------------------
	void add_sz() {++sz;}
	void cut_sz() {--sz;}
	int size() {return sz;}
	
};

//-----------------------------------------------------------------------------------

T_Elem_A Link<Elem>* List_base<Elem,A>::begin() {
	return first;
}

//-----------------------------------------------------------------------------------

T_Elem_A Link<Elem>* List_base<Elem,A>::end() {
	return last;
}

//-----------------------------------------------------------------------------------

T_Elem_A List_base<Elem,A>::List_base() : sz{0}, last{alloc.allocate(sizeof(Link<Elem>))} {
	last->val = nullptr;
	last->succ = nullptr;
	first = last;
}

//-----------------------------------------------------------------------------------

T_Elem_A List_base<Elem,A>::~List_base(){
	
	size_t st = sizeof(Link<Elem>);
	if (begin() == end()) {
		alloc.deallocate(begin(),sizeof(Link<int>));
		return;
	}
	
	else 
		for (auto a = begin(); a && a != end();a = erase(a)) {
	}
		
	
		
}

//-----------------------------------------------------------------------------------

T_Elem_A List_base<Elem,A>::List_base(const List_base& k) {
	//неполноценный перемещающий конструктор
	//необходим для создания объекта через аллокатор - функция construct
	if (k.first == k.last){
		last = alloc.allocate(sizeof(Link<Elem>));
		last->succ = nullptr;
		last->val = nullptr;
		first = last;
		
		
		return;
	}
	//-----------------------------------------------------------------------------------
		throw Smth_bad{};

}


//-----------------------------------------------------------------------------------


T_Elem_A  Link<Elem>* List_base<Elem,A>::init_first(const Elem& e) {
	first = alloc.allocate(sizeof(Link<Elem>));
	alloc.construct(first,Link<Elem>{e});
	++sz;
	
	return first->insert(first,last);;
}


//-----------------------------------------------------------------------------------



T_Elem_A  Link<Elem>* List_base<Elem,A>::insert(Link<Elem>* p, const Elem& e) {
	if (first == last) {
	return init_first(e);
	}
	
	Link<Elem>* n = alloc.allocate(sizeof(Link<Elem>));
	alloc.construct(n,Link<Elem>{e});
	++sz;
	
	return p = p->insert(p,n);
}


//-----------------------------------------------------------------------------------



T_Elem_A  Link<Elem>* List_base<Elem,A>::erase(Link<Elem>* p) {
	
	if (p->succ == end()){
		alloc.deallocate(p->succ,sizeof(Link<Elem>));
		auto res = p->succ;
		alloc.destroy(p);
		alloc.deallocate(p,sizeof(Link<Elem>));
		return res;
	}
	
	else {
		auto res = p->succ->succ;
		alloc.destroy(p->succ);
		alloc.deallocate(p->succ,sizeof(Link<Elem>));
		p->succ = res;
		return p;
		
	}
	return p;
	
}










