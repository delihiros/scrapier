#ifndef __PRINTER_H__
#define __PRINTER_H__

extern void lval_print(lval* v);
extern void lval_expr_print(lval* v, char open, char close);
extern void lval_hash_print(lval* v);
extern void lval_vec_print(lval* v);
extern void lval_println(lval* v);

#endif
