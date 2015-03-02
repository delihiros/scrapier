#ifndef __READER_H__
#define __READER_H__

extern lval* lval_read_num(mpc_ast_t* t);
extern lval* lval_read_bool(mpc_ast_t* t);
extern lval* lval_read_num(mpc_ast_t* t);
extern lval* lval_read_char(mpc_ast_t* t);
extern lval* lval_read_str(mpc_ast_t* t);
extern lval* lval_read_regex(mpc_ast_t* t);
extern lval* lval_read_keyword(mpc_ast_t* t);
extern lval* lval_read_sym(mpc_ast_t* ts);
extern lval* lval_read_hashmap(mpc_ast_t* t);
extern lval* lval_read_list(mpc_ast_t* t);
extern lval* lval_read_vector(mpc_ast_t* t);

extern lval* lval_add(lval* v, lval* x);
extern lval* lval_read(mpc_ast_t* t);

#endif
