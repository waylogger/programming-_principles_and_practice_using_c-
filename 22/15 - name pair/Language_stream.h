#ifndef LANGUAGE_STREAM_H
#define LANGUAGE_STREAM_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <FLTK\\Point.h>
#include <D:\\Programms\\22\\15 - name pair\\history_guard.h>

//----------------------------------------------------------------------------

namespace lang_history {
	
using std::vector;
using std::cin;
using std::cout;
using std::ifstream;
using std::istream;
using std::ofstream;
using std::string;
using std::isalpha;
//-----------------------------------------------------------------------

const char number = '8';
const char break_string = '}';
const char word = 'w';
const char comma = ',';
const char newline = '\n';
const char tabulation = '\t';
const unsigned int bad_number = -1;
const int charaster = 8;
const string  bad_string = "Bad_str";


//-----------------------------------------------------------------------

class name_pair{
	std::string fst;
	unsigned int snd = 0;
	public:
	name_pair(const std::string& s, const unsigned int i) : fst{s}, snd{i} {}
	std::string first() const {return fst;}
	unsigned int second() const {return snd;}
	
	bool operator == (const name_pair& b) {return (fst == b.fst)&&(snd == b.snd);}
	bool operator != (const name_pair& b) {return !(*this == b);}
};


class name_anc : public name_pair{
	std::vector<std::string> ancestors;
	public:
	using name_pair::name_pair;
	void save_anc(const std::string& s) {ancestors.push_back(s);}
	
};

const name_pair bad_pair = {bad_string,bad_number};

//-----------------------------------------------------------------------


std::ostream& operator << (std::ostream& ofs,  const name_pair& np);


//----------------------------------------------------------------------------
	
	
string string_from_stream(istream& ist, const char red);

//----------------------------------------------------------------------------

struct Token{
	char kind;
	int val;
	string name;
	
	Token(const int v) : val{v}, kind{number} {}
	Token(const char k) : kind{k}, val{charaster} {}
	Token(string s) : name {s}, kind{word}, val{word} {}
};


//----------------------------------------------------------------------------


class Language_stream{
	//задача класса - считывать данные из любого входного потока и помещать их в контейнер
	//выражение имеет следующую форму '{' <lang name> ',' <year> '} '';'' ('\t' || '\n')  , { , } ; - is a term
	
	protected:
	
	istream& curr_stream;
	string read_lang_name();
	int read_lang_date();
	bool checking_break();
	Token get();
	virtual name_pair read_pair();
	virtual void console_reading(vector<name_pair>&);
	virtual void file_reading(vector<name_pair>&);
	public:
	enum sourses{file,console};
	void read(sourses s,vector<name_pair>&v);
	Language_stream(istream& ist) : curr_stream{ist} {} 
			
};


class Languages_anc_stream : public Language_stream{
	public:
	using Language_stream::Language_stream;
	name_pair read_pair()						override;
	void console_reading(vector<name_pair>&) 	override;
	void file_reading(vector<name_pair>&) 		override;
	std::vector<std::string> read_lang_anc();
	
};




} // end of namespace


#endif