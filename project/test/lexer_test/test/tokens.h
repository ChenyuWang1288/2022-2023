#include<ctype.h>

union tokenval{
            int i;
            float f;
            char* s;
};

/* yylval's type */
struct token_type {
        int Pos[2]; // token's position
        union tokenval val; 
};

/*for lexer's testing*/   
enum token{

        /*基本数据类型*/
        CHAR = 128,
        INT,
        SHORT,
        LONG,
        DOUBLE,
        FLOAT,
        STRUCT,
        VOID,

        /*修饰符*/
        UNSIGNED,
        STATIC,
        AUTO,
        CONST,

        /*其他*/
        BREAK,
        CASE,
        CONTINUE,
        DO,
        ELSE,
        ENUM,
        FOR,
        IF,
        RETURN,
        SIZEOF,
        SWITCH,
        TYPEDEF,
        UNION,
        WHILE,

        /*标点符号*/
        SELF_ADD,
        SELF_SUB,
        LEFT_SHIFT,
        RIGHT_SHIFT,
        LESS_EQUAL,
        GREATER_EQUAL,
        EQUAL,
        UNEQUAL,
        AND,
        OR,
        MUL_ASSIGN,
        DIV_ASSIGN,
        MOD_ASSIGN,
        ADD_ASSIGN,
        SUB_ASSIGN,
        LEFT_SHIFT_ASSIGN,
        RIGHT_SHIFT_ASSIGN,
        BIT_AND_ASSIGN,
        BIT_OR_ASSIGN,
        BIT_XOR_ASSIGN,
        POINTER,

        /*标识符*/
        ID,
 
        /*常量*/
        C_INT,
        C_CHAR,
        C_FLOAT,
        C_STRING,

        /*ERROR*/
        ERROR,
};
