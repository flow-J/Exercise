/****************
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
    int i,t;

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
            while(s.data[s.top]!=t)
            {
                book[s.data[s.top]]=0;
                q1.data[q1.tail]=s.data[s.top];
                q1.tail++;
                s.top--;
            }
        
        }

        t=q2.data[q2.head];

        if(book[t]==0)
        {
            q2.head++;
            s.top++;
            s.data[s.top]=t;
            book[t]=1;
        }
        else
        {
            q2.head++;
            q2.data[q2.tail]=t;
            q2.tail++;
            while(s.data[s.top]!=t)
            {
                book[s.data[s.top]]=0;
                q2.data[q2.tail]=s.data[s.top];
                q2.tail++;
                s.top--;
            }
        }
    }

    if(q2.head==q2.tail)
    {
        printf("HengWin\n");
        printf("Heng_car_now_is");
        for(i=1;i<=s.top;i++)
            printf(" %d",s.data[i]);
    }
    else
    {
        printf("HaWin\n");
        printf("Ha's card is");
        for(i=q2.head;i<=q2.tail-1;i++)
            printf(" %d",q2.data[i]);
        if(s.top>0)
        {
            printf("\nthe card on the table is ");
            for(i=1;i<=s.top;i++)
                printf(" %d",s.data[i]);
        }
        else
            printf("\n there is no card");

    }

    getchar();getchar();
    return 0;

}




*/


/*
#include <stdio.h>
int main()
{
    char a[20][21];
    int i, j,sum,map=0,p,q,x,y,n,m;

    scanf("%d %d",&n,&m);

    for(i=0;i<=n-1;i++)
        scanf("%s",a[i]);

    //double for to find point in the map
    for(i=0;i<=n-1;i++)
    {
        for(j=0;j<=m-1;j++)
        {
            //make suer the point is not a ground, only ground can have a boom.
            if(a[i][j]=='.')
            {
                sum=0;

                x=i; y=j;
                while(a[x][y]=='G')
                    sum++;
                x--;

            

                x=i; y=j;
                while(a[x][y]!='#')
                {
                    if(a[x][y]=='G')
                        sum++;
                    x++;
                }
                
                x=i; y=j;
                while(a[x][y]!='#')
                {
                    if(a[x][y]=='G')
                        sum++;
                    y--;
                }
    
                x=i; y=j;
                while(a[x][y]!='#')
                {
                    if(a[x][y]=='G')
                        sum++;
                    y++;
                }

               if(sum>map)
                {
                    map=sum;
                    p=i;
                    q=j;
                }
            }
        }
    }

    printf("drop the boom on (%d,%d), can kill %d people\n",p,q,map);
    getchar();getchar();
    return 0;
}

*/


/*





#include <stdio.h>
int fun(int x)
{
    int num=0;
    int f[10]={6,2,5,5,4,5,6,3,7,6};

    while(x/10!=0)
    {
        num += f[x%10];
        x = x/10;
    }

    num += f[x];
    return num;
}

int main()
{
    int a,b,c,m,i,sum=0;
    scanf("%d",&m);

    for(a=0;a<=1111;a++)
    {
        for(b=0;b<=1111;b++)
        {
            c=a+b;

            if(fun(a)+fun(b)+fun(c)==m-4)
            {
                printf("%d+%d=%d\n", a,b,c);
                sum++;
            }
        }
    }

    printf("can spell out %d different equation", sum);
    getchar();getchar();
    return 0;
}




*/








/*











#include <stdio.h>
int a[10],book[10],n;

void dfs(int step)
{
    int i;
    if(step==n+1)
    {
        for(i=1;i<=n;i++)
            printf("%d",a[i]);
        printf("\n");

        return;
    }

    for(i=1;i<=n;i++)
    {
        if(book[i]==0)
        {
            a[step]=i;
            book[i]=1;

            dfs(step+1);
            book[i]=0;


        }
    }
    return;
}

int main()
{
    scanf("%d",&n);
    dfs(1);
    getchar();getchar();
    return 0;
}

*/

/*

#include <stdio.h>
int a[10],book[10],total=0;
void dfs(int step)
{
    int i;
    if(step==10)
    {
        if(a[1]*100+a[2]*10+a[3]+a[4]*100+a[5]*10+a[6]
                ==a[7]*100+a[8]*10+a[9])
        {
            total++;
            printf("%d%d%d+%d%d%d=%d%d%d\n",
                    a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
        }
        return;

    }

    for(i=1;i<=9;i++)
    {
        if(book[i]==0)
        {
            a[step]=i;
            book[i]=1;

            dfs(step+1);

            book[i]=0;
        }
    }
    return;
}

int main()
{
    
    dfs(1);

    printf("total=%d",total/2);
    getchar();getchar();
    return 0;

}
*/
/*


#include <stdio.h>
int n,m,p,q,min=99999999;
int a[51][51],book[51][51];
void dfs(int x,int y,int step)
{
    int next[4][2] = {{ 0, 1},//right
                        { 1, 0},//down
                        { 0, -1},//left
                        {-1, 0}};//up

    int tx,ty,k;

    if(x==p && y==q)
    {
        if(step<min)
            min=step;
        return;
    }

    for(k=0;k<=3;k++)
    {
        tx=x+next[k][0];
        ty=y+next[k][1];
        
        if(tx<1 || tx>n || ty<1 || ty>m)
            continue;

        if(a[tx][ty]==0 && book[tx][ty]==0)
        {
            book[tx][ty]=1;
            dfs(tx,ty,step+1);
            book[tx][ty]=0;
        }

    }
    return ;

}

int main()
{
    int i,j,startx,starty;
    scanf("%d %d",&n,&m);//n = x, m = y;

    //read in map
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&a[i][j]); 

    scanf("%d %d %d %d",&startx,&starty,&p,&q);

    book[startx][startx]=1;//the first 

    dfs(startx,starty,0);
    printf("%d", min);
    getchar();getchar();
    return 0;

}
*/
















/*

#include <stdio.h>
struct note
{
    int x;
    int y;
    int f;
    int s;//setps
};

int main()
{
    struct note que[2501];

    int a[51][51]={0},book[51][51]={0};
    int next[4][2] = {  { 0, 1},
                        { 1, 0},
                        { 0,-1},
                        (-1, 0) };

    int head,tail;
    int i,j,k,n,m,startx,starty,p,q,tx,ty,flag;

    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    scanf("%d %d %d %d",&startx,&starty,&p,&q);

    head=1;
    tail=1;

    que[tail].x=startx;
    que[tail].y=starty;
    que[tail].f=0;
    que[tail].s=0;
    tail++;
    book[startx][starty]=1;

    flag=0;

    while(head<tail) 
    {
        for(k=0;k<=3;k++)
        {
            tx=que[head].x+next[k][0];
            ty=que[head].y+next[k][1];

            if(tx<1 || tx>n || ty<1 || ty>m)
                continue;

            if(a[tx][ty]==0 && book[tx][ty]==0)
            {
                book[tx][ty]=1;
                que[tail].x=tx;
                que[tail].y=tx;
                que[tail].f=head;

                que[tail].s=que[head].s+1;
                tail++;
            }

            if(tx==p && ty==q)
            {
                flag=1;
                break;

            }
        }
        if(flag==1)
            break;
        head++;

    }

    printf("%d",que[tail-1].s);

    getchar();getchar();
    return 0;



}
*/






/*

#include <stdio.h>
struct note
{
    int x;
    int y;
};

char a[20][21];

int getnum(int i,int j)
{
    int sum,x,y;
    sum = 0;

    x=i; y=j;
    while(a[x][y]!='#')
    {
        if(a[x][y]=='G')
            sum++;
        x--;
    }

    x=i; y=j;
    while(a[x][y]!='#')
    {
        if(a[x][y]=='G')
            sum++;
        x++;
    }

    x=i; y=j;
    while(a[x][y]!='#')
    {
        if(a[x][y]=='G')
            sum++;
        y--;
    }

    x=i; y=j;
    while(a[x][y]!='#')
    {
        if(a[x][y]=='G')
            sum++;
        y++;
    }
    return sum;
}

int main()
{
    struct note que[401];
    int head,tail;
    int book[20][20]={0};
    int i,j,k,sum,max=0,mx,my,n,m,startx,starty,tx,ty;

    int next[4][2]={ { 0, 1},
        { 1,0},
        { 0,-1},
        {-1,0} };

    scanf("%d %d %d %d",&n,&m,&startx,&starty);

    for(i=0;i<=n-1;i++)
        scanf("%s",a[i]);

    head=1;
    tail=1;

    que[tail].x=startx;
    que[tail].y=starty;
    tail++;
    book[startx][starty]=1;
    max=getnum(startx,starty);
    mx=startx;
    my=starty;

    while(head<tail)
    {
        for(k=0;k<=3;k++)
        {
            tx=que[head].x+next[k][0];
            ty=que[head].y+next[k][1];

            if(tx<0 || tx>n-1 || ty<0 || ty>m-1)
                continue;

            if(a[tx][ty]=='.' && book[tx][ty]==0)
            {
                book[tx][ty]=1;
                que[tail].x=tx;
                que[tail].y=ty;
                tail++;

                sum=getnum(tx, ty);
                //update max value
                if(sum>max)
                {
                    max=sum;
                    mx=tx;
                    my=ty;

                }

            }
        }
        head++;
    }
    printf("when boom on the (%d,%d), can kill %d people\n",mx,my,max) ;

    getchar();getchar();
    return 0;

}
*/






















/*

#include <stdio.h>
char a[20][21];
int book[20][20],max,mx,my,n,m;
int getnum(int i,int j)
{
    int sum,x,y;
    sum=0;

    x=i; y=j;
    while(a[x][y]!='#')
    {
        if(a[x][y]=='G')
            sum++;
        x--;
    }

    x=i; y=j;
    while(a[x][y]!='#')
    {
        if(a[x][y]=='G')
            sum++;
        x++;
    }

    x=i; y=j;
    while(a[x][y]!='#')
    {
        if(a[x][y]=='G')
            sum++;
        y--;
    }

    x=i; y=j;
    while(a[x][y]!='#')
    {
        if(a[x][y]=='G')
            sum++;
        y++;

    }
    return sum;
}

void dfs(int x, int y)
{
    int next[4][2]={ { 0, 1},
        { 1, 0},
        { 0,-1},
        {-1, 0} };
    int k,sum,tx,ty;

    sum=getnum(x,y);

    if(sum>max)
    {
        max=sum;
        mx=x;

    }


    for(k=0;k<=3;k++)
    {
        tx=x+next[k][0];
        ty=y+next[k][1];

        if(tx<0 || tx>n-1 || ty<0 || ty>m-1)
            continue;
        if(a[tx][ty]=='.' && book[tx][ty]==0)
        {
            book[tx][ty]=1;
            dfs(tx,ty);
        }
    }
    return ;
}

int main()
{
    int i,startx,starty;
    scanf("%d %d %d %d",&n,&m,&startx,&starty);

    for(i=0;i<=n-1;i++)
        scanf("%s",a[i]);

    book[startx][starty]=1;
    max=getnum(startx,starty);
    mx=startx;
    my=starty;
    
    dfs(startx,starty);

    printf("when the boom on the(%d,%d),can kill %d human\n",mx,my,max);

    getchar();getchar();
    return 0;
}

*/






#include <stdio.h>
struct note
{
    int x;
    int y;

};

int main()
{
    struct note que[2501];
    int head, tail;
    int a[51][51];

}



























































































