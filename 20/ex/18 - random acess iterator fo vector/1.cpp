
#include "C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\VC\\Tools\\MSVC\\14.12.25827\\include\\iostream"
#include "C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\VC\\Tools\\MSVC\\14.12.25827\\include\\memory"


struct out_of_range 
{
};


template <typename T, typename A = std::allocator<T>>
class vector_base {
public:
T* elem = nullptr;
int sz = 0;
int space =0;

public:
vector_base(int i = 0);
~vector_base();

vector_base(const vector_base&);
vector_base& operator=(const vector_base&);

vector_base(vector_base&&);
vector_base& operator=(vector_base&&);

T& operator[] (int n) {return elem[n];}
T& operator[] (int n) const {return elem[n];}




};

template <typename T, typename A>
vector_base<T,A>::vector_base(int i) : sz{0}, space{i} {
	A alloc;
	elem = alloc.allocate(i);
}

template <typename T, typename A>
vector_base<T,A>::~vector_base() {
	if (!elem) return;
	A alloc;
	
	for (int i =0; i < sz; ++i)
		alloc.destroy(&elem[i]);
	alloc.deallocate(elem,space);
	elem = nullptr;
}

template <typename T, typename A>
vector_base<T,A>::vector_base(const vector_base& b){
	sz = b.sz;
	space = b.space;
	
	for (int i = 0; i < sz; ++i) 	
		elem[i] = b.elem[i];
}

template <typename T, typename A>
vector_base<T,A>& vector_base<T,A>::operator = (const vector_base& b) {
	A alloc;
	alloc.deallocate(elem,space);
	elem = alloc.allocate(b.space);
	sz = b.sz;
	space = b.space;
	for (int i = 0; i < sz; ++i) 	
		elem[i] = b.elem[i];
	
	return *this;

}

template <typename T, typename A>
vector_base<T,A>::vector_base(vector_base&& b) {
	
	sz = b.sz;
	space = b.space;
	elem = b.elem;
	b.elem = nullptr;
}

template <typename T, typename A> 
vector_base<T,A>& vector_base<T,A>::operator=(vector_base&& b) {
	A alloc;
	alloc.deallocate(elem,space);
	
	sz = b.sz;
	space = b.space;
	elem = b.elem;
	b.elem = nullptr;

return *this;
}

template <typename T, typename A = std::allocator<vector_base<T>>>
class vector {
	vector_base<T>* base = nullptr;

	public:
	using type_name = T;

	size_t size_type = sizeof(T);
	
	vector(int i = 0);
	~vector();
	
	vector(const vector&);
	vector& operator = (const vector&);
	
	vector(vector&&);
	vector& operator = (vector&&);
	
	T& operator[] (const int n) {return (*base)[n];}
	T& operator[] (const int n) const {return *(base)[n];}
	int size() const {return base->sz;}
	int capacity() const {return base->space;}
	
	T* front() {return &base->elem[0];}
	T* back() {return &base->elem[base->sz-1];}
	
	
	void reserve(const int);
	//void resize(const int);
	void push_back(const T&);
	
	
	class iterator;
		
	iterator insert(iterator, const T&);
	iterator erase(iterator);
	iterator erase(iterator,iterator);
	iterator begin() {return iterator{&base->elem[0],&base->elem[0],&base->elem[base->sz]};};
	iterator end() {return iterator {&base->elem[base->sz],&base->elem[0],&base->elem[base->sz]};};

};



template <typename T, typename A>
class vector<T,A>::iterator  {
	
	// Итератор с проверкой выхода за пределы допустимого диапазона
	// Это тот же указатель, только немного умнее
	// Его конструктор получает 3 указателя на текущий элемент и предельные

	
	private:
	T* t = nullptr;
	T* max = nullptr;
	T* min = nullptr;
	public:
	iterator (T* tt, T* ext1 = nullptr, T* ext2 = nullptr) : 
	t{tt}, min {ext1}, max{ext2}{		
		}
	
	
	bool operator ==(iterator p) {return p.t == t;}
	bool operator != (iterator p) {return !(*this == p);}
	iterator& operator++() {range(1);++t; return *this;}
	iterator& operator--() {range(-1);--t; return *this;}
	iterator operator+(const int n) {range(n);return iterator{t+n};}
	iterator operator-(const int n) {range(-n);return iterator{t-n};}
	int operator+(iterator p) {return t+p.t; }
	int operator-(iterator p) {return t-p.t; }
	
	T& operator[](const int n) {range(n); return t[n];}
	T& operator[](const int n) const {range(n);return t[n];}
	T& operator*() {range(0);return *t;}
		
	void range(const int dir) const {
		//проверка выхода за пределы диапазона:
		//вычисляем адрес указателя, который хочет получить пользователь
		//сравниваем его с пределами, если он выходит за диапазон
		//выбрасываем исключение
		T* result = t+dir;

		if (result == min ) return;
		else if (max && result > max) throw out_of_range();
		else if (min && result < min) throw out_of_range();
	
		
		
	}
	};

template <typename T, typename A>
vector<T,A>::vector(int i) {
	A alloc;
	base = alloc.allocate(1);
	alloc.construct(base,vector_base<T>{i});
}

template <typename T, typename A>
vector<T,A>::~vector() {
	if (!base) return;
	A alloc;
	alloc.destroy(base);
	alloc.deallocate(base,1);
	base = nullptr;
}

template <typename T, typename A>
vector<T,A>::vector(const vector& b) {

	A alloc;
	base = alloc.allocate(1);
	alloc.construct(base,vector_base<T>{b.capacity()});
	*base = *b.base;

}

template <typename T, typename A>
vector<T,A>& vector<T,A>::operator = (const vector& b) {

this->~vector();

A alloc;
base = alloc.allocate(1);
alloc.construct(base,vector_base<T>{b.base->space});
*base = *b.base;

return *this;
};

template <typename T, typename A>
vector<T,A>::vector(vector&& b) {
	base = b.base;
	b.base = nullptr;
}

template <typename T, typename A>
vector<T,A>& vector<T,A>::operator=(vector&& b) {
	
	this->~vector();
	
	base = b.base;
	b.base = nullptr;
	
	return *this;
}

template <typename T, typename A>
void vector<T,A>::reserve(const int newalloc) {

if (newalloc <= base->space) return;

vector_base<T>b{newalloc};
for (int i =0; i < base->sz; ++i)
	b[i] = (*base)[i];
b.sz = base->sz;

std::swap(*base,b);
}

template <typename T, typename A>
void vector<T,A>::push_back(const T& t) {
	
	if (base->sz == base->space) 
		reserve(base->sz == 0 ? 8 : 2*base->sz);
	
	base->elem[base->sz] = t;
	++base->sz;


}


template <typename T, typename A>
typename vector<T,A>::iterator vector<T,A>::insert(typename vector<T,A>::iterator p, const T& t) {
A alloc;
int index = p-begin();

if (base->sz == base->space)
	reserve(base->sz == 0 ? 8 : 2*base->sz);

++base->sz;

iterator pp = begin()+index;


for (auto pos = end()-1; pos != pp; --pos) {
	*pos = *(pos-1); 
}

*(begin()+index) = t;

return pp;
}

template <typename T, typename A>
typename vector<T,A>::iterator vector<T,A>::erase
(typename vector<T,A>::iterator p) {

if (p == end()) return p;

for (auto pos = p+1; pos != end(); ++pos) {
*(pos-1) = *pos;
}

A alloc;
alloc.destroy(&*(end()-1));
--base->sz;

return p;
}

template <typename T, typename A>
typename vector<T,A>::iterator vector<T,A>::erase
(typename vector<T,A>::iterator b, typename vector<T,A>::iterator e) {

	if (b == end()) return b;
	int step = e-b;
	A alloc;
	for (auto pos = e; pos != end(); ++pos) {
		alloc.destroy(&*(pos-step));
		*(pos-step) = *pos;
	}
	
	if (e == end()) 
		for (auto pos = b; pos != end(); ++pos)
			alloc.destroy(&*(pos));
	
	
	
	base->sz = base->sz-step;
	
	return e;
}

int main ()
try 
{
	while (true) {
vector<int>q;
for (int i =0; i < 15; ++i)
q.insert(q.begin(),i*10);




q.erase(q.begin(),q.end());
for (auto s : q)
	std::cout << s << '\n';
	}

char c;
std::cin >> c;
}

catch(out_of_range&)
{
	std::cerr << "OUT OF RANGE\n";
	char c;
	std::cin >> c;
}











