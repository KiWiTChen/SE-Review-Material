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

#ifndef YY_YY_LRPARSER_TAB_H_INCLUDED
# define YY_YY_LRPARSER_TAB_H_INCLUDED
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
    num_INT = 258,                 /* num_INT  */
    Y_INT = 259,                   /* Y_INT  */
    Y_VOID = 260,                  /* Y_VOID  */
    Y_CONST = 261,                 /* Y_CONST  */
    Y_IF = 262,                    /* Y_IF  */
    Y_ELSE = 263,                  /* Y_ELSE  */
    Y_WHILE = 264,                 /* Y_WHILE  */
    Y_BREAK = 265,                 /* Y_BREAK  */
    Y_CONTINUE = 266,              /* Y_CONTINUE  */
    Y_FLOAT = 267,                 /* Y_FLOAT  */
    Y_RETURN = 268,                /* Y_RETURN  */
    Y_ADD = 269,                   /* Y_ADD  */
    Y_COMMA = 270,                 /* Y_COMMA  */
    Y_DIV = 271,                   /* Y_DIV  */
    Y_LPAR = 272,                  /* Y_LPAR  */
    Y_SUB = 273,                   /* Y_SUB  */
    Y_LSQUARE = 274,               /* Y_LSQUARE  */
    Y_MODULO = 275,                /* Y_MODULO  */
    Y_MUL = 276,                   /* Y_MUL  */
    Y_NOT = 277,                   /* Y_NOT  */
    Y_RPAR = 278,                  /* Y_RPAR  */
    Y_RSQUARE = 279,               /* Y_RSQUARE  */
    Y_RBRACKET = 280,              /* Y_RBRACKET  */
    Y_LESS = 281,                  /* Y_LESS  */
    Y_LESSEQ = 282,                /* Y_LESSEQ  */
    Y_GREAT = 283,                 /* Y_GREAT  */
    Y_GREATEQ = 284,               /* Y_GREATEQ  */
    Y_NOTEQ = 285,                 /* Y_NOTEQ  */
    Y_EQ = 286,                    /* Y_EQ  */
    Y_AND = 287,                   /* Y_AND  */
    Y_OR = 288,                    /* Y_OR  */
    Y_ASSIGN = 289,                /* Y_ASSIGN  */
    Y_LBRACKET = 290,              /* Y_LBRACKET  */
    Y_SEMICOLON = 291,             /* Y_SEMICOLON  */
    num_FLOAT = 292,               /* num_FLOAT  */
    Y_ID = 293                     /* Y_ID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "lrparser.y"

     int		token;
	int		int_value;
	float     float_value;
	char*	id_name;
	past		pAst;

#line 110 "lrparser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_LRPARSER_TAB_H_INCLUDED  */
