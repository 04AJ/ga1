#include "list.h"
node *list::newNode(string data){
      node *new_node = new node;
      new_node->num = data;
      new_node->next = nullptr;
      return new_node;
    }

node *list::addtoend(node* head,string bar){
      
    if (head == nullptr) 
      return newNode(bar);
    else
      head->next=addtoend(head->next, bar);
      return head;
    }

void list::print(node *head ){
       if(head == nullptr)
         return;
       
       cout << head->num <<endl;
         
       print(head->next);
       
    }

node *list::checkbool(node* head,bool b){
    if (head == nullptr){return nullptr;}
      
    
    if(head->dup == b){
      //temp=addtoend(temp, head->num);
      head->num="";
      }
    
      checkbool(head->next,b);
     return head;
    }
