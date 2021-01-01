#include <stdlib.h>
#include <stdio.h>




int main(){
	
	
	char* h = "Hello";
	char* w = "World";
	
	
	char hw[12];
	
	int i = 0;
	for (int j = 0; j < 5; ++i, ++j){
		hw[i] = h[j];
	}
	
	hw[i] = ' ';
	++i;

	for (int j = 0; j < 5; ++j, ++i ){
		hw[i] = w[j];
	}
	
	hw[11] = 0;
	
	
	printf("%s",hw);
	
	
	
	
}