//1 0 1 1 0 1 1 1 0 1 1 1 1 0 1 0
//2D parity
#include <stdio.h>
void main()
{
    int i,j,n;
    int data[8][8];
    printf("                           2D PARITY\n\n\n\n");
    printf("\nEnter the data Block size:  \n");
    scanf("%d",&n);
    clean(data,n);
    printf("\nEnter the Data:\n");
    for(i=0; i<n; i++)
        for (j=0; j<n; j++)
        {
            scanf("%d",&data[i][j]);
        }
    testdata1(data,n);
    columnparity(data,n);
    rowparity(data,n);
}
rowparity(int data[8][8],int n)
{
    int i,j;
    for(i=0; i<=n; i++)
    {
        int count=0;
        for(j=0; j<=n; j++)
        {
            if (data[i][j]==1)
                count++;
        }
        {
            // printf("\n THIS WILL DO THE EVEN PARITY CHECK ! \n");
            if (count%2==0)  //inserting 0 for even number of set bits
                data[i][n]=0;
            else if (count%2!=0)
                data[i][n]=1;
        }
    }
    printf("\nDATA WITH ROW PARITY\n");
    testdata2(data,n);
}
columnparity(int data[8][8],int n)
{
    int i,j;
    for(j=0; j<n; j++)
    {
        int count=0;
        for(i=0; i<n; i++)
        {
            if (data[i][j]==1)
                count++;
        }
        {
            // printf("\n THIS WILL DO THE EVEN PARITY CHECK ! \n");
            if (count%2==0)  //inserting 0 for even number of set bits
                data[n][j]=0;
            else if (count%2!=0)
                data[n][j]=1;
        }
    }
    printf("\nDATA WITH COLUMN PARITY\n");
    testdata2(data,n);
}
void testdata1(int data[8][8],int n)
{
    printf("\nDATA RECEIVED AS:\n");
    int i,j;
    for(i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            printf("%d  ",data[i][j]);
        }
        printf("\n");
    }
}
void testdata2(int data[8][8],int n)
{
    int i,j;
    for(i=0; i<=n; i++)
    {
        for (j=0; j<=n; j++)
        {
            printf("%d  ",data[i][j]);
        }
        printf("\n");
    }
}
void clean(int data[8][8],int n)
{
    printf("\n 5 is used as cleaner value\n");
    int i,j;
    for(i=0; i<=n; i++)
        for (j=0; j<=n; j++)
        {
            data[i][j]=5;
        }
}
