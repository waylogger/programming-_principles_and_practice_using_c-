#include <iostream>
#include <memory>


template <typename T, typename PA = std::allocator<T*>>
class pvector_base {
	// ��� � ���� ����������� ������ ����� ������ :
	//� ������ ������ ��������� �� ������� ��������� �� ������ � ��������
	//�� � ������ �����a pvector, ��� �������� ��� �� ������������ �� �������� ����������
	//� ������������ ������ - ��� �� ������� ����� pvector
public:
int sz = 0;
int space = 0;
T** elem = nullptr;

public:
pvector_base(int i = 0);
virtual ~pvector_base();

pvector_base(const pvector_base&) = delete;
pvector_base& operator = (const pvector_base&) = delete;

pvector_base(pvector_base&&);
pvector_base& operator = (pvector_base&&);

int size() const {return sz;}
void set_size(const int a) {sz = a;}

int capacity() const {return space;} 
void set_space(const int a) {space = a;}


};

template <typename T, typename PA>
pvector_base<T,PA>::pvector_base(int n =0) : sz {0}, space{n} {
	// ������ ������������ ������� � ������������� ������� ������
	// � ��������� ������ ��� ������� ����������

	PA palloc;
	elem = palloc.allocate(n);
	
}

template <typename T, typename PA>
pvector_base<T,PA>::~pvector_base() {
//������ ����������� ������� � ����������� �� ������ ������� ���������� elem
//�� � � ����������� ������� ��������� ������� � ����������� ��� ������
if (!elem) return;
std::allocator<T> alloc;
PA palloc;


for (int i =0; i < sz; ++i){
	if (elem[i]) { 
	
		alloc.destroy(elem[i]);
		
	}
	
}

for (int i =0; i < sz; ++i){
	if (elem[i]) 
	alloc.deallocate(elem[i],1);
	elem[i] = nullptr;
	}	

//����� ����������� � ������� ���������� ����� ������� ������ ����������
palloc.deallocate(elem,space);
elem = nullptr;
}	

template <typename T, typename PA>
pvector_base<T,PA>::pvector_base(pvector_base&& b) {
// ����������� ������� ���������� � ������� �� ����������� ���������
// ��������� ��� �� ��������� ���� ���������� �������� ����������
//std::cout << "MOVE\n";
this->sz = b.sz;
this->space = b.space;
this->elem = b.elem;
b.elem = nullptr;
}	


template <typename T, typename PA>
pvector_base<T,PA>& pvector_base<T,PA>::operator=(pvector_base&&b) {
this->~pvector_base(); //������� � ������������� ������ � ����

this->sz = b.sz;
this->space = b.space;
this->elem = b.elem;
b.elem = nullptr;

return *this; // � � ����
}


template <typename T, typename A = std::allocator<T*>>
class ownership_base : public pvector_base<T,A> {
/*
���� ����� - ����������
�� ��������� ������� ���������, ������� ��
*/
public:
using pvector_base::pvector_base;

ownership_base(ownership_base&& b) {
	sz = b.sz;
	space = b.space;
	elem = b.elem;
	b.elem = nullptr;
}

ownership_base& operator = (ownership_base&& b) {
	sz = b.sz;
	space = b.space;
	elem = b.elem;
	b.elem = nullptr;
	
	return *this;
	
}

~ownership_base() {

if (!elem) return;
for (int i =0; i < sz; ++i) {
	elem[i] = nullptr; //����� ����������� ������ ����������� ������������� ������
	}
}

};



template<typename T, typename A = std::allocator<pvector_base<T>>> 
class pvector{
	// ���� ����� ������ ����� ��� ������������ ����������, ������� ������ ���������
	// ����������� ����������� � ���, ��� ��� �������� ������������� �������� ����������� 
	// ����������
	// �� ���� ��������� �� ������ ���� ������� std::vector
		
	protected:
	pvector_base<T>* base= nullptr; // �������� ��������� �� ������������� pvector_base
	//������ ��� �������������� �� ���������� ��������� ����
	public:
	using iterator = T**;
	using const_iterator = const T**;
	using type_name = T;
	
	pvector(int i =0);
	virtual ~pvector();	

	pvector(const pvector&) = delete;
	pvector& operator= (const pvector&) = delete;
	
	pvector(pvector&&b) {this->base = b.base; b.base = nullptr;};
	pvector& operator=(pvector&&b) {
		this->~pvector();
		this->base = b.base;
		b.base = nullptr;
		return *this;
	}
	int size() const {return base->size();}
	void set_size(const int a) {base->set_size(a);}
	
	int capacity() const {return base->capacity();}
	int set_space(const int a) {base->set_space(a);}
	
	virtual void reserve(const int);
	virtual void push_back(T* const);
	void resize(const int);
	
	iterator begin() {return &base->elem[0];}
	iterator end() {return &base->elem[size()];}
	
	 T* operator[](const int n) {return base->elem[n];}
	 T* operator*() {return base->elem[0];}
	 
	 virtual  iterator insert(iterator p, T* const);
	 iterator erase(iterator p);
	 iterator erase(iterator b, iterator e);
	
	
	
};

template<typename T, typename A>
pvector<T,A>::pvector(int i=0) { 
	// �������� ������ ��� �������������
	// � �������� ��� �����������
	A alloc;
	base = alloc.allocate(1);
	alloc.construct(base,pvector_base<T>{i});
	}
	
template<typename T, typename A>
pvector<T,A>::~pvector() {
		if (!base) return;
		//���������� ������ ���������� ������������� � ���������� ������
		A alloc;
		alloc.destroy(base);
		alloc.deallocate(base,1);
		base = nullptr;
	}
	
template<typename T, typename A> 
void pvector<T,A>::reserve(const int newalloc) {
/*
����� ������ ������� � ��������� ����� ������ ��� ������� ����������,
���� ��� ���������� ����� ������ ���� ���������
��� ���� ����� ��������� ��������� ��������:
1. ������� ����� ������ ������ pvector_base
2. ����������� � ���� �������� ������
3. ����������� � ����� ������ �� ����� ����������
*/
if (newalloc <= capacity()) return;

pvector_base<T> b {newalloc};

for (int i =0; i < this->size(); ++i) {
//�������� �������� ���
b.elem[i] = this->base->elem[i];
}
b.set_size(size());
std::swap(b,*base);

for (int i =0; i < b.size(); ++i)
	//����� �������� ��������� ��������� �� �������� � ����������� b
	b.elem[i] = nullptr;


}

template <typename T,typename A>
void pvector<T,A>::push_back(T* const t) {
if (capacity() == size())
	reserve(size()==0?8:size()*2);

base->elem[size()] = t;
base->set_size(size()+1);

}

template <typename T,typename A>
void pvector<T,A>::resize(const int newsize) {
/*
������� ���������� ��� ���������� ����������� ������� ����������

*/
if (newsize <= size()) return;

if (newsize >= capacity())
	reserve(newsize*2);

for (int i = size(); i < newsize; ++i)
	base->elem[i] = nullptr;  //��������� ������ ������ �������� �����������

base->set_size(newsize);

}


template <typename T, typename A>
typename pvector<T,A>::iterator pvector<T,A>::insert
(typename pvector<T,A>::iterator p, T* const t) {
	/*
	���� ������� ������ �������� � ������ ����������� � ���������:
	1. ���������� ������� ������������ ��������, ������������ ��� ���������� ���������
	������� � ������� �� ������ � �� ����.
	2. ��� �������� �������� ����� ������;
	3. ��������� ����������� ��������� � ���������� �������� ������ �� ���� ���
	4. ��������� ��������������� �������� ������������ ��������
	*/
	int index = p-begin(); //������ ������������ ��������
	
	if(size() == capacity())
			reserve(size()==0?8:2*size());
	
	iterator b = begin()+index;
	
	
	std::allocator<T>{}.construct(base->elem+size(),base->elem[size()-1]);
	set_size(size()+1);
	for (auto g = end()-1; g != b; --g) {
	*g = *(g-1);
	}
	
	*(begin()+index) = t;
		
	
	return p;
}
template <typename T, typename A>
typename pvector<T,A>::iterator pvector<T,A>::erase
(typename pvector<T,A>::iterator p) {
	/*
	��������� �������� ������� � ����������� ���� ����� ������� ��������� ������� 
	�� ���� ������� �����
	*/
	
if (p == end() || size() ==0) return p;

for (auto q = p+1; q != end(); ++q) {
*(q-1) = *q;

}

std::allocator<int>{}.destroy(&*(end()));
set_size(size()-1);

return p;
}

template <typename T, typename A>
typename pvector<T,A>::iterator pvector<T,A>::erase
(typename pvector<T,A>::iterator b, typename pvector<T,A>::iterator e) {
	/*
	�������� ��������� ��������� ��� ��������: 
	1. �� ������� ������ �� �����
	2. �� ������� ����� ������� � ��������
	
	� ������ ������ �� �������� ����������� ���� ���������� �� �����
	� �� ���� �������� ��������� ����������� �������
	
	�� ������ ������ �� ��������� �� ��, ��� ����� �� ������ ��������� � ������ ���������
	�� ����� ������� � �������� ����������� ����������� ���������
	
	��� ����������� ������������ ���������� ������� �� �� �������� � pvector
	*/
	if (b == e) return e;
	
	if (e == end()) {
		for (auto s = b; s != e; ++s) {
			std::allocator<T>{}.destroy(*s);
			set_size(size()-1);
		}
		return e;
	}
	
int copies = end() - e; //������� ��������� ����� ����� ���������� ���������
int step = e - b; //������� ��������� � ��������� ��� ���������� ����������� 


//������� ���������, ������� ��������� ������� � ������ ����������
pvector<T>to_del;
for (auto d = b; d != e; ++d)
	to_del.push_back(*d); 



iterator pos = b;
for (int i = 0; i <= copies; ++i) {
	//��������� �������� ������� �� ��������� ����������
*pos = *(e+i);
++pos;
}

set_size(size()-step);

for (int i = 0; i < step; ++i) {
	// ���������� ������ �����
	std::allocator<T>{}.destroy(base->elem[size()+i]);
}
	
return e;
}


template <typename T, typename A = std::allocator<pvector_base<T>>>
class ovector : public pvector<T,A> {
public:
using pvector<T,A>::pvector;
T& operator[](const int i) {return *base->elem[i];}
};



template <typename T, typename A = std::allocator<pvector_base<T>>> 
class ownership_vector : public pvector<T,A> {
/*
������ ����� ��������� ��������� ����� pvector �� ����������� ��������� ������������.
�� �������� ��� ����������� �� pvector_base ����� ownership_base

���� ����� �� ������� �������� ���������

���������� ������� ������ ������ ��������� ������� �������� - ��������� �������� � ownervector_base
� ���������� ������ � base ����������, ��� ����� �������������� �� ��������

������ ��������� ownervector_base

1. ��������� ownervector_base �����������, ������� ������ �������
2. ��� �������� ������� ������ �������� �� � ������� ������ - base
3. �������� ���������� ownervector_base, ������� �� ������� �������� ���������

*/

ownership_base<T>* save_base = nullptr;
public:

ownership_vector(int i =0);
~ownership_vector();

bool permiss_to_delete(T* const t);

void reserve(const int) override;
void push_back(T* const, bool permiss = true);


};

template <typename T, typename A>
ownership_vector<T,A>::ownership_vector(int i =0) : pvector<T,A>{i} {
	std::allocator<ownership_base<T>> alloc;
	save_base = alloc.allocate(1);
	alloc.construct(save_base,ownership_base<T>{i});
}

template <typename T, typename A>
ownership_vector<T,A>::~ownership_vector()  {
	
	if (!base) return;
	if (!save_base) return;
	
	
	for (int i = 0; i < base->sz; ++i) 
		if (base->elem[i])
			if (!permiss_to_delete(base->elem[i])) {
				base->elem[i] = nullptr;
			}
	
	std::allocator<ownership_base<T>> alloc;
	
	alloc.destroy(save_base);
			
	alloc.deallocate(save_base,1);
	
	save_base = nullptr;
				
}
 

template <typename T, typename A>
bool ownership_vector<T,A>::permiss_to_delete(T* const t)  {
	
	if (!save_base) return true;
	for (int i = 0; i < save_base->sz; ++i)
			if (t == save_base->elem[i]) {
				
				return false;
		}
			
		
	
	return true;
}



template <typename T, typename A>
void ownership_vector<T,A>::reserve(const int newalloc) {


if (newalloc <= save_base->space) return;

ownership_base<T> b {newalloc};

for (int i =0; i < save_base->size(); ++i) {
//�������� �������� ���
b.elem[i] = this->save_base->elem[i];
}
b.set_size(save_base->size());
std::swap(b,*save_base);

for (int i =0; i < b.size(); ++i)
	//����� �������� ��������� ��������� �� �������� � ����������� b
	b.elem[i] = nullptr;


pvector::reserve(newalloc);
}


template <typename T, typename A>
void ownership_vector<T,A>::push_back(T* const t, bool permiss = true) {

if (!permiss) {
	if (save_base->sz == save_base->space)
		reserve(save_base->sz ==0 ? 8 : 2*save_base->sz);
	
	save_base->elem[save_base->sz] = t;
	++save_base->sz;

}
pvector::push_back(t);
}
int main() {

int** qwe = new int*[250];
ownership_vector<int>q;

for (int i =0; i < 250; ++i) {
qwe[i] = new int(i);
q.push_back(qwe[i],false);
}

for (int i =0; i < 15; ++i)
q.push_back(new int(i*10));

std::allocator<ownership_vector<int>>{}.destroy(&q);
for (int i =0; i < 250; ++i) {
	
std::cout << *qwe[i] << '\n';
}

//std::cout << *qwe << '\n';
//for (auto w : q) std::cout << *w << '\n';

	
	
	char c;
	std::cin >> c;
	
	
}