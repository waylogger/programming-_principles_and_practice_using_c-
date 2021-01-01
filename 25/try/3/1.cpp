#include <iostream>
#include <bitset>

using namespace std;



int main(){
	
	for (int i = 0; cin >> i;){
		cout 	<< dec << i << "==" 
				<< hex << "0x" << i << "=="
				<< bitset<8*sizeof(int)>(i) << '\n';
 	}
	
	
	char end;
	cin >> end;
	
}