#include <iostream>
/*
struct node
{
    key;
    left;
    right;
};*/

template <typename K, typename D>
class binary_search_tree
{
public:
    using KeyType   = K;
    using DataType  = D;
    using Node      = node<K, D>;
    using sPointer  = std::shared_ptr<Node>;
    using wPointer  = std::weak_ptr<Node>;

/*
    void insert(const KeyType& key, const DataType& data)
    {
        sPointer inserted = std::make_shared<Node>(key, data);
        insert(inserted);
    }
    */

    void insert(sPointer inserted)
    {
        sPointer last = nullptr;
        sPointer curr = root;

        while (curr)
        {
            last = curr;
            curr = (inserted->key < curr->key) ? curr->left : curr->right;
        }

        inserted->parent    = last;
        if (last == nullptr)
            root = inserted;
        else if (inserted->key < last->key)
            last->left  = inserted;
        else
            last->right = inserted;
    }

    void insert_recur(sPointer inserted)
    {
        KeyType key = inserted->key;

        std::function<sPointer(sPointer, sPointer)> find =
            [key, &find](sPointer node, sPointer tracker)->sPointer
            {
                if (node == nullptr)
                        return tracker;
                else
                {
                    sPointer next = key < node->key ? node->left : node->right;
                    return find(next, node);
                }
            };

        sPointer parent;
        inserted->parent    = parent = find(root, nullptr);
        if (parent == nullptr)
            root = inserted;
        else
            (inserted->key < parent->key ? parent->left : parent->right)
                = inserted;
    }


    void inoreder_print() const
    {
        inorder_tree_walk(root);
    }

    void inorder_print_nonrecur() const
    {
        sPointer prev = nullptr;
        sPointer curr = root;
        while (curr)
        {
            if (!curr->left || prev == curr->left)
                curr->print();

            if (prev == curr->parent.lock())
            {
                prev    = curr;
                curr    = curr->left ? curr->left :
                          curr->right ? curr->right : curr->parent.lock();
            }
            else if(prev == curr->left && curr->right)
            {
                prev    = curr;
                curr    = curr->right;
            }
            else
            {
                prev    = curr;
                curr    = curr->parent.lock();
            }
        }
    }










    void inoder_print_nonrecur_with_stack() const
    {
        inorder_tree_walk_nonrecur_with_stack(root);
    }

    void preorder_print() const
    {
        preorder_tree_wale(root);
    }

    void postorder_print() const
    {
        postorder_tree_walk(root);
    }

    sPointer search_recur(const KeyType& key) const
    {
        return search_recur(root, key);
    }

    sPointer search_itera(const KeyType& key) const
    {
        return search_itera(root, key);
    }

    sPointer maximum_itera(sPointer node) const
    {
        while (node->right)
            node = node->right;
        return node;
    }

    sPointer maximum_recur(sPointer node) const
    {
        std::function<sPointer(sPointer)> maximum =
            [&maximum](sPointer node)->sPointer
            {
                if (node->right)
                    return maximum(node->right);
                else
                    return node;
            };
        return maximum(node);
    }



    sPointer successor(sPointer node) const
    {
        if (node->right)
            return minimum_itera(node->right);
        else
        {
            sPointer up = node->parent.lock();
            while (up && node == up->right)
            {
                node = up;
                up = up->parent.lock();
            }
            return up;
        }
    }

    sPointer predecessor(sPointer node) const
    {
        if (node->left)
            return maximum_itera(node->left);
        else
        {
            sPointer up = node->parent.lock();
            while (up && node == up->left)
            {
                node = up;
                up   = up->parent.lock();
            }
            return up;
        }
    }

    void remove(sPointer target)
    {
        if (!target->left)
            transplant(target, target->right);
    }




























    inorder()
    {}

    search(tree, k)
    {
        if (tree == nullptr || k == tree.key)
        {
            return tree;
        }
        if (k < tree)
    }

private:
        
    void inorder_tree_walk(sPointer node) const
    {
        if (node)
        {
            inorder_tree_walk(node->left);
            node->print();
            inorder_tree_walk(node->right);
        }
    }
};

inline operator <<(ostream& os, val)
{
    std::cout << val.
}
