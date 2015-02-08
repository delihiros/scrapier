# Scrapier

A Language for scraping. Fast booting, easy to use.

# Syntax

```c
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
```

# Build

```sh
./build.sh
```
