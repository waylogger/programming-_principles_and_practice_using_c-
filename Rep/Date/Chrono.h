#include <std_lib_facilities.h>
namespace Chrono { 																//open namespace Chrono 
enum class Month { 																//open enum class Month
jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
}; 																				//close enum class Month
class Date {																	//open class Date
public:
class Invalid { };									//для исключений
Date(int d, Month m, int y);
Date();

													//немодицифирующие функции
int day () const {return d;}
Month month () const { return m; }
int year () const { return y;}
long int after_null_day () const {return after_null;}
													//модифицируюшие функции
void add_day(int n);
void add_month(int n);
void add_year (int n);
void to_null (const Date& t);
private:
int y;
Month m;
int d;
long int after_null = 0;
};																				//close class Date
bool is_date(int d, Month m, int y); 				//проверка корректности
bool leapyear(int y); 								//високосные года
bool operator == (const Date&a, const Date& b);
bool operator != (const Date&a, const Date& b);
ostream& operator << (ostream&os, const Date&d);
istream&operator >> (istream&is, Date& dd);
int midle_days (const Date& d, const Date& dd);
enum class Day;
void print_day(Day& c);
} 																				//close namespace Chrono 
//int main () {};