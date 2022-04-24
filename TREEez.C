#include <stdio.h>
#include <conio.h>
#include<alloc.h>
#include "c:\tree\tree.h"

//Replaces  item1 with  item2  if item2 is a node of item1
//p and s are arbitrary pointers which carry the adresses of item1
//and item2 respectively

tree *replace(tree *p,tree *s)
{
 tree *temp; //temp is temporary mem space
 if(s->right != NULL)
   s->right = replace(p,s->right);
 else
  {
   temp = s;
   p->item = s->item;
   s = s->left;
   free(temp);
  }
  return(s);
}



/* to compute the number of nodes in a tree */

int size(tree *ptr)
{
 if(ptr== NULL)          //checks if the tree is empty or not
 return(0);
 else
 return(size(ptr->left) + 1 + size(ptr->right)); //returns an integer
}


//Function to delete any item from the tree
tree *del(int item,tree *ptr)
{
 tree *temp;
 if(ptr==NULL)
  {
   printf("\nTree is empty\n");
  }
 else
  if(item < ptr->item)
     ptr->left = del(item,ptr->left);
  else
    if(item > ptr->item)
     ptr->right = del(item,ptr->right);
  else
  {
   temp=ptr;
    if(temp->right == NULL)
    {
     ptr =temp->left;
     free(temp);
    }
   else
    if(temp->left == NULL)
    {
     ptr = temp->right;
     free(temp);
    }
  else
  temp->left = replace(temp,temp->left);
 }
 return(ptr);
}


//Searches for any element inside the tree if found returns 1 else returns 0
int search(int item,tree *ptr)
{
if (ptr!=NULL)
 {
   if (ptr->item==item)//checks the entered item with the current node
    {
     return(1);
    }
   search(item,ptr->left);//searches for item in the left part of the tree
   search(item,ptr->right);//searches for item in the right part of the tree
 }
else
 return(NULL);
}

//To display the complete tree
void display(int level,tree *ptr)
{
 int i;
 if(ptr!=NULL)                                  //checks the last node of tree
 {
   display(level+1,ptr->right);     	//points to the right item
   printf("\n");

     for(i=0;i<level;i++)
	printf("   ");

   printf("%d",ptr->item);  	       //display the item pointed to
   display(level+1,ptr->left);	       //points to the left item

 }
}


//Does a pre order traveresal
void preorder(tree *ptr)
{
 if(ptr!=NULL)
  {
   printf("%d",ptr->item);
   preorder(ptr->left);
   preorder(ptr->right);
  }
}


//Does an inorder traveresal
void inorder(tree *ptr)
{
 if(ptr!=NULL)
  {
   inorder(ptr->left);
   printf("%d",ptr->item);
   inorder(ptr->right);
  }
}


//Does a postorder traveresal
void postorder(tree *ptr)
{
 if(ptr!=NULL)
  {
   postorder(ptr->left);
   postorder(ptr->right);
   printf("%d",ptr->item);
  }
}



//Inserts a new node in the tree
//It also creates a tree ** Can be used in both ways
tree *insert(int item,tree *ptr)
{
 if(ptr==NULL)
 {
  ptr=(tree*)malloc(sizeof(tree));
  ptr->item=item;
  ptr->left=NULL;
  ptr->right=NULL;
  return(ptr);
 }
 if(item < ptr->item)
  ptr->left=insert(item,ptr->left);
 else
   if(item > ptr->item)    //Just for illustration this state ment ca beremoved
  ptr->right=insert(item,ptr->right);
 return(ptr);
}

