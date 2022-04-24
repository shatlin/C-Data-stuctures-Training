/*
you might need to change this line below  to reflect
the folder the library is stored in your computer
*/

#include "c:\twodarr\twodarr.h"
#include <Stdio.h>
#include <conio.h>
#include <alloc.h>

twodarray* twodarrayinitialise(twodarray *array,unsigned int rows,unsigned int columns)
{
int i;
array->numberofrows=rows;
array->numberofcolumns=columns;

/*allocate the memory for the main pointer */
array->element=malloc(array->numberofrows*sizeof(int *));


/* if memory couldnot be allocated display error*/
if(array->element== NULL)
{
	fprintf(stderr,"out of memory\n");
	return NULL;
}

/*allocate the memory for the pointers of each row  */

for(i=0;i<array->numberofrows;i++)
{
array->element[i]=malloc(array->numberofcolumns*sizeof(int));

/* if memory couldnot be allocated display error*/
if(array->element[i] == NULL)
{
fprintf(stderr,"out of memory\n");
return NULL;
}
}
return(array);
}


twodarray* twodarraysetvalues(twodarray *array)
{
	int i,j;
	printf("\n");
	for(i=0;i<array->numberofrows;i++)
	{
	for(j=0;j<array->numberofcolumns;j++)
	{
	printf("Enter the array element[%d][%d] :  ",i,j);
	scanf("%d",&array->element[i][j]);
	}
	}
	return(array);
}

void twodarraydisplay(twodarray* array)
{
	int i,j;
	printf("\n");
	for(i=0;i<array->numberofrows;i++)
	{
	for(j=0;j<array->numberofcolumns;j++)
	{
		printf("%d   ",array->element[i][j]);
	}
	printf("\n");
	}

}


void twodarrayzeroit(twodarray *array)
{
	int i, j;
	for(i = 0; i < array->numberofrows; i++)
		{
		for(j = 0; j < array->numberofcolumns; j++)
			array->element[i][j] = 0;
		}
}

/* free the memory allocated using malloc function*/

void twodarrayfreememory(twodarray *array)
{
	int i;
	for(i = 0; i < array->numberofrows; i++)
		free(array->element[i]);
	free(array->element);
}
