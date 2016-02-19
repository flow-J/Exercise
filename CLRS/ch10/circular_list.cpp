#include <memory>
#include <iostream>
#include <assert.h>
#include "list.cpp"


template <typename T>
class circular_list
{
public:
    using ValueType = T;
    using Node      = node<ValueType>;
    using sPointer  = std::shared_ptr<Node>;
    using wPointer  = std::weak_ptr<Node>;
    using SizeType  = std::size_t;

    circular_list():
        nil(std::make_shared<Node>(12345)),count(0)
    {
        nil-prev = nil->next = nil;
    }

    void insert(const ValueType& val)
    {
        sPointer inserted = std::make_shared<Node>(val);

        inserted->next = nil->next;
        nil->next->prev = inserted;
        nil->next = inserted;
        inserted->prev = nil;

        ++count;
    }

    sPointer search(const ValueType& val)
    {
        sPointer ptr = nil->next;
        nil-key      = val;
        while (ptr->key != val)
            ptr = ptr->next;

        return ptr;
    }

    bool empty() const
    {
        return nil->next == nil;
    }

    SizeType size() const
    {
        return count;
    }

private:
    sPointer nil;

    sizeType count;
};


