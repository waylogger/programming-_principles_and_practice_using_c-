#include <iostream>


using namespace std;

template <typename Elem>
struct Link
{
	Link* prev;
	Link* succ;
	Elem val;
	
};


template <typename Elem>
class list
{
	class iterator;
	
	public:
	iterator begin();
	iterator end();
	
	iterator insert(iterator);
	iterator erase(iterator);
	
	void push_back(const Elem);
	void push_front(const Elem);
	
	void pop_front();
	void pop_back();
	
	Elem& front();
	Elem& back();
	
	};

	
template <typename Elem>
class list<Elem>::iterator
{
	Link<Elem>*curr;
	
	public:
	
	iterator(Link* c) : curr{c} {}
	
	Elem operator*() {return curr->val;}
	
	iterator& operator++() {curr=curr->succ; return *this;}
	iterator& operator--() {curr=curr->prev; return *this;}
	
	bool operator==(const iterator& b) {return curr == b.curr;}
	bool operator!=(const iterator& b) {return curr != b.curr;}
	
};























int main()
{
	
}