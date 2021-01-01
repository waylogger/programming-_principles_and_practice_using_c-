


template <typename Elem>
struct Link
{
Link* prev;
Link* succ;
Elem val;
};


template <typename Elem>
struct list
{
class iterator;

iterator begin();
iterator end();

iterator insert (iterator p, const Elem& v);
iterator erase(iterator p);

void push_back(Elem& e);
void push_front(Elem& e);

void pop_back();
void pop_front();

Elem& front();
Elem& bach();
public:
list() {}



};

template <typename Elem>
class list<Elem>::iterator
{
Link<Elem>* curr;
public:
iterator(Link<Elem>* p) : curr(p) {}

iterator& operator++() {curr = curr->succ; return *this;}
iterator& operator--() {curr = curr->prev; return *this;}

Elem& operator*() {return curr->val;}

bool operator==(const iterator& b)
{return curr == b.curr;}
bool operator!=(const iterator& b)
{return curr != b.curr;}
};




int main()

{
list<int>g;
return 0;
}

