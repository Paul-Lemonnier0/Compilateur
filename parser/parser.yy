%skeleton "lalr1.cc"
%require "3.0"

%defines
%define api.parser.class { Parser }
%define api.value.type variant
%define parse.assert

%locations

%code requires{
    #include "contexte.hh"
    #include "expressionBinaire.hh"
    #include "expressionUnaire.hh"
    #include "constante.hh"
    #include "variable.hh"
    #include "figure.hh"
    #include "noeud.hh"

    class Scanner;
    class Driver;
}

%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%code{
    #include <iostream>
    #include <string>
    #include <map>
    #include <memory>
    
    #include "scanner.hh"
    #include "driver.hh"

    #undef  yylex
    #define yylex scanner.yylex
}

%token                  NL
%token                  END
%token <int>            NUMBER
%token <float>          FLOAT
%token <bool>           BOOL

%token <std::string>    INT_TYPE
%token <std::string>    BOOL_TYPE
%token <std::string>    FLOAT_TYPE
%token <std::string>    VARIABLE
%token <std::string>    STRING

%token                  ATTRIBUT
%token                  INLINE_AFFECTATION
%token <std::string>    HEXA_VALUE

%token <std::string>    COULEUR
%token <std::string>    ROTATION
%token <std::string>    REMPLISSAGE
%token <std::string>    OPACITE
%token <std::string>    EPAISSEUR

%token                  SI
%token                  ALORS
%token                  SINON

%token                  REPETE
%token                  FOIS

%token                  EQUAL
%token                  NOTEQUAL
%token                  LESS
%token                  LESSEQUAL
%token                  GREATER
%token                  GREATEREQUAL

%token                  STRINGEQUAL
%token                  STRINGNOTEQUAL

%token                  TAILLE

%token                  RECTANGLE
%token                  CARRE
%token                  TRIANGLE
%token                  CERCLE

%token                  ELLIPSE
%token                  LIGNE
%token                  CHEMIN
%token                  TEXTE

%token                  STOP
%token                  SVG

%type <ExpressionPtr>   operation

%type <std::vector<Position>> vectPos
%type <std::map<std::string, std::string>> attributs
%type <std::map<std::string, std::string>> attributsInline
%type <std::map<std::string, std::string>> attributsCSS
%type <std::pair<std::string, std::string>> attributAffectation
%type <std::pair<std::string, std::string>> setAttribut

%type <std::string> pourcentage
%type <std::string> chaine


%type <IfNode *> if
%type <ConditionNode *> condition
%type <ConditionNode *> numberCondition
%type <CouleurConditionNode *> stringCondition

%type <operators> numberComparator
%type <string_operators> stringComparator

%type <CanevaNode *> declarationCanva
%type <DeclarationVariable *> declarationVariable
%type <FigureNode *> declarationFigure 

%type <AccesFigureNode *> accesFigure 
%type <ModificationNode *> modificationFigure

%type <AccesCouleurFigure *> accesCouleurFigure


%type <CarreNode *> carre
%type rectangle
%type triangle
%type cercle
%type ellipse
%type ligne
%type chemin
%type texte

%type <ArbreSyntaxique> programme
%type <ArbreSyntaxique> subProgramme
%type <std::vector<Noeud *>> instructions
%type <Noeud *> expression
%type <Noeud *> instruction

%left '-' '+'
%left '*' '/'
%precedence  NEG

%%

programme:

    subProgramme {
        driver.analyseCode($1);
    }

    | SVG {

        YYACCEPT;
    }


subProgramme:
    instruction NL subProgramme {
        $3.addNode($1);
        $$ = $3;
    }


    | 

    NL {

    }

instructions:
    instruction NL instructions {
        $3.push_back($1);
        $$ = $3;
    }


    | 

    {

    }

instruction:
    expression  {
        $$ = $1;
    }
    
attributsInline :
    attributAffectation {
        $$[$1.first] = $1.second;
    }

    |

    attributsInline '&' attributAffectation {
        $1[$3.first] = $3.second;
        $$ = $1;
    };


attributsCSS:
    attributAffectation {
        $$[$1.first] = $1.second;
    }

    |

    attributsCSS NL attributAffectation {
        $1[$3.first] = $3.second;
        $$ = $1;
    }
    
attributs:
    ';'{}

    |

    '{' NL attributsCSS NL '}' {
        $$ = $3;
    }

    |

    INLINE_AFFECTATION attributsInline ';' {
        $$ = $2;
    }
    

attributAffectation:
    COULEUR ':' HEXA_VALUE {
        $$ = std::make_pair($1, $3);
    }

    |

    ROTATION ':' operation {
        $$ = std::make_pair($1, std::to_string($3));
    }

    |

    OPACITE ':' pourcentage {
        $$ = std::make_pair($1, $3);
    }
    
    | 
    
    REMPLISSAGE ':'  HEXA_VALUE {
        $$ = std::make_pair($1, $3);
    }
    
    |
    
    EPAISSEUR ':' operation {
        $$ = std::make_pair($1, std::to_string($3));
    }



expression:
    declarationCanva { $$ = $1; } | 
    declarationFigure { $$ = $1; } | 
    accesFigure { $$ = $1; } | 
    modificationFigure { $$ = $1; } | 
    declarationVariable { $$ = $1; } | 
    if { $$ = $1; } 


declarationCanva:
    TAILLE NUMBER NUMBER {
        $$ = new CanevaNode($2, $3);
    }


declarationFigure:
    carre {
        $$ = $1;
    }

    
carre:
    CARRE operation operation operation attributs {
        CarreNode * carre = new CarreNode($2, $3, $4);
        carre->setAttributs($5);
        $$ = carre;
    } 

rectangle:
    RECTANGLE operation operation operation operation operation operation operation operation attributs {
    } 

triangle:

    TRIANGLE operation operation operation operation attributs {
    }

cercle:

    CERCLE operation operation operation attributs {
    }

ellipse:

    ELLIPSE operation operation operation operation attributs{
    }

ligne:

    LIGNE operation operation operation operation attributs{
    }

chemin:

    CHEMIN vectPos attributs{
    }

texte:

    TEXTE operation operation STRING STRING attributs{
    }

accesFigure:
    CARRE '[' NUMBER ']' {
        $$ = new AccesIndexNode(FigureTypes::carre, $3);
    }

    |

    VARIABLE {
        $$ = new AccesVariableNode($1);
    }


setAttribut:
    COULEUR '=' HEXA_VALUE {
        $$ = std::make_pair($1, $3);
    }

    |

    ROTATION '=' operation {
        $$ = std::make_pair($1, std::to_string($3));
    }

    |

    OPACITE '=' pourcentage {
        $$ = std::make_pair($1, $3);
    }
    
    | 
    
    REMPLISSAGE '='  HEXA_VALUE {
        $$ = std::make_pair($1, $3);
    }
    
    |
    
    EPAISSEUR '=' operation {
        $$ = std::make_pair($1, std::to_string($3));
    }


modificationFigure:
    accesFigure '.' setAttribut{
        $$ = new ModificationNode($1, $3.first, $3.second);
    }

/*
getStringAttribut:
    COULEUR { $$ = $1; } | REMPLISSAGE { $$ = $1; }
*/


declarationVariable:
    VARIABLE affectation declarationFigure {
        $$ = new DeclarationVariable($1, $3);
    }   

numberComparator:   
    EQUAL { $$ = operators::equal; } |
    NOTEQUAL { $$ = operators::not_equal; } |
    LESSEQUAL { $$ = operators::less_equal; } |
    GREATEREQUAL { $$ = operators::greater_equal; } |
    LESS { $$ = operators::less; } |
    GREATER { $$ = operators::greater; }

stringComparator:   
    STRINGEQUAL { $$ = string_operators::equal; } |
    STRINGNOTEQUAL { $$ = string_operators::not_equal; }


condition:
    stringCondition {
        $$ = $1;
    }

numberCondition:  
    operation numberComparator operation {
        $$ = new NumberConditionNode($1, $2, $3);
    }

pourcentage:
    operation '%'{
        $$ = std::to_string($1) + '%';
    }

chaine:
    HEXA_VALUE | STRING | pourcentage


accesCouleurFigure:
    accesFigure '.' COULEUR {
        $$ = new AccesCouleurFigure($1);
    }


stringCondition:  
    accesCouleurFigure stringComparator chaine {
        $$ = new CouleurConditionNode($1, $2, $3);
    }
    

if:
    SI '(' condition ')' ALORS '{' NL instructions '}' {
        $$ = new IfNode($8, $3);
    }


affectation:
    '=' { 
    }

operation:
    NUMBER {
        $$ = std::make_shared<Constante>($1);
    }

    | VARIABLE {
        $$ = std::make_shared<Variable>($1);
    }
    | '(' operation ')' {
        $$ = $2;
    }
    | operation '+' operation {
        $$ = std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::plus);
    }
    | operation '-' operation {
        $$ = std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::moins);
    }
    | operation '*' operation {
        $$ = std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::multiplie);
    }
    | operation '/' operation {
        $$ = std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::divise);
    }
    | '-' operation %prec NEG {
        $$ = std::make_shared<ExpressionUnaire>($2,OperateurUnaire::neg);
    }

vectPos:
    operation operation {
        $$.push_back(Position($1,$2));
    }
    | vectPos operation operation {
        $1.push_back(Position($2,$3));
        for(auto i : $1) {
            $$.push_back(i);
        }
    }

%%

void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}