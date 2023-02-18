#include <iostream>
using namespace std;

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
    void addtoend();
    void msort();
    // for each node assign node->duplicate value and delete them(?)
    void duplicate();
};
