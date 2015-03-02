#include "stdio.h"

#include "data.h"
#include "printer.h"

void lval_expr_print(lval* v, char open, char close);
void lval_hash_print(lval* v);
void lval_vec_print(lval* v);

void lval_print(lval* v){
    switch (v->type){
        case LVAL_BOOL:
            if (v->b){ printf("true"); }
            else printf("false");
            break;
        case LVAL_NUM:
            printf("%li", v->num); break;
        case LVAL_CHAR:
            printf("%c", v->c); break;
        case LVAL_STRING:
            printf("\"%s\"", v->str); break;
        case LVAL_REGEX:
            printf("#\"%s\"", v->regex); break;
        case LVAL_KEYWORD:
            printf("%s", v->keyword); break;
        case LVAL_SYM:
            printf("%s", v->sym); break;
        case LVAL_HASHMAP:
            lval_hash_print(v); break;
        case LVAL_LIST:
            lval_expr_print(v, '(', ')'); break;
        case LVAL_VECTOR:
            lval_vec_print(v); break;
        case LVAL_ERR:
            printf("Error: %s", v->err); break;
    }
}

void lval_hash_print(lval* v){
    putchar('{');
    for (int i = 0; i < v->count; i++){
        lval_print((lval*)v->cell[i]);
        if (i != (v->count-1)){
            putchar(' ');
        }
    }
    putchar('}');
}

void lval_expr_print(lval* v, char open, char close){
    putchar(open);
    for (int i = 0; i < v->count; i++){
        lval_print((lval*)v->cell[i]);
        if (i != (v->count-1)){
            putchar(' ');
        }
    }
    putchar(close);
}

void lval_vec_print(lval* v){
    putchar('[');
    for (int i = 0; i < v->count; i++){
        lval_print((lval*)v->cell[i]);
        if (i != (v->count-1)){
            putchar(' ');
        }
    }
    putchar(']');
}

void lval_println(lval* v){
    lval_print(v);
    putchar('\n');
}
