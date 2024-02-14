%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<ctype.h>

    int yylex();
    void yyerror(const char* s);
    
%}


%token ADD_ASSIGN AND BIT_AND_ASSIGN BIT_OR_ASSIGN BIT_XOR_ASSIGN FOR
%token BREAK CASE CHAR CONTINUE C_CHAR C_FLOAT 
%token C_INT C_STRING DEFAULT DIV_ASSIGN DO ELSE 
%token EQUAL FLOAT GREATER_EQUAL ID IF INT 
%token LEFT_SHIFT LEFT_SHIFT_ASSIGN LESS_EQUAL MOD_ASSIGN MUL_ASSIGN OR 
%token POINTER RETURN RIGHT_SHIFT RIGHT_SHIFT_ASSIGN SELF_ADD SELF_SUB 
%token SIZEOF STRUCT SUB_ASSIGN SWITCH TYPEDEF UNEQUAL 
%token UNION VOID WHILE 
%token DOUBLE SHORT LONG UNSIGNED STATIC AUTO CONST ENUM ERROR // useless this line
%type  additive_exp argument_exp_list assignment_exp AND_exp
%type cast_exp ccode compound_stm conditional_exp constant_exp dec 
%type dec_list declarator designation designator designator_list 
%type direct_declarator equality_exp  exclusive_OR_exp exp exp_stm 
%type for_loop_exp identifier_list inclusive_OR_exp init_dec_list init_declarator 
%type initializer initializer_list iteration_stm jump_stm labeled_stm logical_AND_exp 
%type logical_OR_exp multiplicative_exp parameter_dec parameter_list pointer postfix_exp 
%type primary_exp relational_exp selection_stm shift_exp specifiers stm 
%type stm_list struct_dec struct_dec_list struct_declarator struct_declarator_list struct_or_union_specifier 
%type type_name typedef_name unary_exp 
%type func_def

// %left '(' ')' '[' ']' '.' POINTER SELF_ADD SELF_SUB
// %right '+' '-' '!' '~' SELF_ADD SELF_SUB SIZEOF
// %left '/' '%' '*' 
// %left '+' '-'
// %left LEFT_SHIFT RIGHT_SHIFT
// %left '<' LESS_EQUAL '>' GREATER_EQUAL
// %left EQUAL UNEQUAL
// %left '&'
// %left '^'
// %left '|'
// %left AND
// %left OR
// %right ADD_ASSIGN '=' SUB_ASSIGN DIV_ASSIGN MOD_ASSIGN LEFT_SHIFT_ASSIGN RIGHT_SHIFT_ASSIGN BIT_AND_ASSIGN BIT_OR_ASSIGN BIT_XOR_ASSIGN

%start ccode;

%%

ccode:
	exp	 {  printf("Reduced by rule: 1\n");  }
	|func_def {printf("Reduced by rule: 1.5\n");}
	|stm	 {  printf("Reduced by rule: 2\n");  }
	|dec	 {  printf("Reduced by rule: 3\n");  }
	|ccode exp	 {  printf("Reduced by rule: 4\n");  }
	|ccode stm	 {  printf("Reduced by rule: 5\n");  }
	|ccode dec	 {  printf("Reduced by rule: 6\n");  }
	|ccode func_def {	printf("Reduced by rule: 6.5\n"); }
	|	 {  printf("Reduced by rule: 7\n");  }
	;

stm:
	labeled_stm      	 {  printf("Reduced by rule: 8\n");  }
	|compound_stm	 {  printf("Reduced by rule: 9\n");  }
	|exp_stm	 {  printf("Reduced by rule: 10\n");  }
	|selection_stm	 {  printf("Reduced by rule: 11\n");  }
	|iteration_stm	 {  printf("Reduced by rule: 12\n");  }
	|jump_stm	 {  printf("Reduced by rule: 13\n");  }
	;
	
labeled_stm:
	CASE constant_exp stm ':'	 {  printf("Reduced by rule: 14\n");  }
	|DEFAULT stm	 {  printf("Reduced by rule: 15\n");  }
	;

compound_stm:
	'{' dec_list stm_list '}'	 {  printf("Reduced by rule: 16\n");  }
	|'{' dec_list '}'	 {  printf("Reduced by rule: 17\n");  }
	|'{' stm_list '}'	 {  printf("Reduced by rule: 18\n");  }
	|'{' '}'	 {  printf("Reduced by rule: 19\n");  }
	;

dec_list:
	dec	 {  printf("Reduced by rule: 20\n");  }
	|dec_list dec	 {  printf("Reduced by rule: 21\n");  }
	;

stm_list:
	stm	 {  printf("Reduced by rule: 22\n");  }
	|stm_list stm	 {  printf("Reduced by rule: 23\n");  }
	
exp_stm:
	exp ';'	 {  printf("Reduced by rule: 24\n");  }
	|';'	 {  printf("Reduced by rule: 25\n");  }
	;

for_loop_exp:
	exp	 {  printf("Reduced by rule: 26\n");  }
	|	 {  printf("Reduced by rule: 27\n");  }
	;

iteration_stm:
		WHILE '(' exp ')' stm	 {  printf("Reduced by rule: 28\n");  }
		|DO stm WHILE '(' exp ')' ';'	 {  printf("Reduced by rule: 29\n");  }
		|FOR '(' for_loop_exp ';' for_loop_exp ';' for_loop_exp ')' stm	 {  printf("Reduced by rule: 30\n");  }
		;

selection_stm:
	IF '(' exp ')' stm	 {  printf("Reduced by rule: 31\n");  }
	|IF '(' exp ')' stm ELSE stm	 {  printf("Reduced by rule: 32\n");  }
	|SWITCH '(' exp ')' stm	 {  printf("Reduced by rule: 33\n");  }
	;

jump_stm:
	CONTINUE ';'	 {  printf("Reduced by rule: 34\n");  }
	|BREAK ';'	 {  printf("Reduced by rule: 35\n");  }
	|RETURN exp ';'	 {  printf("Reduced by rule: 36\n");  }
	|RETURN ';'	 {  printf("Reduced by rule: 37\n");  }
	;

exp:
	assignment_exp	 {  printf("Reduced by rule: 38\n");  }
	|exp ',' assignment_exp	 {  printf("Reduced by rule: 39\n");  }
	;

primary_exp:
	ID	 {  printf("Reduced by rule: 40\n");  }
	|C_INT	 {  printf("Reduced by rule: 41\n");  }
	|C_CHAR	 {  printf("Reduced by rule: 42\n");  }
	|C_FLOAT	 {  printf("Reduced by rule: 43\n");  }
	|C_STRING	 {  printf("Reduced by rule: 44\n");  }
	|'(' exp ')'	 {  printf("Reduced by rule: 45\n");  }
    ;

postfix_exp:
	primary_exp	 {  printf("Reduced by rule: 46\n");  }
	|postfix_exp '[' exp ']'	 {  printf("Reduced by rule: 47\n");  }
	|postfix_exp '(' argument_exp_list ')'	 {  printf("Reduced by rule: 48\n");  }
	|postfix_exp '(' ')'	 {  printf("Reduced by rule: 49\n");  }
	|postfix_exp '.' ID	 {  printf("Reduced by rule: 50\n");  }
	|POINTER ID	 {  printf("Reduced by rule: 51\n");  }
	|postfix_exp SELF_ADD	 {  printf("Reduced by rule: 52\n");  }
	|postfix_exp SELF_SUB	 {  printf("Reduced by rule: 53\n");  }
	;
	
argument_exp_list:
	assignment_exp	 {  printf("Reduced by rule: 54\n");  }
	|argument_exp_list ',' assignment_exp	 {  printf("Reduced by rule: 55\n");  }
	;

unary_exp:
	postfix_exp	 {  printf("Reduced by rule: 56\n");  }
	|SELF_ADD unary_exp	 {  printf("Reduced by rule: 57\n");  }
	|SELF_SUB unary_exp	 {  printf("Reduced by rule: 58\n");  }
	|'&' cast_exp	 {  printf("Reduced by rule: 59\n");  }
	|'*' cast_exp	 {  printf("Reduced by rule: 60\n");  }
	|'+' cast_exp	 {  printf("Reduced by rule: 61\n");  }
	|'-' cast_exp	 {  printf("Reduced by rule: 62\n");  }
	|'~' cast_exp	 {  printf("Reduced by rule: 63\n");  }
	|'!' cast_exp	 {  printf("Reduced by rule: 64\n");  }
	|SIZEOF unary_exp	 {  printf("Reduced by rule: 65\n");  }
	;

cast_exp:
	unary_exp	 {  printf("Reduced by rule: 66\n");  }
	|'(' type_name ')' cast_exp	 {  printf("Reduced by rule: 67\n");  }
	;

multiplicative_exp:
	cast_exp	 {  printf("Reduced by rule: 68\n");  }
	|multiplicative_exp '*' cast_exp	 {  printf("Reduced by rule: 69\n");  }
	|multiplicative_exp '/' cast_exp	 {  printf("Reduced by rule: 70\n");  }
	|multiplicative_exp '%' cast_exp	 {  printf("Reduced by rule: 71\n");  }
	;
	
shift_exp:
	additive_exp	 {  printf("Reduced by rule: 72\n");  }
	|shift_exp LEFT_SHIFT additive_exp	 {  printf("Reduced by rule: 73\n");  }
	|shift_exp RIGHT_SHIFT additive_exp	 {  printf("Reduced by rule: 74\n");  }
	;

relational_exp:
	shift_exp	 {  printf("Reduced by rule: 75\n");  }
	|relational_exp '<' shift_exp	 {  printf("Reduced by rule: 76\n");  }
	|relational_exp '>' shift_exp	 {  printf("Reduced by rule: 77\n");  }
	|relational_exp LESS_EQUAL shift_exp	 {  printf("Reduced by rule: 78\n");  }
	|relational_exp GREATER_EQUAL shift_exp	 {  printf("Reduced by rule: 79\n");  }
	 ;
	 
equality_exp:
	relational_exp	 {  printf("Reduced by rule: 80\n");  }
	|equality_exp EQUAL relational_exp	 {  printf("Reduced by rule: 81\n");  }
	|equality_exp UNEQUAL relational_exp	 {  printf("Reduced by rule: 82\n");  }
	 ;

AND_exp:
	equality_exp	 {  printf("Reduced by rule: 83\n");  }
	|AND_exp '&' equality_exp	 {  printf("Reduced by rule: 84\n");  }
     ;

additive_exp:
	multiplicative_exp	 {  printf("Reduced by rule: 85\n");  }
	|additive_exp '+' multiplicative_exp	 {  printf("Reduced by rule: 86\n");  }
	|additive_exp '-' multiplicative_exp	 {  printf("Reduced by rule: 87\n");  }
	;

exclusive_OR_exp:
	AND_exp	 {  printf("Reduced by rule: 88\n");  }
	|exclusive_OR_exp '^' AND_exp	 {  printf("Reduced by rule: 89\n");  }
	;

inclusive_OR_exp:
	exclusive_OR_exp	 {  printf("Reduced by rule: 90\n");  }
	|inclusive_OR_exp '|' exclusive_OR_exp	 {  printf("Reduced by rule: 91\n");  }
	;

logical_AND_exp:
	inclusive_OR_exp	 {  printf("Reduced by rule: 92\n");  }
	|logical_AND_exp AND inclusive_OR_exp	 {  printf("Reduced by rule: 93\n");  }
	;

logical_OR_exp:
	logical_AND_exp	 {  printf("Reduced by rule: 94\n");  }
	|logical_OR_exp OR logical_AND_exp	 {  printf("Reduced by rule: 95\n");  }
    ;

conditional_exp:
	logical_OR_exp	 {  printf("Reduced by rule: 96\n");  }
	|logical_OR_exp '?' exp ':' conditional_exp	 {  printf("Reduced by rule: 97\n");  }
	;
	
assignment_exp:
	conditional_exp	 {  printf("Reduced by rule: 98\n");  }
	|unary_exp '=' assignment_exp	 {  printf("Reduced by rule: 99\n");  }
	|unary_exp MUL_ASSIGN assignment_exp	 {  printf("Reduced by rule: 100\n");  }
	|unary_exp DIV_ASSIGN assignment_exp	 {  printf("Reduced by rule: 101\n");  }
	|unary_exp MOD_ASSIGN assignment_exp	 {  printf("Reduced by rule: 102\n");  }
	|unary_exp ADD_ASSIGN assignment_exp	 {  printf("Reduced by rule: 103\n");  }
	|unary_exp SUB_ASSIGN assignment_exp	 {  printf("Reduced by rule: 104\n");  }
	|unary_exp LEFT_SHIFT_ASSIGN assignment_exp	 {  printf("Reduced by rule: 105\n");  }
	|unary_exp RIGHT_SHIFT_ASSIGN assignment_exp	 {  printf("Reduced by rule: 106\n");  }
	|unary_exp BIT_AND_ASSIGN assignment_exp	 {  printf("Reduced by rule: 107\n");  }
	|unary_exp BIT_XOR_ASSIGN assignment_exp	 {  printf("Reduced by rule: 108\n");  }
	|unary_exp BIT_OR_ASSIGN assignment_exp	 {  printf("Reduced by rule: 109\n");  }
	;
     
constant_exp:
	conditional_exp	 {  printf("Reduced by rule: 110\n");  }
	;

dec:
	specifiers init_dec_list ';'	 {  printf("Reduced by rule: 111\n");  }
	|specifiers ';'
	;

specifiers:
	TYPEDEF  	 {  printf("Reduced by rule: 112\n");  }
	|VOID  	 {  printf("Reduced by rule: 113\n");  }
	|CHAR  	 {  printf("Reduced by rule: 114\n");  }
	|INT	 {  printf("Reduced by rule: 115\n");  }
	|FLOAT	 {  printf("Reduced by rule: 116\n");  }
	|struct_or_union_specifier 	 {  printf("Reduced by rule: 117\n");  }
	|type_name	 {  printf("Reduced by rule: 118\n");  }
	;

init_dec_list:
	init_declarator	 {  printf("Reduced by rule: 119\n");  }
	|init_dec_list ',' init_declarator	 {  printf("Reduced by rule: 120\n");  }
	;
	
init_declarator:
	declarator	 {  printf("Reduced by rule: 121\n");  }
	|declarator '=' initializer	 {  printf("Reduced by rule: 122\n");  }
   ;

struct_or_union_specifier:
	STRUCT ID '{' struct_dec_list '}'	 {  printf("Reduced by rule: 123\n");  }
	|STRUCT '{' struct_dec_list '}'	 {  printf("Reduced by rule: 124\n");  }
	|STRUCT ID	 {  printf("Reduced by rule: 125\n");  }
	|UNION ID '{' struct_dec_list '}'	 {  printf("Reduced by rule: 126\n");  }
	|UNION '{' struct_dec_list '}'	 {  printf("Reduced by rule: 127\n");  }
	|UNION ID	 {  printf("Reduced by rule: 128\n");  }
	;

struct_dec_list:
	struct_dec	 {  printf("Reduced by rule: 129\n");  }
	|struct_dec_list struct_dec	 {  printf("Reduced by rule: 130\n");  }
	;

struct_dec:
	|specifiers ';'	 {  printf("Reduced by rule: 131\n");  }
	|specifiers struct_declarator_list ';'	 {  printf("Reduced by rule: 132\n");  }
	;

struct_declarator_list:
	struct_declarator	 {  printf("Reduced by rule: 133\n");  }
	|struct_declarator_list ',' struct_declarator	 {  printf("Reduced by rule: 134\n");  }
	;

struct_declarator:
	declarator	 {  printf("Reduced by rule: 135\n");  }
	|declarator':' constant_exp	 {  printf("Reduced by rule: 136\n");  }
	|':' constant_exp	 {  printf("Reduced by rule: 137\n");  }
	;

declarator:
	pointer direct_declarator	 {  printf("Reduced by rule: 138\n");  }
	|direct_declarator	 {  printf("Reduced by rule: 139\n");  }
	;


direct_declarator:
	ID	 {  printf("Reduced by rule: 140\n");  }
	|'(' declarator ')'	 {  printf("Reduced by rule: 141\n");  }
	|direct_declarator '[' assignment_exp ']'	 {  printf("Reduced by rule: 142\n");  }
	|direct_declarator '[' ']'	 {  printf("Reduced by rule: 143\n");  }
	|direct_declarator '[' specifiers '*' ']'	 {  printf("Reduced by rule: 144\n");  }
	|direct_declarator '(' parameter_list ')'	 {  printf("Reduced by rule: 145\n");  }
	|direct_declarator '(' identifier_list ')'	 {  printf("Reduced by rule: 146\n");  }
	|direct_declarator '(' ')'      	 {  printf("Reduced by rule: 147\n");  }
	;

pointer:
	'*'	 {  printf("Reduced by rule: 148\n");  }
    | '*' pointer { printf("Reduced by rule: 148.5\n"); }
    ;
   
parameter_list: 
	parameter_dec	 {  printf("Reduced by rule: 149\n");  }
	|parameter_list ',' parameter_dec	 {  printf("Reduced by rule: 150\n");  }
	;
	
parameter_dec:
	specifiers declarator	 {  printf("Reduced by rule: 151\n");  }
    ;

identifier_list:
	ID	 {  printf("Reduced by rule: 152\n");  }
	|identifier_list ',' ID	 {  printf("Reduced by rule: 153\n");  }
	;

type_name:
	VOID 	 {  printf("Reduced by rule: 154\n");  }
	|CHAR 	 {  printf("Reduced by rule: 155\n");  }
	|INT	 {  printf("Reduced by rule: 156\n");  }
	|FLOAT     	 {  printf("Reduced by rule: 157\n");  }
	|struct_or_union_specifier	 {  printf("Reduced by rule: 158\n");  }
	|typedef_name	 {  printf("Reduced by rule: 159\n");  }
	;

typedef_name:
	ID	 {  printf("Reduced by rule: 160\n");  }
	;

initializer:
	assignment_exp   	 {  printf("Reduced by rule: 161\n");  }
	|'{' initializer_list '}'  	 {  printf("Reduced by rule: 162\n");  }
	|'{' initializer_list ',' '}'	 {  printf("Reduced by rule: 163\n");  }
	;

initializer_list:
	initializer	 {  printf("Reduced by rule: 164\n");  }
	|designation initializer	 {  printf("Reduced by rule: 165\n");  }
	|initializer_list ',' initializer	 {  printf("Reduced by rule: 166\n");  }
	|initializer_list ',' designation initializer	 {  printf("Reduced by rule: 167\n");  }
	;

designation:
	designator_list '='	 {  printf("Reduced by rule: 168\n");  }
    ;

designator_list:
	designator	 {  printf("Reduced by rule: 169\n");  }
	|designator_list designator	 {  printf("Reduced by rule: 170\n");  }
	;

designator:
	'[' constant_exp ']'	 {  printf("Reduced by rule: 171\n");  }
	|'.' ID	 {  printf("Reduced by rule: 172\n");  }
	;

func_def:
	specifiers declarator dec_list compound_stm {  printf("Reduced by rule: 173\n");  }
	|specifiers declarator compound_stm {  printf("Reduced by rule: 174\n");  }
	;

%%

int main(int argv, char* args[]){
    yyparse();
}

void yyerror(const char* s){
    fprintf(stderr,"Parse error:%s\n",s);
    exit(1);
}
