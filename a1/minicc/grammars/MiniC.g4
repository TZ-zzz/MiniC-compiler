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
:	
;
preamble:  ;
decl
:   
    ;
vardecl
:   
    ;
scope
/*You may need init in Assignment 3*/
@init {}
:  
    ;
stmt
:   
    ;
varlist
:    
    ;
varlistentry
:   
    ;
vartype
:   
    ;
rettype
:   
    ;
parameters
:   
    ;
parameterlist
:   
    ;
parameterentry
:   
    ;
expropt
:   
    ;
expr
:   
    ;
var
:   
    ;
arguments
:   
    ;
argumentlist
:   
    ;
varname
:   
    ;
funcname
:   
    ;
parametername
:   
    ;

ID:     [a-zA-Z][a-zA-Z0-9_]* ;
INT:    [0] | ([1-9][0-9]*) ;
WS:     [ \t\r\n]+ -> skip;
COMMENT: '//' (~[\r\n])* -> skip;
