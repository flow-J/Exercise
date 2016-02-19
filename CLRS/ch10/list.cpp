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

template <typename T>
class double_list
{
public:
    using ValueType = T;
    using Node      = node<ValueType>;
    using sPointer  = std::shared_ptr<Node>;
    using wPointer  = std::weak_ptr<Node>;
    using SizeType  = std::size_t;

    double_list() = default;

    ValueType& operator[](SizeType index) const
    {
        assert(index < size());

        SizeType count = 0;
        sPointer ptr = head;
        while (count++ != index)
            ptr = ptr->next;

        return ptr->key;
    }

    double_list<ValueType>& operator +(double_list<ValueType>& rhs)
    {
        if (rhs.empty)
            return *this;
        else
        {
            if (this->empty())
                return rhs;
            else
            {
                sPointer tail   = this->tail();

                tail->next      = rhs.head;
                rhs.head->prev  = tail;

                return *this;
            }
        }
    }

    void insert(const ValueType& val)
    {
        sPointer inserted = std::make_shared<Node>(val);

        inserted->next = head;

        if (!empty())
            head->prev = inserted;

        head = inserted;
    }

    SizeType size() const
    {
        SizeType size = 0;
        sPointer ptr = head;
        while (ptr != nullptr)
        {
            ++size;
            ptr = ptr->next;
        }

        return size;
    }

    sPointer search(const ValueType& key) const
    {
        sPointer ret = head;
        while (ret != nullptr && ret->key != key)
            ret = ret->next;
        return ret;
    }

    const sPointer& begin() const
    {
        return head;
    }

    bool empty() const
    {
        return head == nullptr;
    }

    void remove(sPointer target)
    {
        assert(target != nullptr);

        if (target->prev.lock() != nullptr)
            target->prev.lock()->next = target->next;
        else
            head = target->next;

        if (target->next != nullptr)
            target->next->prev = target->prev;
    }

private:
    sPointer head = nullptr;

    sPointer tail() const
    {
        if (empty())
            return head;
        else
        {
            sPointer ret = head;
            while (ret->next != nullptr)
                ret = ret->next;

            return ret;
        }
    }
};

template <typename T>
inline std::ostream& operator <<(std::ostream& os, const double_list<T>& l)
{
    using sPointer = typename double_list<T>::sPointer;

    sPointer ptr = l.begin();
    while (ptr != nullptr)
    {
        os << ptr->key << std::endl;
        ptr = ptr->next;
    }

    return os;
}
