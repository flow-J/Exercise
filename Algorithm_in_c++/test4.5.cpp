#include "stack.h"
#include <iostream>
#include <string.h>

int main(int argc, char *argv[])
{
    char *a = argv[1]; int N = strlen(a);
    Stack<int> save(N);
    for (int i = 0; i < N; i++)
    {
        if (a[i] == '+')
            save.push(save.pop() + save.pop());
        if (a[i] == '*')
            save.push(save.pop() * save.pop());

    }

}
