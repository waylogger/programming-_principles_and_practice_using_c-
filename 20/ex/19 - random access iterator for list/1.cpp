#include <iostream>


struct out_of_range {};

template <typename T, typename A = std::allocator<T>>
class Link {

T* elem = nullptr;
Link* prev = nullptr;
Link* succ = nullptr;
public:
Link(const T& t, Link* p = nullptr, Link* s = nullptr);
Link() {}

Link(const Link& b);
Link& operator=(const Link&);

Link(Link&& b);
Link& operator=(Link&&);
~Link();

Link* previous() {return prev;}
Link* next() {return succ;}

Link* insert(Link*, Link*);
Link* add(Link*, Link*);
Link* erase(Link*);

T& operator*() {return *elem;}

void set_succ(Link<T>* a) {succ =a;}
void set_prev(Link<T>* a) {prev = a;}
void break_elem() {elem = nullptr;}
};


template <typename T, typename A>
Link<T,A>::Link(const T& t, Link* p = nullptr, Link* s = nullptr) : prev{p}, succ{s} {
	A alloc;
	elem = alloc.allocate(1);
	alloc.construct(elem,t);
}

template <typename T, typename A>
Link<T,A>::Link(const Link& b) {
A alloc;
elem = alloc.allocate(1);
alloc.construct(elem,*b.elem);
}

template <typename T, typename A>
Link<T,A>& Link<T,A>::operator=(const Link& b) {
this->~Link();
A alloc;
elem = alloc.allocate(1);
alloc.construct(elem,*b.elem);

return *this;
}


template <typename T, typename A>
Link<T,A>::Link(Link&& b) {
	elem = b.elem;
	prev = b.prev;
	succ = b.succ;
	
	b.elem = nullptr;
	b.prev = nullptr;
	b.succ = nullptr;

}

template <typename T, typename A>
Link<T,A>& Link<T,A>::operator=( Link&& b) {
this->~Link();

	elem = b.elem;
	prev = b.prev;
	succ = b.succ;
	
	b.elem = nullptr;
	b.prev = nullptr;
	b.succ = nullptr;

return *this;
}

template <typename T, typename A>
Link<T,A>::~Link()  {

	if (!elem) 	return;
	A alloc;
	alloc.destroy(elem);
	alloc.deallocate(elem,1);
	elem = nullptr;
	
}

template <typename T, typename A>
Link<T,A>* Link<T,A>::insert(Link* p, Link* n) {
	if (!p) return n;
	if (!n) return p;
	if (n->prev) {
	n->prev->succ = p;
	p->prev = n->prev;
	
	n->prev = p;
	p->succ = n;

	return p;	
	}
	
	p->succ = n;
	n->prev = p;
	
	return p;
	
}

template <typename T,typename A>
Link<T,A>* Link<T,A>::erase (Link* p) {
if (!p) return nullptr;

if (!p->prev && !p->succ) {
	p->~Link();
	p = nullptr;
	return nullptr;
}

else if (!p->prev && p->succ) {
	p->succ->prev = nullptr;
	auto save = p->succ;
	p->~Link();
	
	return save;
	}
	
else if (p->prev && !p->succ) {
	p->prev->succ = nullptr;
	auto save = p->prev;
	p->~Link();
	p = nullptr;
	return save;
}

else if (p->prev && p->succ) {
	p->prev->succ = p->succ;
	p->succ->prev = p->prev;
	auto save = p->succ;
	p->~Link();
	p = nullptr;
	return save;
}
return p;

}

template <typename T, typename A>
Link<T,A>* Link<T,A>::add(Link* p, Link* n) {
if (!p) return n;
if (!n) return p;

if (p->succ) {
p->succ->prev = n;
n->succ = p->succ;
}

p->succ = n;
n->prev = p;

return n;


}

template <typename T, typename A = std::allocator<Link<T>>> 
class List {
private:
Link<T>* first = nullptr;
Link<T>* last = nullptr;
int sz = 0;
public:
using value_type = T;
size_t size_type = sizeof(T);

List();
List(const T& val);
List(Link<T>* node);
~List();
List(const List&);
List& operator=(const List&);
List(List&&);
List& operator=(List&&);

void push_back(const T&);
void push_first(const T&);
void push_front(const T&);

class iterator;

iterator insert(iterator p, const T&);
iterator insert(const T& t, iterator p);
iterator erase(iterator p);	
iterator erase(iterator b, iterator e);
iterator begin() {return iterator{first};};
iterator end() {return iterator{last};};

T* front();
T* back();

Link<T,std::allocator<T>>* share_first() {
	auto a = first; 
	first = nullptr; 
	return a;
	}


};

template <typename T, typename A>
class List<T,A>::iterator  {
Link<T>* curr = nullptr;
public:
iterator(Link<T>* c) 
	: curr {c}  {}
iterator(const iterator& b) {curr = b.curr;};
iterator& operator=(const iterator&b) {curr->~Link(); curr = b.curr; return *this;};
iterator(iterator&&b) { curr = b.curr; b.curr = nullptr;};
iterator& operator= (iterator&&b) {
	curr->~Link(); // очищаем узел
	curr = b.curr;
	b.curr = nullptr;
	return *this;
}

bool operator == (const iterator& b) {return curr == b.curr;}
bool operator != (const iterator& b) {return !(*this == b);}
iterator operator+(const int a) {
	range(a);
	auto pos = curr; for (int i = a; i > 0; --i) pos = pos->next(); return iterator {pos};
	}
iterator operator-(const int a) {
	range(-a);
	auto pos = curr; for (int i = a; i > 0; --i) pos = pos->previous(); return iterator {pos};
	}
iterator& operator ++() {range(1);curr = curr -> next(); return *this;}
iterator& operator --() {range(-1);curr = curr -> previous(); return *this;}
T& operator*() {return *(*curr);}
Link<T,std::allocator<T>>* operator->() {return curr;}
Link<T,std::allocator<T>>* current() {return curr;}

void range(int b) {
Link<T,std::allocator<T>>* check = curr;

if (b > 0)
		for (int i =b; i > 0; --i){
			if (!check->next()) throw out_of_range{};
			check = check->next();
		}
else if (b < 0)
		for (int i =b; i < 0; ++i){
			if (!check->previous()) throw out_of_range{};
			check = check->previous();
		}
else if (b == 0)
		if (!check) throw out_of_range{};
}


};	

template <typename T, typename A>
List<T,A>::List()  {
	//по умолчанию инициализируем только последний элементы
	A alloc;
	last = alloc.allocate(1);
	alloc.construct(last,Link<T>{});
	first = last;
	
}

template <typename T, typename A>
List<T,A>::List(const T& val) {
	//создание списка с одним элементом, необходим для реализации RAII
	A alloc;
	last = alloc.allocate(1);
	alloc.construct(last,Link<T>{});
	
	first = alloc.allocate(1);
	alloc.construct(first,Link<T>{val});
	first = first->insert(first,last);
	++sz;

}


template <typename T, typename A>
List<T,A>::List(Link<T>* node) {
	if (!node) return;
	A alloc;
	//инициализация списка узлом, необходимо для корректного удаления узла, созданного в другом месте
	last = alloc.allocate(1);
	alloc.construct(last,Link<T>{});
	
	first = node;
	first = first->insert(first,last);
	++sz;
	
	
}


template <typename T, typename A>
List<T,A>::~List()  {
	A alloc;
	if (first == nullptr && last == nullptr) return;
	if (first == last) { 
	//если список не был использован, но его первый и последний элемент должны сопадать
	//поэтому деструктор заканчивается на уничтожении последнего узла списка	
				alloc.destroy(last);
				alloc.deallocate(last,1);
				last = nullptr;
				first = nullptr;
		return;
	}
	if (first) 
			for (auto pos = first->next(); pos != last; pos = pos->next()) {
				//первый узел будет равным нулю только когда мы сделаем это намеренно
				//например при реализации идиомы RAII
				alloc.destroy(pos->previous());
				alloc.deallocate(pos->previous(),1);
						
			}
	
			
	if (first && last->previous()) { 
				//верхний цикл не позволяет производить удаление последних двух элементов
		
				alloc.destroy(last->previous());
				alloc.deallocate(last->previous(),1);
			}		
	//последний элемент остается во всех случаях
	if (!last) return;
	alloc.destroy(last);
	alloc.deallocate(last,1);
	
}

template <typename T, typename A>
List<T,A>::List(const List& b) {
A alloc;
sz = b.sz;

last = alloc.allocate(1);
alloc.construct(last,Link<T>{});

first = alloc.allocate(1);
alloc.construct(first,*b.first);

auto fpl = first;
if (b.first->next())
for (auto pos = b.first->next(); pos != b.last; pos = pos->next()) {
		auto nom = alloc.allocate(1);
		alloc.construct(nom,*pos);
		fpl = fpl->add(fpl,nom); //копирование методом вставки
		nom = nullptr;
	}
last->insert(fpl,last); //замыкаем цепочку



}

template <typename T, typename A>
List<T,A>& List<T,A>::operator=(const List& b) {
	
	this->~List();
		
	
	A alloc;
	sz = b.sz;

	last = alloc.allocate(1);
	alloc.construct(last,Link<T>{});

	first = alloc.allocate(1);
	alloc.construct(first,Link<T>{*b.first});
	
	auto fpl = first;
	if (b.first->next())
	for (auto pos = b.first->next(); pos != b.last; pos = pos->next()) {
		
		auto nom = alloc.allocate(1);
		alloc.construct(nom,*pos);
		fpl = fpl->add(fpl,nom); //копирование методом вставки
		nom = nullptr;
	}

last->insert(fpl,last); //замыкаем цепочку
	
	
	return *this;
}

template <typename T, typename A>
List<T,A>::List(List&& b) {
first = b.first;
last = b.last;
sz = b.sz;


b.first = nullptr;
b.last = nullptr;

}

template <typename T, typename A>
List<T,A>& List<T,A>::operator=(List&& b) {
this->~List();

first = b.first;
last = b.last;
sz = b.sz;


b.first = nullptr;
b.last = nullptr;

return *this;


}

template <typename T, typename A>
void List<T,A>::push_first(const T& val) {
	List<T>b{val}; //RAII
	first = nullptr; //освобождаем first от last
	first = first->insert(b.share_first(),first); //инициализируем first
	first = first->insert(first,last); //связываем first и last

	++sz;
}

template <typename T, typename A>
void List<T,A>::push_back(const T& val) {

if (first == last) {
	push_first(val);
	return;
}

A alloc;
List<T>b{val}; //RAII
last->insert(b.share_first(),last);
++sz;

}

template <typename T, typename A>
void List<T,A>::push_front(const T& val) {

if (first == last) {
	push_first(val);
	return;
}

A alloc;
List<T>b{val}; //RAII
first = first->insert(b.share_first(),first);
++sz;

}

template <typename T, typename A>
typename List<T,A>::iterator List<T,A>::insert(typename List<T,A>::iterator p, const T& val) {
	
	if (begin() == end()) {
		push_first(val);
		return iterator{begin()};
	} 
	A alloc;
	List<T,A>b{val}; //RAII
	p->add(p.current(),b.share_first());
	
	++sz;
	
	return p;
}

template <typename T, typename A>
typename List<T,A>::iterator List<T,A>::insert(const T& val, typename List<T,A>::iterator p) {
	
	if (begin() == end()) {
		push_first(val);
		return p;
	}
	A alloc;
	List<T,A>b{val}; //RAII
	
	p->insert(b.share_first(), p.current());
	if (p.current() == first)
	if (first && first->previous())
		first = first->previous();

	++sz;
	
	return p;
}


template <typename T, typename A> 
typename List<T,A>::iterator List<T,A>::erase(typename List<T,A>::iterator p) {
	
	if (p == end()) return p;
	else if (p.current() == first) {
		auto save = p.current();
		first = p.current()->erase(p.current());
		List<T,A>{save};
		--sz;
	}
	else {
		auto save = p.current();
		p.current()->erase(p.current());
		List<T,A>{save};
		--sz;
	}
	return p;
}


template <typename T, typename A> 
typename List<T,A>::iterator List<T,A>::erase(typename List<T,A>::iterator b, typename List<T,A>::iterator e) {
	if (e == b) return b;
	
	for (auto pos = b+1; pos != e; ++pos) {
		erase(pos-1);
		--sz;
	}
	erase(e-1);
	--sz;
	return e;
}


