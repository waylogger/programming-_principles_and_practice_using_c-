#include <iostream>
#include <vector>

using std::vector;
using std::cout;


template <typename Iter>
Iter low(Iter first, Iter last)
{
 Iter a = Iter();
a = *first;

while (first != last)
	{
	if (a < *first) a = *first;
	++first;
	}
return a;
}



double high(double* first, double* last)
{

}


int main()
{
vector<int>a = {1,2,3,4,5,6,7,8,0,-6534,-20000};

low( a.begin(), a.end() );
}
