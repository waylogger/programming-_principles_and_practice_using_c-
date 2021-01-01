/*
Antonyuk I.V.

23/05/2018
Belgorod

vtableP C++ B.Stroustrup

ex. 27.15


*/
#include <stdlib.h>
#include <stdio.h>


#define ALLOC(T,n) ((T*)malloc(sizeof(T)*n))
#define FILELD(n) (bc->draw_table[n])
#define ADR_OF_FIELD (bc->draw_table)

typedef void (*vtable)();

struct Shape{
	int a;
	vtable* draw_table;
	vtable draw;
};

void base_talk(){
	printf("Shape\n");
}


void init_Shape(struct Shape* bc, vtable func){
	bc-> a = 0;
	
	ADR_OF_FIELD = ALLOC(vtable,2);
	FILELD(0) = base_talk;	
	FILELD(1) = func;
	bc->draw = FILELD(0);
	
}


struct Circle{
	struct Shape base;
	vtable draw;
};


void dery_talk(){
	printf("Circle\n");
}

void init_dery(struct Circle* bc){
	init_Shape(&bc->base,dery_talk);
	bc->draw = bc->base.draw_table[1];
}


void some_f(struct Circle* bc){
	bc->base.draw();
	bc->draw();
};

int main(){
	
	
	struct Circle dc;
	init_dery(&dc);
	
	
	some_f(&dc);
	
	char c;
	scanf("%1c",&c);
	
}






