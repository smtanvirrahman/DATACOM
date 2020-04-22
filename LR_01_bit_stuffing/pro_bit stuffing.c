#include<stdio.h>
void main ()
{
    char a,b;
    int i,j,count=0;
    char datain[12], dataout[16];
    printf("<<< THIS PROGRAM WILL TRANSMIT DATA BITS INSTANTLY BIT BY BIT >>>\n");
    printf("\n This will take smallest possible memory space as small as only a character space\n");
    printf("\n <<<..... Program starts from here.....>>>\n");
    printf("\n Enter Data bits (enter 'x' to exit) :\n");
    for(i=0,j=0;;i++,j++)
    {
        printf("\n enter data bit to transmit:\n");
        scanf("%c%c",&a,&b); // taking input to the system as from the sender
        printf("\nInput:%c",a); // this is just to check the input for code analysis
        if(a=='x'||a=='X') // loop breaking bit or it can be multiple bits in complex and real time scenario
        {
            printf("\n Transmission terminated \n");
            break;
        }
        else if (a=='0'||a=='1') // input bit detection
        {
            printf("\nOutput:%c",a); // here input bit will be send to the transmission line
            datain[i]=a;
            dataout[j]=a;
             printf("\nOutput array:%c",datain[i]);
            if(a=='1')
            {
                count++;
                if (count==3) // number of bits check for the the stuffing
                {
                    printf("0"); // stuffing with zero 0
                    dataout[j+1]='0';
                    j++;
                    count=0;    // counter reseting
                }
            }
            else if (a=='0') // for reseting  the counter
                count=0;
        }
        // lines after this comment has no major significance
        printf("\n");
        printf(" \n total number of bits transmitted: %d\n",j+1); // count the total number of bits that have been transmitted
    // printf("\n i counting: %d\n",i);
    // printf("\n j counting: %d\n",j);
    }
 printf("\n Total bit before bit_stuffing: %d\n",i);
 printf("\n Total bit after bit_stuffing: %d\n",j);
int k;
printf("\n Input data: \n");
for(k=0;k<i;k++)
printf("%c ", datain[k]);
printf("\n Output data: \n");
for(k=0;k<j;k++)
printf("%c ", dataout[k]);
}
