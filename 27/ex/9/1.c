/*
Antonyuk I.V.

22/05/18
Belgorod
PPP C++ B.Struoustrup

ex. 27.9

*/


#include <stdlib.h>
#include <stdio.h>





int comp(const char** a, const char** b){

while 		(**a == **b){
			++a;
					if (!(**a)){	
						const char** bb = b + 1;
						if (!**bb)
												return 0;
												return -1;	
					}
			++b;
					if (!(**b)){		
												return 1;
					}
}		

if 			(**a < **b)
								return -1;
else if 	(**a > **b)
								return 1;
								return 0;
	
}


char* make_string_from_istream(int maxsize){
	
	char* buf = (char*)malloc(sizeof(char)*maxsize);
	
	char c = 0;
	int inx = 0;
	while (c != '\n' && inx != maxsize){
		scanf("%1c",&c);
		if (c != '\n')
			buf[inx++] = c;
		
	}
	
	char* ret = (char*)malloc(sizeof(char)*inx);
	for (int i = 0; i < inx; ++i){
		ret[i] = buf[i];
	}
	ret[inx] = 0;
	free(buf);
	return ret;
	
	
}


int main(){
	
	char* hide[5];
	
	for (int i =0; i < 5; ++i){
		hide[i] = make_string_from_istream(50);
	}

	
	qsort(hide,5,sizeof(char*),comp);
	for (int i =0; i < 5; ++i)
	printf("%1s\n",hide[i]);
	
	
	
	char c;
	scanf("%1c",&c);
	
}