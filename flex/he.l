%%
he 	printf("found keyword HE");
%%
int yywrap(void) {
return 1;
}
int main(void) {
yylex();
return 0;
}