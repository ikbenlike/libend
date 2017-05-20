#define __END_INCLUDE_STD_
#include "../src/end.h"



ENTRYPOINT_MAIN(
    REGISTER_VARIABLE(a, CHAR POINTER) LINETERM
    SET(CALL(calloc, 1, CALL(strlen, "ayyy") + 1), a) LINETERM
    CALL(strcpy, a, "ayyy") LINETERM
    CALL(puts, a) LINETERM
    CALL(free, a) LINETERM
    BYE(0) LINETERM
    RET 0 LINETERM
)
