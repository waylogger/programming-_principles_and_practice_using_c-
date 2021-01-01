#include <iostream>
#include <fstream>
#include <string>

using namespace std;



int main(){
	
	string addr{"C:\\data\\write.txt"};
	
	ofstream ofs{addr};
	
	
	ofs << "I am here\n";
	
}
