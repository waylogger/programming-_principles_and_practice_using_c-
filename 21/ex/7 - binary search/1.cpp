#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <chrono>

struct s {
	bool operator()(std::vector<int>::iterator u)
	{
		if (*u == 31) return true;
		return false;
	}
	
};



template <typename BinaryDirectionalIterator, typename T>
BinaryDirectionalIterator 
my_binary_search
(BinaryDirectionalIterator first, 
BinaryDirectionalIterator last, const T& val, int index_to_last = -1) {
	
//расстояние от последнего элемента к первому вычисляется только, если оно задано по умолчанию
//это расстояние при дальнейших вычислениях не может принять отрицательное значение, поэтому оно задается явно
if (index_to_last == -1) 
	index_to_last = last-first;	


int index = (last-first)/2; //расстояние от начала до центра последовательности
auto midle = first+index; //центральный итератор

if (*midle == val) //МЫ НАШЛИ!!!!
	return midle;

else if (index == 0) { //индекс будет равен нулю только если расстояние между первым и последним равно 1
//это означает, что на последнем промежутке искомого значения нет
	return first + index_to_last;
}
 
else if (*midle > val)
{
	//если центральное значение больше искомого, то переходим в первую половину последовательности
	return my_binary_search(first,midle,val,index_to_last);
}
else if (*midle < val)
	//соответственно в правую
	return my_binary_search(midle,last,val,index_to_last+(first-midle));


return last;	
}











template <typename BinaryDirectionalIterator, typename T>
BinaryDirectionalIterator 
my_binary_search_list
(BinaryDirectionalIterator first, 
BinaryDirectionalIterator last, const T& val, int index_to_last = 0) {
	
if (index_to_last == 0) {
	for (auto q = first; q != last; ++q)
		++index_to_last;
	
}
		

int index =0;
for (auto q = first; q != last; ++q)
		++index;
index = index/2;
auto midle = first;
const int corrector = 1; // корректировка индекса на еденицу

for (auto i = 0; i <= index; ++i)
++midle;

if (*midle == val)
	return midle;

else if (index == 0) {
	for (int i = 0; i <= index_to_last+corrector; ++i)
		++first;
	return first;
}
 
else if (*midle > val)
{

	return my_binary_search_list(first,midle,val,index_to_last);
}
else if (*midle < val){
	int correct = 0;
	for (auto b = first; b != midle; ++b) ++correct;
	
	return my_binary_search_list(midle,last,val,index_to_last+correct);
}
	


return last;	
}



void do_something_my()
{
	std::vector<int>v1;
	for (int i =0; i < 1000; ++i)
		v1.push_back(rand()%1000);
	
	std::vector<int>v2;
	for (int i =0; i < v1.size(); ++i)
		v2.push_back(rand()%1000);
	
	
	std::sort(v1.begin(),v1.end());
	std::sort(v2.begin(),v2.end());
	
	
	
	for (int i =0; i < v2.size(); ++i)
	{
		auto u = my_binary_search(v1.begin(),v1.end(),v2[i]);
	}
}

void do_something_std()
{
	std::vector<int>v1;
	for (int i =0; i < 1000; ++i)
		v1.push_back(rand()%1000);
	
	std::vector<int>v2;
	for (int i =0; i < v1.size(); ++i)
		v2.push_back(rand()%1000);
	
	
	std::sort(v1.begin(),v1.end());
	std::sort(v2.begin(),v2.end());
	
	
	
	for (int i =0; i < v2.size(); ++i)
	{
		auto u = binary_search(v1.begin(),v1.end(), v2[i]);
	}
}

__int64 time_of_work_std (int n) {
	
	int num = n;
	auto t1 = std::chrono::system_clock::now();
	for (int i =0; i < num; ++i) {
		do_something_std();
	}
	auto t2 = std::chrono::system_clock::now();
	return std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
		
	
}


__int64 time_of_work_my (int n) {
	
	int num = n;
	auto t1 = std::chrono::system_clock::now();
	for (int i =0; i < num; ++i) {
		do_something_my();
	}
	auto t2 = std::chrono::system_clock::now();
	return std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
		
	
}


int main () {
	
	//while (true){
	std::cout << time_of_work_std(250) << '\n';
	std::cout << time_of_work_my(250) << '\n';
	
	//rак итог - мой алгоритм медленнее на 23%, но он возвращает итератор, а не булево значение

	
	
	
	char c;
std::cin >>c;
	}


