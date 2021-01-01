#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using std::list;
using std::vector;
using std::string;
using std::cout;
using std::cin;

void list_to_vector(vector<double>& v, list<int>&l)
{
	v.resize(l.size());
	std::copy(l.begin(),l.end(),v.begin());
}


int main()
{
	
	
	list<int>source = {1,2,3,4,123,14321,1123541,16451,13,145125,1345,14,2134,15,2345,24,124};
	
	vector<double>target;
	
	list_to_vector(target,source);
	
	std::sort(target.begin(),target.end());
	for (int i =0; i < target.size(); ++i)
	{
		cout << target[i] << '\n';
	}
	
	char c;
	cin >> c;
	
	}