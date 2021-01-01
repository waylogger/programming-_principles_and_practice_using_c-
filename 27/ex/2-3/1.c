/*
Antonyuk I.V.
09/05/2018
Belgorod

PPP C++ B.Stroustrup

ex. 27.2

*/


#include		<		stdlib.h		>
#include		<		stdio.h			>
#include		<		assert.h		>


struct List{
	
	struct Link* first;
	struct Link* last;
	
};


struct Link{
	
	struct Link* succ;
	struct Link* prev;
	
};


void init_link(struct Link* l){
	l->succ = l->prev = 0;
}


struct Link* create_link(){
	struct Link* l = (struct Link*)malloc(sizeof(struct Link));
	init_link(l);
	return l;
}


void init(struct List* lst){
	lst->first
				= lst->last
							= 0;
}

struct List* create(){
	
	struct List* lst = (struct List*)malloc(sizeof(struct List));
	init(lst);
	return lst;
	
}


void clear(struct List* lst){
	assert(lst);
	{
		struct Link* curr = lst->first;
		while (curr){
			struct Link* next = curr -> succ;
			free(curr);
			curr = next;
		}
		init(lst);
	}
}


void destroy(struct List* lst){
	assert(lst);
	clear(lst);
	free(lst);
}


void insert(struct List* lst, struct Link* p, struct Link* q){
	
	assert(lst);
	
	if (!q) return;
	
	if (!lst->last && !lst->first && !p){
		lst->first = lst->last = q;
									return;
	}
	
	else if ((!lst->last || !lst->first) && p)
									return;
	
	if (p == lst->first){
		lst->first = q;
		q->prev = 0;
	}
	
	if(p->prev){
		p->prev->succ = q;
		q->prev = p->prev;
	}
	
	p->prev = q;
	q->succ = p;
	
	
	
}

void push_back(struct List* lst, struct Link* p){
	assert(lst);
	struct Link* last 	= lst -> last;
	if (last){
		insert(lst,p,last);
	}
	
	else{
		lst->first 		= p;
	}
	lst->last 			= p;
}


void push_front(struct List* lst, struct Link* p){
	
	assert(lst);
	
	struct Link* first = lst->first;
	
	if (first){
		insert(lst,first,p);
	}
	else{
		lst->last = p;
		p->succ = 0;
	}
	lst -> first = p;
	p->prev = 0; 
	
}


struct Link* erase(struct List* lst, struct Link* p){
	assert(lst);
	
	if (p == 0)
		return 0;
	if (p == lst -> first){
		if (p->succ){
			lst -> first = p->succ;
			p->succ->prev = 0;
			return p->succ;
		}
		else{
			lst -> first = lst -> last = 0;
			return 0;
		}
	}
	
	else if ( p == lst -> last){
		if (p->prev){
			lst -> last = p->prev;
			p->prev->succ = 0;

		}
		else {
			lst -> first = lst -> last = 0;
			return 0;
		}
	}
	
	else{
		p->succ->prev = p->prev;
		p->prev->succ = p->succ;
		return p->succ;
	}
	
	return 0;
	
}

struct Link* advance(struct Link* lnk, int n){
	
	if (n == 0)
		return lnk;
	
	else if (n > 0){
		for (int i = n; i > 0; --i){
			lnk = lnk -> succ;
		}
	}
	else {
		for (int i = n; i < 0; ++i){
			lnk = lnk -> prev;
		}
	}
	
	return lnk;
	
}



struct Name{
	struct Link lnk;
	char* n;
	
};


struct Name* make_name(char* n){
	struct Name* p = (struct Name*)malloc(sizeof(struct Name));
	p->n = n;
	init_link(&p->lnk);
	return p;
}



void f(){
	
	struct List names;
	
	init(&names);
	
	
	push_front(&names,(struct Link*)make_name("Boolyn1"));
	push_front(&names,(struct Link*)make_name("Boolyn2"));
	push_front(&names,(struct Link*)make_name("Boolyn3"));
	push_front(&names,(struct Link*)make_name("Boolyn4"));
	push_front(&names,(struct Link*)make_name("Boolyn5"));
	push_front(&names,(struct Link*)make_name("Boolyn6"));
	push_front(&names,(struct Link*)make_name("Boolyn7"));
	push_front(&names,(struct Link*)make_name("Boolyn8"));
	push_front(&names,(struct Link*)make_name("Boolyn9"));
	push_front(&names,(struct Link*)make_name("Boolyn10"));
	push_front(&names,(struct Link*)make_name("Boolyn11"));
	push_front(&names,(struct Link*)make_name("Boolyn12"));
	push_front(&names,(struct Link*)make_name("Boolyn13"));
	push_front(&names,(struct Link*)make_name("Boolyn14"));
	push_front(&names,(struct Link*)make_name("Boolyn15"));
	push_front(&names,(struct Link*)make_name("Boolyn16"));
	
	struct Link* a = names.first;
	
	a = advance(a,15);
	
	a = advance(a,-5);
	struct Link* curr = a;
	int count = 0;
	
	while (curr){
			++count;
			printf("element %d: %s\n",count,((struct Name*)curr)->n);
			curr = curr->succ;
			
	}
	
	
}
