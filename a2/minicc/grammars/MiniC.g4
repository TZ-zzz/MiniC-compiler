grammar MiniC;

@header {
#include <vector>
#include "Program.h"
#include "Declarations.h"
#include "Statements.h"
#include "Exprs.h"
#include "Terms.h"
}
/*Add your grammar rules in Assignment 2*/
/*Then add compiler actions in Assignment 3*/
prog returns [minicc::Program *val]
/*You may need init in Assignment 3*/
@init {}
:	preamble decl EOF
;
preamble:  '#include' '"minicio.h"'
    |  ;
decl
:   declentry+
    ;
declentry
:   vardecl+
    | rettype funcname '(' parameters ')' scope
    | rettype funcname '(' parameters ')' ';'
    ;
vardecl
:   vartype varlist ';' 
    ;
scope
/*You may need init in Assignment 3*/
@init {}
:  '{' vardecl+ stmt+ '}'
    | '{' stmt+ '}'
    | '{'  '}'
    ;
stmt
:   expr ';'
    | 'if' '(' expr ')' stmt
    | 'if' '(' expr ')' stmt 'else' stmt
    | 'for' '(' expropt ';' expropt ';' expropt ')' stmt
    | 'while' '(' expr ')' stmt
    | 'break' ';'
    | 'return' ';'
    | 'return' expr ';'
    | scope
    ;

varlist
:   varlistentry
    | varlistentry (',' varlistentry)+
    ;
varlistentry
:   varname
    | varname '[' INT ']'
    ;
vartype
:   'int'
    | 'bool'
    ;
rettype
:   'void'
    | vartype
    ;
parameters
:   
    | parameterlist
    ;
parameterlist
:   parameterentry
    | parameterentry (',' parameterentry)+
    ;
parameterentry
:   vartype parametername
    ;
expropt
:   expr
    |
    ;
expr
:   INT
    | '-' expr
    | '!' expr
    | expr ('*' | '/') expr
    | expr ('+'|'-') expr
    | 'true'
    | 'false'
    | expr ('==' | '!=' | '<' | '<=' | '>' | '>=') expr
    | expr '&&' expr
    | expr '||' expr
    | '(' expr ')'
    | var
    | funcname '(' arguments ')'
    | var '=' expr
    | parametername
    ;
var
:   varname
    | varname '[' expr ']'
    ;
arguments
:   
    | argumentlist
    ;
argumentlist
:   expr
    | expr (',' expr)+
    ;
varname
:   ID
    ;
funcname
:   ID
    ;
parametername
:   ID
    ;

ID:     [a-zA-Z][a-zA-Z0-9_]* ;
INT:    [0] | ([1-9][0-9]*) ;
WS:     [ \t\r\n]+ -> skip;
COMMENT: '//' (~[\r\n])* -> skip;
