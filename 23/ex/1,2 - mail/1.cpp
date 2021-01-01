#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <windows.h>

using namespace std;


using Line_iter = vector<string>::const_iterator;

class Message
{
	Line_iter first;
	Line_iter last;
	
public:
	
	Message(Line_iter p1, Line_iter p2) : first{p1}, last{p2} {}
	Line_iter begin() 	const	{return first;}
	Line_iter end()		const	{return last;}
	
	
};
struct File_except{
	string s;
	File_except(const string& ss) : s{ss} {}
};

void file_handle_error(const string &s) try {
	throw File_except{s};
}
catch(File_except& e){
	cerr << e.s << '\n'; 
	char c;
	std::cin >> c;
	exit(1);
};



typedef vector<Message>::const_iterator Mess_iter;

struct Mail_file{
	string name;
	vector<string>lines;
	vector<Message>m;
	Mail_file(const string& n);
	Mess_iter begin()	const {return m.begin();}
	Mess_iter end() 	const {return m.end();}
	void correction();
	
};




Mail_file::Mail_file(const string& n){
	//Идеология обработки ошибок форматирования такова, что в приоритете находится не формальное соответствие шаблону,
	//а сохранение информации. Поэтому ошибки формата обрабатываются путём восполнения недостатков структуры
	//при этом о каждом внесенном изменении пользователь обязан быть поставлен в известность
	//Письмо состоит из 4х частей: адресат, тема, текст и символ завершения письма
	//Если какой-либо из элементов пропущен, то соответствующий заголовок генерируется программой 
	//Например, если встречается последовательность: отправитель, отправитель, заголок, текст, офончание ввода
	//то это означает, что после первого имени отправителя пропушены остальные элементы, так же со всем остальным.
	// Таким образом после работы программы запись " отправитель, отправитель, заголок, текст, офончание ввода"
	// будет преобразована в "отправитель, заголок(пусто), текст(пусто), офончание ввода" "отправитель, заголок, текст, офончание ввода"
	// то есть цель обработки ошибок - это их восполнение при сохранении информации
	// при этом никакая из часть текста письма не может интерпритироваться как служебный заголовок, они должны быть указаны
	// только явно
	// если в заголовках были допущены грамматические ошибки, то такой заголовок не сможет распознаться как префикс 
	// и будет интерпритироваться как часть текста
	
	ifstream in{n};
	ofstream of{"D:\\data\\corr.txt"};

	if (!in)
		file_handle_error("Не могу найти файл - " + n);
	
	for (string s; getline(in,s); )
		lines.push_back(s);
	
	
	correction();
	
	for (auto a : lines) of << a << '\n';
	
	auto first = lines.begin();
	for (auto p = lines.begin(); p != lines.end(); ++p){
		if (*p == "----"){
			m.push_back(Message(first,p));
			first = p + 1;
		}
	}
}


int is_prefix(const string& s, const string& p){
	int n = p.size();
	
	if (string(s,0,n) == p) return n; 
	
	
	return 0;
}


void Mail_file::correction(){
	string addr = "From: sender not defined";
	string subject = "Subject: subject not defined";
	string both_title = addr + '\n' + subject;
	string end_of_letter = "----";
	
	bool expect_new_letter = true; // флаг ожидания нового письма
	
	if (lines.size() ==0 || (*(lines.end()-1) != end_of_letter)) 
				lines.push_back(end_of_letter); 
			
		int index = 0;
		for (auto b = lines.begin(); b != lines.end(); ++b, ++index){
			if (expect_new_letter){
				if (!is_prefix(*b,"From: ")){
					lines.insert(b,addr);
					b = lines.begin()+index;
					}
				++b;	++index;
				if (!is_prefix(*b,"Subject: ")){
					lines.insert(b,subject);
					b = lines.begin()+index;
				}
				++b;	++index;
				if (is_prefix(*b,"Subject: ") || is_prefix(*b,"From: ")){
					lines.insert(b,end_of_letter);
					b = lines.begin()+index;
				}
			expect_new_letter = false;
			}			
		
		while (*b == end_of_letter)
			if (b != lines.end()-1 && *(b+1) == end_of_letter)
				lines.erase(b+1);
			else {
				expect_new_letter = true;
				break;
			}	
		}	
}


bool find_from_addr(const Message* m, string& s) {
 for (const auto& x : *m){
	 if (int n = is_prefix(x, "From: ")){
		  s = string(x,n);
		  return true;
		}
	 
	}
	return false;
}

string find_subject(const Message* m) {
	
	for (const auto& x : *m){
		if (int n = is_prefix(x, "Subject: "))
			return string(x,n);
	}
	return "";
};


int main(){
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	Mail_file mfile = {"D:\\data\\mail.txt"};
	
	
	multimap <string, const Message*> subject;
	
	for (const auto& m : mfile){
		string s = find_subject(&m);
		if (s != "")
			subject.insert(make_pair(s,&m));
	}
	
	string sub;
	cin >> sub;
	
	
	auto pp = subject.equal_range(sub);
	
	for (auto p = pp.first; p != pp.second; ++p){
		for (auto dd = p->second->begin(); dd != p->second->end(); ++dd)
			cout << *dd << '\n';
	}
	
	
	

	
	char c;
	cin >> c;

}











