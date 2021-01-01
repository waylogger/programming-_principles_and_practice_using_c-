#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

using std::vector;
using std::list;
using std::cout;



int main()
{

vector<int>v = {0,1,2,3,4,5,6,7,8,9};
list<int>l = {0,1,2,3,4,5,6,7,8,9,0,27};

int n = 3;
auto res1 = std::find(v.begin(),v.end(),n);
auto b1 = v.begin();
int num = 0; 
while (b1 != v.end())
	{
	if (b1 == res1) break;
	++num;
	++b1;
	}
	
cout << 3 << " in " << num << " - position\n";

auto res2 = find(l.begin(),l.end(),27);


num = 0;
auto b2 = l.begin();
while (b2 != l.end())
	{
	if (b2 == res2) break;
	++num;
	++b2;
	}

cout << 27 << " in " << num << " - position\n";

}

