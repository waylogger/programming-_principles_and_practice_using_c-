#include <std_lib_facilities.h>

/////////////////////////////
int factorial (int f)
{
int z = 1;
while (f>0)
{
z *=f;
--f;
}
return z;
};

/////////////////////////////
int permutation (int a, int b)
{
int perm = factorial (a)/factorial(a-b);
return perm;
};
////////////////////////////
int combine (int a, int b )
{
int comb = permutation (a,b)/factorial(b);
return comb;
};
/////////////////////////////
int main ()
try
{
setlocale(0,"");
int a = 0;
int b = 0;
int c = 0;
//////////////////////////
cout << "���������� ��������� ��������: ";
cin >> a;
if ((a-int(a))!=0) error ("������������ ��������\n");
cout << "\n����� �������� � ����������: ";

cin >> b;
if ((b-int(b))!=0) error ("������������ ��������\n");
cout << "\n��������: \n1 - ���������� ������������, \n2 - ���������� ��������� \n";
cin >> c;
if (c==1) cout << "���������� ������������ - " << permutation (a, b) << "\n";
if (c==2) cout << "���������� ��������� - " << combine (a,b) << "\n";
if (c!=1&&c!=2) error ("������������ ��������\n");
keep_window_open("~");
}

catch (exception& e)
{
	cerr << e.what ();
	keep_window_open("~");
}


















































