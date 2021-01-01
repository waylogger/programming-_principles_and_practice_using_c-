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
cout << "Количество возможных символов: ";
cin >> a;
if ((a-int(a))!=0) error ("Некорректное значение\n");
cout << "\nЧисло символов в комбинации: ";

cin >> b;
if ((b-int(b))!=0) error ("Некорректное значение\n");
cout << "\nОперация: \n1 - Количество перестановок, \n2 - Количество сочетаний \n";
cin >> c;
if (c==1) cout << "Количество перестановок - " << permutation (a, b) << "\n";
if (c==2) cout << "Количество сочетаний - " << combine (a,b) << "\n";
if (c!=1&&c!=2) error ("Некорректное значение\n");
keep_window_open("~");
}

catch (exception& e)
{
	cerr << e.what ();
	keep_window_open("~");
}


















































