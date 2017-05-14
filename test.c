#include <stdio.h>
#include <stdlib.h>
#define __END_INCLUDE_STD_
#include "end.h"

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
    COMMENT VARIABLE("ayyy", str, CHAR POINTER) LINETERM
    COMMENT CALL(puts, GET(str)) LINETERM
    CALL(test) LINETERM
    IF(argc EQ 2) THEN
        BYE(1) LINETERM
    END
    PRINT_DOC("START");
    RET 0 LINETERM
END 
