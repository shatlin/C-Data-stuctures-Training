/*
you might need to change this line below
to reflect the folder the library is stored
*/

#include "c:\twodarr\twodarr.c"
#include <stdio.h>
#include <conio.h>

void main()
{
twodarray *array;
unsigned int rows,columns;
clrscr();

printf("Enter the number of rows for the two dimensional array   : ");
scanf("%d",&rows);

printf("Enter the number of columns for the two dimensional array: ");
scanf("%d",&columns);

array=twodarrayinitialise(array,rows,columns);

array=twodarraysetvalues(array);

twodarraydisplay(array);


printf("\nfilling the array with zeros...\n");
twodarrayzeroit(array);
twodarraydisplay(array);

printf("\nfreeing up free space ...\n");
twodarrayfreememory(array);

getch();
}