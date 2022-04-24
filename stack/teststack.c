#include <stdio.h>
#include <conio.h>
#include "c:\stack\stack.c"

int main(void)
{
  stack stacks;

  int element1=0;
  int element2=0;
  int i,j;
  int stacksize;
  clrscr();
/* maxsize stores the maximum nodes allocated for the stack */

  printf("Enter the maxsize for the stack :");
  scanf("%d",&stacksize);

  StackInit(&stacks,stacksize);
  printf("\n");
  for(i=0;i<stacksize;i++)
  {
   /* if its a single integer stack, then input one integer per node */
    if(stacks.flag==1)
    {
    printf("enter the %d value to push  :",i+1);
    scanf("%d",&element1);
    StackPush(&stacks,element1,0);
    }
   /* if its two integers stack, then input two integers per node */
    else
    {
    printf("enter the first integer value to push in node %d  :",i+1);
    scanf("%d",&element1);
    printf("enter the second integer value to push in node %d :",i+1);
    scanf("%d",&element2);
    StackPush(&stacks,element1,element2);
    }
   }
   printf("\nTrying to push elements into a full stack...\n");
   StackPush(&stacks,element1,element2);

   StackPop(&stacks,&element1,&element2);

   if(stacks.flag==1)
	printf("\npopped element is %d \n",element1);
   else
	printf("\npopped elements are %d %d\n",element1,element2);

   printf("\nContents of the stack is\n\n");
   Stackdisplay(&stacks);
   printf("\nThe stack memory is released...\n");
   StackDestroy(&stacks);

   getch();
   return 0;
}
