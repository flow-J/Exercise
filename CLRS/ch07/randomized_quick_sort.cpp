#include "quick_sort.cpp"
#include <random>
#include <iterator>
#include <assert.h>

namespace clrs
{
    namespace ch07
    {
        template <typename Iter>
        Iter randomized_partition(Iter first, Iter last);

        template <typename Iter>
        void randomized_quicksort(Iter first, Iter last);

        template <typename Iter>
        inline Iter randmized_partition(Iter first, Iter last)
        {
            assert(last > first);
            static std::default_random_engine e;
            static std::uniform_real_distribution<float> ud(0, 100);

            auto range = last - first;
            Iter pivot = first + ud(e) * range/100;
            std::swap(*pivot, *(last - 1));
            return ch07::partition(first, last);
        }

        template <typename Iter>
        inline void randomized_quicksort(Iter first, Iter last)
        {
            if (last - first > 1)
            {
                Iter pivot = randomized_partition(first, last);
                randomized_quicksort(first, pivot);
                randomized_quicksort(pivot + 1, last);
            }
        }
    }
}
