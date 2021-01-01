#include <vector>
#include <list>
#include <iostream>


using std::vector;
using std::list;
using std::cout;





template <typename Iter1, typename Iter2>
Iter2 mycopy(Iter1 f1, Iter1 e1, Iter2 f2)
{

while(f1 != e1)
	{
	*f2++ = *f1++;
	}
return f2;
}








int main()
{
list<int>l = {0,1,2,3,4,5,6,7,8,9};

int a[10];

mycopy(l.begin(),l.end(),&a[0]);

for (int i =0; i < 10; ++i)
{
cout << a[i] << '\n';
}


}
