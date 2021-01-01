#include <iostream>
#include <vector>
#include <list>

using std::cout;
using std::vector;
using std::list;

void comparance(vector<int>vi)
{
cout << "In vector<int> number of digits is " << vi.size() << '\n';
vector<int>vi2 = {1,2,3,4,5};
	for (int i =0 ; i < vi.size();++i)	
	{
		if(vi[i] != vi2[i])
		{
		cout << "Sequence in not allowed\n";
		return;
		}
	}
cout << "Sequence is allowed\n";

vector<int>vi3 = {1,685,3,4,5};

	for (int i =0; i < vi.size();++i)
	{
	        if (vi[i] != vi3[i])
	        {
			if (vi[i] < vi3[i])
			{
			cout << "VI3 is more \n";
			break;
			}
			else 
			{
			cout << "VI is more\n";
			break;
			}
				
		}
	}


vector<int>vi4;
vi4 = vi3;
}

void comparance(list<int>li)
{
cout << "Number of digits in list is - " << li.size() << '\n';
list<int>li2 = {1,2,3,4,5};

auto it = li.begin();
auto it2 = li2.begin();

for (int i =0; i < li.size();++i)
	{
	if (*it != *it2)
		{	
		cout << "In list sequence is not allowed\n";
		break;
		}
		
	++it;
	++it2;
	}
cout << "In list sequence is allowed\n";

list<int>li3 = {1,543,3,4,5};
it = li.begin();
auto it3 = li3.begin();

for (int i =0; i < li.size();++i)
	{
	if (*it != *it3)
		if(*it < *it3)
		{
		cout << "LI3 is more\n";
		break;
		}
		else
		{
		cout << "LI is more\n";
		break;
		}
	++it;
	++it3;
	}
list<int>li4;
li4 = li;

}

void comparance(int* pi,int count)
{
cout << "In array number of digits is - " << count << '\n';

int pi2[] = {1,2,3,4,5};
for (int i =0; i < count; ++i)
	{
	if (pi[i] != pi2[i])
		{
		cout << "In array sequence is not allowed\n";
		return;
		}
	}
cout << "In array sequence is allowed\n";

int pi3[] = {1,2,124,2,4};
for (int i = 0; i < count;++i)
	{
	if (pi3[i] != pi[i])
		if(pi3[i] > pi[i])
		{
		cout << "PI3 is more\n";
		break;
		}
		else 
		{
		cout << "PI is more\n";
		break;
		}
	}
	
int pi4[5];
for (int i =0; i < count; ++i)
	{
	pi4[i]=pi[i];
	}	
}


int main()
{
vector<int>v = {1,2,3,4,5};
list<int>l = {1,2,3,4,5};
int i[] = {1,2,3,4,5};

comparance(v);
comparance(l);
comparance(&i[0],5);
	return 0;
}
























