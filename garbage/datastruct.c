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

/*

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

*/




/*

#include <stdio.h>
int main()
{
    int a=10;
    int *p;
    p=&a;
    printf("%d",*p);

    getchar();getchar();
    return 0;
}

*/






/*

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *p;
    p=(int *)malloc(sizeof(int));
    *p=10;
    printf("%d",*p);

    getchar();getchar();
}

*/


/*

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head,*p,*q,*t;
    int i,n,a;
    scanf("%d",&n);
    head = NULL;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);

        p=(struct node *)malloc(sizeof(struct node));
        p->data=a;
        p->next=NULL;
        if(head==NULL)
            head=p;
        else
            q->next=p;

        q=p;
    }

    t=head;
    while(t !=NULL)
    {
        printf("%d ",t->data);
        t=t->next;
    }

    getchar();getchar;
    return 0;
}

*/



/*
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head,*p,*q,*t;
    int i,n,a;
    scanf("%d",&n);
    head = NULL;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        p=(struct node *)malloc(sizeof(struct node));
        p->data=a;
        p->next=NULL;
        if(head=NULL)
            head=p;
        else
            q->next=p;

        q=p;
    }

    scanf("%d", &a);
    t=head;
    while(t !=NULL)
    {
        if(t->next->data > a)
        {
            p=(struct node *)malloc(sizeof(struct node));

            p->data=a;
            p->next=t->next;
            t->next=p;
            break;
        }
        t=t->next;
    }

    t=head;
    while(t !=NULL)
    {
        printf("%d ",t->data);
        t=t->next;

    }

    getchar();getchar();
    return 0;

}
*/

#include <stdio.h>
int main()
{
    int data[101],right[101];
    int i,n,t,len;
    
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&data[i]);
    len=n;

    for(i=1;i<=n;i++)
    {
        if(i!=n)
            right[i]=i+1;
        else
            right[i]=0;

    }

    len++;
    scanf("%d",&data[len]);

    t=1;
    while(t!=0)
    {
        if(data[right[t]]>data[len])

        {
            right[len]=right[t];

            right[t]=len;
            break;
        }
        t=right[t];

    }

    t=1;
    while(t!=0)
    {
        printf("%d ",data[t]);
        t=right[t];

    }
    getchar();
    getchar();
    return 0;

}















































































































































































