#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include "c:\stack\stack.h"

void StackInit(stack *stackp, int maxSize)
{
  int x;
  printf("\nDo u want to store one integer or 2 integers in each node(press 1 or 2) :");
  scanf("%d",&x);
  stackp->flag=x;

/*
     if nodes store single integers  allocate memory 
    for  the contents array by using normal malloc 
*/

  if(stackp->flag==1)
	  stackp->contents = malloc(sizeof(int)	* maxSize);

/*
    if nodes store two integers  allocate memory 
    for  the elements array of twodarray ADT by using it special
    function twodarrayinitialise
*/

  else

	  twodarrayinitialise(stackp->aa,maxSize,2);

  if (stackp->contents == NULL)
   {
    fprintf(stderr, "Insufficient memory to initialize stack.\n");
    exit(1);
  }

  stackp->maxSize = maxSize;
  stackp->top = -1;
}


void StackPush(stack *stackp,int element1,int element2)
{
  if (StackIsFull(stackp))
   {
    fprintf(stderr, "Can't push element into stack: stack is full.\n");
    getch();
    return;
   }
/* before pushing the elements,the integer top is made to point to the new node  by incrementing it*/

stackp->top=(stackp->top)+1;

/* if nodes contain single integer add the new integer to the  one dimensional array content */
if(stackp->flag==1)
{
stackp->contents[stackp->top] = element1;
}
/*
    if nodes contain two integer add the new integer to the  two dimensional array element
    which is actually element of another  ADT twodarray called aa,which is a member of stack
    structure
*/

else
{
stackp->aa->element[stackp->top][0]=element1;
stackp->aa->element[stackp->top][1]=element2;
}
}



int StackPop(stack *stackp,int *a,int *b)
{
  if (StackIsEmpty(stackp))
   {
    fprintf(stderr, "Can't pop element from stack: stack is empty.\n");
    getch();
    return(0);
   }

/* if the stack stores single integer then return that integer to the calling function
    and decrease the top pointer by 1  */
    if(stackp->flag==1)
    {

	return stackp->contents[stackp->top--];
    }

/* if the stack stores two integers in each node,we return both those integers to the calling 
    function using pointers.Two values can be returned by using pointers.Then stacks top node
    is reduced by 1 */

    else
    {
	*a=stackp->aa->element[stackp->top][0];
	*b=stackp->aa->element[stackp->top][1];
	stackp->top--;
    }
  return 0;
}

void Stackdisplay(stack *stackp)
{
int i,j;
if(stackp->flag==1) //if the stack contains one integer per node  display that integer
   {
	for(i=0;i<=stackp->top;i++)
	{
		printf("%d\n",stackp->contents[i]);
	}
   }
   else    //if the stack contains two integers per node display both the integers
   {
	for(i=0;i<=stackp->top;i++)
	{
		for(j=0;j<2;j++)
		{
/* stack points to the two dimensional array that points its member element which is a two d array */
			printf("%d ",stackp->aa->element[i][j]);

		}
		printf("\n");

	 }
   }
}

/* freeing up the stacks space */
void StackDestroy(stack *stackP)
{

  free(stackP->contents);
  if(stackP->flag==2)
  twodarrayfreememory(stackP->aa);
  stackP->contents = NULL;
  stackP->maxSize = 0;
  stackP->top = -1;
}

/* checking if the stack is empty */
int StackIsEmpty(stack *stackP)
{
  return stackP->top < 0; 
}


/* checking if the stack is full */
int StackIsFull(stack *stackP)
{
  return stackP->top >= stackP->maxSize - 1;
}
