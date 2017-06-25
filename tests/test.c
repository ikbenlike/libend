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
    SET(CALL(calloc, 1, CALL(strlen, str) + 1), a FIELD_ACCESSOR_POINTER str) LINETERM
    CALL(strcpy, a FIELD_ACCESSOR_POINTER str, str) LINETERM
    SET(n, a FIELD_ACCESSOR_POINTER data FIELD_ACCESSOR i) LINETERM
    RET a LINETERM
END



FUNCTION(__delete__testing, VOID, testing POINTER a) START
    IF(a NEQ NULL) THEN
        IF(a FIELD_ACCESSOR_POINTER str NEQ NULL) THEN
            CALL(free, a FIELD_ACCESSOR_POINTER str) LINETERM
        END
        CALL(free, a) LINETERM
ENND



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



FUNCTION(loopdyloop, VOID) START
    CALL(puts, "while") LINETERM
    VARIABLE(0, i, INT) LINETERM
    LOOP_WHILE(i ST 10, THEN
        POST_INCR(GET(i)) LINETERM
        CALL(printf, "%d\n", GET(i)) LINETERM
    END) LINETERM
    CALL(puts, "for") LINETERM
    LOOP_FOR(INT i = 0, i < 10, i++, THEN
        CALL(printf, "%d\n", GET(i)) LINETERM
    END) LINETERM
    MAKE_NEW_ARRAY(x, INT, START 1, 2, 3, 4 END) LINETERM 
    CALL(puts, "foreach") LINETERM
    LOOP_FOREACH(GET(x), INT, 4, THEN
        CALL(printf, "%d at index %d\n", GET(__lfe_value__), GET(__lfe_index__)) LINETERM
    END) LINETERM
    SET(10, i) LINETERM
    VARIABLE(TRUE, first, BOOL) LINETERM
    CALL(puts, "do while") LINETERM
    LOOP_DOWHILE(i < 10, THEN
        WHEN(first) THEN
            CALL(printf, "%d\n", GET(i)) LINETERM
            i -= 10 LINETERM
            SET(FALSE, first) LINETERM
        END
        CALL(printf, "%d\n", POST_INCR(GET(i))) LINETERM
    END) LINETERM
END

ENTRYPOINT_MAIN(
    // REGISTER_VARIABLE(t, testing) LINETERM
    // MAKE_STRUCT_CLASS(t, &__init_testing__) LINETERM
    VARIABLE(NEW(testing, "ayyy", 10), t, testing POINTER) LINETERM
    CALL(puts, t FIELD_ACCESSOR_POINTER str) LINETERM
    CALL(printf, "%i\n", t FIELD_ACCESSOR_POINTER data FIELD_ACCESSOR i) LINETERM
    DELETE(testing, t) LINETERM
    REGISTER_VARIABLE(a, GET(testing)) LINETERM
    SET(CALL(malloc, CALL(strlen, "ayyy") + 1), GET(a.str)) LINETERM
    CALL(strcpy, GET(a FIELD_ACCESSOR str), "ayyy") LINETERM
    //SET("ayyy", a.str) LINETERM
    SET(10, GET(a FIELD_ACCESSOR data FIELD_ACCESSOR i)) LINETERM
    CALL(puts, a FIELD_ACCESSOR str) LINETERM
    CALL(printf, "%c\n", a FIELD_ACCESSOR str INDEX(3)) LINETERM
    CALL(printf, "%i\n", a FIELD_ACCESSOR data FIELD_ACCESSOR i) LINETERM
    CALL(test) LINETERM
    IF(a FIELD_ACCESSOR str NQ NULL) THEN
        CALL(free, a FIELD_ACCESSOR str) LINETERM
    END
    IF(argc EQ 2) THEN
        CALL(puts, argv INDEX(1)) LINETERM
        BYE(1) LINETERM
    END
    CALL(loopdyloop) LINETERM
    PRINT_DOC("START") LINETERM
    RET 0 LINETERM
)
