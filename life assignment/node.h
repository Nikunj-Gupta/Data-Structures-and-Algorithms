typedef struct nodeobject
{
char *type;
int ival;
double rval;
char *sval;
/* the value part of the node */
} node;
extern char *INTEGER;
extern char *REAL;
extern char *STRING;
extern node *newIntegerNode(int value);
extern node *newRealNode(double value);
extern node *newStringNode(char *value);
