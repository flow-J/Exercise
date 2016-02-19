#include <functional>
#include <vector>
#include "node.cpp"
#include <iostream>

template <typename K, typename D>
class hash_table
{
public:
    using SizeType  = K;
    using KeyType   = K;
    using DataType  = D;
    using Node      = node<K, D>;
    using sPointer  = std::shared_ptr<Node>;
    using wPointer  = std::weak_ptr<Node>;
    using Hash      = std::function<K(K)>;
    using Container = std::vector<sPointer>;

    hash_table()    = delete;

    hash_table(const SizeType& sz, const Hash& h):
        hash(h), container(sz, sPointer())
    {}

    void insert(const KeyType& key, const DataType& data)
    {
        sPointer&   head        = container[hash(key)];
        sPointer    inserted    = std::make_shared<Node>(key, data);
        if (!head)
            head = inserted;
        else
        {
            inserted->next  = head;
            head->prev      = inserted;
            head            = inserted;
        }
    }

    sPointer search(const KeyType key)
    {
        sPointer ret = nullptr;
        sPointer curr = container[hash(key)];
        while (curr)
        {
            if (curr->key == key)
            {
                ret = curr;
                break;
            }
        }
        return ret;
    }

    void erase(sPointer target)
    {
        sPointer&   head = container[hash(target->key)];
        sPointer&   next = target->next;
        wPointer&   prev = target->prev;

        if (!next && !prev.lock())
            head = nullptr;
        else if (next && !prev.lock())
        {
            next->prev.reset();
            head = next;
        }
        else if (!next && prev.lock())
            prev.lock()->next = nullptr;
        else
        {
            next->prev = prev;
            prev.lock()->next = next;
        }
    }

    void print() const
    {
        for (const auto& elem : container)
        {
            sPointer curr = elem;
            while (curr)
            {
                std::cout << "key= " << curr->key
                          << " data=" << curr->data
                          << std::endl;
                curr = curr->next;
            }
        }
    }

private:
    Hash    hash;
    Container container;
};

int main()
{
    auto hash = 
        [](const int key)->int
        {
            return key % 9;
        };

    hash_table<int, std::string> table(10, hash);

    table.insert(6, "first try");
    table.erase(table.search(6));

    table.print();
}
