#include <stdio.h>
#include <conio.h>
#include<alloc.h>
#include "c:\tree\tree.h"

/* this function is used to create the tree as well as to insert nodes */
/* throughout this program the statement if(ptr->flag==1) means 'if the tree stores single integers' */
/* if single integer tree, the values are stored in the integer item
   if two integers tree, the values are stored in the integers item1 and item2
*/
tree *insert(int item1,int item2,int intchoice,tree *ptr)
{
 if(ptr==NULL)
 {

   ptr=(tree*)malloc(sizeof(tree));

  ptr->flag=intchoice;

/* if nodes store single integer store single integer*/
	  if(ptr->flag==1)
	  {
		  ptr->item=item1;
		  ptr->item1=0;
		  ptr->item2=0;
	  }
/* if nodes store two integers store two integers in each node*/
	  else
	  {
		  ptr->item1=item1;
		  ptr->item2=item2;
	  }
	  ptr->left=NULL;
	  ptr->right=NULL;
	  return(ptr);
 }

 ptr->flag=intchoice;

/*
    if the tree is single integer tree, then determine this node's position by
    comparing its value to all other nodes
*/
 
 if(ptr->flag==1)
 {
 if((item1) < (ptr->item))
	  ptr->left=insert(item1,item2,intchoice,ptr->left);
 else
	  ptr->right=insert(item1,item2,intchoice,ptr->right);
 }

/*
    if the tree is two integer tree, then determine this node's position by
    comparing the sum of integers of this node to the sum of integers of all other nodes
*/

 else
 {
 if((item1+item2) < (ptr->item1+ptr->item2))
	  ptr->left=insert(item1,item2,intchoice,ptr->left);
 else
	  ptr->right=insert(item1,item2,intchoice,ptr->right);
 }
 return(ptr);
}



void display(int level,int intchoice,tree *ptr)
{
 int i;

 if(ptr!=NULL)                                  
 {
   ptr->flag=intchoice;
   display(level+1,intchoice,ptr->right);     	
   printf("\n\n");

     for(i=0;i<level;i++)
	printf("       ");
   if(ptr->flag==1)
   printf("%d",ptr->item);  	       
   else
   printf("%d %d",ptr->item1,ptr->item2);
   display(level+1,intchoice,ptr->left);	       

 }
}


void preorder(tree *ptr,int intchoice)
{
 if(ptr!=NULL)
  {
   ptr->flag=intchoice;
   if(ptr->flag==1)
   {
   printf("%d\n",ptr->item);
   }
   else
   {
   printf("%d %d\n",ptr->item1,ptr->item2);
   }
   preorder(ptr->left,intchoice);
   preorder(ptr->right,intchoice);
  }
}



void inorder(tree *ptr,int intchoice)
{
 if(ptr!=NULL)
  {
   ptr->flag=intchoice;

   inorder(ptr->left,intchoice);
   if(ptr->flag==1)
   {
   printf("%d\n",ptr->item);
   }
   else
   {
   printf("%d %d\n",ptr->item1,ptr->item2);
   }

   inorder(ptr->right,intchoice);
  }
}



void postorder(tree *ptr,int intchoice)
{
 if(ptr!=NULL)
  {
   ptr->flag=intchoice;
   postorder(ptr->left,intchoice);
   postorder(ptr->right,intchoice);
   if(ptr->flag==1)
   {
       printf("%d\n",ptr->item);
   }
   else
   {
	printf("%d %d\n",ptr->item1,ptr->item2);
   }

  }
}




