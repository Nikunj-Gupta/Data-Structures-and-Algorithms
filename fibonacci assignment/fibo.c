#include<stdio.h>
#include<stdlib.h>

#define N 1000


void printarray(int* array,int n)
{
int i;
for(i=0;i<n;i++)
{
printf("%d ",array[i]);
}
printf("\n");
}

int main(int argc, char* arg[])
{
int a,b,c;
int i;
FILE *in;
int num[1000];
char ch;

in = fopen(arg[1],"r");
fscanf(in,"%d\n",&a);
fscanf(in,"%d\n",&b);
fscanf(in,"%d\n",&c);

//debugging 1
printf("%d\n%d\n%d\n",a,b,c);

for(i=0;i<N;i++)
{
fscanf(in,"%c",&ch);
num[i] = (int)ch - '0';
}

//debugging 2
printarray(num,N);

return 0;
}
