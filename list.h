#include <iostream>
using namespace std;

struct node {
    node* next;
    int num;
    char c;

    node() {};
    node(int n){num=n; next=nullptr; c=' ';}
};


// class list{
// private:
// 	node* head;
// public:
// 	//ALL FUNCTIONS ARE RECURSIVE
//  list();
// 	void print(node* head, ofstream &output, bool answer);
// 	void addtoend();
// 	bool duplicate();
// 	bool push(char);
//  char pop();
// 	node* peek();
// };



class list{
private:
	node* head;
public:
	//ALL FUNCTIONS ARE RECURSIVE
    list() {head = nullptr;};
	void print(node* head, ofstream &output, bool answer);
	void addtoend();
	bool duplicate();


    bool push(char c) {
        node *tmp = new node();
        tmp->c = c;
        tmp->next = head;
        head = tmp;
        return true;
    }


    char pop() {
        if (head != nullptr) {
            node *tmp = head;
            head = head->next;
            char c = tmp->c;
            delete tmp;
            return c;
        }
        return ' ';
    }

    node* peek(){
        return head;
    }

    bool isEmpty () {return head == nullptr;}
};
