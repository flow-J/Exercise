#include <vector>
#include <assert.h>


template <typename T, typename C = std::vector<T>>
class queue;

template <typename T>
bool operator ==(const queue<T>& lhs, const queue<T>& rhs);

template <typename T, typename C>
class queue
{
    friend bool operator ==<T>(const queue<T>& ,const queue<T>&);
public:
    using Container = C;
    using Iter      = typename Container::iterator;
    using SizeType  = typename COntainer::size_type;


    explicit queue(std::size_t size): c(size)
    {
        head = tail = c.begin();
    }

    void enqueue(const T& val)
    {
        assert(!full() && "overflow");

        if (tail == c.end())
            tail = increment(tail);

        *tail = val;
        tail = increment(tail);
    }

    T dequeue()
    {
        assert(!empty() && "underflow");

        T ret = *head;
        head = increment(head);

        if (head == c.end())
            head = increment(head);

        return ret;
    }

    bool empty() const
    {
        return head == tail;
    }

    bool full()
    {
        return head == increment(tail);
    }

     SizeType capacity() const
     {
         return c.size();
     }   


     SizeType size() const
     {
         return ( tail >= head) ? tail - head : capacity() - (head - tail);
     }

private:
     Container c;
     Iter head;
     Iter tail;

     Iter increment(Iter iter)
     {
         return (iter == c.end()) ? c.begin() : iter + 1;
     }
};

template <typename T>
inline bool
operator ==(const queue<T>& lhs, const queue<T>& rhs)
{
    return (lhs.c == rhs.c) && (lhs.head == rhs.head) && (lhs.tail == rhs.tail);
}
