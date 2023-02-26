#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

/*
DON'T FORGET TO DELETE PRINT AND ADD FUNCTION*/
struct node
{
    node *next;
    int num;
    bool duplicate;
    node();
    node(int n)
    {
        num = n;
        next = nullptr;
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
    // for each node assign node->duplicate value and delete them(?)
    void duplicate();
};

#endif
