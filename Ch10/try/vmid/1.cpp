#include <std_lib_facilities.h>

double central_vec (const vector<double>& p)
{
	int i_f =0;
	int i_b=p.size()-1;
	int midle =0;
	if (p.size()%2!=0)
	{
		while (i_f<p.size() && i_b>=0)
		{
			++i_f;
			--i_b;
			cout << i_f << ' ' << i_b << '\n';
			if (i_f==i_b) {midle = i_f; break;}
		}
	return midle+1;
	}
	if (p.size()%2==0)
	{
		while (i_f<p.size() && i_b>=0)
		{
			cout << i_f << ' ' << i_b << '\n';
			++i_f;
			--i_b;
			if ((i_f+1)==i_b) {midle = i_f; break;}
		}
	return p[(midle)]+p[(midle+1)];
	}
	return 1;
	
}

int main ()
{
	vector<double>d = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	double med = central_vec(d);
	cout << "Midle - " << med <<  '\n';
	keep_window_open();
}