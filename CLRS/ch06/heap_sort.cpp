#include "heap.cpp"

template <typename Iter>
inline void heap_sort(Iter first, Iter last)
{
    build_heap(first, last);
    for (auto curr = last - 1; curr != first; --curr)
    {
        std::swap(*first, *curr);
        heapify(first, curr, first);
    }
}
