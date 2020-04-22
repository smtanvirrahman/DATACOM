#include<stdio.h>
void main()
{
    char ch,om,z;
    int p,i,noise;
    printf("\n\n                                      PARITY CHECKING\n\n                ");
    for(;;)
    {
        printf("\n Press any key to continue or Enter 'X' to Exit:\n");
        scanf("%c%c",&ch,&om); // double %c is to omit the null character input
        //printf("ch= %c om= %c",ch,om);

          if(ch=='X'||ch=='x')
        {
            printf("THANK YOU FOR TESTING THIS CODE\n");
            break;
        }
      else
        {
            printf("\nSENDER'S PART>>>\n\n");
            printf("enter the parity type: (EVEN=1 | ODD=0): ");
            scanf("%d",&p);
            printf("Enter data bits (5 bits word one by one):\n");
            int data[6];
            int count=0;
            for(i=0; i<5; i++)
            {
                scanf("%d",&data[i]);
                if (data[i]==1)
                    count++;
            }
            if (p==1)
            {
                printf("\n THIS WILL DO THE EVEN PARITY CHECK ! \n");
                if (count%2==0)  //inserting 0 for even number of set bits
                    data[5]=0;
                else if (count%2!=0)
                    data[5]=1;
            }
            if (p==0)
            {
                printf("\n THIS WILL DO THE ODD PARITY CHECK ! \n");
                if (count%2==0)  //inserting 1 for even number of set bits
                    data[5]=1;
                else if (count%2!=0)
                    data[5]=0;
            }
            printf("\n the data with parity bit is: \n");
            for(i=0; i<6; i++)
            {
                printf("%d ",data[i]);
            }

            printf("\nDO YOU WANT TO ENTER NOISE IN THE DATA?? (1 for YES /0 for NO)\n");
            scanf("%d",&noise);
            if(noise==1)
            { printf("\n Enter the raw data as noise: \n");
                for(i=0; i<5; i++)
                {
                    scanf("%d",&data[i]);
                }
            }
            if(noise==0)
            {

            }

            printf("\nRECIEVER'S PART\n");
            {
                count=0;
                if(p==1)
                {
                    printf("\n Even parity checking:\n");
                    for(i=0; i<6; i++)
                    {
                        if (data[i]==1)
                            count++;
                    }
                    if (count%2==0)
                        printf("\n There is no error in the received data :) \n");
                    else if(count%2!=0)
                        printf("\n THERE is ERROR IN THE RECEIVED DATA :( \n");
                }
                if(p==0)
                {
                    printf("\n ODD parity checking:\n");
                    for(i=0; i<6; i++)
                    {
                        if (data[i]==1)
                            count++;
                    }
                    if (count%2!=0)
                        printf("\n There is no error in the received data :) \n");
                    else if(count%2==0)
                        printf("\n THERE is ERROR IN THE RECEIVED DATA :( \n");
                }
            }

        }
scanf("%c",&z);// to omit the noise in loop control
    }
}
