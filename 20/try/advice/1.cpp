#include <iostream>

template <typename Iter>
void advice(Iter& p, int n)
{
	if (n == 0) return;

	else if (n > 0)
	{
		while (n > 0)
		{--n;	++p;}
	}
	else if (n < 0)
	{
		while(n < 0)
		{++n;--p;}
	}
};


int main ()
{
return 0;
}

