#include <iostream>
#include <fstream>
#include <string>


using namespace std;



struct File_handle
{
	ifstream ifs;
	File_handle(const string& s)
	{
		string q;
		ifs.open(s);
		ifs >> q;
		cout << q << '\n';
	} 
	
	~File_handle ()
	{
		ifs.close();
	}
	
};
 

void f()
{
	File_handle fh("D:\\Programms\\19\\ex\\12\\1.txt");
	char c;
	cin >>c;
}

int main()
{
	
f();

char c;
cin >> c;
	
}