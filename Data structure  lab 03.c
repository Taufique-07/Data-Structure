#include<stdio.h>

int main()
{
    int num1,num2;
    scanf("%d %d",&num1,&num2);
    int a[num1][num2],diagonal1=0,diagonal2=0;

    for(int i=0; i<num1; i++)
    {
        for(int j=0; j<num2; j++)
        {
            scanf("%d",&a[i][j]);
            if(i==j)
            {
                diagonal1+=a[i][j];
            }

            if(i+j==num1-1)
            {
                diagonal2+=a[i][j];
            }
        }
    }


    printf("%d\n",diagonal1);
    printf("%d\n",diagonal2);
    return 0;

}
