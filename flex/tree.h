typedef struct tree_tag
{
 int item1;
 int item2;
 int item;
 int flag;
 struct tree *left;	
 struct tree *right;	
}tree;

extern tree *insert(int item1,int item2,int intchoice,tree *ptr);
extern void display(int level,int intchoice,tree* ptr);
extern void postorder(tree *ptr,int intchoice);
extern void preorder(tree *ptr,int intchoice);
extern void inorder(tree *ptr,int intchoice);
