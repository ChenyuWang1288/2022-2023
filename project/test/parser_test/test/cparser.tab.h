/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_CPARSER_TAB_H_INCLUDED
# define YY_YY_CPARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ADD_ASSIGN = 258,              /* ADD_ASSIGN  */
    AND = 259,                     /* AND  */
    BIT_AND_ASSIGN = 260,          /* BIT_AND_ASSIGN  */
    BIT_OR_ASSIGN = 261,           /* BIT_OR_ASSIGN  */
    BIT_XOR_ASSIGN = 262,          /* BIT_XOR_ASSIGN  */
    FOR = 263,                     /* FOR  */
    BREAK = 264,                   /* BREAK  */
    CASE = 265,                    /* CASE  */
    CHAR = 266,                    /* CHAR  */
    CONTINUE = 267,                /* CONTINUE  */
    C_CHAR = 268,                  /* C_CHAR  */
    C_FLOAT = 269,                 /* C_FLOAT  */
    C_INT = 270,                   /* C_INT  */
    C_STRING = 271,                /* C_STRING  */
    DEFAULT = 272,                 /* DEFAULT  */
    DIV_ASSIGN = 273,              /* DIV_ASSIGN  */
    DO = 274,                      /* DO  */
    ELSE = 275,                    /* ELSE  */
    EQUAL = 276,                   /* EQUAL  */
    FLOAT = 277,                   /* FLOAT  */
    GREATER_EQUAL = 278,           /* GREATER_EQUAL  */
    ID = 279,                      /* ID  */
    IF = 280,                      /* IF  */
    INT = 281,                     /* INT  */
    LEFT_SHIFT = 282,              /* LEFT_SHIFT  */
    LEFT_SHIFT_ASSIGN = 283,       /* LEFT_SHIFT_ASSIGN  */
    LESS_EQUAL = 284,              /* LESS_EQUAL  */
    MOD_ASSIGN = 285,              /* MOD_ASSIGN  */
    MUL_ASSIGN = 286,              /* MUL_ASSIGN  */
    OR = 287,                      /* OR  */
    POINTER = 288,                 /* POINTER  */
    RETURN = 289,                  /* RETURN  */
    RIGHT_SHIFT = 290,             /* RIGHT_SHIFT  */
    RIGHT_SHIFT_ASSIGN = 291,      /* RIGHT_SHIFT_ASSIGN  */
    SELF_ADD = 292,                /* SELF_ADD  */
    SELF_SUB = 293,                /* SELF_SUB  */
    SIZEOF = 294,                  /* SIZEOF  */
    STRUCT = 295,                  /* STRUCT  */
    SUB_ASSIGN = 296,              /* SUB_ASSIGN  */
    SWITCH = 297,                  /* SWITCH  */
    TYPEDEF = 298,                 /* TYPEDEF  */
    UNEQUAL = 299,                 /* UNEQUAL  */
    UNION = 300,                   /* UNION  */
    VOID = 301,                    /* VOID  */
    WHILE = 302,                   /* WHILE  */
    DOUBLE = 303,                  /* DOUBLE  */
    SHORT = 304,                   /* SHORT  */
    LONG = 305,                    /* LONG  */
    UNSIGNED = 306,                /* UNSIGNED  */
    STATIC = 307,                  /* STATIC  */
    AUTO = 308,                    /* AUTO  */
    CONST = 309,                   /* CONST  */
    ENUM = 310,                    /* ENUM  */
    ERROR = 311                    /* ERROR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_CPARSER_TAB_H_INCLUDED  */
