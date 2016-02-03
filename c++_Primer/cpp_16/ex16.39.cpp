template <typename T>
auto compare(T const& v1, T const& v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return  1;
}

int main()
{
    compare<string>(v1, v2);
}
