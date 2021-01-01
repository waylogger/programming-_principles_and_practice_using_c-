#include <vector>
#include <iostream>
#include <string>
#include <list>
//#include <algorithm>

using std::vector;
using std::cout;
using std::cin;
using std::string;
using std::list;
using std::istream;
using std::ostream;

using Line = vector<char> ;

const char end_of_doc = '~';

void f() {cout << "\n";}

struct Text_iterator
{
	Line::iterator pos;
	list<Line>::iterator ln;
	
	public:
	Text_iterator(list<Line>::iterator ll, Line::iterator pp) 
	: ln{ll}, pos{pp}	{}
	char& operator*() 
	{
		//cout << '*' << ' '; 
		return *pos;
	}
	Text_iterator& operator++();
	Text_iterator& operator+(const int& i);
	
	bool operator==(const Text_iterator& other) const
		{
			//cout << '=' << ' ';
			return ln == other.ln && pos == other.pos;
		}
		
	bool operator!=(const Text_iterator& other) const
	{
		return !(*this==other);
	}
};



Text_iterator& Text_iterator::operator+(const int& i)
{
	for (int k =0; k < i; ++k)
	{
		pos = pos + k;
		if (pos == (*ln).end())
		{
			++ln;
			pos = (*ln).begin();
		}
	}
	
	
	
	return *this;
}

Text_iterator& Text_iterator::operator++()
{

	++pos;
	
	if (pos == (*ln).end())
	{
		++ln;
		if ((*ln).size() != 0) 
			pos = (*ln).begin();
	}
	return *this;
}





struct Document
{
	list<Line> line;
	Document() 
	{
		line.push_back(Line{end_of_doc});
	}
	
	Text_iterator begin() 
	{
		return {line.begin(),(*line.begin()).begin()};
	}
	
	Text_iterator end()
	{		
		return  {line.end(),(*(--line.end())).end()};
	}
	
	
	
	
};

istream& operator >> (istream& ist, Document& doc)
{
	for (char ch; ist.get(ch);)
	{
		doc.line.back().push_back(ch);
		if (ch == '\n')
			doc.line.push_back(Line{end_of_doc});
		
		if (ch == end_of_doc) 
		{
			break;
		}
		
	}
		if (doc.line.back().size())
		doc.line.push_back(Line{end_of_doc});
	return ist;
}


ostream& operator << (ostream& ost, const Line& l)
{
	
	for (int i =0; i < l.size(); ++i) 
	{
		if(l[i] != end_of_doc)	ost << l[i];
	}
		
	
	return ost;
}

 
ostream& operator << (ostream& ost, const Document& doc)
{
	auto f = doc.line.begin(); 
	auto b = doc.line.end();

	while (f != b)
	{
		ost << *f;
		++f;
	}

	return ost;
} 


template <typename Iter>
bool match(Iter first, Iter last, const string& s)
{
	if (first == last) return false;
	auto f = first;
	for (int i =0; i < s.size(); ++i)
	{
		if (f == last || *f != s[i]) return false;
		++f;		
	}
	
	return true;
}

Text_iterator find_txt(Text_iterator first, Text_iterator last, const string& s)
{
	if (s.size() == 0) return last;
	char first_char = s[0];
	while (true)
	{
		auto p = std::find(first,last,first_char);
		//cout << *p << '\n';
		if (p == last || match(p,last,s)) return p;
		first = ++p;
	}
}



Text_iterator find_and_replace(Text_iterator first, Text_iterator last, const string& s, const string& ns)
{
	
	/*
	функция поиска и замены
	*/
if (s == ns) return last;

while (true) // производим замены всех вхождений
	{
	
	auto p = find_txt(first,last,s); //поиск вхождения
	if (p == last) return last;

	vector<char>&line = *p.ln;
	vector<char>newline;
	auto lb = line.begin();

	while (lb != p.pos) //переносим строку до первого вхождения
		{
			newline.push_back(*lb);
			++lb;
		}
	
	for (int i =0; i < ns.size(); ++i) //вставляем новое слово
			newline.push_back(ns[i]);

	auto lb2 = p.pos+s.size();

	while (lb2 != line.end()) //вставляем оставшуюся часть предыдущей строки
		{
			newline.push_back(*lb2);
			++lb2;
		}

	line = newline; // меняем строки
	
	}

return last;
	
}


string from_doc(Text_iterator first, int count)
{
	auto p = first;
	string s;
	
	for (int i =0; i < count;++i)
	{
		s+=(*p);
		++p;
	}
	return s;
}


void print(Document& d)
{
	
	auto p = d.begin();
	while (p != d.end())
	{
		if (*p != end_of_doc ) cout << *p;
		++p;
	}
	cout << '\n';
}


int count_of_chars(Text_iterator first, Text_iterator end)
{
	int count = 0;
	for (auto a = first; a != end; ++a)
	{
	//	cout << *a << '\n';
		if (*a != end_of_doc && *a != '\n' && *a != ' ') ++count;
	}
	
	return count;
}

int number_of_words(Text_iterator first, Text_iterator last)
{
	int count_of_words = 0;
	
	for (auto a = first; a != last; ++a)
	{
		
		while (*a != ' ' && *a != end_of_doc && *a != '\n')
			{
				++a;
				if (*a == ' ' || *a == end_of_doc || *a == '\n') ++count_of_words;
			}
		
	}
	
	
	
	return count_of_words;
}

bool find_devider(char c, vector<char>vc)
{
	return std::find(vc.begin(),vc.end(),c) == vc.end() ? false : true;
}


int number_of_words(Text_iterator first, Text_iterator last, vector<char>dev)
{
	
	int count = 0;
	for (auto a = first; a != last; ++a)
	{
		while (!find_devider(*a,dev) && *a != end_of_doc)
		{
			++a;
			if (find_devider(*a,dev)) 
			{
				++count;
			}
		}
			
				
		
	}
	
	
	return count;
}


int main()
{
	
	Document doc;
	
	
	
	
	cout << "Please insert deviders, if you want to use newline, insert 'N' " << '\n';
	vector<char>dev;
	
	
	string deviders;
	cin >> deviders;
	
	for (int i =0; i < deviders.size(); ++i)
	{
		if (deviders[i] != 'N') dev.push_back(deviders[i]);
		else if (deviders[i] == 'N') dev.push_back(deviders['\n']);
	}
	
	
	
	cin >> doc;
	
	cout << number_of_words(doc.begin(),doc.end(),dev) << '\n';
	
	
	
	
	
	char c;
	cin >> c;
}














