#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

struct node
{
    node *next;
    bool dup;
    int num;
    char c;
    node(){};
    node(int n)
    {
        num = n;
        dup = false;
        next = nullptr;
        c = ' ';
    }
};

class list
{
private:
    node *head;

public:
    list() { head = nullptr; };

    // ALL FUNCTIONS ARE RECURSIVE
    node *getHead() { return head; };
    void msort(node **);
    node *merge(node *, node *);
    bool duplicate(node *);
    void print(node *head, ofstream &output, bool answer);
    void addtoend();
    bool push(char c);
    char pop();
    node *peek();
    bool isEmpty() { return head == nullptr; }
};

#endif
