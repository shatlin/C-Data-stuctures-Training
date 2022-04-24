#include "c:\twodarr\twodarr.c"
typedef struct stackrecord
{
  int *contents;
  int top;
  int maxSize;
  int flag;
  twodarray *aa;//  twodarray ADT is used here if the stack needs to store 2 integers in each node
}stack;

extern void StackInit(stack* stackp,int maxsize);
extern void StackPush(stack *stackP, int element,int element2);
extern int StackPop(stack *stackP,int *a,int *b);
extern void Stackdisplay(stack *stackp);
extern void StackDestroy(stack *stackP);
extern int StackIsFull(stack *stackP);
extern int StackIsEmpty(stack *stackP);



