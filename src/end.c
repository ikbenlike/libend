#define __END_INCLUDE_STD_
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
    puts("alloc'd executor_t");
    e->argc = argc;
    e->args = args;
    e->callee = f;
    return e;
}


queue_t *e_queue_setup(int n){
    queue_t *q = calloc(1, sizeof(queue_t));
    puts("alloc'd queue_t");
    q->queue = calloc(1, sizeof(executor_t) * n);
    puts("alloc'd queue");
    q->n = n;
    q->index = 0;
    return q;
}


queue_t *e_enqueue(queue_t *q, executor_t *e){
    if(q->n - q->index < 5){
        executor_t *tmp = realloc(q->queue, (q->n + 5) * sizeof(executor_t));
        puts("realloc'd");
        if(tmp != NULL){
            q->queue = tmp;
        }
    }
    q->queue[q->index++] = *e;
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
                        if(q->queue[i].args[x].data.charp != NULL){
                            free(q->queue[i].args[x].data.charp);
                            puts("freedom");
                        }
                        break;
                    case intp:
                        if(q->queue[i].args[x].data.intp != NULL){
                            free(q->queue[i].args[x].data.intp);
                        }
                        break;
                    case floatp:
                        if(q->queue[i].args[x].data.floatp != NULL){
                            free(q->queue[i].args[x].data.floatp);
                        }
                        break;
                    case longp:
                        if(q->queue[i].args[x].data.longp != NULL){
                            free(q->queue[i].args[x].data.longp);
                        }
                        break;
                    case doublep:
                        if(q->queue[i].args[x].data.doublep != NULL){
                            free(q->queue[i].args[x].data.doublep);
                        }
                        break;
                    case shortp:
                        if(q->queue[i].args[x].data.shortp != NULL){
                            free(q->queue[i].args[x].data.shortp);
                        }
                        break;
                    case voidp:
                        if(q->queue[i].args[x].data.voidp != NULL){
                            free(q->queue[i].args[x].data.voidp);
                        }
                        break;
                    default:
                        break;
                }
                q->queue[i].callee = NULL;
            }
        }
        for(int i = 0; i < q->n; i++){
            if(q->queue[i].args != NULL){
                free(q->queue[i].args);
                puts("free q->queue[i].args");
            } 
        }
        if(q->queue != NULL){
            free(q->queue);
            puts("free q->queue");
        }
        free(q);
        puts("free q");
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
    e_enqueue(q, e_setup(1, a, &executor_puts));
    e_run(q);
    e_free(q);
    free(a);
    printf("%i\n", sizeof(executor_t) * 5);
}
