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
      case 72: // programme
      case 73: // subProgramme
        value.move< ArbreSyntaxique > (std::move (that.value));
        break;

      case 80: // couleurValue
        value.move< CouleurPtr > (std::move (that.value));
        break;

      case 114: // operation
        value.move< ExpressionPtr > (std::move (that.value));
        break;

      case 97: // setTaille
        value.move< TailleType > (std::move (that.value));
        break;

      case 83: // boolValue
        value.move< bool > (std::move (that.value));
        break;

      case 6: // FLOAT
        value.move< float > (std::move (that.value));
        break;

      case 5: // NUMBER
        value.move< int > (std::move (that.value));
        break;

      case 100: // numberComparator
        value.move< operators > (std::move (that.value));
        break;

      case 95: // accesFigure
        value.move< std::shared_ptr<AccesFigureNode> > (std::move (that.value));
        break;

      case 109: // affectation
        value.move< std::shared_ptr<AffectationSimpleVariableNode> > (std::move (that.value));
        break;

      case 113: // appelFonction
        value.move< std::shared_ptr<AppelFonctionNode> > (std::move (that.value));
        break;

      case 79: // attributAffectation
      case 96: // setAttribut
        value.move< std::shared_ptr<AttributNode> > (std::move (that.value));
        break;

      case 85: // declarationCanva
        value.move< std::shared_ptr<CanevaNode> > (std::move (that.value));
        break;

      case 87: // carre
        value.move< std::shared_ptr<CarreNode> > (std::move (that.value));
        break;

      case 90: // cercle
        value.move< std::shared_ptr<CercleNode> > (std::move (that.value));
        break;

      case 93: // chemin
        value.move< std::shared_ptr<CheminNode> > (std::move (that.value));
        break;

      case 103: // condition
        value.move< std::shared_ptr<ConditionNode> > (std::move (that.value));
        break;

      case 99: // declarationVariable
        value.move< std::shared_ptr<DeclarationVariable> > (std::move (that.value));
        break;

      case 84: // declarationVariableSimple
        value.move< std::shared_ptr<DeclarationVariableSimple> > (std::move (that.value));
        break;

      case 91: // ellipse
        value.move< std::shared_ptr<EllipseNode> > (std::move (that.value));
        break;

      case 86: // declarationFigure
        value.move< std::shared_ptr<FigureNode> > (std::move (that.value));
        break;

      case 112: // fonction
        value.move< std::shared_ptr<FonctionNode> > (std::move (that.value));
        break;

      case 107: // boucleFor
        value.move< std::shared_ptr<ForLoopNode> > (std::move (that.value));
        break;

      case 105: // if
        value.move< std::shared_ptr<IfNode> > (std::move (that.value));
        break;

      case 92: // ligne
        value.move< std::shared_ptr<LigneNode> > (std::move (that.value));
        break;

      case 98: // modificationFigure
        value.move< std::shared_ptr<ModificationFigureNode> > (std::move (that.value));
        break;

      case 75: // instruction
      case 81: // expression
        value.move< std::shared_ptr<Noeud> > (std::move (that.value));
        break;

      case 88: // rectangle
        value.move< std::shared_ptr<RectangleNode> > (std::move (that.value));
        break;

      case 94: // texte
        value.move< std::shared_ptr<TexteNode> > (std::move (that.value));
        break;

      case 89: // triangle
        value.move< std::shared_ptr<TriangleNode> > (std::move (that.value));
        break;

      case 108: // boucleWhile
        value.move< std::shared_ptr<WhileNode> > (std::move (that.value));
        break;

      case 9: // INT_TYPE
      case 10: // BOOL_TYPE
      case 11: // FLOAT_TYPE
      case 12: // VARIABLE
      case 13: // STRING
      case 14: // POSITIONX
      case 15: // POSITIONY
      case 18: // HEXA_VALUE
      case 19: // COULEUR
      case 20: // ROTATION
      case 21: // REMPLISSAGE
      case 22: // OPACITE
      case 23: // EPAISSEUR
      case 39: // TAILLE
      case 82: // variable
      case 102: // positionValue
        value.move< std::string > (std::move (that.value));
        break;

      case 111: // argumentsValues
        value.move< std::vector<ExpressionPtr> > (std::move (that.value));
        break;

      case 76: // attributsInline
      case 77: // attributsCSS
      case 78: // attributs
        value.move< std::vector<std::shared_ptr<AttributNode>> > (std::move (that.value));
        break;

      case 104: // conditions
        value.move< std::vector<std::shared_ptr<ConditionNode>> > (std::move (that.value));
        break;

      case 74: // instructions
      case 106: // else
        value.move< std::vector<std::shared_ptr<Noeud>> > (std::move (that.value));
        break;

      case 115: // vectPos
        value.move< std::vector<std::shared_ptr<PositionNode>> > (std::move (that.value));
        break;

      case 110: // arguments
        value.move< std::vector<std::string> > (std::move (that.value));
        break;

      case 101: // stringComparator
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
      case 72: // programme
      case 73: // subProgramme
        value.copy< ArbreSyntaxique > (YY_MOVE (that.value));
        break;

      case 80: // couleurValue
        value.copy< CouleurPtr > (YY_MOVE (that.value));
        break;

      case 114: // operation
        value.copy< ExpressionPtr > (YY_MOVE (that.value));
        break;

      case 97: // setTaille
        value.copy< TailleType > (YY_MOVE (that.value));
        break;

      case 83: // boolValue
        value.copy< bool > (YY_MOVE (that.value));
        break;

      case 6: // FLOAT
        value.copy< float > (YY_MOVE (that.value));
        break;

      case 5: // NUMBER
        value.copy< int > (YY_MOVE (that.value));
        break;

      case 100: // numberComparator
        value.copy< operators > (YY_MOVE (that.value));
        break;

      case 95: // accesFigure
        value.copy< std::shared_ptr<AccesFigureNode> > (YY_MOVE (that.value));
        break;

      case 109: // affectation
        value.copy< std::shared_ptr<AffectationSimpleVariableNode> > (YY_MOVE (that.value));
        break;

      case 113: // appelFonction
        value.copy< std::shared_ptr<AppelFonctionNode> > (YY_MOVE (that.value));
        break;

      case 79: // attributAffectation
      case 96: // setAttribut
        value.copy< std::shared_ptr<AttributNode> > (YY_MOVE (that.value));
        break;

      case 85: // declarationCanva
        value.copy< std::shared_ptr<CanevaNode> > (YY_MOVE (that.value));
        break;

      case 87: // carre
        value.copy< std::shared_ptr<CarreNode> > (YY_MOVE (that.value));
        break;

      case 90: // cercle
        value.copy< std::shared_ptr<CercleNode> > (YY_MOVE (that.value));
        break;

      case 93: // chemin
        value.copy< std::shared_ptr<CheminNode> > (YY_MOVE (that.value));
        break;

      case 103: // condition
        value.copy< std::shared_ptr<ConditionNode> > (YY_MOVE (that.value));
        break;

      case 99: // declarationVariable
        value.copy< std::shared_ptr<DeclarationVariable> > (YY_MOVE (that.value));
        break;

      case 84: // declarationVariableSimple
        value.copy< std::shared_ptr<DeclarationVariableSimple> > (YY_MOVE (that.value));
        break;

      case 91: // ellipse
        value.copy< std::shared_ptr<EllipseNode> > (YY_MOVE (that.value));
        break;

      case 86: // declarationFigure
        value.copy< std::shared_ptr<FigureNode> > (YY_MOVE (that.value));
        break;

      case 112: // fonction
        value.copy< std::shared_ptr<FonctionNode> > (YY_MOVE (that.value));
        break;

      case 107: // boucleFor
        value.copy< std::shared_ptr<ForLoopNode> > (YY_MOVE (that.value));
        break;

      case 105: // if
        value.copy< std::shared_ptr<IfNode> > (YY_MOVE (that.value));
        break;

      case 92: // ligne
        value.copy< std::shared_ptr<LigneNode> > (YY_MOVE (that.value));
        break;

      case 98: // modificationFigure
        value.copy< std::shared_ptr<ModificationFigureNode> > (YY_MOVE (that.value));
        break;

      case 75: // instruction
      case 81: // expression
        value.copy< std::shared_ptr<Noeud> > (YY_MOVE (that.value));
        break;

      case 88: // rectangle
        value.copy< std::shared_ptr<RectangleNode> > (YY_MOVE (that.value));
        break;

      case 94: // texte
        value.copy< std::shared_ptr<TexteNode> > (YY_MOVE (that.value));
        break;

      case 89: // triangle
        value.copy< std::shared_ptr<TriangleNode> > (YY_MOVE (that.value));
        break;

      case 108: // boucleWhile
        value.copy< std::shared_ptr<WhileNode> > (YY_MOVE (that.value));
        break;

      case 9: // INT_TYPE
      case 10: // BOOL_TYPE
      case 11: // FLOAT_TYPE
      case 12: // VARIABLE
      case 13: // STRING
      case 14: // POSITIONX
      case 15: // POSITIONY
      case 18: // HEXA_VALUE
      case 19: // COULEUR
      case 20: // ROTATION
      case 21: // REMPLISSAGE
      case 22: // OPACITE
      case 23: // EPAISSEUR
      case 39: // TAILLE
      case 82: // variable
      case 102: // positionValue
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case 111: // argumentsValues
        value.copy< std::vector<ExpressionPtr> > (YY_MOVE (that.value));
        break;

      case 76: // attributsInline
      case 77: // attributsCSS
      case 78: // attributs
        value.copy< std::vector<std::shared_ptr<AttributNode>> > (YY_MOVE (that.value));
        break;

      case 104: // conditions
        value.copy< std::vector<std::shared_ptr<ConditionNode>> > (YY_MOVE (that.value));
        break;

      case 74: // instructions
      case 106: // else
        value.copy< std::vector<std::shared_ptr<Noeud>> > (YY_MOVE (that.value));
        break;

      case 115: // vectPos
        value.copy< std::vector<std::shared_ptr<PositionNode>> > (YY_MOVE (that.value));
        break;

      case 110: // arguments
        value.copy< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      case 101: // stringComparator
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
      case 72: // programme
      case 73: // subProgramme
        value.move< ArbreSyntaxique > (YY_MOVE (s.value));
        break;

      case 80: // couleurValue
        value.move< CouleurPtr > (YY_MOVE (s.value));
        break;

      case 114: // operation
        value.move< ExpressionPtr > (YY_MOVE (s.value));
        break;

      case 97: // setTaille
        value.move< TailleType > (YY_MOVE (s.value));
        break;

      case 83: // boolValue
        value.move< bool > (YY_MOVE (s.value));
        break;

      case 6: // FLOAT
        value.move< float > (YY_MOVE (s.value));
        break;

      case 5: // NUMBER
        value.move< int > (YY_MOVE (s.value));
        break;

      case 100: // numberComparator
        value.move< operators > (YY_MOVE (s.value));
        break;

      case 95: // accesFigure
        value.move< std::shared_ptr<AccesFigureNode> > (YY_MOVE (s.value));
        break;

      case 109: // affectation
        value.move< std::shared_ptr<AffectationSimpleVariableNode> > (YY_MOVE (s.value));
        break;

      case 113: // appelFonction
        value.move< std::shared_ptr<AppelFonctionNode> > (YY_MOVE (s.value));
        break;

      case 79: // attributAffectation
      case 96: // setAttribut
        value.move< std::shared_ptr<AttributNode> > (YY_MOVE (s.value));
        break;

      case 85: // declarationCanva
        value.move< std::shared_ptr<CanevaNode> > (YY_MOVE (s.value));
        break;

      case 87: // carre
        value.move< std::shared_ptr<CarreNode> > (YY_MOVE (s.value));
        break;

      case 90: // cercle
        value.move< std::shared_ptr<CercleNode> > (YY_MOVE (s.value));
        break;

      case 93: // chemin
        value.move< std::shared_ptr<CheminNode> > (YY_MOVE (s.value));
        break;

      case 103: // condition
        value.move< std::shared_ptr<ConditionNode> > (YY_MOVE (s.value));
        break;

      case 99: // declarationVariable
        value.move< std::shared_ptr<DeclarationVariable> > (YY_MOVE (s.value));
        break;

      case 84: // declarationVariableSimple
        value.move< std::shared_ptr<DeclarationVariableSimple> > (YY_MOVE (s.value));
        break;

      case 91: // ellipse
        value.move< std::shared_ptr<EllipseNode> > (YY_MOVE (s.value));
        break;

      case 86: // declarationFigure
        value.move< std::shared_ptr<FigureNode> > (YY_MOVE (s.value));
        break;

      case 112: // fonction
        value.move< std::shared_ptr<FonctionNode> > (YY_MOVE (s.value));
        break;

      case 107: // boucleFor
        value.move< std::shared_ptr<ForLoopNode> > (YY_MOVE (s.value));
        break;

      case 105: // if
        value.move< std::shared_ptr<IfNode> > (YY_MOVE (s.value));
        break;

      case 92: // ligne
        value.move< std::shared_ptr<LigneNode> > (YY_MOVE (s.value));
        break;

      case 98: // modificationFigure
        value.move< std::shared_ptr<ModificationFigureNode> > (YY_MOVE (s.value));
        break;

      case 75: // instruction
      case 81: // expression
        value.move< std::shared_ptr<Noeud> > (YY_MOVE (s.value));
        break;

      case 88: // rectangle
        value.move< std::shared_ptr<RectangleNode> > (YY_MOVE (s.value));
        break;

      case 94: // texte
        value.move< std::shared_ptr<TexteNode> > (YY_MOVE (s.value));
        break;

      case 89: // triangle
        value.move< std::shared_ptr<TriangleNode> > (YY_MOVE (s.value));
        break;

      case 108: // boucleWhile
        value.move< std::shared_ptr<WhileNode> > (YY_MOVE (s.value));
        break;

      case 9: // INT_TYPE
      case 10: // BOOL_TYPE
      case 11: // FLOAT_TYPE
      case 12: // VARIABLE
      case 13: // STRING
      case 14: // POSITIONX
      case 15: // POSITIONY
      case 18: // HEXA_VALUE
      case 19: // COULEUR
      case 20: // ROTATION
      case 21: // REMPLISSAGE
      case 22: // OPACITE
      case 23: // EPAISSEUR
      case 39: // TAILLE
      case 82: // variable
      case 102: // positionValue
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case 111: // argumentsValues
        value.move< std::vector<ExpressionPtr> > (YY_MOVE (s.value));
        break;

      case 76: // attributsInline
      case 77: // attributsCSS
      case 78: // attributs
        value.move< std::vector<std::shared_ptr<AttributNode>> > (YY_MOVE (s.value));
        break;

      case 104: // conditions
        value.move< std::vector<std::shared_ptr<ConditionNode>> > (YY_MOVE (s.value));
        break;

      case 74: // instructions
      case 106: // else
        value.move< std::vector<std::shared_ptr<Noeud>> > (YY_MOVE (s.value));
        break;

      case 115: // vectPos
        value.move< std::vector<std::shared_ptr<PositionNode>> > (YY_MOVE (s.value));
        break;

      case 110: // arguments
        value.move< std::vector<std::string> > (YY_MOVE (s.value));
        break;

      case 101: // stringComparator
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
      case 72: // programme
      case 73: // subProgramme
        value.YY_MOVE_OR_COPY< ArbreSyntaxique > (YY_MOVE (that.value));
        break;

      case 80: // couleurValue
        value.YY_MOVE_OR_COPY< CouleurPtr > (YY_MOVE (that.value));
        break;

      case 114: // operation
        value.YY_MOVE_OR_COPY< ExpressionPtr > (YY_MOVE (that.value));
        break;

      case 97: // setTaille
        value.YY_MOVE_OR_COPY< TailleType > (YY_MOVE (that.value));
        break;

      case 83: // boolValue
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case 6: // FLOAT
        value.YY_MOVE_OR_COPY< float > (YY_MOVE (that.value));
        break;

      case 5: // NUMBER
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 100: // numberComparator
        value.YY_MOVE_OR_COPY< operators > (YY_MOVE (that.value));
        break;

      case 95: // accesFigure
        value.YY_MOVE_OR_COPY< std::shared_ptr<AccesFigureNode> > (YY_MOVE (that.value));
        break;

      case 109: // affectation
        value.YY_MOVE_OR_COPY< std::shared_ptr<AffectationSimpleVariableNode> > (YY_MOVE (that.value));
        break;

      case 113: // appelFonction
        value.YY_MOVE_OR_COPY< std::shared_ptr<AppelFonctionNode> > (YY_MOVE (that.value));
        break;

      case 79: // attributAffectation
      case 96: // setAttribut
        value.YY_MOVE_OR_COPY< std::shared_ptr<AttributNode> > (YY_MOVE (that.value));
        break;

      case 85: // declarationCanva
        value.YY_MOVE_OR_COPY< std::shared_ptr<CanevaNode> > (YY_MOVE (that.value));
        break;

      case 87: // carre
        value.YY_MOVE_OR_COPY< std::shared_ptr<CarreNode> > (YY_MOVE (that.value));
        break;

      case 90: // cercle
        value.YY_MOVE_OR_COPY< std::shared_ptr<CercleNode> > (YY_MOVE (that.value));
        break;

      case 93: // chemin
        value.YY_MOVE_OR_COPY< std::shared_ptr<CheminNode> > (YY_MOVE (that.value));
        break;

      case 103: // condition
        value.YY_MOVE_OR_COPY< std::shared_ptr<ConditionNode> > (YY_MOVE (that.value));
        break;

      case 99: // declarationVariable
        value.YY_MOVE_OR_COPY< std::shared_ptr<DeclarationVariable> > (YY_MOVE (that.value));
        break;

      case 84: // declarationVariableSimple
        value.YY_MOVE_OR_COPY< std::shared_ptr<DeclarationVariableSimple> > (YY_MOVE (that.value));
        break;

      case 91: // ellipse
        value.YY_MOVE_OR_COPY< std::shared_ptr<EllipseNode> > (YY_MOVE (that.value));
        break;

      case 86: // declarationFigure
        value.YY_MOVE_OR_COPY< std::shared_ptr<FigureNode> > (YY_MOVE (that.value));
        break;

      case 112: // fonction
        value.YY_MOVE_OR_COPY< std::shared_ptr<FonctionNode> > (YY_MOVE (that.value));
        break;

      case 107: // boucleFor
        value.YY_MOVE_OR_COPY< std::shared_ptr<ForLoopNode> > (YY_MOVE (that.value));
        break;

      case 105: // if
        value.YY_MOVE_OR_COPY< std::shared_ptr<IfNode> > (YY_MOVE (that.value));
        break;

      case 92: // ligne
        value.YY_MOVE_OR_COPY< std::shared_ptr<LigneNode> > (YY_MOVE (that.value));
        break;

      case 98: // modificationFigure
        value.YY_MOVE_OR_COPY< std::shared_ptr<ModificationFigureNode> > (YY_MOVE (that.value));
        break;

      case 75: // instruction
      case 81: // expression
        value.YY_MOVE_OR_COPY< std::shared_ptr<Noeud> > (YY_MOVE (that.value));
        break;

      case 88: // rectangle
        value.YY_MOVE_OR_COPY< std::shared_ptr<RectangleNode> > (YY_MOVE (that.value));
        break;

      case 94: // texte
        value.YY_MOVE_OR_COPY< std::shared_ptr<TexteNode> > (YY_MOVE (that.value));
        break;

      case 89: // triangle
        value.YY_MOVE_OR_COPY< std::shared_ptr<TriangleNode> > (YY_MOVE (that.value));
        break;

      case 108: // boucleWhile
        value.YY_MOVE_OR_COPY< std::shared_ptr<WhileNode> > (YY_MOVE (that.value));
        break;

      case 9: // INT_TYPE
      case 10: // BOOL_TYPE
      case 11: // FLOAT_TYPE
      case 12: // VARIABLE
      case 13: // STRING
      case 14: // POSITIONX
      case 15: // POSITIONY
      case 18: // HEXA_VALUE
      case 19: // COULEUR
      case 20: // ROTATION
      case 21: // REMPLISSAGE
      case 22: // OPACITE
      case 23: // EPAISSEUR
      case 39: // TAILLE
      case 82: // variable
      case 102: // positionValue
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case 111: // argumentsValues
        value.YY_MOVE_OR_COPY< std::vector<ExpressionPtr> > (YY_MOVE (that.value));
        break;

      case 76: // attributsInline
      case 77: // attributsCSS
      case 78: // attributs
        value.YY_MOVE_OR_COPY< std::vector<std::shared_ptr<AttributNode>> > (YY_MOVE (that.value));
        break;

      case 104: // conditions
        value.YY_MOVE_OR_COPY< std::vector<std::shared_ptr<ConditionNode>> > (YY_MOVE (that.value));
        break;

      case 74: // instructions
      case 106: // else
        value.YY_MOVE_OR_COPY< std::vector<std::shared_ptr<Noeud>> > (YY_MOVE (that.value));
        break;

      case 115: // vectPos
        value.YY_MOVE_OR_COPY< std::vector<std::shared_ptr<PositionNode>> > (YY_MOVE (that.value));
        break;

      case 110: // arguments
        value.YY_MOVE_OR_COPY< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      case 101: // stringComparator
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
      case 72: // programme
      case 73: // subProgramme
        value.move< ArbreSyntaxique > (YY_MOVE (that.value));
        break;

      case 80: // couleurValue
        value.move< CouleurPtr > (YY_MOVE (that.value));
        break;

      case 114: // operation
        value.move< ExpressionPtr > (YY_MOVE (that.value));
        break;

      case 97: // setTaille
        value.move< TailleType > (YY_MOVE (that.value));
        break;

      case 83: // boolValue
        value.move< bool > (YY_MOVE (that.value));
        break;

      case 6: // FLOAT
        value.move< float > (YY_MOVE (that.value));
        break;

      case 5: // NUMBER
        value.move< int > (YY_MOVE (that.value));
        break;

      case 100: // numberComparator
        value.move< operators > (YY_MOVE (that.value));
        break;

      case 95: // accesFigure
        value.move< std::shared_ptr<AccesFigureNode> > (YY_MOVE (that.value));
        break;

      case 109: // affectation
        value.move< std::shared_ptr<AffectationSimpleVariableNode> > (YY_MOVE (that.value));
        break;

      case 113: // appelFonction
        value.move< std::shared_ptr<AppelFonctionNode> > (YY_MOVE (that.value));
        break;

      case 79: // attributAffectation
      case 96: // setAttribut
        value.move< std::shared_ptr<AttributNode> > (YY_MOVE (that.value));
        break;

      case 85: // declarationCanva
        value.move< std::shared_ptr<CanevaNode> > (YY_MOVE (that.value));
        break;

      case 87: // carre
        value.move< std::shared_ptr<CarreNode> > (YY_MOVE (that.value));
        break;

      case 90: // cercle
        value.move< std::shared_ptr<CercleNode> > (YY_MOVE (that.value));
        break;

      case 93: // chemin
        value.move< std::shared_ptr<CheminNode> > (YY_MOVE (that.value));
        break;

      case 103: // condition
        value.move< std::shared_ptr<ConditionNode> > (YY_MOVE (that.value));
        break;

      case 99: // declarationVariable
        value.move< std::shared_ptr<DeclarationVariable> > (YY_MOVE (that.value));
        break;

      case 84: // declarationVariableSimple
        value.move< std::shared_ptr<DeclarationVariableSimple> > (YY_MOVE (that.value));
        break;

      case 91: // ellipse
        value.move< std::shared_ptr<EllipseNode> > (YY_MOVE (that.value));
        break;

      case 86: // declarationFigure
        value.move< std::shared_ptr<FigureNode> > (YY_MOVE (that.value));
        break;

      case 112: // fonction
        value.move< std::shared_ptr<FonctionNode> > (YY_MOVE (that.value));
        break;

      case 107: // boucleFor
        value.move< std::shared_ptr<ForLoopNode> > (YY_MOVE (that.value));
        break;

      case 105: // if
        value.move< std::shared_ptr<IfNode> > (YY_MOVE (that.value));
        break;

      case 92: // ligne
        value.move< std::shared_ptr<LigneNode> > (YY_MOVE (that.value));
        break;

      case 98: // modificationFigure
        value.move< std::shared_ptr<ModificationFigureNode> > (YY_MOVE (that.value));
        break;

      case 75: // instruction
      case 81: // expression
        value.move< std::shared_ptr<Noeud> > (YY_MOVE (that.value));
        break;

      case 88: // rectangle
        value.move< std::shared_ptr<RectangleNode> > (YY_MOVE (that.value));
        break;

      case 94: // texte
        value.move< std::shared_ptr<TexteNode> > (YY_MOVE (that.value));
        break;

      case 89: // triangle
        value.move< std::shared_ptr<TriangleNode> > (YY_MOVE (that.value));
        break;

      case 108: // boucleWhile
        value.move< std::shared_ptr<WhileNode> > (YY_MOVE (that.value));
        break;

      case 9: // INT_TYPE
      case 10: // BOOL_TYPE
      case 11: // FLOAT_TYPE
      case 12: // VARIABLE
      case 13: // STRING
      case 14: // POSITIONX
      case 15: // POSITIONY
      case 18: // HEXA_VALUE
      case 19: // COULEUR
      case 20: // ROTATION
      case 21: // REMPLISSAGE
      case 22: // OPACITE
      case 23: // EPAISSEUR
      case 39: // TAILLE
      case 82: // variable
      case 102: // positionValue
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case 111: // argumentsValues
        value.move< std::vector<ExpressionPtr> > (YY_MOVE (that.value));
        break;

      case 76: // attributsInline
      case 77: // attributsCSS
      case 78: // attributs
        value.move< std::vector<std::shared_ptr<AttributNode>> > (YY_MOVE (that.value));
        break;

      case 104: // conditions
        value.move< std::vector<std::shared_ptr<ConditionNode>> > (YY_MOVE (that.value));
        break;

      case 74: // instructions
      case 106: // else
        value.move< std::vector<std::shared_ptr<Noeud>> > (YY_MOVE (that.value));
        break;

      case 115: // vectPos
        value.move< std::vector<std::shared_ptr<PositionNode>> > (YY_MOVE (that.value));
        break;

      case 110: // arguments
        value.move< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      case 101: // stringComparator
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
      case 72: // programme
      case 73: // subProgramme
        value.copy< ArbreSyntaxique > (that.value);
        break;

      case 80: // couleurValue
        value.copy< CouleurPtr > (that.value);
        break;

      case 114: // operation
        value.copy< ExpressionPtr > (that.value);
        break;

      case 97: // setTaille
        value.copy< TailleType > (that.value);
        break;

      case 83: // boolValue
        value.copy< bool > (that.value);
        break;

      case 6: // FLOAT
        value.copy< float > (that.value);
        break;

      case 5: // NUMBER
        value.copy< int > (that.value);
        break;

      case 100: // numberComparator
        value.copy< operators > (that.value);
        break;

      case 95: // accesFigure
        value.copy< std::shared_ptr<AccesFigureNode> > (that.value);
        break;

      case 109: // affectation
        value.copy< std::shared_ptr<AffectationSimpleVariableNode> > (that.value);
        break;

      case 113: // appelFonction
        value.copy< std::shared_ptr<AppelFonctionNode> > (that.value);
        break;

      case 79: // attributAffectation
      case 96: // setAttribut
        value.copy< std::shared_ptr<AttributNode> > (that.value);
        break;

      case 85: // declarationCanva
        value.copy< std::shared_ptr<CanevaNode> > (that.value);
        break;

      case 87: // carre
        value.copy< std::shared_ptr<CarreNode> > (that.value);
        break;

      case 90: // cercle
        value.copy< std::shared_ptr<CercleNode> > (that.value);
        break;

      case 93: // chemin
        value.copy< std::shared_ptr<CheminNode> > (that.value);
        break;

      case 103: // condition
        value.copy< std::shared_ptr<ConditionNode> > (that.value);
        break;

      case 99: // declarationVariable
        value.copy< std::shared_ptr<DeclarationVariable> > (that.value);
        break;

      case 84: // declarationVariableSimple
        value.copy< std::shared_ptr<DeclarationVariableSimple> > (that.value);
        break;

      case 91: // ellipse
        value.copy< std::shared_ptr<EllipseNode> > (that.value);
        break;

      case 86: // declarationFigure
        value.copy< std::shared_ptr<FigureNode> > (that.value);
        break;

      case 112: // fonction
        value.copy< std::shared_ptr<FonctionNode> > (that.value);
        break;

      case 107: // boucleFor
        value.copy< std::shared_ptr<ForLoopNode> > (that.value);
        break;

      case 105: // if
        value.copy< std::shared_ptr<IfNode> > (that.value);
        break;

      case 92: // ligne
        value.copy< std::shared_ptr<LigneNode> > (that.value);
        break;

      case 98: // modificationFigure
        value.copy< std::shared_ptr<ModificationFigureNode> > (that.value);
        break;

      case 75: // instruction
      case 81: // expression
        value.copy< std::shared_ptr<Noeud> > (that.value);
        break;

      case 88: // rectangle
        value.copy< std::shared_ptr<RectangleNode> > (that.value);
        break;

      case 94: // texte
        value.copy< std::shared_ptr<TexteNode> > (that.value);
        break;

      case 89: // triangle
        value.copy< std::shared_ptr<TriangleNode> > (that.value);
        break;

      case 108: // boucleWhile
        value.copy< std::shared_ptr<WhileNode> > (that.value);
        break;

      case 9: // INT_TYPE
      case 10: // BOOL_TYPE
      case 11: // FLOAT_TYPE
      case 12: // VARIABLE
      case 13: // STRING
      case 14: // POSITIONX
      case 15: // POSITIONY
      case 18: // HEXA_VALUE
      case 19: // COULEUR
      case 20: // ROTATION
      case 21: // REMPLISSAGE
      case 22: // OPACITE
      case 23: // EPAISSEUR
      case 39: // TAILLE
      case 82: // variable
      case 102: // positionValue
        value.copy< std::string > (that.value);
        break;

      case 111: // argumentsValues
        value.copy< std::vector<ExpressionPtr> > (that.value);
        break;

      case 76: // attributsInline
      case 77: // attributsCSS
      case 78: // attributs
        value.copy< std::vector<std::shared_ptr<AttributNode>> > (that.value);
        break;

      case 104: // conditions
        value.copy< std::vector<std::shared_ptr<ConditionNode>> > (that.value);
        break;

      case 74: // instructions
      case 106: // else
        value.copy< std::vector<std::shared_ptr<Noeud>> > (that.value);
        break;

      case 115: // vectPos
        value.copy< std::vector<std::shared_ptr<PositionNode>> > (that.value);
        break;

      case 110: // arguments
        value.copy< std::vector<std::string> > (that.value);
        break;

      case 101: // stringComparator
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
      case 72: // programme
      case 73: // subProgramme
        value.move< ArbreSyntaxique > (that.value);
        break;

      case 80: // couleurValue
        value.move< CouleurPtr > (that.value);
        break;

      case 114: // operation
        value.move< ExpressionPtr > (that.value);
        break;

      case 97: // setTaille
        value.move< TailleType > (that.value);
        break;

      case 83: // boolValue
        value.move< bool > (that.value);
        break;

      case 6: // FLOAT
        value.move< float > (that.value);
        break;

      case 5: // NUMBER
        value.move< int > (that.value);
        break;

      case 100: // numberComparator
        value.move< operators > (that.value);
        break;

      case 95: // accesFigure
        value.move< std::shared_ptr<AccesFigureNode> > (that.value);
        break;

      case 109: // affectation
        value.move< std::shared_ptr<AffectationSimpleVariableNode> > (that.value);
        break;

      case 113: // appelFonction
        value.move< std::shared_ptr<AppelFonctionNode> > (that.value);
        break;

      case 79: // attributAffectation
      case 96: // setAttribut
        value.move< std::shared_ptr<AttributNode> > (that.value);
        break;

      case 85: // declarationCanva
        value.move< std::shared_ptr<CanevaNode> > (that.value);
        break;

      case 87: // carre
        value.move< std::shared_ptr<CarreNode> > (that.value);
        break;

      case 90: // cercle
        value.move< std::shared_ptr<CercleNode> > (that.value);
        break;

      case 93: // chemin
        value.move< std::shared_ptr<CheminNode> > (that.value);
        break;

      case 103: // condition
        value.move< std::shared_ptr<ConditionNode> > (that.value);
        break;

      case 99: // declarationVariable
        value.move< std::shared_ptr<DeclarationVariable> > (that.value);
        break;

      case 84: // declarationVariableSimple
        value.move< std::shared_ptr<DeclarationVariableSimple> > (that.value);
        break;

      case 91: // ellipse
        value.move< std::shared_ptr<EllipseNode> > (that.value);
        break;

      case 86: // declarationFigure
        value.move< std::shared_ptr<FigureNode> > (that.value);
        break;

      case 112: // fonction
        value.move< std::shared_ptr<FonctionNode> > (that.value);
        break;

      case 107: // boucleFor
        value.move< std::shared_ptr<ForLoopNode> > (that.value);
        break;

      case 105: // if
        value.move< std::shared_ptr<IfNode> > (that.value);
        break;

      case 92: // ligne
        value.move< std::shared_ptr<LigneNode> > (that.value);
        break;

      case 98: // modificationFigure
        value.move< std::shared_ptr<ModificationFigureNode> > (that.value);
        break;

      case 75: // instruction
      case 81: // expression
        value.move< std::shared_ptr<Noeud> > (that.value);
        break;

      case 88: // rectangle
        value.move< std::shared_ptr<RectangleNode> > (that.value);
        break;

      case 94: // texte
        value.move< std::shared_ptr<TexteNode> > (that.value);
        break;

      case 89: // triangle
        value.move< std::shared_ptr<TriangleNode> > (that.value);
        break;

      case 108: // boucleWhile
        value.move< std::shared_ptr<WhileNode> > (that.value);
        break;

      case 9: // INT_TYPE
      case 10: // BOOL_TYPE
      case 11: // FLOAT_TYPE
      case 12: // VARIABLE
      case 13: // STRING
      case 14: // POSITIONX
      case 15: // POSITIONY
      case 18: // HEXA_VALUE
      case 19: // COULEUR
      case 20: // ROTATION
      case 21: // REMPLISSAGE
      case 22: // OPACITE
      case 23: // EPAISSEUR
      case 39: // TAILLE
      case 82: // variable
      case 102: // positionValue
        value.move< std::string > (that.value);
        break;

      case 111: // argumentsValues
        value.move< std::vector<ExpressionPtr> > (that.value);
        break;

      case 76: // attributsInline
      case 77: // attributsCSS
      case 78: // attributs
        value.move< std::vector<std::shared_ptr<AttributNode>> > (that.value);
        break;

      case 104: // conditions
        value.move< std::vector<std::shared_ptr<ConditionNode>> > (that.value);
        break;

      case 74: // instructions
      case 106: // else
        value.move< std::vector<std::shared_ptr<Noeud>> > (that.value);
        break;

      case 115: // vectPos
        value.move< std::vector<std::shared_ptr<PositionNode>> > (that.value);
        break;

      case 110: // arguments
        value.move< std::vector<std::string> > (that.value);
        break;

      case 101: // stringComparator
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
      case 72: // programme
      case 73: // subProgramme
        yylhs.value.emplace< ArbreSyntaxique > ();
        break;

      case 80: // couleurValue
        yylhs.value.emplace< CouleurPtr > ();
        break;

      case 114: // operation
        yylhs.value.emplace< ExpressionPtr > ();
        break;

      case 97: // setTaille
        yylhs.value.emplace< TailleType > ();
        break;

      case 83: // boolValue
        yylhs.value.emplace< bool > ();
        break;

      case 6: // FLOAT
        yylhs.value.emplace< float > ();
        break;

      case 5: // NUMBER
        yylhs.value.emplace< int > ();
        break;

      case 100: // numberComparator
        yylhs.value.emplace< operators > ();
        break;

      case 95: // accesFigure
        yylhs.value.emplace< std::shared_ptr<AccesFigureNode> > ();
        break;

      case 109: // affectation
        yylhs.value.emplace< std::shared_ptr<AffectationSimpleVariableNode> > ();
        break;

      case 113: // appelFonction
        yylhs.value.emplace< std::shared_ptr<AppelFonctionNode> > ();
        break;

      case 79: // attributAffectation
      case 96: // setAttribut
        yylhs.value.emplace< std::shared_ptr<AttributNode> > ();
        break;

      case 85: // declarationCanva
        yylhs.value.emplace< std::shared_ptr<CanevaNode> > ();
        break;

      case 87: // carre
        yylhs.value.emplace< std::shared_ptr<CarreNode> > ();
        break;

      case 90: // cercle
        yylhs.value.emplace< std::shared_ptr<CercleNode> > ();
        break;

      case 93: // chemin
        yylhs.value.emplace< std::shared_ptr<CheminNode> > ();
        break;

      case 103: // condition
        yylhs.value.emplace< std::shared_ptr<ConditionNode> > ();
        break;

      case 99: // declarationVariable
        yylhs.value.emplace< std::shared_ptr<DeclarationVariable> > ();
        break;

      case 84: // declarationVariableSimple
        yylhs.value.emplace< std::shared_ptr<DeclarationVariableSimple> > ();
        break;

      case 91: // ellipse
        yylhs.value.emplace< std::shared_ptr<EllipseNode> > ();
        break;

      case 86: // declarationFigure
        yylhs.value.emplace< std::shared_ptr<FigureNode> > ();
        break;

      case 112: // fonction
        yylhs.value.emplace< std::shared_ptr<FonctionNode> > ();
        break;

      case 107: // boucleFor
        yylhs.value.emplace< std::shared_ptr<ForLoopNode> > ();
        break;

      case 105: // if
        yylhs.value.emplace< std::shared_ptr<IfNode> > ();
        break;

      case 92: // ligne
        yylhs.value.emplace< std::shared_ptr<LigneNode> > ();
        break;

      case 98: // modificationFigure
        yylhs.value.emplace< std::shared_ptr<ModificationFigureNode> > ();
        break;

      case 75: // instruction
      case 81: // expression
        yylhs.value.emplace< std::shared_ptr<Noeud> > ();
        break;

      case 88: // rectangle
        yylhs.value.emplace< std::shared_ptr<RectangleNode> > ();
        break;

      case 94: // texte
        yylhs.value.emplace< std::shared_ptr<TexteNode> > ();
        break;

      case 89: // triangle
        yylhs.value.emplace< std::shared_ptr<TriangleNode> > ();
        break;

      case 108: // boucleWhile
        yylhs.value.emplace< std::shared_ptr<WhileNode> > ();
        break;

      case 9: // INT_TYPE
      case 10: // BOOL_TYPE
      case 11: // FLOAT_TYPE
      case 12: // VARIABLE
      case 13: // STRING
      case 14: // POSITIONX
      case 15: // POSITIONY
      case 18: // HEXA_VALUE
      case 19: // COULEUR
      case 20: // ROTATION
      case 21: // REMPLISSAGE
      case 22: // OPACITE
      case 23: // EPAISSEUR
      case 39: // TAILLE
      case 82: // variable
      case 102: // positionValue
        yylhs.value.emplace< std::string > ();
        break;

      case 111: // argumentsValues
        yylhs.value.emplace< std::vector<ExpressionPtr> > ();
        break;

      case 76: // attributsInline
      case 77: // attributsCSS
      case 78: // attributs
        yylhs.value.emplace< std::vector<std::shared_ptr<AttributNode>> > ();
        break;

      case 104: // conditions
        yylhs.value.emplace< std::vector<std::shared_ptr<ConditionNode>> > ();
        break;

      case 74: // instructions
      case 106: // else
        yylhs.value.emplace< std::vector<std::shared_ptr<Noeud>> > ();
        break;

      case 115: // vectPos
        yylhs.value.emplace< std::vector<std::shared_ptr<PositionNode>> > ();
        break;

      case 110: // arguments
        yylhs.value.emplace< std::vector<std::string> > ();
        break;

      case 101: // stringComparator
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
#line 178 "parser/parser.yy"
                 {
        driver.analyseCode(yystack_[0].value.as < ArbreSyntaxique > ());
        YYACCEPT;
    }
#line 2047 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 3:
#line 185 "parser/parser.yy"
                                {
        yystack_[0].value.as < ArbreSyntaxique > ().addNode(yystack_[2].value.as < std::shared_ptr<Noeud> > ());
        yylhs.value.as < ArbreSyntaxique > () = yystack_[0].value.as < ArbreSyntaxique > ();
    }
#line 2056 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 4:
#line 192 "parser/parser.yy"
       {
    }
#line 2063 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 5:
#line 196 "parser/parser.yy"
                                {
        yystack_[0].value.as < std::vector<std::shared_ptr<Noeud>> > ().push_back(yystack_[2].value.as < std::shared_ptr<Noeud> > ());
        yylhs.value.as < std::vector<std::shared_ptr<Noeud>> > () = yystack_[0].value.as < std::vector<std::shared_ptr<Noeud>> > ();
    }
#line 2072 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 6:
#line 204 "parser/parser.yy"
    {

    }
#line 2080 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 7:
#line 209 "parser/parser.yy"
                {
        yylhs.value.as < std::shared_ptr<Noeud> > () = yystack_[0].value.as < std::shared_ptr<Noeud> > ();
    }
#line 2088 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 8:
#line 214 "parser/parser.yy"
                        {
        yylhs.value.as < std::vector<std::shared_ptr<AttributNode>> > ().push_back(yystack_[0].value.as < std::shared_ptr<AttributNode> > ());
    }
#line 2096 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 9:
#line 220 "parser/parser.yy"
                                            {
        yystack_[2].value.as < std::vector<std::shared_ptr<AttributNode>> > ().push_back(yystack_[0].value.as < std::shared_ptr<AttributNode> > ());
        yylhs.value.as < std::vector<std::shared_ptr<AttributNode>> > () = yystack_[2].value.as < std::vector<std::shared_ptr<AttributNode>> > ();
    }
#line 2105 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 10:
#line 227 "parser/parser.yy"
                            {
        yylhs.value.as < std::vector<std::shared_ptr<AttributNode>> > ().push_back(yystack_[1].value.as < std::shared_ptr<AttributNode> > ());
    }
#line 2113 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 11:
#line 233 "parser/parser.yy"
                                            {
        yystack_[3].value.as < std::vector<std::shared_ptr<AttributNode>> > ().push_back(yystack_[1].value.as < std::shared_ptr<AttributNode> > ());
        yylhs.value.as < std::vector<std::shared_ptr<AttributNode>> > () = yystack_[3].value.as < std::vector<std::shared_ptr<AttributNode>> > ();
    }
#line 2122 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 12:
#line 239 "parser/parser.yy"
       {}
#line 2128 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 13:
#line 243 "parser/parser.yy"
                               {
        yylhs.value.as < std::vector<std::shared_ptr<AttributNode>> > () = yystack_[2].value.as < std::vector<std::shared_ptr<AttributNode>> > ();
    }
#line 2136 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 14:
#line 249 "parser/parser.yy"
                                           {
        yylhs.value.as < std::vector<std::shared_ptr<AttributNode>> > () = yystack_[1].value.as < std::vector<std::shared_ptr<AttributNode>> > ();
    }
#line 2144 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 15:
#line 255 "parser/parser.yy"
                             {
        yylhs.value.as < std::shared_ptr<AttributNode> > () = std::make_shared<ColorNode>(yystack_[0].value.as < CouleurPtr > ());
    }
#line 2152 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 16:
#line 261 "parser/parser.yy"
                                  {
        yylhs.value.as < std::shared_ptr<AttributNode> > () = std::make_shared<RemplissageNode>(yystack_[0].value.as < CouleurPtr > ());
    }
#line 2160 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 17:
#line 267 "parser/parser.yy"
                                {
        yylhs.value.as < std::shared_ptr<AttributNode> > () = std::make_shared<RotationNode>(yystack_[1].value.as < ExpressionPtr > ());
    }
#line 2168 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 18:
#line 273 "parser/parser.yy"
                              {
        yylhs.value.as < std::shared_ptr<AttributNode> > () = std::make_shared<OpaciteNode>(yystack_[1].value.as < ExpressionPtr > ());
    }
#line 2176 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 19:
#line 279 "parser/parser.yy"
                            {
        yylhs.value.as < std::shared_ptr<AttributNode> > () = std::make_shared<EpaisseurNode>(yystack_[0].value.as < ExpressionPtr > ());
    }
#line 2184 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 20:
#line 285 "parser/parser.yy"
                             {
        yylhs.value.as < std::shared_ptr<AttributNode> > () = std::make_shared<PositionXNode>(yystack_[2].value.as < std::string > (),yystack_[0].value.as < ExpressionPtr > ());
    }
#line 2192 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 21:
#line 291 "parser/parser.yy"
                             {
        yylhs.value.as < std::shared_ptr<AttributNode> > () = std::make_shared<PositionYNode>(yystack_[2].value.as < std::string > (),yystack_[0].value.as < ExpressionPtr > ());
    }
#line 2200 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 22:
#line 296 "parser/parser.yy"
               {
        yylhs.value.as < CouleurPtr > () = std::make_shared<CouleurConstante>(yystack_[0].value.as < std::string > ());
    }
#line 2208 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 23:
#line 302 "parser/parser.yy"
             {
        yylhs.value.as < CouleurPtr > () = std::make_shared<CouleurVariable>(yystack_[0].value.as < std::string > ());
    }
#line 2216 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 24:
#line 308 "parser/parser.yy"
                         { yylhs.value.as < std::shared_ptr<Noeud> > () = yystack_[1].value.as < std::shared_ptr<CanevaNode> > (); }
#line 2222 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 25:
#line 309 "parser/parser.yy"
                      { yylhs.value.as < std::shared_ptr<Noeud> > () = yystack_[0].value.as < std::shared_ptr<FigureNode> > (); }
#line 2228 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 26:
#line 310 "parser/parser.yy"
                           { yylhs.value.as < std::shared_ptr<Noeud> > () = yystack_[1].value.as < std::shared_ptr<ModificationFigureNode> > (); }
#line 2234 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 27:
#line 311 "parser/parser.yy"
                                  { yylhs.value.as < std::shared_ptr<Noeud> > () = yystack_[1].value.as < std::shared_ptr<DeclarationVariableSimple> > (); }
#line 2240 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 28:
#line 312 "parser/parser.yy"
                        { yylhs.value.as < std::shared_ptr<Noeud> > () = yystack_[0].value.as < std::shared_ptr<DeclarationVariable> > (); }
#line 2246 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 29:
#line 313 "parser/parser.yy"
       { yylhs.value.as < std::shared_ptr<Noeud> > () = yystack_[0].value.as < std::shared_ptr<IfNode> > (); }
#line 2252 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 30:
#line 314 "parser/parser.yy"
                { yylhs.value.as < std::shared_ptr<Noeud> > () = yystack_[0].value.as < std::shared_ptr<AccesFigureNode> > (); }
#line 2258 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 31:
#line 315 "parser/parser.yy"
              { yylhs.value.as < std::shared_ptr<Noeud> > () = yystack_[0].value.as < std::shared_ptr<ForLoopNode> > (); }
#line 2264 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 32:
#line 316 "parser/parser.yy"
                { yylhs.value.as < std::shared_ptr<Noeud> > () = yystack_[0].value.as < std::shared_ptr<WhileNode> > (); }
#line 2270 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 33:
#line 317 "parser/parser.yy"
                    { yylhs.value.as < std::shared_ptr<Noeud> > () = yystack_[1].value.as < std::shared_ptr<AffectationSimpleVariableNode> > (); }
#line 2276 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 34:
#line 318 "parser/parser.yy"
             { yylhs.value.as < std::shared_ptr<Noeud> > () = yystack_[0].value.as < std::shared_ptr<FonctionNode> > (); }
#line 2282 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 35:
#line 319 "parser/parser.yy"
                      { yylhs.value.as < std::shared_ptr<Noeud> > () = yystack_[1].value.as < std::shared_ptr<AppelFonctionNode> > (); }
#line 2288 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 36:
#line 322 "parser/parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2294 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 37:
#line 322 "parser/parser.yy"
                      {
        yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
    }
#line 2302 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 38:
#line 327 "parser/parser.yy"
         {
        yylhs.value.as < bool > () = true;
    }
#line 2310 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 39:
#line 333 "parser/parser.yy"
          {
        yylhs.value.as < bool > () = false;
    }
#line 2318 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 40:
#line 338 "parser/parser.yy"
                                    {
        yylhs.value.as < std::shared_ptr<DeclarationVariableSimple> > () = std::make_shared<DeclarationVariableInt>(yystack_[2].value.as < std::string > (), yystack_[0].value.as < ExpressionPtr > ());
    }
#line 2326 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 41:
#line 344 "parser/parser.yy"
                                      {
        yylhs.value.as < std::shared_ptr<DeclarationVariableSimple> > () = std::make_shared<DeclarationVariableInt>(yystack_[2].value.as < std::string > (), yystack_[0].value.as < ExpressionPtr > ());
    }
#line 2334 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 42:
#line 350 "parser/parser.yy"
                                     {
        yylhs.value.as < std::shared_ptr<DeclarationVariableSimple> > () = std::make_shared<DeclarationVariableBool>(yystack_[2].value.as < std::string > (), yystack_[0].value.as < bool > ());
    }
#line 2342 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 43:
#line 356 "parser/parser.yy"
                                    {
        yylhs.value.as < std::shared_ptr<DeclarationVariableSimple> > () = std::make_shared<DeclarationVariableString>(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ());
    }
#line 2350 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 44:
#line 361 "parser/parser.yy"
                               {
        yylhs.value.as < std::shared_ptr<CanevaNode> > () = std::make_shared<CanevaNode>(yystack_[1].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > ());
    }
#line 2358 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 45:
#line 367 "parser/parser.yy"
       {
 yylhs.value.as < std::shared_ptr<FigureNode> > () = yystack_[0].value.as < std::shared_ptr<CarreNode> > ();
 }
#line 2366 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 46:
#line 371 "parser/parser.yy"
           {
 yylhs.value.as < std::shared_ptr<FigureNode> > () = yystack_[0].value.as < std::shared_ptr<RectangleNode> > ();
 }
#line 2374 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 47:
#line 375 "parser/parser.yy"
          {
 yylhs.value.as < std::shared_ptr<FigureNode> > () = yystack_[0].value.as < std::shared_ptr<TriangleNode> > ();
 }
#line 2382 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 48:
#line 380 "parser/parser.yy"
        {
 yylhs.value.as < std::shared_ptr<FigureNode> > () = yystack_[0].value.as < std::shared_ptr<CercleNode> > ();
 }
#line 2390 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 49:
#line 385 "parser/parser.yy"
         {
 yylhs.value.as < std::shared_ptr<FigureNode> > () = yystack_[0].value.as < std::shared_ptr<EllipseNode> > ();
 }
#line 2398 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 50:
#line 390 "parser/parser.yy"
        {
 yylhs.value.as < std::shared_ptr<FigureNode> > () = yystack_[0].value.as < std::shared_ptr<CheminNode> > ();
 }
#line 2406 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 51:
#line 395 "parser/parser.yy"
       {
 yylhs.value.as < std::shared_ptr<FigureNode> > () = yystack_[0].value.as < std::shared_ptr<LigneNode> > ();
 }
#line 2414 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 52:
#line 400 "parser/parser.yy"
       {
 yylhs.value.as < std::shared_ptr<FigureNode> > () = yystack_[0].value.as < std::shared_ptr<TexteNode> > ();
 }
#line 2422 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 53:
#line 408 "parser/parser.yy"
                                               {
    std::shared_ptr<CarreNode> carre = std::make_shared<CarreNode>(yystack_[3].value.as < ExpressionPtr > (), yystack_[2].value.as < ExpressionPtr > (), yystack_[1].value.as < ExpressionPtr > ());
    carre->setAttributs(yystack_[0].value.as < std::vector<std::shared_ptr<AttributNode>> > ());
    yylhs.value.as < std::shared_ptr<CarreNode> > () = carre;
 }
#line 2432 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 54:
#line 415 "parser/parser.yy"
                                                                                                     {
    std::shared_ptr<RectangleNode> rectangle = std::make_shared<RectangleNode>(yystack_[8].value.as < ExpressionPtr > (), yystack_[7].value.as < ExpressionPtr > (), yystack_[6].value.as < ExpressionPtr > (),yystack_[5].value.as < ExpressionPtr > (),yystack_[4].value.as < ExpressionPtr > (),yystack_[3].value.as < ExpressionPtr > (),yystack_[2].value.as < ExpressionPtr > (),yystack_[1].value.as < ExpressionPtr > ());
    rectangle->setAttributs(yystack_[0].value.as < std::vector<std::shared_ptr<AttributNode>> > ());
    yylhs.value.as < std::shared_ptr<RectangleNode> > () = rectangle;
 }
#line 2442 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 55:
#line 423 "parser/parser.yy"
                                                            {
    std::shared_ptr<TriangleNode> triangle = std::make_shared<TriangleNode>(yystack_[4].value.as < ExpressionPtr > (), yystack_[3].value.as < ExpressionPtr > (), yystack_[2].value.as < ExpressionPtr > (),yystack_[1].value.as < ExpressionPtr > ());
    triangle->setAttributs(yystack_[0].value.as < std::vector<std::shared_ptr<AttributNode>> > ());
    yylhs.value.as < std::shared_ptr<TriangleNode> > () = triangle;
 }
#line 2452 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 56:
#line 431 "parser/parser.yy"
                                                {
    std::shared_ptr<CercleNode> cercle = std::make_shared<CercleNode>(yystack_[3].value.as < ExpressionPtr > (), yystack_[2].value.as < ExpressionPtr > (), yystack_[1].value.as < ExpressionPtr > ());
    cercle->setAttributs(yystack_[0].value.as < std::vector<std::shared_ptr<AttributNode>> > ());
    yylhs.value.as < std::shared_ptr<CercleNode> > () = cercle;
 }
#line 2462 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 57:
#line 439 "parser/parser.yy"
                                                          {
    std::shared_ptr<EllipseNode> ellipse = std::make_shared<EllipseNode>(yystack_[4].value.as < ExpressionPtr > (), yystack_[3].value.as < ExpressionPtr > (), yystack_[2].value.as < ExpressionPtr > (),yystack_[1].value.as < ExpressionPtr > ());
    ellipse->setAttributs(yystack_[0].value.as < std::vector<std::shared_ptr<AttributNode>> > ());
    yylhs.value.as < std::shared_ptr<EllipseNode> > () = ellipse;
 }
#line 2472 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 58:
#line 447 "parser/parser.yy"
                                                        {
    std::shared_ptr<LigneNode> ligne = std::make_shared<LigneNode>(yystack_[4].value.as < ExpressionPtr > (), yystack_[3].value.as < ExpressionPtr > (), yystack_[2].value.as < ExpressionPtr > (),yystack_[1].value.as < ExpressionPtr > ());
    ligne->setAttributs(yystack_[0].value.as < std::vector<std::shared_ptr<AttributNode>> > ());
    yylhs.value.as < std::shared_ptr<LigneNode> > () = ligne;
 }
#line 2482 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 59:
#line 455 "parser/parser.yy"
                         {
    std::shared_ptr<CheminNode> chemin = std::make_shared<CheminNode>(yystack_[1].value.as < std::vector<std::shared_ptr<PositionNode>> > ());
    chemin->setAttributs(yystack_[0].value.as < std::vector<std::shared_ptr<AttributNode>> > ());
    yylhs.value.as < std::shared_ptr<CheminNode> > () = chemin;
 }
#line 2492 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 60:
#line 463 "parser/parser.yy"
                                                  {
    std::shared_ptr<TexteNode> texte = std::make_shared<TexteNode>(yystack_[4].value.as < ExpressionPtr > (), yystack_[3].value.as < ExpressionPtr > (), yystack_[2].value.as < std::string > (),yystack_[1].value.as < std::string > ());
    texte->setAttributs(yystack_[0].value.as < std::vector<std::shared_ptr<AttributNode>> > ());
    yylhs.value.as < std::shared_ptr<TexteNode> > () = texte;
 }
#line 2502 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 61:
#line 470 "parser/parser.yy"
                             {
        yylhs.value.as < std::shared_ptr<AccesFigureNode> > () = std::make_shared<AccesIndexNode>(FigureTypes::carre, yystack_[2].value.as < int > ());
    }
#line 2510 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 62:
#line 475 "parser/parser.yy"
                                 {
        yylhs.value.as < std::shared_ptr<AccesFigureNode> > () = std::make_shared<AccesIndexNode>(FigureTypes::rectangle, yystack_[2].value.as < int > ());
    }
#line 2518 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 63:
#line 480 "parser/parser.yy"
                                {
        yylhs.value.as < std::shared_ptr<AccesFigureNode> > () = std::make_shared<AccesIndexNode>(FigureTypes::triangle, yystack_[2].value.as < int > ());
    }
#line 2526 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 64:
#line 485 "parser/parser.yy"
                              {
        yylhs.value.as < std::shared_ptr<AccesFigureNode> > () = std::make_shared<AccesIndexNode>(FigureTypes::cercle, yystack_[2].value.as < int > ());
    }
#line 2534 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 65:
#line 490 "parser/parser.yy"
                               {
        yylhs.value.as < std::shared_ptr<AccesFigureNode> > () = std::make_shared<AccesIndexNode>(FigureTypes::ellipse, yystack_[2].value.as < int > ());
    }
#line 2542 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 66:
#line 495 "parser/parser.yy"
                             {
        yylhs.value.as < std::shared_ptr<AccesFigureNode> > () = std::make_shared<AccesIndexNode>(FigureTypes::ligne, yystack_[2].value.as < int > ());
    }
#line 2550 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 67:
#line 500 "parser/parser.yy"
                              {
        yylhs.value.as < std::shared_ptr<AccesFigureNode> > () = std::make_shared<AccesIndexNode>(FigureTypes::chemin, yystack_[2].value.as < int > ());
    }
#line 2558 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 68:
#line 505 "parser/parser.yy"
                             {
        yylhs.value.as < std::shared_ptr<AccesFigureNode> > () = std::make_shared<AccesIndexNode>(FigureTypes::texte, yystack_[2].value.as < int > ());
    }
#line 2566 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 69:
#line 511 "parser/parser.yy"
                 {
        yylhs.value.as < std::shared_ptr<AccesFigureNode> > () = std::make_shared<AccesVariableNode>(yystack_[1].value.as < std::string > ());
    }
#line 2574 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 70:
#line 516 "parser/parser.yy"
                             {
        yylhs.value.as < std::shared_ptr<AttributNode> > () = std::make_shared<ColorNode>(yystack_[0].value.as < CouleurPtr > ());
    }
#line 2582 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 71:
#line 522 "parser/parser.yy"
                                  {
        yylhs.value.as < std::shared_ptr<AttributNode> > () = std::make_shared<RemplissageNode>(yystack_[0].value.as < CouleurPtr > ());
    }
#line 2590 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 72:
#line 528 "parser/parser.yy"
                                {
        yylhs.value.as < std::shared_ptr<AttributNode> > () = std::make_shared<RotationNode>(yystack_[1].value.as < ExpressionPtr > ());
    }
#line 2598 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 73:
#line 534 "parser/parser.yy"
                              {
        yylhs.value.as < std::shared_ptr<AttributNode> > () = std::make_shared<OpaciteNode>(yystack_[1].value.as < ExpressionPtr > ());
    }
#line 2606 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 74:
#line 540 "parser/parser.yy"
                            {
        yylhs.value.as < std::shared_ptr<AttributNode> > () = std::make_shared<EpaisseurNode>(yystack_[0].value.as < ExpressionPtr > ());
    }
#line 2614 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 75:
#line 546 "parser/parser.yy"
                             {
        yylhs.value.as < std::shared_ptr<AttributNode> > () = std::make_shared<PositionXNode>(yystack_[2].value.as < std::string > (),yystack_[0].value.as < ExpressionPtr > ());
    }
#line 2622 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 76:
#line 552 "parser/parser.yy"
                             {
        yylhs.value.as < std::shared_ptr<AttributNode> > () = std::make_shared<PositionYNode>(yystack_[2].value.as < std::string > (),yystack_[0].value.as < ExpressionPtr > ());
    }
#line 2630 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 77:
#line 558 "parser/parser.yy"
           {
        yylhs.value.as < TailleType > () = TailleType::taille;
    }
#line 2638 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 78:
#line 562 "parser/parser.yy"
            {
        yylhs.value.as < TailleType > () = TailleType::hauteur;
    }
#line 2646 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 79:
#line 566 "parser/parser.yy"
            {
        yylhs.value.as < TailleType > () = TailleType::largeur;
    }
#line 2654 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 80:
#line 572 "parser/parser.yy"
                           {
        yylhs.value.as < std::shared_ptr<ModificationFigureNode> > () = std::make_shared<ModificationAttributsNode>(yystack_[1].value.as < std::shared_ptr<AccesFigureNode> > (), yystack_[0].value.as < std::shared_ptr<AttributNode> > ());
    }
#line 2662 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 81:
#line 578 "parser/parser.yy"
                                        {
        yylhs.value.as < std::shared_ptr<ModificationFigureNode> > () = std::make_shared<ModificationTailleFigureNode>(yystack_[3].value.as < std::shared_ptr<AccesFigureNode> > (), yystack_[2].value.as < TailleType > (), yystack_[0].value.as < ExpressionPtr > ());
    }
#line 2670 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 82:
#line 584 "parser/parser.yy"
                                   {
        yylhs.value.as < std::shared_ptr<DeclarationVariable> > () = std::make_shared<DeclarationVariable>(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::shared_ptr<FigureNode> > ());
    }
#line 2678 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 83:
#line 589 "parser/parser.yy"
          { yylhs.value.as < operators > () = operators::equal; }
#line 2684 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 84:
#line 590 "parser/parser.yy"
             { yylhs.value.as < operators > () = operators::not_equal; }
#line 2690 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 85:
#line 591 "parser/parser.yy"
              { yylhs.value.as < operators > () = operators::less_equal; }
#line 2696 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 86:
#line 592 "parser/parser.yy"
                 { yylhs.value.as < operators > () = operators::greater_equal; }
#line 2702 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 87:
#line 593 "parser/parser.yy"
         { yylhs.value.as < operators > () = operators::less; }
#line 2708 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 88:
#line 594 "parser/parser.yy"
            { yylhs.value.as < operators > () = operators::greater; }
#line 2714 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 89:
#line 597 "parser/parser.yy"
                { yylhs.value.as < string_operators > () = string_operators::equal; }
#line 2720 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 90:
#line 598 "parser/parser.yy"
                   { yylhs.value.as < string_operators > () = string_operators::not_equal; }
#line 2726 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 91:
#line 601 "parser/parser.yy"
              {
        yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
    }
#line 2734 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 92:
#line 607 "parser/parser.yy"
              {
        yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
    }
#line 2742 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 93:
#line 612 "parser/parser.yy"
                                                     {
        yylhs.value.as < std::shared_ptr<ConditionNode> > () = std::make_shared<TailleConditionNode>(yystack_[3].value.as < std::shared_ptr<AccesFigureNode> > (), yystack_[1].value.as < operators > (), yystack_[0].value.as < ExpressionPtr > (), yystack_[2].value.as < TailleType > ());
    }
#line 2750 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 94:
#line 618 "parser/parser.yy"
                                                         {
        yylhs.value.as < std::shared_ptr<ConditionNode> > () = std::make_shared<PositionConditionNode>(yystack_[3].value.as < std::shared_ptr<AccesFigureNode> > (),yystack_[2].value.as < std::string > (), yystack_[1].value.as < operators > (), yystack_[0].value.as < ExpressionPtr > ());
    }
#line 2758 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 95:
#line 624 "parser/parser.yy"
                                         {
        yylhs.value.as < std::shared_ptr<ConditionNode> > () = std::make_shared<NumberConditionNode>(yystack_[2].value.as < ExpressionPtr > (), yystack_[1].value.as < operators > (), yystack_[0].value.as < ExpressionPtr > ());
    }
#line 2766 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 96:
#line 630 "parser/parser.yy"
             {
        yylhs.value.as < std::shared_ptr<ConditionNode> > () = std::make_shared<BooleanVariableConditionNode>(yystack_[0].value.as < std::string > ());
    }
#line 2774 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 97:
#line 636 "parser/parser.yy"
                                                      {
        yylhs.value.as < std::shared_ptr<ConditionNode> > () = std::make_shared<CouleurConditionNode>(yystack_[3].value.as < std::shared_ptr<AccesFigureNode> > (), yystack_[1].value.as < string_operators > (), yystack_[0].value.as < CouleurPtr > ());
    }
#line 2782 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 98:
#line 642 "parser/parser.yy"
              {
        yylhs.value.as < std::vector<std::shared_ptr<ConditionNode>> > ().push_back(yystack_[0].value.as < std::shared_ptr<ConditionNode> > ());
    }
#line 2790 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 99:
#line 648 "parser/parser.yy"
                                             {
        yystack_[5].value.as < std::vector<std::shared_ptr<ConditionNode>> > ().push_back(yystack_[1].value.as < std::shared_ptr<ConditionNode> > ());
        yylhs.value.as < std::vector<std::shared_ptr<ConditionNode>> > () = yystack_[5].value.as < std::vector<std::shared_ptr<ConditionNode>> > ();
    }
#line 2799 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 100:
#line 654 "parser/parser.yy"
                                                                {
        yylhs.value.as < std::shared_ptr<IfNode> > () = std::make_shared<IfNode>(yystack_[3].value.as < std::vector<std::shared_ptr<Noeud>> > (), yystack_[0].value.as < std::vector<std::shared_ptr<Noeud>> > (), yystack_[8].value.as < std::vector<std::shared_ptr<ConditionNode>> > ());
    }
#line 2807 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 101:
#line 659 "parser/parser.yy"
    {

    }
#line 2815 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 102:
#line 665 "parser/parser.yy"
                                  {
        yylhs.value.as < std::vector<std::shared_ptr<Noeud>> > () = yystack_[1].value.as < std::vector<std::shared_ptr<Noeud>> > ();
    }
#line 2823 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 103:
#line 671 "parser/parser.yy"
                                                  {
        yylhs.value.as < std::shared_ptr<ForLoopNode> > () = std::make_shared<ForLoopNode>(yystack_[1].value.as < std::vector<std::shared_ptr<Noeud>> > (), yystack_[5].value.as < ExpressionPtr > ());
    }
#line 2831 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 104:
#line 676 "parser/parser.yy"
                                                     {
        yylhs.value.as < std::shared_ptr<WhileNode> > () = std::make_shared<WhileNode>(yystack_[1].value.as < std::vector<std::shared_ptr<Noeud>> > (), yystack_[5].value.as < std::vector<std::shared_ptr<ConditionNode>> > ());
    }
#line 2839 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 105:
#line 682 "parser/parser.yy"
                           { 
        yylhs.value.as < std::shared_ptr<AffectationSimpleVariableNode> > () = std::make_shared<AffectationDoubleVariableNode>(yystack_[2].value.as < std::string > (), yystack_[0].value.as < ExpressionPtr > ());
    }
#line 2847 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 106:
#line 688 "parser/parser.yy"
                           {
        yylhs.value.as < std::shared_ptr<AffectationSimpleVariableNode> > () = std::make_shared<AffectationBoolVariableNode>(yystack_[2].value.as < std::string > (), yystack_[0].value.as < bool > ());
    }
#line 2855 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 107:
#line 694 "parser/parser.yy"
                            {
        yylhs.value.as < std::shared_ptr<AffectationSimpleVariableNode> > () = std::make_shared<AffectationCouleurVariableNode>(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ());
    }
#line 2863 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 108:
#line 699 "parser/parser.yy"
    {
    }
#line 2870 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 109:
#line 704 "parser/parser.yy"
                       {
        yystack_[0].value.as < std::vector<std::string> > ().push_back(yystack_[1].value.as < std::string > ());
        yylhs.value.as < std::vector<std::string> > () = yystack_[0].value.as < std::vector<std::string> > ();
    }
#line 2879 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 110:
#line 710 "parser/parser.yy"
    {
    }
#line 2886 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 111:
#line 715 "parser/parser.yy"
                              {
        yystack_[0].value.as < std::vector<ExpressionPtr> > ().push_back(yystack_[1].value.as < ExpressionPtr > ());
        yylhs.value.as < std::vector<ExpressionPtr> > () = yystack_[0].value.as < std::vector<ExpressionPtr> > ();
    }
#line 2895 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 112:
#line 722 "parser/parser.yy"
                                                                {
        yylhs.value.as < std::shared_ptr<FonctionNode> > () = std::make_shared<FonctionNode>(yystack_[1].value.as < std::vector<std::shared_ptr<Noeud>> > (), yystack_[7].value.as < std::string > (), yystack_[5].value.as < std::vector<std::string> > ());
    }
#line 2903 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 113:
#line 727 "parser/parser.yy"
                             {
        yylhs.value.as < std::shared_ptr<AppelFonctionNode> > () = std::make_shared<AppelFonctionNode>(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::vector<ExpressionPtr> > ());
    }
#line 2911 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 114:
#line 733 "parser/parser.yy"
           {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<Constante>(yystack_[0].value.as < int > ());
    }
#line 2919 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 115:
#line 737 "parser/parser.yy"
               {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<Variable>(yystack_[0].value.as < std::string > ());
    }
#line 2927 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 116:
#line 740 "parser/parser.yy"
                        {
        yylhs.value.as < ExpressionPtr > () = yystack_[1].value.as < ExpressionPtr > ();
    }
#line 2935 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 117:
#line 743 "parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::plus);
    }
#line 2943 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 118:
#line 746 "parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::moins);
    }
#line 2951 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 119:
#line 749 "parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::multiplie);
    }
#line 2959 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 120:
#line 752 "parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::divise);
    }
#line 2967 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 121:
#line 755 "parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionUnaire>(yystack_[0].value.as < ExpressionPtr > (),OperateurUnaire::neg);
    }
#line 2975 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 122:
#line 760 "parser/parser.yy"
                        {
        yylhs.value.as < std::vector<std::shared_ptr<PositionNode>> > ().push_back(std::make_shared<PositionNode>(yystack_[1].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > ()));
    }
#line 2983 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;

  case 123:
#line 763 "parser/parser.yy"
                                      {
        yystack_[3].value.as < std::vector<std::shared_ptr<PositionNode>> > ().push_back(std::make_shared<PositionNode>(yystack_[1].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > ()));
        for(auto i : yystack_[3].value.as < std::vector<std::shared_ptr<PositionNode>> > ()) {
            yylhs.value.as < std::vector<std::shared_ptr<PositionNode>> > ().push_back(i);
        }
    }
#line 2994 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"
    break;


#line 2998 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"

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


  const short  Parser ::yypact_ninf_ = -269;

  const signed char  Parser ::yytable_ninf_ = -122;

  const short
   Parser ::yypact_[] =
  {
     407,  -269,    12,    12,    12,  -269,    12,   -57,    12,    22,
     -36,    22,   137,   211,   263,   294,   296,   327,   329,   331,
      21,  -269,    20,  -269,   210,   -24,    -7,  -269,  -269,  -269,
    -269,  -269,  -269,  -269,  -269,  -269,   484,    -5,  -269,  -269,
    -269,  -269,    -3,  -269,     6,  -269,    -4,     4,    30,    34,
      76,     2,  -269,    22,    22,  -269,   125,    76,   191,    95,
     191,    97,   191,   101,   191,   107,   191,   108,   191,   109,
     191,   111,   191,    75,   121,   191,  -269,   407,   276,  -269,
    -269,   191,  -269,  -269,    63,    67,    69,    77,    79,    82,
      84,  -269,  -269,  -269,  -269,    92,  -269,  -269,  -269,    22,
       7,    22,    62,    94,    96,    98,   100,   106,   110,   126,
     128,    76,   -49,   212,  -269,    78,   477,    12,  -269,   257,
     112,    22,    22,    22,    22,    88,    22,   358,   132,   191,
     140,   191,   151,   191,   153,   191,   155,   191,   158,   191,
     159,   358,   520,  -269,   170,    22,  -269,   162,    83,  -269,
    -269,  -269,  -269,    22,    22,    22,    22,    22,    22,    22,
      22,  -269,  -269,   358,  -269,    22,    22,    10,    22,    10,
      22,    22,    22,   358,  -269,   358,  -269,   160,   408,  -269,
    -269,   -12,   355,   355,   209,  -269,  -269,  -269,  -269,  -269,
    -269,    22,    12,   166,  -269,   234,   -25,   -25,  -269,  -269,
     178,    16,   172,   191,   176,   297,   188,   191,   189,   297,
     190,   191,   193,   191,   194,   200,   204,   207,   208,   220,
     223,   224,    15,  -269,   520,   191,   206,   277,   358,   358,
    -269,  -269,  -269,   369,  -269,   318,   358,   358,   237,  -269,
    -269,    10,    22,    22,   231,   358,  -269,   236,   448,   306,
    -269,   191,  -269,  -269,  -269,   297,  -269,  -269,  -269,   297,
    -269,   297,  -269,    22,    22,    10,    22,    10,    22,    22,
     520,  -269,   324,   241,   358,  -269,    -1,  -269,  -269,   269,
    -269,   358,   358,   337,   339,   284,   343,   448,   191,  -269,
    -269,  -269,   358,   358,  -269,   415,  -269,   322,   358,  -269,
     386,  -269,  -269,   165,   448,   448,  -269,   448,   293,   191,
    -269,  -269,  -269,   299,   286,   302,   304,  -269,  -269,   191,
    -269,  -269,   357,  -269,   297,   341,  -269,   309,  -269,   376,
     448,   332,  -269
  };

  const signed char
   Parser ::yydefact_[] =
  {
       0,     4,     0,     0,     0,    36,     0,     0,     0,     0,
       0,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     0,     7,   110,     0,     0,    25,    45,    46,
      47,    48,    49,    51,    50,    52,    30,     0,    28,    29,
      31,    32,     0,    34,     0,    37,     0,     0,     0,     0,
       0,     0,   114,     0,     0,   115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     0,    69,
     113,   110,    27,    24,     0,     0,     0,     0,     0,     0,
       0,    77,    78,    79,    80,     0,    26,    33,    35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   115,     0,    98,     0,     0,   108,   121,     0,
       0,     0,     0,     0,     0,     0,     0,    44,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   122,     0,    12,     0,     0,    59,     0,     0,     3,
      38,    39,   107,     0,     0,     0,     0,     0,     0,     0,
       0,   106,    82,   105,   111,     0,     0,     0,     0,     0,
       0,     0,     0,    40,    42,    41,    43,     0,     0,    91,
      92,     0,     0,     0,     0,    83,    84,    87,    85,    88,
      86,     0,   108,     0,   116,     0,   118,   117,   119,   120,
       0,   118,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     8,     0,     0,     0,     0,    75,    76,
      22,    70,    23,     0,    71,     0,    74,    81,     0,    89,
      90,     0,     0,     0,     0,    95,   109,     0,     6,     0,
      62,     0,    61,    53,    63,     0,    64,    56,    65,     0,
      66,     0,    67,     0,     0,     0,     0,     0,     0,     0,
       0,    14,     0,     0,   123,    68,     0,    72,    73,     0,
      97,    93,    94,     0,     0,     0,     0,     6,     0,    55,
      57,    58,    20,    21,    15,     0,    16,     0,    19,     9,
       0,    10,    60,     0,     6,     6,   103,     6,     0,     0,
      17,    18,    13,     0,     0,     0,     0,     5,   104,     0,
      11,    99,     0,   112,     0,   101,    54,     0,   100,     0,
       6,     0,   102
  };

  const short
   Parser ::yypgoto_[] =
  {
    -269,  -269,   321,  -268,     1,  -269,  -269,  -192,  -215,  -162,
    -269,     0,   283,  -269,  -269,   325,  -269,  -269,  -269,  -269,
    -269,  -269,  -269,  -269,   -45,  -269,   289,  -269,  -269,   -74,
    -269,  -269,   118,   -47,  -269,  -269,  -269,  -269,  -269,   235,
     323,  -269,  -269,    29,  -269
  };

  const short
   Parser ::yydefgoto_[] =
  {
      -1,    20,    21,   285,   286,   222,   272,   146,   223,   231,
      23,    55,   161,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    94,    95,    37,    38,   191,
     241,   183,   114,   115,    39,   328,    40,    41,    42,   193,
      80,    43,    44,   116,    73
  };

  const short
   Parser ::yytable_[] =
  {
      24,    22,    46,    47,    48,   113,    49,   234,    51,   273,
     125,    50,   113,   253,   150,   151,   142,   257,    79,   308,
     -96,    76,     5,    77,     5,   239,   240,    52,   230,  -121,
     123,   124,    57,  -121,     5,    82,   315,   316,    56,   317,
      58,    60,    62,    64,    66,    68,    70,    72,    75,    45,
     112,    45,    83,    81,    96,   299,    97,   112,   143,   144,
      99,    45,   331,   289,   177,    98,   113,   290,   100,   291,
     117,  -121,  -121,   270,   271,    53,  -121,    24,    22,   280,
     176,    52,   118,   119,   302,   313,  -121,   127,     5,   129,
      54,   131,   142,   133,   101,   135,   227,   137,   102,   139,
     128,   141,   130,   294,   148,   296,   132,   163,   242,   243,
      81,   112,   134,   136,   138,    45,   140,   192,   103,   104,
     105,   106,   107,   108,   109,   110,   147,   165,   173,    53,
     175,   166,   326,   167,   143,   144,   121,   122,   123,   124,
     178,   168,    52,   169,   111,   145,   170,   184,   171,     5,
     196,   197,   198,   199,   120,   201,   172,   200,   203,    59,
     205,    61,   207,    63,   209,    65,   211,   232,   213,   232,
      52,    67,   195,   224,   225,    69,    45,     5,   121,   122,
     123,   124,    60,    62,    64,    66,    68,    70,    72,    75,
      53,    71,   192,    74,   228,   229,    52,   233,   202,   235,
     236,   237,    59,     5,    45,    54,   204,   103,   104,   105,
     106,   107,   108,   109,   110,    52,    52,   206,    53,   208,
     245,   210,     5,     5,   212,   214,   179,   180,   226,   238,
      45,   181,   251,    54,   244,   247,   255,   248,   249,   250,
     259,   232,   261,   252,   126,   122,   123,   124,    24,    45,
      45,    91,    92,    93,   274,   254,   256,   258,   113,    54,
     260,   262,   263,    53,    53,   232,   264,   232,    52,   265,
     266,   281,   282,   275,    78,     5,    61,    79,    54,    54,
     288,    52,   267,   150,   151,   268,   269,    24,     5,   279,
     276,   283,   292,   293,   152,   295,   284,   297,   298,    52,
     301,    52,    45,   112,    24,    24,     5,    24,     5,   287,
     121,   122,   123,   124,   142,    45,    53,   309,   153,   154,
     155,   156,   157,   158,   159,   160,   194,   300,    63,    53,
      24,    54,    52,    45,    52,    45,    52,   303,   319,     5,
     304,     5,   305,     5,    54,   306,   307,    53,   324,    53,
     121,   122,   123,   124,   318,   321,   143,   144,   320,    65,
     325,    67,    54,   322,    54,   323,    45,   327,    45,   329,
      45,   121,   122,   123,   124,   121,   122,   123,   124,   330,
      53,   278,    53,   174,    53,   311,   185,   186,   187,   188,
     189,   190,    69,   332,    71,    54,    74,    54,   149,    54,
     215,   216,   182,   162,   164,   217,   218,   219,   220,   221,
       1,   121,   122,   123,   124,     0,     2,     3,     4,     5,
     277,   314,   121,   122,   123,   124,     6,   246,     0,     0,
       0,     7,     0,     0,     8,     9,     0,    10,     0,   185,
     186,   187,   188,   189,   190,     0,    11,   312,     0,    12,
      13,    14,    15,    16,    17,    18,    19,     2,     3,     4,
       5,   121,   122,   123,   124,     0,   310,     6,   121,   122,
     123,   124,     7,     0,     0,     8,     9,   194,    10,     0,
       0,     0,     0,     0,     0,     0,     0,    11,     0,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    84,    85,
       0,     0,     0,    86,    87,    88,    89,    90,   185,   186,
     187,   188,   189,   190,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,     0,     0,     0,     0,
     121,   122,   123,   124,   215,   216,     0,     0,     0,   217,
     218,   219,   220,   221
  };

  const short
   Parser ::yycheck_[] =
  {
       0,     0,     2,     3,     4,    50,     6,   169,     8,   224,
      57,    68,    57,   205,     7,     8,    17,   209,    67,   287,
      69,     0,    12,     3,    12,    37,    38,     5,    18,    13,
      55,    56,    68,    17,    12,    59,   304,   305,     9,   307,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    39,
      50,    39,    59,    24,    59,   270,    59,    57,    59,    60,
      64,    39,   330,   255,   111,    59,   111,   259,    64,   261,
      68,    55,    56,    58,    59,    53,    60,    77,    77,   241,
      18,     5,    53,    54,   276,   300,    70,    58,    12,    60,
      68,    62,    17,    64,    64,    66,    13,    68,    64,    70,
       5,    72,     5,   265,    75,   267,     5,    78,   182,   183,
      81,   111,     5,     5,     5,    39,     5,   117,    42,    43,
      44,    45,    46,    47,    48,    49,     5,    64,    99,    53,
     101,    64,   324,    64,    59,    60,    53,    54,    55,    56,
     111,    64,     5,    64,    68,    70,    64,    69,    64,    12,
     121,   122,   123,   124,    29,   126,    64,    69,   129,    65,
     131,    65,   133,    65,   135,    65,   137,   167,   139,   169,
       5,    65,    60,     3,   145,    65,    39,    12,    53,    54,
      55,    56,   153,   154,   155,   156,   157,   158,   159,   160,
      53,    65,   192,    65,   165,   166,     5,   168,    66,   170,
     171,   172,    65,    12,    39,    68,    66,    42,    43,    44,
      45,    46,    47,    48,    49,     5,     5,    66,    53,    66,
     191,    66,    12,    12,    66,    66,    14,    15,    66,    69,
      39,    19,   203,    68,    25,    69,   207,     3,    60,    67,
     211,   241,   213,    67,    53,    54,    55,    56,   248,    39,
      39,    39,    40,    41,   225,    67,    67,    67,   303,    68,
      67,    67,    62,    53,    53,   265,    62,   267,     5,    62,
      62,   242,   243,    67,    64,    12,    65,    67,    68,    68,
     251,     5,    62,     7,     8,    62,    62,   287,    12,    52,
      13,    60,   263,   264,    18,   266,    60,   268,   269,     5,
      59,     5,    39,   303,   304,   305,    12,   307,    12,     3,
      53,    54,    55,    56,    17,    39,    53,   288,    42,    43,
      44,    45,    46,    47,    48,    49,    69,     3,    65,    53,
     330,    68,     5,    39,     5,    39,     5,    68,   309,    12,
       3,    12,     3,    12,    68,    61,     3,    53,   319,    53,
      53,    54,    55,    56,    61,    69,    59,    60,    59,    65,
       3,    65,    68,    61,    68,    61,    39,    26,    39,    60,
      39,    53,    54,    55,    56,    53,    54,    55,    56,     3,
      53,    63,    53,   100,    53,    63,    31,    32,    33,    34,
      35,    36,    65,    61,    65,    68,    65,    68,    77,    68,
      14,    15,   113,    78,    81,    19,    20,    21,    22,    23,
       3,    53,    54,    55,    56,    -1,     9,    10,    11,    12,
      51,   303,    53,    54,    55,    56,    19,   192,    -1,    -1,
      -1,    24,    -1,    -1,    27,    28,    -1,    30,    -1,    31,
      32,    33,    34,    35,    36,    -1,    39,    61,    -1,    42,
      43,    44,    45,    46,    47,    48,    49,     9,    10,    11,
      12,    53,    54,    55,    56,    -1,    51,    19,    53,    54,
      55,    56,    24,    -1,    -1,    27,    28,    69,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,
      42,    43,    44,    45,    46,    47,    48,    49,    14,    15,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    41,    -1,    -1,    -1,    -1,
      53,    54,    55,    56,    14,    15,    -1,    -1,    -1,    19,
      20,    21,    22,    23
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,     3,     9,    10,    11,    12,    19,    24,    27,    28,
      30,    39,    42,    43,    44,    45,    46,    47,    48,    49,
      72,    73,    75,    81,    82,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    98,    99,   105,
     107,   108,   109,   112,   113,    39,    82,    82,    82,    82,
      68,    82,     5,    53,    68,    82,   114,    68,   114,    65,
     114,    65,   114,    65,   114,    65,   114,    65,   114,    65,
     114,    65,   114,   115,    65,   114,     0,     3,    64,    67,
     111,   114,    59,    59,    14,    15,    19,    20,    21,    22,
      23,    39,    40,    41,    96,    97,    59,    59,    59,    64,
      64,    64,    64,    42,    43,    44,    45,    46,    47,    48,
      49,    68,    82,    95,   103,   104,   114,    68,   114,   114,
      29,    53,    54,    55,    56,   104,    53,   114,     5,   114,
       5,   114,     5,   114,     5,   114,     5,   114,     5,   114,
       5,   114,    17,    59,    60,    70,    78,     5,   114,    73,
       7,     8,    18,    42,    43,    44,    45,    46,    47,    48,
      49,    83,    86,   114,   111,    64,    64,    64,    64,    64,
      64,    64,    64,   114,    83,   114,    18,   104,   114,    14,
      15,    19,    97,   102,    69,    31,    32,    33,    34,    35,
      36,   100,    82,   110,    69,    60,   114,   114,   114,   114,
      69,   114,    66,   114,    66,   114,    66,   114,    66,   114,
      66,   114,    66,   114,    66,    14,    15,    19,    20,    21,
      22,    23,    76,    79,     3,   114,    66,    13,   114,   114,
      18,    80,    82,   114,    80,   114,   114,   114,    69,    37,
      38,   101,   100,   100,    25,   114,   110,    69,     3,    60,
      67,   114,    67,    78,    67,   114,    67,    78,    67,   114,
      67,   114,    67,    62,    62,    62,    62,    62,    62,    62,
      58,    59,    77,    79,   114,    67,    13,    51,    63,    52,
      80,   114,   114,    60,    60,    74,    75,     3,   114,    78,
      78,    78,   114,   114,    80,   114,    80,   114,   114,    79,
       3,    59,    78,    68,     3,     3,    61,     3,    74,   114,
      51,    63,    61,    79,   103,    74,    74,    74,    61,   114,
      59,    69,    61,    61,   114,     3,    78,    26,   106,    60,
       3,    74,    61
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    71,    72,    73,    73,    74,    74,    75,    76,    76,
      77,    77,    78,    78,    78,    79,    79,    79,    79,    79,
      79,    79,    80,    80,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    82,    82,    83,    83,
      84,    84,    84,    84,    85,    86,    86,    86,    86,    86,
      86,    86,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      96,    96,    96,    96,    96,    96,    96,    97,    97,    97,
      98,    98,    99,   100,   100,   100,   100,   100,   100,   101,
     101,   102,   102,   103,   103,   103,   103,   103,   104,   104,
     105,   106,   106,   107,   108,   109,   109,   109,   110,   110,
     111,   111,   112,   113,   114,   114,   114,   114,   114,   114,
     114,   114,   115,   115
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     1,     3,     1,     3,     0,     1,     1,     3,
       2,     4,     1,     5,     3,     3,     3,     4,     4,     3,
       3,     3,     1,     1,     2,     1,     2,     2,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     1,     1,     1,
       4,     4,     4,     4,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     5,    10,     6,     5,     6,     6,     3,
       6,     5,     5,     5,     5,     5,     5,     5,     5,     2,
       3,     3,     4,     4,     3,     3,     3,     1,     1,     1,
       2,     4,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     3,     1,     4,     1,     7,
      11,     0,     5,     7,     8,     3,     3,     3,     0,     2,
       0,     2,     9,     2,     1,     1,     3,     3,     3,     3,
       3,     2,     2,     4
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const  Parser ::yytname_[] =
  {
  "$end", "error", "$undefined", "NL", "END", "NUMBER", "FLOAT", "TRUE",
  "FALSE", "INT_TYPE", "BOOL_TYPE", "FLOAT_TYPE", "VARIABLE", "STRING",
  "POSITIONX", "POSITIONY", "ATTRIBUT", "INLINE_AFFECTATION", "HEXA_VALUE",
  "COULEUR", "ROTATION", "REMPLISSAGE", "OPACITE", "EPAISSEUR", "SI",
  "ALORS", "SINON", "FUNCTION", "REPETE", "FOIS", "WHILE", "EQUAL",
  "NOTEQUAL", "LESS", "LESSEQUAL", "GREATER", "GREATEREQUAL",
  "STRINGEQUAL", "STRINGNOTEQUAL", "TAILLE", "HAUTEUR", "LARGEUR",
  "RECTANGLE", "CARRE", "TRIANGLE", "CERCLE", "ELLIPSE", "LIGNE", "CHEMIN",
  "TEXTE", "STOP", "DEGRE", "AND", "'-'", "'+'", "'*'", "'/'", "NEG",
  "'&'", "';'", "'{'", "'}'", "':'", "'%'", "'='", "'['", "']'", "'.'",
  "'('", "')'", "','", "$accept", "programme", "subProgramme",
  "instructions", "instruction", "attributsInline", "attributsCSS",
  "attributs", "attributAffectation", "couleurValue", "expression",
  "variable", "boolValue", "declarationVariableSimple", "declarationCanva",
  "declarationFigure", "carre", "rectangle", "triangle", "cercle",
  "ellipse", "ligne", "chemin", "texte", "accesFigure", "setAttribut",
  "setTaille", "modificationFigure", "declarationVariable",
  "numberComparator", "stringComparator", "positionValue", "condition",
  "conditions", "if", "else", "boucleFor", "boucleWhile", "affectation",
  "arguments", "argumentsValues", "fonction", "appelFonction", "operation",
  "vectPos", YY_NULLPTR
  };


  const short
   Parser ::yyrline_[] =
  {
       0,   178,   178,   185,   192,   196,   204,   209,   214,   220,
     227,   233,   239,   243,   249,   255,   261,   267,   273,   279,
     285,   291,   296,   302,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   322,   322,   327,   333,
     338,   344,   350,   356,   361,   367,   371,   375,   380,   385,
     390,   395,   400,   408,   415,   423,   431,   439,   447,   455,
     463,   470,   475,   480,   485,   490,   495,   500,   505,   511,
     516,   522,   528,   534,   540,   546,   552,   558,   562,   566,
     572,   578,   584,   589,   590,   591,   592,   593,   594,   597,
     598,   601,   607,   612,   618,   624,   630,   636,   642,   648,
     654,   659,   665,   671,   676,   682,   688,   694,   699,   704,
     710,   715,   722,   727,   733,   737,   740,   743,   746,   749,
     752,   755,   760,   763
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
       2,     2,     2,     2,     2,     2,     2,    63,    58,     2,
      68,    69,    55,    54,    70,    53,    67,    56,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    62,    59,
       2,    64,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,    66,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    60,     2,    61,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    57
    };
    const int user_token_number_max_ = 308;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

} // yy
#line 3606 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp"

#line 770 "parser/parser.yy"


void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
