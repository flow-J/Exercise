#include <memory>
#include <iostream>
#include <stack.cpp>

template <typename T>
struct node;

template <typename T>
class binary_tree;

template <typename T>
struct node
{
    using ValueType = T;
    using Node      = node<ValueType>;
    using sPointer  = std::shared_ptr<Node>;
    using wPointer  = std::weak_ptr<Node>;

    node() = default;

    explicit node(const ValueType& val):
        key(val)
    {}

    ValueType   key     = ValueType();
    wPointer    parent;
    sPointer    left    = nullptr;
    sPointer    right   = nullptr;
};

template <typename T>
class binary_tree
{
public:
    using ValueType = T;
    using Node      = node<ValueType>;
    using sPointer  = std::shared_ptr<Node>;
    using wPointer  = std::weak_ptr<Node>;

    void insert(const ValueType& val)
    {
        recur_add(root, val);
    }

    void print_by_recursion() const
    {
        recur_print(root);
    }

    void print_with_prev() const
    {
        checking_prev_print(root);
    }

    void print_with_satck() const
    {
        nonrecur_print(root);
    }
private:
    sPointer root;

    void recur_add(sPointer& current, const ValueType& val, sPointer prev = nullptr)
    {
        if (current == nullptr)
        {
            current = std::make_shared<Node>(val);
            current->parent = prev;
            return ;
        }
        else
        {
            if (current->key > val)
                recur_add(current->left, val, current);
            else
                recur_add(current->right, val, current);
        }
    }

    void recur_print(sPointer node) const
    {
        if (node != nullptr)
        {
            std::cout << node->key << std::endl;
            recur_print(node->left);
            recur_print(node->right);
        }
    }

    void nonrecur_print(sPointer node) const
    {
        if (node)
        {
            stack<sPointer> stack;
            while (!stack.empty())
            {
                sPointer current = stack.top();
                stack.pop();
                std::cout << current->key << std::endl;

                if (current->left)
                    stack.push(current->left);
                if (current->right)
                    stack.push(current->right);
            }
        }
    }

    void checking_prev_print(sPointer node) const
    {
        sPointer prev   = nullptr;
        sPointer current = node;

        while (current)
        {
            if (prev == current->parent.lock())
            {
                std::cout << current->key << std::endl;
                prev = current;

                current = current->left ? current->left : current-> right ? current->right : current->parent.lock();
            }
            else if (prev == current->left && current->right)
            {
                prev = current;
                current = current->right;
            }
            else
            {
                prev = current;
                current = current->parent.lock();
            }
        }
    }
};
