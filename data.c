#include "stdlib.h"
#include "string.h"
#include "data.h"

lval* lval_bool(int b){
    lval* v = malloc(sizeof(lval));
    v->type = LVAL_BOOL;
    v->b = b;
    return v;
}

lval* lval_num(long x){
    lval* v = malloc(sizeof(lval));
    v->type = LVAL_NUM;
    v->num = x;
    return v;
}

lval* lval_char(char c){
    lval* v = malloc(sizeof(lval));
    v->type = LVAL_CHAR;
    v->c = c;
    return v;
}

lval* lval_str(char* s){
    lval* v = malloc(sizeof(lval));
    v->type = LVAL_STRING;
    v->str = malloc(strlen(s) + 1);
    strcpy(v->str, s);
    return v;
}

lval* lval_regex(char* r){
    lval* v = malloc(sizeof(lval));
    v->type = LVAL_REGEX;
    v->str = malloc(strlen(r) + 1);
    strcpy(v->regex, r);
    return v;
}

lval* lval_keyword(char* k){
    lval* v = malloc(sizeof(lval));
    v->type = LVAL_KEYWORD;
    v->keyword = malloc(strlen(k) + 1);
    strcpy(v->keyword, k);
    return v;
}

lval* lval_sym(char* s){
    lval* v = malloc(sizeof(lval));
    v->type = LVAL_SYM;
    v->sym = malloc(strlen(s) + 1);
    strcpy(v->sym, s);
    return v;
}

lval* lval_hashmap(void){
    lval* v = malloc(sizeof(lval));
    v->type = LVAL_HASHMAP;
    v->count = 0;
    v->cell = NULL;
    return v;
}

lval* lval_list(void){
    lval* v = malloc(sizeof(lval));
    v->type = LVAL_LIST;
    v->count = 0;
    v->cell = NULL;
    return v;
}

lval* lval_vector(void){
    lval* v = malloc(sizeof(lval));
    v->type = LVAL_VECTOR;
    v->count = 0;
    v->cell = NULL;
    return v;
}

lval* lval_err(char* m){
    lval* v = malloc(sizeof(lval));
    v->type = LVAL_ERR;
    v->err = malloc(strlen(m) + 1);
    strcpy(v->err, m);
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

