#include 		<		stdio.h		>






int strlen(char* c){
	int count = 0;
	while (*c++) 
					++count;
	return count;
}

int strcmp(char* a, char* b){
	int res = 0;
	
	while (*a && *b && (*a == *b)) {
		++a;
		++b;
	}
	
	return *(unsigned char*)a-*(unsigned char*)b;
}


void strcpy(char* a, char* b){
	
	while (*a++ = *b++){}
	
}






int main(){
	
	
		
		int a = strcmp("albazavr","albazavr");
		printf("%d",a);



		
	
		char end;
		scanf("%1c",&end);
}
 