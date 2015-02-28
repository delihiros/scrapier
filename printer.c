#include "data.h"
#include "printer.h"

void lval_expr_print(lval* v, char open, char close);

void lval_print(lval* v){
    switch (v->type){
        case LVAL_NUM:
            printf("%li", v->num); break;
        case LVAL_ERR:
            printf("Error: %s", v->err); break;
        case LVAL_SYM:
            printf("%s", v->sym); break;
        case LVAL_LIST:
            lval_expr_print(v, '(', ')'); break;
    }
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

void lval_println(lval* v){
    lval_print(v);
    putchar('\n');
}
