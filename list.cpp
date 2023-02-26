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

//make sure dup is set to false by default
bool list::duplicate(node *head){
  if(head == nullptr || head->next == nullptr){
    return false;
  }
  if(head->num == head->next->num){
    node *temp = head->next;
    head->dup = true;
    head->next = head->next->next;
    delete temp;
  }
  return duplicate(head->next);
}
