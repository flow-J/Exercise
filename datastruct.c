/*include <stdio.h>
int main()
{
    int a[1001], n, i, t;
    for(i=1;i<=1000;i++)
        a[i]=0;//initialization

    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&t);
        a[t]=1;
    }

    for(i=1;i<=1000;i++)
    {
        if(a[i]==1)
            printf("%d ",i);
    }


    getchar();getchar();
    return 0;
*/


/*
#include <stdio.h>
int main()
{
    int a[101], n, i, j, t;

    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }


    for(i=1;i<=n-1;i++)
    {
        for(j=1;j<=n-i;j++)
        {
            if(a[j]>a[j+1])
            {   t=a[j]; a[j]=a[j+1]; a[j+1]=t;    }
        }
    }

    printf("%d ",a[1]);
    for(i=2;j<=n;i++)
    {
        if( a[i] != a[i-1] )
            printf("%d ",a[i])
    }
]
    getchar();getchar();
    return 0;

*************/

/*

#include <stdio.h>

int main()
{
    int number[102]={0, 6, 3, 1 ,7, 5, 8, 9, 2, 4},head,tail;
    int i;
    head=1;
    tail=10;
    while(head<tail)
    {
        printf("%d ",number[head]);
        head++;
    

    number[tail]=number[head];
    tail++;

    head++;
    }

    getchar();getchar();
    return 0;
}

**********************/


/*

#include <stdio.h>
struct queue
{
    int data[100];
    int head;
    int tail;
};

int main()
{
    struct queue q;
    int i;

    q.head=1;
    q.tail=1;
    for(i=1;i<=9;i++)
    {
        scanf("%d",&q.data[q.tail]);
        q.tail++;

    }

    while(q.head<q.tail)
    {
        printf("%d ",q.data[q.head]);
        q.head++;

        q.data[q.tail]=q.data[q.head];
        q.tail++;

        q.head++;
    }

    getchar();getchar;
    return 0;
}
*/



#include <stdio.h>
#include <string.h>
int main()
{
    char a[101],s[101];
    int i,len,mid,next,top;

    gets(a);
    len=strlen(a);
    mid=len/2-1;

    top=0;
    for(i=0;i<=mid;i++)
        s[++top]=a[i];

    if(len%2==0)
        next=mid+1;
    else
        next=mid+2;

    for(i=next;i<=len-1;i++)
    {
        if(a[i]!= s[top])
            break;

        top--;

    }

    if(top==0)
        printf("YES");
    else
        printf("NO");

    getchar();getchar();
    return 0;
}




























































































