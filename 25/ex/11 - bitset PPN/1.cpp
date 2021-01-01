#include <iostream>
#include <bitset>





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


template <int N>
bool init_ppn(PPN* ppn, const bitset<N>n){
	
	unsigned long int nn = n.to_ulong();;
	
	ppn->global 		= nn&0x00000001;
	ppn->valid			= (nn>>1)&0x00000001;
	ppn->dyrty 			= (nn>>2)&0x00000001;
	ppn->nonreachable 	= (nn>>3)&0x00000001;
	ppn->CCA 			= (nn>>4)&0x00000003;
	ppn->PFN			= (nn>>10);
		
	return true;
			
	return true;
}

template <int N>
void save_in_bitset(PPN* n, bitset<N>& nn){
		
	nn = n->PFN;
	nn = nn << 6;
	nn = nn|bitset<N>{n->CCA};
	nn = nn << 1;
	nn = nn|bitset<N>{n->nonreachable};
	nn = nn << 1;
	nn = nn|bitset<N>{n->dyrty};
	nn = nn << 1;
	nn = nn|bitset<N>{n->valid};
	nn = nn << 1;
	nn = nn|bitset<N>{n->global};

	}

	
int main(){
	PPN pn;
	init_ppn(&pn,500,2,true,false,true,false);
	print_ppn(&pn);
	
	bitset<32> save;
	save_in_bitset<32>(&pn,save);
	
	init_ppn(&pn,200,5,true,true,true,true);
	print_ppn(&pn);
	
	init_ppn(&pn,save);
	cout << '\n';
	print_ppn(&pn);
	
	
	
	char end;
	cin >> end;
	
}