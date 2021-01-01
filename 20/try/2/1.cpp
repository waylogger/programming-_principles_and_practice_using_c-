#include <iostream>
#include <vector>


using namespace std;

template <typename Iterator>
Iterator high(Iterator first, Iterator last)
{
	if (!first || !last) throw;
	Iterator high = Iterator{};
	for (Iterator q = first; q != last;++q)
	if (*q < *high)
	{
		high = q;
		
	}
	return high;
}

int main()
{
	

char c;
cin >> c;	
	
}




