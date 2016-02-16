#include <iostream>

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
}

template <typename Container, typename CompareFunc = std::greate<typename Container::value_type>>
void insertion_sort(Container& seq)
