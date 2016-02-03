template <typename Container>
std::ostream& print(Container const& container,std::ostream& os)
{
    for (typename Container::size_type i = 0; i != container.size();++i)
        os << container[i] << " ";
    return os;
}

template <typename Container>
std::ostream &print2(Container const& container, std::ostream &os)
{
    for (auto curr = container.cbegin(); curr != container.cend(); ++curr)
        os << *curr << " ";
    return os;
}
