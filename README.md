# Scrapier

A Language for scraping. Fast booting, easy to use.

# Syntax

```
<numeric> ::= integer | float
<boolean> ::= true | false
<char> ::= \ character
<string> ::= " no-\"* "
<keyword> ::= : alpha+num+symbol
<variable> ::= (alpha alpha+num+symbol*)(\.<variable>)*
<hashmap> ::= { (<value> <value>)* }
<list> ::= ( <value>* )
<vector> ::=  [ <value>* ]
<range> ::= [<numeric...<numeric>]
<sequence> ::= <hashmap> | <list> | <vector> | <range>
<value> ::= <keyword> | <numeric> | <keyword> | <sequence> | <variable>
```

# Build

