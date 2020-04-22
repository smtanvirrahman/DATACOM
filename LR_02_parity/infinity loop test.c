#include<stdio.h>
void main()
{
    char ch,om;
    int p,i,noise;
    for(;;)
    {
        printf("\n Press any key to continue or Enter 'X' to Exit\n");
        scanf("%c%c",&ch,&om);
        //scanf("%c",&cn); // double %c is to omit the null character input
        //printf("ch= %c om= %c",ch,om);

          if(ch=='X'||ch=='x')
        {
            printf("THANK YOU FOR TESTING THIS CODE\n");
            break;
        }
      else
        {
            printf("\nSENDER'S PART\n");
            }
    }
}
