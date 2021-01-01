#include <iostream>
#include <vector>

using std::vector;
using std::cout;

template<typename Iter>
Iter high(Iter first, Iter last)
{
	Iter high = first;
	
	for (Iter p = first; p != last;++p)
	{
		if (*high < *p) high = p; 
	}
	return high;
}


double* from_jake(int* count)
{
	double* a = new double[10];
	for (int i =0; i < 10; ++i)
	{
		a[i] = 0.5+i;
	}
	*count = 10;
	return a;
}


vector<double>* from_jill ()
{
	vector<double>* a = new vector<double>;
	for (int i =0; i < 10; ++i) a->push_back(5.1+i);
	
	return a;
}



int main()
{
	int count = 0;
	double* q = from_jake(&count);
	cout << *high(&q[0],&q[count]) << '\n';
	
	vector<double>* a = from_jill();
	vector<double>& va = *a;
	
	cout << *high(va.begin(),va.end()) << '\n';
	
	
	char c;
	std::cin >> c;
	delete[] q;
	delete a;
	
}





