#include <stdio.h>
int h[101];
int n;

void swap(int x,int y)
{
    int t;
    t=h[x];
    h[x]=h[y];
    h[y]=t;
}

void siftdown(int i)
{
    int t,flag=0;
    while( i*2<=n && flag==0 )
    {
        if( h[i] > h[i*2] )
            t=i*2;
        else
            t=i;

        if(i*2+1 <= n)
        {
            if(h[t] > h[i*2+1])
                t=i*2+1;
        }

        if(t!=i)
        {
            swap(t,i);
            i=t;
        }
        else
            flag=1;
    }
}

void creat()
{
    int i;
    for(i=n/2;i>=1;i--)
    {
        siftdown(i);
    }
}

int deletemax()
{
    int t;
    t=h[1];
    h[1]=h[n];
    n--;
    siftdown(1);
    return t;
}

int main()
{
    int i,num;
    scanf("%d",&num);

    for(i=1;i<=num;i++)
        scanf("%d",&h[i]);
    n=num;

    creat();

    for(i=1;i<=num;i++)
        printf("%d ",deletemax());


    getchar();getchar();
    return 0;
}

