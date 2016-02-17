#include <iterator>
#include <vector>
#include <algorithm>
namespace clrs
{
    template <typename Iter>
    using IterValue = typename std::iterator_traits<Iter>::value_type;
}

namespace clrs
{
    namespace ch04
    {
        template <typename Iter>
        struct Record
        {
            Iter first;
            Iter last;
            clrs::IterValue<Iter> sum;
        };


        template <typename Iter>
        inline bool
        operator >=(const Record<Iter>& lhs, const Record<Iter>& rhs)
        {
            return lhs.sum >= rhs.sum;
        }

        template <typename Iter>
        inline bool
        operator <(const Record<Iter>& lhs, const Record<Iter>& rhs)
        {
            return lhs.sum < rhs.sum;
        }


        template<typename Iter>
        Record<Iter>
        find_max_crossing_subarray(Iter first, Iter mid, Iter last)
        {
            auto left_sum = *(mid - 1);
            IterValue<Iter> sum = 0;
            auto max_left = mid - 1;
            for (auto l = mid - 1; l != first - 1; --l)
            {
                sum += *l;
                if (sum > left_sum)
                {
                    left_sum = sum;
                    max_left = l;
                }
            }

            auto right_sum = *mid;
            sum = 0;
            auto max_right = mid;
            for (auto r = mid; r != last; ++r)
            {
                sum += *r;
                if (sum > right_sum)
                {
                    right_sum = sum;
                    max_right = r;
                }
            }

            return { max_left, max_right, left_sum + right_sum };
        }


            /*************************************************************************************************************************/

            template <typename Iter>
            Record<Iter> find_max_subarray_linear(Iter first, Iter last)
            {
                using Vec = std::vector<Record<Iter>>;
                Vec v(last - first);
                v[0] = {first, first + 1, *first};
                for (typename Vec::size_type curr = 1; curr != v.size(); ++curr)
                {
                    if (v[curr - 1].sum <= 0)
                        v[curr] = 
                        {
                            first + curr,
                            first + curr + 1,
                            *(first + curr)
                        };
                    else
                        v[curr] = 
                        {
                            v[curr  - 1].first,
                            first + curr + 1,
                            v[curr - 1].sum + *(first + curr)
                        };
                }

                return *std::max_element(v.begin(), v.end());
            }
    }
}
