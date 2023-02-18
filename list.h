#include <iostream>
using namespace std;

struct node {
    node* next;
    int num;

    node();
    node(int n){num=n; next=nullptr;}
};


class list{
private:
	node* head;
public:
	//ALL FUNCTIONS ARE RECURSIVE
    list();
	void print(node* head, ofstream &output, bool answer);
	void addtoend();
	bool duplicate();
	
	
};
