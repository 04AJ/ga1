#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

struct node
{
    node *next;
    int num;
    bool dup;
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
    bool duplicate(node *);
    void addtoend(int num)
    {
        if (head == nullptr)
            head = new node(num);
        else
        {
            node *cur = head;
            while (cur->next != nullptr)
                cur = cur->next;
            node *temp = new node(num);
            cur->next = temp;
        }
    }

    void print()
    {
        if (head == nullptr)
            return;
        node *cur = head;
        while (cur != nullptr)
        {
            cout << cur->num << endl;
            cur = cur->next;
        }
    }
};

#endif
