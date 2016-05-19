#include<stdio.h>
#include<string.h>
int main(int argc, char *arg[])
{
FILE *gen0;
gen0 = fopen(arg[1],"r");
char *firstline;
char c;
int rows,columns,count=0;
//c = fgetc(gen0);
while(c!='\n')
{
fscanf(gen0,"%c\n",&c);
count++;
}
printf("%d\n",count);
//fscanf(gen0,"%s\n",firstline);
//rows = strlen(firstline);
//printf("%d\n",rows);
return 0;
}
