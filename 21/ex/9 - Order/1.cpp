#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <list>

//раздел символьных констант
const char open_brace = '{';
const char close_brace = '}';
const char colon = ':';
const char tabulation = '\t';
const char newline = '\n';
const char end_of_order = '!';

//-----------------------------------------------------

struct Purchase{
	std::string name;
	int unit_price = 0;
	int count =0;
	Purchase() {}
	Purchase(const std::string n, const int up, int c) : name{n}, unit_price{up}, count{c} {}
	
};
//-----------------------------------------------------
struct Date {
	int day = 0;
	int month = 0;
	int year = 0;
	Date() {}
	Date(int dd, int mm, int yy) : day{dd}, month{mm}, year{yy} {}
};

//-----------------------------------------------------

struct Address{
	std::string post_index;
	std::string country;
	std::string region;
	std::string city;
	std::string street;
	std::string house;
	std::string room;
	Address() {}
	Address(const std::string& pi, const std::string& ct, const std::string& reg, const std::string& cy,
			const std::string&st, const std::string& h, const std::string&r) 
			: post_index{pi}, country{ct}, region{reg}, city{cy}, street{st}, house{h}, room{r} {}
};

//-----------------------------------------------------
struct Order{
	std::string name;
	Date birth_day;
	Address address;
	std::vector<Purchase>purchases;
	Order(const std::string& n, const Date& d, const Address ad, const std::vector<Purchase>& p)
	: name {n}, birth_day{d}, address{ad}, purchases{p} 
		{}
	Order() {}
	
	bool operator <(const Order& b) {return name < b.name;}
	
};
//-----------------------------------------------------
std::string read_string(std::istream& ifs, const char stop) {
std::string n;
char det = 0;
while (true){
ifs.get(det);
if (det == stop) return n;
else
	n+=det;
}

return n;


}
//-----------------------------------------------------
char read_and_check(std::istream& read, const char check){
	char ch = 0;
	read.get(ch);
	if (ch != check) {read.setstate(read.failbit);}
	return ch;
		
}
//-----------------------------------------------------
std::istream& operator >> (std::istream& ifs, Purchase& pur) {
//формат name: {"name"} '\t' price:{"unit_price"} '\t' count:{"count"}
	char c = 0;
	ifs >> c;
	if (ifs.eof()) return ifs;
	else
		ifs.putback(c);
char ch1 =0, ch2 = 0, ch3 = 0, ch4 = 0;
std::string title, n;
int up =0, ct = 0;
//-------------------------------------------------------------------
title = read_string(ifs,colon); 		// name
read_and_check(ifs,open_brace); 		// {
n = read_string(ifs,close_brace); 		//name of item
read_and_check(ifs,tabulation); 		//\t
//-------------------------------------------------------------------
title = read_string(ifs,colon);			//price
read_and_check(ifs,open_brace); 		// {
ifs >> up;	 							// price of unit
read_and_check(ifs,close_brace); 		// }
read_and_check(ifs,tabulation); 		// \t
//-------------------------------------------------------------------
read_string(ifs,colon); 				// count:
read_and_check(ifs,open_brace); 		// '{'
ifs >> ct;								// count
read_and_check(ifs,close_brace);		// '}'
//-------------------------------------------------------------------
pur = Purchase{n,up,ct};
return ifs;
};
//-----------------------------------------------------
std::ostream& operator << (std::ostream& ost, const Purchase& pur){
//name: {"name"} '\t' price:{"unit_price"} '\t' count:{"count"}
	ost << "name:{" << pur.name << "}\t" << "price:{" << pur.unit_price << "}\t" << "count:{"
	<< pur.count << "}\n";
	return ost;
};

std::istream& operator >> (std::istream& ist, Date& date){
	//format day:{"day"}'\t'month:{"month"}'\t'year:{"year"}
	char c = 0;
	ist >> c;

	if (ist.eof()) return ist;
	else
	ist.putback(c);
	int dd =0, mm =0, yy =0;
	//-------------------------------------------------------------------
	read_string(ist,colon); //day:
	read_and_check(ist,open_brace); //'{'
	ist >> dd; // day
	read_and_check(ist,close_brace); // '}'
	read_and_check(ist,tabulation);
	//-------------------------------------------------------------------
	read_string(ist,colon); // month:
	read_and_check(ist,open_brace); // '{'
	ist >> mm; //month
	read_and_check(ist,close_brace); // '}'
	read_and_check(ist,tabulation); // '\t'
	//-------------------------------------------------------------------
	read_string(ist,colon); // year:
	read_and_check(ist,open_brace); // '{'
	ist >> yy; //month
	read_and_check(ist,close_brace); // '}'
	date = Date{dd,mm,yy};
	
	return ist;
}

std::ostream& operator << (std::ostream& ost, const Date& date){
	//format day:{"day"}'\t'month:{"month"}'\t'year:{"year"}
	
	ost << "day:{" << date.day << "}\t"
		<< "month:{" << date.month << "}\t"
		<< "year:{" << date.year << "}";
		
		return ost;
	
}


std::istream& operator >> (std::istream& ist, Address& adr) {
//format
//post index:'\t'{"index"}'/n'
//country:'\t'{"country"}'\n'
//region:'\t'{"region"}'\n'
//city:'\t'{"city"}'\n'
//street:'\t'{"street"}'\n'
//house:'\t'{"house"}'\n'
//room:'\t'{"room"}'\n'

char c = 0;
ist >> c;

if (ist.eof()) return ist;
else
	ist.putback(c);
//-------------------------------------------------------------
std::string index, country, region, city, street, house, room;
//-------------------------------------------------------------

read_string(ist,open_brace);
index = read_string(ist,close_brace);
read_and_check(ist,newline);
//-------------------------------------------------------------
read_string(ist,open_brace);
country = read_string(ist,close_brace);
read_and_check(ist,newline);
//-------------------------------------------------------------
read_string(ist,open_brace);
region = read_string(ist,close_brace);
read_and_check(ist,newline);
//-------------------------------------------------------------
read_string(ist,open_brace);
city = read_string(ist,close_brace);
read_and_check(ist,newline);
//-------------------------------------------------------------
read_string(ist,open_brace);
street = read_string(ist,close_brace);
read_and_check(ist,newline);
//-------------------------------------------------------------
read_string(ist,open_brace);
house = read_string(ist,close_brace);
read_and_check(ist,newline);
//-------------------------------------------------------------
read_string(ist,open_brace);
room = read_string(ist,close_brace);
//-------------------------------------------------------------
adr = Address{index, country, region, city, street, house, room};



	

return ist;
}

std::ostream& operator << (std::ostream&ost, const Address& adr){
//format
//post index:'\t'{"index"}'/n'
//country:'\t'{"country"}'\n'
//region:'\t'{"region"}'\n'
//city:'\t'{"city"}'\n'
//street:'\t'{"street"}'\n'
//house:'\t'{"house"}'\n'
//room:'\t'{"room"}'\n'
	ost << "Post index:\t{" 	<< adr.post_index << "}\n"
		<< "Country:\t{" 		<< adr.country << "}\n"
		<< "Region:\t{" 		<< adr.region << "}\n"
		<< "City:\t{" 			<< adr.city << "}\n"
		<< "Street:\t{" 		<< adr.street << "}\n"
		<< "House:\t{" 			<< adr.house << "}\n"
		<< "Room:\t{" 			<< adr.room << "}";
				
	return ost;
}


std::istream& operator >> (std::istream& ist, Order& order){

char c;
ist >> c;
if (ist.eof()) 
		return ist;
else
	ist.putback(c);

std::string name;
Date br;
Address ad;
std::vector<Purchase>p;
//формат Name of client:'\t'{"name"}
read_string(ist,open_brace);
name = read_string(ist,close_brace);
read_and_check(ist,newline);
//----------------------------------------------------
read_and_check(ist,newline);
read_string(ist,tabulation); //birth_day
ist >> br;
read_and_check(ist,newline);

//-----------------------------------------------------
read_and_check(ist,newline);
read_string(ist,newline); //address
ist >> ad;
read_and_check(ist,newline);
//-----------------------------------------------------
read_and_check(ist,newline);
read_string(ist,newline); //Purchases:\n
char cc =0;
while (cc != end_of_order){
Purchase pur;
ist >> pur;
p.push_back(pur);
ist >> cc;
}

order = Order{name,br,ad,p};

return ist;
}

std::ostream& operator << (std::ostream& ost, const Order& order) {
//формат Name of client:'\t'{"name"}
ost << "Name of client:\t{" << order.name << "}\n\n"
	<< "Birth day:\t" 		<< order.birth_day << "\n\n"
	<< "Address:\n" 		<< order.address << "\n\n"
	<< "Purchases:\n";
for (auto q : order.purchases)
	ost << q;

ost << "!\n";
return ost;
}


struct Order_by_address{
bool operator()(const Order& a, const Order& b) {
	return a.address.country < b.address.country;
	}
};

struct Order_by_name{
bool operator()(const Order& a, const Order& b) {
	return a.name < b.name;
	}
};
int main() {

std::string source,target,source2, target2, target3;
source = "D:\\data\\input.txt";
target = "D:\\data\\output.txt";
source2 = "D:\\data\\input2.txt";
target2 = "D:\\data\\output2.txt";
target3 = "D:\\data\\output3.txt";

std::ifstream ifs {source};
std::ofstream ofs {target};
std::ifstream ifs2 {source2};
std::ofstream ofs2 {target2};
int sum = 0;
std::istream_iterator<Order>ii{ifs};
std::istream_iterator<Order>eos;

for(;ii != eos; ++ii)
	for (int i =0; i < (*ii).purchases.size(); ++i)
	{
		sum+=((*ii).purchases[i].unit_price * (*ii).purchases[i].count);
	}
	
std::istream_iterator<Order>ii2{ifs2};

for(;ii2 != eos; ++ii2)
	for (int i =0; i < (*ii2).purchases.size(); ++i)
	{
		sum+=((*ii2).purchases[i].unit_price * (*ii2).purchases[i].count);
	}
	
	std::cout << sum << '\n';
	char c;
	std::cin >> c;


}











