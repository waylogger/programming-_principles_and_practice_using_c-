#include <std_lib_facilities.h>
const string in_adress = "D:\\Programms\\Ch11\\ex\\9\\data\\1.txt";
const string out_adress = "D:\\Programms\\Ch11\\ex\\9\\data\\2.txt";

ifstream read_file ()
{
	ifstream ist  {in_adress,ios_base::binary};
	if (!ist) error ("Cant open file");
	return ist;
}

ofstream write_file()
{
	ofstream ost  {out_adress};
	if (!ost) error ("Cant open file");
	return ost;
}






int main ()
{
	ifstream ist = read_file ();
	ofstream ost = write_file ();
	
	vector<int>v;
	for (int x; ist.read(as_bytes(x),sizeof(int));) v.push_back(x);
	
	for (int x : v) ost.write(as_bytes(x),sizeof(int));
}