%{

#include "scanner.hh"
#include <string>
#include <cstdlib>

#define YY_NO_UNISTD_H

using token = yy::Parser::token;

#undef  YY_DECL
#define YY_DECL int Scanner::yylex( yy::Parser::semantic_type * const lval, yy::Parser::location_type *loc )

/* update location on matching */
#define YY_USER_ACTION loc->step(); loc->columns(yyleng);

%}

%option c++
%option yyclass="Scanner"
%option noyywrap

%%
%{
    yylval = lval;
%}
fin return token::END;

"+" return '+';
"*" return '*';
"-" return '-';
"/" return '/';
"(" return '(';
")" return ')';
"=" return '=';
":" return ':';
"&" return '&';
";" return ';';
"{" return '{';
"}" return '}';
"[" return '[';
"]" return ']';
"." return '.';
"%" return '%';



"°" {
    return token::DEGRE;
}

"&&" {
    return token::AND;
}

"fonction" {
    return token::FUNCTION;
}

"si" {
    return token::SI;
}

"alors" {
    return token::ALORS;
}

"sinon" {
    return token::SINON;
}

"répète" {
    return token::REPETE;
}

"tant que" {
    return token::WHILE;
}

"fois" {
    return token::FOIS;
}

"==" {
    return token::EQUAL;
}

"!=" {
    return token::NOTEQUAL;
}

"<" {
    return token::LESS;
}

"<=" {
    return token::LESSEQUAL;
}

">" {
    return token::GREATER;
}

">=" {
    return token::GREATEREQUAL;
}

"est" {
    return token::STRINGEQUAL;
}

"n'est pas" {
    return token::STRINGNOTEQUAL;
}

"sinon" {
    return token::SINON;
}

"taille" {
    yylval->build<std::string>(YYText());
    return token::TAILLE;
}

"hauteur" {
    yylval->build<std::string>(YYText());
    return token::HAUTEUR;
}

"largeur" {
    yylval->build<std::string>(YYText());
    return token::LARGEUR;
}

"rectangle" {
    return token::RECTANGLE;
}

"carré" {
    return token::CARRE;
}

"triangle" {
    return token::TRIANGLE;
}

"cercle" {
    return token::CERCLE;
}

"ellipse" {
    return token::ELLIPSE;
}

"ligne" {
    return token::LIGNE;
}

"chemin" {
    return token::CHEMIN;
}

"texte" {
    return token::TEXTE;
}

"stop" {
    return token::STOP;
}

"couleur" {
    yylval->build<std::string>(YYText());
    return token::COULEUR;
}

"rotation" {
    yylval->build<std::string>(YYText());
    return token::ROTATION;
}

"remplissage" {
    yylval->build<std::string>(YYText());
    return token::REMPLISSAGE;
}

"opacité" {
    yylval->build<std::string>(YYText());
    return token::OPACITE;
}

"épaisseur" {
    yylval->build<std::string>(YYText());
    return token::EPAISSEUR;
}

"entier" {
    yylval->build<std::string>(YYText());
    return token::INT_TYPE;
}

"booléen" {
    yylval->build<std::string>(YYText());
    return token::BOOL_TYPE;
}

"réel" {
    yylval->build<std::string>(YYText());
    return token::FLOAT_TYPE;
}


"->" {
    return token::INLINE_AFFECTATION;
}

"#"([0-9]|[a-fA-F]){6} {
    yylval->build<std::string>(YYText());
    return token::HEXA_VALUE;
}

"true" {
    return token::TRUE;
}

"false" {
    return token::FALSE;
}

[0-9]+ {
    yylval->build<int>(std::atoi(YYText()));
    return token::NUMBER;
}

[0-9]+(\.[0-9]+)? {
    yylval->build<float>(std::atoi(YYText()));
    return token::FLOAT;
}

"\n" {
    loc->lines();
    return token::NL;
}

"rgb("(([0-9])|([1-9][0-9])|(1[0-9]{2})|(2[0-5]{2})),(([0-9])|([1-9][0-9])|(1[0-9]{2})|(2[0-5]{2})),(([0-9])|([1-9][0-9])|(1[0-9]{2})|(2[0-5]{2}))")" {
    yylval->build<std::string>(YYText());
    return token::HEXA_VALUE;
}

"rouge"|"vert"|"bleu"|"jaune"|"violet"|"magenta"|"cyan"|"noir"|"blanc" {
    yylval->build<std::string>(YYText());
    return token::HEXA_VALUE;
}

[a-zA-Z]([a-zA-Z]|[0-9]+)* {
    yylval->build<std::string>(YYText());
    return token::VARIABLE;
}


"\""(([a-zA-Z]|[0-9])+" ")*([a-zA-Z]|[0-9])*"\"" {
    yylval->build<std::string>(YYText());
    return token::STRING;
}


%%
