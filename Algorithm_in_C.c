/*#include<stdio.h>
int main()
{
    int a[11], i, j, t;
    for(i=0;i<=10;i++)
        a[i]=0;//read in i and make i be zero

    for(i=1;i<=5;i++)  //read in 5 number
    {
        scanf("%d", &t); // scanf number in t
        a[t]++;
    }

    for(i=10;i>=0;i--)
        for(j=1;j<=a[i];j++)
            printf("%d ",i);

    getchar();getchar();
    return 0;
}
*/

/*
#include<stdio.h>

int main()
{
    int book[1001],i,j,t,n;
    for(i=0;i<=1000;i++)
        book[i]=0;
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
        scanf("%d", &t);
        book[t]++;
    }
    for(i=1000;i>=0;i--)
        for(j=1;j<=book[i];j++)
            printf("%d ",i);

    getchar();getchar();
    return 0;
*/

/*
#include <stdio.h>

int main()
{
    int a[100], i, j, t, n;
    scanf("%d", &n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    

    for(i=1;i<=n-1;i++)
    {
        for(j=1;j<=n-i;j++)

        {
            if(a[j]<a[j+1])
            {  t=a[j]; a[j]=a[j+1]; a[j+1]=t;  }

        }
    }

    for(i=1;i<=n;i++)
        printf("%d ",a[i]);

    getchar();getchar();
    return 0;

}

*/

/*


#include <stdio.h>

struct student
{
    char name[21];
    char score;
};

int main()
{
    struct student a[100],t;
    int i, j, n;
    scanf("%d", &n);
    for(i=1;i<=n;i++)
        scanf("%s %d",a[i].name,&a[i].score);


    for(i=1;i<=n-1;i++)
    {
        for(j=1;j<=n-1;j++)
        {
            if(a[j].score<a[j+1].score)
            {   t=a[j]; a[j]=a[j+1]; a[j+1]=t;  }
        }
    }

    for(i=1;i<=n;i++)
        printf("%s\n",a[i].name);

    getchar();getchar();
    return 0;
}
*/

/*
#include <stdio.h>
int a[101], n;

void quicksort(int left,int right)
{
    int i,j,t,temp;
    if(left>right)
        return;

    temp=a[left];
    i=left;
    j=right;
    while(i!=j)
    {
        while(a[j]>=temp && i<j)
            j--;
        while(a[i]<=temp && i<j)
            i++;

        if(i<j)
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }

    a[left]=a[i];
    a[i]=temp;

    quicksort(left,i-1);
    quicksort(i+1,right);

}

int main()
{
    int i,j,t;
    
    scanf("%d", &n);
    for(i=1;i<=n;i++)
        scanf("%d", &a[i]);

    quicksort(1,n);

    for(i=1;i<=n;i++)
        printf("%d ", a[i]);

    getchar();getchar();
    return 0;
}
*/
















































































































