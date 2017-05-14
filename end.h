#ifdef __END_INCLUDE_STD_
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
#endif


#define START {
#define THEN {
#define END }
#define ENND }}
#define ENNND }}}
#define LOOP while(1)
#define WHILE(x) while(x)
#define FOR(X) for(x)
#define FUNCTION(x, y, ...) y x(__VA_ARGS__)
#define CALL(x, ...) x(__VA_ARGS__)
#define VARIABLE(x, y, z) z y = x
#define REGISTER_VARIABLE(x, y) y x
#define SET(x, y) y = x
#define GET(x) x
#define INT int 
#define CHAR char 
#define FLOAT float 
#define LONG long
#define VOID void
#define POINTER *
#define PPOINTER **
#define PPPOINTER ***
#define LINETERM ;
#define IF(x) if(x)
#define ELIF(x) else if(x) 
#define ELSE else 
#define RET return
#define COMMENT //
#define BREAK break 
#define CONT continue 
#define ST <
#define LT >
#define EQ ==
#define NQ !=
#define OR ||
#define AND &&
#define ADD +
#define SUB -
#define BYE(x) CALL(exit, x)
#define INDEX(x) [x]

#define PRINT_DOC(x) IF(strcmp(x, "START") == 0){puts("Open new scope, '{'");} \
                   ELIF(strcmp(x, "THEN") == 0){puts("Open new scope after a conditional, '{'");} \
                   ELIF(strcmp(x, "END") == 0){puts("Close scope, '}'");} \
                   ELIF(strcmp(x, "ENND") == 0){puts("Close two scopes, '}}'");} \
                   ELIF(strcmp(x, "ENNND") == 0){puts("Close three scopes, '}}}'");} \
                   ELIF(strcmp(x, "LOOP") == 0){puts("Infinite loop, 'while(1)'");} \
                   ELIF(strcmp(x, "WHILE") == 0){puts("While loop, 'while(x)'");} \
                   ELIF(strcmp(x, "FOR") == 0){puts("For loop, 'for(x)'");} \
                   ELIF(strcmp(x, "FUNCTION") == 0){puts("Function definition, FUNCTION(main, INT, VOID) == 'int main(void)'");} \
                   ELIF(strcmp(x, "CALL") == 0){puts("Call function, CALL(puts, \"test\") == 'puts(\"test\")'");} \
                   ELIF(strcmp(x, "VARIABLE") == 0){puts("Define and initialize variable, VARIABLE('a', b, CHAR) == 'char b = 'a''");} \
                   ELIF(strcmp(x, "REGISTER_VARIABLE") == 0){puts("Define variable, REGISTER_VARIABLE(a, CHAR) == 'char a;'");} \
                   ELIF(strcmp(x, "SET") == 0){puts("Change variable's value, SET('a', b) == 'b = 'a''");} \
                   ELIF(strcmp(x, "GET") == 0){puts("Get variable's value, GET(a) == 'a'");} \
                   ELIF(strcmp(x, "INT") == 0){puts("int");} \
                   ELIF(strcmp(x, "CHAR") == 0){puts("char");} \
                   ELIF(strcmp(x, "FLOAT") == 0){puts("float");} \
                   ELIF(strcmp(x, "LONG") == 0){puts("long");} \
                   ELIF(strcmp(x, "VOID") == 0){puts("void");} \
                   ELIF(strcmp(x, "POINTER") == 0){puts("pointer, *");} \
                   ELIF(strcmp(x, "PPOINTER") == 0){puts("pointer pointer, **");} \
                   ELIF(strcmp(x, "PPPOINTER") == 0){puts("pointer pointer pointer, ***");} \
                   ELIF(strcmp(x, "IF") == 0){puts("if, IF(x) == 'if(x)'");} \
                   ELIF(strcmp(x, "ELIF") == 0){puts("else if, ELIF(x) == 'else if(x)'");} \
                   ELIF(strcmp(x, "ELSE") == 0){puts("else");} \
                   ELIF(strcmp(x, "RET") == 0){puts("return");} \
                   ELIF(strcmp(x, "COMMENT") == 0){puts("//, comment");} \
                   ELIF(strcmp(x, "BREAK") == 0){puts("break");} \
                   ELIF(strcmp(x, "CONT") == 0){puts("continue");} \
                   ELIF(strcmp(x, "ST") == 0){puts("smaller than, <");} \
                   ELIF(strcmp(x, "LT") == 0){puts("larger than, >");} \
                   ELIF(strcmp(x, "EQ") == 0){puts("equals, ==");} \
                   ELIF(strcmp(x, "NQ") == 0){puts("not equals, !=");} \
                   ELIF(strcmp(x, "OR") == 0){puts("or, ||");} \
                   ELIF(strcmp(x, "AND") == 0){puts("and, &&");} \
                   ELIF(strcmp(x, "ADD") == 0){puts("add, +");} \
                   ELIF(strcmp(x, "SUB") == 0){puts("substract, -");} \
                   ELIF(strcmp(x, "BYE") == 0){puts("BYE(x) == 'exit(x)'");} \
                   ELIF(strcmp(x, "PRINT_DOC") == 0){puts("PRINT_DOC(x) print simple description");} \
                   ELIF(strcmp(x, "INDEX") == 0){puts("INDEX(x) == '[x]'");}


