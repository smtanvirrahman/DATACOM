#include<stdio.h>
int main (){
char a[20]={'1','0','1','0','1','1','1','1','0','1','1','1','0','1','1','1','1','1','0','0','\0'};
int i;
printf("\n input data:\n");
for(i=0;i<20;i++)
    printf("%c",a[i]);
char b[21];
for(i=0;i<20;i++)
    b[i]=a[i];
printf("\ntest for result data:\n");
   for(i=0;i<20;i++)
    printf("%c",b[i]);
    printf("\n\n");
    printf("THE DATA AFTER BIT STUFFING\n:");
int j,k=0,count=0;
for(i=0;i<21;i++)
{
    if (a[i]=='0')
        printf("%c",b[i]);
    if(b[i]=='1')
{ printf("%c",b[i]);
   count=1;
    //printf("%d",count);
for(j=1;j<5;j++)
{     if(b[i+j]=='1')
        count++;
   //printf("%c",b[i+j]);
}
 //printf("%d",count);

if (count==5)
{
   //b[i+5]='0';
   printf("0");      //printf("%d",count);
   //printf("\n  5 consecutive 1's found \n");
}
}
//else  b[k]=a[i];
}
return 0;
}
