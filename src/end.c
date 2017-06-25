#define __END_INCLUDE_STD_
#include <stdbool.h>
#include "end.h"

enum arg_type {
    integer,
    character,
    floating,
    long_int,
    double_float,
    short_int,
    charp,
    intp,
    floatp,
    longp,
    doublep,
    shortp,
    voidp
};

typedef struct {
    enum arg_type type;
    union Data {
        int integer;
        char character;
        float floating;
        long int lint;
        double dfloat;
        short sint;
        char *charp;
        int *intp;
        float *floatp;
        long int *longp;
        double *doublep;
        short *shortp;
        void *voidp;
    } data;
} arg_t;

typedef struct {
    int argc;
    arg_t *args;
    void (*callee)(arg_t*);
} executor_t;

typedef struct {
    int index;
    int n;
    executor_t *queue;
} queue_t;


executor_t *e_setup(int argc, arg_t *args, void *f){
    executor_t *e = calloc(1, sizeof(executor_t));
    //puts("alloc'd executor_t");
    e->argc = argc;
    e->args = args;
    e->callee = f;
    return e;
}


queue_t *e_queue_setup(int n){
    queue_t *q = calloc(1, sizeof(queue_t));
    //puts("alloc'd queue_t");
    q->queue = calloc(1, sizeof(executor_t) * n);
    //puts("alloc'd queue");
    q->n = n;
    q->index = 0;
    return q;
}


queue_t *e_enqueue(queue_t *q, executor_t *e){
    if(q->n - q->index < 5){
        executor_t *tmp = realloc(q->queue, (q->n + 5) * sizeof(executor_t));
        q->n += 5;
        //puts("realloc'd");
        if(tmp != NULL){
            q->queue = tmp;
        }
    }
    q->queue[q->index].argc = e->argc;
    q->queue[q->index].args = e->args;
    q->queue[q->index++].callee = e->callee;
    free(e);
    return q;
}


int e_run(queue_t *q){
    int i = 0;
    for(i = 0; i < q->index; i++){
        q->queue[i].callee(q->queue[i].args);
    }
    return i;
}

int e_free(queue_t *q){
    if(q != NULL){
        for(int i = 0; i < q->index; i++){
            for(int x = 0; x < q->queue[i].argc; x++){
                switch(q->queue[i].args[x].type){
                    case charp:
                        free(q->queue[i].args[x].data.charp);
                        break;
                    case intp:
                        free(q->queue[i].args[x].data.intp);
                        break;
                    case floatp:
                        free(q->queue[i].args[x].data.floatp);
                        break;
                    case longp:
                        free(q->queue[i].args[x].data.longp);
                        break;
                    case doublep:
                        free(q->queue[i].args[x].data.doublep);
                        break;
                    case shortp:
                        free(q->queue[i].args[x].data.shortp);
                        break;
                    case voidp:                    
                        free(q->queue[i].args[x].data.voidp);                        
                        break;
                    default:
                        break;
                }
                q->queue[i].callee = NULL;
            }
        }
        for(int i = 0; i < q->index; i++){
            free(q->queue[i].args);
        }
        free(q->queue);
        free(q);
        return 0;
    }
    else {
        return 1;
    }
}

void executor_puts(arg_t *args){
    if(args[0].type == charp){
        puts(args[0].data.charp);
    }
}

int main(void){
    queue_t *q = e_queue_setup(5);
    arg_t *a = calloc(1, sizeof(arg_t));
    a->type = charp;
    a->data.charp = calloc(1, strlen("Hello, World!") + 1);
    strcpy(a->data.charp, "Hello, World!");
    arg_t *b = calloc(1, sizeof(arg_t));
    b->type = charp;
    b->data.charp = calloc(1, strlen("Hello, World!") + 1);
    strcpy(b->data.charp, "Hello, World!");
    e_enqueue(q, e_setup(1, a, &executor_puts));
    e_enqueue(q, e_setup(1, b, &executor_puts));
    //free(e);
    e_run(q);
    e_free(q);
    int i = 0;
    puts("while");
    LOOP_WHILE(i < 10, {
        i++;
        printf("%d\n", i);
        BRK_LP(while);
    });
    puts("for");
    LOOP_FOR(int i = 0, i < 10, i++, {
        printf("%d\n", i);
        BRK_LP(for);
    });
    int x[] = {1, 2, 3, 4};
    puts("foreach");
    LOOP_FOREACH(x, int, 4, {
        printf("%d at index %d\n", __lfe_value__, __lfe_index__);
        BRK_LP(foreach);
    });
    i = 10;
    bool first = true;
    puts("do while");
    LOOP_DOWHILE(i < 10, {
        if(first){
            printf("%d\n", i);
            i -= 10;
            first = false;
        }
        if(3 == 4){
            BRK_LP(dowhile);
        }
        printf("%d\n", i++);
    });
    int index = 0;
    LOOP_UNTIL(x, 3, sizeof(x), index, {
        printf("index %d\n", __lwh_index__);
        if(3 == 4){
            BRK_LP(until);
        }
    });
    printf("found value %d at index %d\n", x[index], index);
}
