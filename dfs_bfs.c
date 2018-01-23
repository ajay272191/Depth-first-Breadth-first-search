#include<stdio.h>
#define SIZE 10
void bfs(int table[SIZE][SIZE],char a[SIZE]);
void dfs(int table[SIZE][SIZE],char a[SIZE]);
int printdfs(int i,int j);
int search(char x);
int n;
char a[SIZE],avail[SIZE];
int table[SIZE][SIZE];
int main()
{

    int i,j,ch;
    printf("how many vertex you want to give\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("give %d vertex\n",i+1);
        scanf(" %c",&a[i]);
    }
    printf("give the edge b/w vertex\n\n");
    printf("is there any egde : 1(yes)/0(no)\n\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
    {
        printf("\nb/w %c & %c\n",a[i],a[j]);
        scanf("%d",&table[i][j]);


    }

    while(1)
    {
            printf("\n1.for bfs\n2.for dfs\n3.for exit\n");
            scanf("%d",&ch);
            switch(ch)
            {
               case 1:  if(n==0)
                        {
                            printf("\nnothing to print\n");
                       exit(0);
                        }
                        bfs(table,a);
                        break;

               case 2:if(n==0)
                        {
                            printf("\nnothing to print\n");
                       exit(0);
                        }
                    dfs(table,a);
                    break;
               case 3:
                exit(0);
                break;
               default:
                printf("plz select right key\n");
            }
    }

}
void bfs(int table[SIZE][SIZE],char a[SIZE])
{
    int i,j;
    char x,y;
   for(i=0;i<n;i++)
    {
        avail[i]=NULL;
    }

    avail[0]=a[0];
    printf("bfs of given graph is\n");
    printf("%c",a[0]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
        if(table[i][j]==1)
            {
                x=a[j];
                y=search(x);
                if(y==0)
                    {
                    printf("%c",a[j]);
                    avail[j]=a[j];
                    }
            }
        }
    }
}
int search(char x)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(avail[i]==x)
            {
            return 1;
        }
    }
    return 0;
}

void dfs(int table[SIZE][SIZE],char a[SIZE])
{
    int i,j;
    char x,y;
    for(i=0;i<n;i++)
    {
        avail[i]=NULL;
    }
    avail[0]=a[0];
    printf("dfs of given graph is\n");
    printf("%c",a[0]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(table[i][j]==1)
            {
                x=a[j];
                y=search(x);
                if(y==0)
                    {
                    printf("%c",a[j]);
                    avail[j]=a[j];
                    printdfs(j,i);
                    }
            }
        }
        }
    }

int printdfs(int i,int j)
{
    char x,y;

    for(i;i<n;i++)
    {
        for(j;j<n;j++)
        {
            if(table[i][j]==1)
            {
                x=a[j];
                y=search(x);
                if(y==1)
                {

                    continue;
                }
                else
                {
                    printf("%c",a[j]);
                    avail[j]=a[j];
                    printdfs(j,i);

                }

            }

        }
        if(table[i][j]==0)
        {
            return ;
        }

    }
}

