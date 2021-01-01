#include <std_lib_facilities.h>

int main ()
{
	string iname = "D:\\Programms\\Ch11\\try\\binary\\data\\1.txt";
	string oname = "D:\\Programms\\Ch11\\try\\binary\\data\\2.txt";
	ifstream ist {iname,ios_base::binary};
	
	ofstream ost {oname,ios_base::binary};
	vector<int>v;
	for (int x; ist.read(as_bytes(x),sizeof(int));) v.push_back(x);
	
	for (int x : v) ost.write(as_bytes(x),sizeof(int));
	
	
	//keep_window_open();
}