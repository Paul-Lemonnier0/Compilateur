// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "parser.hpp"


// Unqualified %code blocks.
#line 30 "parser/parser.yy"

    #include <iostream>
    #include <string>
    #include <map>
    #include <memory>
    
    #include "scanner.hh"
    #include "driver.hh"

    #undef  yylex
    #define yylex scanner.yylex

#line 58 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 149 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"


  /// Build a parser object.
   Parser :: Parser  (Scanner &scanner_yyarg, Driver &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

   Parser ::~ Parser  ()
  {}

   Parser ::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
    , location (std::move (that.location))
  {
    switch (this->type_get ())
    {
      case 69: // programme
      case 70: // subProgramme
        value.move< ArbreSyntaxique > (std::move (that.value));
        break;

      case 77: // couleurValue
        value.move< CouleurPtr > (std::move (that.value));
        break;

      case 110: // operation
        value.move< ExpressionPtr > (std::move (that.value));
        break;

      case 94: // setTaille
        value.move< TailleType > (std::move (that.value));
        break;

      case 80: // boolValue
        value.move< bool > (std::move (that.value));
        break;

      case 6: // FLOAT
        value.move< float > (std::move (that.value));
        break;

      case 5: // NUMBER
        value.move< int > (std::move (that.value));
        break;

      case 97: // numberComparator
        value.move< operators > (std::move (that.value));
        break;

      case 92: // accesFigure
        value.move< std::shared_ptr<AccesFigureNode> > (std::move (that.value));
        break;

      case 105: // affectation
        value.move< std::shared_ptr<AffectationSimpleVariableNode> > (std::move (that.value));
        break;

      case 109: // appelFonction
        value.move< std::shared_ptr<AppelFonctionNode> > (std::move (that.value));
        break;

      case 76: // attributAffectation
      case 93: // setAttribut
        value.move< std::shared_ptr<AttributNode> > (std::move (that.value));
        break;

      case 82: // declarationCanva
        value.move< std::shared_ptr<CanevaNode> > (std::move (that.value));
        break;

      case 84: // carre
        value.move< std::shared_ptr<CarreNode> > (std::move (that.value));
        break;

      case 87: // cercle
        value.move< std::shared_ptr<CercleNode> > (std::move (that.value));
        break;

      case 90: // chemin
        value.move< std::shared_ptr<CheminNode> > (std::move (that.value));
        break;

      case 99: // condition
        value.move< std::shared_ptr<ConditionNode> > (std::move (that.value));
        break;

      case 96: // declarationVariable
        value.move< std::shared_ptr<DeclarationVariable> > (std::move (that.value));
        break;

      case 81: // declarationVariableSimple
        value.move< std::shared_ptr<DeclarationVariableSimple> > (std::move (that.value));
        break;

      case 88: // ellipse
        value.move< std::shared_ptr<EllipseNode> > (std::move (that.value));
        break;

      case 83: // declarationFigure
        value.move< std::shared_ptr<FigureNode> > (std::move (that.value));
        break;

      case 108: // fonction
        value.move< std::shared_ptr<FonctionNode> > (std::move (that.value));
        break;

      case 103: // boucleFor
        value.move< std::shared_ptr<ForLoopNode> > (std::move (that.value));
        break;

      case 101: // if
        value.move< std::shared_ptr<IfNode> > (std::move (that.value));
        break;

      case 89: // ligne
        value.move< std::shared_ptr<LigneNode> > (std::move (that.value));
        break;

      case 95: // modificationFigure
        value.move< std::shared_ptr<ModificationFigureNode> > (std::move (that.value));
        break;

      case 72: // instruction
      case 78: // expression
        value.move< std::shared_ptr<Noeud> > (std::move (that.value));
        break;

      case 85: // rectangle
        value.move< std::shared_ptr<RectangleNode> > (std::move (that.value));
        break;

      case 91: // texte
        value.move< std::shared_ptr<TexteNode> > (std::move (that.value));
        break;

      case 86: // triangle
        value.move< std::shared_ptr<TriangleNode> > (std::move (that.value));
        break;

      case 104: // boucleWhile
        value.move< std::shared_ptr<WhileNode> > (std::move (that.value));
        break;

      case 9: // INT_TYPE
      case 10: // BOOL_TYPE
      case 11: // FLOAT_TYPE
      case 12: // VARIABLE
      case 13: // STRING
      case 16: // HEXA_VALUE
      case 17: // COULEUR
      case 18: // ROTATION
      case 19: // REMPLISSAGE
      case 20: // OPACITE
      case 21: // EPAISSEUR
      case 37: // TAILLE
      case 38: // HAUTEUR
      case 39: // LARGEUR
      case 79: // variable
        value.move< std::string > (std::move (that.value));
        break;

      case 107: // argumentsValues
        value.move< std::vector<ExpressionPtr> > (std::move (that.value));
        break;

      case 111: // vectPos
        value.move< std::vector<Position> > (std::move (that.value));
        break;

      case 73: // attributsInline
      case 74: // attributsCSS
      case 75: // attributs
        value.move< std::vector<std::shared_ptr<AttributNode>> > (std::move (that.value));
        break;

      case 100: // conditions
        value.move< std::vector<std::shared_ptr<ConditionNode>> > (std::move (that.value));
        break;

      case 71: // instructions
      case 102: // else
        value.move< std::vector<std::shared_ptr<Noeud>> > (std::move (that.value));
        break;

      case 106: // arguments
        value.move< std::vector<std::string> > (std::move (that.value));
        break;

      case 98: // stringComparator
        value.move< string_operators > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->type_get ())
    {
      case 69: // programme
      case 70: // subProgramme
        value.copy< ArbreSyntaxique > (YY_MOVE (that.value));
        break;

      case 77: // couleurValue
        value.copy< CouleurPtr > (YY_MOVE (that.value));
        break;

      case 110: // operation
        value.copy< ExpressionPtr > (YY_MOVE (that.value));
        break;

      case 94: // setTaille
        value.copy< TailleType > (YY_MOVE (that.value));
        break;

      case 80: // boolValue
        value.copy< bool > (YY_MOVE (that.value));
        break;

      case 6: // FLOAT
        value.copy< float > (YY_MOVE (that.value));
        break;

      case 5: // NUMBER
        value.copy< int > (YY_MOVE (that.value));
        break;

      case 97: // numberComparator
        value.copy< operators > (YY_MOVE (that.value));
        break;

      case 92: // accesFigure
        value.copy< std::shared_ptr<AccesFigureNode> > (YY_MOVE (that.value));
        break;

      case 105: // affectation
        value.copy< std::shared_ptr<AffectationSimpleVariableNode> > (YY_MOVE (that.value));
        break;

      case 109: // appelFonction
        value.copy< std::shared_ptr<AppelFonctionNode> > (YY_MOVE (that.value));
        break;

      case 76: // attributAffectation
      case 93: // setAttribut
        value.copy< std::shared_ptr<AttributNode> > (YY_MOVE (that.value));
        break;

      case 82: // declarationCanva
        value.copy< std::shared_ptr<CanevaNode> > (YY_MOVE (that.value));
        break;

      case 84: // carre
        value.copy< std::shared_ptr<CarreNode> > (YY_MOVE (that.value));
        break;

      case 87: // cercle
        value.copy< std::shared_ptr<CercleNode> > (YY_MOVE (that.value));
        break;

      case 90: // chemin
        value.copy< std::shared_ptr<CheminNode> > (YY_MOVE (that.value));
        break;

      case 99: // condition
        value.copy< std::shared_ptr<ConditionNode> > (YY_MOVE (that.value));
        break;

      case 96: // declarationVariable
        value.copy< std::shared_ptr<DeclarationVariable> > (YY_MOVE (that.value));
        break;

      case 81: // declarationVariableSimple
        value.copy< std::shared_ptr<DeclarationVariableSimple> > (YY_MOVE (that.value));
        break;

      case 88: // ellipse
        value.copy< std::shared_ptr<EllipseNode> > (YY_MOVE (that.value));
        break;

      case 83: // declarationFigure
        value.copy< std::shared_ptr<FigureNode> > (YY_MOVE (that.value));
        break;

      case 108: // fonction
        value.copy< std::shared_ptr<FonctionNode> > (YY_MOVE (that.value));
        break;

      case 103: // boucleFor
        value.copy< std::shared_ptr<ForLoopNode> > (YY_MOVE (that.value));
        break;

      case 101: // if
        value.copy< std::shared_ptr<IfNode> > (YY_MOVE (that.value));
        break;

      case 89: // ligne
        value.copy< std::shared_ptr<LigneNode> > (YY_MOVE (that.value));
        break;

      case 95: // modificationFigure
        value.copy< std::shared_ptr<ModificationFigureNode> > (YY_MOVE (that.value));
        break;

      case 72: // instruction
      case 78: // expression
        value.copy< std::shared_ptr<Noeud> > (YY_MOVE (that.value));
        break;

      case 85: // rectangle
        value.copy< std::shared_ptr<RectangleNode> > (YY_MOVE (that.value));
        break;

      case 91: // texte
        value.copy< std::shared_ptr<TexteNode> > (YY_MOVE (that.value));
        break;

      case 86: // triangle
        value.copy< std::shared_ptr<TriangleNode> > (YY_MOVE (that.value));
        break;

      case 104: // boucleWhile
        value.copy< std::shared_ptr<WhileNode> > (YY_MOVE (that.value));
        break;

      case 9: // INT_TYPE
      case 10: // BOOL_TYPE
      case 11: // FLOAT_TYPE
      case 12: // VARIABLE
      case 13: // STRING
      case 16: // HEXA_VALUE
      case 17: // COULEUR
      case 18: // ROTATION
      case 19: // REMPLISSAGE
      case 20: // OPACITE
      case 21: // EPAISSEUR
      case 37: // TAILLE
      case 38: // HAUTEUR
      case 39: // LARGEUR
      case 79: // variable
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case 107: // argumentsValues
        value.copy< std::vector<ExpressionPtr> > (YY_MOVE (that.value));
        break;

      case 111: // vectPos
        value.copy< std::vector<Position> > (YY_MOVE (that.value));
        break;

      case 73: // attributsInline
      case 74: // attributsCSS
      case 75: // attributs
        value.copy< std::vector<std::shared_ptr<AttributNode>> > (YY_MOVE (that.value));
        break;

      case 100: // conditions
        value.copy< std::vector<std::shared_ptr<ConditionNode>> > (YY_MOVE (that.value));
        break;

      case 71: // instructions
      case 102: // else
        value.copy< std::vector<std::shared_ptr<Noeud>> > (YY_MOVE (that.value));
        break;

      case 106: // arguments
        value.copy< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      case 98: // stringComparator
        value.copy< string_operators > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
   Parser ::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
   Parser ::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 69: // programme
      case 70: // subProgramme
        value.move< ArbreSyntaxique > (YY_MOVE (s.value));
        break;

      case 77: // couleurValue
        value.move< CouleurPtr > (YY_MOVE (s.value));
        break;

      case 110: // operation
        value.move< ExpressionPtr > (YY_MOVE (s.value));
        break;

      case 94: // setTaille
        value.move< TailleType > (YY_MOVE (s.value));
        break;

      case 80: // boolValue
        value.move< bool > (YY_MOVE (s.value));
        break;

      case 6: // FLOAT
        value.move< float > (YY_MOVE (s.value));
        break;

      case 5: // NUMBER
        value.move< int > (YY_MOVE (s.value));
        break;

      case 97: // numberComparator
        value.move< operators > (YY_MOVE (s.value));
        break;

      case 92: // accesFigure
        value.move< std::shared_ptr<AccesFigureNode> > (YY_MOVE (s.value));
        break;

      case 105: // affectation
        value.move< std::shared_ptr<AffectationSimpleVariableNode> > (YY_MOVE (s.value));
        break;

      case 109: // appelFonction
        value.move< std::shared_ptr<AppelFonctionNode> > (YY_MOVE (s.value));
        break;

      case 76: // attributAffectation
      case 93: // setAttribut
        value.move< std::shared_ptr<AttributNode> > (YY_MOVE (s.value));
        break;

      case 82: // declarationCanva
        value.move< std::shared_ptr<CanevaNode> > (YY_MOVE (s.value));
        break;

      case 84: // carre
        value.move< std::shared_ptr<CarreNode> > (YY_MOVE (s.value));
        break;

      case 87: // cercle
        value.move< std::shared_ptr<CercleNode> > (YY_MOVE (s.value));
        break;

      case 90: // chemin
        value.move< std::shared_ptr<CheminNode> > (YY_MOVE (s.value));
        break;

      case 99: // condition
        value.move< std::shared_ptr<ConditionNode> > (YY_MOVE (s.value));
        break;

      case 96: // declarationVariable
        value.move< std::shared_ptr<DeclarationVariable> > (YY_MOVE (s.value));
        break;

      case 81: // declarationVariableSimple
        value.move< std::shared_ptr<DeclarationVariableSimple> > (YY_MOVE (s.value));
        break;

      case 88: // ellipse
        value.move< std::shared_ptr<EllipseNode> > (YY_MOVE (s.value));
        break;

      case 83: // declarationFigure
        value.move< std::shared_ptr<FigureNode> > (YY_MOVE (s.value));
        break;

      case 108: // fonction
        value.move< std::shared_ptr<FonctionNode> > (YY_MOVE (s.value));
        break;

      case 103: // boucleFor
        value.move< std::shared_ptr<ForLoopNode> > (YY_MOVE (s.value));
        break;

      case 101: // if
        value.move< std::shared_ptr<IfNode> > (YY_MOVE (s.value));
        break;

      case 89: // ligne
        value.move< std::shared_ptr<LigneNode> > (YY_MOVE (s.value));
        break;

      case 95: // modificationFigure
        value.move< std::shared_ptr<ModificationFigureNode> > (YY_MOVE (s.value));
        break;

      case 72: // instruction
      case 78: // expression
        value.move< std::shared_ptr<Noeud> > (YY_MOVE (s.value));
        break;

      case 85: // rectangle
        value.move< std::shared_ptr<RectangleNode> > (YY_MOVE (s.value));
        break;

      case 91: // texte
        value.move< std::shared_ptr<TexteNode> > (YY_MOVE (s.value));
        break;

      case 86: // triangle
        value.move< std::shared_ptr<TriangleNode> > (YY_MOVE (s.value));
        break;

      case 104: // boucleWhile
        value.move< std::shared_ptr<WhileNode> > (YY_MOVE (s.value));
        break;

      case 9: // INT_TYPE
      case 10: // BOOL_TYPE
      case 11: // FLOAT_TYPE
      case 12: // VARIABLE
      case 13: // STRING
      case 16: // HEXA_VALUE
      case 17: // COULEUR
      case 18: // ROTATION
      case 19: // REMPLISSAGE
      case 20: // OPACITE
      case 21: // EPAISSEUR
      case 37: // TAILLE
      case 38: // HAUTEUR
      case 39: // LARGEUR
      case 79: // variable
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case 107: // argumentsValues
        value.move< std::vector<ExpressionPtr> > (YY_MOVE (s.value));
        break;

      case 111: // vectPos
        value.move< std::vector<Position> > (YY_MOVE (s.value));
        break;

      case 73: // attributsInline
      case 74: // attributsCSS
      case 75: // attributs
        value.move< std::vector<std::shared_ptr<AttributNode>> > (YY_MOVE (s.value));
        break;

      case 100: // conditions
        value.move< std::vector<std::shared_ptr<ConditionNode>> > (YY_MOVE (s.value));
        break;

      case 71: // instructions
      case 102: // else
        value.move< std::vector<std::shared_ptr<Noeud>> > (YY_MOVE (s.value));
        break;

      case 106: // arguments
        value.move< std::vector<std::string> > (YY_MOVE (s.value));
        break;

      case 98: // stringComparator
        value.move< string_operators > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_type.
   Parser ::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
   Parser ::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

   Parser ::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

   Parser ::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
   Parser ::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
   Parser ::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
   Parser ::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
   Parser ::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

   Parser ::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
   Parser ::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
   Parser ::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

   Parser ::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

   Parser ::symbol_number_type
   Parser ::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

   Parser ::stack_symbol_type::stack_symbol_type ()
  {}

   Parser ::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 69: // programme
      case 70: // subProgramme
        value.YY_MOVE_OR_COPY< ArbreSyntaxique > (YY_MOVE (that.value));
        break;

      case 77: // couleurValue
        value.YY_MOVE_OR_COPY< CouleurPtr > (YY_MOVE (that.value));
        break;

      case 110: // operation
        value.YY_MOVE_OR_COPY< ExpressionPtr > (YY_MOVE (that.value));
        break;

      case 94: // setTaille
        value.YY_MOVE_OR_COPY< TailleType > (YY_MOVE (that.value));
        break;

      case 80: // boolValue
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case 6: // FLOAT
        value.YY_MOVE_OR_COPY< float > (YY_MOVE (that.value));
        break;

      case 5: // NUMBER
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 97: // numberComparator
        value.YY_MOVE_OR_COPY< operators > (YY_MOVE (that.value));
        break;

      case 92: // accesFigure
        value.YY_MOVE_OR_COPY< std::shared_ptr<AccesFigureNode> > (YY_MOVE (that.value));
        break;

      case 105: // affectation
        value.YY_MOVE_OR_COPY< std::shared_ptr<AffectationSimpleVariableNode> > (YY_MOVE (that.value));
        break;

      case 109: // appelFonction
        value.YY_MOVE_OR_COPY< std::shared_ptr<AppelFonctionNode> > (YY_MOVE (that.value));
        break;

      case 76: // attributAffectation
      case 93: // setAttribut
        value.YY_MOVE_OR_COPY< std::shared_ptr<AttributNode> > (YY_MOVE (that.value));
        break;

      case 82: // declarationCanva
        value.YY_MOVE_OR_COPY< std::shared_ptr<CanevaNode> > (YY_MOVE (that.value));
        break;

      case 84: // carre
        value.YY_MOVE_OR_COPY< std::shared_ptr<CarreNode> > (YY_MOVE (that.value));
        break;

      case 87: // cercle
        value.YY_MOVE_OR_COPY< std::shared_ptr<CercleNode> > (YY_MOVE (that.value));
        break;

      case 90: // chemin
        value.YY_MOVE_OR_COPY< std::shared_ptr<CheminNode> > (YY_MOVE (that.value));
        break;

      case 99: // condition
        value.YY_MOVE_OR_COPY< std::shared_ptr<ConditionNode> > (YY_MOVE (that.value));
        break;

      case 96: // declarationVariable
        value.YY_MOVE_OR_COPY< std::shared_ptr<DeclarationVariable> > (YY_MOVE (that.value));
        break;

      case 81: // declarationVariableSimple
        value.YY_MOVE_OR_COPY< std::shared_ptr<DeclarationVariableSimple> > (YY_MOVE (that.value));
        break;

      case 88: // ellipse
        value.YY_MOVE_OR_COPY< std::shared_ptr<EllipseNode> > (YY_MOVE (that.value));
        break;

      case 83: // declarationFigure
        value.YY_MOVE_OR_COPY< std::shared_ptr<FigureNode> > (YY_MOVE (that.value));
        break;

      case 108: // fonction
        value.YY_MOVE_OR_COPY< std::shared_ptr<FonctionNode> > (YY_MOVE (that.value));
        break;

      case 103: // boucleFor
        value.YY_MOVE_OR_COPY< std::shared_ptr<ForLoopNode> > (YY_MOVE (that.value));
        break;

      case 101: // if
        value.YY_MOVE_OR_COPY< std::shared_ptr<IfNode> > (YY_MOVE (that.value));
        break;

      case 89: // ligne
        value.YY_MOVE_OR_COPY< std::shared_ptr<LigneNode> > (YY_MOVE (that.value));
        break;

      case 95: // modificationFigure
        value.YY_MOVE_OR_COPY< std::shared_ptr<ModificationFigureNode> > (YY_MOVE (that.value));
        break;

      case 72: // instruction
      case 78: // expression
        value.YY_MOVE_OR_COPY< std::shared_ptr<Noeud> > (YY_MOVE (that.value));
        break;

      case 85: // rectangle
        value.YY_MOVE_OR_COPY< std::shared_ptr<RectangleNode> > (YY_MOVE (that.value));
        break;

      case 91: // texte
        value.YY_MOVE_OR_COPY< std::shared_ptr<TexteNode> > (YY_MOVE (that.value));
        break;

      case 86: // triangle
        value.YY_MOVE_OR_COPY< std::shared_ptr<TriangleNode> > (YY_MOVE (that.value));
        break;

      case 104: // boucleWhile
        value.YY_MOVE_OR_COPY< std::shared_ptr<WhileNode> > (YY_MOVE (that.value));
        break;

      case 9: // INT_TYPE
      case 10: // BOOL_TYPE
      case 11: // FLOAT_TYPE
      case 12: // VARIABLE
      case 13: // STRING
      case 16: // HEXA_VALUE
      case 17: // COULEUR
      case 18: // ROTATION
      case 19: // REMPLISSAGE
      case 20: // OPACITE
      case 21: // EPAISSEUR
      case 37: // TAILLE
      case 38: // HAUTEUR
      case 39: // LARGEUR
      case 79: // variable
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case 107: // argumentsValues
        value.YY_MOVE_OR_COPY< std::vector<ExpressionPtr> > (YY_MOVE (that.value));
        break;

      case 111: // vectPos
        value.YY_MOVE_OR_COPY< std::vector<Position> > (YY_MOVE (that.value));
        break;

      case 73: // attributsInline
      case 74: // attributsCSS
      case 75: // attributs
        value.YY_MOVE_OR_COPY< std::vector<std::shared_ptr<AttributNode>> > (YY_MOVE (that.value));
        break;

      case 100: // conditions
        value.YY_MOVE_OR_COPY< std::vector<std::shared_ptr<ConditionNode>> > (YY_MOVE (that.value));
        break;

      case 71: // instructions
      case 102: // else
        value.YY_MOVE_OR_COPY< std::vector<std::shared_ptr<Noeud>> > (YY_MOVE (that.value));
        break;

      case 106: // arguments
        value.YY_MOVE_OR_COPY< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      case 98: // stringComparator
        value.YY_MOVE_OR_COPY< string_operators > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

   Parser ::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 69: // programme
      case 70: // subProgramme
        value.move< ArbreSyntaxique > (YY_MOVE (that.value));
        break;

      case 77: // couleurValue
        value.move< CouleurPtr > (YY_MOVE (that.value));
        break;

      case 110: // operation
        value.move< ExpressionPtr > (YY_MOVE (that.value));
        break;

      case 94: // setTaille
        value.move< TailleType > (YY_MOVE (that.value));
        break;

      case 80: // boolValue
        value.move< bool > (YY_MOVE (that.value));
        break;

      case 6: // FLOAT
        value.move< float > (YY_MOVE (that.value));
        break;

      case 5: // NUMBER
        value.move< int > (YY_MOVE (that.value));
        break;

      case 97: // numberComparator
        value.move< operators > (YY_MOVE (that.value));
        break;

      case 92: // accesFigure
        value.move< std::shared_ptr<AccesFigureNode> > (YY_MOVE (that.value));
        break;

      case 105: // affectation
        value.move< std::shared_ptr<AffectationSimpleVariableNode> > (YY_MOVE (that.value));
        break;

      case 109: // appelFonction
        value.move< std::shared_ptr<AppelFonctionNode> > (YY_MOVE (that.value));
        break;

      case 76: // attributAffectation
      case 93: // setAttribut
        value.move< std::shared_ptr<AttributNode> > (YY_MOVE (that.value));
        break;

      case 82: // declarationCanva
        value.move< std::shared_ptr<CanevaNode> > (YY_MOVE (that.value));
        break;

      case 84: // carre
        value.move< std::shared_ptr<CarreNode> > (YY_MOVE (that.value));
        break;

      case 87: // cercle
        value.move< std::shared_ptr<CercleNode> > (YY_MOVE (that.value));
        break;

      case 90: // chemin
        value.move< std::shared_ptr<CheminNode> > (YY_MOVE (that.value));
        break;

      case 99: // condition
        value.move< std::shared_ptr<ConditionNode> > (YY_MOVE (that.value));
        break;

      case 96: // declarationVariable
        value.move< std::shared_ptr<DeclarationVariable> > (YY_MOVE (that.value));
        break;

      case 81: // declarationVariableSimple
        value.move< std::shared_ptr<DeclarationVariableSimple> > (YY_MOVE (that.value));
        break;

      case 88: // ellipse
        value.move< std::shared_ptr<EllipseNode> > (YY_MOVE (that.value));
        break;

      case 83: // declarationFigure
        value.move< std::shared_ptr<FigureNode> > (YY_MOVE (that.value));
        break;

      case 108: // fonction
        value.move< std::shared_ptr<FonctionNode> > (YY_MOVE (that.value));
        break;

      case 103: // boucleFor
        value.move< std::shared_ptr<ForLoopNode> > (YY_MOVE (that.value));
        break;

      case 101: // if
        value.move< std::shared_ptr<IfNode> > (YY_MOVE (that.value));
        break;

      case 89: // ligne
        value.move< std::shared_ptr<LigneNode> > (YY_MOVE (that.value));
        break;

      case 95: // modificationFigure
        value.move< std::shared_ptr<ModificationFigureNode> > (YY_MOVE (that.value));
        break;

      case 72: // instruction
      case 78: // expression
        value.move< std::shared_ptr<Noeud> > (YY_MOVE (that.value));
        break;

      case 85: // rectangle
        value.move< std::shared_ptr<RectangleNode> > (YY_MOVE (that.value));
        break;

      case 91: // texte
        value.move< std::shared_ptr<TexteNode> > (YY_MOVE (that.value));
        break;

      case 86: // triangle
        value.move< std::shared_ptr<TriangleNode> > (YY_MOVE (that.value));
        break;

      case 104: // boucleWhile
        value.move< std::shared_ptr<WhileNode> > (YY_MOVE (that.value));
        break;

      case 9: // INT_TYPE
      case 10: // BOOL_TYPE
      case 11: // FLOAT_TYPE
      case 12: // VARIABLE
      case 13: // STRING
      case 16: // HEXA_VALUE
      case 17: // COULEUR
      case 18: // ROTATION
      case 19: // REMPLISSAGE
      case 20: // OPACITE
      case 21: // EPAISSEUR
      case 37: // TAILLE
      case 38: // HAUTEUR
      case 39: // LARGEUR
      case 79: // variable
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case 107: // argumentsValues
        value.move< std::vector<ExpressionPtr> > (YY_MOVE (that.value));
        break;

      case 111: // vectPos
        value.move< std::vector<Position> > (YY_MOVE (that.value));
        break;

      case 73: // attributsInline
      case 74: // attributsCSS
      case 75: // attributs
        value.move< std::vector<std::shared_ptr<AttributNode>> > (YY_MOVE (that.value));
        break;

      case 100: // conditions
        value.move< std::vector<std::shared_ptr<ConditionNode>> > (YY_MOVE (that.value));
        break;

      case 71: // instructions
      case 102: // else
        value.move< std::vector<std::shared_ptr<Noeud>> > (YY_MOVE (that.value));
        break;

      case 106: // arguments
        value.move< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      case 98: // stringComparator
        value.move< string_operators > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 69: // programme
      case 70: // subProgramme
        value.copy< ArbreSyntaxique > (that.value);
        break;

      case 77: // couleurValue
        value.copy< CouleurPtr > (that.value);
        break;

      case 110: // operation
        value.copy< ExpressionPtr > (that.value);
        break;

      case 94: // setTaille
        value.copy< TailleType > (that.value);
        break;

      case 80: // boolValue
        value.copy< bool > (that.value);
        break;

      case 6: // FLOAT
        value.copy< float > (that.value);
        break;

      case 5: // NUMBER
        value.copy< int > (that.value);
        break;

      case 97: // numberComparator
        value.copy< operators > (that.value);
        break;

      case 92: // accesFigure
        value.copy< std::shared_ptr<AccesFigureNode> > (that.value);
        break;

      case 105: // affectation
        value.copy< std::shared_ptr<AffectationSimpleVariableNode> > (that.value);
        break;

      case 109: // appelFonction
        value.copy< std::shared_ptr<AppelFonctionNode> > (that.value);
        break;

      case 76: // attributAffectation
      case 93: // setAttribut
        value.copy< std::shared_ptr<AttributNode> > (that.value);
        break;

      case 82: // declarationCanva
        value.copy< std::shared_ptr<CanevaNode> > (that.value);
        break;

      case 84: // carre
        value.copy< std::shared_ptr<CarreNode> > (that.value);
        break;

      case 87: // cercle
        value.copy< std::shared_ptr<CercleNode> > (that.value);
        break;

      case 90: // chemin
        value.copy< std::shared_ptr<CheminNode> > (that.value);
        break;

      case 99: // condition
        value.copy< std::shared_ptr<ConditionNode> > (that.value);
        break;

      case 96: // declarationVariable
        value.copy< std::shared_ptr<DeclarationVariable> > (that.value);
        break;

      case 81: // declarationVariableSimple
        value.copy< std::shared_ptr<DeclarationVariableSimple> > (that.value);
        break;

      case 88: // ellipse
        value.copy< std::shared_ptr<EllipseNode> > (that.value);
        break;

      case 83: // declarationFigure
        value.copy< std::shared_ptr<FigureNode> > (that.value);
        break;

      case 108: // fonction
        value.copy< std::shared_ptr<FonctionNode> > (that.value);
        break;

      case 103: // boucleFor
        value.copy< std::shared_ptr<ForLoopNode> > (that.value);
        break;

      case 101: // if
        value.copy< std::shared_ptr<IfNode> > (that.value);
        break;

      case 89: // ligne
        value.copy< std::shared_ptr<LigneNode> > (that.value);
        break;

      case 95: // modificationFigure
        value.copy< std::shared_ptr<ModificationFigureNode> > (that.value);
        break;

      case 72: // instruction
      case 78: // expression
        value.copy< std::shared_ptr<Noeud> > (that.value);
        break;

      case 85: // rectangle
        value.copy< std::shared_ptr<RectangleNode> > (that.value);
        break;

      case 91: // texte
        value.copy< std::shared_ptr<TexteNode> > (that.value);
        break;

      case 86: // triangle
        value.copy< std::shared_ptr<TriangleNode> > (that.value);
        break;

      case 104: // boucleWhile
        value.copy< std::shared_ptr<WhileNode> > (that.value);
        break;

      case 9: // INT_TYPE
      case 10: // BOOL_TYPE
      case 11: // FLOAT_TYPE
      case 12: // VARIABLE
      case 13: // STRING
      case 16: // HEXA_VALUE
      case 17: // COULEUR
      case 18: // ROTATION
      case 19: // REMPLISSAGE
      case 20: // OPACITE
      case 21: // EPAISSEUR
      case 37: // TAILLE
      case 38: // HAUTEUR
      case 39: // LARGEUR
      case 79: // variable
        value.copy< std::string > (that.value);
        break;

      case 107: // argumentsValues
        value.copy< std::vector<ExpressionPtr> > (that.value);
        break;

      case 111: // vectPos
        value.copy< std::vector<Position> > (that.value);
        break;

      case 73: // attributsInline
      case 74: // attributsCSS
      case 75: // attributs
        value.copy< std::vector<std::shared_ptr<AttributNode>> > (that.value);
        break;

      case 100: // conditions
        value.copy< std::vector<std::shared_ptr<ConditionNode>> > (that.value);
        break;

      case 71: // instructions
      case 102: // else
        value.copy< std::vector<std::shared_ptr<Noeud>> > (that.value);
        break;

      case 106: // arguments
        value.copy< std::vector<std::string> > (that.value);
        break;

      case 98: // stringComparator
        value.copy< string_operators > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 69: // programme
      case 70: // subProgramme
        value.move< ArbreSyntaxique > (that.value);
        break;

      case 77: // couleurValue
        value.move< CouleurPtr > (that.value);
        break;

      case 110: // operation
        value.move< ExpressionPtr > (that.value);
        break;

      case 94: // setTaille
        value.move< TailleType > (that.value);
        break;

      case 80: // boolValue
        value.move< bool > (that.value);
        break;

      case 6: // FLOAT
        value.move< float > (that.value);
        break;

      case 5: // NUMBER
        value.move< int > (that.value);
        break;

      case 97: // numberComparator
        value.move< operators > (that.value);
        break;

      case 92: // accesFigure
        value.move< std::shared_ptr<AccesFigureNode> > (that.value);
        break;

      case 105: // affectation
        value.move< std::shared_ptr<AffectationSimpleVariableNode> > (that.value);
        break;

      case 109: // appelFonction
        value.move< std::shared_ptr<AppelFonctionNode> > (that.value);
        break;

      case 76: // attributAffectation
      case 93: // setAttribut
        value.move< std::shared_ptr<AttributNode> > (that.value);
        break;

      case 82: // declarationCanva
        value.move< std::shared_ptr<CanevaNode> > (that.value);
        break;

      case 84: // carre
        value.move< std::shared_ptr<CarreNode> > (that.value);
        break;

      case 87: // cercle
        value.move< std::shared_ptr<CercleNode> > (that.value);
        break;

      case 90: // chemin
        value.move< std::shared_ptr<CheminNode> > (that.value);
        break;

      case 99: // condition
        value.move< std::shared_ptr<ConditionNode> > (that.value);
        break;

      case 96: // declarationVariable
        value.move< std::shared_ptr<DeclarationVariable> > (that.value);
        break;

      case 81: // declarationVariableSimple
        value.move< std::shared_ptr<DeclarationVariableSimple> > (that.value);
        break;

      case 88: // ellipse
        value.move< std::shared_ptr<EllipseNode> > (that.value);
        break;

      case 83: // declarationFigure
        value.move< std::shared_ptr<FigureNode> > (that.value);
        break;

      case 108: // fonction
        value.move< std::shared_ptr<FonctionNode> > (that.value);
        break;

      case 103: // boucleFor
        value.move< std::shared_ptr<ForLoopNode> > (that.value);
        break;

      case 101: // if
        value.move< std::shared_ptr<IfNode> > (that.value);
        break;

      case 89: // ligne
        value.move< std::shared_ptr<LigneNode> > (that.value);
        break;

      case 95: // modificationFigure
        value.move< std::shared_ptr<ModificationFigureNode> > (that.value);
        break;

      case 72: // instruction
      case 78: // expression
        value.move< std::shared_ptr<Noeud> > (that.value);
        break;

      case 85: // rectangle
        value.move< std::shared_ptr<RectangleNode> > (that.value);
        break;

      case 91: // texte
        value.move< std::shared_ptr<TexteNode> > (that.value);
        break;

      case 86: // triangle
        value.move< std::shared_ptr<TriangleNode> > (that.value);
        break;

      case 104: // boucleWhile
        value.move< std::shared_ptr<WhileNode> > (that.value);
        break;

      case 9: // INT_TYPE
      case 10: // BOOL_TYPE
      case 11: // FLOAT_TYPE
      case 12: // VARIABLE
      case 13: // STRING
      case 16: // HEXA_VALUE
      case 17: // COULEUR
      case 18: // ROTATION
      case 19: // REMPLISSAGE
      case 20: // OPACITE
      case 21: // EPAISSEUR
      case 37: // TAILLE
      case 38: // HAUTEUR
      case 39: // LARGEUR
      case 79: // variable
        value.move< std::string > (that.value);
        break;

      case 107: // argumentsValues
        value.move< std::vector<ExpressionPtr> > (that.value);
        break;

      case 111: // vectPos
        value.move< std::vector<Position> > (that.value);
        break;

      case 73: // attributsInline
      case 74: // attributsCSS
      case 75: // attributs
        value.move< std::vector<std::shared_ptr<AttributNode>> > (that.value);
        break;

      case 100: // conditions
        value.move< std::vector<std::shared_ptr<ConditionNode>> > (that.value);
        break;

      case 71: // instructions
      case 102: // else
        value.move< std::vector<std::shared_ptr<Noeud>> > (that.value);
        break;

      case 106: // arguments
        value.move< std::vector<std::string> > (that.value);
        break;

      case 98: // stringComparator
        value.move< string_operators > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
   Parser ::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
   Parser ::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
   Parser ::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
   Parser ::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
   Parser ::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
   Parser ::debug_stream () const
  {
    return *yycdebug_;
  }

  void
   Parser ::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


   Parser ::debug_level_type
   Parser ::debug_level () const
  {
    return yydebug_;
  }

  void
   Parser ::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

   Parser ::state_type
   Parser ::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
   Parser ::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
   Parser ::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
   Parser ::operator() ()
  {
    return parse ();
  }

  int
   Parser ::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 69: // programme
      case 70: // subProgramme
        yylhs.value.emplace< ArbreSyntaxique > ();
        break;

      case 77: // couleurValue
        yylhs.value.emplace< CouleurPtr > ();
        break;

      case 110: // operation
        yylhs.value.emplace< ExpressionPtr > ();
        break;

      case 94: // setTaille
        yylhs.value.emplace< TailleType > ();
        break;

      case 80: // boolValue
        yylhs.value.emplace< bool > ();
        break;

      case 6: // FLOAT
        yylhs.value.emplace< float > ();
        break;

      case 5: // NUMBER
        yylhs.value.emplace< int > ();
        break;

      case 97: // numberComparator
        yylhs.value.emplace< operators > ();
        break;

      case 92: // accesFigure
        yylhs.value.emplace< std::shared_ptr<AccesFigureNode> > ();
        break;

      case 105: // affectation
        yylhs.value.emplace< std::shared_ptr<AffectationSimpleVariableNode> > ();
        break;

      case 109: // appelFonction
        yylhs.value.emplace< std::shared_ptr<AppelFonctionNode> > ();
        break;

      case 76: // attributAffectation
      case 93: // setAttribut
        yylhs.value.emplace< std::shared_ptr<AttributNode> > ();
        break;

      case 82: // declarationCanva
        yylhs.value.emplace< std::shared_ptr<CanevaNode> > ();
        break;

      case 84: // carre
        yylhs.value.emplace< std::shared_ptr<CarreNode> > ();
        break;

      case 87: // cercle
        yylhs.value.emplace< std::shared_ptr<CercleNode> > ();
        break;

      case 90: // chemin
        yylhs.value.emplace< std::shared_ptr<CheminNode> > ();
        break;

      case 99: // condition
        yylhs.value.emplace< std::shared_ptr<ConditionNode> > ();
        break;

      case 96: // declarationVariable
        yylhs.value.emplace< std::shared_ptr<DeclarationVariable> > ();
        break;

      case 81: // declarationVariableSimple
        yylhs.value.emplace< std::shared_ptr<DeclarationVariableSimple> > ();
        break;

      case 88: // ellipse
        yylhs.value.emplace< std::shared_ptr<EllipseNode> > ();
        break;

      case 83: // declarationFigure
        yylhs.value.emplace< std::shared_ptr<FigureNode> > ();
        break;

      case 108: // fonction
        yylhs.value.emplace< std::shared_ptr<FonctionNode> > ();
        break;

      case 103: // boucleFor
        yylhs.value.emplace< std::shared_ptr<ForLoopNode> > ();
        break;

      case 101: // if
        yylhs.value.emplace< std::shared_ptr<IfNode> > ();
        break;

      case 89: // ligne
        yylhs.value.emplace< std::shared_ptr<LigneNode> > ();
        break;

      case 95: // modificationFigure
        yylhs.value.emplace< std::shared_ptr<ModificationFigureNode> > ();
        break;

      case 72: // instruction
      case 78: // expression
        yylhs.value.emplace< std::shared_ptr<Noeud> > ();
        break;

      case 85: // rectangle
        yylhs.value.emplace< std::shared_ptr<RectangleNode> > ();
        break;

      case 91: // texte
        yylhs.value.emplace< std::shared_ptr<TexteNode> > ();
        break;

      case 86: // triangle
        yylhs.value.emplace< std::shared_ptr<TriangleNode> > ();
        break;

      case 104: // boucleWhile
        yylhs.value.emplace< std::shared_ptr<WhileNode> > ();
        break;

      case 9: // INT_TYPE
      case 10: // BOOL_TYPE
      case 11: // FLOAT_TYPE
      case 12: // VARIABLE
      case 13: // STRING
      case 16: // HEXA_VALUE
      case 17: // COULEUR
      case 18: // ROTATION
      case 19: // REMPLISSAGE
      case 20: // OPACITE
      case 21: // EPAISSEUR
      case 37: // TAILLE
      case 38: // HAUTEUR
      case 39: // LARGEUR
      case 79: // variable
        yylhs.value.emplace< std::string > ();
        break;

      case 107: // argumentsValues
        yylhs.value.emplace< std::vector<ExpressionPtr> > ();
        break;

      case 111: // vectPos
        yylhs.value.emplace< std::vector<Position> > ();
        break;

      case 73: // attributsInline
      case 74: // attributsCSS
      case 75: // attributs
        yylhs.value.emplace< std::vector<std::shared_ptr<AttributNode>> > ();
        break;

      case 100: // conditions
        yylhs.value.emplace< std::vector<std::shared_ptr<ConditionNode>> > ();
        break;

      case 71: // instructions
      case 102: // else
        yylhs.value.emplace< std::vector<std::shared_ptr<Noeud>> > ();
        break;

      case 106: // arguments
        yylhs.value.emplace< std::vector<std::string> > ();
        break;

      case 98: // stringComparator
        yylhs.value.emplace< string_operators > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 174 "parser/parser.yy"
                 {
        driver.analyseCode(yystack_[0].value.as < ArbreSyntaxique > ());
    }
#line 2038 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 3:
#line 180 "parser/parser.yy"
                                {
        yystack_[0].value.as < ArbreSyntaxique > ().addNode(yystack_[2].value.as < std::shared_ptr<Noeud> > ());
        yylhs.value.as < ArbreSyntaxique > () = yystack_[0].value.as < ArbreSyntaxique > ();
    }
#line 2047 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 4:
#line 187 "parser/parser.yy"
       {
    }
#line 2054 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 5:
#line 191 "parser/parser.yy"
                                {
        yystack_[0].value.as < std::vector<std::shared_ptr<Noeud>> > ().push_back(yystack_[2].value.as < std::shared_ptr<Noeud> > ());
        yylhs.value.as < std::vector<std::shared_ptr<Noeud>> > () = yystack_[0].value.as < std::vector<std::shared_ptr<Noeud>> > ();
    }
#line 2063 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 6:
#line 199 "parser/parser.yy"
    {

    }
#line 2071 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 7:
#line 204 "parser/parser.yy"
                {
        yylhs.value.as < std::shared_ptr<Noeud> > () = yystack_[0].value.as < std::shared_ptr<Noeud> > ();
    }
#line 2079 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 8:
#line 209 "parser/parser.yy"
                        {
        yylhs.value.as < std::vector<std::shared_ptr<AttributNode>> > ().push_back(yystack_[0].value.as < std::shared_ptr<AttributNode> > ());
    }
#line 2087 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 9:
#line 215 "parser/parser.yy"
                                            {
        yystack_[2].value.as < std::vector<std::shared_ptr<AttributNode>> > ().push_back(yystack_[0].value.as < std::shared_ptr<AttributNode> > ());
        yylhs.value.as < std::vector<std::shared_ptr<AttributNode>> > () = yystack_[2].value.as < std::vector<std::shared_ptr<AttributNode>> > ();
    }
#line 2096 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 10:
#line 222 "parser/parser.yy"
                            {
        yylhs.value.as < std::vector<std::shared_ptr<AttributNode>> > ().push_back(yystack_[1].value.as < std::shared_ptr<AttributNode> > ());
    }
#line 2104 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 11:
#line 228 "parser/parser.yy"
                                            {
        yystack_[3].value.as < std::vector<std::shared_ptr<AttributNode>> > ().push_back(yystack_[0].value.as < std::shared_ptr<AttributNode> > ());
        yylhs.value.as < std::vector<std::shared_ptr<AttributNode>> > () = yystack_[3].value.as < std::vector<std::shared_ptr<AttributNode>> > ();
    }
#line 2113 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 12:
#line 234 "parser/parser.yy"
       {}
#line 2119 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 13:
#line 238 "parser/parser.yy"
                               {
        yylhs.value.as < std::vector<std::shared_ptr<AttributNode>> > () = yystack_[2].value.as < std::vector<std::shared_ptr<AttributNode>> > ();
    }
#line 2127 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 14:
#line 244 "parser/parser.yy"
                                           {
        yylhs.value.as < std::vector<std::shared_ptr<AttributNode>> > () = yystack_[1].value.as < std::vector<std::shared_ptr<AttributNode>> > ();
    }
#line 2135 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 15:
#line 250 "parser/parser.yy"
                             {
        yylhs.value.as < std::shared_ptr<AttributNode> > () = std::make_shared<ColorNode>(yystack_[0].value.as < CouleurPtr > ());
    }
#line 2143 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 16:
#line 256 "parser/parser.yy"
                                  {
        yylhs.value.as < std::shared_ptr<AttributNode> > () = std::make_shared<RemplissageNode>(yystack_[0].value.as < CouleurPtr > ());
    }
#line 2151 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 17:
#line 262 "parser/parser.yy"
                                {
        yylhs.value.as < std::shared_ptr<AttributNode> > () = std::make_shared<RotationNode>(yystack_[1].value.as < ExpressionPtr > ());
    }
#line 2159 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 18:
#line 268 "parser/parser.yy"
                          {
        yylhs.value.as < std::shared_ptr<AttributNode> > () = std::make_shared<OpaciteNode>(yystack_[0].value.as < ExpressionPtr > ());
    }
#line 2167 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 19:
#line 274 "parser/parser.yy"
                            {
        yylhs.value.as < std::shared_ptr<AttributNode> > () = std::make_shared<EpaisseurNode>(yystack_[0].value.as < ExpressionPtr > ());
    }
#line 2175 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 20:
#line 279 "parser/parser.yy"
               {
        yylhs.value.as < CouleurPtr > () = std::make_shared<CouleurConstante>(yystack_[0].value.as < std::string > ());
    }
#line 2183 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 21:
#line 285 "parser/parser.yy"
             {
        yylhs.value.as < CouleurPtr > () = std::make_shared<CouleurVariable>(yystack_[0].value.as < std::string > ());
    }
#line 2191 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 22:
#line 291 "parser/parser.yy"
                         { yylhs.value.as < std::shared_ptr<Noeud> > () = yystack_[1].value.as < std::shared_ptr<CanevaNode> > (); }
#line 2197 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 23:
#line 292 "parser/parser.yy"
                      { yylhs.value.as < std::shared_ptr<Noeud> > () = yystack_[0].value.as < std::shared_ptr<FigureNode> > (); }
#line 2203 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 24:
#line 293 "parser/parser.yy"
                       { yylhs.value.as < std::shared_ptr<Noeud> > () = yystack_[0].value.as < std::shared_ptr<ModificationFigureNode> > (); }
#line 2209 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 25:
#line 294 "parser/parser.yy"
                              { yylhs.value.as < std::shared_ptr<Noeud> > () = yystack_[0].value.as < std::shared_ptr<DeclarationVariableSimple> > (); }
#line 2215 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 26:
#line 295 "parser/parser.yy"
                        { yylhs.value.as < std::shared_ptr<Noeud> > () = yystack_[0].value.as < std::shared_ptr<DeclarationVariable> > (); }
#line 2221 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 27:
#line 296 "parser/parser.yy"
       { yylhs.value.as < std::shared_ptr<Noeud> > () = yystack_[0].value.as < std::shared_ptr<IfNode> > (); }
#line 2227 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 28:
#line 297 "parser/parser.yy"
                { yylhs.value.as < std::shared_ptr<Noeud> > () = yystack_[0].value.as < std::shared_ptr<AccesFigureNode> > (); }
#line 2233 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 29:
#line 298 "parser/parser.yy"
              { yylhs.value.as < std::shared_ptr<Noeud> > () = yystack_[0].value.as < std::shared_ptr<ForLoopNode> > (); }
#line 2239 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 30:
#line 299 "parser/parser.yy"
                { yylhs.value.as < std::shared_ptr<Noeud> > () = yystack_[0].value.as < std::shared_ptr<WhileNode> > (); }
#line 2245 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 31:
#line 300 "parser/parser.yy"
                { yylhs.value.as < std::shared_ptr<Noeud> > () = yystack_[0].value.as < std::shared_ptr<AffectationSimpleVariableNode> > (); }
#line 2251 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 32:
#line 301 "parser/parser.yy"
             { yylhs.value.as < std::shared_ptr<Noeud> > () = yystack_[0].value.as < std::shared_ptr<FonctionNode> > (); }
#line 2257 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 33:
#line 302 "parser/parser.yy"
                      { yylhs.value.as < std::shared_ptr<Noeud> > () = yystack_[1].value.as < std::shared_ptr<AppelFonctionNode> > (); }
#line 2263 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 34:
#line 305 "parser/parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2269 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 35:
#line 305 "parser/parser.yy"
                      {
        yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
    }
#line 2277 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 36:
#line 310 "parser/parser.yy"
         {
        yylhs.value.as < bool > () = true;
    }
#line 2285 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 37:
#line 316 "parser/parser.yy"
          {
        yylhs.value.as < bool > () = false;
    }
#line 2293 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 38:
#line 321 "parser/parser.yy"
                                    {
        yylhs.value.as < std::shared_ptr<DeclarationVariableSimple> > () = std::make_shared<DeclarationVariableInt>(yystack_[2].value.as < std::string > (), yystack_[0].value.as < ExpressionPtr > ());
    }
#line 2301 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 39:
#line 327 "parser/parser.yy"
                                     {
        yylhs.value.as < std::shared_ptr<DeclarationVariableSimple> > () = std::make_shared<DeclarationVariableBool>(yystack_[2].value.as < std::string > (), yystack_[0].value.as < bool > ());
    }
#line 2309 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 40:
#line 333 "parser/parser.yy"
                                    {
        yylhs.value.as < std::shared_ptr<DeclarationVariableSimple> > () = std::make_shared<DeclarationVariableString>(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ());
    }
#line 2317 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 41:
#line 338 "parser/parser.yy"
                               {
        yylhs.value.as < std::shared_ptr<CanevaNode> > () = std::make_shared<CanevaNode>(yystack_[1].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > ());
    }
#line 2325 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 42:
#line 344 "parser/parser.yy"
       {
 yylhs.value.as < std::shared_ptr<FigureNode> > () = yystack_[0].value.as < std::shared_ptr<CarreNode> > ();
 }
#line 2333 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 43:
#line 347 "parser/parser.yy"
             {
 yylhs.value.as < std::shared_ptr<FigureNode> > () = yystack_[0].value.as < std::shared_ptr<RectangleNode> > ();
 }
#line 2341 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 44:
#line 350 "parser/parser.yy"
            {
 yylhs.value.as < std::shared_ptr<FigureNode> > () = yystack_[0].value.as < std::shared_ptr<TriangleNode> > ();
 }
#line 2349 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 45:
#line 354 "parser/parser.yy"
          {
 yylhs.value.as < std::shared_ptr<FigureNode> > () = yystack_[0].value.as < std::shared_ptr<CercleNode> > ();
 }
#line 2357 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 46:
#line 358 "parser/parser.yy"
           {
 yylhs.value.as < std::shared_ptr<FigureNode> > () = yystack_[0].value.as < std::shared_ptr<EllipseNode> > ();
 }
#line 2365 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 47:
#line 362 "parser/parser.yy"
          {
 yylhs.value.as < std::shared_ptr<FigureNode> > () = yystack_[0].value.as < std::shared_ptr<CheminNode> > ();
 }
#line 2373 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 48:
#line 366 "parser/parser.yy"
         {
 yylhs.value.as < std::shared_ptr<FigureNode> > () = yystack_[0].value.as < std::shared_ptr<LigneNode> > ();
 }
#line 2381 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 49:
#line 370 "parser/parser.yy"
         {
 yylhs.value.as < std::shared_ptr<FigureNode> > () = yystack_[0].value.as < std::shared_ptr<TexteNode> > ();
 }
#line 2389 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 50:
#line 378 "parser/parser.yy"
                                               {
    std::shared_ptr<CarreNode> carre = std::make_shared<CarreNode>(yystack_[3].value.as < ExpressionPtr > (), yystack_[2].value.as < ExpressionPtr > (), yystack_[1].value.as < ExpressionPtr > ());
    carre->setAttributs(yystack_[0].value.as < std::vector<std::shared_ptr<AttributNode>> > ());
    yylhs.value.as < std::shared_ptr<CarreNode> > () = carre;
 }
#line 2399 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 51:
#line 385 "parser/parser.yy"
                                                                                                     {
    std::shared_ptr<RectangleNode> rectangle = std::make_shared<RectangleNode>(yystack_[8].value.as < ExpressionPtr > (), yystack_[7].value.as < ExpressionPtr > (), yystack_[6].value.as < ExpressionPtr > (),yystack_[5].value.as < ExpressionPtr > (),yystack_[4].value.as < ExpressionPtr > (),yystack_[3].value.as < ExpressionPtr > (),yystack_[2].value.as < ExpressionPtr > (),yystack_[1].value.as < ExpressionPtr > ());
    rectangle->setAttributs(yystack_[0].value.as < std::vector<std::shared_ptr<AttributNode>> > ());
    yylhs.value.as < std::shared_ptr<RectangleNode> > () = rectangle;
 }
#line 2409 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 52:
#line 393 "parser/parser.yy"
                                                            {
    std::shared_ptr<TriangleNode> triangle = std::make_shared<TriangleNode>(yystack_[4].value.as < ExpressionPtr > (), yystack_[3].value.as < ExpressionPtr > (), yystack_[2].value.as < ExpressionPtr > (),yystack_[1].value.as < ExpressionPtr > ());
    triangle->setAttributs(yystack_[0].value.as < std::vector<std::shared_ptr<AttributNode>> > ());
    yylhs.value.as < std::shared_ptr<TriangleNode> > () = triangle;
 }
#line 2419 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 53:
#line 401 "parser/parser.yy"
                                                {
    std::shared_ptr<CercleNode> cercle = std::make_shared<CercleNode>(yystack_[3].value.as < ExpressionPtr > (), yystack_[2].value.as < ExpressionPtr > (), yystack_[1].value.as < ExpressionPtr > ());
    cercle->setAttributs(yystack_[0].value.as < std::vector<std::shared_ptr<AttributNode>> > ());
    yylhs.value.as < std::shared_ptr<CercleNode> > () = cercle;
 }
#line 2429 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 54:
#line 409 "parser/parser.yy"
                                                          {
    std::shared_ptr<EllipseNode> ellipse = std::make_shared<EllipseNode>(yystack_[4].value.as < ExpressionPtr > (), yystack_[3].value.as < ExpressionPtr > (), yystack_[2].value.as < ExpressionPtr > (),yystack_[1].value.as < ExpressionPtr > ());
    ellipse->setAttributs(yystack_[0].value.as < std::vector<std::shared_ptr<AttributNode>> > ());
    yylhs.value.as < std::shared_ptr<EllipseNode> > () = ellipse;
 }
#line 2439 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 55:
#line 417 "parser/parser.yy"
                                                        {
    std::shared_ptr<LigneNode> ligne = std::make_shared<LigneNode>(yystack_[4].value.as < ExpressionPtr > (), yystack_[3].value.as < ExpressionPtr > (), yystack_[2].value.as < ExpressionPtr > (),yystack_[1].value.as < ExpressionPtr > ());
    ligne->setAttributs(yystack_[0].value.as < std::vector<std::shared_ptr<AttributNode>> > ());
    yylhs.value.as < std::shared_ptr<LigneNode> > () = ligne;
 }
#line 2449 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 56:
#line 425 "parser/parser.yy"
                         {
    std::shared_ptr<CheminNode> chemin = std::make_shared<CheminNode>(yystack_[1].value.as < std::vector<Position> > ());
    chemin->setAttributs(yystack_[0].value.as < std::vector<std::shared_ptr<AttributNode>> > ());
    yylhs.value.as < std::shared_ptr<CheminNode> > () = chemin;
 }
#line 2459 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 57:
#line 433 "parser/parser.yy"
                                                  {
    std::shared_ptr<TexteNode> texte = std::make_shared<TexteNode>(yystack_[4].value.as < ExpressionPtr > (), yystack_[3].value.as < ExpressionPtr > (), yystack_[2].value.as < std::string > (),yystack_[1].value.as < std::string > ());
    texte->setAttributs(yystack_[0].value.as < std::vector<std::shared_ptr<AttributNode>> > ());
    yylhs.value.as < std::shared_ptr<TexteNode> > () = texte;
 }
#line 2469 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 58:
#line 440 "parser/parser.yy"
                             {
        yylhs.value.as < std::shared_ptr<AccesFigureNode> > () = std::make_shared<AccesIndexNode>(FigureTypes::carre, yystack_[2].value.as < int > ());
    }
#line 2477 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 59:
#line 446 "parser/parser.yy"
                                {
        yylhs.value.as < std::shared_ptr<AccesFigureNode> > () = std::make_shared<AccesIndexNode>(FigureTypes::triangle, yystack_[2].value.as < int > ());
    }
#line 2485 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 60:
#line 452 "parser/parser.yy"
                 {
        yylhs.value.as < std::shared_ptr<AccesFigureNode> > () = std::make_shared<AccesVariableNode>(yystack_[1].value.as < std::string > ());
    }
#line 2493 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 61:
#line 457 "parser/parser.yy"
                             {
        yylhs.value.as < std::shared_ptr<AttributNode> > () = std::make_shared<ColorNode>(yystack_[0].value.as < CouleurPtr > ());
    }
#line 2501 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 62:
#line 463 "parser/parser.yy"
                                  {
        yylhs.value.as < std::shared_ptr<AttributNode> > () = std::make_shared<RemplissageNode>(yystack_[0].value.as < CouleurPtr > ());
    }
#line 2509 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 63:
#line 469 "parser/parser.yy"
                                {
        yylhs.value.as < std::shared_ptr<AttributNode> > () = std::make_shared<RotationNode>(yystack_[1].value.as < ExpressionPtr > ());
    }
#line 2517 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 64:
#line 475 "parser/parser.yy"
                              {
        yylhs.value.as < std::shared_ptr<AttributNode> > () = std::make_shared<OpaciteNode>(yystack_[1].value.as < ExpressionPtr > ());
    }
#line 2525 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 65:
#line 481 "parser/parser.yy"
                            {
        yylhs.value.as < std::shared_ptr<AttributNode> > () = std::make_shared<EpaisseurNode>(yystack_[0].value.as < ExpressionPtr > ());
    }
#line 2533 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 66:
#line 487 "parser/parser.yy"
           {
        yylhs.value.as < TailleType > () = TailleType::taille;
    }
#line 2541 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 67:
#line 491 "parser/parser.yy"
            {
        yylhs.value.as < TailleType > () = TailleType::hauteur;
    }
#line 2549 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 68:
#line 495 "parser/parser.yy"
            {
        yylhs.value.as < TailleType > () = TailleType::largeur;
    }
#line 2557 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 69:
#line 501 "parser/parser.yy"
                           {
        yylhs.value.as < std::shared_ptr<ModificationFigureNode> > () = std::make_shared<ModificationAttributsNode>(yystack_[1].value.as < std::shared_ptr<AccesFigureNode> > (), yystack_[0].value.as < std::shared_ptr<AttributNode> > ());
    }
#line 2565 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 70:
#line 507 "parser/parser.yy"
                                        {
        yylhs.value.as < std::shared_ptr<ModificationFigureNode> > () = std::make_shared<ModificationTailleFigureNode>(yystack_[3].value.as < std::shared_ptr<AccesFigureNode> > (), yystack_[2].value.as < TailleType > (), yystack_[0].value.as < ExpressionPtr > ());
    }
#line 2573 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 71:
#line 513 "parser/parser.yy"
                                   {
        yylhs.value.as < std::shared_ptr<DeclarationVariable> > () = std::make_shared<DeclarationVariable>(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::shared_ptr<FigureNode> > ());
    }
#line 2581 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 72:
#line 518 "parser/parser.yy"
          { yylhs.value.as < operators > () = operators::equal; }
#line 2587 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 73:
#line 519 "parser/parser.yy"
             { yylhs.value.as < operators > () = operators::not_equal; }
#line 2593 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 74:
#line 520 "parser/parser.yy"
              { yylhs.value.as < operators > () = operators::less_equal; }
#line 2599 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 75:
#line 521 "parser/parser.yy"
                 { yylhs.value.as < operators > () = operators::greater_equal; }
#line 2605 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 76:
#line 522 "parser/parser.yy"
         { yylhs.value.as < operators > () = operators::less; }
#line 2611 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 77:
#line 523 "parser/parser.yy"
            { yylhs.value.as < operators > () = operators::greater; }
#line 2617 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 78:
#line 526 "parser/parser.yy"
                { yylhs.value.as < string_operators > () = string_operators::equal; }
#line 2623 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 79:
#line 527 "parser/parser.yy"
                   { yylhs.value.as < string_operators > () = string_operators::not_equal; }
#line 2629 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 80:
#line 531 "parser/parser.yy"
                                                     {
        yylhs.value.as < std::shared_ptr<ConditionNode> > () = std::make_shared<TailleConditionNode>(yystack_[3].value.as < std::shared_ptr<AccesFigureNode> > (), yystack_[1].value.as < operators > (), yystack_[0].value.as < ExpressionPtr > (), yystack_[2].value.as < TailleType > ());
    }
#line 2637 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 81:
#line 537 "parser/parser.yy"
             {
        yylhs.value.as < std::shared_ptr<ConditionNode> > () = std::make_shared<BooleanVariableConditionNode>(yystack_[0].value.as < std::string > ());
    }
#line 2645 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 82:
#line 543 "parser/parser.yy"
                                                      {
        yylhs.value.as < std::shared_ptr<ConditionNode> > () = std::make_shared<CouleurConditionNode>(yystack_[3].value.as < std::shared_ptr<AccesFigureNode> > (), yystack_[1].value.as < string_operators > (), yystack_[0].value.as < CouleurPtr > ());
    }
#line 2653 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 83:
#line 549 "parser/parser.yy"
              {
        yylhs.value.as < std::vector<std::shared_ptr<ConditionNode>> > ().push_back(yystack_[0].value.as < std::shared_ptr<ConditionNode> > ());
    }
#line 2661 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 84:
#line 555 "parser/parser.yy"
                                             {
        yystack_[5].value.as < std::vector<std::shared_ptr<ConditionNode>> > ().push_back(yystack_[1].value.as < std::shared_ptr<ConditionNode> > ());
        yylhs.value.as < std::vector<std::shared_ptr<ConditionNode>> > () = yystack_[5].value.as < std::vector<std::shared_ptr<ConditionNode>> > ();
    }
#line 2670 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 85:
#line 561 "parser/parser.yy"
                                                                {
        yylhs.value.as < std::shared_ptr<IfNode> > () = std::make_shared<IfNode>(yystack_[3].value.as < std::vector<std::shared_ptr<Noeud>> > (), yystack_[0].value.as < std::vector<std::shared_ptr<Noeud>> > (), yystack_[8].value.as < std::vector<std::shared_ptr<ConditionNode>> > ());
    }
#line 2678 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 86:
#line 566 "parser/parser.yy"
    {   
    }
#line 2685 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 87:
#line 571 "parser/parser.yy"
                                  {
        yylhs.value.as < std::vector<std::shared_ptr<Noeud>> > () = yystack_[1].value.as < std::vector<std::shared_ptr<Noeud>> > ();
    }
#line 2693 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 88:
#line 577 "parser/parser.yy"
                                                  {
        yylhs.value.as < std::shared_ptr<ForLoopNode> > () = std::make_shared<ForLoopNode>(yystack_[1].value.as < std::vector<std::shared_ptr<Noeud>> > (), yystack_[5].value.as < ExpressionPtr > ());
    }
#line 2701 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 89:
#line 582 "parser/parser.yy"
                                                     {
        yylhs.value.as < std::shared_ptr<WhileNode> > () = std::make_shared<WhileNode>(yystack_[1].value.as < std::vector<std::shared_ptr<Noeud>> > (), yystack_[5].value.as < std::vector<std::shared_ptr<ConditionNode>> > ());
    }
#line 2709 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 90:
#line 588 "parser/parser.yy"
                           { 
        yylhs.value.as < std::shared_ptr<AffectationSimpleVariableNode> > () = std::make_shared<AffectationDoubleVariableNode>(yystack_[2].value.as < std::string > (), yystack_[0].value.as < ExpressionPtr > ());
    }
#line 2717 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 91:
#line 594 "parser/parser.yy"
                           {
        yylhs.value.as < std::shared_ptr<AffectationSimpleVariableNode> > () = std::make_shared<AffectationBoolVariableNode>(yystack_[2].value.as < std::string > (), yystack_[0].value.as < bool > ());
    }
#line 2725 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 92:
#line 600 "parser/parser.yy"
                            {
        yylhs.value.as < std::shared_ptr<AffectationSimpleVariableNode> > () = std::make_shared<AffectationCouleurVariableNode>(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ());
    }
#line 2733 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 93:
#line 605 "parser/parser.yy"
    {
    }
#line 2740 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 94:
#line 610 "parser/parser.yy"
                       {
        yystack_[0].value.as < std::vector<std::string> > ().push_back(yystack_[1].value.as < std::string > ());
        yylhs.value.as < std::vector<std::string> > () = yystack_[0].value.as < std::vector<std::string> > ();
    }
#line 2749 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 95:
#line 616 "parser/parser.yy"
    {
    }
#line 2756 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 96:
#line 621 "parser/parser.yy"
                              {
        yystack_[0].value.as < std::vector<ExpressionPtr> > ().push_back(yystack_[1].value.as < ExpressionPtr > ());
        yylhs.value.as < std::vector<ExpressionPtr> > () = yystack_[0].value.as < std::vector<ExpressionPtr> > ();
    }
#line 2765 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 97:
#line 628 "parser/parser.yy"
                                                                {
        yylhs.value.as < std::shared_ptr<FonctionNode> > () = std::make_shared<FonctionNode>(yystack_[1].value.as < std::vector<std::shared_ptr<Noeud>> > (), yystack_[7].value.as < std::string > (), yystack_[5].value.as < std::vector<std::string> > ());
    }
#line 2773 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 98:
#line 633 "parser/parser.yy"
                             {
        yylhs.value.as < std::shared_ptr<AppelFonctionNode> > () = std::make_shared<AppelFonctionNode>(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::vector<ExpressionPtr> > ());
    }
#line 2781 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 99:
#line 639 "parser/parser.yy"
           {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<Constante>(yystack_[0].value.as < int > ());
    }
#line 2789 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 100:
#line 643 "parser/parser.yy"
               {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<Variable>(yystack_[0].value.as < std::string > ());
    }
#line 2797 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 101:
#line 646 "parser/parser.yy"
                        {
        yylhs.value.as < ExpressionPtr > () = yystack_[1].value.as < ExpressionPtr > ();
    }
#line 2805 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 102:
#line 649 "parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::plus);
    }
#line 2813 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 103:
#line 652 "parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::moins);
    }
#line 2821 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 104:
#line 655 "parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::multiplie);
    }
#line 2829 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 105:
#line 658 "parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::divise);
    }
#line 2837 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 106:
#line 661 "parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionUnaire>(yystack_[0].value.as < ExpressionPtr > (),OperateurUnaire::neg);
    }
#line 2845 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 107:
#line 666 "parser/parser.yy"
                        {
        yylhs.value.as < std::vector<Position> > ().push_back(Position(yystack_[1].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > ()));
    }
#line 2853 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 108:
#line 669 "parser/parser.yy"
                                  {
        yystack_[2].value.as < std::vector<Position> > ().push_back(Position(yystack_[1].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > ()));
        for(auto i : yystack_[2].value.as < std::vector<Position> > ()) {
            yylhs.value.as < std::vector<Position> > ().push_back(i);
        }
    }
#line 2864 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;


#line 2868 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
   Parser ::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
   Parser ::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const short  Parser ::yypact_ninf_ = -195;

  const signed char  Parser ::yytable_ninf_ = -107;

  const short
   Parser ::yypact_[] =
  {
     289,  -195,     4,     4,  -195,     4,   -41,     4,    93,   -35,
      93,    93,    21,   116,    93,    93,    93,    93,    93,    38,
    -195,    64,  -195,    31,  -195,    13,  -195,  -195,  -195,  -195,
    -195,  -195,  -195,  -195,  -195,   341,  -195,  -195,  -195,  -195,
    -195,  -195,  -195,    16,  -195,    29,    43,    45,    82,    52,
    -195,    93,    93,  -195,    49,    82,     8,     8,   106,     8,
     115,     8,     8,     8,     8,     8,    27,     8,  -195,   289,
     237,  -195,  -195,     8,  -195,    68,    72,    78,    79,    86,
    -195,  -195,  -195,  -195,    91,  -195,    93,    20,   109,    81,
      92,    82,   104,   177,  -195,    90,     4,  -195,   -30,   112,
      93,    93,    93,    93,   107,    93,   296,     8,   110,     8,
     114,     8,     8,     8,     8,   296,   301,  -195,   178,  -195,
       8,   136,  -195,  -195,  -195,  -195,    93,    93,  -195,  -195,
     296,  -195,     3,    93,     3,    93,    93,    93,   296,  -195,
    -195,   113,   -18,   238,   156,     4,   119,  -195,   180,   -19,
     -19,  -195,  -195,   133,    73,     8,   129,    84,   132,     8,
      84,     8,     8,   137,   138,   143,   149,   157,    24,  -195,
     301,   296,   218,  -195,  -195,  -195,   169,  -195,   330,   296,
     296,   183,  -195,  -195,     3,  -195,  -195,  -195,  -195,  -195,
    -195,    93,   179,  -195,   188,   329,   235,     8,  -195,  -195,
    -195,    84,  -195,    84,    84,     3,    93,     3,    93,    93,
     301,  -195,     9,   190,    -1,  -195,  -195,   182,  -195,   296,
     247,   248,   193,   252,   329,     8,  -195,  -195,  -195,  -195,
     176,  -195,   296,   296,  -195,   197,   254,  -195,  -195,   134,
     329,   329,  -195,   329,   200,     8,  -195,  -195,   301,   195,
     204,   205,  -195,  -195,     8,  -195,  -195,   263,  -195,    84,
     249,  -195,   217,  -195,   273,   329,   226,  -195
  };

  const signed char
   Parser ::yydefact_[] =
  {
       0,     4,     0,     0,    34,     0,     0,     0,     0,     0,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     0,     7,    95,    25,     0,    23,    42,    43,    44,
      45,    46,    48,    47,    49,    28,    24,    26,    27,    29,
      30,    31,    32,     0,    35,     0,     0,     0,     0,     0,
      99,     0,     0,   100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,    60,    98,    95,    22,     0,     0,     0,     0,     0,
      66,    67,    68,    69,     0,    33,     0,     0,     0,     0,
       0,     0,    81,     0,    83,     0,    93,   106,     0,     0,
       0,     0,     0,     0,     0,     0,    41,     0,     0,     0,
       0,     0,     0,     0,     0,   107,     0,    12,     0,    56,
       0,     0,     3,    36,    37,    92,     0,     0,    91,    71,
      90,    96,     0,     0,     0,     0,     0,     0,    38,    39,
      40,     0,     0,     0,     0,    93,     0,   101,     0,   103,
     102,   104,   105,     0,   103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       0,   108,     0,    20,    61,    21,     0,    62,     0,    65,
      70,     0,    78,    79,     0,    72,    73,    76,    74,    77,
      75,     0,     0,    94,     0,     6,     0,     0,    58,    50,
      59,     0,    53,     0,     0,     0,     0,     0,     0,     0,
       0,    14,     0,     0,     0,    63,    64,     0,    82,    80,
       0,     0,     0,     0,     6,     0,    52,    54,    55,    15,
       0,    16,    18,    19,     9,     0,     0,    10,    57,     0,
       6,     6,    88,     6,     0,     0,    17,    13,     0,     0,
       0,     0,     5,    89,     0,    11,    84,     0,    97,     0,
      86,    51,     0,    85,     0,     6,     0,    87
  };

  const short
   Parser ::yypgoto_[] =
  {
    -195,  -195,   220,  -194,    10,  -195,  -195,  -151,  -159,  -130,
    -195,     0,   199,  -195,  -195,   221,  -195,  -195,  -195,  -195,
    -195,  -195,  -195,  -195,   -47,  -195,   194,  -195,  -195,  -195,
    -195,    54,   -26,  -195,  -195,  -195,  -195,  -195,   150,   224,
    -195,  -195,    99,  -195
  };

  const short
   Parser ::yydefgoto_[] =
  {
      -1,    19,    20,   222,   223,   168,   212,   119,   169,   174,
      22,    53,   128,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    83,    84,    36,    37,   191,
     184,    94,    95,    38,   263,    39,    40,    41,   146,    72,
      42,    43,    59,    66
  };

  const short
   Parser ::yytable_[] =
  {
      23,    93,    45,    46,   177,    47,   199,    49,    93,   202,
      21,   213,   235,    50,   116,     4,     4,   182,   183,   173,
       4,   100,   101,   102,   103,    48,    50,   123,   124,   104,
     244,    55,    50,     4,   102,   103,    50,   147,    68,     4,
      44,    44,   116,     4,    93,    44,   250,   251,    92,   252,
     226,   234,   227,   228,   218,    92,   117,   118,    44,   105,
     101,   102,   103,   238,    44,   141,   236,    69,    44,    23,
      74,   266,    51,    85,    52,   229,    99,   231,    51,    21,
     210,   211,    51,    58,   117,   118,  -106,    52,  -106,   255,
      86,    92,    70,    52,     4,    71,   145,    52,    50,   116,
     100,   101,   102,   103,    87,     4,    88,    54,   261,    56,
      57,   108,    61,    62,    63,    64,    65,    67,    96,    44,
     110,    50,    73,    89,    90,   140,  -106,  -106,     4,   132,
      44,  -106,   175,   133,   175,   100,   101,   102,   103,   134,
     135,   117,   118,    58,    51,   145,     4,   136,    91,   172,
      97,    98,   137,    44,    60,   106,   107,   144,   109,    52,
     111,   112,   113,   114,   115,   120,   121,    51,    71,   130,
     148,    44,    73,   156,   153,    89,    90,   158,    60,   192,
     181,   170,    52,   195,   175,   138,   194,   100,   101,   102,
     103,   196,    93,   198,   142,    23,   200,   205,   206,   149,
     150,   151,   152,   207,   154,   175,   155,   175,   157,   208,
     159,   160,   161,   162,    80,    81,    82,   209,   215,   171,
     100,   101,   102,   103,    23,   246,    61,   100,   101,   102,
     103,   214,   176,   217,   178,   179,   180,   220,   224,    92,
      23,    23,    50,    23,   123,   124,   221,   237,   239,     4,
     240,   241,   242,   125,   197,   243,   247,   248,   201,   253,
     203,   204,   256,   257,   258,    23,   260,   185,   186,   187,
     188,   189,   190,   262,    44,   264,   265,    11,   126,   127,
      14,    15,    16,    17,    18,   267,   139,   143,    51,   122,
     219,   129,     1,   249,     0,   193,   225,   131,     2,     3,
       0,     4,     0,    52,     0,   230,     5,   232,   233,     0,
       0,     6,     0,     0,     7,     8,     0,     9,   163,   164,
     165,   166,   167,     0,   245,     0,    10,     0,     0,    11,
      12,    13,    14,    15,    16,    17,    18,     0,     2,     3,
       0,     4,     0,     0,   254,     0,     5,   100,   101,   102,
     103,     6,     0,   259,     7,     8,     0,     9,    75,    76,
      77,    78,    79,     0,     0,     0,    10,     0,     0,    11,
      12,    13,    14,    15,    16,    17,    18,     0,    80,    81,
      82,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   216
  };

  const short
   Parser ::yycheck_[] =
  {
       0,    48,     2,     3,   134,     5,   157,     7,    55,   160,
       0,   170,     3,     5,    15,    12,    12,    35,    36,    16,
      12,    51,    52,    53,    54,    66,     5,     7,     8,    55,
     224,    66,     5,    12,    53,    54,     5,    67,     0,    12,
      37,    37,    15,    12,    91,    37,   240,   241,    48,   243,
     201,   210,   203,   204,   184,    55,    57,    58,    37,    51,
      52,    53,    54,   214,    37,    91,    57,     3,    37,    69,
      57,   265,    51,    57,    66,   205,    27,   207,    51,    69,
      56,    57,    51,    62,    57,    58,    13,    66,    15,   248,
      61,    91,    61,    66,    12,    64,    96,    66,     5,    15,
      51,    52,    53,    54,    61,    12,    61,     8,   259,    10,
      11,     5,    13,    14,    15,    16,    17,    18,    66,    37,
       5,     5,    23,    41,    42,    16,    53,    54,    12,    61,
      37,    58,   132,    61,   134,    51,    52,    53,    54,    61,
      61,    57,    58,    62,    51,   145,    12,    61,    66,    13,
      51,    52,    61,    37,    62,    56,    57,    67,    59,    66,
      61,    62,    63,    64,    65,    66,    67,    51,    64,    70,
      58,    37,    73,    63,    67,    41,    42,    63,    62,    23,
      67,     3,    66,     3,   184,    86,    67,    51,    52,    53,
      54,    58,   239,    64,    17,   195,    64,    60,    60,   100,
     101,   102,   103,    60,   105,   205,   107,   207,   109,    60,
     111,   112,   113,   114,    37,    38,    39,    60,    49,   120,
      51,    52,    53,    54,   224,    49,   127,    51,    52,    53,
      54,    13,   133,    50,   135,   136,   137,    58,     3,   239,
     240,   241,     5,   243,     7,     8,    58,    57,    66,    12,
       3,     3,    59,    16,   155,     3,    59,     3,   159,    59,
     161,   162,    67,    59,    59,   265,     3,    29,    30,    31,
      32,    33,    34,    24,    37,    58,     3,    40,    41,    42,
      43,    44,    45,    46,    47,    59,    87,    93,    51,    69,
     191,    70,     3,   239,    -1,   145,   197,    73,     9,    10,
      -1,    12,    -1,    66,    -1,   206,    17,   208,   209,    -1,
      -1,    22,    -1,    -1,    25,    26,    -1,    28,    17,    18,
      19,    20,    21,    -1,   225,    -1,    37,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,     9,    10,
      -1,    12,    -1,    -1,   245,    -1,    17,    51,    52,    53,
      54,    22,    -1,   254,    25,    26,    -1,    28,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    37,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    37,    38,
      39,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,     3,     9,    10,    12,    17,    22,    25,    26,    28,
      37,    40,    41,    42,    43,    44,    45,    46,    47,    69,
      70,    72,    78,    79,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    95,    96,   101,   103,
     104,   105,   108,   109,    37,    79,    79,    79,    66,    79,
       5,    51,    66,    79,   110,    66,   110,   110,    62,   110,
      62,   110,   110,   110,   110,   110,   111,   110,     0,     3,
      61,    64,   107,   110,    57,    17,    18,    19,    20,    21,
      37,    38,    39,    93,    94,    57,    61,    61,    61,    41,
      42,    66,    79,    92,    99,   100,    66,   110,   110,    27,
      51,    52,    53,    54,   100,    51,   110,   110,     5,   110,
       5,   110,   110,   110,   110,   110,    15,    57,    58,    75,
     110,   110,    70,     7,     8,    16,    41,    42,    80,    83,
     110,   107,    61,    61,    61,    61,    61,    61,   110,    80,
      16,   100,    17,    94,    67,    79,   106,    67,    58,   110,
     110,   110,   110,    67,   110,   110,    63,   110,    63,   110,
     110,   110,   110,    17,    18,    19,    20,    21,    73,    76,
       3,   110,    13,    16,    77,    79,   110,    77,   110,   110,
     110,    67,    35,    36,    98,    29,    30,    31,    32,    33,
      34,    97,    23,   106,    67,     3,    58,   110,    64,    75,
      64,   110,    75,   110,   110,    60,    60,    60,    60,    60,
      56,    57,    74,    76,    13,    49,    65,    50,    77,   110,
      58,    58,    71,    72,     3,   110,    75,    75,    75,    77,
     110,    77,   110,   110,    76,     3,    57,    57,    75,    66,
       3,     3,    59,     3,    71,   110,    49,    59,     3,    99,
      71,    71,    71,    59,   110,    76,    67,    59,    59,   110,
       3,    75,    24,   102,    58,     3,    71,    59
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    68,    69,    70,    70,    71,    71,    72,    73,    73,
      74,    74,    75,    75,    75,    76,    76,    76,    76,    76,
      77,    77,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    79,    79,    80,    80,    81,    81,
      81,    82,    83,    83,    83,    83,    83,    83,    83,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    92,
      92,    93,    93,    93,    93,    93,    94,    94,    94,    95,
      95,    96,    97,    97,    97,    97,    97,    97,    98,    98,
      99,    99,    99,   100,   100,   101,   102,   102,   103,   104,
     105,   105,   105,   106,   106,   107,   107,   108,   109,   110,
     110,   110,   110,   110,   110,   110,   110,   111,   111
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     1,     3,     1,     3,     0,     1,     1,     3,
       2,     4,     1,     5,     3,     3,     3,     4,     3,     3,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     4,     4,
       4,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       5,    10,     6,     5,     6,     6,     3,     6,     5,     5,
       2,     3,     3,     4,     4,     3,     1,     1,     1,     2,
       4,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     4,     1,     7,    11,     0,     5,     7,     8,
       3,     3,     3,     0,     2,     0,     2,     9,     2,     1,
       1,     3,     3,     3,     3,     3,     2,     2,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const  Parser ::yytname_[] =
  {
  "$end", "error", "$undefined", "NL", "END", "NUMBER", "FLOAT", "TRUE",
  "FALSE", "INT_TYPE", "BOOL_TYPE", "FLOAT_TYPE", "VARIABLE", "STRING",
  "ATTRIBUT", "INLINE_AFFECTATION", "HEXA_VALUE", "COULEUR", "ROTATION",
  "REMPLISSAGE", "OPACITE", "EPAISSEUR", "SI", "ALORS", "SINON",
  "FUNCTION", "REPETE", "FOIS", "WHILE", "EQUAL", "NOTEQUAL", "LESS",
  "LESSEQUAL", "GREATER", "GREATEREQUAL", "STRINGEQUAL", "STRINGNOTEQUAL",
  "TAILLE", "HAUTEUR", "LARGEUR", "RECTANGLE", "CARRE", "TRIANGLE",
  "CERCLE", "ELLIPSE", "LIGNE", "CHEMIN", "TEXTE", "STOP", "DEGRE", "AND",
  "'-'", "'+'", "'*'", "'/'", "NEG", "'&'", "';'", "'{'", "'}'", "':'",
  "'='", "'['", "']'", "'.'", "'%'", "'('", "')'", "$accept", "programme",
  "subProgramme", "instructions", "instruction", "attributsInline",
  "attributsCSS", "attributs", "attributAffectation", "couleurValue",
  "expression", "variable", "boolValue", "declarationVariableSimple",
  "declarationCanva", "declarationFigure", "carre", "rectangle",
  "triangle", "cercle", "ellipse", "ligne", "chemin", "texte",
  "accesFigure", "setAttribut", "setTaille", "modificationFigure",
  "declarationVariable", "numberComparator", "stringComparator",
  "condition", "conditions", "if", "else", "boucleFor", "boucleWhile",
  "affectation", "arguments", "argumentsValues", "fonction",
  "appelFonction", "operation", "vectPos", YY_NULLPTR
  };


  const short
   Parser ::yyrline_[] =
  {
       0,   174,   174,   180,   187,   191,   199,   204,   209,   215,
     222,   228,   234,   238,   244,   250,   256,   262,   268,   274,
     279,   285,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   305,   305,   310,   316,   321,   327,
     333,   338,   344,   347,   350,   354,   358,   362,   366,   370,
     378,   385,   393,   401,   409,   417,   425,   433,   440,   446,
     452,   457,   463,   469,   475,   481,   487,   491,   495,   501,
     507,   513,   518,   519,   520,   521,   522,   523,   526,   527,
     531,   537,   543,   549,   555,   561,   566,   571,   577,   582,
     588,   594,   600,   605,   610,   616,   621,   628,   633,   639,
     643,   646,   649,   652,   655,   658,   661,   666,   669
  };

  // Print the state stack on the debug stream.
  void
   Parser ::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
   Parser ::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

   Parser ::token_number_type
   Parser ::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    65,    56,     2,
      66,    67,    53,    52,     2,    51,    64,    54,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    60,    57,
       2,    61,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    62,     2,    63,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,     2,    59,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    55
    };
    const int user_token_number_max_ = 306;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

} // yy
#line 3418 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"

#line 676 "parser/parser.yy"


void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
