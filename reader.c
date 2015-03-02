#include "data.h"
#include "lib/mpc/mpc.h"

lval* lval_read_num(mpc_ast_t* t){
    errno = 0;
    long x = strtol(t->contents, NULL, 10);
    return errno != ERANGE ?
        lval_num(x) : lval_err("invalid number");
}

lval* lval_read_bool(mpc_ast_t* t){
    errno = 0;
    if (strstr(t->contents, "true")){
        return lval_bool(1);
    }
    else if (strstr(t->contents, "false")){
        return lval_bool(0);
    }
    else return lval_err("not a boolean"); // and this should not happen!
}


lval* lval_add(lval* v, lval* x){
    v->count++;
    v->cell = realloc(v->cell, sizeof(lval*) * v->count);
    v->cell[v->count-1] = x;
    return v;
}

lval* lval_read(mpc_ast_t* t){
    if (strstr(t->tag, "boolean")){
        return lval_read_bool(t);
    }
    if (strstr(t->tag, "numeric")){
        return lval_read_num(t);
    }
    if (strstr(t->tag, "symbol")){
        return lval_sym(t->contents);
    }

    lval* x = NULL;
    if (strcmp(t->tag, ">") == 0){
        x = lval_list();
    }
    if (strstr(t->tag, "list")){
        x = lval_list();
    }

    for (int i = 0; i < t->children_num; i++){
        if (strcmp(t->children[i]->contents, "(") == 0){ continue; }
        if (strcmp(t->children[i]->contents, ")") == 0){ continue; }
        if (strcmp(t->children[i]->contents, "{") == 0){ continue; }
        if (strcmp(t->children[i]->contents, "}") == 0){ continue; }
        if (strcmp(t->children[i]->contents, "[") == 0){ continue; }
        if (strcmp(t->children[i]->contents, "]") == 0){ continue; }
        if (strcmp(t->children[i]->tag,  "regex") == 0){ continue; }
        x = lval_add(x, lval_read(t->children[i]));
    }

    return x;
}

