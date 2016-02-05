#ifndef FIFO_hpp
#define FIFO_hpp

template <typename Item>
class QUEUE
{
public:
    auto Queue(int) { head = 0; }
    int empty()
    {  return head == 0; }
    void put(Item x)
    {
        link t = tail;
        tail = new node(x);
        if (head == 0)
            head = tail;
        else t->next = tail;
    }
    Item get()
      { Item v = head->item; link temp = head ->next;
        delete head; head = temp; return v;}
private:
    struct node
    {
        Item item; node* next;
        node (Item x)
          {item = x; next = 0;}
    };
    typedef node *link;
    link head, tail;
};

#endif
