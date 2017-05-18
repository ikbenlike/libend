#include <stdio.h>
#include <stdlib.h>
#define __END_INCLUDE_STD_
#include "../src/end.h"


STRUCTURE(testing) START
    REGISTER_VARIABLE(str, CHAR POINTER) LINETERM
    UNION(Data) START
        REGISTER_VARIABLE(i, INT) LINETERM
    END data LINETERM
    void (*__init__)(struct testing, char*, int);
END LINETERM

TYPEDEFINITION(testing, STRUCTURE(testing)) LINETERM



FUNCTION(__init__testing, testing POINTER, testing POINTER a, CHAR POINTER str, INT n) START
    SET(CALL(calloc, 1, CALL(strlen, str) + 1), a FIELD_ACCESSOR_ARROW str) LINETERM
    CALL(strcpy, a FIELD_ACCESSOR_ARROW str, str) LINETERM
    SET(n, a FIELD_ACCESSOR_ARROW data FIELD_ACCESSOR_DOT i) LINETERM
    RET a LINETERM
END 


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



/*FUNCTION(main, INT, INT argc, CHAR PPOINTER argv) START
    // VARIABLE("ayyy", str, CHAR POINTER) LINETERM
    // CALL(puts, GET(str)) LINETERM
    REGISTER_VARIABLE(a, GET(testing)) LINETERM
    SET(CALL(malloc, CALL(strlen, "ayyy") + 1), GET(a.str)) LINETERM
    CALL(strcpy, GET(a FIELD_ACCESSOR_DOT str), "ayyy") LINETERM
    //SET("ayyy", a.str) LINETERM
    SET(10, GET(a FIELD_ACCESSOR_DOT data FIELD_ACCESSOR_DOT i)) LINETERM
    CALL(puts, a FIELD_ACCESSOR_DOT str) LINETERM
    CALL(printf, "%c\n", a FIELD_ACCESSOR_DOT str INDEX(3)) LINETERM
    CALL(printf, "%i\n", a FIELD_ACCESSOR_DOT data FIELD_ACCESSOR_DOT i) LINETERM
    CALL(test) LINETERM
    IF(argc EQ 2) THEN
        CALL(puts, argv INDEX(1)) LINETERM
        BYE(1) LINETERM
    END
    PRINT_DOC("START") LINETERM
    RET 0 LINETERM
END*/

ENTRYPOINT_MAIN(
    // REGISTER_VARIABLE(t, testing) LINETERM
    // MAKE_STRUCT_CLASS(t, &__init_testing__) LINETERM
    VARIABLE(NEW(testing, "ayyy", 10), t, testing POINTER) LINETERM
    CALL(puts, t FIELD_ACCESSOR_ARROW str) LINETERM
    CALL(printf, "%i\n", t FIELD_ACCESSOR_ARROW data FIELD_ACCESSOR_DOT i) LINETERM
    REGISTER_VARIABLE(a, GET(testing)) LINETERM
    SET(CALL(malloc, CALL(strlen, "ayyy") + 1), GET(a.str)) LINETERM
    CALL(strcpy, GET(a FIELD_ACCESSOR_DOT str), "ayyy") LINETERM
    //SET("ayyy", a.str) LINETERM
    SET(10, GET(a FIELD_ACCESSOR_DOT data FIELD_ACCESSOR_DOT i)) LINETERM
    CALL(puts, a FIELD_ACCESSOR_DOT str) LINETERM
    CALL(printf, "%c\n", a FIELD_ACCESSOR_DOT str INDEX(3)) LINETERM
    CALL(printf, "%i\n", a FIELD_ACCESSOR_DOT data FIELD_ACCESSOR_DOT i) LINETERM
    CALL(test) LINETERM
    IF(argc EQ 2) THEN
        CALL(puts, argv INDEX(1)) LINETERM
        BYE(1) LINETERM
    END
    PRINT_DOC("START") LINETERM
    RET 0 LINETERM
)
