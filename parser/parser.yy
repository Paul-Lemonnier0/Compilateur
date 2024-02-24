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
    #include "boucles.hh"
    #include "condition.hh"
    #include "arbre.hh"
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
%token                  TRUE
%token                  FALSE

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

%token                  FUNCTION

%token                  REPETE
%token                  FOIS

%token                  WHILE

%token                  EQUAL
%token                  NOTEQUAL
%token                  LESS
%token                  LESSEQUAL
%token                  GREATER
%token                  GREATEREQUAL

%token                  STRINGEQUAL
%token                  STRINGNOTEQUAL

%token <std::string>    TAILLE
%token <std::string>    HAUTEUR
%token <std::string>    LARGEUR

%token                  RECTANGLE
%token                  CARRE
%token                  TRIANGLE
%token                  CERCLE

%token                  ELLIPSE
%token                  LIGNE
%token                  CHEMIN
%token                  TEXTE

%token                  STOP

%token                  DEGRE

%token                  AND

%type <ExpressionPtr>   operation
%type <CouleurPtr> couleurValue

%type <std::vector<Position>> vectPos
%type <std::vector<std::shared_ptr<AttributNode>>> attributs
%type <std::vector<std::shared_ptr<AttributNode>>> attributsInline
%type <std::vector<std::shared_ptr<AttributNode>>> attributsCSS


%type <std::shared_ptr<AttributNode>> attributAffectation

%type <std::shared_ptr<AttributNode>> setAttribut
%type <TailleType> setTaille

%type <std::shared_ptr<ForLoopNode>> boucleFor
%type <std::shared_ptr<WhileNode>> boucleWhile

%type <std::shared_ptr<FonctionNode>> fonction
%type <std::shared_ptr<AppelFonctionNode>> appelFonction

%type <std::vector<std::string>> arguments
%type <std::vector<ExpressionPtr>> argumentsValues

%type <bool> boolValue
%type <std::shared_ptr<IfNode>> if
%type <std::vector<std::shared_ptr<Noeud>>> else
%type <std::shared_ptr<ConditionNode>> condition
%type <std::vector<std::shared_ptr<ConditionNode>>> conditions

%type <operators> numberComparator
%type <string_operators> stringComparator

%type <std::shared_ptr<CanevaNode>> declarationCanva
%type <std::shared_ptr<DeclarationVariable>> declarationVariable
%type <std::shared_ptr<FigureNode>> declarationFigure 

%type <std::shared_ptr<AccesFigureNode>> accesFigure 
%type <std::shared_ptr<ModificationFigureNode>> modificationFigure

%type <std::shared_ptr<CarreNode>> carre
%type <std::shared_ptr<RectangleNode>> rectangle
%type <std::shared_ptr<TriangleNode>> triangle
%type <std::shared_ptr<CercleNode>> cercle
%type <std::shared_ptr<CheminNode>> chemin
%type <std::shared_ptr<LigneNode>> ligne
%type <std::shared_ptr<EllipseNode>> ellipse
%type <std::shared_ptr<TexteNode>> texte

%type <ArbreSyntaxique> programme
%type <ArbreSyntaxique> subProgramme
%type <std::vector<std::shared_ptr<Noeud>>> instructions
%type <std::shared_ptr<Noeud>> expression
%type <std::shared_ptr<Noeud>> instruction

%type <std::shared_ptr<DeclarationVariableSimple>> declarationVariableSimple

%type <std::shared_ptr<AffectationSimpleVariableNode>> affectation

%type <std::string> variable

%left '-' '+'
%left '*' '/'
%precedence  NEG

%%

programme:
    subProgramme {
        driver.analyseCode($1);
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
        $$.push_back($1);
    }

    |

    attributsInline '&' attributAffectation {
        $1.push_back($3);
        $$ = $1;
    };


attributsCSS:
    attributAffectation ';' {
        $$.push_back($1);
    }

    |

    attributsCSS ';' NL attributAffectation {
        $1.push_back($4);
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
    COULEUR ':' couleurValue {
        $$ = std::make_shared<ColorNode>($3);
    }

    |
        
    REMPLISSAGE ':'  couleurValue {
        $$ = std::make_shared<RemplissageNode>($3);
    }

    |

    ROTATION ':' operation DEGRE{
        $$ = std::make_shared<RotationNode>($3);
    }

    |

    OPACITE ':' operation {
        $$ = std::make_shared<OpaciteNode>($3);
    }
    
    | 
    
    EPAISSEUR ':' operation {
        $$ = std::make_shared<EpaisseurNode>($3);
    }

couleurValue:
    HEXA_VALUE {
        $$ = std::make_shared<CouleurConstante>($1);
    }

    |

    variable {
        $$ = std::make_shared<CouleurVariable>($1);
    }


expression:
    declarationCanva ';' { $$ = $1; } | 
    declarationFigure { $$ = $1; } | 
    modificationFigure { $$ = $1; } | 
    declarationVariableSimple { $$ = $1; } |
    declarationVariable { $$ = $1; } | 
    if { $$ = $1; } |
    accesFigure { $$ = $1; } | 
    boucleFor { $$ = $1; } |
    boucleWhile { $$ = $1; } |
    affectation { $$ = $1; } |
    fonction { $$ = $1; } |
    appelFonction ';' { $$ = $1; }

variable: 
    VARIABLE | TAILLE {
        $$ = $1;
    }

boolValue:
    TRUE {
        $$ = true;
    }

    |

    FALSE {
        $$ = false;
    }

declarationVariableSimple:
    INT_TYPE variable '=' operation {
        $$ = std::make_shared<DeclarationVariableInt>($2, $4);
    }

    |

    BOOL_TYPE variable '=' boolValue {
        $$ = std::make_shared<DeclarationVariableBool>($2, $4);
    }

    |

    COULEUR variable '=' HEXA_VALUE {
        $$ = std::make_shared<DeclarationVariableString>($2, $4);
    }

declarationCanva:
    TAILLE operation operation {
        $$ = std::make_shared<CanevaNode>($2, $3);
    }


declarationFigure:
 carre {
 $$ = $1;
 }
 | rectangle {
 $$ = $1;
 }
 | triangle {
 $$ = $1;
 }

 | cercle {
 $$ = $1;
 }

 | ellipse {
 $$ = $1;
 }

 | chemin {
 $$ = $1;
 }

 | ligne {
 $$ = $1;
 }

 | texte {
 $$ = $1;
 }



 
carre:
 CARRE operation operation operation attributs {
    std::shared_ptr<CarreNode> carre = std::make_shared<CarreNode>($2, $3, $4);
    carre->setAttributs($5);
    $$ = carre;
 } 

rectangle:
 RECTANGLE operation operation operation operation operation operation operation operation attributs {
    std::shared_ptr<RectangleNode> rectangle = std::make_shared<RectangleNode>($2, $3, $4,$5,$6,$7,$8,$9);
    rectangle->setAttributs($10);
    $$ = rectangle;
 } 

triangle:

 TRIANGLE operation operation operation operation attributs {
    std::shared_ptr<TriangleNode> triangle = std::make_shared<TriangleNode>($2, $3, $4,$5);
    triangle->setAttributs($6);
    $$ = triangle;
 }

cercle:

 CERCLE operation operation operation attributs {
    std::shared_ptr<CercleNode> cercle = std::make_shared<CercleNode>($2, $3, $4);
    cercle->setAttributs($5);
    $$ = cercle;
 }

ellipse:

 ELLIPSE operation operation operation operation attributs{
    std::shared_ptr<EllipseNode> ellipse = std::make_shared<EllipseNode>($2, $3, $4,$5);
    ellipse->setAttributs($6);
    $$ = ellipse;
 }

ligne:

 LIGNE operation operation operation operation attributs{
    std::shared_ptr<LigneNode> ligne = std::make_shared<LigneNode>($2, $3, $4,$5);
    ligne->setAttributs($6);
    $$ = ligne;
 }

chemin:

 CHEMIN vectPos attributs{
    std::shared_ptr<CheminNode> chemin = std::make_shared<CheminNode>($2);
    chemin->setAttributs($3);
    $$ = chemin;
 }

texte:

 TEXTE operation operation STRING STRING attributs{
    std::shared_ptr<TexteNode> texte = std::make_shared<TexteNode>($2, $3, $4,$5);
    texte->setAttributs($6);
    $$ = texte;
 }

accesFigure:
    CARRE '[' NUMBER ']' '.' {
        $$ = std::make_shared<AccesIndexNode>(FigureTypes::carre, $3);
    }

    |
    
    TRIANGLE '[' NUMBER ']' '.' {
        $$ = std::make_shared<AccesIndexNode>(FigureTypes::triangle, $3);
    }

    |

    variable '.' {
        $$ = std::make_shared<AccesVariableNode>($1);
    }

setAttribut:
    COULEUR '=' couleurValue {
        $$ = std::make_shared<ColorNode>($3);
    }

    |

    REMPLISSAGE '='  couleurValue {
        $$ = std::make_shared<RemplissageNode>($3);
    }

    |

    ROTATION '=' operation DEGRE{
        $$ = std::make_shared<RotationNode>($3);
    }

    |

    OPACITE '=' operation '%' {
        $$ = std::make_shared<OpaciteNode>($3);
    }
    
    | 
    
    EPAISSEUR '=' operation {
        $$ = std::make_shared<EpaisseurNode>($3);
    }


setTaille:
    TAILLE {
        $$ = TailleType::taille;
    } | 

    HAUTEUR {
        $$ = TailleType::hauteur;
    } | 
    
    LARGEUR {
        $$ = TailleType::largeur;
    }


modificationFigure:
    accesFigure setAttribut{
        $$ = std::make_shared<ModificationAttributsNode>($1, $2);
    }

    |

    accesFigure setTaille '=' operation {
        $$ = std::make_shared<ModificationTailleFigureNode>($1, $2, $4);
    }


declarationVariable:
    variable '=' declarationFigure {
        $$ = std::make_shared<DeclarationVariable>($1, $3);
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
    accesFigure setTaille numberComparator operation {
        $$ = std::make_shared<TailleConditionNode>($1, $3, $4, $2);
    }

    |

    variable {
        $$ = std::make_shared<BooleanVariableConditionNode>($1);
    }

    |

    accesFigure COULEUR stringComparator couleurValue {
        $$ = std::make_shared<CouleurConditionNode>($1, $3, $4);
    }


conditions: 
    condition {
        $$.push_back($1);
    }

    |

    '(' conditions ')' AND '(' condition ')' {
        $2.push_back($6);
        $$ = $2;
    }

if:
    SI '(' conditions ')' ALORS '{' NL instructions '}' NL else {
        $$ = std::make_shared<IfNode>($8, $11, $3);
    }

else:
    {   
    }

    |

    SINON '{' NL instructions '}' {
        $$ = $4;
    }


boucleFor:
    REPETE operation FOIS '{' NL instructions '}' {
        $$ = std::make_shared<ForLoopNode>($6, $2);
    }

boucleWhile:
    WHILE '(' conditions ')' '{' NL instructions '}' {
        $$ = std::make_shared<WhileNode>($7, $3);
    }


affectation:
    variable '=' operation { 
        $$ = std::make_shared<AffectationDoubleVariableNode>($1, $3);
    }

    |

    variable '=' boolValue {
        $$ = std::make_shared<AffectationBoolVariableNode>($1, $3);
    }

    |

    variable '=' HEXA_VALUE {
        $$ = std::make_shared<AffectationCouleurVariableNode>($1, $3);
    }

arguments:
    {
    }

    |

    variable arguments {
        $2.push_back($1);
        $$ = $2;
    }

argumentsValues:
    {
    }

    |

    operation argumentsValues {
        $2.push_back($1);
        $$ = $2;
    }


fonction:
    FUNCTION variable '(' arguments ')' '{' NL instructions '}' {
        $$ = std::make_shared<FonctionNode>($8, $2, $4);
    } 

appelFonction:
    variable argumentsValues {
        $$ = std::make_shared<AppelFonctionNode>($1, $2);
    }


operation:
    NUMBER {
        $$ = std::make_shared<Constante>($1);
    }

    | variable {
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