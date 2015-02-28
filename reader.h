#ifndef __READER_H__
#define __READER_H__

extern lval* lval_read_num(mpc_ast_t* t);
extern lval* lval_add(lval* v, lval* x);
extern lval* lval_read(mpc_ast_t* t);

#endif
