
#include <std_lib_facilities.h>

int main ()
try
{
setlocale (0, "");


}

catch (exception& e)
{
cerr << e.what ();
}