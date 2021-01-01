#include <std_lib_facilities.h>


char get_sym (char ch) {
	while(cin.get(ch)) {
	if (ch!=' ')  return ch;
  
  }
}




int main()
{
char ch;
setlocale(0,"");
while (true) {
ch = get_sym (ch);
cout << ch;

}
keep_window_open();
} 