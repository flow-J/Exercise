#include <functional>
#include "../iterator.hpp"

namespace clrs
{
    namespace ch06
    {
        template <typename Iter>
        inline Iter parent(Iter first, Iter curr)
        {
            return first + (curr - first - 1) / 2;
        }

        template <typename Iter>
        inline Iter left(Iter first, Iter curr)
        {
            return first + 2 * (curr - first) + 1;
        }

        template <typename Iter>
        inline Iter right(Iter first, Iter curr)
        {
            return first + 2 * (curr - first) + 2;
        }


       template<typename Iter, typename Comp = std::greater<IterValue<Iter> > >
       void heapify(Iter first, Iter last, Iter curr, Comp&& compare = Comp())
       {
            //! left and right child
            Iter l = left(first, curr), r = right(first, curr);
        
            //! find the max or min depending on Comp object
            auto largest = (l < last    &&  compare(*l, *curr))?    l   :   curr;
            if(r < last     &&  compare(*r, *largest))
                largest = r;
        
            //! recur
            if(largest != curr)
            {
                std::swap(*largest, *curr);
                heapify(first, last, largest, compare);
            }
        }

/****************************************************************************************/


        template <typename Iter, typename Comp = std::greater<IterValue<Iter>>>
        void heapify_itera(Iter first, Iter last, Iter curr, Comp&& compare = Comp())
        {
            for (;;)
            {
                Iter l = left(first, curr);
                Iter r = right(first, curr);

                auto max_min = (l < last && compare(*l, *curr)) ? l : curr;
                if (r < last && compare(*r, *max_min))
                    max_min = r;

                if (max_min != curr)
                {
                    std::swap(*max_min, *curr);
                    curr = max_min;
                }
                else break;
            }
        }
        
        template <typename Iter, typename Comp = std::greater<Iter>>
        inline void
        build_heap(Iter first, Iter last, Comp&& compare = Comp())
        {
            auto size = last - first;
            for (auto curr = first + size/2 - 1; curr != first - 1; --curr)
                heapify(first, last, curr, compare);
        }
    }
}

