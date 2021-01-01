/*
Antonuyk I.V.
08/05/2018
Belgorod

PPP C++ B.Stroustrup

ch. 27

*/

#include 		<		stdlib.h		>




char* cat(char* id, char* addr){
	//combine name and suffix of address and sym '@'
	
	char* 	res 		= NULL;	
	int strlen_id 		= strlen( id );
	int strlen_addr		= strlen( addr ); 
	int sz 				= strlen_id + strlen_addr + 2;		// 2: 1 for @, 1 for 0
	//----------------------------------------------------
	res 				= ( char* ) malloc(sizeof(char)*sz);
	strcpy				(res,id);
	res					[strlen_id+1] 			= '@';		// @ in place of 0
	strcpy				(res+strlen_id+2,addr);				// res+strlen_id+2  = move to position after '@'
	res					[sz-1]					= 0;
	
	
	return res;
};

int main(){
	
	
	
	
	
	
}