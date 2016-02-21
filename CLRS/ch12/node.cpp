#include <memory>
#include <iostream>

template <typename K, typename D>
struct node
{
    using KeyType   = K;
    using DataType  = D;
    using Node      = node<K, D>;
    using sPointer  = std::shared_ptr<Node>;
    using wPointer  = std::weak_ptr<Node>;

    node() = default;

    explicit node(const KeyType& key):
        data(), key(key), parent(), left(), right(), successor()
    {}

    node(const KeyType& key, const DataType& data):
        data(data), key(key), parent(), left(), right(), successor()
    {}

    void print() const
    {
        std::cout << "key = " << key
                  << " data = " << data
                  << std::endl;
    }

    DataType    data;
    KeyType     key;
    wPointer    parent;
    sPointer    left;
    sPointer    right;

    wPointer    successor;
};
