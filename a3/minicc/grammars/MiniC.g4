grammar MiniC;

@header {
#include <vector>
#include "Program.h"
#include "Declarations.h"
#include "Statements.h"
#include "Exprs.h"
#include "Terms.h"
#include <iostream>
}

prog returns [minicc::Program *val]
@init { { $val = new minicc::Program(); }
}
:	(preamble {$val->setSyslibFlag(true);}| ) (decl {$val->addChild($decl.dec); } )* EOF 
;
preamble:  '#include' '"minicio.h"';
decl returns [minicc::Declaration *dec]
:   vardecl {$dec = $vardecl.vd;}
    |   rettype funcname '(' parameters ')' scope 
    {
        minicc::FuncDeclaration *fd = new minicc::FuncDeclaration();
        fd->setHasBody(true);
        fd->addChild($rettype.rt);
        fd->addChild($funcname.fn);
        for (std::vector<minicc::Parameter *>::iterator i = $parameters.params.begin(); i != $parameters.params.end(); i++) {
            fd->addChild(*i);
        }
        fd->addChild($scope.sc);
        $dec = fd;
    }
    |   rettype funcname '(' parameters ')' ';'
    {
        minicc::FuncDeclaration *fd = new minicc::FuncDeclaration();
        fd->setHasBody(false);
        fd->addChild($rettype.rt);
        fd->addChild($funcname.fn);
        for (std::vector<minicc::Parameter *>::iterator i = $parameters.params.begin(); i != $parameters.params.end(); i++) {
            fd->addChild(*i);
        }
        $dec = fd;
    }
    ;
vardecl returns [minicc::VarDeclaration *vd]
:   vartype varlist ';'
    {
        $vd = new minicc::VarDeclaration();
        $vd->addChild($vartype.vt);
        for (std::vector<minicc::VarReference *>::iterator i = $varlist.vl.begin(); i != $varlist.vl.end(); i++) {
            $vd->addChild(*i);
        }
    }
    ;
scope returns [minicc::ScopeStatement *sc]
/*You may need init in Assignment 3*/
@init {$sc = new minicc::ScopeStatement();
        size_t n = 0;
        }
:  '{' (vardecl {   $sc->addChild($vardecl.vd);
                    n += $vardecl.vd->numVarReferences();
                }
    )*  (stmt {$sc->addChild($stmt.st);})* '}' {$sc->setNumVarDecl(n);}
    ;
stmt returns[minicc::Statement *st]
:   expr ';' 
    {  
        $st = new minicc::ExprStatement();
        $st->addChild($expr.e);
    }
    |   'if' '(' expr ')' stmt 
    {  
        $st = new minicc::IfStatement();
        $st->addChild($expr.e);
        $st->addChild($stmt.st);
    }
    |   'if' '(' expr ')' s1=stmt 'else' s2=stmt
    {
        $st = new minicc::IfStatement();
        $st->addChild($expr.e);
        $st->addChild($s1.st);
        $st->addChild($s2.st);
    }
    |   'for' '(' e1=expropt ';' e2=expropt ';' e3=expropt ')' stmt
    {
        $st = new minicc::ForStatement();
        $st->addChild($e1.ep);
        $st->addChild($e2.ep);
        $st->addChild($e3.ep);
        $st->addChild($stmt.st);
    }
    |   'while' '(' expr ')' stmt
    {
        $st = new minicc::WhileStatement();
        $st->addChild($expr.e);
        $st->addChild($stmt.st);
    }
    |   'break' ';'
    {
        $st = new minicc::BreakStatement();
    }
    |   'return' ';'
    {
        $st = new minicc::ReturnStatement();
    }
    |   'return' expr ';'
    {
        $st = new minicc::ReturnStatement();
        $st->addChild($expr.e);
    }
    |   scope
    {
        $st = $scope.sc;
    }
    ;
varlist returns [std::vector<minicc::VarReference *> vl]
:    varlistentry {std::vector<minicc::VarReference *> v; v.push_back($varlistentry.vle); $vl = v;}
    |   v1=varlist ',' varlistentry     
    {
        $vl = $v1.vl;
        $vl.push_back($varlistentry.vle);
    }
    ;
varlistentry returns [minicc::VarReference *vle]
:   varname 
    {
        $vle = new minicc::VarReference();
        $vle->addChild($varname.vn);
    }
    |   varname '[' INT ']'
    {
        $vle = new minicc::VarReference();
        $vle->addChild($varname.vn);
        $vle->addChild(minicc::ConstantLiteralExpr::fromString($INT.text));
    }
    ;
vartype returns [minicc::TypeReference *vt]
:    'int' {$vt = new minicc::TypeReference(Type::Int);}
    |   'bool' {$vt = new minicc::TypeReference(Type::Bool);}
    ;
rettype returns [minicc::TypeReference *rt]
:    'void' {$rt = new minicc::TypeReference(Type::Void);}
    |   vartype {$rt = $vartype.vt;}
    ;
parameters returns [std::vector<minicc::Parameter *> params]
:     /* eps */ {std::vector<minicc::Parameter *> p; $params = p;}
    |   parameterlist {$params = $parameterlist.pl;}
    ;
parameterlist returns [std::vector<minicc::Parameter *> pl]
:     parameterentry 
    {
        std::vector<minicc::Parameter *> p;
        p.push_back($parameterentry.pe);
        $pl = p;
    }
    |   p1=parameterlist ',' parameterentry
    {
        $pl = $p1.pl;
        $pl.push_back($parameterentry.pe);
    }
    ;
parameterentry returns [minicc::Parameter *pe]
:     vartype parametername
    {
        $pe = new minicc::Parameter();
        $pe->addChild($vartype.vt);
        $pe->addChild($parametername.pn);
    }
    ;
expropt returns [minicc::Expr *ep]
:    expr {$ep = $expr.e;}
    |   /* eps */ {$ep = NULL;}
    ;
expr returns [minicc::Expr *e]
:   INT
    {
        $e = minicc::ConstantLiteralExpr::fromString($INT.text);
    }
    |   '-' expr
    {
        minicc::UnaryExpr *ue = new minicc::UnaryExpr();
        ue->addChild($expr.e);
        ue->setOpcode(minicc::Expr::opcodeFromString("-"));
        $e = ue;
    }
    |   e1=expr op=('*'|'/') e2=expr
    {
        minicc::BinaryExpr *be = new minicc::BinaryExpr();
        be->addChild($e1.e);
        be->addChild($e2.e);
        be->setOpcode(minicc::Expr::opcodeFromString($op.text));
        $e = be;
    }
    |   e1=expr op=('+'|'-') e2=expr
    {
        minicc::BinaryExpr *be = new minicc::BinaryExpr();
        be->addChild($e1.e);
        be->addChild($e2.e);
        be->setOpcode(minicc::Expr::opcodeFromString($op.text));
        $e = be;
    }
    |   e1=expr op=('==' | '!=' | '<' | '<=' | '>' | '>=') e2=expr
    {
        minicc::BinaryExpr *be = new minicc::BinaryExpr();
        be->addChild($e1.e);
        be->addChild($e2.e);
        be->setOpcode(minicc::Expr::opcodeFromString($op.text));
        $e = be;
    }
    |   '!' expr
    {
        minicc::UnaryExpr *ue = new minicc::UnaryExpr();
        ue->addChild($expr.e);
        ue->setOpcode(minicc::Expr::opcodeFromString("!"));
        $e = ue;
    }
    |   e1=expr '&&' e2=expr
    {
        minicc::BinaryExpr *be = new minicc::BinaryExpr();
        be->addChild($e1.e);
        be->addChild($e2.e);
        be->setOpcode(minicc::Expr::opcodeFromString("&&"));
        $e = be;
    }
    |   e1=expr '||' e2=expr
    {
        minicc::BinaryExpr *be = new minicc::BinaryExpr();
        be->addChild($e1.e);
        be->addChild($e2.e);
        be->setOpcode(minicc::Expr::opcodeFromString("||"));
        $e = be;
    }
    |   var '=' expr
    {
        minicc::AssignmentExpr *ae = new minicc::AssignmentExpr();
        ae->addChild($var.vr);
        ae->addChild($expr.e);
        $e = ae;
    }
    |   'true' {$e = new minicc::BoolLiteralExpr(true);}
    |   'false' {$e = new minicc::BoolLiteralExpr(false);}
    |   '(' expr ')' {$e = $expr.e;}
    |   var 
    {
        $e = new minicc::VarExpr();
        $e->addChild($var.vr);
    }
    |   funcname '(' arguments ')'
    {
        $e = new minicc::CallExpr();
        $e->addChild($funcname.fn);
        for (std::vector<minicc::Expr *>::iterator i = $arguments.args.begin(); i != $arguments.args.end(); i++){
            $e->addChild(*i);
        }
    }
    |   parametername
    {
        $e = new minicc::VarExpr();
        minicc:VarReference *p = new minicc::VarReference();
        p->addChild($parametername.pn);
        $e->addChild(p);
    }
    ;
var returns [minicc::VarReference *vr]
:    varname
    {
        $vr = new minicc::VarReference();
        $vr->addChild($varname.vn);
    }
    |   varname '[' expr ']'
    {
        $vr = new minicc::VarReference();
        $vr->addChild($varname.vn);
        $vr->addChild($expr.e);
    }
    ;
arguments returns [std::vector<minicc::Expr *> args]
:   /* epsilon */ {std::vector<minicc::Expr *> args_vector;
        $args = args_vector;}
    |   argumentlist {$args = $argumentlist.al;}
    ;
argumentlist returns [std::vector<minicc::Expr *> al]
:   expr
    {
        std::vector<minicc::Expr *> al_vector;
        al_vector.push_back($expr.e);
        $al = al_vector;
    }
    |   a1=argumentlist ',' expr
    {
        $al = $a1.al;
        $al.push_back($expr.e);
    }
    ;
varname returns [minicc::Identifier *vn]
:   ID {$vn = new minicc::Identifier($ID.text);}
    ;
funcname returns [minicc::Identifier *fn]
:   ID {$fn = new minicc::Identifier($ID.text);}
    ;
parametername returns [minicc::Identifier *pn]
:   ID {$pn = new minicc::Identifier($ID.text);}
    ;

ID:     [a-zA-Z][a-zA-Z0-9_]* ;
INT:    [0] | ([1-9][0-9]*) ;
WS:     [ \t\r\n]+ -> skip;
COMMENT: '//' (~[\r\n])* -> skip;