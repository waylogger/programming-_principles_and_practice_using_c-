

#include <iostream>
#include <string>

using namespace std;


const char min = '0';
const char max = '9';

int num_of_char (const char c)
{
	switch(c)
	{	case min: return -1;
		case max: return 999999;
		case 'A': case 'a': return 0;
		case 'B': case 'b': return 1;
		case 'C': case 'c': return 2;
		case 'D': case 'd': return 3;
		case 'E': case 'e': return 4;
		case 'F': case 'f': return 5;
		case 'G': case 'g': return 6;
		case 'H': case 'h': return 7;
		case 'I': case 'i': return 8;
		case 'J': case 'j': return 9;
		case 'K': case 'k': return 10;
		case 'L': case 'l': return 11;
		case 'M': case 'm': return 12;
		case 'N': case 'n': return 13;
		case 'O': case 'o': return 14;
		case 'P': case 'p': return 15;
		case 'Q': case 'q': return 16;
		case 'R': case 'r': return 17;
		case 'S': case 's': return 18;
		case 'T': case 't': return 19;
		case 'U': case 'u': return 20;
		case 'V': case 'v': return 21;
		case 'W': case 'w': return 22;
		case 'X': case 'x': return 23;
		case 'Y': case 'y': return 24;
		case 'Z': case 'z': return 25;
	}
	return 0;
}



bool lexigraph_last (const string& s1, const string& s2)
{
	for (int i =0, j =0; i < s1.size() || j < s2.size(); ++i, ++j)
	{
		if (s1[i]!=s2[j])
		{
			int f {num_of_char(s1[i])};
			int s {num_of_char(s2[j])};
			if (f>s) 		return true;
			else if (f<s) 	return false;
			else if (f==s) 	return false;
		}
	}
	return false; 
}


class Link
{
	private:
	Link* succ;
	Link* prev;
	string name;
	public:
	Link(string n, Link* p = nullptr, Link* s = nullptr) : name{n}, prev{p}, succ {s} {}
	Link* previous() {return prev;}
	Link* next() {return succ;}
	Link* add (Link*,Link*);
	string show_name () {return name;}
	void show();
	Link* find(Link* p, const string& s);
	Link* first();
};

Link* Link::first()
{
	Link* p = this;
	if (p == nullptr) return nullptr;
	if (!p->prev) return p;
	
	while (p->prev) p=p->prev;
	return p;
}

Link* Link::find(Link* p, const string& s)
{
	p=p->first();
	while (p) 
	{
		if (p->name == s) return p;
		p=p->succ;
	}
	
	return nullptr;

}

void Link::show()
{
	Link* p = this;
	while (p->prev) p = p->prev;
	
	while (p) 
	{
		cout << p->name << '\n';
		p=p->succ;
	}
}

Link* Link::add(Link* p, Link*n)
{
	if (p==nullptr) return n;
	if (n==nullptr) return p;
	
	if (p->succ)
	{
		p->succ->prev=n;
		n->succ=p->succ;
	}
	
	n->prev=p;
	p->succ=n;
	
	return n;
}

Link* lex_last(Link* p)
{
	if (p == nullptr) return nullptr;
	
	p=p->first();
	
	string last = "0";
	
	while(p)
	{
		if (lexigraph_last(p->show_name(),last)) last = p->show_name();
		if (p->next()) p=p->next();
		else if (!p->next()) break;
	}

	return p->find(p,last);
}

Link* lex_less(Link* p)
{
	if (p == nullptr) return nullptr;
	
	p=p->first();
	
	string less = "9";
	
	while(p)
	{
		if (!lexigraph_last(p->show_name(),less)) less = p->show_name();
		if (p->next()) p=p->next();
		else if (!p->next()) break;
	}

	return p->find(p,less);
}






int main()
{
	
	Link* p = new Link{"D"};

	
	
	p=p->insert(p);
	
	cout << p->show_name() << '\n';
	
	
	char c;
	cin >> c;
	
	
}














