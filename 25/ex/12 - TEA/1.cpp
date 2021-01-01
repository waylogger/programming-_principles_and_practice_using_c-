#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


void encipher(
const unsigned long * const v,
unsigned long * w,
const unsigned long* const k
){
	static_assert(sizeof(long) == 4, "Uncorrect size of long int for TEA");
	
	unsigned long y = v[0];
	unsigned long z = v[1];
	unsigned long sum = 0;
	
	const unsigned long delta = 0x9e3779b9;
	
	for (unsigned long n = 32; n-- > 0;){
		y += (z << 4 ^ z >> 5) + z ^ sum +k[sum&3];
		sum+=delta;
		z += (y << 4 ^ y >> 5) + y ^ sum + k[sum >> 11 & 3];
	}
	
	w[0] = y;
	w[1] = z;
	
}


void decipher	(const unsigned long int* const v, 
				 unsigned long int* w,
				 const unsigned long int* const k
				 )
			{
	static_assert(sizeof(long) == 4, "Uncorrect size of long int for TEA");

	unsigned long  y = v[0];
	unsigned long  z = v[1];
	unsigned long  sum = 0xc6ef3720;
	
	const unsigned long delta = 0x9e3779b9;
	
	for (unsigned long n = 32; n --> 0;){
		z -= (y << 4 ^ y >> 5) + y ^ sum + k[sum >> 11 & 3];
		sum -=delta;
		y -= (z << 4 ^ z >> 5) + z ^ sum + k[sum&3];
	}
	
	w[0] = y;
	w[1] = z;
							 
}


ifstream target_file(const string& s){
	ifstream ifs {s,ios_base::binary};
	
	if (!ifs) 
		cerr << "Cant open file\n";
	
	return ifs;
}

ofstream dest_file(const string& s){
	
	ofstream ofs {s,ios_base::binary};
	
	if (!ofs)
		cerr << "Cant open file\n";
	
	return ofs;
}

void greeting(){
	
}

template <typename T>
char* as_bytes(T& i){
	void* addr = &i;
	
	return static_cast<char*>(addr);
}



int main(){
	
	string s, key, dest;
	cout << "Target of decripher - ";
	cin >> s;
	cout << "Key - ";
	cin >> key;
	cout << "Destination - ";
	cin >> dest;
	
	vector<unsigned long> data;
	vector<unsigned long> crypt_data;
	
	ifstream ifs = target_file(s);
	ofstream ofs = dest_file(dest);
	
	
	
		
	while (key.size() < 128) key += '0';
	
	const unsigned long* k = 
						reinterpret_cast<const unsigned long*>(key.data());

	for(unsigned long x; ifs.read(as_bytes(x),sizeof(unsigned long));){
		data.push_back(x);
	}
	
		unsigned long a[2];
		unsigned long b[2];
	
	for (int i =0, j = 1; j < data.size(); i+=2, j+=2){
		
		a[0] = data[i];
		a[1] = data[j];
		
		//encipher(a,b,k);
		decipher(a,b,k);
	
		for (int kk =0; kk < 2; ++kk)
			crypt_data.push_back(b[kk]);
		
	}
		
	for (int i = 0; i < crypt_data.size(); ++i){
		ofs.write(as_bytes(crypt_data[i]),sizeof(unsigned long));
	}
	
	
	
	char end;
	cin >> end;
	
	
	
	
}














