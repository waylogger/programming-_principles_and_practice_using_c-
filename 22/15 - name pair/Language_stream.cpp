

#include <D:\\Programms\\22\\15 - name pair\\Language_stream.h>

std::string lang_history::string_from_stream(istream& ist, const char red = '}') try{
	std::string val = "";
	char c = 0;
	ist.get(c);
	
	for (; c != red && c != '\n'; ist.get(c)) val += c;
	
	ist.putback(c); 
	return val;
}
catch(...){return "Something bad";}


//----------------------------------------------------------------------------


lang_history::Token lang_history::Language_stream::get(){
	char c;
	curr_stream.get(c);
	
	switch(c){
		case '0': case '1': case '2': //термы
		case '3': case '4': case '5':
		case '6': case '7': case '8':
		case '9':
			{
				int val = 0;
				curr_stream.putback(c);
				curr_stream >> val;
				return Token{val};
			}
			
		case '{': case '}': 
		case '(': case ')':
		case lang_history::comma:
		case '\n': case ' ': case';':
		case tabulation:
			return Token{c};
			
		default:
			if (std::isalpha(c)) {
				curr_stream.putback(c);
				std::string name;
				name = lang_history::string_from_stream(curr_stream,lang_history::comma); // функция определена несколькими строками выше
				return lang_history::Token{name};
			}
		else
			lang_history::exception_primary(c);
		 }

	return Token{0};
}


//----------------------------------------------------------------------------


std::string lang_history::Language_stream::read_lang_name(){

		std::string name;
		lang_history::Token t = get();
			if (t.kind != '{'){
				lang_history::destroyed_expectations('{');
				return lang_history::bad_string;
			}
		
		t = get();
			if (t.kind != lang_history::word) {
					lang_history::destroyed_expectations(string("name"));
					return bad_string;
				}
			else name = t.name;
				
		t = get();
			if (t.kind != lang_history::comma) {
					lang_history::destroyed_expectations(comma);
					return bad_string;
				}
		
		
		return name;
		
			
	
}


//----------------------------------------------------------------------------


int lang_history::Language_stream::read_lang_date(){
	lang_history::Token t = get();
	int key = 0;
		if (t.kind != lang_history::number){
					lang_history::destroyed_expectations(string("number"));
					return lang_history::bad_number;
		}
		else key = t.val;
	
	
	t = get();
		if (t.kind != '}') {
					lang_history::destroyed_expectations('}');
					return lang_history::bad_number;
				}
				
	t = get();
		if (t.kind != ';') {
					lang_history::destroyed_expectations(';');
					return lang_history::bad_number;
				}
	
	
	return key;
}


//----------------------------------------------------------------------------


lang_history::name_pair lang_history::Language_stream::read_pair(){
	std::string name;
	name = read_lang_name();
											//если операция считывания была неудачной (сгенерировано искоючение), 
											//то функция возвращает значение bad_string
	if (name == lang_history::bad_string)
		return lang_history::name_pair{bad_string,bad_number};
	
	unsigned int year = 0;
	year = read_lang_date();
	
		//если операция считывания была неудачной (сгенерировано искоючение), 
											//то функция возвращает значение bad_number
	if (year == bad_number)
		return lang_history::name_pair{bad_string,bad_number};
	
	Token t = get();
		if (t.kind != lang_history::newline && t.kind != lang_history::tabulation){
					lang_history::destroyed_expectations(string("devider"));
					return name_pair{bad_string,bad_number};
		}
	
	return lang_history::name_pair{name,year};
	
	
}


//----------------------------------------------------------------------------


bool lang_history::Language_stream::checking_break(){
lang_history::Token t = get();
if (t.kind == lang_history::word)
{
	if (t.name == "quit") return true;
	else 
	{
		for (int i =0; i < t.name.size(); ++i)
		curr_stream.putback(t.name[i]);
		return false;
	}
}
curr_stream.putback(t.kind);
return false;
}


//----------------------------------------------------------------------------


void lang_history::Language_stream::console_reading(vector<name_pair>& npv){
	lang_history::name_pair np = lang_history::name_pair{"",0};
	
	
	while (true){
		
		if (checking_break())
			return;
		
		np = read_pair();
		if (np != bad_pair)
			npv.push_back(np);
		
		else
			lang_history::destroyed_expectations(string("normal pair"));
		
		
	}
}


//----------------------------------------------------------------------------


void lang_history::Language_stream::file_reading(vector<name_pair>& npv){
	lang_history::name_pair np = name_pair{"",0};
	
	
	while (!curr_stream.eof()){
		char c;
		
		curr_stream.get(c);
		
		if (curr_stream.eof())
			return;
		else
			curr_stream.putback(c);
		
		np = read_pair();
		if (np != bad_pair)
			npv.push_back(np);
		
		else
			lang_history::destroyed_expectations(string("normal pair"));
			
	}
}
//----------------------------------------------------------------------------

void lang_history::Language_stream::read(sourses s,vector<name_pair>&v)
	{
		switch(s){
			case file:
			file_reading(v);
			return;
			case console:
			console_reading(v);
			return;
		}
	}	




//----------------------------------------------------------------------------


std::ostream& lang_history::operator << (std::ostream& ofs,  const name_pair& np){
	ofs << '{' << np.first() << lang_history::comma << np.second() << '}' << ';';
	return ofs;
}










