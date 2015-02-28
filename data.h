#ifndef __DATA_H__
#define __DATA_H__

typedef struct lval {
    int type;
    long num;

    char* err;
    char* sym;

    int count;
    struct lval **cell;
} lval;

enum { LVAL_NUM, LVAL_LIST, LVAL_SYM, LVAL_ERR };
enum { LERR_DIV_ZERO, LERR_BAD_OP, LERR_BAD_NUM };

extern lval* lval_num(long x);
extern lval* lval_err(char* m);
extern lval* lval_sym(char* s);
extern lval* lval_list(void);
extern void lval_del(lval* v);

#endif
