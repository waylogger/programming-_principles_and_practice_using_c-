#include <iostream>
#include <vector>
#include <list>

typedef std::vector<char> Line;

struct Document
{
std::list<Line>line;
Document() {line.push_back(Line{});}
};


std::istream& operator>> (std::istream& is, Document& d)
{
	for (char ch; is.get(ch);)
	{
		d.line.back().push_back(ch);
		if (ch == '\n')
		d.line.push_back(Line{});
	}
if (d.line.back().size())
	d.line.push_back(Line{});
return is;
};

int main()
{

Document d;
std::cin >> d;

return 0;
}
