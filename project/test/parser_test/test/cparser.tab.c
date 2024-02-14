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
#line 1 "cparser.y"

    #include<stdio.h>
    #include<stdlib.h>
    #include<ctype.h>

    int yylex();
    void yyerror(const char* s);
    

#line 81 "cparser.tab.c"

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

#include "cparser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ADD_ASSIGN = 3,                 /* ADD_ASSIGN  */
  YYSYMBOL_AND = 4,                        /* AND  */
  YYSYMBOL_BIT_AND_ASSIGN = 5,             /* BIT_AND_ASSIGN  */
  YYSYMBOL_BIT_OR_ASSIGN = 6,              /* BIT_OR_ASSIGN  */
  YYSYMBOL_BIT_XOR_ASSIGN = 7,             /* BIT_XOR_ASSIGN  */
  YYSYMBOL_FOR = 8,                        /* FOR  */
  YYSYMBOL_BREAK = 9,                      /* BREAK  */
  YYSYMBOL_CASE = 10,                      /* CASE  */
  YYSYMBOL_CHAR = 11,                      /* CHAR  */
  YYSYMBOL_CONTINUE = 12,                  /* CONTINUE  */
  YYSYMBOL_C_CHAR = 13,                    /* C_CHAR  */
  YYSYMBOL_C_FLOAT = 14,                   /* C_FLOAT  */
  YYSYMBOL_C_INT = 15,                     /* C_INT  */
  YYSYMBOL_C_STRING = 16,                  /* C_STRING  */
  YYSYMBOL_DEFAULT = 17,                   /* DEFAULT  */
  YYSYMBOL_DIV_ASSIGN = 18,                /* DIV_ASSIGN  */
  YYSYMBOL_DO = 19,                        /* DO  */
  YYSYMBOL_ELSE = 20,                      /* ELSE  */
  YYSYMBOL_EQUAL = 21,                     /* EQUAL  */
  YYSYMBOL_FLOAT = 22,                     /* FLOAT  */
  YYSYMBOL_GREATER_EQUAL = 23,             /* GREATER_EQUAL  */
  YYSYMBOL_ID = 24,                        /* ID  */
  YYSYMBOL_IF = 25,                        /* IF  */
  YYSYMBOL_INT = 26,                       /* INT  */
  YYSYMBOL_LEFT_SHIFT = 27,                /* LEFT_SHIFT  */
  YYSYMBOL_LEFT_SHIFT_ASSIGN = 28,         /* LEFT_SHIFT_ASSIGN  */
  YYSYMBOL_LESS_EQUAL = 29,                /* LESS_EQUAL  */
  YYSYMBOL_MOD_ASSIGN = 30,                /* MOD_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 31,                /* MUL_ASSIGN  */
  YYSYMBOL_OR = 32,                        /* OR  */
  YYSYMBOL_POINTER = 33,                   /* POINTER  */
  YYSYMBOL_RETURN = 34,                    /* RETURN  */
  YYSYMBOL_RIGHT_SHIFT = 35,               /* RIGHT_SHIFT  */
  YYSYMBOL_RIGHT_SHIFT_ASSIGN = 36,        /* RIGHT_SHIFT_ASSIGN  */
  YYSYMBOL_SELF_ADD = 37,                  /* SELF_ADD  */
  YYSYMBOL_SELF_SUB = 38,                  /* SELF_SUB  */
  YYSYMBOL_SIZEOF = 39,                    /* SIZEOF  */
  YYSYMBOL_STRUCT = 40,                    /* STRUCT  */
  YYSYMBOL_SUB_ASSIGN = 41,                /* SUB_ASSIGN  */
  YYSYMBOL_SWITCH = 42,                    /* SWITCH  */
  YYSYMBOL_TYPEDEF = 43,                   /* TYPEDEF  */
  YYSYMBOL_UNEQUAL = 44,                   /* UNEQUAL  */
  YYSYMBOL_UNION = 45,                     /* UNION  */
  YYSYMBOL_VOID = 46,                      /* VOID  */
  YYSYMBOL_WHILE = 47,                     /* WHILE  */
  YYSYMBOL_DOUBLE = 48,                    /* DOUBLE  */
  YYSYMBOL_SHORT = 49,                     /* SHORT  */
  YYSYMBOL_LONG = 50,                      /* LONG  */
  YYSYMBOL_UNSIGNED = 51,                  /* UNSIGNED  */
  YYSYMBOL_STATIC = 52,                    /* STATIC  */
  YYSYMBOL_AUTO = 53,                      /* AUTO  */
  YYSYMBOL_CONST = 54,                     /* CONST  */
  YYSYMBOL_ENUM = 55,                      /* ENUM  */
  YYSYMBOL_ERROR = 56,                     /* ERROR  */
  YYSYMBOL_57_ = 57,                       /* ':'  */
  YYSYMBOL_58_ = 58,                       /* '{'  */
  YYSYMBOL_59_ = 59,                       /* '}'  */
  YYSYMBOL_60_ = 60,                       /* ';'  */
  YYSYMBOL_61_ = 61,                       /* '('  */
  YYSYMBOL_62_ = 62,                       /* ')'  */
  YYSYMBOL_63_ = 63,                       /* ','  */
  YYSYMBOL_64_ = 64,                       /* '['  */
  YYSYMBOL_65_ = 65,                       /* ']'  */
  YYSYMBOL_66_ = 66,                       /* '.'  */
  YYSYMBOL_67_ = 67,                       /* '&'  */
  YYSYMBOL_68_ = 68,                       /* '*'  */
  YYSYMBOL_69_ = 69,                       /* '+'  */
  YYSYMBOL_70_ = 70,                       /* '-'  */
  YYSYMBOL_71_ = 71,                       /* '~'  */
  YYSYMBOL_72_ = 72,                       /* '!'  */
  YYSYMBOL_73_ = 73,                       /* '/'  */
  YYSYMBOL_74_ = 74,                       /* '%'  */
  YYSYMBOL_75_ = 75,                       /* '<'  */
  YYSYMBOL_76_ = 76,                       /* '>'  */
  YYSYMBOL_77_ = 77,                       /* '^'  */
  YYSYMBOL_78_ = 78,                       /* '|'  */
  YYSYMBOL_79_ = 79,                       /* '?'  */
  YYSYMBOL_80_ = 80,                       /* '='  */
  YYSYMBOL_YYACCEPT = 81,                  /* $accept  */
  YYSYMBOL_ccode = 82,                     /* ccode  */
  YYSYMBOL_stm = 83,                       /* stm  */
  YYSYMBOL_labeled_stm = 84,               /* labeled_stm  */
  YYSYMBOL_compound_stm = 85,              /* compound_stm  */
  YYSYMBOL_dec_list = 86,                  /* dec_list  */
  YYSYMBOL_stm_list = 87,                  /* stm_list  */
  YYSYMBOL_exp_stm = 88,                   /* exp_stm  */
  YYSYMBOL_for_loop_exp = 89,              /* for_loop_exp  */
  YYSYMBOL_iteration_stm = 90,             /* iteration_stm  */
  YYSYMBOL_selection_stm = 91,             /* selection_stm  */
  YYSYMBOL_jump_stm = 92,                  /* jump_stm  */
  YYSYMBOL_exp = 93,                       /* exp  */
  YYSYMBOL_primary_exp = 94,               /* primary_exp  */
  YYSYMBOL_postfix_exp = 95,               /* postfix_exp  */
  YYSYMBOL_argument_exp_list = 96,         /* argument_exp_list  */
  YYSYMBOL_unary_exp = 97,                 /* unary_exp  */
  YYSYMBOL_cast_exp = 98,                  /* cast_exp  */
  YYSYMBOL_multiplicative_exp = 99,        /* multiplicative_exp  */
  YYSYMBOL_shift_exp = 100,                /* shift_exp  */
  YYSYMBOL_relational_exp = 101,           /* relational_exp  */
  YYSYMBOL_equality_exp = 102,             /* equality_exp  */
  YYSYMBOL_AND_exp = 103,                  /* AND_exp  */
  YYSYMBOL_additive_exp = 104,             /* additive_exp  */
  YYSYMBOL_exclusive_OR_exp = 105,         /* exclusive_OR_exp  */
  YYSYMBOL_inclusive_OR_exp = 106,         /* inclusive_OR_exp  */
  YYSYMBOL_logical_AND_exp = 107,          /* logical_AND_exp  */
  YYSYMBOL_logical_OR_exp = 108,           /* logical_OR_exp  */
  YYSYMBOL_conditional_exp = 109,          /* conditional_exp  */
  YYSYMBOL_assignment_exp = 110,           /* assignment_exp  */
  YYSYMBOL_constant_exp = 111,             /* constant_exp  */
  YYSYMBOL_dec = 112,                      /* dec  */
  YYSYMBOL_specifiers = 113,               /* specifiers  */
  YYSYMBOL_init_dec_list = 114,            /* init_dec_list  */
  YYSYMBOL_init_declarator = 115,          /* init_declarator  */
  YYSYMBOL_struct_or_union_specifier = 116, /* struct_or_union_specifier  */
  YYSYMBOL_struct_dec_list = 117,          /* struct_dec_list  */
  YYSYMBOL_struct_dec = 118,               /* struct_dec  */
  YYSYMBOL_struct_declarator_list = 119,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 120,        /* struct_declarator  */
  YYSYMBOL_declarator = 121,               /* declarator  */
  YYSYMBOL_direct_declarator = 122,        /* direct_declarator  */
  YYSYMBOL_pointer = 123,                  /* pointer  */
  YYSYMBOL_parameter_list = 124,           /* parameter_list  */
  YYSYMBOL_parameter_dec = 125,            /* parameter_dec  */
  YYSYMBOL_identifier_list = 126,          /* identifier_list  */
  YYSYMBOL_type_name = 127,                /* type_name  */
  YYSYMBOL_typedef_name = 128,             /* typedef_name  */
  YYSYMBOL_initializer = 129,              /* initializer  */
  YYSYMBOL_initializer_list = 130,         /* initializer_list  */
  YYSYMBOL_designation = 131,              /* designation  */
  YYSYMBOL_designator_list = 132,          /* designator_list  */
  YYSYMBOL_designator = 133,               /* designator  */
  YYSYMBOL_func_def = 134                  /* func_def  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  110
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1120

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  81
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  180
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  319

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   311


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
       2,     2,     2,    72,     2,     2,     2,    74,    67,     2,
      61,    62,    68,    69,    63,    70,    66,    73,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    57,    60,
      75,    80,    76,    79,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    64,     2,    65,    77,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,    78,    59,    71,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    52,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    64,    65,    66,    67,    68,    69,    73,    74,    78,
      79,    80,    81,    85,    86,    90,    91,    94,    95,    99,
     100,   104,   105,   106,   110,   111,   112,   116,   117,   118,
     119,   123,   124,   128,   129,   130,   131,   132,   133,   137,
     138,   139,   140,   141,   142,   143,   144,   148,   149,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   166,
     167,   171,   172,   173,   174,   178,   179,   180,   184,   185,
     186,   187,   188,   192,   193,   194,   198,   199,   203,   204,
     205,   209,   210,   214,   215,   219,   220,   224,   225,   229,
     230,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   249,   253,   254,   258,   259,   260,   261,
     262,   263,   264,   268,   269,   273,   274,   278,   279,   280,
     281,   282,   283,   287,   288,   291,   292,   293,   297,   298,
     302,   303,   304,   308,   309,   314,   315,   316,   317,   318,
     319,   320,   321,   325,   326,   330,   331,   335,   339,   340,
     344,   345,   346,   347,   348,   349,   353,   357,   358,   359,
     363,   364,   365,   366,   370,   374,   375,   379,   380,   384,
     385
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
  "\"end of file\"", "error", "\"invalid token\"", "ADD_ASSIGN", "AND",
  "BIT_AND_ASSIGN", "BIT_OR_ASSIGN", "BIT_XOR_ASSIGN", "FOR", "BREAK",
  "CASE", "CHAR", "CONTINUE", "C_CHAR", "C_FLOAT", "C_INT", "C_STRING",
  "DEFAULT", "DIV_ASSIGN", "DO", "ELSE", "EQUAL", "FLOAT", "GREATER_EQUAL",
  "ID", "IF", "INT", "LEFT_SHIFT", "LEFT_SHIFT_ASSIGN", "LESS_EQUAL",
  "MOD_ASSIGN", "MUL_ASSIGN", "OR", "POINTER", "RETURN", "RIGHT_SHIFT",
  "RIGHT_SHIFT_ASSIGN", "SELF_ADD", "SELF_SUB", "SIZEOF", "STRUCT",
  "SUB_ASSIGN", "SWITCH", "TYPEDEF", "UNEQUAL", "UNION", "VOID", "WHILE",
  "DOUBLE", "SHORT", "LONG", "UNSIGNED", "STATIC", "AUTO", "CONST", "ENUM",
  "ERROR", "':'", "'{'", "'}'", "';'", "'('", "')'", "','", "'['", "']'",
  "'.'", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'",
  "'>'", "'^'", "'|'", "'?'", "'='", "$accept", "ccode", "stm",
  "labeled_stm", "compound_stm", "dec_list", "stm_list", "exp_stm",
  "for_loop_exp", "iteration_stm", "selection_stm", "jump_stm", "exp",
  "primary_exp", "postfix_exp", "argument_exp_list", "unary_exp",
  "cast_exp", "multiplicative_exp", "shift_exp", "relational_exp",
  "equality_exp", "AND_exp", "additive_exp", "exclusive_OR_exp",
  "inclusive_OR_exp", "logical_AND_exp", "logical_OR_exp",
  "conditional_exp", "assignment_exp", "constant_exp", "dec", "specifiers",
  "init_dec_list", "init_declarator", "struct_or_union_specifier",
  "struct_dec_list", "struct_dec", "struct_declarator_list",
  "struct_declarator", "declarator", "direct_declarator", "pointer",
  "parameter_list", "parameter_dec", "identifier_list", "type_name",
  "typedef_name", "initializer", "initializer_list", "designation",
  "designator_list", "designator", "func_def", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-232)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-159)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     494,   -40,   -34,   973,  -232,   -21,  -232,  -232,  -232,  -232,
     664,   664,  -232,  -232,   -11,  -232,    24,   866,  1000,  1000,
    1000,    -4,     8,  -232,     3,  -232,    31,   364,  -232,   744,
     973,   973,   973,   973,   973,   973,   324,  -232,  -232,  -232,
    -232,  -232,  -232,  -232,   -35,  -232,    86,    27,  -232,    60,
      40,    33,   -13,    30,   102,    22,    32,   108,   -19,  -232,
    -232,  -232,    54,  -232,  -232,  -232,  -232,   973,  -232,  -232,
    -232,  -232,   664,  -232,  -232,   -35,    78,   973,  -232,  -232,
     -23,   973,  -232,  -232,  -232,    93,   152,   973,   111,   152,
     973,  -232,  -232,   429,   534,  -232,    54,  -232,  -232,  -232,
    -232,   123,  -232,   113,  -232,  -232,  -232,  -232,  -232,  -232,
    -232,  -232,   -35,  -232,  -232,  -232,   973,  -232,  -232,   906,
     973,   149,   973,   973,   973,   973,   973,   973,   973,   973,
     973,   973,   973,   973,   973,   973,   973,   973,   973,   973,
     973,   973,   973,   973,   973,   973,   973,   973,   973,   973,
     973,   973,  -232,  -232,   -15,   115,    67,  -232,   144,    95,
      -2,   128,   133,   134,   140,   131,  -232,   152,  -232,    20,
     249,  -232,   137,   152,   939,   163,  -232,   599,  -232,  -232,
    -232,   143,  -232,   973,  -232,  -232,   181,  -232,    21,  -232,
    -232,  -232,  -232,  -232,  -232,  -232,  -232,  -232,  -232,  -232,
    -232,  -232,  -232,  -232,   102,   102,    40,    40,    40,    40,
      33,    33,   -13,    60,    60,    30,    22,    32,   108,     7,
     141,  -232,  -232,   -15,   933,  -232,  1062,   237,   704,    95,
     973,  -232,   973,   664,  1006,   973,  -232,   101,  -232,   170,
    -232,  -232,   664,  1036,  -232,   664,  -232,  -232,  -232,   973,
    -232,   973,  -232,  -232,   825,  -232,  -232,  -232,   184,  -232,
     -15,   187,  -232,   189,  -232,   167,   166,   180,   194,   233,
    -232,  -232,  -232,    97,   973,  -232,  -232,  -232,  -232,  -232,
     973,   234,  -232,    90,   933,    82,  -232,  -232,  -232,   152,
    -232,   242,  -232,   205,   973,   212,   664,  -232,  -232,   209,
    -232,  -232,   784,  -232,  -232,  -232,  -232,  -232,  -232,   214,
    -232,  -232,  -232,  -232,  -232,   933,   664,  -232,  -232
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      10,     0,     0,     0,   118,     0,    45,    46,    44,    47,
       0,     0,   120,    43,     0,   119,     0,     0,     0,     0,
       0,     0,     0,   116,     0,   117,     0,     0,    28,     0,
       0,     0,     0,     0,     0,     0,     0,     4,    11,    12,
      13,    15,    14,    16,     2,    49,    59,    69,    71,    88,
      78,    83,    86,    91,    75,    93,    95,    97,    99,   101,
      41,     5,     0,   121,   122,   165,     3,    30,    38,    43,
      69,   113,     0,    37,    18,     0,     0,     0,    54,    40,
       0,     0,    60,    61,    68,   129,   135,     0,   132,   135,
       0,    22,    25,     0,     0,    23,     0,   161,   163,   162,
     160,     0,   164,     0,    62,    63,    64,    65,    66,    67,
       1,     7,     6,     8,     9,    27,     0,    55,    56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   145,   115,     0,   153,     0,   123,   125,   144,
       0,     0,    29,     0,     0,     0,    39,   135,   166,     0,
       0,   133,     0,   135,     0,     0,    20,     0,    24,    21,
      26,   125,    48,     0,    42,    52,     0,    57,     0,    53,
     106,   110,   112,   111,   104,   108,   105,   103,   109,   107,
     102,    72,    73,    74,    76,    77,    82,    81,    79,    80,
      84,    85,    87,    89,    90,    92,    94,    96,    98,     0,
       0,   154,   114,     0,     0,   180,     0,     0,     0,   143,
      30,    17,     0,     0,     0,     0,   136,     0,   138,   140,
     128,   134,     0,     0,   131,     0,    19,    70,    51,     0,
      50,     0,   146,   124,     0,   167,   126,   179,   166,   152,
       0,     0,   155,     0,   148,     0,     0,     0,     0,    34,
     127,   142,   137,     0,     0,    36,   130,    31,    58,   100,
       0,     0,   170,     0,     0,     0,   175,   157,   150,     0,
     151,     0,   147,     0,    30,     0,     0,   139,   141,     0,
     178,   168,     0,   171,   174,   176,   156,   159,   149,     0,
      32,    35,   177,   169,   172,     0,     0,   173,    33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -232,  -232,     0,  -232,  -155,   121,   188,  -232,  -218,  -232,
    -232,  -232,     6,  -232,  -232,  -232,    71,   -16,   -80,    41,
     122,   142,   138,   132,   139,   153,   148,  -232,     4,    13,
    -231,     5,     2,  -232,    65,   261,   -88,  -123,  -232,    28,
     -38,   145,   154,  -232,    14,  -232,   264,  -232,  -202,  -232,
       9,  -232,    19,   271
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    36,    92,    38,    39,    93,    94,    40,   161,    41,
      42,    43,    75,    45,    46,   186,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      72,    95,   169,   156,   157,    63,   170,   171,   237,   238,
     181,   159,   160,   261,   262,   263,    64,    65,   256,   283,
     284,   285,   286,    66
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,   174,    62,   225,   271,    61,    44,    71,   142,   152,
      74,    76,   267,   150,   104,   105,   106,   107,   108,   109,
      85,    67,   152,    80,   158,   115,    68,    88,   116,    96,
     122,   143,   123,   124,   125,   101,   111,   166,    62,    73,
     116,   113,   112,   298,   152,   126,   154,   241,    78,   299,
      77,   241,   282,   155,    86,   127,   138,   128,   129,   154,
     151,    89,   139,   130,   251,   213,   214,   136,   131,    87,
     116,   257,   163,   162,    70,   137,   309,   235,   152,   234,
     236,   154,   303,   165,   116,   243,   250,   101,   155,    82,
      83,    84,    90,   172,   180,    96,   175,   144,   178,   147,
     314,    70,    70,    70,    70,    70,    70,   132,   140,   141,
     148,   241,   149,   317,   153,   154,   220,   201,   202,   203,
     241,   152,   155,   117,   118,   164,   188,   222,   133,   184,
     223,   239,   187,   134,   135,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   280,   119,   281,   301,
     120,   167,   121,   302,   235,     4,   227,   219,   154,   228,
      96,   272,   304,     4,   273,   155,    12,   247,   168,   173,
      15,   145,   146,   189,    12,   183,   168,   180,    15,   206,
     207,   208,   209,   155,    21,   182,   116,    23,   230,    24,
      25,   231,    21,   233,   116,    23,   116,    24,    25,   242,
     116,   232,    27,   252,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,   287,   224,   224,   245,   116,   274,    96,   260,
     266,   178,   292,   269,   293,   239,   162,   255,   268,    71,
     294,   265,   275,   248,   249,   277,  -158,  -158,     4,   288,
     289,   290,   291,   296,    70,   279,   295,   116,   300,    12,
       4,   258,   278,    15,   210,   211,   307,   255,   204,   205,
     308,    12,   310,   168,   312,    15,   316,    21,    71,   226,
      23,   177,    24,    25,    71,   215,   212,   216,   253,    21,
     102,   260,    23,   103,    24,    25,   311,   255,   218,   259,
     162,   297,   217,   306,   305,   229,    70,   114,   240,   221,
       0,   315,     0,     0,     0,   255,   318,     0,     0,     0,
       0,     0,    70,     0,   110,     0,     0,     0,   255,     0,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,    70,    12,     0,    13,    14,
      15,    70,     0,     0,     0,     0,     0,    16,    17,     0,
       0,    18,    19,    20,    21,     0,    22,    23,     0,    24,
      25,    26,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    27,    11,    28,    29,    12,     0,    13,    14,
      15,    30,    31,    32,    33,    34,    35,    16,    17,     0,
       0,    18,    19,    20,    21,     0,    22,    23,     0,    24,
      25,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,    91,    28,    29,     0,     0,     0,     0,
       0,    30,    31,    32,    33,    34,    35,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,     0,    11,     0,
       0,    12,     0,    13,    14,    15,     0,     0,     0,     0,
       0,     0,    16,    17,     0,     0,    18,    19,    20,    21,
       0,    22,    23,     0,    24,    25,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,   176,    28,
      29,     0,     0,     0,     0,     0,    30,    31,    32,    33,
      34,    35,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,    12,     0,    13,    14,
      15,     0,     0,     0,     0,     0,     0,    16,    17,     0,
       0,    18,    19,    20,    21,     0,    22,    23,     0,    24,
      25,    26,     1,     2,     3,     0,     5,     6,     7,     8,
       9,    10,    27,    11,    28,    29,     0,     0,    69,    14,
       0,    30,    31,    32,    33,    34,    35,    16,    17,     0,
       0,    18,    19,    20,     0,     0,    22,     0,     0,     0,
       0,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,   179,    28,    29,     0,     0,     0,     0,
       0,    30,    31,    32,    33,    34,    35,     1,     2,     3,
       0,     5,     6,     7,     8,     9,    10,     0,    11,     0,
       0,     0,     0,    69,    14,     0,     0,     0,     0,     0,
       0,     0,    16,    17,     0,     0,    18,    19,    20,     0,
       0,    22,     0,     0,     0,     0,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,   246,    28,
      29,     0,     0,     0,     0,     0,    30,    31,    32,    33,
      34,    35,     1,     2,     3,     0,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,     0,    69,    14,
       0,     0,     0,     0,     0,     0,     0,    16,    17,     0,
       0,    18,    19,    20,     0,     0,    22,     0,     0,     0,
       0,    26,     0,     0,     0,     4,     0,     6,     7,     8,
       9,     0,    27,     0,    28,    29,    12,     0,    13,     0,
      15,    30,    31,    32,    33,    34,    35,    16,     0,     0,
       0,    18,    19,    20,    21,     0,     0,    23,     0,    24,
      25,     0,     0,     0,     0,    97,     0,     6,     7,     8,
       9,     0,     0,     0,     0,    29,    98,     0,    13,   264,
      99,    30,    31,    32,    33,    34,    35,    16,     0,     0,
       0,    18,    19,    20,    21,     0,     0,     0,     0,    24,
     100,     0,     0,     0,     0,     0,     0,     6,     7,     8,
       9,     0,     0,     0,     0,    29,     0,     0,    69,     0,
       0,    30,    31,    32,    33,    34,    35,    16,     0,     0,
       0,    18,    19,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     7,
       8,     9,   254,   313,     0,    29,     0,     0,   280,    69,
     281,    30,    31,    32,    33,    34,    35,     0,    16,     0,
       0,     0,    18,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     6,
       7,     8,     9,   254,     0,     0,    29,     0,     0,   280,
      69,   281,    30,    31,    32,    33,    34,    35,     0,    16,
       0,     0,     0,    18,    19,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     6,
       7,     8,     9,     0,     0,     0,    79,    29,     0,     0,
      69,     0,     0,    30,    31,    32,    33,    34,    35,    16,
       0,     0,     0,    18,    19,    20,     6,     7,     8,     9,
       4,     0,     0,     0,     0,     0,     0,    69,     0,     0,
       0,    12,     0,   168,     0,    15,    16,    29,   185,     0,
      18,    19,    20,    30,    31,    32,    33,    34,    35,    21,
       0,     0,    23,     0,    24,    25,     6,     7,     8,     9,
       0,   254,     0,     0,    29,     0,     0,    69,   244,     0,
      30,    31,    32,    33,    34,    35,    16,     0,     0,     0,
      18,    19,    20,     6,     7,     8,     9,     4,     0,     0,
       0,     0,     0,     0,    69,     0,     0,     0,    12,     0,
     168,     0,    15,    16,    29,     0,     0,    18,    19,    20,
      30,    31,    32,    33,    34,    35,    21,     4,     0,    23,
       0,    24,    25,     0,     0,     0,     0,     0,    12,     0,
     168,    81,    15,     0,     0,   270,     0,    30,    31,    32,
      33,    34,    35,     4,     0,     0,    21,     0,     0,    23,
       0,    24,    25,     0,    12,     0,   168,     0,    15,     0,
       0,     0,     0,     0,     0,   276,     0,     0,     0,     0,
       0,     0,    21,     0,     0,    23,     0,    24,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27
};

static const yytype_int16 yycheck[] =
{
       0,    89,     0,   158,   235,     0,     0,     3,    21,    24,
      10,    11,   230,    32,    30,    31,    32,    33,    34,    35,
      24,    61,    24,    17,    62,    60,    60,    24,    63,    27,
       3,    44,     5,     6,     7,    29,    36,    60,    36,    60,
      63,    36,    36,   274,    24,    18,    61,   170,    24,   280,
      61,   174,   254,    68,    58,    28,    23,    30,    31,    61,
      79,    58,    29,    36,    57,   145,   146,    27,    41,    61,
      63,   226,    72,    67,     3,    35,   294,    57,    24,   167,
      60,    61,   284,    77,    63,   173,    65,    81,    68,    18,
      19,    20,    61,    87,    94,    93,    90,    67,    93,    77,
     302,    30,    31,    32,    33,    34,    35,    80,    75,    76,
      78,   234,     4,   315,    60,    61,   154,   133,   134,   135,
     243,    24,    68,    37,    38,    47,   120,    60,    68,   116,
      63,   169,   119,    73,    74,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,    64,    61,    66,    59,
      64,    58,    66,    63,    57,    11,    61,   151,    61,    64,
     158,    60,    80,    11,    63,    68,    22,   183,    24,    58,
      26,    69,    70,    24,    22,    62,    24,   177,    26,   138,
     139,   140,   141,    68,    40,    62,    63,    43,    60,    45,
      46,    57,    40,    62,    63,    43,    63,    45,    46,    62,
      63,    61,    58,    62,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   260,    80,    80,    62,    63,    57,   226,   227,
     228,   226,    65,   233,    68,   273,   230,   224,   232,   235,
      60,   228,   242,    62,    63,   245,    62,    63,    11,    62,
      63,    62,    63,    20,   183,   251,    62,    63,    24,    22,
      11,    24,   249,    26,   142,   143,    24,   254,   136,   137,
      65,    22,    60,    24,    65,    26,    62,    40,   274,   158,
      43,    93,    45,    46,   280,   147,   144,   148,   223,    40,
      29,   289,    43,    29,    45,    46,   296,   284,   150,    62,
     294,   273,   149,   289,   285,   160,   235,    36,    59,   155,
      -1,   302,    -1,    -1,    -1,   302,   316,    -1,    -1,    -1,
      -1,    -1,   251,    -1,     0,    -1,    -1,    -1,   315,    -1,
      -1,    -1,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    19,    -1,   274,    22,    -1,    24,    25,
      26,   280,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      -1,    37,    38,    39,    40,    -1,    42,    43,    -1,    45,
      46,    47,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    58,    19,    60,    61,    22,    -1,    24,    25,
      26,    67,    68,    69,    70,    71,    72,    33,    34,    -1,
      -1,    37,    38,    39,    40,    -1,    42,    43,    -1,    45,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    71,    72,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    19,    -1,
      -1,    22,    -1,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    -1,    37,    38,    39,    40,
      -1,    42,    43,    -1,    45,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    19,    -1,    -1,    22,    -1,    24,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      -1,    37,    38,    39,    40,    -1,    42,    43,    -1,    45,
      46,    47,     8,     9,    10,    -1,    12,    13,    14,    15,
      16,    17,    58,    19,    60,    61,    -1,    -1,    24,    25,
      -1,    67,    68,    69,    70,    71,    72,    33,    34,    -1,
      -1,    37,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    71,    72,     8,     9,    10,
      -1,    12,    13,    14,    15,    16,    17,    -1,    19,    -1,
      -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    -1,    37,    38,    39,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,     8,     9,    10,    -1,    12,    13,    14,    15,
      16,    17,    -1,    19,    -1,    -1,    -1,    -1,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      -1,    37,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    -1,    11,    -1,    13,    14,    15,
      16,    -1,    58,    -1,    60,    61,    22,    -1,    24,    -1,
      26,    67,    68,    69,    70,    71,    72,    33,    -1,    -1,
      -1,    37,    38,    39,    40,    -1,    -1,    43,    -1,    45,
      46,    -1,    -1,    -1,    -1,    11,    -1,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    61,    22,    -1,    24,    65,
      26,    67,    68,    69,    70,    71,    72,    33,    -1,    -1,
      -1,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    61,    -1,    -1,    24,    -1,
      -1,    67,    68,    69,    70,    71,    72,    33,    -1,    -1,
      -1,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      15,    16,    58,    59,    -1,    61,    -1,    -1,    64,    24,
      66,    67,    68,    69,    70,    71,    72,    -1,    33,    -1,
      -1,    -1,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    15,    16,    58,    -1,    -1,    61,    -1,    -1,    64,
      24,    66,    67,    68,    69,    70,    71,    72,    -1,    33,
      -1,    -1,    -1,    37,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    15,    16,    -1,    -1,    -1,    60,    61,    -1,    -1,
      24,    -1,    -1,    67,    68,    69,    70,    71,    72,    33,
      -1,    -1,    -1,    37,    38,    39,    13,    14,    15,    16,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    22,    -1,    24,    -1,    26,    33,    61,    62,    -1,
      37,    38,    39,    67,    68,    69,    70,    71,    72,    40,
      -1,    -1,    43,    -1,    45,    46,    13,    14,    15,    16,
      -1,    58,    -1,    -1,    61,    -1,    -1,    24,    59,    -1,
      67,    68,    69,    70,    71,    72,    33,    -1,    -1,    -1,
      37,    38,    39,    13,    14,    15,    16,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    22,    -1,
      24,    -1,    26,    33,    61,    -1,    -1,    37,    38,    39,
      67,    68,    69,    70,    71,    72,    40,    11,    -1,    43,
      -1,    45,    46,    -1,    -1,    -1,    -1,    -1,    22,    -1,
      24,    61,    26,    -1,    -1,    59,    -1,    67,    68,    69,
      70,    71,    72,    11,    -1,    -1,    40,    -1,    -1,    43,
      -1,    45,    46,    -1,    22,    -1,    24,    -1,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    43,    -1,    45,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    19,    22,    24,    25,    26,    33,    34,    37,    38,
      39,    40,    42,    43,    45,    46,    47,    58,    60,    61,
      67,    68,    69,    70,    71,    72,    82,    83,    84,    85,
      88,    90,    91,    92,    93,    94,    95,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   112,   113,   116,   127,   128,   134,    61,    60,    24,
      97,   109,   111,    60,    83,    93,    83,    61,    24,    60,
      93,    61,    97,    97,    97,    24,    58,    61,    24,    58,
      61,    59,    83,    86,    87,   112,   113,    11,    22,    26,
      46,    93,   116,   127,    98,    98,    98,    98,    98,    98,
       0,    83,    93,   112,   134,    60,    63,    37,    38,    61,
      64,    66,     3,     5,     6,     7,    18,    28,    30,    31,
      36,    41,    80,    68,    73,    74,    27,    35,    23,    29,
      75,    76,    21,    44,    67,    69,    70,    77,    78,     4,
      32,    79,    24,    60,    61,    68,   114,   115,   121,   122,
     123,    89,    93,    83,    47,    93,    60,    58,    24,   113,
     117,   118,    93,    58,   117,    93,    59,    87,   112,    59,
      83,   121,    62,    62,   110,    62,    96,   110,    93,    24,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,    98,    98,    98,   104,   104,   100,   100,   100,   100,
     101,   101,   102,    99,    99,   103,   105,   106,   107,    93,
     121,   123,    60,    63,    80,    85,    86,    61,    64,   122,
      60,    57,    61,    62,   117,    57,    60,   119,   120,   121,
      59,   118,    62,   117,    59,    62,    59,    98,    62,    63,
      65,    57,    62,   115,    58,   110,   129,    85,    24,    62,
     113,   124,   125,   126,    65,   110,   113,    89,    93,    83,
      59,   111,    60,    63,    57,    83,    59,    83,   110,   109,
      64,    66,   129,   130,   131,   132,   133,   121,    62,    63,
      62,    63,    65,    68,    60,    62,    20,   120,   111,   111,
      24,    59,    63,   129,    80,   133,   125,    24,    65,    89,
      60,    83,    65,    59,   129,   131,    62,   129,    83
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    81,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    83,    83,    83,    83,    83,    83,    84,    84,    85,
      85,    85,    85,    86,    86,    87,    87,    88,    88,    89,
      89,    90,    90,    90,    91,    91,    91,    92,    92,    92,
      92,    93,    93,    94,    94,    94,    94,    94,    94,    95,
      95,    95,    95,    95,    95,    95,    95,    96,    96,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    98,
      98,    99,    99,    99,    99,   100,   100,   100,   101,   101,
     101,   101,   101,   102,   102,   102,   103,   103,   104,   104,
     104,   105,   105,   106,   106,   107,   107,   108,   108,   109,
     109,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   111,   112,   112,   113,   113,   113,   113,
     113,   113,   113,   114,   114,   115,   115,   116,   116,   116,
     116,   116,   116,   117,   117,   118,   118,   118,   119,   119,
     120,   120,   120,   121,   121,   122,   122,   122,   122,   122,
     122,   122,   122,   123,   123,   124,   124,   125,   126,   126,
     127,   127,   127,   127,   127,   127,   128,   129,   129,   129,
     130,   130,   130,   130,   131,   132,   132,   133,   133,   134,
     134
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     2,     2,     2,
       0,     1,     1,     1,     1,     1,     1,     4,     2,     4,
       3,     3,     2,     1,     2,     1,     2,     2,     1,     1,
       0,     5,     7,     9,     5,     7,     5,     2,     2,     3,
       2,     1,     3,     1,     1,     1,     1,     1,     3,     1,
       4,     4,     3,     3,     2,     2,     2,     1,     3,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       4,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     5,     4,     2,
       5,     4,     2,     1,     2,     0,     2,     3,     1,     3,
       1,     3,     2,     2,     1,     1,     3,     4,     3,     5,
       4,     4,     3,     1,     2,     1,     3,     2,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     4,
       1,     2,     3,     4,     2,     1,     2,     3,     2,     4,
       3
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
  case 2: /* ccode: exp  */
#line 52 "cparser.y"
                 {  printf("Reduced by rule: 1\n");  }
#line 1598 "cparser.tab.c"
    break;

  case 3: /* ccode: func_def  */
#line 53 "cparser.y"
                  {printf("Reduced by rule: 1.5\n");}
#line 1604 "cparser.tab.c"
    break;

  case 4: /* ccode: stm  */
#line 54 "cparser.y"
                 {  printf("Reduced by rule: 2\n");  }
#line 1610 "cparser.tab.c"
    break;

  case 5: /* ccode: dec  */
#line 55 "cparser.y"
                 {  printf("Reduced by rule: 3\n");  }
#line 1616 "cparser.tab.c"
    break;

  case 6: /* ccode: ccode exp  */
#line 56 "cparser.y"
                         {  printf("Reduced by rule: 4\n");  }
#line 1622 "cparser.tab.c"
    break;

  case 7: /* ccode: ccode stm  */
#line 57 "cparser.y"
                         {  printf("Reduced by rule: 5\n");  }
#line 1628 "cparser.tab.c"
    break;

  case 8: /* ccode: ccode dec  */
#line 58 "cparser.y"
                         {  printf("Reduced by rule: 6\n");  }
#line 1634 "cparser.tab.c"
    break;

  case 9: /* ccode: ccode func_def  */
#line 59 "cparser.y"
                        {	printf("Reduced by rule: 6.5\n"); }
#line 1640 "cparser.tab.c"
    break;

  case 10: /* ccode: %empty  */
#line 60 "cparser.y"
                 {  printf("Reduced by rule: 7\n");  }
#line 1646 "cparser.tab.c"
    break;

  case 11: /* stm: labeled_stm  */
#line 64 "cparser.y"
                                 {  printf("Reduced by rule: 8\n");  }
#line 1652 "cparser.tab.c"
    break;

  case 12: /* stm: compound_stm  */
#line 65 "cparser.y"
                         {  printf("Reduced by rule: 9\n");  }
#line 1658 "cparser.tab.c"
    break;

  case 13: /* stm: exp_stm  */
#line 66 "cparser.y"
                         {  printf("Reduced by rule: 10\n");  }
#line 1664 "cparser.tab.c"
    break;

  case 14: /* stm: selection_stm  */
#line 67 "cparser.y"
                         {  printf("Reduced by rule: 11\n");  }
#line 1670 "cparser.tab.c"
    break;

  case 15: /* stm: iteration_stm  */
#line 68 "cparser.y"
                         {  printf("Reduced by rule: 12\n");  }
#line 1676 "cparser.tab.c"
    break;

  case 16: /* stm: jump_stm  */
#line 69 "cparser.y"
                         {  printf("Reduced by rule: 13\n");  }
#line 1682 "cparser.tab.c"
    break;

  case 17: /* labeled_stm: CASE constant_exp stm ':'  */
#line 73 "cparser.y"
                                         {  printf("Reduced by rule: 14\n");  }
#line 1688 "cparser.tab.c"
    break;

  case 18: /* labeled_stm: DEFAULT stm  */
#line 74 "cparser.y"
                         {  printf("Reduced by rule: 15\n");  }
#line 1694 "cparser.tab.c"
    break;

  case 19: /* compound_stm: '{' dec_list stm_list '}'  */
#line 78 "cparser.y"
                                         {  printf("Reduced by rule: 16\n");  }
#line 1700 "cparser.tab.c"
    break;

  case 20: /* compound_stm: '{' dec_list '}'  */
#line 79 "cparser.y"
                                 {  printf("Reduced by rule: 17\n");  }
#line 1706 "cparser.tab.c"
    break;

  case 21: /* compound_stm: '{' stm_list '}'  */
#line 80 "cparser.y"
                                 {  printf("Reduced by rule: 18\n");  }
#line 1712 "cparser.tab.c"
    break;

  case 22: /* compound_stm: '{' '}'  */
#line 81 "cparser.y"
                         {  printf("Reduced by rule: 19\n");  }
#line 1718 "cparser.tab.c"
    break;

  case 23: /* dec_list: dec  */
#line 85 "cparser.y"
                 {  printf("Reduced by rule: 20\n");  }
#line 1724 "cparser.tab.c"
    break;

  case 24: /* dec_list: dec_list dec  */
#line 86 "cparser.y"
                         {  printf("Reduced by rule: 21\n");  }
#line 1730 "cparser.tab.c"
    break;

  case 25: /* stm_list: stm  */
#line 90 "cparser.y"
                 {  printf("Reduced by rule: 22\n");  }
#line 1736 "cparser.tab.c"
    break;

  case 26: /* stm_list: stm_list stm  */
#line 91 "cparser.y"
                         {  printf("Reduced by rule: 23\n");  }
#line 1742 "cparser.tab.c"
    break;

  case 27: /* exp_stm: exp ';'  */
#line 94 "cparser.y"
                 {  printf("Reduced by rule: 24\n");  }
#line 1748 "cparser.tab.c"
    break;

  case 28: /* exp_stm: ';'  */
#line 95 "cparser.y"
                 {  printf("Reduced by rule: 25\n");  }
#line 1754 "cparser.tab.c"
    break;

  case 29: /* for_loop_exp: exp  */
#line 99 "cparser.y"
                 {  printf("Reduced by rule: 26\n");  }
#line 1760 "cparser.tab.c"
    break;

  case 30: /* for_loop_exp: %empty  */
#line 100 "cparser.y"
                 {  printf("Reduced by rule: 27\n");  }
#line 1766 "cparser.tab.c"
    break;

  case 31: /* iteration_stm: WHILE '(' exp ')' stm  */
#line 104 "cparser.y"
                                         {  printf("Reduced by rule: 28\n");  }
#line 1772 "cparser.tab.c"
    break;

  case 32: /* iteration_stm: DO stm WHILE '(' exp ')' ';'  */
#line 105 "cparser.y"
                                                 {  printf("Reduced by rule: 29\n");  }
#line 1778 "cparser.tab.c"
    break;

  case 33: /* iteration_stm: FOR '(' for_loop_exp ';' for_loop_exp ';' for_loop_exp ')' stm  */
#line 106 "cparser.y"
                                                                                 {  printf("Reduced by rule: 30\n");  }
#line 1784 "cparser.tab.c"
    break;

  case 34: /* selection_stm: IF '(' exp ')' stm  */
#line 110 "cparser.y"
                                 {  printf("Reduced by rule: 31\n");  }
#line 1790 "cparser.tab.c"
    break;

  case 35: /* selection_stm: IF '(' exp ')' stm ELSE stm  */
#line 111 "cparser.y"
                                         {  printf("Reduced by rule: 32\n");  }
#line 1796 "cparser.tab.c"
    break;

  case 36: /* selection_stm: SWITCH '(' exp ')' stm  */
#line 112 "cparser.y"
                                 {  printf("Reduced by rule: 33\n");  }
#line 1802 "cparser.tab.c"
    break;

  case 37: /* jump_stm: CONTINUE ';'  */
#line 116 "cparser.y"
                         {  printf("Reduced by rule: 34\n");  }
#line 1808 "cparser.tab.c"
    break;

  case 38: /* jump_stm: BREAK ';'  */
#line 117 "cparser.y"
                         {  printf("Reduced by rule: 35\n");  }
#line 1814 "cparser.tab.c"
    break;

  case 39: /* jump_stm: RETURN exp ';'  */
#line 118 "cparser.y"
                         {  printf("Reduced by rule: 36\n");  }
#line 1820 "cparser.tab.c"
    break;

  case 40: /* jump_stm: RETURN ';'  */
#line 119 "cparser.y"
                         {  printf("Reduced by rule: 37\n");  }
#line 1826 "cparser.tab.c"
    break;

  case 41: /* exp: assignment_exp  */
#line 123 "cparser.y"
                         {  printf("Reduced by rule: 38\n");  }
#line 1832 "cparser.tab.c"
    break;

  case 42: /* exp: exp ',' assignment_exp  */
#line 124 "cparser.y"
                                 {  printf("Reduced by rule: 39\n");  }
#line 1838 "cparser.tab.c"
    break;

  case 43: /* primary_exp: ID  */
#line 128 "cparser.y"
                 {  printf("Reduced by rule: 40\n");  }
#line 1844 "cparser.tab.c"
    break;

  case 44: /* primary_exp: C_INT  */
#line 129 "cparser.y"
                 {  printf("Reduced by rule: 41\n");  }
#line 1850 "cparser.tab.c"
    break;

  case 45: /* primary_exp: C_CHAR  */
#line 130 "cparser.y"
                 {  printf("Reduced by rule: 42\n");  }
#line 1856 "cparser.tab.c"
    break;

  case 46: /* primary_exp: C_FLOAT  */
#line 131 "cparser.y"
                         {  printf("Reduced by rule: 43\n");  }
#line 1862 "cparser.tab.c"
    break;

  case 47: /* primary_exp: C_STRING  */
#line 132 "cparser.y"
                         {  printf("Reduced by rule: 44\n");  }
#line 1868 "cparser.tab.c"
    break;

  case 48: /* primary_exp: '(' exp ')'  */
#line 133 "cparser.y"
                         {  printf("Reduced by rule: 45\n");  }
#line 1874 "cparser.tab.c"
    break;

  case 49: /* postfix_exp: primary_exp  */
#line 137 "cparser.y"
                         {  printf("Reduced by rule: 46\n");  }
#line 1880 "cparser.tab.c"
    break;

  case 50: /* postfix_exp: postfix_exp '[' exp ']'  */
#line 138 "cparser.y"
                                         {  printf("Reduced by rule: 47\n");  }
#line 1886 "cparser.tab.c"
    break;

  case 51: /* postfix_exp: postfix_exp '(' argument_exp_list ')'  */
#line 139 "cparser.y"
                                                 {  printf("Reduced by rule: 48\n");  }
#line 1892 "cparser.tab.c"
    break;

  case 52: /* postfix_exp: postfix_exp '(' ')'  */
#line 140 "cparser.y"
                                 {  printf("Reduced by rule: 49\n");  }
#line 1898 "cparser.tab.c"
    break;

  case 53: /* postfix_exp: postfix_exp '.' ID  */
#line 141 "cparser.y"
                                 {  printf("Reduced by rule: 50\n");  }
#line 1904 "cparser.tab.c"
    break;

  case 54: /* postfix_exp: POINTER ID  */
#line 142 "cparser.y"
                         {  printf("Reduced by rule: 51\n");  }
#line 1910 "cparser.tab.c"
    break;

  case 55: /* postfix_exp: postfix_exp SELF_ADD  */
#line 143 "cparser.y"
                                 {  printf("Reduced by rule: 52\n");  }
#line 1916 "cparser.tab.c"
    break;

  case 56: /* postfix_exp: postfix_exp SELF_SUB  */
#line 144 "cparser.y"
                                 {  printf("Reduced by rule: 53\n");  }
#line 1922 "cparser.tab.c"
    break;

  case 57: /* argument_exp_list: assignment_exp  */
#line 148 "cparser.y"
                         {  printf("Reduced by rule: 54\n");  }
#line 1928 "cparser.tab.c"
    break;

  case 58: /* argument_exp_list: argument_exp_list ',' assignment_exp  */
#line 149 "cparser.y"
                                                 {  printf("Reduced by rule: 55\n");  }
#line 1934 "cparser.tab.c"
    break;

  case 59: /* unary_exp: postfix_exp  */
#line 153 "cparser.y"
                         {  printf("Reduced by rule: 56\n");  }
#line 1940 "cparser.tab.c"
    break;

  case 60: /* unary_exp: SELF_ADD unary_exp  */
#line 154 "cparser.y"
                                 {  printf("Reduced by rule: 57\n");  }
#line 1946 "cparser.tab.c"
    break;

  case 61: /* unary_exp: SELF_SUB unary_exp  */
#line 155 "cparser.y"
                                 {  printf("Reduced by rule: 58\n");  }
#line 1952 "cparser.tab.c"
    break;

  case 62: /* unary_exp: '&' cast_exp  */
#line 156 "cparser.y"
                         {  printf("Reduced by rule: 59\n");  }
#line 1958 "cparser.tab.c"
    break;

  case 63: /* unary_exp: '*' cast_exp  */
#line 157 "cparser.y"
                         {  printf("Reduced by rule: 60\n");  }
#line 1964 "cparser.tab.c"
    break;

  case 64: /* unary_exp: '+' cast_exp  */
#line 158 "cparser.y"
                         {  printf("Reduced by rule: 61\n");  }
#line 1970 "cparser.tab.c"
    break;

  case 65: /* unary_exp: '-' cast_exp  */
#line 159 "cparser.y"
                         {  printf("Reduced by rule: 62\n");  }
#line 1976 "cparser.tab.c"
    break;

  case 66: /* unary_exp: '~' cast_exp  */
#line 160 "cparser.y"
                         {  printf("Reduced by rule: 63\n");  }
#line 1982 "cparser.tab.c"
    break;

  case 67: /* unary_exp: '!' cast_exp  */
#line 161 "cparser.y"
                         {  printf("Reduced by rule: 64\n");  }
#line 1988 "cparser.tab.c"
    break;

  case 68: /* unary_exp: SIZEOF unary_exp  */
#line 162 "cparser.y"
                                 {  printf("Reduced by rule: 65\n");  }
#line 1994 "cparser.tab.c"
    break;

  case 69: /* cast_exp: unary_exp  */
#line 166 "cparser.y"
                         {  printf("Reduced by rule: 66\n");  }
#line 2000 "cparser.tab.c"
    break;

  case 70: /* cast_exp: '(' type_name ')' cast_exp  */
#line 167 "cparser.y"
                                         {  printf("Reduced by rule: 67\n");  }
#line 2006 "cparser.tab.c"
    break;

  case 71: /* multiplicative_exp: cast_exp  */
#line 171 "cparser.y"
                         {  printf("Reduced by rule: 68\n");  }
#line 2012 "cparser.tab.c"
    break;

  case 72: /* multiplicative_exp: multiplicative_exp '*' cast_exp  */
#line 172 "cparser.y"
                                                 {  printf("Reduced by rule: 69\n");  }
#line 2018 "cparser.tab.c"
    break;

  case 73: /* multiplicative_exp: multiplicative_exp '/' cast_exp  */
#line 173 "cparser.y"
                                                 {  printf("Reduced by rule: 70\n");  }
#line 2024 "cparser.tab.c"
    break;

  case 74: /* multiplicative_exp: multiplicative_exp '%' cast_exp  */
#line 174 "cparser.y"
                                                 {  printf("Reduced by rule: 71\n");  }
#line 2030 "cparser.tab.c"
    break;

  case 75: /* shift_exp: additive_exp  */
#line 178 "cparser.y"
                         {  printf("Reduced by rule: 72\n");  }
#line 2036 "cparser.tab.c"
    break;

  case 76: /* shift_exp: shift_exp LEFT_SHIFT additive_exp  */
#line 179 "cparser.y"
                                                 {  printf("Reduced by rule: 73\n");  }
#line 2042 "cparser.tab.c"
    break;

  case 77: /* shift_exp: shift_exp RIGHT_SHIFT additive_exp  */
#line 180 "cparser.y"
                                                 {  printf("Reduced by rule: 74\n");  }
#line 2048 "cparser.tab.c"
    break;

  case 78: /* relational_exp: shift_exp  */
#line 184 "cparser.y"
                         {  printf("Reduced by rule: 75\n");  }
#line 2054 "cparser.tab.c"
    break;

  case 79: /* relational_exp: relational_exp '<' shift_exp  */
#line 185 "cparser.y"
                                         {  printf("Reduced by rule: 76\n");  }
#line 2060 "cparser.tab.c"
    break;

  case 80: /* relational_exp: relational_exp '>' shift_exp  */
#line 186 "cparser.y"
                                         {  printf("Reduced by rule: 77\n");  }
#line 2066 "cparser.tab.c"
    break;

  case 81: /* relational_exp: relational_exp LESS_EQUAL shift_exp  */
#line 187 "cparser.y"
                                                 {  printf("Reduced by rule: 78\n");  }
#line 2072 "cparser.tab.c"
    break;

  case 82: /* relational_exp: relational_exp GREATER_EQUAL shift_exp  */
#line 188 "cparser.y"
                                                 {  printf("Reduced by rule: 79\n");  }
#line 2078 "cparser.tab.c"
    break;

  case 83: /* equality_exp: relational_exp  */
#line 192 "cparser.y"
                         {  printf("Reduced by rule: 80\n");  }
#line 2084 "cparser.tab.c"
    break;

  case 84: /* equality_exp: equality_exp EQUAL relational_exp  */
#line 193 "cparser.y"
                                                 {  printf("Reduced by rule: 81\n");  }
#line 2090 "cparser.tab.c"
    break;

  case 85: /* equality_exp: equality_exp UNEQUAL relational_exp  */
#line 194 "cparser.y"
                                                 {  printf("Reduced by rule: 82\n");  }
#line 2096 "cparser.tab.c"
    break;

  case 86: /* AND_exp: equality_exp  */
#line 198 "cparser.y"
                         {  printf("Reduced by rule: 83\n");  }
#line 2102 "cparser.tab.c"
    break;

  case 87: /* AND_exp: AND_exp '&' equality_exp  */
#line 199 "cparser.y"
                                         {  printf("Reduced by rule: 84\n");  }
#line 2108 "cparser.tab.c"
    break;

  case 88: /* additive_exp: multiplicative_exp  */
#line 203 "cparser.y"
                                 {  printf("Reduced by rule: 85\n");  }
#line 2114 "cparser.tab.c"
    break;

  case 89: /* additive_exp: additive_exp '+' multiplicative_exp  */
#line 204 "cparser.y"
                                                 {  printf("Reduced by rule: 86\n");  }
#line 2120 "cparser.tab.c"
    break;

  case 90: /* additive_exp: additive_exp '-' multiplicative_exp  */
#line 205 "cparser.y"
                                                 {  printf("Reduced by rule: 87\n");  }
#line 2126 "cparser.tab.c"
    break;

  case 91: /* exclusive_OR_exp: AND_exp  */
#line 209 "cparser.y"
                 {  printf("Reduced by rule: 88\n");  }
#line 2132 "cparser.tab.c"
    break;

  case 92: /* exclusive_OR_exp: exclusive_OR_exp '^' AND_exp  */
#line 210 "cparser.y"
                                         {  printf("Reduced by rule: 89\n");  }
#line 2138 "cparser.tab.c"
    break;

  case 93: /* inclusive_OR_exp: exclusive_OR_exp  */
#line 214 "cparser.y"
                                 {  printf("Reduced by rule: 90\n");  }
#line 2144 "cparser.tab.c"
    break;

  case 94: /* inclusive_OR_exp: inclusive_OR_exp '|' exclusive_OR_exp  */
#line 215 "cparser.y"
                                                 {  printf("Reduced by rule: 91\n");  }
#line 2150 "cparser.tab.c"
    break;

  case 95: /* logical_AND_exp: inclusive_OR_exp  */
#line 219 "cparser.y"
                                 {  printf("Reduced by rule: 92\n");  }
#line 2156 "cparser.tab.c"
    break;

  case 96: /* logical_AND_exp: logical_AND_exp AND inclusive_OR_exp  */
#line 220 "cparser.y"
                                                 {  printf("Reduced by rule: 93\n");  }
#line 2162 "cparser.tab.c"
    break;

  case 97: /* logical_OR_exp: logical_AND_exp  */
#line 224 "cparser.y"
                         {  printf("Reduced by rule: 94\n");  }
#line 2168 "cparser.tab.c"
    break;

  case 98: /* logical_OR_exp: logical_OR_exp OR logical_AND_exp  */
#line 225 "cparser.y"
                                                 {  printf("Reduced by rule: 95\n");  }
#line 2174 "cparser.tab.c"
    break;

  case 99: /* conditional_exp: logical_OR_exp  */
#line 229 "cparser.y"
                         {  printf("Reduced by rule: 96\n");  }
#line 2180 "cparser.tab.c"
    break;

  case 100: /* conditional_exp: logical_OR_exp '?' exp ':' conditional_exp  */
#line 230 "cparser.y"
                                                         {  printf("Reduced by rule: 97\n");  }
#line 2186 "cparser.tab.c"
    break;

  case 101: /* assignment_exp: conditional_exp  */
#line 234 "cparser.y"
                         {  printf("Reduced by rule: 98\n");  }
#line 2192 "cparser.tab.c"
    break;

  case 102: /* assignment_exp: unary_exp '=' assignment_exp  */
#line 235 "cparser.y"
                                         {  printf("Reduced by rule: 99\n");  }
#line 2198 "cparser.tab.c"
    break;

  case 103: /* assignment_exp: unary_exp MUL_ASSIGN assignment_exp  */
#line 236 "cparser.y"
                                                 {  printf("Reduced by rule: 100\n");  }
#line 2204 "cparser.tab.c"
    break;

  case 104: /* assignment_exp: unary_exp DIV_ASSIGN assignment_exp  */
#line 237 "cparser.y"
                                                 {  printf("Reduced by rule: 101\n");  }
#line 2210 "cparser.tab.c"
    break;

  case 105: /* assignment_exp: unary_exp MOD_ASSIGN assignment_exp  */
#line 238 "cparser.y"
                                                 {  printf("Reduced by rule: 102\n");  }
#line 2216 "cparser.tab.c"
    break;

  case 106: /* assignment_exp: unary_exp ADD_ASSIGN assignment_exp  */
#line 239 "cparser.y"
                                                 {  printf("Reduced by rule: 103\n");  }
#line 2222 "cparser.tab.c"
    break;

  case 107: /* assignment_exp: unary_exp SUB_ASSIGN assignment_exp  */
#line 240 "cparser.y"
                                                 {  printf("Reduced by rule: 104\n");  }
#line 2228 "cparser.tab.c"
    break;

  case 108: /* assignment_exp: unary_exp LEFT_SHIFT_ASSIGN assignment_exp  */
#line 241 "cparser.y"
                                                         {  printf("Reduced by rule: 105\n");  }
#line 2234 "cparser.tab.c"
    break;

  case 109: /* assignment_exp: unary_exp RIGHT_SHIFT_ASSIGN assignment_exp  */
#line 242 "cparser.y"
                                                         {  printf("Reduced by rule: 106\n");  }
#line 2240 "cparser.tab.c"
    break;

  case 110: /* assignment_exp: unary_exp BIT_AND_ASSIGN assignment_exp  */
#line 243 "cparser.y"
                                                         {  printf("Reduced by rule: 107\n");  }
#line 2246 "cparser.tab.c"
    break;

  case 111: /* assignment_exp: unary_exp BIT_XOR_ASSIGN assignment_exp  */
#line 244 "cparser.y"
                                                         {  printf("Reduced by rule: 108\n");  }
#line 2252 "cparser.tab.c"
    break;

  case 112: /* assignment_exp: unary_exp BIT_OR_ASSIGN assignment_exp  */
#line 245 "cparser.y"
                                                 {  printf("Reduced by rule: 109\n");  }
#line 2258 "cparser.tab.c"
    break;

  case 113: /* constant_exp: conditional_exp  */
#line 249 "cparser.y"
                         {  printf("Reduced by rule: 110\n");  }
#line 2264 "cparser.tab.c"
    break;

  case 114: /* dec: specifiers init_dec_list ';'  */
#line 253 "cparser.y"
                                         {  printf("Reduced by rule: 111\n");  }
#line 2270 "cparser.tab.c"
    break;

  case 116: /* specifiers: TYPEDEF  */
#line 258 "cparser.y"
                         {  printf("Reduced by rule: 112\n");  }
#line 2276 "cparser.tab.c"
    break;

  case 117: /* specifiers: VOID  */
#line 259 "cparser.y"
                 {  printf("Reduced by rule: 113\n");  }
#line 2282 "cparser.tab.c"
    break;

  case 118: /* specifiers: CHAR  */
#line 260 "cparser.y"
                 {  printf("Reduced by rule: 114\n");  }
#line 2288 "cparser.tab.c"
    break;

  case 119: /* specifiers: INT  */
#line 261 "cparser.y"
                 {  printf("Reduced by rule: 115\n");  }
#line 2294 "cparser.tab.c"
    break;

  case 120: /* specifiers: FLOAT  */
#line 262 "cparser.y"
                 {  printf("Reduced by rule: 116\n");  }
#line 2300 "cparser.tab.c"
    break;

  case 121: /* specifiers: struct_or_union_specifier  */
#line 263 "cparser.y"
                                         {  printf("Reduced by rule: 117\n");  }
#line 2306 "cparser.tab.c"
    break;

  case 122: /* specifiers: type_name  */
#line 264 "cparser.y"
                         {  printf("Reduced by rule: 118\n");  }
#line 2312 "cparser.tab.c"
    break;

  case 123: /* init_dec_list: init_declarator  */
#line 268 "cparser.y"
                         {  printf("Reduced by rule: 119\n");  }
#line 2318 "cparser.tab.c"
    break;

  case 124: /* init_dec_list: init_dec_list ',' init_declarator  */
#line 269 "cparser.y"
                                                 {  printf("Reduced by rule: 120\n");  }
#line 2324 "cparser.tab.c"
    break;

  case 125: /* init_declarator: declarator  */
#line 273 "cparser.y"
                         {  printf("Reduced by rule: 121\n");  }
#line 2330 "cparser.tab.c"
    break;

  case 126: /* init_declarator: declarator '=' initializer  */
#line 274 "cparser.y"
                                         {  printf("Reduced by rule: 122\n");  }
#line 2336 "cparser.tab.c"
    break;

  case 127: /* struct_or_union_specifier: STRUCT ID '{' struct_dec_list '}'  */
#line 278 "cparser.y"
                                                 {  printf("Reduced by rule: 123\n");  }
#line 2342 "cparser.tab.c"
    break;

  case 128: /* struct_or_union_specifier: STRUCT '{' struct_dec_list '}'  */
#line 279 "cparser.y"
                                         {  printf("Reduced by rule: 124\n");  }
#line 2348 "cparser.tab.c"
    break;

  case 129: /* struct_or_union_specifier: STRUCT ID  */
#line 280 "cparser.y"
                         {  printf("Reduced by rule: 125\n");  }
#line 2354 "cparser.tab.c"
    break;

  case 130: /* struct_or_union_specifier: UNION ID '{' struct_dec_list '}'  */
#line 281 "cparser.y"
                                                 {  printf("Reduced by rule: 126\n");  }
#line 2360 "cparser.tab.c"
    break;

  case 131: /* struct_or_union_specifier: UNION '{' struct_dec_list '}'  */
#line 282 "cparser.y"
                                         {  printf("Reduced by rule: 127\n");  }
#line 2366 "cparser.tab.c"
    break;

  case 132: /* struct_or_union_specifier: UNION ID  */
#line 283 "cparser.y"
                         {  printf("Reduced by rule: 128\n");  }
#line 2372 "cparser.tab.c"
    break;

  case 133: /* struct_dec_list: struct_dec  */
#line 287 "cparser.y"
                         {  printf("Reduced by rule: 129\n");  }
#line 2378 "cparser.tab.c"
    break;

  case 134: /* struct_dec_list: struct_dec_list struct_dec  */
#line 288 "cparser.y"
                                         {  printf("Reduced by rule: 130\n");  }
#line 2384 "cparser.tab.c"
    break;

  case 136: /* struct_dec: specifiers ';'  */
#line 292 "cparser.y"
                         {  printf("Reduced by rule: 131\n");  }
#line 2390 "cparser.tab.c"
    break;

  case 137: /* struct_dec: specifiers struct_declarator_list ';'  */
#line 293 "cparser.y"
                                                 {  printf("Reduced by rule: 132\n");  }
#line 2396 "cparser.tab.c"
    break;

  case 138: /* struct_declarator_list: struct_declarator  */
#line 297 "cparser.y"
                                 {  printf("Reduced by rule: 133\n");  }
#line 2402 "cparser.tab.c"
    break;

  case 139: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 298 "cparser.y"
                                                         {  printf("Reduced by rule: 134\n");  }
#line 2408 "cparser.tab.c"
    break;

  case 140: /* struct_declarator: declarator  */
#line 302 "cparser.y"
                         {  printf("Reduced by rule: 135\n");  }
#line 2414 "cparser.tab.c"
    break;

  case 141: /* struct_declarator: declarator ':' constant_exp  */
#line 303 "cparser.y"
                                         {  printf("Reduced by rule: 136\n");  }
#line 2420 "cparser.tab.c"
    break;

  case 142: /* struct_declarator: ':' constant_exp  */
#line 304 "cparser.y"
                                 {  printf("Reduced by rule: 137\n");  }
#line 2426 "cparser.tab.c"
    break;

  case 143: /* declarator: pointer direct_declarator  */
#line 308 "cparser.y"
                                         {  printf("Reduced by rule: 138\n");  }
#line 2432 "cparser.tab.c"
    break;

  case 144: /* declarator: direct_declarator  */
#line 309 "cparser.y"
                                 {  printf("Reduced by rule: 139\n");  }
#line 2438 "cparser.tab.c"
    break;

  case 145: /* direct_declarator: ID  */
#line 314 "cparser.y"
                 {  printf("Reduced by rule: 140\n");  }
#line 2444 "cparser.tab.c"
    break;

  case 146: /* direct_declarator: '(' declarator ')'  */
#line 315 "cparser.y"
                                 {  printf("Reduced by rule: 141\n");  }
#line 2450 "cparser.tab.c"
    break;

  case 147: /* direct_declarator: direct_declarator '[' assignment_exp ']'  */
#line 316 "cparser.y"
                                                         {  printf("Reduced by rule: 142\n");  }
#line 2456 "cparser.tab.c"
    break;

  case 148: /* direct_declarator: direct_declarator '[' ']'  */
#line 317 "cparser.y"
                                         {  printf("Reduced by rule: 143\n");  }
#line 2462 "cparser.tab.c"
    break;

  case 149: /* direct_declarator: direct_declarator '[' specifiers '*' ']'  */
#line 318 "cparser.y"
                                                         {  printf("Reduced by rule: 144\n");  }
#line 2468 "cparser.tab.c"
    break;

  case 150: /* direct_declarator: direct_declarator '(' parameter_list ')'  */
#line 319 "cparser.y"
                                                         {  printf("Reduced by rule: 145\n");  }
#line 2474 "cparser.tab.c"
    break;

  case 151: /* direct_declarator: direct_declarator '(' identifier_list ')'  */
#line 320 "cparser.y"
                                                         {  printf("Reduced by rule: 146\n");  }
#line 2480 "cparser.tab.c"
    break;

  case 152: /* direct_declarator: direct_declarator '(' ')'  */
#line 321 "cparser.y"
                                                 {  printf("Reduced by rule: 147\n");  }
#line 2486 "cparser.tab.c"
    break;

  case 153: /* pointer: '*'  */
#line 325 "cparser.y"
                 {  printf("Reduced by rule: 148\n");  }
#line 2492 "cparser.tab.c"
    break;

  case 154: /* pointer: '*' pointer  */
#line 326 "cparser.y"
                  { printf("Reduced by rule: 148.5\n"); }
#line 2498 "cparser.tab.c"
    break;

  case 155: /* parameter_list: parameter_dec  */
#line 330 "cparser.y"
                         {  printf("Reduced by rule: 149\n");  }
#line 2504 "cparser.tab.c"
    break;

  case 156: /* parameter_list: parameter_list ',' parameter_dec  */
#line 331 "cparser.y"
                                                 {  printf("Reduced by rule: 150\n");  }
#line 2510 "cparser.tab.c"
    break;

  case 157: /* parameter_dec: specifiers declarator  */
#line 335 "cparser.y"
                                 {  printf("Reduced by rule: 151\n");  }
#line 2516 "cparser.tab.c"
    break;

  case 158: /* identifier_list: ID  */
#line 339 "cparser.y"
                 {  printf("Reduced by rule: 152\n");  }
#line 2522 "cparser.tab.c"
    break;

  case 159: /* identifier_list: identifier_list ',' ID  */
#line 340 "cparser.y"
                                 {  printf("Reduced by rule: 153\n");  }
#line 2528 "cparser.tab.c"
    break;

  case 160: /* type_name: VOID  */
#line 344 "cparser.y"
                 {  printf("Reduced by rule: 154\n");  }
#line 2534 "cparser.tab.c"
    break;

  case 161: /* type_name: CHAR  */
#line 345 "cparser.y"
                 {  printf("Reduced by rule: 155\n");  }
#line 2540 "cparser.tab.c"
    break;

  case 162: /* type_name: INT  */
#line 346 "cparser.y"
                 {  printf("Reduced by rule: 156\n");  }
#line 2546 "cparser.tab.c"
    break;

  case 163: /* type_name: FLOAT  */
#line 347 "cparser.y"
                         {  printf("Reduced by rule: 157\n");  }
#line 2552 "cparser.tab.c"
    break;

  case 164: /* type_name: struct_or_union_specifier  */
#line 348 "cparser.y"
                                         {  printf("Reduced by rule: 158\n");  }
#line 2558 "cparser.tab.c"
    break;

  case 165: /* type_name: typedef_name  */
#line 349 "cparser.y"
                         {  printf("Reduced by rule: 159\n");  }
#line 2564 "cparser.tab.c"
    break;

  case 166: /* typedef_name: ID  */
#line 353 "cparser.y"
                 {  printf("Reduced by rule: 160\n");  }
#line 2570 "cparser.tab.c"
    break;

  case 167: /* initializer: assignment_exp  */
#line 357 "cparser.y"
                                 {  printf("Reduced by rule: 161\n");  }
#line 2576 "cparser.tab.c"
    break;

  case 168: /* initializer: '{' initializer_list '}'  */
#line 358 "cparser.y"
                                         {  printf("Reduced by rule: 162\n");  }
#line 2582 "cparser.tab.c"
    break;

  case 169: /* initializer: '{' initializer_list ',' '}'  */
#line 359 "cparser.y"
                                         {  printf("Reduced by rule: 163\n");  }
#line 2588 "cparser.tab.c"
    break;

  case 170: /* initializer_list: initializer  */
#line 363 "cparser.y"
                         {  printf("Reduced by rule: 164\n");  }
#line 2594 "cparser.tab.c"
    break;

  case 171: /* initializer_list: designation initializer  */
#line 364 "cparser.y"
                                         {  printf("Reduced by rule: 165\n");  }
#line 2600 "cparser.tab.c"
    break;

  case 172: /* initializer_list: initializer_list ',' initializer  */
#line 365 "cparser.y"
                                                 {  printf("Reduced by rule: 166\n");  }
#line 2606 "cparser.tab.c"
    break;

  case 173: /* initializer_list: initializer_list ',' designation initializer  */
#line 366 "cparser.y"
                                                         {  printf("Reduced by rule: 167\n");  }
#line 2612 "cparser.tab.c"
    break;

  case 174: /* designation: designator_list '='  */
#line 370 "cparser.y"
                                 {  printf("Reduced by rule: 168\n");  }
#line 2618 "cparser.tab.c"
    break;

  case 175: /* designator_list: designator  */
#line 374 "cparser.y"
                         {  printf("Reduced by rule: 169\n");  }
#line 2624 "cparser.tab.c"
    break;

  case 176: /* designator_list: designator_list designator  */
#line 375 "cparser.y"
                                         {  printf("Reduced by rule: 170\n");  }
#line 2630 "cparser.tab.c"
    break;

  case 177: /* designator: '[' constant_exp ']'  */
#line 379 "cparser.y"
                                 {  printf("Reduced by rule: 171\n");  }
#line 2636 "cparser.tab.c"
    break;

  case 178: /* designator: '.' ID  */
#line 380 "cparser.y"
                 {  printf("Reduced by rule: 172\n");  }
#line 2642 "cparser.tab.c"
    break;

  case 179: /* func_def: specifiers declarator dec_list compound_stm  */
#line 384 "cparser.y"
                                                    {  printf("Reduced by rule: 173\n");  }
#line 2648 "cparser.tab.c"
    break;

  case 180: /* func_def: specifiers declarator compound_stm  */
#line 385 "cparser.y"
                                            {  printf("Reduced by rule: 174\n");  }
#line 2654 "cparser.tab.c"
    break;


#line 2658 "cparser.tab.c"

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

#line 388 "cparser.y"


int main(int argv, char* args[]){
    yyparse();
}

void yyerror(const char* s){
    fprintf(stderr,"Parse error:%s\n",s);
    exit(1);
}
