#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "data.h"
#include "parser.h"
#include "reader.h"
#include "printer.h"
#include "eval.h"

#include "lib/mpc/mpc.h"

static char buffer[2048];

char* readline(char* prompt) {
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);
    char* cpy = malloc(strlen(buffer)+1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy)-1] = '\0';
    return cpy;
}

int main(){

    init_parser();
    while (1) {
        char* input = readline("scrapier> ");

        mpc_result_t r;
        if (mpc_parse("<stdin>", input, Scrapier, &r)){
            //print_ast(r.output, 0); // for debugging
            lval* x = lval_read(r.output);
            lval_println(x);
            lval_del(x);
            mpc_ast_delete(r.output);
        }
        else {
            mpc_err_print(r.error);
            mpc_err_delete(r.error);
        }
        free(input);
    }
    cleanup_parser();
    return 0;
}
