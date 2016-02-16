#include <iostream>
#include <functional>
/*
template <typename T>
insertionSort(T t)
{
    int key = 0; i = 0;
    for (int j = 0; j < t.size(); ++j)
    {
        int key = a[j];
        i = j - 1;
        while (i > 0 && t[i]>key)
        {
            t[i+1] = t[i];
            i = i - 1;
        }
        t[i+1] = key;
    }
}*/
namespace clrs
{
    namespace ch02
    {
        template <typename Container, typename CompareFunc = std::greater<typename Container::value_type>>
        void insertion_sort(Container& seq)
        {
            if (seq.size() <= 1) return ;
        
            CompareFunc compare;
            for (int i = 1; i != seq.size(); ++i)
            {
                auto key = seq[i];
                auto j = i - 1;
                while (j >= 0 && compare(seq[j], key))
                {
                    seq[j+1] = seq[j];
                    --j;
                }
                seq[j + 1] = key;
            }
        }
    }
}
