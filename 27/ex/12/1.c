/*

Antonuyk I.V.
23/05/17
Belgorod

PPP C++ B.Stroustrup

ex. 27.12

*/

#include <stdlib.h>
#include <stdio.h>

//---------------------------------------------------------

struct Note{
	char* note;
	int inx;
};

//---------------------------------------------------------


void init_note(struct Note* n){
	n->note 	= 0;
	n->inx 		= 0;
}


//---------------------------------------------------------


struct Table{
	int space;
	struct Note* data;
};


//---------------------------------------------------------

void init_table(struct Table* t){
	t->data		= 0;
	t->space	= 0;
}

//---------------------------------------------------------


void clear_table(struct Table* t){
	for (int i = 0; i < t->space; ++i){
		t->data[i].note = "empty note";
	}
}


//---------------------------------------------------------

void destroy_table(struct Table* d){
	free(d->data);
	free(d);
}

//---------------------------------------------------------

struct Table* create_table(int notes) { 
	struct Table* t = (struct Table*)malloc(sizeof(struct Table));
	init_table(t);
	t->data = (struct Note*)malloc(sizeof(struct Note)*notes);
	for (int i = 0; i < notes; ++i){
		t->data[i].note = "empty note";
		t->data[i].inx  = i;	
	}
	t->space = notes;
	return t;	
}

//---------------------------------------------------------


void insert(struct Table* tab, char* str, int pos){
			
	tab->data[pos].note = str;
	
}


//---------------------------------------------------------


int comp_str(char* a, char* b){
	
	while(*a++ == *b++){
		if 		(!(*a) && !(*b))
									return -1;
		else if (!(*a) || !(*b))
									return 0;
	}
									return 0;
}

//---------------------------------------------------------

int find(struct Table* t, char* str){
	
	for (int i = 0; i < t->space; ++i){
		
		if (comp_str(t->data[i].note,str)){
				return i;
		}
		
	}	
	
				return -1;
}


//---------------------------------------------------------

void print_table(struct Table* tab){
	
	for (int i = 0; i < tab->space; ++i){
		char* p = tab->data[i].note;
		int inx = tab->data[i].inx;
		printf("%1d.\t%1s\n",inx,p);
	}
	
}

//---------------------------------------------------------


void erase(struct Table* t, char* str){
	
	int inx = find(t,str);
	if (inx < 0)
		return;
	t->data[inx].note = "empty note";
	
	
}

int main(){
	
	struct Table* t = create_table(10);
	
	insert(t,"Vicror\0",4);
	insert(t,"Misty\0",1);
	insert(t,"Aaron\0",9);
	
	
	print_table(t);
	char c;
	scanf("%1c",&c);
	
}