#include <iostream>
#include <vector>
using namespace std;


 double* get_from_jill(int* count)
{
	*count = 8;
	double* a = new double[*count];
	
	a[0] = 5321;
	a[1] = 1234;
	a[2] = 53234;
	a[3] = 1343;
	a[4] = 1234;
	a[5] = 25235;
	a[6] = 342344;
	a[7] = 1411;
	
	
	return a;
}

vector<double>* get_from_jack()
{
	vector<double>* d = new vector<double>;
	d->push_back(12);
	d->push_back(13432);
	d->push_back(123423);
	d->push_back(1233);
	d->push_back(124532);
	d->push_back(2351);
	d->push_back(23421);
	d->push_back(343);
	d->push_back(3421);
	d->push_back(23441);
	
	return d;
}

double get (vector<double>* vd, int inx)
{
	return (*vd)[inx];
}

double* high(double* first, double* last)
{
	double* high = nullptr;
	double h = -1;
	for (double* p = first; p != last; ++p)
		if (*p > h)
	{
		high = p;
		h = *p;
	}
	return high;
}

void fct()
{
	int count = 0;
	double* d = get_from_jill(&count);
	
	vector<double>* vd = get_from_jack();
	
	double h = -1;
	
	double* jill_data = nullptr;
	double* jack_data = nullptr;
	
	for (int i = 0; i < vd->size();++i)
		if (get(vd,i) > h)
	{
		h = get(vd,i);
		jack_data = new double(get(vd,i));
	}
	
	h = -1; 
	
	for (int i = 0; i < count; ++i)
	if (d[i] > h)
	{
		//cout << d[i] << '\n';
		jill_data = &d[i];
		h = d[i];
	}
	
	
	
	cout << *jack_data << '\n';	
	cout << *jill_data << '\n';	
	
	vector<double>&v = *vd;
	double* jd = high(&v[0],&v[0]+v.size());
	double* jilld = high(&d[0],&d[0]+count);
	
	
	cout << *jd << '\n';
	cout << *jilld << '\n';
	
	
	
	delete[] d;
	delete vd;
	
}

int main()
{
	fct();
	
	char c;
	cin >>c;
}