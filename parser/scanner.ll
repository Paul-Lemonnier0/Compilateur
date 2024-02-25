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
"," return ',';



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

("t"|"T")("a"|"A")("i"|"I")("l"|"L")("l"|"L")("e"|"E") {
    yylval->build<std::string>(YYText());
    return token::TAILLE;
}

("r"|"R")("e"|"E")("c"|"C")("t"|"T")("a"|"A")("n"|"N")("g"|"G")("l"|"L")("e"|"E") {
    return token::RECTANGLE;
}

("c"|"C")("a"|"A")("r"|"R"){2}("é"|"É") {
    return token::CARRE;
}

("t"|"T")("r"|"R")("i"|"I")("a"|"A")("n"|"N")("g"|"G")("l"|"L")("e"|"E") {
    return token::TRIANGLE;
}

("c"|"C")("e"|"E")("r"|"R")("c"|"C")("l"|"L")("e"|"E") {
    return token::CERCLE;
}

("e"|"E")("l"|"L"){2}("i"|"I")("p"|"P")("s"|"S")("e"|"E") {
    return token::ELLIPSE;
}

("l"|"L")("i"|"I")("g"|"G")("n"|"N")("e"|"E") {
    return token::LIGNE;
}

("c"|"C")("h"|"H")("e"|"E")("m"|"M")("i"|"I")("n"|"N") {
    return token::CHEMIN;
}

("t"|"T")("e"|"E")("x"|"X")("t"|"T")("e"|"E") {
    return token::TEXTE;
}

("l"|"L")("a"|"A")("r"|"R")("g"|"G")("e"|"E")("u"|"U")("r"|"R") {
    return token::LARGEUR;
}

("h"|"H")("a"|"A")("u"|"U")("t"|"T")("e"|"E")("u"|"U")("r"|"R") {
    return token::HAUTEUR;
}

("s"|"S")("t"|"T")("o"|"O")("p"|"P") {
    return token::STOP;
}

("c"|"C")("o"|"O")("u"|"U")("l"|"L")("e"|"E")("u"|"U")("r"|"R") {
    yylval->build<std::string>(YYText());
    return token::COULEUR;
}

("r"|"R")("o"|"O")("t"|"T")("a"|"A")("t"|"T")("i"|"I")("o"|"O")("n"|"N") {
    yylval->build<std::string>(YYText());
    return token::ROTATION;
}

("r"|"R")("e"|"E")("m"|"M")("p"|"P")("l"|"L")("i"|"I")("s"|"S")("s"|"S")("a"|"A")("g"|"G")("e"|"E") {
    yylval->build<std::string>(YYText());
    return token::REMPLISSAGE;
}

("o"|"O")("p"|"P")("a"|"A")("c"|"C")("i"|"I")("t"|"T")("é"|"É") {
    yylval->build<std::string>(YYText());
    return token::OPACITE;
}

("é"|"É")("p"|"P")("a"|"A")("i"|"I")("s"|"S")("s"|"S")("e"|"E")("u"|"U")("r"|"R") {
    yylval->build<std::string>(YYText());
    return token::EPAISSEUR;
}

("e"|"E")("n"|"N")("t"|"T")("i"|"I")("e"|"E")("r"|"R") {
    yylval->build<std::string>(YYText());
    return token::INT_TYPE;
}

("b"|"B")("o"|"O")("o"|"O")("l"|"L")("é"|"É")("e"|"E")("n"|"N") {
    yylval->build<std::string>(YYText());
    return token::BOOL_TYPE;
}

("r"|"R")("é"|"É")("e"|"E")("l"|"L") {
    yylval->build<std::string>(YYText());
    return token::FLOAT_TYPE;
}

"positionX"([1-9]|"") {
    yylval->build<std::string>(YYText());
    return token::POSITIONX;
}
"positionY"([1-9]|"") {
    yylval->build<std::string>(YYText());
    return token::POSITIONY;
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

("r"|"R")("o"|"O")("u"|"U")("g"|"G")("e"|"E") |
("v"|"V")("e"|"E")("r"|"R")("t"|"T") |
("b"|"B")("l"|"L")("e"|"E")("u"|"U") |
("j"|"J")("a"|"A")("u"|"U")("n"|"N")("e"|"E") |
("v"|"V")("i"|"I")("o"|"O")("l"|"L")("e"|"E")("t"|"T") |
("m"|"M")("a"|"A")("g"|"G")("e"|"E")("n"|"N")("t"|"T")("a"|"A") |
("c"|"C")("y"|"Y")("a"|"A")("n"|"N") |
("n"|"N")("o"|"O")("i"|"I")("r"|"R") |
("b"|"B")("l"|"L")("a"|"A")("n"|"N")("c"|"C") {
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
