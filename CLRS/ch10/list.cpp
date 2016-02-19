#include <iostream>
#include <memory>
#include <assert.h>

template <typename T>
struct node;

template <typename T>
class double_list;

template <typename T>
struct node
{
    using ValueType = T;
    using sPointer  = std::shared_ptr<node<ValueType>>;
    using wPointer  = std::weak_ptr<node<ValueType>>;

    explicit node(const ValueType& val)
        : key(val), prev(), next(nullptr)
    {}

    ValueType   key;
    wPointer    prev;
    sPointer    next;
};


