#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
	{
	int name;
	struct node *next;
	struct node *down;
	};


struct node* search(struct node* ,int);
int check(struct node *,int );
void printR (struct node *);
int rep(int *,int,int);
int lengthoflist(struct node* );
int network(struct node*,int,int *,int);
void printarray(int *,int);


void linearsort(int* arr,int l)
{
int i,j,temp;
for(i=1;i<l;i++)
{
for(j=i+1;j<l;j++)
{
if(arr[j]<arr[i]){
temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
}}}
}


void printR (struct node *n)
	{
	struct node *t;
	if(n != 0)
		{
		t = n->next;
		if (n != 0)
			{
			printf ("%d-> ", n->name);
			n = n->down;
			printR (n);
			}
		//n = t;
		printf ("\n");
		printR (t);
		}
	}

int main (int argc, char *arg[])
	{
	FILE *in;
	in = fopen (arg[1], "r");
	int n, i;
	char c;
	fscanf (in, "%d", &n);
	fgetc(in);
	//fscanf (in, "%c", &c);
	int friend;
	struct node *list;
	struct node *tempdown, *tempnext;
	list = malloc (sizeof (struct node));
	tempdown = list;
	tempnext = list;
	tempdown->down = malloc (sizeof (struct node));
	tempnext->next = malloc (sizeof (struct node));
	for (i = 0; i < n; i++)
		{
		if(feof(in))break;
		tempnext->name = i + 1;
		tempdown = tempnext;
		tempnext->next = malloc (sizeof (struct node));
		while (1)
			{
			fscanf (in, "%c", &c);
			if (c == ' ')
				continue;
		        else if(c == '\n')
			{
				tempdown->down=0;
				break;
			}
			else 
			{
			   fseek(in,-1, SEEK_CUR);
			   fscanf(in, "%d", &friend);
			   //printf("%d,",friend);
			   tempdown->down = malloc (sizeof (struct node));
			   tempdown = tempdown->down;
			   tempdown->name = friend;
			}
		        //fscanf (in, "%c", &c);
			}
		tempnext = tempnext->next;
		}
  tempnext = list;
  /*
  while(tempnext!=NULL){
    tempdown = tempnext;
    while(tempdown!=NULL){
    printf("%d->",tempdown->name);
    tempdown = tempdown->down;
    }
    printf("\n");
    tempnext = tempnext->next;
  }*/
  //printR(list);
  //printf("Count = %d\n",lengthoflist(list));
  //printR(search(list,2));
  /*int *array;
  array = (int*)malloc(sizeof(int)*100000);
  array = network(list,1);
  printarray(array);*/
int *arr=(int *)malloc(4*n);
arr[0]=atoi(arg[2]);
int l=network(list,atoi(arg[2]),arr,1);  
printarray(arr,l);
return 0;
	}
void printarray(int *array,int l)
{
int i;
//linearsort(array,l);
for(i=1;i<l;i++)
  printf("%d ",array[i]);
printf("\n");
}


struct node* search(struct node* n,int key)
	{
	struct node* t;
	t = n;
	while(t!=NULL)
		{
		if (t->name==key)
			return t->down;
		t = t->next;
		if (t->name==key)
			return t->down;
		if (t->name==key)
			return t->down;
		}
	printf("No such person found!\n");
	}

int check(struct node *n,int person)
	{
	struct node *t;
	t = n;
	while(t!=NULL)
		{
		if(t->name==person)
			return 1;
		t = t->down;
		}
	return 0;
	}

int rep(int *array,int key,int l)
  {
  int i,j;
    for(i=0;i<l;i++)
      {
      if(array[i] == key)
        return 1;
      }
    return 0;
  }

int lengthoflist(struct node* n)
{
int count = 0;
while(n!=NULL)
{
count++;
n = n->down;
}
return count;
}


int network(struct node* head,int person,int *arr,int p)
    {
    if(head==NULL)
	return 0;
    //int *array;
    //array = (int*)malloc(sizeof(int)*1000);
    //int i;
    struct node* t;
    t=search(head,person);
    if(t==0)
	return p;
    if(!rep(arr,t->name,p+1))
    {
	arr[p]=t->name;
	p++;
    	p=network(head,t->name,arr,p);
    }
    while(1)
    {
	t=t->down;
    	if(t==0)
		return p;
	else if(!rep(arr,t->name,p+1))
	{
    		arr[p]=t->name;
    		p++;
    		p=network(head,t->name,arr,p);
	}
    }
    /*while(t!=NULL)
    {
    t = search(head,person);
    array[0] = person;
    for(i=1;i<lengthoflist(t);i++)
      {
      array[i] = t->name;
      t = t->down;
      }
    }*/
    return p+1;
    }




/*
struct node* add(struct node* n,int person)
	{
	struct node* t;
	t = search(n,person);
  }
*/
