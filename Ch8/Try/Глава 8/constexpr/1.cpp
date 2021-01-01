#include <std_lib_facilities.h>


constexpr int b (int x) 	{

return x;
				}
				
int main () {
const int q = 126;
constexpr int z = b(q);
cout << z << '\n';
keep_window_open ();
}
