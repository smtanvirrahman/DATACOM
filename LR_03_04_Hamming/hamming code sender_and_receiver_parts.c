//1 0 0 1 1 0 1
#include<stdio.h>
#include<stdlib.h> // to use system()
#include<math.h> // to use pow()
#include<string.h>
void main()
{
    printf("                                        ");
    printf("<<< WELCOME TO THE ERROR CHECKING SYSTEM >>> \n\n\n");
    printf("                                 ");
    printf("This  program is an implementation of the 'Hammming Code'\n");
    printf("\n This program can try on different data block size\n");
    printf("\n Maximum redundant bit capacity is: 4 bits");
    options();
    printf("                                            ");
    printf("<<< THANK YOU FOR TRYING THIS >>> \n\n\n");
    printf("                                            ");
    printf("\n\n For any suggestion mail me>>> tanvir.181002196@green.ac.bd\n\n");
    scanf("%d");
}

options()
{
    int op;
    printf("\n\n\nPlease Select a Option from the following items:\n");
    printf("\n 1: Hamming code Sender and Receiver\n");
    printf("\n 2: Hamming Distance\n");
    printf("\nEnter Selection(1/2)?: ");
    scanf("%d",&op);
    if(op==1)
        hamcs();//hamming code sender part
    if(op==2)
        hamd(); // hamming distance
}

void hamcs()
{
    int i,j,k,m,r,count=0;
    int data[20], trans[20];
    printf("\n\nSender Part:\n\n");
    printf("\nDO you want to read Hamming Code help File");
    help(1);
    printf("\n\nEnter the number of bits in data block: ");
    scanf("%d",&m);
    printf("\n Enter the data bits:\n");
    for(i=0; i<m; i++)
        scanf("%d",&data[i]);
    printf("\n Entered data bits are:\n");
    for(i=0; i<m; i++)
        printf("%d  ",data[i]);
    for(r=0; r>=0; r++)
    {
        if(pow(2,r)>=(m+r+1))
            break;
    }
    printf("\n\nThe total number of required redundant bit is: %d",r);
    //int rbit[r];
    for(i=0,j=0,k=0; j<m+r;)
    {
        if(j==(pow(2,i)-1))
        {
            trans[j]=9;
            i++;
            j++;
        }
        else
        {
            trans[j]=data[k];
            k++;
            j++;
        }
    }
    printf("\n\nTransmission test:\n");
    for(i=0; i<m+r; i++)
        printf("%d  ",trans[i]);

    {
        for(k=2; k<m+r; k=k+2)
        {
            count=count+trans[k];
            //printf("count : %d",count);
        }
        j=(pow(2,0)-1);
        //printf("count : %d",count);
        trans[j]= count%2;
    }

    {
        count=trans[2];
        for(k=5; k<m+r; k=k+3)
        {
            count=count+trans[k]+trans[k+1];
            //printf("count : %d",count);
        }
        j=(pow(2,1)-1);
        //printf("count : %d",count);
        trans[j]= count%2;
    }

    {
        count=trans[4]+trans[5]+trans[6];
        for(k=11; k<m+r; k=k+5)
        {
            count=count+trans[k]+trans[k+1]+trans[k+2]+trans[k+3];
            //printf("count : %d",count);
        }
        j=(pow(2,2)-1);
        //printf("count : %d",count);
        trans[j]= count%2;
    }
    {
        count=trans[8]+trans[9]+trans[10];
        for(k=23; k<m+r; k=k+9)
        {
            count=count+trans[k]+trans[k+1]+trans[k+2]+trans[k+3]+trans[k+4]+trans[k+5]+trans[k+6]+trans[k+7];
            //printf("count : %d",count);
        }
        j=(pow(2,3)-1);
        //printf("count : %d",count);
        trans[j]= count%2;
    }

    printf("\n\nTransmission test:\n");
    for(i=0; i<m+r; i++)
        printf("%d  ",trans[i]);

    printf("\n\n");
    noise(trans,m,r);
    hamcr(trans, m, r);
}
void noise(int trans[], int m, int r)
{
    int nos,i;
    //printf("\n Do you want to Enter Noise:");
    printf("\n\nEnter the noise, position 1 to %d:\n",m+r);
    scanf("%d",&nos);
    if(trans[nos-1]==0)
        trans[nos-1]=1;
    else if(trans[nos-1]==1)
        trans[nos-1]=0;
    printf("\n\nTransmission with noise test:\n");
    for(i=0; i<m+r; i++)
        printf("%d  ",trans[i]);
}

void hamcr(int trans[], int m, int r)
{
    int k,count=0, rbit[r],pos=0;
    printf("\n\n\n Receiver Part:\n");

    {
        count=trans[0];
        for(k=2; k<m+r; k=k+2)
        {
            count=count+trans[k];
            //printf("count : %d",count);
        }
        //j=(pow(2,0)-1);
        //printf("count : %d",count);
        rbit[0]= count%2;
    }

    {
        count=trans[1]+trans[2];
        for(k=5; k<m+r; k=k+3)
        {
            count=count+trans[k]+trans[k+1];
            //printf("count : %d",count);
        }
        //j=(pow(2,1)-1);
        //printf("count : %d",count);
        rbit[1]= count%2;
    }

    {
        count=trans[3]+trans[4]+trans[5]+trans[6];
        for(k=11; k<m+r; k=k+5)
        {
            count=count+trans[k]+trans[k+1]+trans[k+2]+trans[k+3];
            //printf("count : %d",count);
        }
        //j=(pow(2,2)-1);
        //printf("count : %d",count);
        rbit[2]= count%2;
    }
    {
        count=trans[7]+trans[8]+trans[9]+trans[10];
        for(k=23; k<m+r; k=k+9)
        {
            count=count+trans[k]+trans[k+1]+trans[k+2]+trans[k+3]+trans[k+4]+trans[k+5]+trans[k+6]+trans[k+7];
            //printf("count : %d",count);
        }
        //j=(pow(2,3)-1);
        //printf("count : %d",count);
        rbit[3]= count%2;
    }

    printf("\n\n Error dtection part:\n\n");
    for(k=0; k<r; k++)
        pos=rbit[k]*pow(2,k)+pos;
    if(pos==0)
        printf("\n\nNO Error is in the transmitted DATA\n\n");
    else
    {
        printf("\n\n Error is in the position %d",pos);
        printf("\n\n Correction Part:\n\n");
        if(trans[pos-1]==0)
            trans[pos-1]=1;
        else if(trans[pos-1]==1)
            trans[pos-1]=0;
    }
    printf("\n\n The original Data is:\n\n");
    for(k=0; k<m+r; k++)
        printf("%d  ",trans[k]);

}

void hamd()
{
    char s1[5];
    int data1[5], data2[5];
    int i,count=0;
    printf("\n\n\nHamming Distance:(TEST PURPOSE)\n");
    gets(s1);// to ignore the null character in the loop
    printf("\nDO you want to read Hamming Distance help file");
    help(2);
    printf("\nEnter 1st string:\n");
    for(i=0; i<5; i++)
        scanf("%d",&data1[i]);
    printf("\nEnter 2nd string:\n");
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
    printf("\n\n Hamming Distance = %d",count);
}

void help(int a)
{
    char s1[5];
    printf(" (Y/N): ");
    gets(s1);
    if(strcmp(s1,"y")==0||strcmp(s1,"Y")==0)
    {
        if(a==1)
            system("\help_hamming_code.txt");// to open a windows system file
        if(a==2)
            system("\help_hamming_distance.txt");
    }
}
//error generating algorithm
void makeerror(int trans[], int m, int r)
{
    int i,j,k,count=0;
    for(i=0; i<r; i++)
    {
        for(k=2; k<m+r; k=k+2)
        {
            count=count+trans[k];
        }
        j=(pow(2,i)-1);
        trans[j]= count%2;
    }
}
