#include <stdio.h>
struct queue
{
    int data[1000];
    int head;
    int tail;
};

struct stack
{
    int data[10];
    int top;
};

int main()
{
    struct queue q1,q2;
    struct stack s;
    int book[10];

    q1.head=1; q1.tail=1;
    q2.head=1; q2.tail=1;

    s.top=0;
    for(i=1;i<=9;i++)
        book[i]=0;

    for(i=1;i<=6;i++)
    {
        scanf("%d",&q1.data[q1.tail]);
        q1.tail++;
    }

    for(i=1;i<=6;i++)
    {
        scanf("%d",&q2.data[q2.tail]);
        q2.tail++;
    }

    while(q1.head<q1.tail && q2.head<q2.tail)
    {
        t=q1.data[q1.head];

        if(book[t]==0)
        {
            q1.head++;
            s.top++;
            s.data[s.top]=t;
            book[t]=1;
        }
        else
        {
            q1.head++;
            q1.data[q1.tail]=t;
            q1.tail++;
            while
        
        }
    }

}























