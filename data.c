#include "stdlib.h"
#include "string.h"
#include "data.h"

lval* lval_num(long x){
    lval* v = malloc(sizeof(lval));
    v->type = LVAL_NUM;
    v->num = x;
    return v;
}

lval* lval_err(char* m){
    lval* v = malloc(sizeof(lval));
    v->type = LVAL_ERR;
    v->err = malloc(strlen(m) + 1);
    strcpy(v->err, m);
    return v;
}

lval* lval_list(void){
    lval* v = malloc(sizeof(lval));
    v->type = LVAL_LIST;
    v->count = 0;
    v->cell = NULL;
    return v;
}

void lval_del(lval* v){
    switch (v->type){
        case LVAL_NUM:
            break;
        case LVAL_ERR:
            free(v->err); break;
        case LVAL_SYM:
            free(v->sym); break;
        case LVAL_LIST:
            for (int i = 0; i < v->count; i++){
                lval_del((lval*)v->cell[i]);
            }
            free(v->cell);
            break;
    }

    free(v);
}

