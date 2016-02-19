#include <memory>

template <typename K, typename D>
struct node
{
    using KeyType   = K;
    using DataType  = D;
    using sPointer  = std::shared_ptr<node<K, D>>;
    using wPointer  = std::weak_ptr<node<K, D>>;

    explicit node(const KeyType& k, const DataType d):
        key(k), data(d), prev(), next(nullptr)
    {}

    KeyType     key;
    DataType    data;
    wPointer    prev;
    sPointer    next;
};


