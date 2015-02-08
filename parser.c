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

void print_ast(mpc_ast_t* t, int depth){
    int d = 0;
    while (d++ < depth){ printf("\t"); }
    printf("tag: %s\n", t->tag);
    d = 0;
    while (d++ < depth){ printf("\t"); }
    printf("contents: %s\n", t->contents);
    int i = 0; 
    for (i = 0; i < t->children_num; i++){
        print_ast(t->children[i], depth+1);
    }
}

int main(){
    mpc_parser_t* Boolean    = mpc_new("boolean");
    mpc_parser_t* Numeric    = mpc_new("numeric");
    mpc_parser_t* Character  = mpc_new("character");
    mpc_parser_t* String     = mpc_new("string");
    mpc_parser_t* Regex      = mpc_new("regex");
    mpc_parser_t* Keyword    = mpc_new("keyword");
    mpc_parser_t* Variable   = mpc_new("variable");
    mpc_parser_t* Hashmap    = mpc_new("hashmap");
    mpc_parser_t* List       = mpc_new("list");
    mpc_parser_t* Vector     = mpc_new("vector");
    mpc_parser_t* Sequence   = mpc_new("sequence");
    mpc_parser_t* Expression = mpc_new("expression");
    mpc_parser_t* Scrapier   = mpc_new("scrapier");

    mpca_lang(MPCA_LANG_DEFAULT,
            "boolean : \"true\" | \"false\" ;\n"
            "numeric : /-?[0-9]+/ ;\n"
            "character : /\\\\./ ;"
            "string : /\"(\\\\.|[^\"])*\"/ ;"
            "regex : /#\"(\\\\.|[^\"])*\"/ ;"
            "keyword : /:.+/ ;"
            "variable : /[a-zA-Z0-9><-+*\\/]+/ ;"
            "hashmap : '{' (<expression> <expression>)* '}' ;"
            "list : '(' <expression>* ')' ;"
            "vector : '[' <expression>* ']' ;"
            "sequence : <hashmap> | <list> | <vector> ;"
            "expression : <boolean>"
            "           | <numeric>"
            "           | <character>"
            "           | <string>"
            "           | <regex>"
            "           | <keyword>"
            "           | <variable>"
            "           | <sequence> ;"
            "scrapier : /^/ <expression> /$/ ;"
            ,
            Boolean, Numeric, Character, String, Regex, Keyword, Variable, Hashmap, List, Vector, Sequence, Expression, Scrapier);

    while (1) {
        char* input = readline("scrapier> ");

        mpc_result_t r;
        if (mpc_parse("<stdin>", input, Scrapier, &r)){
            print_ast(r.output, 0);
            mpc_ast_delete(r.output);
        }
        else {
            mpc_err_print(r.error);
            mpc_err_delete(r.error);
        }
        free(input);
    }
    mpc_cleanup(13, Boolean, Numeric, Character, String, Regex, Keyword, Variable, Hashmap, List, Vector, Sequence, Expression, Scrapier);
    return 0;
}
