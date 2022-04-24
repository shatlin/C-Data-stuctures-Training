#include <stdio.h>
#include <string.h>
#include<ctype.h>

 FILE *f_input;
 void comment(char *);
 void variable(),  string1(char *);
 int operatorPunc(char *), decimalValue(char *);
void main()
{
 char filename[100];

 char word[100] = " ";

 printf("Enter your file path and name together with the file extension\n");
 gets(filename);



 if ((f_input = fopen(filename,"r")) == NULL)
	printf("Error!! can't open the input file");
 else
	{
	 while (!feof(f_input))
		{
			fscanf(f_input,"%s", word);

			switch (word[0])
			{
		  case '/': comment(word);
					  break;
		  case 'i': if (word[1] == 'f')
							printf(" %s    : is keyword if\n",word);
						if (strcmp(word,"int")== 0)
							{
							printf(" %s    : is keyword int\n",word);
							variable();
							}
						break;

		  case 'e':if (strcmp(word,"else")== 0)
							{
							printf(" %s    : is keyword else\n",word);
							}
							break;
		  case 'w': if (strcmp(word,"while")== 0)
							{
							printf(" %s    : is keyword while\n",word);
							}
							break;
		  case 'v':  if (strcmp(word,"void")== 0)
							{
							printf(" %s    : is keyword void\n",word);
							}
							break;
		  case 'c': if (strcmp(word,"char")== 0)
							{
							printf(" %s    : is keyword char\n",word);
							variable();
							}
							break;
		  case 'r': if (strcmp(word,"return")== 0)
							{
							printf(" %s    : is keyword return\n",word);
							}
							break;
		  case '"':  string1(word);
						 break;

			}


			strcpy(word," " );
		}
	}


}

void comment(char *word)
{
  if (word[1] == '/')
						{
						fgets(word,100,f_input);
						word[strlen(word)-1] = '\0';
						printf(" %s    : is comments\n",word);
					  }
}

void variable()
{
 char word[40] = " ";
 int done =0;
 int res =0;
 while (done == 0)
	{
	fscanf(f_input,"%s",word);
	 if (word[0] == '_' || islower(word[0]))
		{
		 for (int i=0;i<strlen(word)-1;i++)
			if (!isalpha(word[0]) && !isdigit(word[0]) && word[0] != '_' )
			  {res = operatorPunc(word);
				res = decimalValue(word);
				if (res == 0)
				  printf(" %s    : is not a valid variable name\n",word);
				break;
			  }
			  if (i == strlen(word)-1)
			printf(" %s    : is valid variable name\n",word);

		}
	 else
		{
		if (word[strlen(word)-1] == ';')
			{
				done = 1;
				word[strlen(word)-1] = '\0';
			}
			res = operatorPunc(word);
			if (res == 0)
			res = decimalValue(word);
			if (res == 0)
					printf(" %s    : is not a valid variable name\n",word);
		}
	}
}

int operatorPunc(char *word)
 {
  switch(word[0])
  {
	case '+':
	case '-':
	case '(':
	case ')':
	case ',':
	case ';':
	case '=':
	case '*':
	case '/':printf(" %s    : is Operator or Punctuation\n",word);
				return 1;
	case '|':if (word[1] == '|')
					 {
					 printf(" %s    : is Operator or Punctuation\n",word);
					  return 1;
					 }
				return 0;
	case '&':if (word[1] == '&')
				 {
					printf(" %s    : is Operator or Punctuation\n",word);
					return 1;
				  }
				return 0;
	default: return 0;

  }
 }

int decimalValue(char *word)
{
  for (int i=0;i< strlen(word);i++)
	if (!isdigit(word[i]))
			  {
			  printf(" %s    : is not a valid integer value\n",word);
			  return 0;
			  }
	printf(" %s    : is a valid integer value\n",word);
	return 1;
}

void string1(char *word)
{
int i;
char *p1,*p2;
char word1[100];
char word2[100];
fseek(f_input,strlen(word),SEEK_END);
fgets(word1,100,f_input);
 p1 = strchr(word1,'"');
 p2 = strrchr(word1,'"');
 if (p2 && (p1 != p2))
  {
	for (i=1;word1[i] != '"' && i< 100 ;i++)
		 word2[i] = word1[i];
	printf(" %s    : is   a valid string \n",word2);
  }
  printf(" %s    : is  not a valid string \n",word);

}