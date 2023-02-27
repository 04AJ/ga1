#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

struct node
{
    node *next;
    bool dup;
    string num;
    string snum;
    char c;
    node(){};
    node(string n)
    {
        num = n;
        snum = n;
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
    void duplicate(node *);
    bool innocent(node *);
    bool guilty(node *);
    void print(node *head, ofstream &output, bool answer);
    node *checkbool(node *head, bool b);
    node *addtoend(node *head, string bar);
    void print(node *head);
    bool push(char c);
    char pop();
    node *peek();
    bool isEmpty() { return head == nullptr; }
};

#endif
