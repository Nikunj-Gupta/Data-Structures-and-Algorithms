#include <stdio.h>
#include <stdlib.h>
#include "node.h"
static node *newNode(void);
/*************** public interface *************/
char *INTEGER = "integer";
char *REAL = "real";
char *STRING = "string";
node *
newIntegerNode(int v)
{
node *p = newNode();
p->type = INTEGER;
p->ival = v;
return p;
}
node *
newRealNode(double v)
{
node *p = newNode();
p->type = REAL;
p->rval = v;
return p;
}
node *
newStringNode(char *v)
{
node *p = newNode();
p->type = STRING;
p->sval = v;
return p;
}
/*************** private methods *************/
static node *
newNode()
{
node *n = (node *) malloc(sizeof(node));
if (n == 0) { fprintf(stderr,"out of memory"); exit(-1); }
return n;
}
