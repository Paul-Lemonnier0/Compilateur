// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file /mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.hpp
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.

#ifndef YY_YY_MNT_C_USERS_PAULL_ONEDRIVE_BUREAU_COMPILATEUR_DESSIN_BUILD_PARSER_HPP_INCLUDED
# define YY_YY_MNT_C_USERS_PAULL_ONEDRIVE_BUREAU_COMPILATEUR_DESSIN_BUILD_PARSER_HPP_INCLUDED
// "%code requires" blocks.
#line 11 "parser/parser.yy"

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

#line 64 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.hpp"

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
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
#line 198 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.hpp"




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
    /// Prohibit blind copies.
    self_type& operator= (const self_type&);
    semantic_type (const self_type&);

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
      // programme
      // subProgramme
      char dummy1[sizeof (ArbreSyntaxique)];

      // couleurValue
      char dummy2[sizeof (CouleurPtr)];

      // operation
      char dummy3[sizeof (ExpressionPtr)];

      // setTaille
      char dummy4[sizeof (TailleType)];

      // boolValue
      char dummy5[sizeof (bool)];

      // FLOAT
      char dummy6[sizeof (float)];

      // NUMBER
      char dummy7[sizeof (int)];

      // numberComparator
      char dummy8[sizeof (operators)];

      // accesFigure
      char dummy9[sizeof (std::shared_ptr<AccesFigureNode>)];

      // affectation
      char dummy10[sizeof (std::shared_ptr<AffectationSimpleVariableNode>)];

      // appelFonction
      char dummy11[sizeof (std::shared_ptr<AppelFonctionNode>)];

      // attributAffectation
      // setAttribut
      char dummy12[sizeof (std::shared_ptr<AttributNode>)];

      // declarationCanva
      char dummy13[sizeof (std::shared_ptr<CanevaNode>)];

      // carre
      char dummy14[sizeof (std::shared_ptr<CarreNode>)];

      // cercle
      char dummy15[sizeof (std::shared_ptr<CercleNode>)];

      // chemin
      char dummy16[sizeof (std::shared_ptr<CheminNode>)];

      // condition
      char dummy17[sizeof (std::shared_ptr<ConditionNode>)];

      // declarationVariable
      char dummy18[sizeof (std::shared_ptr<DeclarationVariable>)];

      // declarationVariableSimple
      char dummy19[sizeof (std::shared_ptr<DeclarationVariableSimple>)];

      // ellipse
      char dummy20[sizeof (std::shared_ptr<EllipseNode>)];

      // declarationFigure
      char dummy21[sizeof (std::shared_ptr<FigureNode>)];

      // fonction
      char dummy22[sizeof (std::shared_ptr<FonctionNode>)];

      // boucleFor
      char dummy23[sizeof (std::shared_ptr<ForLoopNode>)];

      // if
      char dummy24[sizeof (std::shared_ptr<IfNode>)];

      // ligne
      char dummy25[sizeof (std::shared_ptr<LigneNode>)];

      // modificationFigure
      char dummy26[sizeof (std::shared_ptr<ModificationFigureNode>)];

      // instruction
      // expression
      char dummy27[sizeof (std::shared_ptr<Noeud>)];

      // rectangle
      char dummy28[sizeof (std::shared_ptr<RectangleNode>)];

      // texte
      char dummy29[sizeof (std::shared_ptr<TexteNode>)];

      // triangle
      char dummy30[sizeof (std::shared_ptr<TriangleNode>)];

      // boucleWhile
      char dummy31[sizeof (std::shared_ptr<WhileNode>)];

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
      // TAILLE
      // HAUTEUR
      // LARGEUR
      // variable
      char dummy32[sizeof (std::string)];

      // argumentsValues
      char dummy33[sizeof (std::vector<ExpressionPtr>)];

      // vectPos
      char dummy34[sizeof (std::vector<Position>)];

      // attributsInline
      // attributsCSS
      // attributs
      char dummy35[sizeof (std::vector<std::shared_ptr<AttributNode>>)];

      // conditions
      char dummy36[sizeof (std::vector<std::shared_ptr<ConditionNode>>)];

      // instructions
      // else
      char dummy37[sizeof (std::vector<std::shared_ptr<Noeud>>)];

      // arguments
      char dummy38[sizeof (std::vector<std::string>)];

      // stringComparator
      char dummy39[sizeof (string_operators)];
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

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        NL = 258,
        END = 259,
        NUMBER = 260,
        FLOAT = 261,
        TRUE = 262,
        FALSE = 263,
        INT_TYPE = 264,
        BOOL_TYPE = 265,
        FLOAT_TYPE = 266,
        VARIABLE = 267,
        STRING = 268,
        ATTRIBUT = 269,
        INLINE_AFFECTATION = 270,
        HEXA_VALUE = 271,
        COULEUR = 272,
        ROTATION = 273,
        REMPLISSAGE = 274,
        OPACITE = 275,
        EPAISSEUR = 276,
        SI = 277,
        ALORS = 278,
        SINON = 279,
        FUNCTION = 280,
        REPETE = 281,
        FOIS = 282,
        WHILE = 283,
        EQUAL = 284,
        NOTEQUAL = 285,
        LESS = 286,
        LESSEQUAL = 287,
        GREATER = 288,
        GREATEREQUAL = 289,
        STRINGEQUAL = 290,
        STRINGNOTEQUAL = 291,
        TAILLE = 292,
        HAUTEUR = 293,
        LARGEUR = 294,
        RECTANGLE = 295,
        CARRE = 296,
        TRIANGLE = 297,
        CERCLE = 298,
        ELLIPSE = 299,
        LIGNE = 300,
        CHEMIN = 301,
        TEXTE = 302,
        STOP = 303,
        DEGRE = 304,
        AND = 305,
        NEG = 306
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef signed char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get ().
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
      basic_symbol (basic_symbol&& that);
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructor for valueless symbols, and symbols from each type.
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
      basic_symbol (typename Base::kind_type t, CouleurPtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const CouleurPtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ExpressionPtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ExpressionPtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, TailleType&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const TailleType& v, const location_type& l)
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
      basic_symbol (typename Base::kind_type t, operators&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const operators& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<AccesFigureNode>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<AccesFigureNode>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<AffectationSimpleVariableNode>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<AffectationSimpleVariableNode>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<AppelFonctionNode>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<AppelFonctionNode>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<AttributNode>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<AttributNode>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<CanevaNode>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<CanevaNode>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<CarreNode>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<CarreNode>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<CercleNode>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<CercleNode>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<CheminNode>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<CheminNode>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<ConditionNode>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<ConditionNode>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<DeclarationVariable>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<DeclarationVariable>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<DeclarationVariableSimple>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<DeclarationVariableSimple>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<EllipseNode>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<EllipseNode>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<FigureNode>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<FigureNode>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<FonctionNode>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<FonctionNode>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<ForLoopNode>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<ForLoopNode>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<IfNode>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<IfNode>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<LigneNode>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<LigneNode>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<ModificationFigureNode>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<ModificationFigureNode>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<Noeud>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<Noeud>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<RectangleNode>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<RectangleNode>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<TexteNode>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<TexteNode>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<TriangleNode>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<TriangleNode>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<WhileNode>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<WhileNode>& v, const location_type& l)
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
      basic_symbol (typename Base::kind_type t, std::vector<ExpressionPtr>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<ExpressionPtr>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<Position>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<Position>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<std::shared_ptr<AttributNode>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<std::shared_ptr<AttributNode>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<std::shared_ptr<ConditionNode>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<std::shared_ptr<ConditionNode>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<std::shared_ptr<Noeud>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<std::shared_ptr<Noeud>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<std::string>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<std::string>& v, const location_type& l)
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
      void clear ()
      {
        // User destructor.
        symbol_number_type yytype = this->type_get ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yytype)
        {
       default:
          break;
        }

        // Type destructor.
switch (yytype)
    {
      case 69: // programme
      case 70: // subProgramme
        value.template destroy< ArbreSyntaxique > ();
        break;

      case 77: // couleurValue
        value.template destroy< CouleurPtr > ();
        break;

      case 110: // operation
        value.template destroy< ExpressionPtr > ();
        break;

      case 94: // setTaille
        value.template destroy< TailleType > ();
        break;

      case 80: // boolValue
        value.template destroy< bool > ();
        break;

      case 6: // FLOAT
        value.template destroy< float > ();
        break;

      case 5: // NUMBER
        value.template destroy< int > ();
        break;

      case 97: // numberComparator
        value.template destroy< operators > ();
        break;

      case 92: // accesFigure
        value.template destroy< std::shared_ptr<AccesFigureNode> > ();
        break;

      case 105: // affectation
        value.template destroy< std::shared_ptr<AffectationSimpleVariableNode> > ();
        break;

      case 109: // appelFonction
        value.template destroy< std::shared_ptr<AppelFonctionNode> > ();
        break;

      case 76: // attributAffectation
      case 93: // setAttribut
        value.template destroy< std::shared_ptr<AttributNode> > ();
        break;

      case 82: // declarationCanva
        value.template destroy< std::shared_ptr<CanevaNode> > ();
        break;

      case 84: // carre
        value.template destroy< std::shared_ptr<CarreNode> > ();
        break;

      case 87: // cercle
        value.template destroy< std::shared_ptr<CercleNode> > ();
        break;

      case 90: // chemin
        value.template destroy< std::shared_ptr<CheminNode> > ();
        break;

      case 99: // condition
        value.template destroy< std::shared_ptr<ConditionNode> > ();
        break;

      case 96: // declarationVariable
        value.template destroy< std::shared_ptr<DeclarationVariable> > ();
        break;

      case 81: // declarationVariableSimple
        value.template destroy< std::shared_ptr<DeclarationVariableSimple> > ();
        break;

      case 88: // ellipse
        value.template destroy< std::shared_ptr<EllipseNode> > ();
        break;

      case 83: // declarationFigure
        value.template destroy< std::shared_ptr<FigureNode> > ();
        break;

      case 108: // fonction
        value.template destroy< std::shared_ptr<FonctionNode> > ();
        break;

      case 103: // boucleFor
        value.template destroy< std::shared_ptr<ForLoopNode> > ();
        break;

      case 101: // if
        value.template destroy< std::shared_ptr<IfNode> > ();
        break;

      case 89: // ligne
        value.template destroy< std::shared_ptr<LigneNode> > ();
        break;

      case 95: // modificationFigure
        value.template destroy< std::shared_ptr<ModificationFigureNode> > ();
        break;

      case 72: // instruction
      case 78: // expression
        value.template destroy< std::shared_ptr<Noeud> > ();
        break;

      case 85: // rectangle
        value.template destroy< std::shared_ptr<RectangleNode> > ();
        break;

      case 91: // texte
        value.template destroy< std::shared_ptr<TexteNode> > ();
        break;

      case 86: // triangle
        value.template destroy< std::shared_ptr<TriangleNode> > ();
        break;

      case 104: // boucleWhile
        value.template destroy< std::shared_ptr<WhileNode> > ();
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
        value.template destroy< std::string > ();
        break;

      case 107: // argumentsValues
        value.template destroy< std::vector<ExpressionPtr> > ();
        break;

      case 111: // vectPos
        value.template destroy< std::vector<Position> > ();
        break;

      case 73: // attributsInline
      case 74: // attributsCSS
      case 75: // attributs
        value.template destroy< std::vector<std::shared_ptr<AttributNode>> > ();
        break;

      case 100: // conditions
        value.template destroy< std::vector<std::shared_ptr<ConditionNode>> > ();
        break;

      case 71: // instructions
      case 102: // else
        value.template destroy< std::vector<std::shared_ptr<Noeud>> > ();
        break;

      case 106: // arguments
        value.template destroy< std::vector<std::string> > ();
        break;

      case 98: // stringComparator
        value.template destroy< string_operators > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

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
    struct by_type
    {
      /// Default constructor.
      by_type ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_type (by_type&& that);
#endif

      /// Copy constructor.
      by_type (const by_type& that);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_type>
    {
      /// Superclass.
      typedef basic_symbol<by_type> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
      {
        YY_ASSERT (tok == 0 || tok == token::NL || tok == token::END || tok == token::TRUE || tok == token::FALSE || tok == token::ATTRIBUT || tok == token::INLINE_AFFECTATION || tok == token::SI || tok == token::ALORS || tok == token::SINON || tok == token::FUNCTION || tok == token::REPETE || tok == token::FOIS || tok == token::WHILE || tok == token::EQUAL || tok == token::NOTEQUAL || tok == token::LESS || tok == token::LESSEQUAL || tok == token::GREATER || tok == token::GREATEREQUAL || tok == token::STRINGEQUAL || tok == token::STRINGNOTEQUAL || tok == token::RECTANGLE || tok == token::CARRE || tok == token::TRIANGLE || tok == token::CERCLE || tok == token::ELLIPSE || tok == token::LIGNE || tok == token::CHEMIN || tok == token::TEXTE || tok == token::STOP || tok == token::DEGRE || tok == token::AND || tok == 45 || tok == 43 || tok == 42 || tok == 47 || tok == token::NEG || tok == 38 || tok == 59 || tok == 123 || tok == 125 || tok == 58 || tok == 61 || tok == 91 || tok == 93 || tok == 46 || tok == 37 || tok == 40 || tok == 41);
      }
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
      {
        YY_ASSERT (tok == 0 || tok == token::NL || tok == token::END || tok == token::TRUE || tok == token::FALSE || tok == token::ATTRIBUT || tok == token::INLINE_AFFECTATION || tok == token::SI || tok == token::ALORS || tok == token::SINON || tok == token::FUNCTION || tok == token::REPETE || tok == token::FOIS || tok == token::WHILE || tok == token::EQUAL || tok == token::NOTEQUAL || tok == token::LESS || tok == token::LESSEQUAL || tok == token::GREATER || tok == token::GREATEREQUAL || tok == token::STRINGEQUAL || tok == token::STRINGNOTEQUAL || tok == token::RECTANGLE || tok == token::CARRE || tok == token::TRIANGLE || tok == token::CERCLE || tok == token::ELLIPSE || tok == token::LIGNE || tok == token::CHEMIN || tok == token::TEXTE || tok == token::STOP || tok == token::DEGRE || tok == token::AND || tok == 45 || tok == 43 || tok == 42 || tok == 47 || tok == token::NEG || tok == 38 || tok == 59 || tok == 123 || tok == 125 || tok == 58 || tok == 61 || tok == 91 || tok == 93 || tok == 46 || tok == 37 || tok == 40 || tok == 41);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, float v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::FLOAT);
      }
#else
      symbol_type (int tok, const float& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::FLOAT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, int v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::NUMBER);
      }
#else
      symbol_type (int tok, const int& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::NUMBER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::INT_TYPE || tok == token::BOOL_TYPE || tok == token::FLOAT_TYPE || tok == token::VARIABLE || tok == token::STRING || tok == token::HEXA_VALUE || tok == token::COULEUR || tok == token::ROTATION || tok == token::REMPLISSAGE || tok == token::OPACITE || tok == token::EPAISSEUR || tok == token::TAILLE || tok == token::HAUTEUR || tok == token::LARGEUR);
      }
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::INT_TYPE || tok == token::BOOL_TYPE || tok == token::FLOAT_TYPE || tok == token::VARIABLE || tok == token::STRING || tok == token::HEXA_VALUE || tok == token::COULEUR || tok == token::ROTATION || tok == token::REMPLISSAGE || tok == token::OPACITE || tok == token::EPAISSEUR || tok == token::TAILLE || tok == token::HAUTEUR || tok == token::LARGEUR);
      }
#endif
    };

    /// Build a parser object.
     Parser  (Scanner &scanner_yyarg, Driver &driver_yyarg);
    virtual ~ Parser  ();

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

    // Implementation of make_symbol for each symbol type.
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
      make_TRUE (location_type l)
      {
        return symbol_type (token::TRUE, std::move (l));
      }
#else
      static
      symbol_type
      make_TRUE (const location_type& l)
      {
        return symbol_type (token::TRUE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FALSE (location_type l)
      {
        return symbol_type (token::FALSE, std::move (l));
      }
#else
      static
      symbol_type
      make_FALSE (const location_type& l)
      {
        return symbol_type (token::FALSE, l);
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
      make_FUNCTION (location_type l)
      {
        return symbol_type (token::FUNCTION, std::move (l));
      }
#else
      static
      symbol_type
      make_FUNCTION (const location_type& l)
      {
        return symbol_type (token::FUNCTION, l);
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
      make_WHILE (location_type l)
      {
        return symbol_type (token::WHILE, std::move (l));
      }
#else
      static
      symbol_type
      make_WHILE (const location_type& l)
      {
        return symbol_type (token::WHILE, l);
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
      make_TAILLE (std::string v, location_type l)
      {
        return symbol_type (token::TAILLE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TAILLE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TAILLE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HAUTEUR (std::string v, location_type l)
      {
        return symbol_type (token::HAUTEUR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_HAUTEUR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::HAUTEUR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LARGEUR (std::string v, location_type l)
      {
        return symbol_type (token::LARGEUR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LARGEUR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::LARGEUR, v, l);
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
      make_DEGRE (location_type l)
      {
        return symbol_type (token::DEGRE, std::move (l));
      }
#else
      static
      symbol_type
      make_DEGRE (const location_type& l)
      {
        return symbol_type (token::DEGRE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND (location_type l)
      {
        return symbol_type (token::AND, std::move (l));
      }
#else
      static
      symbol_type
      make_AND (const location_type& l)
      {
        return symbol_type (token::AND, l);
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
    /// This class is not copyable.
     Parser  (const  Parser &);
     Parser & operator= (const  Parser &);

    /// Stored state numbers (used for stacks).
    typedef short state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

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

    static const short yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    /// In theory \a t should be a token_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static token_number_type yytranslate_ (int t);

    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const signed char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


#if YYDEBUG
    /// For a symbol, its name in clear.
    static const char* const yytname_[];

    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
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

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

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
      typedef typename S::reverse_iterator iterator;
      typedef typename S::const_reverse_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

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

      std::ptrdiff_t
      ssize () const YY_NOEXCEPT
      {
        return std::ptrdiff_t (size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.rbegin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.rend ();
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
      stack (const stack&);
      stack& operator= (const stack&);
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

    /// Some specific tokens.
    static const token_number_type yy_error_token_ = 1;
    static const token_number_type yy_undef_token_ = 2;

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 395,     ///< Last index in yytable_.
      yynnts_ = 44,  ///< Number of nonterminal symbols.
      yyfinal_ = 68, ///< Termination state number.
      yyntokens_ = 68  ///< Number of tokens.
    };


    // User arguments.
    Scanner &scanner;
    Driver &driver;
  };


} // yy
#line 2606 "/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.hpp"





#endif // !YY_YY_MNT_C_USERS_PAULL_ONEDRIVE_BUREAU_COMPILATEUR_DESSIN_BUILD_PARSER_HPP_INCLUDED
