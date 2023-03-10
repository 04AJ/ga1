#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

struct node
{
    node *next;
    bool dup;
    string id;
    int num;
    char c;
    node(){};
    node(string n)
    {
        id = n;
        num = stoi(n);
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

    node *getHead() { return head; };
    void msort(node **);
    node *merge(node *, node *);
    void duplicate(node *);
    bool innocent(node *);
    bool guilty(node *);
    string print(node *head);
    node *checkbool(node *head, bool b);
    node *addtoend(node *head, string bar);
    bool push(char c);
    char pop();
    node *peek();
    bool isEmpty() { return head == nullptr; }
    void addend(char c);
};

#endif
