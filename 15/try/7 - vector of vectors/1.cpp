#include <std_lib_facilities.h>



void print (const vector<vector<string>>v)
{
	for (int i =0; i < v.size();++i)
	{
		for (int j =0; j < v[i].size();++j)
		{
			cout << v[i][j] << '\n';
		}
	}
}





int main ()
{
	vector<string> s {"1-Brunduk","2-Racoon"};
	vector<string> c {"2-Cow", "3 - Bools"};
 	vector<vector<string>>a;
	a.push_back(s);
	a.push_back(c);
	//print(a);
	
	
	vector<vector<string>>qwer(5,s);

	keep_window_open();
	
}