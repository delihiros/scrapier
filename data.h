#ifndef __DATA_H__
#define __DATA_H__

typedef struct lval {
    int type;
    int b;
    long num;
    char c;
    char* str;
    char* regex;
    char* keyword;

    char* err;
    char* sym;

    int count;
    struct lval **cell;
} lval;

enum { LVAL_BOOL, LVAL_NUM, LVAL_CHAR, LVAL_STRING, LVAL_REGEX, LVAL_KEYWORD, LVAL_SYM, LVAL_HASHMAP, LVAL_LIST, LVAL_VECTOR, LVAL_ERR };
enum { LERR_DIV_ZERO, LERR_BAD_OP, LERR_BAD_NUM };

extern lval* lval_bool(int b);
extern lval* lval_num(long x);
extern lval* lval_char(char c);
extern lval* lval_str(char* s);
extern lval* lval_regex(char* r);
extern lval* lval_keyword(char* k);
extern lval* lval_sym(char* s);
extern lval* lval_hashmap(void);
extern lval* lval_list(void);
extern lval* lval_vector(void);
extern lval* lval_err(char* m);
extern void lval_del(lval* v);

#endif
