typedef struct twodimensionarray
{
	 unsigned int numberofrows;
	 unsigned int numberofcolumns;
	 int **element; /* this is the two dimensional array,equivalent to element[][] 
		              declared using pointers to implement dynamic allocation 
		        */
}twodarray;

 extern twodarray* setdimension(twodarray* array,unsigned int a,unsigned int b);
 extern twodarray* setvalues(twodarray* array);
 extern void displayarray(twodarray* array);
 extern void zeroit(twodarray *array);
 extern void freememory(twodarray *array);

/*extern key word is used to tell the compiler that this function is defined elsewhere*/