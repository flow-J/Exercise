#ifndef FIFO_hpp
#define FIFO_hpp

template <typename Item>
class QUEUE
{
public:
    QUEUE(int);
    int empty();
    void put(Item);
    Item get();
private:
    int empty(auto p)
    {  p == null ? true : false; }
};

#endif
