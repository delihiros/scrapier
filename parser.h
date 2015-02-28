#ifndef __PARSER_H__
#define __PARSER_H__

#include "lib/mpc/mpc.h"

extern mpc_parser_t* Boolean;  
extern mpc_parser_t* Numeric;
extern mpc_parser_t* Character;
extern mpc_parser_t* String;
extern mpc_parser_t* Regex;
extern mpc_parser_t* Keyword;
extern mpc_parser_t* Symbol;
extern mpc_parser_t* Hashmap;
extern mpc_parser_t* List;
extern mpc_parser_t* Vector;
extern mpc_parser_t* Sequence;
extern mpc_parser_t* Expression;
extern mpc_parser_t* Scrapier;


extern void print_ast(mpc_ast_t* t, int depth);
extern void init_parser();
extern void cleanup_parser();

#endif
