#include <iostream>
#include <vector>
#include <assert.h>

template <typename T, typename C = std::vector<T>>
class stack
{
public:
    using ValueType = T;
    using Container = C;
    using SizeType = typename Container::size_type;


    stack() : c() {}

    bool empty()
    {
        return c.empty();
    }


    SizeType size() const
    {
        return s.size();
    }

    void push(const ValueType& val)
    {
        c.push_back(val);
    }

    void pop()
    {
        assert(!c.empty());
        c.pop_back();
    }

    ValueType& top()
    {
        assert(!c.empty());
        return c.back();
    }

private:
    Container c;
};
