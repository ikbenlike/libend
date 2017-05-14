#include <stdio.h>
#include <stdlib.h>
#define __END_INCLUDE_STD_
#include "end.h"


STRUCTURE(testing) START
   REGISTER_VARIABLE(str, CHAR POINTER) LINETERM 
END LINETERM

TYPEDEFINITION(testing, STRUCTURE(testing)) LINETERM



FUNCTION(test, VOID) START 
    VARIABLE("ayyy", str, CHAR POINTER) LINETERM
    VARIABLE(0, i, INT) LINETERM
    WHILE(i++ ST 10) THEN
        CALL(puts, GET(str)) LINETERM
    END
    REGISTER_VARIABLE(a, CHAR POINTER) LINETERM
    SET("end", a) LINETERM
    CALL(puts, GET(a)) LINETERM
    RET LINETERM
END 



FUNCTION(main, INT, INT argc, CHAR PPOINTER argv) START
    // VARIABLE("ayyy", str, CHAR POINTER) LINETERM
    // CALL(puts, GET(str)) LINETERM
    VARIABLE({.str = "Hello, World!"}, a, GET(testing)) LINETERM
    CALL(puts, a.str) LINETERM
    CALL(printf, "%c\n", a.str INDEX(3)) LINETERM
    CALL(test) LINETERM
    IF(argc EQ 2) THEN
        CALL(puts, argv INDEX(1)) LINETERM
        BYE(1) LINETERM
    END
    PRINT_DOC("START") LINETERM
    RET 0 LINETERM
END
