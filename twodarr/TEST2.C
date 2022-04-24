/*
A test program to test the two dimensional array abstract data type
This is a program for matrix addition
*/
/*
you might need to change this line below
to reflect the folder the library is stored
*/

#include "c:\twodarr\twodarr.c"
#include <stdio.h>
#include <conio.h>

void main()
{
	int i,j;
	twodarray *firstarray;
	twodarray *secondarray;
	twodarray *resultarray;
	unsigned int rows,columns;
	clrscr();

	printf("Enter the number of rows for the two dimensional array   : ");
	scanf("%d",&rows);
	printf("Enter the number of columns for the two dimensional array: ");
	scanf("%d",&columns);

	firstarray=twodarrayinitialise(firstarray,rows,columns);
	secondarray=twodarrayinitialise(secondarray,rows,columns);
	resultarray=twodarrayinitialise(resultarray,rows,columns);

	printf("\nenter the first two dimensional array elements\n");
	firstarray=twodarraysetvalues(firstarray);
	printf("\nenter the second two dimensional array elements\n");
	secondarray=twodarraysetvalues(secondarray);

for(i=0;i<resultarray->numberofrows;i++)
{
	for(j=0;j<resultarray->numberofcolumns;j++)
	{
	resultarray->element[i][j]=firstarray->element[i][j]+secondarray->element[i][j];
	}
}
printf("\nthe first two dimensional array\n");
twodarraydisplay(firstarray);
printf("\nthe second two dimensional array\n");
twodarraydisplay(secondarray);
printf("\nthe sum of the two two dimensional arrays\n");
twodarraydisplay(resultarray);

printf("\nfreeing up memory ...\n");

twodarrayfreememory(firstarray);
twodarrayfreememory(secondarray);

getch();
}