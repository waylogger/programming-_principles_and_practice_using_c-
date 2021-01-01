#include <std_lib_facilities.h>
/*
Правила:
2. Дефисов только 3, не меньше не больше +
3. Пока не встретим 3-й дефис, допускаем только цифры и дефис
4. Как только встремим 3-й дефис, допускаем цифры,дефис и закгавные латинские буквы
5. После 1 и 2 
6. В ISBN только 13 символов, не считая дефисов
7. Начинается с 978 979 +


*/
class is_isbn
{
	private:
	const vector<char>digit = {'1','2','3','4','5','6','7','8','9','0'};
	const vector<char>digit_defice = {'1','2','3','4','5','6','7','8','9','0','-'};
	const vector<char>allchar ={'1','2','3','4','5','6','7','8','9','0','-',
										'A','B','C','D','E','F','G','H','I','J','K','L',
										'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	public:
	bool isbn (string s);
};



bool is_isbn::isbn (string s) 
{																				//open is_isbn::isbn (string s) 
	int def =0;
	
	string g = " ";
	g = s[0]+s[1]+s[2]; 
	if (g!="978"||g!="979") error ("Uncorrect prefix EAN.UCC");
		
	for (int i =0; i<s.size();++i) if(s[i]=='-') ++def;	
		if (def>3) error ("Too many of parts ISBN"); 
		if (def<1) error ("Too few of parts ISBN");
		return true;
}																				//close is_isbn::isbn (string s) 











int main () 
try
{
	is_isbn a;
	a.isbn("1a---__");
	keep_window_open();
}

catch (exception& e)
{
	cerr << e.what() << '\n';
	keep_window_open();
}

















