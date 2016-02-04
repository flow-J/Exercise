#include <iostream>

using namespace std;

int main()
{
    int i, j, adj[v][v];
    for (i = 0; i < v; i++)
        for (j = 0; j < v; j++)
            adj[i][j] = 0;
    for (i = 0; i < v; i++) adj[i][i] = 1;
    while (cin >> i >> j)
    { adj[i][j] = 1; adj[j][i] = 1; }
}
