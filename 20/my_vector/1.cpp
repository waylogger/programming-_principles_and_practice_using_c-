
#include <iostream>
#include <memory>

template <typename T, typename A = std::allocator<T>>
struct vector_base {
//-------------------------------------------
using iterator = T*;
using const_iterator = const T*;
using value_type = T;
using size_type = unsigned int;
//-------------------------------------------

int sz = 0;
int space = 0;
A alloc;


value_type* val = nullptr;
//-------------------------------------------

vector_base(int n = 0);
vector_base(const vector_base&);
vector_base(vector_base&&);

vector_base& operator= (const vector_base&);
vector_base& operator= ( vector_base&&);

virtual ~vector_base();
//-------------------------------------------
iterator begin() {return &val[0];};
iterator end() {return &val[sz];};




};
template <typename T, typename A>
vector_base<T,A>::vector_base(int i) : sz{0}, space{i}, val {alloc.allocate(i)} {
	//for (int q =0; q < sz;++q) alloc.construct(&val[q],T());
}
template <typename T,typename A>
vector_base<T,A>::~vector_base() {
	
	for (int i = 0; i < sz; ++i) alloc.destroy(&val[i]);
	alloc.deallocate(val,space);
}	
template <typename T, typename A>
vector_base<T,A>::vector_base(const vector_base& cp) {
	auto old_obj = this;
	//--------------------------------------------------------
	old_obj->~vector_base();
	//-------------------------------------------------------
	old_obj->val = alloc.allocate(cp.space);
	old_obj->sz = cp.sz;
	old_obj->space = cp.space;
	for (int i =0; i < old_obj->sz;++i) alloc.construct(&old_obj->val[i],cp.val[i]);
	//--------------------------------------------------------
		
}	
template <typename T, typename A>
vector_base<T,A>& vector_base<T,A>::operator = (const vector_base<T,A> & cp) {
	
	auto old_obj = this;
	//--------------------------------------------------------
	old_obj->~vector_base();
	//-------------------------------------------------------
	old_obj->val = alloc.allocate(cp.space);
	old_obj->sz = cp.sz;
	old_obj->space = cp.space;
	for (int i =0; i < old_obj->sz;++i) alloc.construct(&old_obj->val[i],cp.val[i]);
	//--------------------------------------------------------
	return *this;
}
template <typename T, typename A>
vector_base<T,A>::vector_base(vector_base&& cp) {
	
	auto old_obj = this;
	//--------------------------------------------------------
	old_obj->~vector_base();
	//-------------------------------------------------------
	old_obj->val = alloc.allocate(cp.space);
	old_obj->sz = cp.sz;
	old_obj->space = cp.space;
	for (int i =0; i < old_obj->sz;++i) alloc.construct(&old_obj->val[i],cp.val[i]);
	//--------------------------------------------------------
}
template <typename T, typename A>
vector_base<T,A>& vector_base<T,A>::operator = (vector_base<T,A> && cp) {
	//std::cout << "WOOOOPY!!!\n";
	auto old_obj = this;
	//--------------------------------------------------------
	old_obj->~vector_base();
	//-------------------------------------------------------
	old_obj->val = alloc.allocate(cp.space);
	old_obj->sz = cp.sz;
	old_obj->space = cp.space;
	for (int i =0; i < old_obj->sz;++i) alloc.construct(&old_obj->val[i],cp.val[i]);
	//--------------------------------------------------------
	return *this;
}
template <typename T, typename A = std::allocator<T>>
class vector : public vector_base<T,A> {
public:
void resize(const int newsize);
void reserve(const int newalloc);
void push_back(const value_type&);
void push_front(const value_type&);

vector(int i = 0) : vector_base<T,A>{i} {

};
iterator insert(iterator p, const T& val);
iterator erase(iterator p);
iterator erase(iterator b, iterator e);

value_type& operator[](const int n) {return val[n];}
value_type& operator[](const int n) const {return val[n];}

};
template <typename T, typename A>
void vector<T,A>::reserve(const int newalloc) {

if (newalloc <= this->space) return;
vector_base<T,A> b {newalloc};
for (int i = 0; i < this->sz; ++i) alloc.construct(&b.val[i],this->val[i]);
b.sz = sz;

std::swap<vector_base<T,A>>(*this,b);
}
template <typename T, typename A>
void vector<T,A>::resize(const int newsize) {
if (newsize <= sz) return;
reserve(newsize);
for (int i = sz; i < newsize; ++i) {
	alloc.construct(&val[i],T());
}
	sz = newsize;
}
template <typename T, typename A>
void vector<T,A>::push_back(const T& elem) {

if (space == 0) reserve(8);
else if (sz == space) reserve(space*2);
alloc.construct(&val[sz],elem);
++sz;
}
template <typename T, typename A>
typename vector<T,A>::iterator vector<T,A>::erase(typename vector<T,A>::iterator p){ 
if (p == end()) return p;

for (auto pos = p+1; pos != end(); ++pos) {
	*(pos-1) = *pos;
}
--sz;
alloc.destroy(end()-1);

return p;
}
template <typename T, typename A>
typename vector<T,A>::iterator vector<T,A>::erase(typename vector<T,A>::iterator b, typename vector<T,A>::iterator e){ 
if (b == end()) return b;

if (e != end())
for (auto pos = e+1; pos != end(); ++pos, ++b) {
	*b = *pos;
}

for (auto pos = end(); pos != b;--pos) {
	alloc.destroy(pos);
	--sz;
}

return e;
}
template <typename T, typename A>
typename vector<T,A>::iterator vector<T,A>::insert(typename vector<T,A>::iterator b, const T& elem){ 

int index = b - begin();

if (space == sz) 
	reserve (sz == 0?8:2*sz);

alloc.construct(val+sz,*(end()-1));
++sz;
iterator pp = begin()+index;

for (auto pos = end()-1; pos != pp; --pos ) {
*pos = *(pos-1);
}

*(begin()+index) = elem;
return pp;
}






template <typename T, typename A = std::allocator<T>>
class pvector : public vector<T,A> {
	using vector::vector;
	public:
	
	
	~pvector() {
		std::allocator<T*> loc;
		for (int i =0; i < sz; ++i) {
			loc.deallocate(*(&val[i]),1);
			//std::cout << &val[i] << '\n';
		
			}
		
			
		}
		
		
};









int main (){
	
	

pvector<double*>q;

for (int i=0; i < 24;++i) q.push_back(std::allocator<double>{}.allocate(1));
	
	
	char c;
	std::cin >> c;
}