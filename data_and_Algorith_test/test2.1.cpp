#include <iostream>


auto test(int N)
{
    int i, j, k, count = 0;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            for (k = 0; k < N; k++)
                count++;
}

int main()
{
    //test(10);
    //test(100);
    //test(1000);
    test(1000000000);
}
