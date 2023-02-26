#include "list.h"


bool list::push(char c) {
    node *tmp = new node();
    tmp->c = c;
    tmp->next = head;
    head = tmp;
    return true;
}


char list::pop() {
    if (head != nullptr) {
        node *tmp = head;
        head = head->next;
        char c = tmp->c;
        delete tmp;
        return c;
    }
    return ' ';
}

node* list::peek(){
    return head;
}
