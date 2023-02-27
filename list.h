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
    void addtoend();
    void msort();
    // for each node assign node->duplicate value and delete them(?)
    void duplicate();
    node *checkbool(node* head,bool b);
    node *newNode(string data);
    node *addtoend(node *head,string bar);
    void print(node *head );
    
};
