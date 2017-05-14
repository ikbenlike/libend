#define START {
#define END }
#define LOOP while(1)
#define WHILE(x) while(x)
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
#define POINTER *
#define PPOINTER **
#define PPPOINTER ***
#define LINETERM ;
#define IF if 
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
