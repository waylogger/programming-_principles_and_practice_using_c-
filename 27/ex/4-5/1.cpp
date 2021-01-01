/*

Antonyuk I.V.
11/05/2018
Belgorod

PPP C++ B.Stroustrup

ex. 27.4
*/


#include 		<		iostream		>
#include		<		string			>
#include		<		D:\\Programms\\27\\ex\\2-3\\1.c		>
#include		<		chrono			>
#include		<		map				>

using namespace std;




struct cppLink{
	cppLink* succ = nullptr;
	cppLink* prev = nullptr;
};

cppLink* advance(cppLink* lnk, int n){
	if (n == 0)
					return lnk;
	else if (n > 0)
		for (int i = n; i > 0; --i){
			lnk = lnk -> succ;
		}
		
	else if (n < 0)
		for (int i = n; i < 0; ++i){
			lnk = lnk -> prev;
		}
					return lnk;
}


struct cppList{
	cppLink* first;
	cppLink* last;
	cppList() : first {nullptr}, last{nullptr} {}
	~cppList(){
		cppLink* curr = first;
		
		while (curr){
			
			cppLink* next = curr -> succ;
			delete curr;
			curr = next;
		}
		first = last = nullptr;			
			
	}
	cppLink* erase(cppLink*);
	void insert(cppLink*,cppLink*);
	void push_back(cppLink*);
	void push_front(cppLink*);
	
};


void cppList::push_back(cppLink* p){
	

	cppLink* last = this->last;
	
	if (last){
		last 	-> succ = p;
		p		-> prev = last;
	}
	else{
		this->first = p;
	}
	
	this->last = p;
	
}


void cppList::push_front(cppLink* p){
	
	cppLink* first = this->first;
	
	if (first){
		first -> prev = p;
		p->succ = first;
	}
	else{
		this->last = p;
	}
	
	this->first = p;
	
}


void cppList::insert(cppLink* p, cppLink* q){
	
	if (!q)
		return;
	
	if (!this->first && !this->last && !p){
		this->first = this->last = q;
		return;
	}
	
	if ((!this->first || !this->last) && p){
		return;
	}
	
	if (p == this->first){
		first = q;
		q->prev = nullptr;
	}
	
	if (p->prev){
		p->prev->succ = q;
		q->prev = p->prev;
	}
	
	
	p->prev = q;
	q->succ = p;
	
	
}


cppLink* cppList::erase(cppLink* p){
	
	if (p == nullptr)
		return nullptr;
	if (p == this -> first){
		if (p->succ){
			this -> first = p->succ;
			p->succ->prev = nullptr;
			return p->succ;
		}
		else{
			this -> first = this -> last = nullptr;
			return nullptr;
		}
	}
	
	else if ( p == this -> last){
		if (p->prev){
			this -> last = p->prev;
			p->prev->succ = nullptr;

		}
		else {
			this -> first = this -> last = nullptr;
			return nullptr;
		}
	}
	
	else{
		p->succ->prev = p->prev;
		p->prev->succ = p->succ;
		return p->succ;
	}
	
	return nullptr;
	
}


struct cppName{
	cppLink lnk;
	char* name;
	cppName(char* s) : name {s} {}
	cppLink* cast() {return static_cast<cppLink*>(&lnk);}
};



void cppf(){
	cppList* p = new cppList{};
	for (int i = 0; i < 100; ++i){
		p->push_back((cppLink*)(new cppName{"paul1"}));
		
	}	
	delete p;
}

void cf(){
	
	List* p = create();
	for (int i = 0; i < 100; ++i){
		push_back(p,(struct Link*)make_name("paul1"));
	}
	destroy(p);		
}


void mega_battle(){


	map<int,int>res;
	
	for (int i = 0 ; i < 100; ++i)
	{
	auto t1 = chrono::system_clock::now();
	for (int i = 0 ; i < 100; ++i) cf();
	auto t2 = chrono::system_clock::now();
	for (int i = 0 ; i < 100; ++i) cppf();
	auto t3 = chrono::system_clock::now();

	int c = chrono::duration_cast<chrono::nanoseconds>(t2-t1).count();
	int cpp = chrono::duration_cast<chrono::nanoseconds>(t3-t2).count();
	
	res.insert(make_pair(c,cpp));
	}
	
	int c = 0;
	int cpp = 0;
	for (auto d : res){
		
		if (d.first > d.second) 
									++cpp;
		else if (d.first < d.second)
									++c;
		
	}
	
	cout 	<< "In 100 rounds, C show best results in " << c << " cases\n"
			<< "In 100 rounds, C++ show best results in " << cpp << " cases\n"
			<< "in rest: " << 100-(c+cpp) << " both lang show same time\n";
	
	
}


int main(){
		
		
		
	mega_battle();
	
	
	
	char end;
	cin >> end;
}