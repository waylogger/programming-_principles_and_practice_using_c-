
#include <iostream>
#include <vector>
using namespace std;

struct Node{
	Node* n;
	Node* p;
};

struct Message{
	double s;
	int c;
	//vector<int>q;
	
};

int main(){


for (int i =0; i < 50; ++i){
	Message* a = new Message{};
	cout << a << '\t' << sizeof(Message{}) << '\n';
	Node* n1 = new Node{};
	cout << n1 << '\t' << sizeof(Node{}) << '\n';
	delete a;
	Node* n2 = new Node{};
	cout << n2 << '\t' << sizeof(Node{}) << "\n\n";

}



	char c;
	std::cin >> c;
	
}