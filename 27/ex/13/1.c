/*

Antonyuk I.V.
23/05/2018
Belgorod


PPP C++ B.Stroustrup

ex. 27.13


*/


#include <stdlib.h>
#include <stdio.h>


void cpy_str(char* a, char* b){
	
	while (*a++ = *b++) {}
}


void f(){
	char el = 0;
	int sz = 0;
	int space = 8;
	char* str = (char*)malloc(sizeof(char)*8);
	while (el != ' ' && el != '\n' && el != '\t'){
		
		if (sz == space){
			char* buf = (char*)malloc(sizeof(char)*space*2);
			space *= 2;
			cpy_str(buf,str);
			free(str);
			str = buf;
		}
		
		scanf("%1c",&el);
		if (el != ' ' && el != '\n' && el != '\t'){
			str[sz] = el;
			++sz;
		}
		
	}
	str[sz] = 0;
	
	for (int i = 0; i < sz; ++i)
	printf("%1c",str[i]);

	printf("\n");
	
	
}

int main(){
	
	
	
	while (1)
		f();
	
	
	char c;
	scanf("%1c",&c);
	
	
	
}