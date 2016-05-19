#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void print_array(char**,int ,int);
char** initialize(int rows,int columns)
{
char** array;
int i;
array = (char**)malloc(sizeof(char*)*rows);
for(i=0;i<rows;i++)
array[i] = (char*)malloc(sizeof(char)*columns);
return array;
}
int count_columns(char *file)
{
FILE *in;
int lencol=0;
in=fopen(file,"r");
char *line;
//fscanf(in,"%s",line);
//lenrow = strlen(line);
char c;
c = fgetc(in);
while(c!='\n')
{
lencol++;
c = fgetc(in);
}
//fclose(in);
return lencol;
}
int count_rows(char *file)
{
FILE *in;
int lenrow=0;
in = fopen(file,"r");
char* line;
while(!feof(in))
{
fscanf(in,"%s\n",line);
lenrow++;
}
//fclose(in);
return lenrow;
}
void print_gen0(char *file)
{
FILE *in;
in = fopen(file,"r");
char c;
while(!feof(in))
{
fscanf(in,"%c",&c);
printf("%c",c);
}
//fclose(in);
}
char** store_in_array(char *file,int rows,int columns)
{
FILE *in;
in = fopen(file,"r");
char **gen;
int i,j;
gen = initialize(rows,columns);
char c;
char ch[rows*columns];
int k=0;
for(i=0;i<(rows*columns);)
{
fscanf(in,"%c",&c);
if(c!='\n')
{
ch[i]=c;
i++;
}
}
for(i=0;i<rows;i++)
{
for(j=0;j<columns;j++)
{
gen[i][j] = ch[k];
k++;
}
}
//print_array(gen,rows,columns);
return gen;
}
void print_array(char **array,int rows,int columns)
{
int i,j;
for(i=0;i<rows;i++)
{
for(j=0;j<columns;j++)
{
printf("%c",array[i][j]);
}
printf("\n");
}
}
char** copy_gen(char** orig_gen,int rows,int columns)
{
char **newgen;
newgen = initialize(rows,columns);
int i,j;
for(i=0;i<rows;i++)
{
for(j=0;j<columns;j++)
{
newgen[i][j] = orig_gen[i][j];
}
}
for(i=0;i<rows;i++)
{
for(j=0;j<columns;j++)
{
if(newgen[i][j]!='.')
newgen[i][j]='x';
}
}
printf("\n\n");
//print_array(newgen,rows,columns);
return newgen;
}

int count_neighbours(char** gen,int i,int j,int rows,int columns)
{
int count=0;
if(i>0&&j>0&&i<(rows-1)&&j<(columns-1))
{
if(gen[i][j]==gen[i-1][j-1])
count++;

if(gen[i][j]==gen[i-1][j])
count++;

if(gen[i][j]==gen[i-1][j+1])
count++;

if(gen[i][j]==gen[i][j-1])
count++;

if(gen[i][j]==gen[i][j+1])
count++;
 
if(gen[i][j]==gen[i+1][j-1])
count++;

if(gen[i][j]==gen[i+1][j])
count++;

if(gen[i][j]==gen[i+1][j+1])
count++;
}
if(i==0 && j!=0 && j!=(columns-1))
{
if(gen[0][j]==gen[0][j-1])
count++;

if(gen[0][j]==gen[0][j+1])
count++;

if(gen[0][j]==gen[1][j-1])
count++;

if(gen[0][j]==gen[1][j])
count++;

if(gen[0][j]==gen[1][j+1])
count++;
}
if(i==rows-1 && j!=0 && j!=(columns-1))
{
if(gen[rows-1][j]==gen[rows-1][j-1])
count++;

if(gen[rows-1][j]==gen[rows-2][j-1])
count++;

if(gen[rows-1][j]==gen[rows-2][j])
count++;

if(gen[rows-1][j]==gen[rows-2][j+1])
count++;

if(gen[rows-1][j]==gen[rows-1][j+1])
count++;
}
if(j==0 && i!=0 && i!=rows-1)
{
if(gen[i][0]== gen[i-1][0])
count++;

if(gen[i][0]== gen[i-1][1])
count++;

if(gen[i][0]== gen[i][1])
count++;

if(gen[i][0]== gen[i+1][1])
count++;

if(gen[i][0]== gen[i+1][0])
count++;
}
if(j==columns-1 && i!=0 && i!=rows-1)
{
if(gen[i][columns-1]=gen[i-1][columns-1])
count++;

if(gen[i][columns-1]=gen[i-1][columns-2])
count++;

if(gen[i][columns-1]=gen[i][columns-2])
count++;

if(gen[i][columns-1]=gen[i+1][columns-2])
count++;

if(gen[i][columns-1]=gen[i+1][columns+1])
count++;
}
if(i==0&&j==0)
{
if(gen[0][0]==gen[0][1])
count++;

if(gen[0][0]==gen[1][1])
count++;

if(gen[0][0]==gen[1][0])
count++;
}
if(i==0&&j==columns-1)
{
if(gen[0][columns-1]==gen[0][columns-2])
count++;

if(gen[0][columns-1]==gen[1][columns-2])
count++;

if(gen[0][columns-1]==gen[1][columns-1])
count++;
}
if(i==rows-1 && j==0)
{
if(gen[rows-1][0]==gen[rows-2][0])
count++;

if(gen[rows-1][0]==gen[rows-2][1])
count++;

if(gen[rows-1][0]==gen[rows-1][1])
count++;
}
if(i==rows-1 && j==columns-1)
{
if(gen[rows-1][columns-1]==gen[rows-2][columns-1])
count++;

if(gen[rows-1][columns-1]==gen[rows-2][columns-2])
count++;

if(gen[rows-1][columns-1]==gen[rows-1][columns-2])
count++;
}
return count;
}







int main(int argc,char *arg[])
{
int rows,columns;
int i,j;
int count;
char **gen,**newgen;
//printf("%s\t%d\n",arg[1],arg[2]);
columns = count_columns(arg[1]);//1
rows = count_rows(arg[1]);//2
print_gen0(arg[1]);//3
printf("ROWS = %d\n",rows);
printf("COLUMNS = %d\n",columns);
gen = store_in_array(arg[1],rows,columns);
newgen = copy_gen(gen,rows,columns);
print_array(newgen,rows,columns);
for(i=0;i<rows;i++)
{
for(j=0;j<columns;j++)
{
if(gen[i][j]!='.')
{
count = count_neighbours(gen,i,j,rows,columns);
newgen[i][j] = count+'0';
}
}
}
gen1 = copy_gen(gen)
printf("\n\n");
print_array(newgen,rows,columns);
return 0;
}
