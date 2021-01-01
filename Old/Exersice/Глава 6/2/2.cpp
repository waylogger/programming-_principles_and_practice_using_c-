#include <std_lib_facilities.h>



char w ()
{
char p;
cin >> p;
return p;
};


int main ()
try
{
vector<char>q;
setlocale (0, "");
while (cin)
{
char m = w();
q.push_back(m);
}
for (int i =0; i<q.size (); ++i)
cout << q[i] << " ";



}

catch (exception& e)
{
cerr << e.what ();
}