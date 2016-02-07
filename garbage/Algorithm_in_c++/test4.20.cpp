#include <iostream>
#include "FIFO.hpp"
#include <stdlib.h>

using namespace std;
static const int M = 4;

int main(int argc, char *argv[])
{
    int N = atoi(argv[1]);
    QUEUE<int> queues[M];
    for (int i = 0; i < N; i++, cout << endl)
    {
        int in = rand() % M, out = rand() % M;
        queues[in].put(i);
        cout << i << " in ";
        if (!queues[out].empty())
            cout << queues[out].get() << " out";
        cout << endl;
        for (int k = 0; k < M; k++, cout << endl)
        {
            QUEUE<int> q = queues[k];
            cout << k << ": ";
            while (!q.empty())
                cout << q.get() << " ";
        }
    }
}
