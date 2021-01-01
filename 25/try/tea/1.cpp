#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;


void decrypter (const unsigned long * const v, unsigned long* const w, const unsigned long * const k){
	
	static_assert(sizeof(long) == 4, "Wrong size of long for TEA");
	
	unsigned long y = v[0];
	unsigned long z = v[1];
	unsigned long sum = 0xC6EF3720;
	const unsigned long delta = 0x9E3779B9;
	
	for (unsigned long n = 32; n-->0;){
		z -= (y << 4 ^ y >> 5) + y ^ sum + k[sum>>11 & 3];
		sum -= delta;
		y -= (z << 4 ^ z >> 5) + z ^ sum + k[sum&3];
	}
	w[0] = y;
	w[1] = z;
	
	
}


int main(){
	const int nchar = 2*sizeof(long);
	const int kchar = 2*nchar;
	
	string key;
	ifstream inf("D:\\data\\encrypt.txt");
	ofstream outf("D:\\data\\dycrypt.txt");
	
	
	cout << "Insert key\n";
	cin >> key;
	
	while (key.size() < kchar) key += '0';
	
	const unsigned long* k = reinterpret_cast<const unsigned long*> (key.data());
	
	
	unsigned long inptr [2];
	char outbuf [nchar+1];
	outbuf[nchar] = 0;
	unsigned long* outptr = 
					reinterpret_cast<unsigned long*>(outbuf);
	inf.setf(ios_base::hex,ios_base::basefield);
	int i =0;
	while (inf >> inptr[0]>>inptr[1]){
		++i;
		decrypter(inptr,outptr,k);
		outf << outbuf;
	}

	
	cout << i << '\n';
	
	
	char end;
	cin >> end;
}





















