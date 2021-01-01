#include <std_lib_facilities.h>

int main ()
{
	vector<double>v{1,2,3,4,5,6,7,8,9,0};
	for (int i =0; i<v.size();++i) cout << v[i] << '\n';
	v.erase(remove(v.begin(),v.end(),v[5]));
	for (int i =0; i<v.size();++i) cout << v[i] << '\n';
	
	keep_window_open();
}