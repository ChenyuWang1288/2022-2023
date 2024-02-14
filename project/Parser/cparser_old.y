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
	exp	 {  printf("Reduced by rule: 1");  }
	|stm	 {  printf("Reduced by rule: 2");  }
	|dec	 {  printf("Reduced by rule: 3");  }
	|ccode exp	 {  printf("Reduced by rule: 4");  }
	|ccode stm	 {  printf("Reduced by rule: 5");  }
	|ccode dec	 {  printf("Reduced by rule: 6");  }
	|	 {  printf("Reduced by rule: 7");  }
	;

stm:
	labeled_stm      	 {  printf("Reduced by rule: 8");  }
	|compound_stm	 {  printf("Reduced by rule: 9");  }
	|exp_stm	 {  printf("Reduced by rule: 10");  }
	|selection_stm	 {  printf("Reduced by rule: 11");  }
	|iteration_stm	 {  printf("Reduced by rule: 12");  }
	|jump_stm	 {  printf("Reduced by rule: 13");  }
	;
	
labeled_stm:
	CASE constant_exp stm ':'	 {  printf("Reduced by rule: 14");  }
	|DEFAULT stm	 {  printf("Reduced by rule: 15");  }
	;

compound_stm:
	'{' dec_list stm_list '}'	 {  printf("Reduced by rule: 16");  }
	|'{' dec_list '}'	 {  printf("Reduced by rule: 17");  }
	|'{' stm_list '}'	 {  printf("Reduced by rule: 18");  }
	|'{' '}'	 {  printf("Reduced by rule: 19");  }
	;

dec_list:
	dec	 {  printf("Reduced by rule: 20");  }
	|dec_list dec	 {  printf("Reduced by rule: 21");  }
	;

stm_list:
	stm	 {  printf("Reduced by rule: 22");  }
	|stm_list stm	 {  printf("Reduced by rule: 23");  }
	
exp_stm:
	exp ';'	 {  printf("Reduced by rule: 24");  }
	|';'	 {  printf("Reduced by rule: 25");  }
	;

for_loop_exp:
	exp	 {  printf("Reduced by rule: 26");  }
	|	 {  printf("Reduced by rule: 27");  }
	;

iteration_stm:
		WHILE '(' exp ')' stm	 {  printf("Reduced by rule: 28");  }
		|DO stm WHILE '(' exp ')' ';'	 {  printf("Reduced by rule: 29");  }
		|FOR '(' for_loop_exp ';' for_loop_exp ';' for_loop_exp ')' stm	 {  printf("Reduced by rule: 30");  }
		;

selection_stm:
	IF '(' exp ')' stm	 {  printf("Reduced by rule: 31");  }
	|IF '(' exp ')' stm ELSE stm	 {  printf("Reduced by rule: 32");  }
	|SWITCH '(' exp ')' stm	 {  printf("Reduced by rule: 33");  }
	;

jump_stm:
	CONTINUE ';'	 {  printf("Reduced by rule: 34");  }
	|BREAK ';'	 {  printf("Reduced by rule: 35");  }
	|RETURN exp ';'	 {  printf("Reduced by rule: 36");  }
	|RETURN ';'	 {  printf("Reduced by rule: 37");  }
	;

exp:
	assignment_exp	 {  printf("Reduced by rule: 38");  }
	|exp ',' assignment_exp	 {  printf("Reduced by rule: 39");  }
	;

primary_exp:
	ID	 {  printf("Reduced by rule: 40");  }
	|C_INT	 {  printf("Reduced by rule: 41");  }
	|C_CHAR	 {  printf("Reduced by rule: 42");  }
	|C_FLOAT	 {  printf("Reduced by rule: 43");  }
	|C_STRING	 {  printf("Reduced by rule: 44");  }
	|'(' exp ')'	 {  printf("Reduced by rule: 45");  }
    ;

postfix_exp:
	primary_exp	 {  printf("Reduced by rule: 46");  }
	|postfix_exp '[' exp ']'	 {  printf("Reduced by rule: 47");  }
	|postfix_exp '(' argument_exp_list ')'	 {  printf("Reduced by rule: 48");  }
	|postfix_exp '(' ')'	 {  printf("Reduced by rule: 49");  }
	|postfix_exp '.' ID	 {  printf("Reduced by rule: 50");  }
	|POINTER ID	 {  printf("Reduced by rule: 51");  }
	|postfix_exp SELF_ADD	 {  printf("Reduced by rule: 52");  }
	|postfix_exp SELF_SUB	 {  printf("Reduced by rule: 53");  }
	;
	
argument_exp_list:
	assignment_exp	 {  printf("Reduced by rule: 54");  }
	|argument_exp_list ',' assignment_exp	 {  printf("Reduced by rule: 55");  }
	;

unary_exp:
	postfix_exp	 {  printf("Reduced by rule: 56");  }
	|SELF_ADD unary_exp	 {  printf("Reduced by rule: 57");  }
	|SELF_SUB unary_exp	 {  printf("Reduced by rule: 58");  }
	|'&' cast_exp	 {  printf("Reduced by rule: 59");  }
	|'*' cast_exp	 {  printf("Reduced by rule: 60");  }
	|'+' cast_exp	 {  printf("Reduced by rule: 61");  }
	|'-' cast_exp	 {  printf("Reduced by rule: 62");  }
	|'~' cast_exp	 {  printf("Reduced by rule: 63");  }
	|'!' cast_exp	 {  printf("Reduced by rule: 64");  }
	|SIZEOF unary_exp	 {  printf("Reduced by rule: 65");  }
	;

cast_exp:
	unary_exp	 {  printf("Reduced by rule: 66");  }
	|'(' type_name ')' cast_exp	 {  printf("Reduced by rule: 67");  }
	;

multiplicative_exp:
	cast_exp	 {  printf("Reduced by rule: 68");  }
	|multiplicative_exp '*' cast_exp	 {  printf("Reduced by rule: 69");  }
	|multiplicative_exp '/' cast_exp	 {  printf("Reduced by rule: 70");  }
	|multiplicative_exp '%' cast_exp	 {  printf("Reduced by rule: 71");  }
	;
	
shift_exp:
	additive_exp	 {  printf("Reduced by rule: 72");  }
	|shift_exp LEFT_SHIFT additive_exp	 {  printf("Reduced by rule: 73");  }
	|shift_exp RIGHT_SHIFT additive_exp	 {  printf("Reduced by rule: 74");  }
	;

relational_exp:
	shift_exp	 {  printf("Reduced by rule: 75");  }
	|relational_exp '<' shift_exp	 {  printf("Reduced by rule: 76");  }
	|relational_exp '>' shift_exp	 {  printf("Reduced by rule: 77");  }
	|relational_exp LESS_EQUAL shift_exp	 {  printf("Reduced by rule: 78");  }
	|relational_exp GREATER_EQUAL shift_exp	 {  printf("Reduced by rule: 79");  }
	 ;
	 
equality_exp:
	relational_exp	 {  printf("Reduced by rule: 80");  }
	|equality_exp EQUAL relational_exp	 {  printf("Reduced by rule: 81");  }
	|equality_exp UNEQUAL relational_exp	 {  printf("Reduced by rule: 82");  }
	 ;

AND_exp:
	equality_exp	 {  printf("Reduced by rule: 83");  }
	|AND_exp '&' equality_exp	 {  printf("Reduced by rule: 84");  }
     ;

additive_exp:
	multiplicative_exp	 {  printf("Reduced by rule: 85");  }
	|additive_exp '+' multiplicative_exp	 {  printf("Reduced by rule: 86");  }
	|additive_exp '-' multiplicative_exp	 {  printf("Reduced by rule: 87");  }
	;

exclusive_OR_exp:
	AND_exp	 {  printf("Reduced by rule: 88");  }
	|exclusive_OR_exp '^' AND_exp	 {  printf("Reduced by rule: 89");  }
	;

inclusive_OR_exp:
	exclusive_OR_exp	 {  printf("Reduced by rule: 90");  }
	|inclusive_OR_exp '|' exclusive_OR_exp	 {  printf("Reduced by rule: 91");  }
	;

logical_AND_exp:
	inclusive_OR_exp	 {  printf("Reduced by rule: 92");  }
	|logical_AND_exp AND inclusive_OR_exp	 {  printf("Reduced by rule: 93");  }
	;

logical_OR_exp:
	logical_AND_exp	 {  printf("Reduced by rule: 94");  }
	|logical_OR_exp OR logical_AND_exp	 {  printf("Reduced by rule: 95");  }
    ;

conditional_exp:
	logical_OR_exp	 {  printf("Reduced by rule: 96");  }
	|logical_OR_exp '?' exp ':' conditional_exp	 {  printf("Reduced by rule: 97");  }
	;
	
assignment_exp:
	conditional_exp	 {  printf("Reduced by rule: 98");  }
	|unary_exp '=' assignment_exp	 {  printf("Reduced by rule: 99");  }
	|unary_exp MUL_ASSIGN assignment_exp	 {  printf("Reduced by rule: 100");  }
	|unary_exp DIV_ASSIGN assignment_exp	 {  printf("Reduced by rule: 101");  }
	|unary_exp MOD_ASSIGN assignment_exp	 {  printf("Reduced by rule: 102");  }
	|unary_exp ADD_ASSIGN assignment_exp	 {  printf("Reduced by rule: 103");  }
	|unary_exp SUB_ASSIGN assignment_exp	 {  printf("Reduced by rule: 104");  }
	|unary_exp LEFT_SHIFT_ASSIGN assignment_exp	 {  printf("Reduced by rule: 105");  }
	|unary_exp RIGHT_SHIFT_ASSIGN assignment_exp	 {  printf("Reduced by rule: 106");  }
	|unary_exp BIT_AND_ASSIGN assignment_exp	 {  printf("Reduced by rule: 107");  }
	|unary_exp BIT_XOR_ASSIGN assignment_exp	 {  printf("Reduced by rule: 108");  }
	|unary_exp BIT_OR_ASSIGN assignment_exp	 {  printf("Reduced by rule: 109");  }
	;
     
constant_exp:
	conditional_exp	 {  printf("Reduced by rule: 110");  }
	;

dec:
	specifiers init_dec_list ';'	 {  printf("Reduced by rule: 111");  }
	|';'
	;

specifiers:
	TYPEDEF  	 {  printf("Reduced by rule: 112");  }
	|VOID  	 {  printf("Reduced by rule: 113");  }
	|CHAR  	 {  printf("Reduced by rule: 114");  }
	|INT	 {  printf("Reduced by rule: 115");  }
	|FLOAT	 {  printf("Reduced by rule: 116");  }
	|struct_or_union_specifier 	 {  printf("Reduced by rule: 117");  }
	|type_name	 {  printf("Reduced by rule: 118");  }
	;

init_dec_list:
	init_declarator	 {  printf("Reduced by rule: 119");  }
	|init_dec_list ',' init_declarator	 {  printf("Reduced by rule: 120");  }
	;
	
init_declarator:
	declarator	 {  printf("Reduced by rule: 121");  }
	|declarator '=' initializer	 {  printf("Reduced by rule: 122");  }
   ;

struct_or_union_specifier:
	STRUCT ID '{' struct_dec_list '}'	 {  printf("Reduced by rule: 123");  }
	|STRUCT '{' struct_dec_list '}'	 {  printf("Reduced by rule: 124");  }
	|STRUCT ID	 {  printf("Reduced by rule: 125");  }
	|UNION ID '{' struct_dec_list '}'	 {  printf("Reduced by rule: 126");  }
	|UNION '{' struct_dec_list '}'	 {  printf("Reduced by rule: 127");  }
	|UNION ID	 {  printf("Reduced by rule: 128");  }
	;

struct_dec_list:
	struct_dec	 {  printf("Reduced by rule: 129");  }
	|struct_dec_list struct_dec	 {  printf("Reduced by rule: 130");  }
	;

struct_dec:
	|specifiers ';'	 {  printf("Reduced by rule: 131");  }
	|specifiers struct_declarator_list ';'	 {  printf("Reduced by rule: 132");  }
	;

struct_declarator_list:
	struct_declarator	 {  printf("Reduced by rule: 133");  }
	|struct_declarator_list ',' struct_declarator	 {  printf("Reduced by rule: 134");  }
	;

struct_declarator:
	declarator	 {  printf("Reduced by rule: 135");  }
	|declarator':' constant_exp	 {  printf("Reduced by rule: 136");  }
	|':' constant_exp	 {  printf("Reduced by rule: 137");  }
	;

declarator:
	'*' direct_declarator	 {  printf("Reduced by rule: 138");  }
	|direct_declarator	 {  printf("Reduced by rule: 139");  }
	;


direct_declarator:
	ID	 {  printf("Reduced by rule: 140");  }
	|'(' ID ')'	 {  printf("Reduced by rule: 141");  }
	|direct_declarator '[' assignment_exp ']'	 {  printf("Reduced by rule: 142");  }
	|direct_declarator '[' ']'	 {  printf("Reduced by rule: 143");  }
	|direct_declarator '[' specifiers '*' ']'	 {  printf("Reduced by rule: 144");  }
	|direct_declarator '(' parameter_list ')'	 {  printf("Reduced by rule: 145");  }
	|direct_declarator '(' identifier_list ')'	 {  printf("Reduced by rule: 146");  }
	|direct_declarator '(' ')'      	 {  printf("Reduced by rule: 147");  }
	;

pointer:
	'*'	 {  printf("Reduced by rule: 148");  }
    | '*' pointer {}
    ;
   
parameter_list: 
	parameter_dec	 {  printf("Reduced by rule: 149");  }
	|parameter_list ',' parameter_dec	 {  printf("Reduced by rule: 150");  }
	;
	
parameter_dec:
	specifiers declarator	 {  printf("Reduced by rule: 151");  }
    ;

identifier_list:
	ID	 {  printf("Reduced by rule: 152");  }
	|identifier_list ',' ID	 {  printf("Reduced by rule: 153");  }
	;

type_name:
	VOID 	 {  printf("Reduced by rule: 154");  }
	|CHAR 	 {  printf("Reduced by rule: 155");  }
	|INT	 {  printf("Reduced by rule: 156");  }
	|FLOAT     	 {  printf("Reduced by rule: 157");  }
	|struct_or_union_specifier	 {  printf("Reduced by rule: 158");  }
	|typedef_name	 {  printf("Reduced by rule: 159");  }
	;

typedef_name:
	ID	 {  printf("Reduced by rule: 160");  }
	;

initializer:
	assignment_exp   	 {  printf("Reduced by rule: 161");  }
	|'{' initializer_list '}'  	 {  printf("Reduced by rule: 162");  }
	|'{' initializer_list ',' '}'	 {  printf("Reduced by rule: 163");  }
	;

initializer_list:
	initializer	 {  printf("Reduced by rule: 164");  }
	|designation initializer	 {  printf("Reduced by rule: 165");  }
	|initializer_list ',' initializer	 {  printf("Reduced by rule: 166");  }
	|initializer_list ',' designation initializer	 {  printf("Reduced by rule: 167");  }
	;

designation:
	designator_list '='	 {  printf("Reduced by rule: 168");  }
    ;

designator_list:
	designator	 {  printf("Reduced by rule: 169");  }
	|designator_list designator	 {  printf("Reduced by rule: 170");  }
	;

designator:
	'[' constant_exp ']'	 {  printf("Reduced by rule: 171");  }
	|'.' ID	 {  printf("Reduced by rule: 172");  }
	;


%%

int main(int argv, char* args[]){
    yyparse();
}

void yyerror(const char* s){
    fprintf(stderr,"Parse error:%s\n",s);
    exit(1);
}
