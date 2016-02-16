namespace clrs
{
    namespace ch02
    {
        template <typename Container>
        void bubble_sort(Container& seq)
        {
            int i, j;
            auto len = seq.size();
            for (i = 1; i < len - 1; ++i)
                for (j = len; j > (i + 1); --j)
                {
                    if (seq[j] < seq[j-1])
                        swap(seq[j], seq[j-1]);
                }
        }
    }
}
