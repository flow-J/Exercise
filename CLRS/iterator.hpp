#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iterator>

namespace clrs 
{
    template <typename Iter>
    using IterValue = typename std::iterator_traits<Iter>::value_type;
}

#endif
