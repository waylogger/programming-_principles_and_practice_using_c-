#include<std_lib_facilities.h>

class Invalid  // для обработки исключений
{ };

struct Rules_for_names //класс допустимых символов в именах
{
	const vector<char>first_letter {'A','B','C','D','E','F','G','H','I','J','K','L',
								'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	const vector<char>rest_letter {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o',
							'p','q','r','s','t','u','v','w','x','y','z'};
};


class Name //герой дня
{
	private:
	string firstname  = "";
	string surname = "";
	bool is_letter(string s); //проверяет буквы ли вообще в имени
	bool legal_name_firstletter (string s); //проверяет большая ли первая буква
	bool legal_name_rest_letter (string s); //проверяет маленькие ли остальные буква
	void is_true (string f, string s);
	public:
	Name(string f, string s) : firstname(f), surname (s) { is_true(f,s); }; 
	Name() {};
	
	
	//немодифицирующие функции
	string ffname () const {return firstname;}
	string fsname () const {return surname;}
	
	
};
	

	ostream& operator << (ostream& os, const Name& n) //перегружаем оператор ввода
	{
		return os << n.ffname() << ' ' <<  n.fsname();
	}

	void Name::is_true(string f, string s)
	try
	 {
		const bool is_letter_firstname = is_letter(f); //буквы ли в имени
		const bool is_letter_surname   = is_letter(s); //буквы ли в имени
		
		const bool firstname_first = legal_name_firstletter (f); //большая ли буква в имени
		const bool firstname_rest = legal_name_rest_letter (f); //маленькие ли буквы в имени после первой буквы
		
		const bool surname_first = legal_name_firstletter (s); // та же история
		const bool surname_rest = legal_name_rest_letter (s);
		
		if (!is_letter_firstname) cout << "Need to use only lowercase or capital latin letter\n";
		if (!is_letter_surname) cout << "Need to use only lowercase or capital latin letter\n";
		
		if (!is_letter_firstname|| !is_letter_surname) throw Invalid{}; //если использован хоть один недопустимый символ - ошибка
		
		if (!firstname_first) cout << "First letter of firstname must be capital\n";
		if (!firstname_rest) cout << "All letter of firstname must be lowercase, except first\n";
		if (!surname_first)  cout << "First letter of surname must be capital\n";
		if (!surname_rest) cout << "All letter of surname must be lowercase, except first\n";
				
		if (!firstname_first
		|| !firstname_rest 
		|| !surname_first 
		|| !surname_rest
		) throw Invalid{};//Эта быть может неудачная конструкция призвана выводить перечень 
											//всех встреченных в программе ошибок перед её закрытием
						
	}
	catch (Invalid) // перехват исключений
	{
		cerr << "\nThe end of the error sheet\n";
		keep_window_open ();
	}
	
	catch (...)
	{
		cerr << "Ups...." << '\n';
		keep_window_open();
	}
	
	bool Name::is_letter(string s) //буква ли это вообще
	{
		int find = 0;
		Rules_for_names a;
		for (int i =0; i<s.size();++i) //прогоняем символ по двум векторам
		{
			for (int i2 =0; i2<a.first_letter.size();++i2)
				if (s[i]==a.first_letter[i2]||s[i]==a.rest_letter[i2]) ++find;
		}
		if (find==s.size()) return true;
		 return false;
	}
	
	bool Name::legal_name_firstletter (string s) //большая ли первая буква?
	{
		Rules_for_names a;
		int find = 0;
		for (int i =0; i<a.first_letter.size();++i) if (s[0]==a.first_letter[i]) ++find;
		if (find>0) return true;
		else return false;
	}
	
	bool Name::legal_name_rest_letter (string s) //маленькие ли остальные буквы?
	{
		Rules_for_names a;
		int find = 0;
		for (int i =0; i<s.size();++i) 
			{
				for (int i2 = 0; i2<a.rest_letter.size();++i2)
				{
					if (s[1+i]==a.rest_letter[i2]) ++find;
				}
						
			}
		if (find==s.size()-1) return true;
		return false;
	}
	
	 для самостоятельной проверки
	int main () 
	{
		Name a = {"Wilson", "John"};
		keep_window_open();
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	