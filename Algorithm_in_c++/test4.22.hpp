template <class Item>
class Queue
{
private:
    void deletelist()
    {
        for (link t = head; t != 0; head = t)
          { t = head->next; delete head; }
    }
public:
    Queue(const Queue& rhs)
      { head = 0; *this = rhs; }
    Queue& operator=(const Queue& rhs)
    {
        if (this == &rhs) return *this;
        deletelist();
        link t = rhs.head;
        while (t != 0)
          { put(t->item); t = t->next; }
        return *this;
    }
    Queue& operator+(const Queue& rhs)
    {

    }
    Queue(int);
    Queue(const Queue&);
    Queue& operator=(const Queue&);
    ~Queue() { deletelist(); }
    int empty() const;
    void put(Item);
    Item get();
};
