#include<stdio.h>
#include<strings.h>
void main()
{

    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int i,j,m;
    i=++a[0];
    j=a[0]++;
    m=a[i++];
    printf("\n%d %d %d",i,j,m);
    i=--a[2];
    j=a[2];
    m=a[i];
    printf("\n%d %d %d",i,j,m);
        int num1=30,num2=1000;
    if(!(num1>=12)||!(num2<=5000))
        printf("num1=%d\tnum2=%d\n",++num1,++num2);
}
void fun1(void)
{

}
