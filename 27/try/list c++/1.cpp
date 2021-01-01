#include		<		iostream		>


using namespace std;



struct Link{
	
	Link* prev = nullptr;
	Link* succ = nullptr;
	int val = 0;
	
	Link(int n) : val{n}{}
	
	
};


struct List{
	
	Link* first;
	Link* last;
	
	List() : first{new Link{0}}, last{new Link{0}}{
		
		first 	-> succ = last;
		last 	-> prev = first;
		
	} 
	~List(){
		
		Link* curr = first;
		
		while (curr){
			Link* next = curr -> succ;
			delete curr;
			curr = next;
		}
		
		
	}
	
	void insert(Link*,Link*);
	void push_back(Link*);
	void push_front(Link*);

};

void List::insert(Link* p, Link* n){
	
	if (p == nullptr || n == nullptr || p == n)		return;
	if (n->prev){
		n->prev->succ = p;
		p->prev = n->prev;
	}
	p->succ = n;
	n->prev = p;
}

void List::push_back(Link* n){
	insert(last,n);
	last = n;
	

}

void List::push_front(Link*n){
	insert(n,first);
	first = n;
}


void f(){
	List l;
	
	for (int i =0; i < 50; i+=2)
	l.push_back(new Link{i});

	for (int i =0; i < 50; i+=6)
	l.push_front(new Link{i});
	
}



int main(){
	
	
	
	char end;
	cin >> end;
}