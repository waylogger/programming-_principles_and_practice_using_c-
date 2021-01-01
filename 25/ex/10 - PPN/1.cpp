#include <iostream>

using namespace std;

struct PPN{
	unsigned int PFN 	:22;
	int 				:3;
	unsigned int CCA 	:3;
	bool nonreachable 	:1;
	bool dyrty 			:1;
	bool valid 			:1;
	bool global			:1;
		
};


void print_ppn(PPN* pn){
	cout 	<< pn->PFN << '\t' 
			<< pn->CCA << '\n' 
			<< pn->nonreachable << '\t' 
			<< pn->dyrty << '\t' 
			<< pn->valid << '\t' 
			<< pn->global << '\n';
}

bool init_ppn(PPN* ppn,unsigned int a, unsigned int b, bool c, bool d, bool f, bool g){
	ppn->PFN 				= a;
	ppn->CCA 				= b;
	ppn->nonreachable		= c;
	ppn->dyrty 				= d;
	ppn->valid 				= f;
	ppn->global 			= g;
	
	return true;
}


bool init_ppn(PPN* ppn, unsigned long int*p){
	
	unsigned long int& nn = *p;
	
	ppn->global 		= nn&0x00000001;
	ppn->valid			= (nn>>1)&0x00000001;
	ppn->dyrty 			= (nn>>2)&0x00000001;
	ppn->nonreachable 	= (nn>>3)&0x00000001;
	ppn->CCA 			= (nn>>4)&0x00000003;
	ppn->PFN			= (nn>>10);
		
	return true;
}


void save_in_long(PPN* n, unsigned long int* p){
	unsigned long int& nn = *p;
	
	nn = n->PFN;
	nn = nn<<6;
	nn = nn|n->CCA;
	nn = nn<<1;
	nn = nn|n->nonreachable;
	nn = nn<<1;
	nn = nn|n->dyrty;
	nn = nn<<1;
	nn = nn|n->valid;
	nn = nn<<1;
	nn = nn|n->global;
	}

int main(){
	PPN pn;
	init_ppn(&pn,500,2,true,false,true,false);
	print_ppn(&pn);
	
	unsigned long int save = 0;
	save_in_long(&pn,&save);
	
	cout << '\n';
	init_ppn(&pn,200,5,true,true,true,true);
	print_ppn(&pn);
	cout << '\n';
	init_ppn(&pn,&save);
	print_ppn(&pn);
	
	
	
	char end;
	cin >> end;
	
}