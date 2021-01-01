#include <vector>
#include <list>
#include <iostream>

using std::vector;
using std::list;
using std::cout;


void to_up(int* p, int count, int val)
{
for (int i =0; i < count; ++i)
	{
	p[i]+=val;
	}
}

void print_array(int*p,int count)
{
for (int i =0; i < count; ++i)
	{
	cout << p[i] << '\n';
	}
}







int main ()
{
int a[] = {0,1,2,3,4,5,6,7,8,9};
vector<int> v = {0,1,2,3,4,5,6,7,8,9};
list<int>l = {0,1,2,3,4,5,6,7,8,9};


int a2[10] = {a};
vector<int>v2 = v;
list<int>l2 = l;
print_array(&a[0],10);
to_up(&a[0],10,2);
print_array(&a[0],10);
to_up(&a[0],10,3);
print_array(&a[0],10);
to_up(&a[0],10,5);
print_array(&a[0],10);
	
	

}

