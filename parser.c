#include "lib/mpc/mpc.h"
#include "parser.h"

mpc_parser_t* Boolean;  
mpc_parser_t* Numeric;
mpc_parser_t* Character;
mpc_parser_t* String;
mpc_parser_t* Regex;
mpc_parser_t* Keyword;
mpc_parser_t* Symbol;
mpc_parser_t* Hashmap;
mpc_parser_t* List;
mpc_parser_t* Vector;
mpc_parser_t* Sequence;
mpc_parser_t* Expression;
mpc_parser_t* Scrapier;


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

void init_parser(){
    Boolean    = mpc_new("boolean");
    Numeric    = mpc_new("numeric");
    Character  = mpc_new("character");
    String     = mpc_new("string");
    Regex      = mpc_new("regex");
    Keyword    = mpc_new("keyword");
    Symbol     = mpc_new("symbol");
    Hashmap    = mpc_new("hashmap");
    List       = mpc_new("list");
    Vector     = mpc_new("vector");
    Sequence   = mpc_new("sequence");
    Expression = mpc_new("expression");
    Scrapier   = mpc_new("scrapier");

    mpca_lang(MPCA_LANG_DEFAULT,
            "boolean : \"true\" | \"false\" ;\n"
            "numeric : /-?[0-9]+/ ;\n"
            "character : /\\\\./ ;"
            "string : /\"(\\\\.|[^\"])*\"/ ;"
            "regex : /#\"(\\\\.|[^\"])*\"/ ;"
            "keyword : /:.+/ ;"
            "symbol  : /[a-zA-Z0-9><-+*\\/]+/ ;"
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
            "           | <symbol>"
            "           | <sequence> ;"
            "scrapier : /^/ <expression> /$/ ;"
            ,
        Boolean, Numeric, Character, String, Regex, Keyword, Symbol, Hashmap, List, Vector, Sequence, Expression, Scrapier);
}

void cleanup_parser(){
    mpc_cleanup(13, Boolean, Numeric, Character, String, Regex, Keyword, Symbol, Hashmap, List, Vector, Sequence, Expression, Scrapier);
}
