// A Bison parser, made by GNU Bison 3.7.5.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hpp"


// Unqualified %code blocks.
#line 27 "parser/parser.yy"

    #include <iostream>
    #include <string>
    #include <map>
    #include <memory>
    
    #include "scanner.hh"
    #include "driver.hh"

    #undef  yylex
    #define yylex scanner.yylex

#line 59 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"


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
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
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
#line 151 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"

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
  | symbol kinds.  |
  `---------------*/

  // basic_symbol.
  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_accesCouleurFigure: // accesCouleurFigure
        value.copy< AccesCouleurFigure * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_accesFigure: // accesFigure
        value.copy< AccesFigureNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_programme: // programme
      case symbol_kind::S_subProgramme: // subProgramme
        value.copy< ArbreSyntaxique > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declarationCanva: // declarationCanva
        value.copy< CanevaNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_carre: // carre
        value.copy< CarreNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_condition: // condition
        value.copy< ConditionNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stringCondition: // stringCondition
        value.copy< CouleurConditionNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declarationVariable: // declarationVariable
        value.copy< DeclarationVariable * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declarationFigure: // declarationFigure
        value.copy< FigureNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if: // if
        value.copy< IfNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_modificationFigure: // modificationFigure
        value.copy< ModificationNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_instruction: // instruction
      case symbol_kind::S_expression: // expression
        value.copy< Noeud * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.copy< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.copy< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_operation: // operation
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_attributsInline: // attributsInline
      case symbol_kind::S_attributsCSS: // attributsCSS
      case symbol_kind::S_attributs: // attributs
        value.copy< std::map<std::string, std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_attributAffectation: // attributAffectation
      case symbol_kind::S_setAttribut: // setAttribut
        value.copy< std::pair<std::string, std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT_TYPE: // INT_TYPE
      case symbol_kind::S_BOOL_TYPE: // BOOL_TYPE
      case symbol_kind::S_FLOAT_TYPE: // FLOAT_TYPE
      case symbol_kind::S_VARIABLE: // VARIABLE
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_HEXA_VALUE: // HEXA_VALUE
      case symbol_kind::S_COULEUR: // COULEUR
      case symbol_kind::S_ROTATION: // ROTATION
      case symbol_kind::S_REMPLISSAGE: // REMPLISSAGE
      case symbol_kind::S_OPACITE: // OPACITE
      case symbol_kind::S_EPAISSEUR: // EPAISSEUR
      case symbol_kind::S_pourcentage: // pourcentage
      case symbol_kind::S_chaine: // chaine
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_instructions: // instructions
        value.copy< std::vector<Noeud *> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stringComparator: // stringComparator
        value.copy< string_operators > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
   Parser ::symbol_kind_type
   Parser ::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
   Parser ::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
   Parser ::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_accesCouleurFigure: // accesCouleurFigure
        value.move< AccesCouleurFigure * > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_accesFigure: // accesFigure
        value.move< AccesFigureNode * > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_programme: // programme
      case symbol_kind::S_subProgramme: // subProgramme
        value.move< ArbreSyntaxique > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_declarationCanva: // declarationCanva
        value.move< CanevaNode * > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_carre: // carre
        value.move< CarreNode * > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_condition: // condition
        value.move< ConditionNode * > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stringCondition: // stringCondition
        value.move< CouleurConditionNode * > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_declarationVariable: // declarationVariable
        value.move< DeclarationVariable * > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_declarationFigure: // declarationFigure
        value.move< FigureNode * > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_if: // if
        value.move< IfNode * > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_modificationFigure: // modificationFigure
        value.move< ModificationNode * > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_instruction: // instruction
      case symbol_kind::S_expression: // expression
        value.move< Noeud * > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.move< bool > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< float > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_operation: // operation
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_attributsInline: // attributsInline
      case symbol_kind::S_attributsCSS: // attributsCSS
      case symbol_kind::S_attributs: // attributs
        value.move< std::map<std::string, std::string> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_attributAffectation: // attributAffectation
      case symbol_kind::S_setAttribut: // setAttribut
        value.move< std::pair<std::string, std::string> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INT_TYPE: // INT_TYPE
      case symbol_kind::S_BOOL_TYPE: // BOOL_TYPE
      case symbol_kind::S_FLOAT_TYPE: // FLOAT_TYPE
      case symbol_kind::S_VARIABLE: // VARIABLE
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_HEXA_VALUE: // HEXA_VALUE
      case symbol_kind::S_COULEUR: // COULEUR
      case symbol_kind::S_ROTATION: // ROTATION
      case symbol_kind::S_REMPLISSAGE: // REMPLISSAGE
      case symbol_kind::S_OPACITE: // OPACITE
      case symbol_kind::S_EPAISSEUR: // EPAISSEUR
      case symbol_kind::S_pourcentage: // pourcentage
      case symbol_kind::S_chaine: // chaine
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_instructions: // instructions
        value.move< std::vector<Noeud *> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stringComparator: // stringComparator
        value.move< string_operators > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
   Parser ::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
   Parser ::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

   Parser ::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

   Parser ::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  void
   Parser ::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
   Parser ::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

   Parser ::symbol_kind_type
   Parser ::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

   Parser ::symbol_kind_type
   Parser ::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
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

   Parser ::symbol_kind_type
   Parser ::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

   Parser ::stack_symbol_type::stack_symbol_type ()
  {}

   Parser ::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_accesCouleurFigure: // accesCouleurFigure
        value.YY_MOVE_OR_COPY< AccesCouleurFigure * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_accesFigure: // accesFigure
        value.YY_MOVE_OR_COPY< AccesFigureNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_programme: // programme
      case symbol_kind::S_subProgramme: // subProgramme
        value.YY_MOVE_OR_COPY< ArbreSyntaxique > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declarationCanva: // declarationCanva
        value.YY_MOVE_OR_COPY< CanevaNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_carre: // carre
        value.YY_MOVE_OR_COPY< CarreNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_condition: // condition
        value.YY_MOVE_OR_COPY< ConditionNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stringCondition: // stringCondition
        value.YY_MOVE_OR_COPY< CouleurConditionNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declarationVariable: // declarationVariable
        value.YY_MOVE_OR_COPY< DeclarationVariable * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declarationFigure: // declarationFigure
        value.YY_MOVE_OR_COPY< FigureNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if: // if
        value.YY_MOVE_OR_COPY< IfNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_modificationFigure: // modificationFigure
        value.YY_MOVE_OR_COPY< ModificationNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_instruction: // instruction
      case symbol_kind::S_expression: // expression
        value.YY_MOVE_OR_COPY< Noeud * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.YY_MOVE_OR_COPY< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_operation: // operation
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_attributsInline: // attributsInline
      case symbol_kind::S_attributsCSS: // attributsCSS
      case symbol_kind::S_attributs: // attributs
        value.YY_MOVE_OR_COPY< std::map<std::string, std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_attributAffectation: // attributAffectation
      case symbol_kind::S_setAttribut: // setAttribut
        value.YY_MOVE_OR_COPY< std::pair<std::string, std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT_TYPE: // INT_TYPE
      case symbol_kind::S_BOOL_TYPE: // BOOL_TYPE
      case symbol_kind::S_FLOAT_TYPE: // FLOAT_TYPE
      case symbol_kind::S_VARIABLE: // VARIABLE
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_HEXA_VALUE: // HEXA_VALUE
      case symbol_kind::S_COULEUR: // COULEUR
      case symbol_kind::S_ROTATION: // ROTATION
      case symbol_kind::S_REMPLISSAGE: // REMPLISSAGE
      case symbol_kind::S_OPACITE: // OPACITE
      case symbol_kind::S_EPAISSEUR: // EPAISSEUR
      case symbol_kind::S_pourcentage: // pourcentage
      case symbol_kind::S_chaine: // chaine
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_instructions: // instructions
        value.YY_MOVE_OR_COPY< std::vector<Noeud *> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stringComparator: // stringComparator
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
    switch (that.kind ())
    {
      case symbol_kind::S_accesCouleurFigure: // accesCouleurFigure
        value.move< AccesCouleurFigure * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_accesFigure: // accesFigure
        value.move< AccesFigureNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_programme: // programme
      case symbol_kind::S_subProgramme: // subProgramme
        value.move< ArbreSyntaxique > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declarationCanva: // declarationCanva
        value.move< CanevaNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_carre: // carre
        value.move< CarreNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_condition: // condition
        value.move< ConditionNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stringCondition: // stringCondition
        value.move< CouleurConditionNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declarationVariable: // declarationVariable
        value.move< DeclarationVariable * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declarationFigure: // declarationFigure
        value.move< FigureNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if: // if
        value.move< IfNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_modificationFigure: // modificationFigure
        value.move< ModificationNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_instruction: // instruction
      case symbol_kind::S_expression: // expression
        value.move< Noeud * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_operation: // operation
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_attributsInline: // attributsInline
      case symbol_kind::S_attributsCSS: // attributsCSS
      case symbol_kind::S_attributs: // attributs
        value.move< std::map<std::string, std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_attributAffectation: // attributAffectation
      case symbol_kind::S_setAttribut: // setAttribut
        value.move< std::pair<std::string, std::string> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT_TYPE: // INT_TYPE
      case symbol_kind::S_BOOL_TYPE: // BOOL_TYPE
      case symbol_kind::S_FLOAT_TYPE: // FLOAT_TYPE
      case symbol_kind::S_VARIABLE: // VARIABLE
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_HEXA_VALUE: // HEXA_VALUE
      case symbol_kind::S_COULEUR: // COULEUR
      case symbol_kind::S_ROTATION: // ROTATION
      case symbol_kind::S_REMPLISSAGE: // REMPLISSAGE
      case symbol_kind::S_OPACITE: // OPACITE
      case symbol_kind::S_EPAISSEUR: // EPAISSEUR
      case symbol_kind::S_pourcentage: // pourcentage
      case symbol_kind::S_chaine: // chaine
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_instructions: // instructions
        value.move< std::vector<Noeud *> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stringComparator: // stringComparator
        value.move< string_operators > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_accesCouleurFigure: // accesCouleurFigure
        value.copy< AccesCouleurFigure * > (that.value);
        break;

      case symbol_kind::S_accesFigure: // accesFigure
        value.copy< AccesFigureNode * > (that.value);
        break;

      case symbol_kind::S_programme: // programme
      case symbol_kind::S_subProgramme: // subProgramme
        value.copy< ArbreSyntaxique > (that.value);
        break;

      case symbol_kind::S_declarationCanva: // declarationCanva
        value.copy< CanevaNode * > (that.value);
        break;

      case symbol_kind::S_carre: // carre
        value.copy< CarreNode * > (that.value);
        break;

      case symbol_kind::S_condition: // condition
        value.copy< ConditionNode * > (that.value);
        break;

      case symbol_kind::S_stringCondition: // stringCondition
        value.copy< CouleurConditionNode * > (that.value);
        break;

      case symbol_kind::S_declarationVariable: // declarationVariable
        value.copy< DeclarationVariable * > (that.value);
        break;

      case symbol_kind::S_declarationFigure: // declarationFigure
        value.copy< FigureNode * > (that.value);
        break;

      case symbol_kind::S_if: // if
        value.copy< IfNode * > (that.value);
        break;

      case symbol_kind::S_modificationFigure: // modificationFigure
        value.copy< ModificationNode * > (that.value);
        break;

      case symbol_kind::S_instruction: // instruction
      case symbol_kind::S_expression: // expression
        value.copy< Noeud * > (that.value);
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.copy< float > (that.value);
        break;

      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_operation: // operation
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_attributsInline: // attributsInline
      case symbol_kind::S_attributsCSS: // attributsCSS
      case symbol_kind::S_attributs: // attributs
        value.copy< std::map<std::string, std::string> > (that.value);
        break;

      case symbol_kind::S_attributAffectation: // attributAffectation
      case symbol_kind::S_setAttribut: // setAttribut
        value.copy< std::pair<std::string, std::string> > (that.value);
        break;

      case symbol_kind::S_INT_TYPE: // INT_TYPE
      case symbol_kind::S_BOOL_TYPE: // BOOL_TYPE
      case symbol_kind::S_FLOAT_TYPE: // FLOAT_TYPE
      case symbol_kind::S_VARIABLE: // VARIABLE
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_HEXA_VALUE: // HEXA_VALUE
      case symbol_kind::S_COULEUR: // COULEUR
      case symbol_kind::S_ROTATION: // ROTATION
      case symbol_kind::S_REMPLISSAGE: // REMPLISSAGE
      case symbol_kind::S_OPACITE: // OPACITE
      case symbol_kind::S_EPAISSEUR: // EPAISSEUR
      case symbol_kind::S_pourcentage: // pourcentage
      case symbol_kind::S_chaine: // chaine
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_instructions: // instructions
        value.copy< std::vector<Noeud *> > (that.value);
        break;

      case symbol_kind::S_stringComparator: // stringComparator
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
    switch (that.kind ())
    {
      case symbol_kind::S_accesCouleurFigure: // accesCouleurFigure
        value.move< AccesCouleurFigure * > (that.value);
        break;

      case symbol_kind::S_accesFigure: // accesFigure
        value.move< AccesFigureNode * > (that.value);
        break;

      case symbol_kind::S_programme: // programme
      case symbol_kind::S_subProgramme: // subProgramme
        value.move< ArbreSyntaxique > (that.value);
        break;

      case symbol_kind::S_declarationCanva: // declarationCanva
        value.move< CanevaNode * > (that.value);
        break;

      case symbol_kind::S_carre: // carre
        value.move< CarreNode * > (that.value);
        break;

      case symbol_kind::S_condition: // condition
        value.move< ConditionNode * > (that.value);
        break;

      case symbol_kind::S_stringCondition: // stringCondition
        value.move< CouleurConditionNode * > (that.value);
        break;

      case symbol_kind::S_declarationVariable: // declarationVariable
        value.move< DeclarationVariable * > (that.value);
        break;

      case symbol_kind::S_declarationFigure: // declarationFigure
        value.move< FigureNode * > (that.value);
        break;

      case symbol_kind::S_if: // if
        value.move< IfNode * > (that.value);
        break;

      case symbol_kind::S_modificationFigure: // modificationFigure
        value.move< ModificationNode * > (that.value);
        break;

      case symbol_kind::S_instruction: // instruction
      case symbol_kind::S_expression: // expression
        value.move< Noeud * > (that.value);
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< float > (that.value);
        break;

      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_operation: // operation
        value.move< int > (that.value);
        break;

      case symbol_kind::S_attributsInline: // attributsInline
      case symbol_kind::S_attributsCSS: // attributsCSS
      case symbol_kind::S_attributs: // attributs
        value.move< std::map<std::string, std::string> > (that.value);
        break;

      case symbol_kind::S_attributAffectation: // attributAffectation
      case symbol_kind::S_setAttribut: // setAttribut
        value.move< std::pair<std::string, std::string> > (that.value);
        break;

      case symbol_kind::S_INT_TYPE: // INT_TYPE
      case symbol_kind::S_BOOL_TYPE: // BOOL_TYPE
      case symbol_kind::S_FLOAT_TYPE: // FLOAT_TYPE
      case symbol_kind::S_VARIABLE: // VARIABLE
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_HEXA_VALUE: // HEXA_VALUE
      case symbol_kind::S_COULEUR: // COULEUR
      case symbol_kind::S_ROTATION: // ROTATION
      case symbol_kind::S_REMPLISSAGE: // REMPLISSAGE
      case symbol_kind::S_OPACITE: // OPACITE
      case symbol_kind::S_EPAISSEUR: // EPAISSEUR
      case symbol_kind::S_pourcentage: // pourcentage
      case symbol_kind::S_chaine: // chaine
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_instructions: // instructions
        value.move< std::vector<Noeud *> > (that.value);
        break;

      case symbol_kind::S_stringComparator: // stringComparator
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
   Parser ::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
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
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
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
    YY_STACK_PRINT ();

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
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
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

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
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
      case symbol_kind::S_accesCouleurFigure: // accesCouleurFigure
        yylhs.value.emplace< AccesCouleurFigure * > ();
        break;

      case symbol_kind::S_accesFigure: // accesFigure
        yylhs.value.emplace< AccesFigureNode * > ();
        break;

      case symbol_kind::S_programme: // programme
      case symbol_kind::S_subProgramme: // subProgramme
        yylhs.value.emplace< ArbreSyntaxique > ();
        break;

      case symbol_kind::S_declarationCanva: // declarationCanva
        yylhs.value.emplace< CanevaNode * > ();
        break;

      case symbol_kind::S_carre: // carre
        yylhs.value.emplace< CarreNode * > ();
        break;

      case symbol_kind::S_condition: // condition
        yylhs.value.emplace< ConditionNode * > ();
        break;

      case symbol_kind::S_stringCondition: // stringCondition
        yylhs.value.emplace< CouleurConditionNode * > ();
        break;

      case symbol_kind::S_declarationVariable: // declarationVariable
        yylhs.value.emplace< DeclarationVariable * > ();
        break;

      case symbol_kind::S_declarationFigure: // declarationFigure
        yylhs.value.emplace< FigureNode * > ();
        break;

      case symbol_kind::S_if: // if
        yylhs.value.emplace< IfNode * > ();
        break;

      case symbol_kind::S_modificationFigure: // modificationFigure
        yylhs.value.emplace< ModificationNode * > ();
        break;

      case symbol_kind::S_instruction: // instruction
      case symbol_kind::S_expression: // expression
        yylhs.value.emplace< Noeud * > ();
        break;

      case symbol_kind::S_BOOL: // BOOL
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        yylhs.value.emplace< float > ();
        break;

      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_operation: // operation
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_attributsInline: // attributsInline
      case symbol_kind::S_attributsCSS: // attributsCSS
      case symbol_kind::S_attributs: // attributs
        yylhs.value.emplace< std::map<std::string, std::string> > ();
        break;

      case symbol_kind::S_attributAffectation: // attributAffectation
      case symbol_kind::S_setAttribut: // setAttribut
        yylhs.value.emplace< std::pair<std::string, std::string> > ();
        break;

      case symbol_kind::S_INT_TYPE: // INT_TYPE
      case symbol_kind::S_BOOL_TYPE: // BOOL_TYPE
      case symbol_kind::S_FLOAT_TYPE: // FLOAT_TYPE
      case symbol_kind::S_VARIABLE: // VARIABLE
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_HEXA_VALUE: // HEXA_VALUE
      case symbol_kind::S_COULEUR: // COULEUR
      case symbol_kind::S_ROTATION: // ROTATION
      case symbol_kind::S_REMPLISSAGE: // REMPLISSAGE
      case symbol_kind::S_OPACITE: // OPACITE
      case symbol_kind::S_EPAISSEUR: // EPAISSEUR
      case symbol_kind::S_pourcentage: // pourcentage
      case symbol_kind::S_chaine: // chaine
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_instructions: // instructions
        yylhs.value.emplace< std::vector<Noeud *> > ();
        break;

      case symbol_kind::S_stringComparator: // stringComparator
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
  case 2: // programme: subProgramme
#line 147 "parser/parser.yy"
                 {
        driver.analyseCode(yystack_[0].value.as < ArbreSyntaxique > ());
    }
#line 1323 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 3: // programme: SVG
#line 151 "parser/parser.yy"
          {

        YYACCEPT;
    }
#line 1332 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 4: // subProgramme: instruction NL subProgramme
#line 158 "parser/parser.yy"
                                {
        yystack_[0].value.as < ArbreSyntaxique > ().addNode(yystack_[2].value.as < Noeud * > ());
        yylhs.value.as < ArbreSyntaxique > () = yystack_[0].value.as < ArbreSyntaxique > ();
    }
#line 1341 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 5: // subProgramme: NL
#line 166 "parser/parser.yy"
       {

    }
#line 1349 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 6: // instructions: instruction NL instructions
#line 171 "parser/parser.yy"
                                {
        yystack_[0].value.as < std::vector<Noeud *> > ().push_back(yystack_[2].value.as < Noeud * > ());
        yylhs.value.as < std::vector<Noeud *> > () = yystack_[0].value.as < std::vector<Noeud *> > ();
    }
#line 1358 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 7: // instructions: %empty
#line 179 "parser/parser.yy"
    {

    }
#line 1366 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 8: // instruction: expression
#line 184 "parser/parser.yy"
                {
        yylhs.value.as < Noeud * > () = yystack_[0].value.as < Noeud * > ();
    }
#line 1374 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 9: // attributsInline: attributAffectation
#line 189 "parser/parser.yy"
                        {
        yylhs.value.as < std::map<std::string, std::string> > ()[yystack_[0].value.as < std::pair<std::string, std::string> > ().first] = yystack_[0].value.as < std::pair<std::string, std::string> > ().second;
    }
#line 1382 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 10: // attributsInline: attributsInline '&' attributAffectation
#line 195 "parser/parser.yy"
                                            {
        yystack_[2].value.as < std::map<std::string, std::string> > ()[yystack_[0].value.as < std::pair<std::string, std::string> > ().first] = yystack_[0].value.as < std::pair<std::string, std::string> > ().second;
        yylhs.value.as < std::map<std::string, std::string> > () = yystack_[2].value.as < std::map<std::string, std::string> > ();
    }
#line 1391 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 11: // attributsCSS: attributAffectation
#line 202 "parser/parser.yy"
                        {
        yylhs.value.as < std::map<std::string, std::string> > ()[yystack_[0].value.as < std::pair<std::string, std::string> > ().first] = yystack_[0].value.as < std::pair<std::string, std::string> > ().second;
    }
#line 1399 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 12: // attributsCSS: attributsCSS NL attributAffectation
#line 208 "parser/parser.yy"
                                        {
        yystack_[2].value.as < std::map<std::string, std::string> > ()[yystack_[0].value.as < std::pair<std::string, std::string> > ().first] = yystack_[0].value.as < std::pair<std::string, std::string> > ().second;
        yylhs.value.as < std::map<std::string, std::string> > () = yystack_[2].value.as < std::map<std::string, std::string> > ();
    }
#line 1408 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 13: // attributs: ';'
#line 214 "parser/parser.yy"
       {}
#line 1414 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 14: // attributs: '{' NL attributsCSS NL '}'
#line 218 "parser/parser.yy"
                               {
        yylhs.value.as < std::map<std::string, std::string> > () = yystack_[2].value.as < std::map<std::string, std::string> > ();
    }
#line 1422 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 15: // attributs: INLINE_AFFECTATION attributsInline ';'
#line 224 "parser/parser.yy"
                                           {
        yylhs.value.as < std::map<std::string, std::string> > () = yystack_[1].value.as < std::map<std::string, std::string> > ();
    }
#line 1430 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 16: // attributAffectation: COULEUR ':' HEXA_VALUE
#line 230 "parser/parser.yy"
                           {
        yylhs.value.as < std::pair<std::string, std::string> > () = std::make_pair(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ());
    }
#line 1438 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 17: // attributAffectation: ROTATION ':' operation
#line 236 "parser/parser.yy"
                           {
        yylhs.value.as < std::pair<std::string, std::string> > () = std::make_pair(yystack_[2].value.as < std::string > (), std::to_string(yystack_[0].value.as < int > ()));
    }
#line 1446 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 18: // attributAffectation: OPACITE ':' pourcentage
#line 242 "parser/parser.yy"
                            {
        yylhs.value.as < std::pair<std::string, std::string> > () = std::make_pair(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ());
    }
#line 1454 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 19: // attributAffectation: REMPLISSAGE ':' HEXA_VALUE
#line 248 "parser/parser.yy"
                                {
        yylhs.value.as < std::pair<std::string, std::string> > () = std::make_pair(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ());
    }
#line 1462 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 20: // attributAffectation: EPAISSEUR ':' operation
#line 254 "parser/parser.yy"
                            {
        yylhs.value.as < std::pair<std::string, std::string> > () = std::make_pair(yystack_[2].value.as < std::string > (), std::to_string(yystack_[0].value.as < int > ()));
    }
#line 1470 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 21: // expression: declarationCanva
#line 261 "parser/parser.yy"
                     { yylhs.value.as < Noeud * > () = yystack_[0].value.as < CanevaNode * > (); }
#line 1476 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 22: // expression: declarationFigure
#line 262 "parser/parser.yy"
                      { yylhs.value.as < Noeud * > () = yystack_[0].value.as < FigureNode * > (); }
#line 1482 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 23: // expression: accesFigure
#line 263 "parser/parser.yy"
                { yylhs.value.as < Noeud * > () = yystack_[0].value.as < AccesFigureNode * > (); }
#line 1488 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 24: // expression: modificationFigure
#line 264 "parser/parser.yy"
                       { yylhs.value.as < Noeud * > () = yystack_[0].value.as < ModificationNode * > (); }
#line 1494 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 25: // expression: declarationVariable
#line 265 "parser/parser.yy"
                        { yylhs.value.as < Noeud * > () = yystack_[0].value.as < DeclarationVariable * > (); }
#line 1500 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 26: // expression: if
#line 266 "parser/parser.yy"
       { yylhs.value.as < Noeud * > () = yystack_[0].value.as < IfNode * > (); }
#line 1506 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 27: // declarationCanva: TAILLE NUMBER NUMBER
#line 270 "parser/parser.yy"
                         {
        yylhs.value.as < CanevaNode * > () = new CanevaNode(yystack_[1].value.as < int > (), yystack_[0].value.as < int > ());
    }
#line 1514 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 28: // declarationFigure: carre
#line 276 "parser/parser.yy"
          {
        yylhs.value.as < FigureNode * > () = yystack_[0].value.as < CarreNode * > ();
    }
#line 1522 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 29: // carre: CARRE operation operation operation attributs
#line 282 "parser/parser.yy"
                                                  {
        CarreNode * carre = new CarreNode(yystack_[3].value.as < int > (), yystack_[2].value.as < int > (), yystack_[1].value.as < int > ());
        carre->setAttributs(yystack_[0].value.as < std::map<std::string, std::string> > ());
        yylhs.value.as < CarreNode * > () = carre;
    }
#line 1532 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 30: // accesFigure: CARRE '[' NUMBER ']'
#line 323 "parser/parser.yy"
                         {
        yylhs.value.as < AccesFigureNode * > () = new AccesIndexNode(FigureTypes::carre, yystack_[1].value.as < int > ());
    }
#line 1540 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 31: // accesFigure: VARIABLE
#line 329 "parser/parser.yy"
             {
        yylhs.value.as < AccesFigureNode * > () = new AccesVariableNode(yystack_[0].value.as < std::string > ());
    }
#line 1548 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 32: // setAttribut: COULEUR '=' HEXA_VALUE
#line 335 "parser/parser.yy"
                           {
        yylhs.value.as < std::pair<std::string, std::string> > () = std::make_pair(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ());
    }
#line 1556 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 33: // setAttribut: ROTATION '=' operation
#line 341 "parser/parser.yy"
                           {
        yylhs.value.as < std::pair<std::string, std::string> > () = std::make_pair(yystack_[2].value.as < std::string > (), std::to_string(yystack_[0].value.as < int > ()));
    }
#line 1564 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 34: // setAttribut: OPACITE '=' pourcentage
#line 347 "parser/parser.yy"
                            {
        yylhs.value.as < std::pair<std::string, std::string> > () = std::make_pair(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ());
    }
#line 1572 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 35: // setAttribut: REMPLISSAGE '=' HEXA_VALUE
#line 353 "parser/parser.yy"
                                {
        yylhs.value.as < std::pair<std::string, std::string> > () = std::make_pair(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ());
    }
#line 1580 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 36: // setAttribut: EPAISSEUR '=' operation
#line 359 "parser/parser.yy"
                            {
        yylhs.value.as < std::pair<std::string, std::string> > () = std::make_pair(yystack_[2].value.as < std::string > (), std::to_string(yystack_[0].value.as < int > ()));
    }
#line 1588 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 37: // modificationFigure: accesFigure '.' setAttribut
#line 365 "parser/parser.yy"
                               {
        yylhs.value.as < ModificationNode * > () = new ModificationNode(yystack_[2].value.as < AccesFigureNode * > (), yystack_[0].value.as < std::pair<std::string, std::string> > ().first, yystack_[0].value.as < std::pair<std::string, std::string> > ().second);
    }
#line 1596 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 38: // declarationVariable: VARIABLE affectation declarationFigure
#line 376 "parser/parser.yy"
                                           {
        yylhs.value.as < DeclarationVariable * > () = new DeclarationVariable(yystack_[2].value.as < std::string > (), yystack_[0].value.as < FigureNode * > ());
    }
#line 1604 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 39: // stringComparator: STRINGEQUAL
#line 389 "parser/parser.yy"
                { yylhs.value.as < string_operators > () = string_operators::equal; }
#line 1610 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 40: // stringComparator: STRINGNOTEQUAL
#line 390 "parser/parser.yy"
                   { yylhs.value.as < string_operators > () = string_operators::not_equal; }
#line 1616 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 41: // condition: stringCondition
#line 394 "parser/parser.yy"
                    {
        yylhs.value.as < ConditionNode * > () = yystack_[0].value.as < CouleurConditionNode * > ();
    }
#line 1624 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 42: // pourcentage: operation '%'
#line 404 "parser/parser.yy"
                 {
        yylhs.value.as < std::string > () = std::to_string(yystack_[1].value.as < int > ()) + '%';
    }
#line 1632 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 43: // chaine: HEXA_VALUE
#line 409 "parser/parser.yy"
    { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1638 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 44: // chaine: STRING
#line 409 "parser/parser.yy"
                 { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1644 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 45: // chaine: pourcentage
#line 409 "parser/parser.yy"
                          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1650 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 46: // accesCouleurFigure: accesFigure '.' COULEUR
#line 413 "parser/parser.yy"
                            {
        yylhs.value.as < AccesCouleurFigure * > () = new AccesCouleurFigure(yystack_[2].value.as < AccesFigureNode * > ());
    }
#line 1658 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 47: // stringCondition: accesCouleurFigure stringComparator chaine
#line 419 "parser/parser.yy"
                                               {
        yylhs.value.as < CouleurConditionNode * > () = new CouleurConditionNode(yystack_[2].value.as < AccesCouleurFigure * > (), yystack_[1].value.as < string_operators > (), yystack_[0].value.as < std::string > ());
    }
#line 1666 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 48: // if: SI '(' condition ')' ALORS '{' NL instructions '}'
#line 425 "parser/parser.yy"
                                                       {
        yylhs.value.as < IfNode * > () = new IfNode(yystack_[1].value.as < std::vector<Noeud *> > (), yystack_[6].value.as < ConditionNode * > ());
    }
#line 1674 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 49: // affectation: '='
#line 431 "parser/parser.yy"
        { 
    }
#line 1681 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 50: // operation: NUMBER
#line 435 "parser/parser.yy"
           {
        yylhs.value.as < int > () = yystack_[0].value.as < int > ();
    }
#line 1689 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 51: // operation: '(' operation ')'
#line 438 "parser/parser.yy"
                        {
        yylhs.value.as < int > () = yystack_[1].value.as < int > ();
    }
#line 1697 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 52: // operation: operation '+' operation
#line 441 "parser/parser.yy"
                              {
        yylhs.value.as < int > () = yystack_[2].value.as < int > () + yystack_[0].value.as < int > ();
    }
#line 1705 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 53: // operation: operation '-' operation
#line 444 "parser/parser.yy"
                              {
        yylhs.value.as < int > () = yystack_[2].value.as < int > () - yystack_[0].value.as < int > ();
    }
#line 1713 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 54: // operation: operation '*' operation
#line 447 "parser/parser.yy"
                              {
        yylhs.value.as < int > () = yystack_[2].value.as < int > () * yystack_[0].value.as < int > ();
    }
#line 1721 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 55: // operation: operation '/' operation
#line 450 "parser/parser.yy"
                              {
        yylhs.value.as < int > () = yystack_[2].value.as < int > () / yystack_[0].value.as < int > ();
    }
#line 1729 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;

  case 56: // operation: '-' operation
#line 453 "parser/parser.yy"
                              {
        yylhs.value.as < int > () = - yystack_[0].value.as < int > ();
    }
#line 1737 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"
    break;


#line 1741 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"

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
        std::string msg = YY_("syntax error");
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
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
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
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
    {
      stack_symbol_type error_token;

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
    YY_STACK_PRINT ();
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

#if YYDEBUG || 0
  const char *
   Parser ::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0





  const signed char  Parser ::yypact_ninf_ = -92;

  const signed char  Parser ::yytable_ninf_ = -54;

  const short
   Parser ::yypact_[] =
  {
      49,   -92,   -52,   -48,    12,     4,   -92,    19,   -92,    24,
     -92,   -92,   -92,   -92,   -23,   -92,   -92,   -92,   -92,    15,
      -7,    48,   -92,     5,    50,     5,    -3,   -92,    76,   101,
       5,   -92,   -92,     3,    -2,     7,   -18,   -92,   -92,   -92,
      25,    27,     5,     5,     5,     5,    -3,   -92,    23,    29,
      32,    34,    35,   -92,    66,    62,   -92,   -92,     1,     5,
     -92,   -92,     2,   -25,   -92,   -92,    55,    79,     5,    80,
       5,     5,   -92,    46,   -92,   -92,   -92,   -92,    68,   -25,
     106,   -92,   102,   -92,   -92,    83,   -92,   -92,    83,   105,
     -92,    57,    78,    81,    82,    84,    26,   -92,   106,   -10,
      89,     5,    94,     5,     5,   106,   -92,   130,   -92,    86,
     131,   -92,    83,   -92,   -92,    83,   -92,    14,   -92,   -10,
     -92,   -92,   -92
  };

  const signed char
   Parser ::yydefact_[] =
  {
       0,     5,    31,     0,     0,     0,     3,     0,     2,     0,
       8,    21,    22,    28,    23,    24,    25,    26,    49,     0,
       0,     0,    50,     0,     0,     0,     0,     1,     0,     0,
       0,    38,    31,     0,     0,     0,     0,    41,    27,    56,
       0,     0,     0,     0,     0,     0,     0,     4,     0,     0,
       0,     0,     0,    37,     0,     0,    39,    40,     0,     0,
      30,    51,    56,    52,    54,    55,     0,     0,     0,     0,
       0,     0,    46,     0,    44,    43,    45,    47,     0,    53,
       0,    13,     0,    29,    32,    33,    35,    34,    36,     0,
      42,     0,     0,     0,     0,     0,     0,     9,     0,     7,
       0,     0,     0,     0,     0,     0,    15,     0,    11,     0,
       0,    16,    17,    19,    18,    20,    10,     0,    48,     7,
      14,    12,     6
  };

  const signed char
   Parser ::yypgoto_[] =
  {
     -92,   -92,   109,    21,   -91,   -92,   -92,   -92,   -27,   -92,
     -92,   122,   -92,   123,   -92,   -92,   -92,   -92,   -92,   -67,
     -92,   -92,   -92,   -92,   -92,    -5
  };

  const signed char
   Parser ::yydefgoto_[] =
  {
       0,     7,     8,   109,     9,    96,   107,    83,    97,    10,
      11,    12,    13,    14,    53,    15,    16,    58,    35,    76,
      77,    36,    37,    17,    19,    78
  };

  const signed char
   Parser ::yytable_[] =
  {
      26,     2,    22,    87,    32,    18,    22,   -53,   110,    22,
      22,     3,    20,    74,    56,    57,    75,    21,    39,    27,
      41,    46,    44,    45,     4,    26,     5,    28,   110,    33,
      91,    92,    93,    94,    95,    29,   114,    62,    63,    64,
      65,    66,    42,    43,    44,    45,    23,   -53,   -53,    23,
      23,    30,     1,    38,    79,    40,    54,    25,    24,    24,
       2,    25,   -53,    85,    25,    25,    88,   120,    55,    80,
       3,   108,    59,    43,    44,    45,   105,   106,   116,     1,
      67,    60,    72,     4,    73,     5,    68,     2,    61,    69,
     121,    70,    71,     6,    84,    86,   112,     3,    89,   115,
      59,    43,    44,    45,   111,    98,    81,    82,    99,   113,
       4,   100,     5,    59,    43,    44,    45,    48,    49,    50,
      51,    52,    91,    92,    93,    94,    95,    90,    59,    43,
      44,    45,   101,   117,   119,   102,   103,    47,   104,   118,
     122,    31,     0,    34
  };

  const signed char
   Parser ::yycheck_[] =
  {
       5,    11,     5,    70,    11,    57,     5,     5,    99,     5,
       5,    21,    60,    12,    32,    33,    15,     5,    23,     0,
      25,    26,    47,    48,    34,    30,    36,     3,   119,    36,
      16,    17,    18,    19,    20,    58,   103,    42,    43,    44,
      45,    46,    45,    46,    47,    48,    45,    45,    46,    45,
      45,    36,     3,     5,    59,     5,    58,    60,    55,    55,
      11,    60,    60,    68,    60,    60,    71,    53,    61,    14,
      21,    98,    45,    46,    47,    48,    50,    51,   105,     3,
      57,    56,    16,    34,    22,    36,    57,    11,    61,    57,
     117,    57,    57,    44,    15,    15,   101,    21,    52,   104,
      45,    46,    47,    48,    15,     3,    51,    52,     3,    15,
      34,    54,    36,    45,    46,    47,    48,    16,    17,    18,
      19,    20,    16,    17,    18,    19,    20,    59,    45,    46,
      47,    48,    54,     3,     3,    54,    54,    28,    54,    53,
     119,    19,    -1,    20
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,     3,    11,    21,    34,    36,    44,    63,    64,    66,
      71,    72,    73,    74,    75,    77,    78,    85,    57,    86,
      60,     5,     5,    45,    55,    60,    87,     0,     3,    58,
      36,    73,    11,    36,    75,    80,    83,    84,     5,    87,
       5,    87,    45,    46,    47,    48,    87,    64,    16,    17,
      18,    19,    20,    76,    58,    61,    32,    33,    79,    45,
      56,    61,    87,    87,    87,    87,    87,    57,    57,    57,
      57,    57,    16,    22,    12,    15,    81,    82,    87,    87,
      14,    51,    52,    69,    15,    87,    15,    81,    87,    52,
      59,    16,    17,    18,    19,    20,    67,    70,     3,     3,
      54,    54,    54,    54,    54,    50,    51,    68,    70,    65,
      66,    15,    87,    15,    81,    87,    70,     3,    53,     3,
      53,    70,    65
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    62,    63,    63,    64,    64,    65,    65,    66,    67,
      67,    68,    68,    69,    69,    69,    70,    70,    70,    70,
      70,    71,    71,    71,    71,    71,    71,    72,    73,    74,
      75,    75,    76,    76,    76,    76,    76,    77,    78,    79,
      79,    80,    81,    82,    82,    82,    83,    84,    85,    86,
      87,    87,    87,    87,    87,    87,    87
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     1,     1,     3,     1,     3,     0,     1,     1,
       3,     1,     3,     1,     5,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     3,     1,     5,
       4,     1,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     2,     1,     1,     1,     3,     3,     9,     1,
       1,     3,     3,     3,     3,     3,     2
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const  Parser ::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "NL", "END", "NUMBER",
  "FLOAT", "BOOL", "INT_TYPE", "BOOL_TYPE", "FLOAT_TYPE", "VARIABLE",
  "STRING", "ATTRIBUT", "INLINE_AFFECTATION", "HEXA_VALUE", "COULEUR",
  "ROTATION", "REMPLISSAGE", "OPACITE", "EPAISSEUR", "SI", "ALORS",
  "SINON", "REPETE", "FOIS", "EQUAL", "NOTEQUAL", "LESS", "LESSEQUAL",
  "GREATER", "GREATEREQUAL", "STRINGEQUAL", "STRINGNOTEQUAL", "TAILLE",
  "RECTANGLE", "CARRE", "TRIANGLE", "CERCLE", "ELLIPSE", "LIGNE", "CHEMIN",
  "TEXTE", "STOP", "SVG", "'-'", "'+'", "'*'", "'/'", "NEG", "'&'", "';'",
  "'{'", "'}'", "':'", "'['", "']'", "'='", "'.'", "'%'", "'('", "')'",
  "$accept", "programme", "subProgramme", "instructions", "instruction",
  "attributsInline", "attributsCSS", "attributs", "attributAffectation",
  "expression", "declarationCanva", "declarationFigure", "carre",
  "accesFigure", "setAttribut", "modificationFigure",
  "declarationVariable", "stringComparator", "condition", "pourcentage",
  "chaine", "accesCouleurFigure", "stringCondition", "if", "affectation",
  "operation", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   147,   147,   151,   158,   166,   171,   179,   184,   189,
     195,   202,   208,   214,   218,   224,   230,   236,   242,   248,
     254,   261,   262,   263,   264,   265,   266,   270,   276,   282,
     323,   329,   335,   341,   347,   353,   359,   365,   376,   389,
     390,   394,   404,   409,   409,   409,   413,   419,   425,   431,
     435,   438,   441,   444,   447,   450,   453
  };

  void
   Parser ::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
   Parser ::yy_reduce_print_ (int yyrule) const
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

   Parser ::symbol_kind_type
   Parser ::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    59,    50,     2,
      60,    61,    47,    46,     2,    45,    58,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    54,    51,
       2,    57,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,    53,     2,     2,     2,     2,
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
      49
    };
    // Last valid token kind.
    const int code_max = 300;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 2185 "/home/etud/Bureau/projet_theorie/dessin/build/parser.cpp"

#line 468 "parser/parser.yy"


void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
