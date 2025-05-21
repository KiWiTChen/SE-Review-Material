/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "lrparser.y"


#include <stdio.h>
#include "genllvm.h"
int yylex(void);
void yyerror(char *);
extern int type;
extern int array_size;
int count_size = 0;



#line 84 "lrparser.tab.c"

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

#include "lrparser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_num_INT = 3,                    /* num_INT  */
  YYSYMBOL_Y_INT = 4,                      /* Y_INT  */
  YYSYMBOL_Y_VOID = 5,                     /* Y_VOID  */
  YYSYMBOL_Y_CONST = 6,                    /* Y_CONST  */
  YYSYMBOL_Y_IF = 7,                       /* Y_IF  */
  YYSYMBOL_Y_ELSE = 8,                     /* Y_ELSE  */
  YYSYMBOL_Y_WHILE = 9,                    /* Y_WHILE  */
  YYSYMBOL_Y_BREAK = 10,                   /* Y_BREAK  */
  YYSYMBOL_Y_CONTINUE = 11,                /* Y_CONTINUE  */
  YYSYMBOL_Y_FLOAT = 12,                   /* Y_FLOAT  */
  YYSYMBOL_Y_RETURN = 13,                  /* Y_RETURN  */
  YYSYMBOL_Y_ADD = 14,                     /* Y_ADD  */
  YYSYMBOL_Y_COMMA = 15,                   /* Y_COMMA  */
  YYSYMBOL_Y_DIV = 16,                     /* Y_DIV  */
  YYSYMBOL_Y_LPAR = 17,                    /* Y_LPAR  */
  YYSYMBOL_Y_SUB = 18,                     /* Y_SUB  */
  YYSYMBOL_Y_LSQUARE = 19,                 /* Y_LSQUARE  */
  YYSYMBOL_Y_MODULO = 20,                  /* Y_MODULO  */
  YYSYMBOL_Y_MUL = 21,                     /* Y_MUL  */
  YYSYMBOL_Y_NOT = 22,                     /* Y_NOT  */
  YYSYMBOL_Y_RPAR = 23,                    /* Y_RPAR  */
  YYSYMBOL_Y_RSQUARE = 24,                 /* Y_RSQUARE  */
  YYSYMBOL_Y_RBRACKET = 25,                /* Y_RBRACKET  */
  YYSYMBOL_Y_LESS = 26,                    /* Y_LESS  */
  YYSYMBOL_Y_LESSEQ = 27,                  /* Y_LESSEQ  */
  YYSYMBOL_Y_GREAT = 28,                   /* Y_GREAT  */
  YYSYMBOL_Y_GREATEQ = 29,                 /* Y_GREATEQ  */
  YYSYMBOL_Y_NOTEQ = 30,                   /* Y_NOTEQ  */
  YYSYMBOL_Y_EQ = 31,                      /* Y_EQ  */
  YYSYMBOL_Y_AND = 32,                     /* Y_AND  */
  YYSYMBOL_Y_OR = 33,                      /* Y_OR  */
  YYSYMBOL_Y_ASSIGN = 34,                  /* Y_ASSIGN  */
  YYSYMBOL_Y_LBRACKET = 35,                /* Y_LBRACKET  */
  YYSYMBOL_Y_SEMICOLON = 36,               /* Y_SEMICOLON  */
  YYSYMBOL_num_FLOAT = 37,                 /* num_FLOAT  */
  YYSYMBOL_Y_ID = 38,                      /* Y_ID  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_program = 40,                   /* program  */
  YYSYMBOL_CompUnit = 41,                  /* CompUnit  */
  YYSYMBOL_GlobalDecl = 42,                /* GlobalDecl  */
  YYSYMBOL_GlobalConstDecl = 43,           /* GlobalConstDecl  */
  YYSYMBOL_GlobalVarDecl = 44,             /* GlobalVarDecl  */
  YYSYMBOL_Decl = 45,                      /* Decl  */
  YYSYMBOL_ConstDefs = 46,                 /* ConstDefs  */
  YYSYMBOL_ConstDef = 47,                  /* ConstDef  */
  YYSYMBOL_ConstExps = 48,                 /* ConstExps  */
  YYSYMBOL_ConstInitVal = 49,              /* ConstInitVal  */
  YYSYMBOL_ConstExp = 50,                  /* ConstExp  */
  YYSYMBOL_ConstInitVals = 51,             /* ConstInitVals  */
  YYSYMBOL_VarDecl = 52,                   /* VarDecl  */
  YYSYMBOL_VarDecls = 53,                  /* VarDecls  */
  YYSYMBOL_VarDef = 54,                    /* VarDef  */
  YYSYMBOL_InitVal = 55,                   /* InitVal  */
  YYSYMBOL_InitVals = 56,                  /* InitVals  */
  YYSYMBOL_FuncDef = 57,                   /* FuncDef  */
  YYSYMBOL_FuncParams = 58,                /* FuncParams  */
  YYSYMBOL_FuncParam = 59,                 /* FuncParam  */
  YYSYMBOL_Type = 60,                      /* Type  */
  YYSYMBOL_Stmt = 61,                      /* Stmt  */
  YYSYMBOL_Block = 62,                     /* Block  */
  YYSYMBOL_BlockItems = 63,                /* BlockItems  */
  YYSYMBOL_BlockItem = 64,                 /* BlockItem  */
  YYSYMBOL_RelExp = 65,                    /* RelExp  */
  YYSYMBOL_EqExp = 66,                     /* EqExp  */
  YYSYMBOL_LAndExp = 67,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 68,                    /* LOrExp  */
  YYSYMBOL_Exp = 69,                       /* Exp  */
  YYSYMBOL_AddExp = 70,                    /* AddExp  */
  YYSYMBOL_MulExp = 71,                    /* MulExp  */
  YYSYMBOL_UnaryExp = 72,                  /* UnaryExp  */
  YYSYMBOL_CallParams = 73,                /* CallParams  */
  YYSYMBOL_PrimaryExp = 74,                /* PrimaryExp  */
  YYSYMBOL_LVal = 75,                      /* LVal  */
  YYSYMBOL_ArraySubscripts = 76            /* ArraySubscripts  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
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

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   376

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  113
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  209

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    36,    36,    39,    40,    41,    42,    45,    46,    49,
      50,    53,    54,    57,    58,    65,    66,    69,    70,    73,
      74,    77,    78,    79,    80,    83,    86,    87,    90,    91,
      94,    95,    98,    99,   100,   101,   104,   105,   106,   107,
     110,   111,   115,   116,   119,   120,   123,   124,   125,   126,
     129,   130,   131,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   150,   151,
     152,   153,   156,   157,   160,   161,   164,   165,   168,   169,
     170,   171,   172,   175,   176,   177,   180,   181,   184,   185,
     188,   192,   193,   194,   197,   198,   199,   200,   203,   204,
     205,   206,   207,   208,   211,   212,   215,   216,   217,   218,
     221,   222,   225,   226
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "num_INT", "Y_INT",
  "Y_VOID", "Y_CONST", "Y_IF", "Y_ELSE", "Y_WHILE", "Y_BREAK",
  "Y_CONTINUE", "Y_FLOAT", "Y_RETURN", "Y_ADD", "Y_COMMA", "Y_DIV",
  "Y_LPAR", "Y_SUB", "Y_LSQUARE", "Y_MODULO", "Y_MUL", "Y_NOT", "Y_RPAR",
  "Y_RSQUARE", "Y_RBRACKET", "Y_LESS", "Y_LESSEQ", "Y_GREAT", "Y_GREATEQ",
  "Y_NOTEQ", "Y_EQ", "Y_AND", "Y_OR", "Y_ASSIGN", "Y_LBRACKET",
  "Y_SEMICOLON", "num_FLOAT", "Y_ID", "$accept", "program", "CompUnit",
  "GlobalDecl", "GlobalConstDecl", "GlobalVarDecl", "Decl", "ConstDefs",
  "ConstDef", "ConstExps", "ConstInitVal", "ConstExp", "ConstInitVals",
  "VarDecl", "VarDecls", "VarDef", "InitVal", "InitVals", "FuncDef",
  "FuncParams", "FuncParam", "Type", "Stmt", "Block", "BlockItems",
  "BlockItem", "RelExp", "EqExp", "LAndExp", "LOrExp", "Exp", "AddExp",
  "MulExp", "UnaryExp", "CallParams", "PrimaryExp", "LVal",
  "ArraySubscripts", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-150)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     135,  -150,  -150,    94,  -150,    27,  -150,   135,  -150,  -150,
     135,     7,    31,  -150,  -150,  -150,    25,    10,    -3,    18,
      20,    90,   338,   283,    53,    46,  -150,    85,   289,    98,
      31,  -150,    31,  -150,    91,    92,  -150,   114,  -150,   338,
     338,   338,   338,  -150,    51,   112,    96,    69,  -150,  -150,
    -150,    12,  -150,  -150,    96,   283,    47,   149,  -150,   256,
    -150,  -150,   289,  -150,  -150,   175,  -150,    94,    91,   146,
    -150,   143,  -150,  -150,    74,   338,   150,   151,   338,   338,
     338,   338,   338,  -150,    49,  -150,  -150,  -150,    58,  -150,
     154,   155,   132,   138,   295,  -150,  -150,  -150,  -150,  -150,
      46,  -150,  -150,   158,   211,   139,   142,  -150,  -150,   320,
     150,  -150,  -150,   180,   168,   172,   338,  -150,    69,    69,
    -150,  -150,  -150,   283,  -150,   173,   289,  -150,   174,   338,
     338,  -150,  -150,  -150,   165,    24,  -150,  -150,  -150,   338,
     187,   338,  -150,  -150,   183,   193,  -150,   194,  -150,    89,
     195,   186,   203,   176,   207,  -150,  -150,   196,   198,   150,
    -150,  -150,  -150,  -150,   338,   338,   338,   338,   247,   338,
     338,   338,   338,   247,  -150,  -150,  -150,  -150,  -150,  -150,
     223,  -150,  -150,  -150,  -150,  -150,   120,   218,   200,   201,
     332,  -150,   202,   205,   338,  -150,  -150,  -150,   204,  -150,
     338,   219,  -150,   208,   247,  -150,   233,   247,  -150
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    50,    52,     0,    51,     0,     2,     5,     7,     8,
       6,     0,     0,     1,     3,     4,    32,     0,     0,     0,
       0,     0,     0,     0,    34,     0,    11,     0,     0,     0,
       0,    10,     0,     9,     0,     0,    44,     0,   108,     0,
       0,     0,     0,   109,   110,     0,    25,    91,    94,    98,
     107,     0,    33,    36,    90,     0,    32,    30,    12,     0,
      17,    21,     0,    16,    15,     0,    42,     0,     0,    46,
     101,     0,   102,   103,     0,     0,   111,    19,     0,     0,
       0,     0,     0,    37,     0,    35,    31,    22,     0,    18,
       0,     0,     0,     0,     0,    73,    54,    13,    76,    14,
       0,    77,    56,     0,    74,     0,   107,    45,    43,     0,
      48,   106,    99,   104,     0,     0,     0,    20,    92,    93,
      96,    97,    95,     0,    38,     0,     0,    23,     0,     0,
       0,    68,    69,    71,     0,     0,    72,    75,    55,     0,
      47,     0,   100,   112,     0,    40,    39,    26,    24,    83,
      86,    88,     0,    78,     0,    70,    28,     0,     0,    49,
     105,   113,    41,    27,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,    53,    85,    84,    87,    89,
      58,    79,    81,    80,    82,    57,     0,     0,     0,     0,
       0,    60,     0,   107,     0,    61,    62,    64,     0,    59,
       0,     0,    63,     0,     0,    65,    66,     0,    67
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -150,  -150,    33,  -150,   -47,  -150,  -150,  -150,    71,    -5,
     -50,   221,   104,  -150,   -53,   -20,   -45,   100,  -150,  -150,
     185,     0,  -149,   -32,   159,  -150,   -10,   -40,    87,  -119,
     -23,   -21,    50,   -19,   121,  -150,   -51,   -61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,     8,     9,    98,    19,    20,    24,
      60,    61,   128,    99,    27,    17,    52,   125,    10,    35,
      36,    11,   101,   102,   103,   104,   149,   150,   151,   152,
     105,    54,    47,    48,   114,    49,    50,    76
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      53,    46,    66,    12,    86,    57,    84,    46,   110,    88,
      85,   154,    89,    29,   106,    38,    22,    71,    97,   180,
      70,    37,    72,    73,   185,    25,    39,    13,    53,    40,
      41,    28,    53,    30,    42,    32,   108,    83,    46,    25,
      14,    46,    21,    15,    22,    16,    26,    51,   179,    43,
      44,   113,   115,   106,    31,   206,    33,    97,   208,    23,
     156,   120,   121,   122,   123,   100,    22,    37,    74,    18,
      75,   134,   117,   126,   124,   201,   147,    38,   145,   159,
     135,    23,   157,   127,    56,    80,   115,    55,    39,    81,
      82,    40,    41,   144,     1,     2,    42,   112,     1,     2,
      53,    63,     4,    64,   100,    46,     4,    67,   153,   153,
      78,    43,    44,    34,    79,    68,   158,   106,   113,   164,
     165,    58,   106,    38,   176,   177,    65,   187,   118,   119,
     188,   189,    62,   190,    39,   193,    77,    40,    41,     1,
       2,     3,    42,   153,   153,   153,   153,     4,   153,   153,
     153,   153,    69,   106,   191,    65,   106,    43,    44,   181,
     182,   183,   184,   192,    25,   109,   111,   198,   131,   116,
      22,   129,   130,   153,   132,   138,   139,   203,    38,     1,
       2,     3,    90,   136,    91,    92,    93,     4,    94,    39,
      78,   142,    40,    41,    79,   141,   143,    42,   146,   148,
      95,   155,   169,   170,   171,   172,    75,   161,   123,   126,
      65,    96,    43,    44,    38,     1,     2,     3,    90,   167,
      91,    92,    93,     4,    94,    39,   168,   166,    40,    41,
     173,   186,   174,    42,   175,   194,   195,   196,   199,   200,
     202,   207,   204,    45,   205,   162,    65,    96,    43,    44,
      38,   163,   107,   178,    90,     0,    91,    92,    93,    38,
      94,    39,   160,   137,    40,    41,     0,     0,     0,    42,
      39,     0,     0,    40,    41,     0,     0,     0,    42,     0,
       0,    87,    65,    96,    43,    44,    38,     0,     0,     0,
       0,    59,    38,    43,    44,     0,     0,    39,    38,     0,
      40,    41,     0,    39,     0,    42,    40,    41,     0,    39,
       0,    42,    40,    41,     0,     0,     0,    42,    51,     0,
      43,    44,     0,    38,    59,     0,    43,    44,     0,     0,
       0,   133,    43,    44,    39,    38,     0,    40,    41,     0,
       0,    38,    42,     0,   140,     0,    39,     0,     0,    40,
      41,     0,    39,     0,    42,    40,    41,    43,    44,     0,
      42,     0,     0,     0,     0,     0,     0,     0,   197,    43,
      44,     0,     0,     0,     0,    43,    44
};

static const yytype_int16 yycheck[] =
{
      23,    22,    34,     3,    57,    25,    51,    28,    69,    59,
      55,   130,    62,    18,    65,     3,    19,    40,    65,   168,
      39,    21,    41,    42,   173,    15,    14,     0,    51,    17,
      18,    34,    55,    15,    22,    15,    68,    25,    59,    15,
       7,    62,    17,    10,    19,    38,    36,    35,   167,    37,
      38,    74,    75,   104,    36,   204,    36,   104,   207,    34,
      36,    80,    81,    82,    15,    65,    19,    67,    17,    38,
      19,    94,    77,    15,    25,   194,   126,     3,   123,   140,
     100,    34,   135,    25,    38,    16,   109,    34,    14,    20,
      21,    17,    18,   116,     4,     5,    22,    23,     4,     5,
     123,    30,    12,    32,   104,   126,    12,    15,   129,   130,
      14,    37,    38,    23,    18,    23,   139,   168,   141,    30,
      31,    36,   173,     3,   164,   165,    35,     7,    78,    79,
      10,    11,    34,    13,    14,   186,    24,    17,    18,     4,
       5,     6,    22,   164,   165,   166,   167,    12,   169,   170,
     171,   172,    38,   204,   186,    35,   207,    37,    38,   169,
     170,   171,   172,   186,    15,    19,    23,   190,    36,    19,
      19,    17,    17,   194,    36,    36,    34,   200,     3,     4,
       5,     6,     7,    25,     9,    10,    11,    12,    13,    14,
      14,    23,    17,    18,    18,    15,    24,    22,    25,    25,
      25,    36,    26,    27,    28,    29,    19,    24,    15,    15,
      35,    36,    37,    38,     3,     4,     5,     6,     7,    33,
       9,    10,    11,    12,    13,    14,    23,    32,    17,    18,
      23,     8,    36,    22,    36,    17,    36,    36,    36,    34,
      36,     8,    23,    22,    36,   145,    35,    36,    37,    38,
       3,   147,    67,   166,     7,    -1,     9,    10,    11,     3,
      13,    14,   141,   104,    17,    18,    -1,    -1,    -1,    22,
      14,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,
      -1,    25,    35,    36,    37,    38,     3,    -1,    -1,    -1,
      -1,    35,     3,    37,    38,    -1,    -1,    14,     3,    -1,
      17,    18,    -1,    14,    -1,    22,    17,    18,    -1,    14,
      -1,    22,    17,    18,    -1,    -1,    -1,    22,    35,    -1,
      37,    38,    -1,     3,    35,    -1,    37,    38,    -1,    -1,
      -1,    36,    37,    38,    14,     3,    -1,    17,    18,    -1,
      -1,     3,    22,    -1,    24,    -1,    14,    -1,    -1,    17,
      18,    -1,    14,    -1,    22,    17,    18,    37,    38,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    -1,    -1,    -1,    -1,    37,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,     6,    12,    40,    41,    42,    43,    44,
      57,    60,    60,     0,    41,    41,    38,    54,    38,    46,
      47,    17,    19,    34,    48,    15,    36,    53,    34,    48,
      15,    36,    15,    36,    23,    58,    59,    60,     3,    14,
      17,    18,    22,    37,    38,    50,    70,    71,    72,    74,
      75,    35,    55,    69,    70,    34,    38,    54,    36,    35,
      49,    50,    34,    47,    47,    35,    62,    15,    23,    38,
      72,    69,    72,    72,    17,    19,    76,    24,    14,    18,
      16,    20,    21,    25,    55,    55,    53,    25,    49,    49,
       7,     9,    10,    11,    13,    25,    36,    43,    45,    52,
      60,    61,    62,    63,    64,    69,    75,    59,    62,    19,
      76,    23,    23,    69,    73,    69,    19,    48,    71,    71,
      72,    72,    72,    15,    25,    56,    15,    25,    51,    17,
      17,    36,    36,    36,    69,    54,    25,    63,    36,    34,
      24,    15,    23,    24,    69,    55,    25,    49,    25,    65,
      66,    67,    68,    70,    68,    36,    36,    53,    69,    76,
      73,    24,    56,    51,    30,    31,    32,    33,    23,    26,
      27,    28,    29,    23,    36,    36,    66,    66,    67,    68,
      61,    65,    65,    65,    65,    61,     8,     7,    10,    11,
      13,    62,    69,    75,    17,    36,    36,    36,    69,    36,
      34,    68,    36,    69,    23,    36,    61,     8,    61
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    41,    41,    41,    41,    42,    42,    43,
      43,    44,    44,    45,    45,    46,    46,    47,    47,    48,
      48,    49,    49,    49,    49,    50,    51,    51,    52,    52,
      53,    53,    54,    54,    54,    54,    55,    55,    55,    55,
      56,    56,    57,    57,    58,    58,    59,    59,    59,    59,
      60,    60,    60,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    63,    63,    64,    64,    65,    65,
      65,    65,    65,    66,    66,    66,    67,    67,    68,    68,
      69,    70,    70,    70,    71,    71,    71,    71,    72,    72,
      72,    72,    72,    72,    73,    73,    74,    74,    74,    74,
      75,    75,    76,    76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     1,     1,     4,
       4,     3,     4,     1,     1,     3,     3,     3,     4,     3,
       4,     1,     2,     3,     4,     1,     2,     3,     3,     4,
       2,     3,     1,     3,     2,     4,     1,     2,     3,     4,
       2,     3,     5,     6,     1,     3,     2,     4,     3,     5,
       1,     1,     1,     4,     1,     2,     1,     5,     5,     8,
       7,     8,     8,     9,     8,    10,    11,    13,     2,     2,
       3,     2,     3,     2,     1,     2,     1,     1,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     3,
       1,     1,     3,     3,     1,     3,     3,     3,     1,     3,
       4,     2,     2,     2,     1,     3,     3,     1,     1,     1,
       1,     2,     3,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: CompUnit  */
#line 36 "lrparser.y"
                  {setNode((yyvsp[0].pAst)); }
#line 1322 "lrparser.tab.c"
    break;

  case 3: /* CompUnit: GlobalDecl CompUnit  */
#line 39 "lrparser.y"
                              {past l = newCompUnit((yyvsp[-1].pAst), NULL); l->right = (yyvsp[0].pAst); (yyval.pAst) = l;}
#line 1328 "lrparser.tab.c"
    break;

  case 4: /* CompUnit: FuncDef CompUnit  */
#line 40 "lrparser.y"
                            {past l = newCompUnit((yyvsp[-1].pAst), NULL); l->right = (yyvsp[0].pAst); (yyval.pAst) = l;}
#line 1334 "lrparser.tab.c"
    break;

  case 5: /* CompUnit: GlobalDecl  */
#line 41 "lrparser.y"
                       {(yyval.pAst) = newCompUnit((yyvsp[0].pAst), NULL);}
#line 1340 "lrparser.tab.c"
    break;

  case 6: /* CompUnit: FuncDef  */
#line 42 "lrparser.y"
                   {(yyval.pAst) = newCompUnit((yyvsp[0].pAst), NULL);}
#line 1346 "lrparser.tab.c"
    break;

  case 7: /* GlobalDecl: GlobalConstDecl  */
#line 45 "lrparser.y"
                           {(yyvsp[0].pAst)->if_const += 3;(yyval.pAst) = (yyvsp[0].pAst);}
#line 1352 "lrparser.tab.c"
    break;

  case 8: /* GlobalDecl: GlobalVarDecl  */
#line 46 "lrparser.y"
                         {(yyvsp[0].pAst)->if_const += 3;(yyval.pAst) = (yyvsp[0].pAst);}
#line 1358 "lrparser.tab.c"
    break;

  case 9: /* GlobalConstDecl: Y_CONST Type ConstDef Y_SEMICOLON  */
#line 49 "lrparser.y"
                                                   {(yyval.pAst) = (yyvsp[-1].pAst); }
#line 1364 "lrparser.tab.c"
    break;

  case 10: /* GlobalConstDecl: Y_CONST Type ConstDefs Y_SEMICOLON  */
#line 50 "lrparser.y"
                                                    {(yyval.pAst) = (yyvsp[-1].pAst); }
#line 1370 "lrparser.tab.c"
    break;

  case 11: /* GlobalVarDecl: Type VarDef Y_SEMICOLON  */
#line 53 "lrparser.y"
                                        {(yyval.pAst) = (yyvsp[-1].pAst); }
#line 1376 "lrparser.tab.c"
    break;

  case 12: /* GlobalVarDecl: Type VarDef VarDecls Y_SEMICOLON  */
#line 54 "lrparser.y"
                                                 {(yyvsp[-2].pAst)->next = (yyvsp[-1].pAst);(yyval.pAst) = (yyvsp[-2].pAst); }
#line 1382 "lrparser.tab.c"
    break;

  case 15: /* ConstDefs: ConstDef Y_COMMA ConstDef  */
#line 65 "lrparser.y"
                                     {(yyvsp[-2].pAst)->next = (yyvsp[0].pAst),(yyval.pAst) = (yyvsp[-2].pAst);}
#line 1388 "lrparser.tab.c"
    break;

  case 16: /* ConstDefs: ConstDefs Y_COMMA ConstDef  */
#line 66 "lrparser.y"
                                       {(yyvsp[0].pAst)->next = (yyvsp[-2].pAst);(yyval.pAst) = (yyvsp[0].pAst);}
#line 1394 "lrparser.tab.c"
    break;

  case 17: /* ConstDef: Y_ID Y_ASSIGN ConstInitVal  */
#line 69 "lrparser.y"
                                     {(yyval.pAst) = newVarDecl(get_conststype(type), type, 1, (yyvsp[-2].id_name), NULL, (yyvsp[0].pAst));}
#line 1400 "lrparser.tab.c"
    break;

  case 18: /* ConstDef: Y_ID ConstExps Y_ASSIGN ConstInitVal  */
#line 70 "lrparser.y"
                                                {(yyval.pAst) = newVarDecl(get_conststype(type), type, 1, (yyvsp[-3].id_name), NULL, newAstAny((yyvsp[0].pAst),NULL,"INIT_LIST_EXPR",INIT_LIST_EXPR)); }
#line 1406 "lrparser.tab.c"
    break;

  case 19: /* ConstExps: Y_LSQUARE ConstExp Y_RSQUARE  */
#line 73 "lrparser.y"
                                        {(yyval.pAst) = (yyvsp[-1].pAst);array_size = (yyvsp[-1].pAst)->ivalue;}
#line 1412 "lrparser.tab.c"
    break;

  case 20: /* ConstExps: Y_LSQUARE ConstExp Y_RSQUARE ConstExps  */
#line 74 "lrparser.y"
                                                  {array_size = (yyvsp[0].pAst)->ivalue;(yyvsp[-2].pAst)->next = (yyvsp[0].pAst),(yyval.pAst) = (yyvsp[-2].pAst); }
#line 1418 "lrparser.tab.c"
    break;

  case 22: /* ConstInitVal: Y_LBRACKET Y_RBRACKET  */
#line 78 "lrparser.y"
                                     {(yyval.pAst) = NULL; }
#line 1424 "lrparser.tab.c"
    break;

  case 23: /* ConstInitVal: Y_LBRACKET ConstInitVal Y_RBRACKET  */
#line 79 "lrparser.y"
                                                  {past node = (yyvsp[-1].pAst);node = newAstAny(node,NULL,"INIT_LIST_EXPR",INIT_LIST_EXPR);(yyval.pAst) = node;count_size =0;}
#line 1430 "lrparser.tab.c"
    break;

  case 24: /* ConstInitVal: Y_LBRACKET ConstInitVal ConstInitVals Y_RBRACKET  */
#line 80 "lrparser.y"
                                                                {count_size++;past node = (yyvsp[-2].pAst);node->next = (yyvsp[-1].pAst);(yyval.pAst) = node;count_size =0; }
#line 1436 "lrparser.tab.c"
    break;

  case 26: /* ConstInitVals: Y_COMMA ConstInitVal  */
#line 86 "lrparser.y"
                                    {count_size++;past node = (yyvsp[0].pAst);(yyval.pAst) = node; }
#line 1442 "lrparser.tab.c"
    break;

  case 27: /* ConstInitVals: Y_COMMA ConstInitVal ConstInitVals  */
#line 87 "lrparser.y"
                                                   {count_size++;past node = (yyvsp[-1].pAst);node->next = (yyvsp[0].pAst);(yyval.pAst) = node; }
#line 1448 "lrparser.tab.c"
    break;

  case 28: /* VarDecl: Type VarDef Y_SEMICOLON  */
#line 90 "lrparser.y"
                                 {(yyval.pAst) = newDeclStmt(NULL, (yyvsp[-1].pAst));}
#line 1454 "lrparser.tab.c"
    break;

  case 29: /* VarDecl: Type VarDef VarDecls Y_SEMICOLON  */
#line 91 "lrparser.y"
                                           {(yyval.pAst) = newDeclStmt((yyvsp[-2].pAst), (yyvsp[-1].pAst));}
#line 1460 "lrparser.tab.c"
    break;

  case 30: /* VarDecls: Y_COMMA VarDef  */
#line 94 "lrparser.y"
                         {(yyval.pAst) = (yyvsp[0].pAst);}
#line 1466 "lrparser.tab.c"
    break;

  case 31: /* VarDecls: Y_COMMA VarDef VarDecls  */
#line 95 "lrparser.y"
                                  {(yyvsp[-1].pAst)->next = (yyvsp[0].pAst);(yyval.pAst) = (yyvsp[-1].pAst);}
#line 1472 "lrparser.tab.c"
    break;

  case 32: /* VarDef: Y_ID  */
#line 98 "lrparser.y"
             {(yyval.pAst) = newVarDecl(get_stype(type), type, 0, (yyvsp[0].id_name), NULL, NULL);}
#line 1478 "lrparser.tab.c"
    break;

  case 33: /* VarDef: Y_ID Y_ASSIGN InitVal  */
#line 99 "lrparser.y"
                               {(yyval.pAst) = newVarDecl(get_stype(type), type, 0, (yyvsp[-2].id_name), NULL, (yyvsp[0].pAst));}
#line 1484 "lrparser.tab.c"
    break;

  case 34: /* VarDef: Y_ID ConstExps  */
#line 100 "lrparser.y"
                        {(yyval.pAst) = newVarDecl(get_stype(type), type, 0, (yyvsp[-1].id_name), NULL, NULL); }
#line 1490 "lrparser.tab.c"
    break;

  case 35: /* VarDef: Y_ID ConstExps Y_ASSIGN InitVal  */
#line 101 "lrparser.y"
                                         {(yyval.pAst) = newVarDecl(get_stype(type), type, 0, (yyvsp[-3].id_name), NULL, newAstAny((yyvsp[0].pAst),NULL,"INIT_LIST_EXPR",INIT_LIST_EXPR)); }
#line 1496 "lrparser.tab.c"
    break;

  case 37: /* InitVal: Y_LBRACKET Y_RBRACKET  */
#line 105 "lrparser.y"
                                {(yyval.pAst) = NULL;}
#line 1502 "lrparser.tab.c"
    break;

  case 38: /* InitVal: Y_LBRACKET InitVal Y_RBRACKET  */
#line 106 "lrparser.y"
                                        {past node = (yyvsp[-1].pAst);node = newAstAny(node,NULL,"INIT_LIST_EXPR",INIT_LIST_EXPR);(yyval.pAst) = node;count_size =0;}
#line 1508 "lrparser.tab.c"
    break;

  case 39: /* InitVal: Y_LBRACKET InitVal InitVals Y_RBRACKET  */
#line 107 "lrparser.y"
                                                 {count_size++;past node = (yyvsp[-2].pAst);node->next = (yyvsp[-1].pAst);if(node->nodeType!=INIT_LIST_EXPR){node = newAstAny(node,NULL,"INIT_LIST_EXPR",INIT_LIST_EXPR);node->next = (yyvsp[-1].pAst)->next;(yyvsp[-1].pAst)->next=NULL;}(yyval.pAst) = node;count_size =0; }
#line 1514 "lrparser.tab.c"
    break;

  case 40: /* InitVals: Y_COMMA InitVal  */
#line 110 "lrparser.y"
                          {count_size++;past node = (yyvsp[0].pAst);(yyval.pAst) = node; }
#line 1520 "lrparser.tab.c"
    break;

  case 41: /* InitVals: Y_COMMA InitVal InitVals  */
#line 111 "lrparser.y"
                                    {count_size++;past node = (yyvsp[-1].pAst);node->next = (yyvsp[0].pAst);if(node->nodeType==INIT_LIST_EXPR){count_size = 0;}if(count_size>=array_size && node->nodeType!=INIT_LIST_EXPR){node = newAstAny(node,NULL,"INIT_LIST_EXPR",INIT_LIST_EXPR);node->next = (yyvsp[0].pAst)->next;(yyvsp[0].pAst)->next = NULL;count_size=0;}(yyval.pAst) = node; }
#line 1526 "lrparser.tab.c"
    break;

  case 42: /* FuncDef: Type Y_ID Y_LPAR Y_RPAR Block  */
#line 115 "lrparser.y"
                                       {(yyval.pAst) = newFuncDecl(get_stype((yyvsp[-4].pAst)->ivalue), (yyvsp[-4].pAst)->ivalue,(yyvsp[-3].id_name), NULL, newCompoundStmt(NULL, (yyvsp[0].pAst)));}
#line 1532 "lrparser.tab.c"
    break;

  case 43: /* FuncDef: Type Y_ID Y_LPAR FuncParams Y_RPAR Block  */
#line 116 "lrparser.y"
                                                   {(yyval.pAst) = newFuncDecl(get_stype((yyvsp[-5].pAst)->ivalue), (yyvsp[-5].pAst)->ivalue, (yyvsp[-4].id_name), (yyvsp[-2].pAst), newCompoundStmt(NULL, (yyvsp[0].pAst)));}
#line 1538 "lrparser.tab.c"
    break;

  case 45: /* FuncParams: FuncParams Y_COMMA FuncParam  */
#line 120 "lrparser.y"
                                          {past node=(yyvsp[-2].pAst);while(node->next!=NULL) node = node->next;node->next = (yyvsp[0].pAst); (yyval.pAst) = (yyvsp[-2].pAst);}
#line 1544 "lrparser.tab.c"
    break;

  case 46: /* FuncParam: Type Y_ID  */
#line 123 "lrparser.y"
                     {(yyval.pAst) = newParaDecl(get_stype((yyvsp[-1].pAst)->ivalue), (yyvsp[0].id_name), NULL, NULL);}
#line 1550 "lrparser.tab.c"
    break;

  case 47: /* FuncParam: Type Y_ID Y_LSQUARE Y_RSQUARE  */
#line 124 "lrparser.y"
                                          {(yyval.pAst) = newParaDecl(get_stype((yyvsp[-3].pAst)->ivalue), (yyvsp[-2].id_name), NULL, NULL);}
#line 1556 "lrparser.tab.c"
    break;

  case 48: /* FuncParam: Type Y_ID ArraySubscripts  */
#line 125 "lrparser.y"
                                      {(yyval.pAst) = newParaDecl(get_stype((yyvsp[-2].pAst)->ivalue), (yyvsp[-1].id_name), NULL, NULL);}
#line 1562 "lrparser.tab.c"
    break;

  case 49: /* FuncParam: Type Y_ID Y_LSQUARE Y_RSQUARE ArraySubscripts  */
#line 126 "lrparser.y"
                                                          {(yyval.pAst) = newParaDecl(get_stype((yyvsp[-4].pAst)->ivalue), (yyvsp[-3].id_name), NULL, NULL);}
#line 1568 "lrparser.tab.c"
    break;

  case 50: /* Type: Y_INT  */
#line 129 "lrparser.y"
            {yylval.int_value = Y_INT;(yyval.pAst) = newType(Y_INT);}
#line 1574 "lrparser.tab.c"
    break;

  case 51: /* Type: Y_FLOAT  */
#line 130 "lrparser.y"
               {yylval.int_value = Y_FLOAT;(yyval.pAst) = newType(Y_FLOAT);}
#line 1580 "lrparser.tab.c"
    break;

  case 52: /* Type: Y_VOID  */
#line 131 "lrparser.y"
              {yylval.int_value = Y_VOID;(yyval.pAst) = newType(Y_VOID);}
#line 1586 "lrparser.tab.c"
    break;

  case 53: /* Stmt: LVal Y_ASSIGN Exp Y_SEMICOLON  */
#line 134 "lrparser.y"
                                    {(yyval.pAst) = newBinaryOper("=", Y_ASSIGN, (yyvsp[-3].pAst), (yyvsp[-1].pAst));}
#line 1592 "lrparser.tab.c"
    break;

  case 54: /* Stmt: Y_SEMICOLON  */
#line 135 "lrparser.y"
                   {(yyval.pAst) = NULL;}
#line 1598 "lrparser.tab.c"
    break;

  case 55: /* Stmt: Exp Y_SEMICOLON  */
#line 136 "lrparser.y"
                       {(yyval.pAst) = (yyvsp[-1].pAst);}
#line 1604 "lrparser.tab.c"
    break;

  case 57: /* Stmt: Y_WHILE Y_LPAR LOrExp Y_RPAR Stmt  */
#line 138 "lrparser.y"
                                         {(yyval.pAst) = newWhileStmt((yyvsp[-2].pAst), newCompoundStmt(NULL,(yyvsp[0].pAst)));}
#line 1610 "lrparser.tab.c"
    break;

  case 58: /* Stmt: Y_IF Y_LPAR LOrExp Y_RPAR Stmt  */
#line 139 "lrparser.y"
                                      {(yyval.pAst) = newIfStmt((yyvsp[-2].pAst), (yyvsp[0].pAst), NULL);}
#line 1616 "lrparser.tab.c"
    break;

  case 59: /* Stmt: Y_IF Y_LPAR LOrExp Y_RPAR Stmt Y_ELSE Exp Y_SEMICOLON  */
#line 140 "lrparser.y"
                                                             {(yyval.pAst) = newIfStmt((yyvsp[-5].pAst),(yyvsp[-3].pAst), (yyvsp[-1].pAst));}
#line 1622 "lrparser.tab.c"
    break;

  case 60: /* Stmt: Y_IF Y_LPAR LOrExp Y_RPAR Stmt Y_ELSE Block  */
#line 141 "lrparser.y"
                                                   {(yyval.pAst) = newIfStmt((yyvsp[-4].pAst),(yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1628 "lrparser.tab.c"
    break;

  case 61: /* Stmt: Y_IF Y_LPAR LOrExp Y_RPAR Stmt Y_ELSE Y_BREAK Y_SEMICOLON  */
#line 142 "lrparser.y"
                                                                 {(yyval.pAst) = newIfStmt((yyvsp[-5].pAst),(yyvsp[-3].pAst), newBreakStmt());}
#line 1634 "lrparser.tab.c"
    break;

  case 62: /* Stmt: Y_IF Y_LPAR LOrExp Y_RPAR Stmt Y_ELSE Y_CONTINUE Y_SEMICOLON  */
#line 143 "lrparser.y"
                                                                    {(yyval.pAst) = newIfStmt((yyvsp[-5].pAst),(yyvsp[-3].pAst),newContinueStmt());}
#line 1640 "lrparser.tab.c"
    break;

  case 63: /* Stmt: Y_IF Y_LPAR LOrExp Y_RPAR Stmt Y_ELSE Y_RETURN Exp Y_SEMICOLON  */
#line 144 "lrparser.y"
                                                                      {(yyval.pAst) = newIfStmt((yyvsp[-6].pAst),(yyvsp[-4].pAst),newReturnStmt((yyvsp[-1].pAst), NULL));}
#line 1646 "lrparser.tab.c"
    break;

  case 64: /* Stmt: Y_IF Y_LPAR LOrExp Y_RPAR Stmt Y_ELSE Y_RETURN Y_SEMICOLON  */
#line 145 "lrparser.y"
                                                                  {(yyval.pAst) = newIfStmt((yyvsp[-5].pAst),(yyvsp[-3].pAst),newReturnStmt(NULL, NULL));}
#line 1652 "lrparser.tab.c"
    break;

  case 65: /* Stmt: Y_IF Y_LPAR LOrExp Y_RPAR Stmt Y_ELSE LVal Y_ASSIGN Exp Y_SEMICOLON  */
#line 146 "lrparser.y"
                                                                           {(yyval.pAst) = newIfStmt((yyvsp[-7].pAst), (yyvsp[-5].pAst),newBinaryOper("=", Y_ASSIGN, (yyvsp[-3].pAst), (yyvsp[-1].pAst)));}
#line 1658 "lrparser.tab.c"
    break;

  case 66: /* Stmt: Y_IF Y_LPAR LOrExp Y_RPAR Stmt Y_ELSE Y_IF Y_LPAR LOrExp Y_RPAR Stmt  */
#line 147 "lrparser.y"
                                                                            {(yyval.pAst) = newIfStmt((yyvsp[-8].pAst),(yyvsp[-6].pAst),newIfStmt((yyvsp[-2].pAst),(yyvsp[0].pAst),NULL));}
#line 1664 "lrparser.tab.c"
    break;

  case 67: /* Stmt: Y_IF Y_LPAR LOrExp Y_RPAR Stmt Y_ELSE Y_IF Y_LPAR LOrExp Y_RPAR Stmt Y_ELSE Stmt  */
#line 148 "lrparser.y"
                                                                                        {(yyval.pAst) = newIfStmt((yyvsp[-10].pAst),(yyvsp[-8].pAst),newIfStmt((yyvsp[-4].pAst),(yyvsp[-2].pAst),(yyvsp[0].pAst)));}
#line 1670 "lrparser.tab.c"
    break;

  case 68: /* Stmt: Y_BREAK Y_SEMICOLON  */
#line 150 "lrparser.y"
                           {(yyval.pAst) = newBreakStmt();}
#line 1676 "lrparser.tab.c"
    break;

  case 69: /* Stmt: Y_CONTINUE Y_SEMICOLON  */
#line 151 "lrparser.y"
                              {(yyval.pAst) = newContinueStmt();}
#line 1682 "lrparser.tab.c"
    break;

  case 70: /* Stmt: Y_RETURN Exp Y_SEMICOLON  */
#line 152 "lrparser.y"
                                {(yyval.pAst) = newReturnStmt((yyvsp[-1].pAst), NULL);}
#line 1688 "lrparser.tab.c"
    break;

  case 71: /* Stmt: Y_RETURN Y_SEMICOLON  */
#line 153 "lrparser.y"
                            {(yyval.pAst) = newReturnStmt(NULL, NULL);}
#line 1694 "lrparser.tab.c"
    break;

  case 72: /* Block: Y_LBRACKET BlockItems Y_RBRACKET  */
#line 156 "lrparser.y"
                                        {(yyval.pAst) = newCompoundStmt(NULL,(yyvsp[-1].pAst));}
#line 1700 "lrparser.tab.c"
    break;

  case 73: /* Block: Y_LBRACKET Y_RBRACKET  */
#line 157 "lrparser.y"
                              {(yyval.pAst) = NULL;}
#line 1706 "lrparser.tab.c"
    break;

  case 74: /* BlockItems: BlockItem  */
#line 160 "lrparser.y"
                      {(yyval.pAst) = newCompoundStmt((yyvsp[0].pAst), NULL);}
#line 1712 "lrparser.tab.c"
    break;

  case 75: /* BlockItems: BlockItem BlockItems  */
#line 161 "lrparser.y"
                                  {past l = newCompoundStmt((yyvsp[-1].pAst), NULL); l->right = (yyvsp[0].pAst); (yyval.pAst) = l;}
#line 1718 "lrparser.tab.c"
    break;

  case 79: /* RelExp: AddExp Y_LESS RelExp  */
#line 169 "lrparser.y"
                              {(yyval.pAst) = newBinaryOper("<", Y_LESS, (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1724 "lrparser.tab.c"
    break;

  case 80: /* RelExp: AddExp Y_GREAT RelExp  */
#line 170 "lrparser.y"
                               {(yyval.pAst) = newBinaryOper(">", Y_GREAT, (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1730 "lrparser.tab.c"
    break;

  case 81: /* RelExp: AddExp Y_LESSEQ RelExp  */
#line 171 "lrparser.y"
                                {(yyval.pAst) = newBinaryOper("<=", Y_LESSEQ, (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1736 "lrparser.tab.c"
    break;

  case 82: /* RelExp: AddExp Y_GREATEQ RelExp  */
#line 172 "lrparser.y"
                                 {(yyval.pAst) = newBinaryOper(">=", Y_GREATEQ, (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1742 "lrparser.tab.c"
    break;

  case 84: /* EqExp: RelExp Y_EQ EqExp  */
#line 176 "lrparser.y"
                          {(yyval.pAst) = newBinaryOper("==", Y_EQ, (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1748 "lrparser.tab.c"
    break;

  case 85: /* EqExp: RelExp Y_NOTEQ EqExp  */
#line 177 "lrparser.y"
                             {(yyval.pAst) = newBinaryOper("!=", Y_NOTEQ, (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1754 "lrparser.tab.c"
    break;

  case 87: /* LAndExp: EqExp Y_AND LAndExp  */
#line 181 "lrparser.y"
                              {(yyval.pAst) = newBinaryOper("&&", Y_AND, (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1760 "lrparser.tab.c"
    break;

  case 89: /* LOrExp: LAndExp Y_OR LOrExp  */
#line 185 "lrparser.y"
                             {(yyval.pAst) = newBinaryOper("||", Y_OR, (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1766 "lrparser.tab.c"
    break;

  case 92: /* AddExp: AddExp Y_ADD MulExp  */
#line 193 "lrparser.y"
                           {(yyval.pAst) = newBinaryOper("+", Y_ADD, (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1772 "lrparser.tab.c"
    break;

  case 93: /* AddExp: AddExp Y_SUB MulExp  */
#line 194 "lrparser.y"
                           {(yyval.pAst) = newBinaryOper("-", Y_SUB, (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1778 "lrparser.tab.c"
    break;

  case 95: /* MulExp: MulExp Y_MUL UnaryExp  */
#line 198 "lrparser.y"
                             {(yyval.pAst) = newBinaryOper("*", Y_MUL, (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1784 "lrparser.tab.c"
    break;

  case 96: /* MulExp: MulExp Y_DIV UnaryExp  */
#line 199 "lrparser.y"
                             {(yyval.pAst) = newBinaryOper("/", Y_DIV, (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1790 "lrparser.tab.c"
    break;

  case 97: /* MulExp: MulExp Y_MODULO UnaryExp  */
#line 200 "lrparser.y"
                                {(yyval.pAst) = newBinaryOper("%", Y_MODULO, (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1796 "lrparser.tab.c"
    break;

  case 99: /* UnaryExp: Y_ID Y_LPAR Y_RPAR  */
#line 204 "lrparser.y"
                          {(yyval.pAst) = newCallExp(NULL, 0, (yyvsp[-2].id_name), NULL, NULL);}
#line 1802 "lrparser.tab.c"
    break;

  case 100: /* UnaryExp: Y_ID Y_LPAR CallParams Y_RPAR  */
#line 205 "lrparser.y"
                                     {(yyval.pAst) = newCallExp(NULL, 0, (yyvsp[-3].id_name), (yyvsp[-1].pAst), NULL);}
#line 1808 "lrparser.tab.c"
    break;

  case 101: /* UnaryExp: Y_ADD UnaryExp  */
#line 206 "lrparser.y"
                      {(yyval.pAst) = newUnaryOper("+", Y_ADD, NULL, (yyvsp[0].pAst));}
#line 1814 "lrparser.tab.c"
    break;

  case 102: /* UnaryExp: Y_SUB UnaryExp  */
#line 207 "lrparser.y"
                      {(yyval.pAst) = newUnaryOper("-", Y_SUB, NULL, (yyvsp[0].pAst));}
#line 1820 "lrparser.tab.c"
    break;

  case 103: /* UnaryExp: Y_NOT UnaryExp  */
#line 208 "lrparser.y"
                      {(yyval.pAst) = newUnaryOper("!", Y_NOT, NULL, (yyvsp[0].pAst));}
#line 1826 "lrparser.tab.c"
    break;

  case 105: /* CallParams: Exp Y_COMMA CallParams  */
#line 212 "lrparser.y"
                              {(yyvsp[-2].pAst)->next = (yyvsp[0].pAst);(yyval.pAst) = (yyvsp[-2].pAst) ;}
#line 1832 "lrparser.tab.c"
    break;

  case 106: /* PrimaryExp: Y_LPAR Exp Y_RPAR  */
#line 215 "lrparser.y"
                              {past node = newAstAny((yyvsp[-1].pAst),NULL,"PAREN_EXPR",INIT_LIST_EXPR);(yyval.pAst) = node;}
#line 1838 "lrparser.tab.c"
    break;

  case 108: /* PrimaryExp: num_INT  */
#line 217 "lrparser.y"
               {(yyval.pAst) = newIntVal((yyvsp[0].int_value));}
#line 1844 "lrparser.tab.c"
    break;

  case 109: /* PrimaryExp: num_FLOAT  */
#line 218 "lrparser.y"
                 {(yyval.pAst) = newFloatVal((yyvsp[0].float_value));}
#line 1850 "lrparser.tab.c"
    break;

  case 110: /* LVal: Y_ID  */
#line 221 "lrparser.y"
           {(yyval.pAst) = newDeclRefExp((yyvsp[0].id_name), NULL, NULL);}
#line 1856 "lrparser.tab.c"
    break;

  case 111: /* LVal: Y_ID ArraySubscripts  */
#line 222 "lrparser.y"
                           {past node = newDeclRefExp((yyvsp[-1].id_name),NULL,NULL);past node2 = (yyvsp[0].pAst);while(node2->left!=NULL) node2 = node2->left;node2->left = node;(yyval.pAst) = (yyvsp[0].pAst);}
#line 1862 "lrparser.tab.c"
    break;

  case 112: /* ArraySubscripts: Y_LSQUARE Exp Y_RSQUARE  */
#line 225 "lrparser.y"
                                         {(yyval.pAst) = newArraySubscriptsExp(NULL,(yyvsp[-1].pAst));}
#line 1868 "lrparser.tab.c"
    break;

  case 113: /* ArraySubscripts: ArraySubscripts Y_LSQUARE Exp Y_RSQUARE  */
#line 226 "lrparser.y"
                                                         {(yyval.pAst) = newArraySubscriptsExp((yyvsp[-3].pAst), (yyvsp[-1].pAst));}
#line 1874 "lrparser.tab.c"
    break;


#line 1878 "lrparser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 229 "lrparser.y"

