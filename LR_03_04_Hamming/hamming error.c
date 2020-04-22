#include<stdio.h>
void main()
{
    int data1[5], data2[5];
    int i,count=0;
    for(i=0; i<5; i++)
        scanf("%d",&data1[i]);
    printf("\nEnter 2nd string");
    for(i=0; i<5; i++)
        scanf("%d",&data2[i]);
    printf("\ninput data1:\n");
    for(i=0; i<5; i++)
        printf("%d",data1[i]);
    printf("\ninput data2:\n");
    for(i=0; i<5; i++)
        printf("%d",data2[i]);
    for(i=0; i<5; i++)
        if(data1[i]!=data2[i])
            count++;
    printf("\n HD= %d",count);

}
