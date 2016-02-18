#include <algorithm>

namespace clrs
{
    namespace ch07
    {
        template <typename Iter>
        void quick_sort(Iter first, Iter last);

        template <typename Iter>
        Iter partition(Iter first, Iter last);


        template <typename Iter>
        inline void quick_sort(Iter first, Iter last)
        {
            Iter pivot = partition(first, last);
            quick_sort(first, pivot);
            quick_sort(pivot + 1, last);
        }

        template <typename Iter>
        inline Iter partition(Iter first, Iter last)
        {
            Iter pivot = last - 1;
            Iter smaller = first - 1;
            for (Iter iter = first; iter != pivot; ++iter)
            {
                if (*iter <= *pivot)
                {
                    ++smaller;
                    std::swap(*smaller, *iter);
                }
            }
            std::swap(*++smaller, *pivot);
            pivot = smaller;

            return pivot;
        }
    }
}
