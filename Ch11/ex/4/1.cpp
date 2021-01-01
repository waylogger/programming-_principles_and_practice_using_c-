#include <std_lib_facilities.h>


int get_int ()
{
	setlocale(0,"");
	char ch;
	cin >> ch;
	switch(ch)
	{
		case '1': case '2':
		case '3': case '4':
		case '5': case '6':
		case '7': case '8':
		case '9':
		{
			cin.putback(ch);
			int i =0;
			cin >> dec >> i;
									cout 	<< i 
											<< " (десятичное) превращается в десятичное " 
											<< dec << i << '\n';  
									return i; //dec
		}
		case '0':
		{
			cin >> ch;
			switch(ch)
			{
				case 'x':
				{
				int i =0;
				cin >> hex >> i;
									cout 	<< "0x" << hex << i 
											<< " (шестрандцатиричное) превращается в десятичное " 
											<< dec << i << '\n';  
									return i; //hex
				}
				case '1': case '2':
				case '3': case '4':
				case '5': case '6':
				case '7': case '8':
				case '9':
				{
				cin.putback(ch);
				int i =0;
				cin >> oct >> i;
									cout 	<< "0" << oct << i 
											<< " (восьмеричное) превращается в десятичное " 
											<< dec << i << '\n';  
									return i; //oct
				}
				default:
				error ("Bad digit");
			}
		}
	default:
	error ("Bad digit");
	}
	return 0;
}



int main ()
{
	while (true) get_int();
	keep_window_open();
}
