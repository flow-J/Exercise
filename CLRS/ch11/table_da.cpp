#include "node.cpp"
#include <vector>

template <typename K, typename D>
class table_da
{
public:
    using SizeType  = K;
    using KeyType   = K;
    using DataType  = D;
    using Node      = node<K, D>;
    using sPointer  = std::shared_ptr<Node>;
    using wPointer  = std::weak_ptr<Node>;
    using Container = std::vector<sPointer>;

    table_da() = delete;

    table_da(SizeType sz):
        container(sz)
    {}

    DataType& search(const KeyType& key)
    {
        return container[key]->data;
    }

    void insert(const KeyType& key, const DataType& data)
    {
        container[key] = std::make_shared<Node>(key, data);
    }

    void remove(const KeyType &key)
    {
        container[key] = nullptr;
    }
private:
    Container container;
};
