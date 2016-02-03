#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::find_if;
using std::bind;
using std::size_t;

auto check_size(string const& str, size_t sz)
{
    return str.size() < sz;
}

auto find_first_greater(vector<int> const& v, string const& str)
{
    auto predicate = [&](int i){ return bind(check_size, str, i)(); };
    return find_if(v.cbegin(), v.cend(), predicate);
}

int main()
{
    vector<int> vec{ 0, 1, 2, 3, 4, 5, 6, 7 };
    string str{"123456"};
    auto result = find_first_greater(vec, str);
    if (result != vec.cend())
        cout << *result << endl;
    else
        cout << "Not found" << endl;

    return 0;
}
