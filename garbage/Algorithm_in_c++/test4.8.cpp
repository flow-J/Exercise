#ifndef stack_h
#define stack_h

#include <iostream>

template<typename Item>
class Stack
{
private:
    struct node;
    {
        Item item; node *next;
        node (Item x, node* t)
          { item = x; next = t; }
    };
    typedef node *link;
    link head;
public:
    Stack(int) { head = 0; }
    int empty() const { return head == 0; }
    void push(Item x) { head = new node(x, head); }
    Item pop()
      { 
          Item v = head->item; link t = head->next;
          delate head; head = t; return v;
      }
};
#endif
