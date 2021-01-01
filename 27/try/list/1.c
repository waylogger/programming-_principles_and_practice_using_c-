

#include 		<		stdio.h		>
#include 		<		stdio.h		>
#include 		<		assert.h	>





struct 	Link	{
	
		struct Link*	prev;
		struct Link*	succ;
	
};

struct List	{
	
		struct Link*	first;
		struct Link*	last;
	
};


void init(struct List* lst){
	
		assert( lst );
		lst -> first = lst -> last = 0;
	
}


struct List* create(){
	
		struct List* lst = ( struct List* ) malloc( sizeof( struct List* ) );
		init(lst);
		return lst;
	
}



void clear(struct List* lst){
	
		assert( lst );
		
		struct Link* curr = lst->first;
		
		while ( curr ){
			
			struct Link* next = curr->succ;
			free(curr);
			curr = next;
		}
		
		lst -> first = lst -> last = 0;
	
}

void destroy(struct List* lst){
	
		assert	( lst );
		clear	( lst );
		free	( lst );
}


void push_back( struct List* lst, struct Link* p ){
	
		assert( lst );
	{//----------------------------
		struct Link* last = lst -> last;
		if ( last ){//---------------
					last->succ = p;
					p->prev = last;
		}
	
	
		else {//-------------------
					lst->first = p;
					p->prev = 0;
		
		}
	
					lst->last = p;
					p->succ = 0;
	}
		
	
}


struct Link* erase( struct List* lst, struct Link* p ){
	
	if ( p == 0 ) 								
														return 0;
	if ( p == lst->first ){
									if ( p->succ )	{
														lst -> first = p->succ;
														p->succ->prev = 0;
														return p->succ;
													}
									
									else	{
														lst->first = lst -> last =0;
														return 0;	
											}
						}
	else if (p == lst -> last)	{
									if (p->prev){
														lst->last = p->prev;
														p->prev->succ = 0;
												}
		
									else 		{
														lst->first = lst->last = 0;
														return 0;
												}
								}
	else{
														p->succ->prev = p->prev;
														p->prev->succ = p->succ;
														return p->succ;
		}
	return p;
}


struct Name{
	
	struct Link lnk;
	char* n;
	
};


struct Name* make_name(char* n){
	struct Name* name = (struct Name*)malloc(sizeof(struct Name*));
	name->n = n;
	return name;	
}


int main(){
	
	
	int count = 0;
	struct List names;
	struct Link* curr1 = 0;

	
	init(&names);
	

	
	//push_back(&names,(struct Link*)make_name("Annemarie"));
	//push_back(&names,(struct Link*)make_name("Kris"));
	
	//erase(&names, advance(names.first,1));
	//curr = names.first;
	
	/*for(; curr != 0; curr = curr -> succ){
		count ++;
		printf("element %d: %s\n", count , ((struct Name*) curr)->n);
	}*/
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}