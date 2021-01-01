
/*
Antonuyk I.V.
04/05/2018
Belgorod

PPP C++ B.Stroustrup

ex. 26.7

*/

#include <iostream>
#include <vector>
#include <list>


using namespace std;


class Text_iterator;

using Line = vector<char>;


struct Document{
	
	list<Line>lines;
	Document() { lines.push_back(Line{}); }
	
	Text_iterator begin();
	Text_iterator end();
	
};


istream& operator >> (istream& ist, Document& d){
	
for (char ch = 0; ist.get(ch);){
	d.lines.back().push_back(ch);
	
	if (ch == '\n'){
		d.lines.push_back(Line{});
	}
	
	else if (ch == '~'){
		return ist;
	}
}
	if (d.lines.back().size())
		d.lines.push_back(Line{});
	
	
	return ist;
}


ostream& operator << (ostream& ost, const Document& d){
	
	
	for (auto f : d.lines){
		for (int i = 0 ; i < f.size(); ++i){
			cout << f[i];
		}
	
	}
	
	return ost;
}


class Text_iterator{
	list<Line>::iterator ln;
	Line::iterator pos;
	public:
	
	Text_iterator(list<Line>::iterator ll, Line::iterator pp) :
		ln{ll}, pos {pp} {}
		
	char& operator*() {return *pos;}
	
	Text_iterator& operator++();
	bool operator == (const Text_iterator& other){
		return (other.ln == ln)&&(other.pos == pos);
	}
	
	bool operator != (const Text_iterator& other){
		return !(*this == other);
	}
	
};


Text_iterator& Text_iterator::operator++(){
	++pos;
	if (pos == (*ln).end()){
		++ln;
		pos = (*ln).begin();
	}
	return *this;
}


Text_iterator Document::begin() {
	return Text_iterator{lines.begin(),(*lines.begin()).begin()};
	}
	
	
Text_iterator Document::end(){
	
	return Text_iterator{lines.end(),(*lines.end()).end()};
}

template <typename ForwardIterator, typename Fit>
bool match(ForwardIterator begin, ForwardIterator end, Fit second){
	
	for (auto f = begin; f != end; ++f, ++second){
		if ( f != second)
			return false;
	}
	
	
	return true;
}


Text_iterator find_txt(Text_iterator first, Text_iterator last, const string& s){

if (s.size() == 0) 
	return last;
char first_char  = s[0];

while (true){
	auto p = find(first,last,first_char);
	
	if (p == last || match(p,last,s.begin())) return p;
	first = ++p;
}
	
	
}
	
	

int main(){
	
	
	Document d;
	
	
	cin >> d;
	cout << d;
	
	char end;
	cin >> end;
}