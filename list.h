#include <iostream>
using namespace std;

struct node {
    node *next;
    int num;
    char c;
    bool dup;
    node() {};
    node(int n){num=n; next=nullptr; c=' ';}
};


class list{
private:
    node *head;

public:
	//ALL FUNCTIONS ARE RECURSIVE
    list() {head = nullptr;};
	void print(node* head, ofstream &output, bool answer);
	void addtoend();
	bool duplicate(node *head);
    bool push(char c);
    char pop();
    node* peek();
    bool isEmpty () {return head == nullptr;}
};
