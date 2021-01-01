/*
Правила:
Дефисов только 3, не меньше не больше +
Пока не встретим 3-й дефис, допускаем только цифры и дефис
Как только встремим 3-й дефис, допускаем цифры,дефис и закгавные латинские буквы
В ISBN только 13 символов, не считая дефисов +
Начинается с 978 979 +
*/


class is_isbn
{
	private:
	const vector<char>digit = {'1','2','3','4','5','6','7','8','9','0'};
	const vector<char>digit_hyphen = {'1','2','3','4','5','6','7','8','9','0','-'};
	const vector<char>allchar ={'1','2','3','4','5','6','7','8','9','0','-',
								'A','B','C','D','E','F','G','H','I','J','K','L',
								'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	public:
	bool isbn (string s);
};



bool is_isbn::isbn (string s) 
{																				//open is_isbn::isbn (string s) 
	
	string g = ""; //проверка соблюдения префикса EAN.UCC
	for (int i =0; i<3;++i) g+=s[i];
	if (g!="978"&&g!="979") error ("ISBN Format error :: Uncorrect prefix EAN.UCC, only - 978, 979");
	
	int def =0;				//число дефисов
	int qofchars = 0;		//число символов 
	for (int i =0; i<s.size();++i) 
		{ 																			//open for
		if(s[i]=='-') ++def;
		if(s[i]!='-') ++qofchars;
		} 																			//close for
		if (def>3) error ("ISBN Format error :: Too many of parts ISBN"); //слишком много частей определяется по количеству дефисов
		if (def<1) error ("ISBN Format error :: Too few of parts ISBN");  //слишком мало частей определяется по количеству дефисов
		if (qofchars>13) error ("ISBN Format error :: ISBN include only 13 char - to many of char"); //слишком много символов в ISBN
		if (qofchars<13) error ("ISBN Format error :: ISBN include only 13 char - to few of char");  //слишком мало символов в ISBN
		int hyphen = 0;
	int comp = 0;
	for (int i =0; i<s.size();++i)
	{ 																			//open for (int i =0; i<s.size();++i)
		if(s[i]=='-') ++hyphen;
		if (hyphen<3)
		{																			//open if (hyphen<3)
			for (int i2 =0; i2<digit_hyphen.size();++i2)
				{																	//open for (int i2 =0; i2<digit_hyphen.size();++i2)
					if(s[i]==digit_hyphen[i2]) ++comp; //пока не встретим 3-й дефис допускаем только цифры и дефисы
				}																	//close for (int i2 =0; i2<digit_hyphen.size();++i2)
		}																			//close if (hyphen<3)
		
		if (hyphen==3)
		{																			//open if (hyphen==3)
			for (int i2 =0; i2<allchar.size();++i2)
				{																	//open for (int i2 =0; i2<digit_hyphen.size();++i2)
					if(s[i]==allchar[i2]) ++comp;//когда встретили 3-й дефис допускаем и заглавные латинские буквы	
				}																	//close for (int i2 =0; i2<digit_hyphen.size();++i2)
		}																			//close if (hyphen==3)
	} 																			//close for(int i =0; i<s.size();++i)
	if (comp<s.size()) error ("ISBN Format error :: ISBN include only digit and hyphen for 3 part and capital letter for 4th part");

	return true;
}																					//close is_isbn::isbn (string s) 




/* блок для самостоятельной проверки заголовочного файла
int main () 
try
{
	is_isbn a;
	string s = " ";
	while (true)
	{
		try
		{
		cin>>s;
		a.isbn(s);
		}
		catch (exception& e)
		{
		cerr << e.what() << '\n';
		}
	}
	
	keep_window_open();
}

catch (exception& e)
{
	cerr << e.what() << '\n';
	keep_window_open();
}

*/















