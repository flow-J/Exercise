template <class Item>
class Queue
{
private:
public:
    Queue(int);
    Queue(const Queue&);
    Queue& operator=(const Queue&);
    ~Queue();
    int empty() const;
    void put(Item);
    Item get();
};
