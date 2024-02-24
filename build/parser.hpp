// A Bison parser, made by GNU Bison 3.7.5.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file /home/etud/Bureau/projet_theorie/dessin/build/parser.hpp
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_HOME_ETUD_BUREAU_PROJET_THEORIE_DESSIN_BUILD_PARSER_HPP_INCLUDED
# define YY_YY_HOME_ETUD_BUREAU_PROJET_THEORIE_DESSIN_BUILD_PARSER_HPP_INCLUDED
// "%code requires" blocks.
#line 11 "parser/parser.yy"

    #include "contexte.hh"
    #include "expressionBinaire.hh"
    #include "expressionUnaire.hh"
    #include "constante.hh"
    #include "variable.hh"
    #include "figure.hh"
    #include "noeud.hh"

    class Scanner;
    class Driver;

#line 62 "/home/etud/Bureau/projet_theorie/dessin/build/parser.hpp"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"
#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

namespace yy {
#line 196 "/home/etud/Bureau/projet_theorie/dessin/build/parser.hpp"




  /// A Bison parser.
  class  Parser 
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    semantic_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    semantic_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // accesCouleurFigure
      char dummy1[sizeof (AccesCouleurFigure *)];

      // accesFigure
      char dummy2[sizeof (AccesFigureNode *)];

      // programme
      // subProgramme
      char dummy3[sizeof (ArbreSyntaxique)];

      // declarationCanva
      char dummy4[sizeof (CanevaNode *)];

      // carre
      char dummy5[sizeof (CarreNode *)];

      // condition
      char dummy6[sizeof (ConditionNode *)];

      // stringCondition
      char dummy7[sizeof (CouleurConditionNode *)];

      // declarationVariable
      char dummy8[sizeof (DeclarationVariable *)];

      // declarationFigure
      char dummy9[sizeof (FigureNode *)];

      // if
      char dummy10[sizeof (IfNode *)];

      // modificationFigure
      char dummy11[sizeof (ModificationNode *)];

      // instruction
      // expression
      char dummy12[sizeof (Noeud *)];

      // BOOL
      char dummy13[sizeof (bool)];

      // FLOAT
      char dummy14[sizeof (float)];

      // NUMBER
      // operation
      char dummy15[sizeof (int)];

      // attributsInline
      // attributsCSS
      // attributs
      char dummy16[sizeof (std::map<std::string, std::string>)];

      // attributAffectation
      // setAttribut
      char dummy17[sizeof (std::pair<std::string, std::string>)];

      // INT_TYPE
      // BOOL_TYPE
      // FLOAT_TYPE
      // VARIABLE
      // STRING
      // HEXA_VALUE
      // COULEUR
      // ROTATION
      // REMPLISSAGE
      // OPACITE
      // EPAISSEUR
      // pourcentage
      // chaine
      char dummy18[sizeof (std::string)];

      // instructions
      char dummy19[sizeof (std::vector<Noeud *>)];

      // stringComparator
      char dummy20[sizeof (string_operators)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    YYEOF = 0,                     // "end of file"
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    NL = 258,                      // NL
    END = 259,                     // END
    NUMBER = 260,                  // NUMBER
    FLOAT = 261,                   // FLOAT
    BOOL = 262,                    // BOOL
    INT_TYPE = 263,                // INT_TYPE
    BOOL_TYPE = 264,               // BOOL_TYPE
    FLOAT_TYPE = 265,              // FLOAT_TYPE
    VARIABLE = 266,                // VARIABLE
    STRING = 267,                  // STRING
    ATTRIBUT = 268,                // ATTRIBUT
    INLINE_AFFECTATION = 269,      // INLINE_AFFECTATION
    HEXA_VALUE = 270,              // HEXA_VALUE
    COULEUR = 271,                 // COULEUR
    ROTATION = 272,                // ROTATION
    REMPLISSAGE = 273,             // REMPLISSAGE
    OPACITE = 274,                 // OPACITE
    EPAISSEUR = 275,               // EPAISSEUR
    SI = 276,                      // SI
    ALORS = 277,                   // ALORS
    SINON = 278,                   // SINON
    REPETE = 279,                  // REPETE
    FOIS = 280,                    // FOIS
    EQUAL = 281,                   // EQUAL
    NOTEQUAL = 282,                // NOTEQUAL
    LESS = 283,                    // LESS
    LESSEQUAL = 284,               // LESSEQUAL
    GREATER = 285,                 // GREATER
    GREATEREQUAL = 286,            // GREATEREQUAL
    STRINGEQUAL = 287,             // STRINGEQUAL
    STRINGNOTEQUAL = 288,          // STRINGNOTEQUAL
    TAILLE = 289,                  // TAILLE
    RECTANGLE = 290,               // RECTANGLE
    CARRE = 291,                   // CARRE
    TRIANGLE = 292,                // TRIANGLE
    CERCLE = 293,                  // CERCLE
    ELLIPSE = 294,                 // ELLIPSE
    LIGNE = 295,                   // LIGNE
    CHEMIN = 296,                  // CHEMIN
    TEXTE = 297,                   // TEXTE
    STOP = 298,                    // STOP
    SVG = 299,                     // SVG
    NEG = 300                      // NEG
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::yytokentype token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 62, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_NL = 3,                                // NL
        S_END = 4,                               // END
        S_NUMBER = 5,                            // NUMBER
        S_FLOAT = 6,                             // FLOAT
        S_BOOL = 7,                              // BOOL
        S_INT_TYPE = 8,                          // INT_TYPE
        S_BOOL_TYPE = 9,                         // BOOL_TYPE
        S_FLOAT_TYPE = 10,                       // FLOAT_TYPE
        S_VARIABLE = 11,                         // VARIABLE
        S_STRING = 12,                           // STRING
        S_ATTRIBUT = 13,                         // ATTRIBUT
        S_INLINE_AFFECTATION = 14,               // INLINE_AFFECTATION
        S_HEXA_VALUE = 15,                       // HEXA_VALUE
        S_COULEUR = 16,                          // COULEUR
        S_ROTATION = 17,                         // ROTATION
        S_REMPLISSAGE = 18,                      // REMPLISSAGE
        S_OPACITE = 19,                          // OPACITE
        S_EPAISSEUR = 20,                        // EPAISSEUR
        S_SI = 21,                               // SI
        S_ALORS = 22,                            // ALORS
        S_SINON = 23,                            // SINON
        S_REPETE = 24,                           // REPETE
        S_FOIS = 25,                             // FOIS
        S_EQUAL = 26,                            // EQUAL
        S_NOTEQUAL = 27,                         // NOTEQUAL
        S_LESS = 28,                             // LESS
        S_LESSEQUAL = 29,                        // LESSEQUAL
        S_GREATER = 30,                          // GREATER
        S_GREATEREQUAL = 31,                     // GREATEREQUAL
        S_STRINGEQUAL = 32,                      // STRINGEQUAL
        S_STRINGNOTEQUAL = 33,                   // STRINGNOTEQUAL
        S_TAILLE = 34,                           // TAILLE
        S_RECTANGLE = 35,                        // RECTANGLE
        S_CARRE = 36,                            // CARRE
        S_TRIANGLE = 37,                         // TRIANGLE
        S_CERCLE = 38,                           // CERCLE
        S_ELLIPSE = 39,                          // ELLIPSE
        S_LIGNE = 40,                            // LIGNE
        S_CHEMIN = 41,                           // CHEMIN
        S_TEXTE = 42,                            // TEXTE
        S_STOP = 43,                             // STOP
        S_SVG = 44,                              // SVG
        S_45_ = 45,                              // '-'
        S_46_ = 46,                              // '+'
        S_47_ = 47,                              // '*'
        S_48_ = 48,                              // '/'
        S_NEG = 49,                              // NEG
        S_50_ = 50,                              // '&'
        S_51_ = 51,                              // ';'
        S_52_ = 52,                              // '{'
        S_53_ = 53,                              // '}'
        S_54_ = 54,                              // ':'
        S_55_ = 55,                              // '['
        S_56_ = 56,                              // ']'
        S_57_ = 57,                              // '='
        S_58_ = 58,                              // '.'
        S_59_ = 59,                              // '%'
        S_60_ = 60,                              // '('
        S_61_ = 61,                              // ')'
        S_YYACCEPT = 62,                         // $accept
        S_programme = 63,                        // programme
        S_subProgramme = 64,                     // subProgramme
        S_instructions = 65,                     // instructions
        S_instruction = 66,                      // instruction
        S_attributsInline = 67,                  // attributsInline
        S_attributsCSS = 68,                     // attributsCSS
        S_attributs = 69,                        // attributs
        S_attributAffectation = 70,              // attributAffectation
        S_expression = 71,                       // expression
        S_declarationCanva = 72,                 // declarationCanva
        S_declarationFigure = 73,                // declarationFigure
        S_carre = 74,                            // carre
        S_accesFigure = 75,                      // accesFigure
        S_setAttribut = 76,                      // setAttribut
        S_modificationFigure = 77,               // modificationFigure
        S_declarationVariable = 78,              // declarationVariable
        S_stringComparator = 79,                 // stringComparator
        S_condition = 80,                        // condition
        S_pourcentage = 81,                      // pourcentage
        S_chaine = 82,                           // chaine
        S_accesCouleurFigure = 83,               // accesCouleurFigure
        S_stringCondition = 84,                  // stringCondition
        S_if = 85,                               // if
        S_affectation = 86,                      // affectation
        S_operation = 87                         // operation
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_accesCouleurFigure: // accesCouleurFigure
        value.move< AccesCouleurFigure * > (std::move (that.value));
        break;

      case symbol_kind::S_accesFigure: // accesFigure
        value.move< AccesFigureNode * > (std::move (that.value));
        break;

      case symbol_kind::S_programme: // programme
      case symbol_kind::S_subProgramme: // subProgramme
        value.move< ArbreSyntaxique > (std::move (that.value));
        break;

      case symbol_kind::S_declarationCanva: // declarationCanva
        value.move< CanevaNode * > (std::move (that.value));
        break;

      case symbol_kind::S_carre: // carre
        value.move< CarreNode * > (std::move (that.value));
        break;

      case symbol_kind::S_condition: // condition
        value.move< ConditionNode * > (std::move (that.value));
        break;

      case symbol_kind::S_stringCondition: // stringCondition
        value.move< CouleurConditionNode * > (std::move (that.value));
        break;

      case symbol_kind::S_declarationVariable: // declarationVariable
        value.move< DeclarationVariable * > (std::move (that.value));
        break;

      case symbol_kind::S_declarationFigure: // declarationFigure
        value.move< FigureNode * > (std::move (that.value));
        break;

      case symbol_kind::S_if: // if
        value.move< IfNode * > (std::move (that.value));
        break;

      case symbol_kind::S_modificationFigure: // modificationFigure
        value.move< ModificationNode * > (std::move (that.value));
        break;

      case symbol_kind::S_instruction: // instruction
      case symbol_kind::S_expression: // expression
        value.move< Noeud * > (std::move (that.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.move< bool > (std::move (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< float > (std::move (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_operation: // operation
        value.move< int > (std::move (that.value));
        break;

      case symbol_kind::S_attributsInline: // attributsInline
      case symbol_kind::S_attributsCSS: // attributsCSS
      case symbol_kind::S_attributs: // attributs
        value.move< std::map<std::string, std::string> > (std::move (that.value));
        break;

      case symbol_kind::S_attributAffectation: // attributAffectation
      case symbol_kind::S_setAttribut: // setAttribut
        value.move< std::pair<std::string, std::string> > (std::move (that.value));
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
        value.move< std::string > (std::move (that.value));
        break;

      case symbol_kind::S_instructions: // instructions
        value.move< std::vector<Noeud *> > (std::move (that.value));
        break;

      case symbol_kind::S_stringComparator: // stringComparator
        value.move< string_operators > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AccesCouleurFigure *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AccesCouleurFigure *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AccesFigureNode *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AccesFigureNode *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ArbreSyntaxique&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ArbreSyntaxique& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, CanevaNode *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const CanevaNode *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, CarreNode *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const CarreNode *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ConditionNode *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ConditionNode *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, CouleurConditionNode *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const CouleurConditionNode *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, DeclarationVariable *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const DeclarationVariable *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, FigureNode *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const FigureNode *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IfNode *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IfNode *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ModificationNode *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ModificationNode *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Noeud *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Noeud *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, bool&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const bool& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, float&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const float& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::map<std::string, std::string>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::map<std::string, std::string>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::pair<std::string, std::string>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::pair<std::string, std::string>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<Noeud *>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<Noeud *>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, string_operators&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const string_operators& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_accesCouleurFigure: // accesCouleurFigure
        value.template destroy< AccesCouleurFigure * > ();
        break;

      case symbol_kind::S_accesFigure: // accesFigure
        value.template destroy< AccesFigureNode * > ();
        break;

      case symbol_kind::S_programme: // programme
      case symbol_kind::S_subProgramme: // subProgramme
        value.template destroy< ArbreSyntaxique > ();
        break;

      case symbol_kind::S_declarationCanva: // declarationCanva
        value.template destroy< CanevaNode * > ();
        break;

      case symbol_kind::S_carre: // carre
        value.template destroy< CarreNode * > ();
        break;

      case symbol_kind::S_condition: // condition
        value.template destroy< ConditionNode * > ();
        break;

      case symbol_kind::S_stringCondition: // stringCondition
        value.template destroy< CouleurConditionNode * > ();
        break;

      case symbol_kind::S_declarationVariable: // declarationVariable
        value.template destroy< DeclarationVariable * > ();
        break;

      case symbol_kind::S_declarationFigure: // declarationFigure
        value.template destroy< FigureNode * > ();
        break;

      case symbol_kind::S_if: // if
        value.template destroy< IfNode * > ();
        break;

      case symbol_kind::S_modificationFigure: // modificationFigure
        value.template destroy< ModificationNode * > ();
        break;

      case symbol_kind::S_instruction: // instruction
      case symbol_kind::S_expression: // expression
        value.template destroy< Noeud * > ();
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.template destroy< bool > ();
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.template destroy< float > ();
        break;

      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_operation: // operation
        value.template destroy< int > ();
        break;

      case symbol_kind::S_attributsInline: // attributsInline
      case symbol_kind::S_attributsCSS: // attributsCSS
      case symbol_kind::S_attributs: // attributs
        value.template destroy< std::map<std::string, std::string> > ();
        break;

      case symbol_kind::S_attributAffectation: // attributAffectation
      case symbol_kind::S_setAttribut: // setAttribut
        value.template destroy< std::pair<std::string, std::string> > ();
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
        value.template destroy< std::string > ();
        break;

      case symbol_kind::S_instructions: // instructions
        value.template destroy< std::vector<Noeud *> > ();
        break;

      case symbol_kind::S_stringComparator: // stringComparator
        value.template destroy< string_operators > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

#if YYDEBUG || 0
      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return  Parser ::symbol_name (this->kind ());
      }
#endif // #if YYDEBUG || 0


      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// Default constructor.
      by_kind ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that);
#endif

      /// Copy constructor.
      by_kind (const by_kind& that);

      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t);

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
#endif
      {
        YY_ASSERT (tok == token::YYEOF
                   || (token::YYerror <= tok && tok <= token::END)
                   || (token::ATTRIBUT <= tok && tok <= token::INLINE_AFFECTATION)
                   || (token::SI <= tok && tok <= token::SVG)
                   || tok == 45
                   || tok == 43
                   || tok == 42
                   || tok == 47
                   || tok == token::NEG
                   || tok == 38
                   || tok == 59
                   || tok == 123
                   || tok == 125
                   || tok == 58
                   || tok == 91
                   || tok == 93
                   || tok == 61
                   || tok == 46
                   || tok == 37
                   || (40 <= tok && tok <= 41));
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, bool v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const bool& v, const location_type& l)
        : super_type(token_type (tok), v, l)
#endif
      {
        YY_ASSERT (tok == token::BOOL);
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, float v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const float& v, const location_type& l)
        : super_type(token_type (tok), v, l)
#endif
      {
        YY_ASSERT (tok == token::FLOAT);
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, int v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const int& v, const location_type& l)
        : super_type(token_type (tok), v, l)
#endif
      {
        YY_ASSERT (tok == token::NUMBER);
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type(token_type (tok), v, l)
#endif
      {
        YY_ASSERT ((token::INT_TYPE <= tok && tok <= token::STRING)
                   || (token::HEXA_VALUE <= tok && tok <= token::EPAISSEUR));
      }
    };

    /// Build a parser object.
     Parser  (Scanner &scanner_yyarg, Driver &driver_yyarg);
    virtual ~ Parser  ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
     Parser  (const  Parser &) = delete;
    /// Non copyable.
     Parser & operator= (const  Parser &) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

#if YYDEBUG || 0
    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);
#endif // #if YYDEBUG || 0


    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYEOF (location_type l)
      {
        return symbol_type (token::YYEOF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYEOF (const location_type& l)
      {
        return symbol_type (token::YYEOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NL (location_type l)
      {
        return symbol_type (token::NL, std::move (l));
      }
#else
      static
      symbol_type
      make_NL (const location_type& l)
      {
        return symbol_type (token::NL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END (location_type l)
      {
        return symbol_type (token::END, std::move (l));
      }
#else
      static
      symbol_type
      make_END (const location_type& l)
      {
        return symbol_type (token::END, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUMBER (int v, location_type l)
      {
        return symbol_type (token::NUMBER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NUMBER (const int& v, const location_type& l)
      {
        return symbol_type (token::NUMBER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLOAT (float v, location_type l)
      {
        return symbol_type (token::FLOAT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FLOAT (const float& v, const location_type& l)
      {
        return symbol_type (token::FLOAT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOL (bool v, location_type l)
      {
        return symbol_type (token::BOOL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BOOL (const bool& v, const location_type& l)
      {
        return symbol_type (token::BOOL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT_TYPE (std::string v, location_type l)
      {
        return symbol_type (token::INT_TYPE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INT_TYPE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::INT_TYPE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOL_TYPE (std::string v, location_type l)
      {
        return symbol_type (token::BOOL_TYPE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BOOL_TYPE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::BOOL_TYPE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLOAT_TYPE (std::string v, location_type l)
      {
        return symbol_type (token::FLOAT_TYPE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FLOAT_TYPE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FLOAT_TYPE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VARIABLE (std::string v, location_type l)
      {
        return symbol_type (token::VARIABLE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_VARIABLE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::VARIABLE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING (std::string v, location_type l)
      {
        return symbol_type (token::STRING, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING (const std::string& v, const location_type& l)
      {
        return symbol_type (token::STRING, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ATTRIBUT (location_type l)
      {
        return symbol_type (token::ATTRIBUT, std::move (l));
      }
#else
      static
      symbol_type
      make_ATTRIBUT (const location_type& l)
      {
        return symbol_type (token::ATTRIBUT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INLINE_AFFECTATION (location_type l)
      {
        return symbol_type (token::INLINE_AFFECTATION, std::move (l));
      }
#else
      static
      symbol_type
      make_INLINE_AFFECTATION (const location_type& l)
      {
        return symbol_type (token::INLINE_AFFECTATION, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HEXA_VALUE (std::string v, location_type l)
      {
        return symbol_type (token::HEXA_VALUE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_HEXA_VALUE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::HEXA_VALUE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COULEUR (std::string v, location_type l)
      {
        return symbol_type (token::COULEUR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_COULEUR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::COULEUR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ROTATION (std::string v, location_type l)
      {
        return symbol_type (token::ROTATION, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ROTATION (const std::string& v, const location_type& l)
      {
        return symbol_type (token::ROTATION, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REMPLISSAGE (std::string v, location_type l)
      {
        return symbol_type (token::REMPLISSAGE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_REMPLISSAGE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::REMPLISSAGE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPACITE (std::string v, location_type l)
      {
        return symbol_type (token::OPACITE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_OPACITE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::OPACITE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EPAISSEUR (std::string v, location_type l)
      {
        return symbol_type (token::EPAISSEUR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EPAISSEUR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::EPAISSEUR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SI (location_type l)
      {
        return symbol_type (token::SI, std::move (l));
      }
#else
      static
      symbol_type
      make_SI (const location_type& l)
      {
        return symbol_type (token::SI, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ALORS (location_type l)
      {
        return symbol_type (token::ALORS, std::move (l));
      }
#else
      static
      symbol_type
      make_ALORS (const location_type& l)
      {
        return symbol_type (token::ALORS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SINON (location_type l)
      {
        return symbol_type (token::SINON, std::move (l));
      }
#else
      static
      symbol_type
      make_SINON (const location_type& l)
      {
        return symbol_type (token::SINON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REPETE (location_type l)
      {
        return symbol_type (token::REPETE, std::move (l));
      }
#else
      static
      symbol_type
      make_REPETE (const location_type& l)
      {
        return symbol_type (token::REPETE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FOIS (location_type l)
      {
        return symbol_type (token::FOIS, std::move (l));
      }
#else
      static
      symbol_type
      make_FOIS (const location_type& l)
      {
        return symbol_type (token::FOIS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQUAL (location_type l)
      {
        return symbol_type (token::EQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_EQUAL (const location_type& l)
      {
        return symbol_type (token::EQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOTEQUAL (location_type l)
      {
        return symbol_type (token::NOTEQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_NOTEQUAL (const location_type& l)
      {
        return symbol_type (token::NOTEQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LESS (location_type l)
      {
        return symbol_type (token::LESS, std::move (l));
      }
#else
      static
      symbol_type
      make_LESS (const location_type& l)
      {
        return symbol_type (token::LESS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LESSEQUAL (location_type l)
      {
        return symbol_type (token::LESSEQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_LESSEQUAL (const location_type& l)
      {
        return symbol_type (token::LESSEQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GREATER (location_type l)
      {
        return symbol_type (token::GREATER, std::move (l));
      }
#else
      static
      symbol_type
      make_GREATER (const location_type& l)
      {
        return symbol_type (token::GREATER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GREATEREQUAL (location_type l)
      {
        return symbol_type (token::GREATEREQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_GREATEREQUAL (const location_type& l)
      {
        return symbol_type (token::GREATEREQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRINGEQUAL (location_type l)
      {
        return symbol_type (token::STRINGEQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_STRINGEQUAL (const location_type& l)
      {
        return symbol_type (token::STRINGEQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRINGNOTEQUAL (location_type l)
      {
        return symbol_type (token::STRINGNOTEQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_STRINGNOTEQUAL (const location_type& l)
      {
        return symbol_type (token::STRINGNOTEQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TAILLE (location_type l)
      {
        return symbol_type (token::TAILLE, std::move (l));
      }
#else
      static
      symbol_type
      make_TAILLE (const location_type& l)
      {
        return symbol_type (token::TAILLE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RECTANGLE (location_type l)
      {
        return symbol_type (token::RECTANGLE, std::move (l));
      }
#else
      static
      symbol_type
      make_RECTANGLE (const location_type& l)
      {
        return symbol_type (token::RECTANGLE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CARRE (location_type l)
      {
        return symbol_type (token::CARRE, std::move (l));
      }
#else
      static
      symbol_type
      make_CARRE (const location_type& l)
      {
        return symbol_type (token::CARRE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRIANGLE (location_type l)
      {
        return symbol_type (token::TRIANGLE, std::move (l));
      }
#else
      static
      symbol_type
      make_TRIANGLE (const location_type& l)
      {
        return symbol_type (token::TRIANGLE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CERCLE (location_type l)
      {
        return symbol_type (token::CERCLE, std::move (l));
      }
#else
      static
      symbol_type
      make_CERCLE (const location_type& l)
      {
        return symbol_type (token::CERCLE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELLIPSE (location_type l)
      {
        return symbol_type (token::ELLIPSE, std::move (l));
      }
#else
      static
      symbol_type
      make_ELLIPSE (const location_type& l)
      {
        return symbol_type (token::ELLIPSE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LIGNE (location_type l)
      {
        return symbol_type (token::LIGNE, std::move (l));
      }
#else
      static
      symbol_type
      make_LIGNE (const location_type& l)
      {
        return symbol_type (token::LIGNE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHEMIN (location_type l)
      {
        return symbol_type (token::CHEMIN, std::move (l));
      }
#else
      static
      symbol_type
      make_CHEMIN (const location_type& l)
      {
        return symbol_type (token::CHEMIN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TEXTE (location_type l)
      {
        return symbol_type (token::TEXTE, std::move (l));
      }
#else
      static
      symbol_type
      make_TEXTE (const location_type& l)
      {
        return symbol_type (token::TEXTE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STOP (location_type l)
      {
        return symbol_type (token::STOP, std::move (l));
      }
#else
      static
      symbol_type
      make_STOP (const location_type& l)
      {
        return symbol_type (token::STOP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SVG (location_type l)
      {
        return symbol_type (token::SVG, std::move (l));
      }
#else
      static
      symbol_type
      make_SVG (const location_type& l)
      {
        return symbol_type (token::SVG, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEG (location_type l)
      {
        return symbol_type (token::NEG, std::move (l));
      }
#else
      static
      symbol_type
      make_NEG (const location_type& l)
      {
        return symbol_type (token::NEG, l);
      }
#endif


  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
     Parser  (const  Parser &);
    /// Non copyable.
     Parser & operator= (const  Parser &);
#endif


    /// Stored state numbers (used for stacks).
    typedef signed char state_type;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static symbol_kind_type yytranslate_ (int t);

#if YYDEBUG || 0
    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#endif // #if YYDEBUG || 0


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const signed char yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const signed char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const signed char yytable_[];

    static const signed char yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const signed char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Constants.
    enum
    {
      yylast_ = 143,     ///< Last index in yytable_.
      yynnts_ = 26,  ///< Number of nonterminal symbols.
      yyfinal_ = 27 ///< Termination state number.
    };


    // User arguments.
    Scanner &scanner;
    Driver &driver;

  };


} // yy
#line 2462 "/home/etud/Bureau/projet_theorie/dessin/build/parser.hpp"




#endif // !YY_YY_HOME_ETUD_BUREAU_PROJET_THEORIE_DESSIN_BUILD_PARSER_HPP_INCLUDED
