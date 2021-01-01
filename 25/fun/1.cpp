#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


template <typename T>
char* as_bytes(T& i){
	void* addr = &i;
	
	return static_cast<char*>(addr);
}

vector<unsigned long> rf(const string& d){
	
	string s = d;
	ifstream ifs {s,ios_base::binary};
	vector<unsigned long>data;
	if (!ifs){
		cout << "Cant open file - " + s + "\n";
		return data;
	}
	
	for (unsigned long x = 0;ifs.read(as_bytes(x),sizeof(unsigned long));) {
		data.push_back(x);
	}
	
	return data;
	
	
}

void combine(vector<unsigned long>&v1, vector<unsigned long>&v2, const string& place){
	
	ofstream ofs{place,ios_base::binary};
	
	if (!ofs){
		cout << "Cant open file - " + place + "\n";
		return;
	}
	
	for (int i = 0; i < v1.size(); ++i){
		ofs.write(as_bytes(v1[i]),sizeof(unsigned long));
	}
	
	
	
	for (int i = 0; i < v2.size(); ++i){
		ofs.write(as_bytes(v2[i]),sizeof(unsigned long));
	}
	
	
	
	

	
}


int main(){
	
	auto f1 = rf("C:\\Data\\hw.exe");
	auto f2 = rf("C:\\Data\\hs.exe");
	
	combine(f1,f2,"C:\\Data\\v.exe");
	
	
	
	
	
	
}