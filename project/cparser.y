%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<ctype.h>
	#include<cassert>
	#include<string>
	#include"token_printer.h"
	#include<string>
	#include<vector>
	#include"absyn.h"
	#include"transform.h"

	using namespace std;

	extern int LinePos;  
    extern int ColPos;

	extern FILE* yyin;

    extern int yylex();
    void yyerror(const char* s);
	void JumpToNext(FILE* in);

	A_cCodeDecList code;
	
	A_pos A_Pos(){
		return A_POS(LinePos,ColPos,"thisfile");
	}
	
    FILE * cparser_outfile;
	FILE * cfile;

	bool parseSuccessfully = true;

    void echoE();




%}

%union{
	int inum;
	float fnum;
	char c;
	char * s;
	A_exp exp;
	A_stm stm;
	A_expList expList;
	A_declarator declarator;
	A_paramList paramList;
	A_structDeclaratorList structDeclaratorList;
	A_structDecList structDecList;
	A_specifiers specifiers;
	A_initializer initializer;
	A_initDecList initDecList;
	A_dec dec;
	A_typeName typeName;
	A_stmDecList stmDecList;
	A_cCodeDecList cCodeDecList;
	A_pointer pointer;
	A_structDec structDec;
	A_initDeclarator initDeclarator;
	A_forLoopExp forLoopExp;
}

%token<s> ID
%token<inum> C_INT
%token<fnum> C_FLOAT
%token<c> C_CHAR
%token<s> C_STRING

%token ADD_ASSIGN AND BIT_AND_ASSIGN BIT_OR_ASSIGN BIT_XOR_ASSIGN FOR TD
%token BREAK CASE CHAR CONTINUE
%token DEFAULT DIV_ASSIGN DO ELSE
%token EQUAL FLOAT GREATER_EQUAL IF INT
%token LEFT_SHIFT LEFT_SHIFT_ASSIGN LESS_EQUAL MOD_ASSIGN MUL_ASSIGN OR
%token POINTER RETURN RIGHT_SHIFT RIGHT_SHIFT_ASSIGN SELF_ADD SELF_SUB
%token SIZEOF STRUCT SUB_ASSIGN SWITCH TYPEDEF UNEQUAL
%token UNION VOID WHILE
%token DOUBLE SHORT LONG UNSIGNED STATIC AUTO CONST ENUM ERROR // useless this line

%type<exp> additive_exp assignment_exp AND_exp cast_exp  conditional_exp constant_exp equality_exp  unary_exp postfix_exp  logical_AND_exp
%type<exp> exclusive_OR_exp exp  inclusive_OR_exp logical_OR_exp multiplicative_exp primary_exp relational_exp  shift_exp
%type<forLoopExp> for_loop_exp
%type<stm> exp_stm  stm iteration_stm jump_stm labeled_stm compound_stm selection_stm
%type<cCodeDecList> ccode
%type<expList> argument_exp_list exp_list
%type<dec> dec func_def for_loop_dec
%type<initializer> initializer
%type<stmDecList> dec_stm_list dec_list
%type<typeName> type_name
%type<specifiers> specifiers struct_or_union_specifier
%type<initDecList> init_dec_list
%type<initDeclarator> init_declarator
%type<paramList> parameter_list parameter_dec
%type<structDecList> struct_dec_list
%type<structDeclaratorList> struct_declarator_list
%type<declarator> direct_declarator declarator struct_declarator func_declarator
%type<pointer> pointer
%type<s> td_name
%type<structDec> struct_dec


%left '(' ')' '[' ']' '.' POINTER
%right '!' '~' SIZEOF
%left '/' '%' '*'
%left LEFT_SHIFT RIGHT_SHIFT
%left '<' LESS_EQUAL '>' GREATER_EQUAL
%left EQUAL UNEQUAL
%left '&'
%left '^'
%left '|'
%left AND
%left OR

%right ADD_ASSIGN SUB_ASSIGN DIV_ASSIGN MOD_ASSIGN LEFT_SHIFT_ASSIGN RIGHT_SHIFT_ASSIGN BIT_AND_ASSIGN BIT_OR_ASSIGN BIT_XOR_ASSIGN

%start ccode;

%%

ccode:
	func_def {
		code =  A_CCodeDecList(A_Pos(),$1,nullptr);
		$$ = code;
		fprintf(cparser_outfile , "Reduced by rule: 1.5	ccode->func_def	\tline:%d  pos:%d \n",LinePos,ColPos);

	}
	|dec	{
		code =  A_CCodeDecList(A_Pos(),$1,nullptr);
		$$ = code;
		fprintf(cparser_outfile , "Reduced by rule: 3	ccode->dec	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|dec ccode	{
		code = A_CCodeDecList(A_Pos(),$1,$2);
		$$ = code;
	    fprintf(cparser_outfile , "Reduced by rule: 6	ccode->ccode dec	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|func_def ccode{
		code =  A_CCodeDecList(A_Pos(),$1,$2);
		$$ = code;
		fprintf(cparser_outfile , "Reduced by rule: 6.5	ccode->ccode func_def	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	;

stm:
	exp_stm	 {
		$$ = $1;
	//	if(isInCaseBlock){caseStms.push_back($$);}
		fprintf(cparser_outfile , "Reduced by rule: 8	stm->exp_stm	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|labeled_stm  {
		$$ = $1;
	//	if(isInCaseBlock){caseStms.push_back($$);}
		fprintf(cparser_outfile , "Reduced by rule: 9	stm->labeled_stm      	\tline:%d  pos:%d \n",LinePos,ColPos);
	 }
	|selection_stm	 {
		$$ = $1;
	//	if(isInCaseBlock){caseStms.push_back($$);}
		fprintf(cparser_outfile , "Reduced by rule: 10	stm->selection_stm	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|iteration_stm	 {
		$$ = $1;
	//	if(isInCaseBlock){caseStms.push_back($$);}
		fprintf(cparser_outfile , "Reduced by rule: 11	stm->iteration_stm	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|jump_stm	 {
		$$ = $1;
	//	if(isInCaseBlock){caseStms.push_back($$);}
		fprintf(cparser_outfile , "Reduced by rule: 12	stm->jump_stm	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|compound_stm	 {
		 $$ = $1;
		 fprintf(cparser_outfile , "Reduced by rule: 13	stm->compound_stm	\tline:%d  pos:%d \n",LinePos,ColPos);
		}
	|error{echoE();	parseSuccessfully=false;}
	;

labeled_stm:
	CASE constant_exp ':'{
		  $$ = A_CaseStm(A_Pos(),$2,nullptr);
		  fprintf(cparser_outfile , "Reduced by rule: 14	labeled_stm->CASE constant_exp stm ':'	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|DEFAULT ':'{
		  $$ = A_DefaultStm(A_Pos(),nullptr);
		  fprintf(cparser_outfile , "Reduced by rule: 15	labeled_stm->DEFAULT stm	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	;

dec_stm_list:
	stm	 {
		$$ = A_StmDecList_S(A_Pos(), $1, nullptr);
		fprintf(cparser_outfile , "Reduced by rule: 15.2	dec_stm_list->stm	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|dec  {
		$$ = A_StmDecList_D(A_Pos(), $1, nullptr);
		fprintf(cparser_outfile , "Reduced by rule: 15.4	dec_stm_list->dec	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|stm dec_stm_list	 {
		$$ = A_StmDecList_S(A_Pos(), $1, $2);
		fprintf(cparser_outfile , "Reduced by rule: 15.6	dec_stm_list->stm dec_stm_list	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|dec dec_stm_list	 {
		$$ = A_StmDecList_D(A_Pos(), $1, $2);
		fprintf(cparser_outfile , "Reduced by rule: 15.8	dec_stm_list->dec dec_stm_list	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	;

compound_stm:
	'{' '}'	 {
		 $$ = A_CompoundStm(A_Pos(),nullptr);
		 fprintf(cparser_outfile , "Reduced by rule: 16	compound_stm->'{' '}'	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|'{' dec_stm_list '}'	 {
		$$ = A_CompoundStm(A_Pos(),$2);
		fprintf(cparser_outfile , "Reduced by rule: 17	compound_stm->'{' dec_stm_list '}'	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|'{' error '}' {
	    echoE();
	    parseSuccessfully=false;
	}
	;

dec_list:
	dec	 {
		$$ = A_StmDecList_D(A_Pos(),$1,nullptr);
		fprintf(cparser_outfile , "Reduced by rule: 20	dec_list->dec	\tline:%d  pos:%d \n",LinePos,ColPos);  }
	| dec dec_list {
		$$ = A_StmDecList_D(A_Pos(),$1,$2);
		fprintf(cparser_outfile , "Reduced by rule: 21	dec_list->dec_list dec	\tline:%d  pos:%d \n",LinePos,ColPos);
	}

	;

exp_stm:
	exp ';'	 {
		$$ = A_ExpStm(A_Pos(),$1);
		fprintf(cparser_outfile , "Reduced by rule: 24	exp_stm->exp ';'	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|';'  {
		$$ = A_ExpStm(A_Pos(),A_NullExp(A_Pos()));
		fprintf(cparser_outfile , "Reduced by rule: 25	exp_stm->';'	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|error ';' {echoE();	parseSuccessfully=false;}

	;

for_loop_exp:
	exp	 {
		$$ = A_ForLoopExp_Exp(A_Pos(),$1);
		fprintf(cparser_outfile , "Reduced by rule: 26	for_loop_exp->exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|for_loop_dec {
	 	$$ = A_ForLoopExp_Dec(A_Pos(),$1);
	     fprintf(cparser_outfile , "Reduced by rule: 26	for_loop_exp->dec	\tline:%d  pos:%d \n",LinePos,ColPos);

	}
	|	{
		$$ = A_ForLoopExp_Exp(A_Pos(),nullptr);
		fprintf(cparser_outfile , "Reduced by rule: 27	for_loop_exp->exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
    |error{echoE();	parseSuccessfully=false;}
	;

iteration_stm:
		WHILE '(' exp ')' stm	 {
			$$ = A_WhileStm(A_Pos(),$3,$5);
			fprintf(cparser_outfile , "Reduced by rule: 28	iteration_stm->WHILE '(' exp ')' stm	\tline:%d  pos:%d \n",LinePos,ColPos);
		}
		|DO stm WHILE '(' exp ')' ';'	 {
			$$ = A_DoWhileStm(A_Pos(), $5 , $2);
			fprintf(cparser_outfile , "Reduced by rule: 29	iteration_stm->DO stm WHILE '(' exp ')' ';'	\tline:%d  pos:%d \n",LinePos,ColPos);
		}
		|FOR '(' for_loop_exp ';' for_loop_exp ';' for_loop_exp ')' stm	 {
			$$ = A_ForStm(A_Pos(),$3,$5,$7,$9);
			fprintf(cparser_outfile , "Reduced by rule: 30	iteration_stm->FOR '(' for_loop_exp ';' for_loop_exp ';' for_loop_exp ')' stm	\tline:%d  pos:%d \n",LinePos,ColPos);
		}
		;

selection_stm:
	IF '(' exp ')' stm	 {
		$$ = A_IfElseStm(A_Pos(),$3,$5,nullptr);
		fprintf(cparser_outfile , "Reduced by rule: 31	selection_stm->IF '(' exp ')' stm	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|IF '(' exp ')' stm ELSE stm	 {
		$$ = A_IfElseStm(A_Pos(),$3,$5,$7);
		fprintf(cparser_outfile , "Reduced by rule: 32	selection_stm->IF '(' exp ')' stm ELSE stm	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|SWITCH '(' exp ')' stm	 {
		$$ = A_SwitchStm(A_Pos(),$3,$5);
		fprintf(cparser_outfile , "Reduced by rule: 33	selection_stm->SWITCH '(' exp ')' stm	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	;

jump_stm:
	CONTINUE ';'	 {
		$$ = A_ContinueStm(A_Pos());
		fprintf(cparser_outfile , "Reduced by rule: 34	jump_stm->CONTINUE ';'	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|BREAK ';'	 {
		$$ = A_BreakStm(A_Pos());
		fprintf(cparser_outfile , "Reduced by rule: 35	jump_stm->BREAK ';'	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|RETURN exp ';'	 {
		$$ = A_ReturnStm(A_Pos(),$2);
		fprintf(cparser_outfile , "Reduced by rule: 36	jump_stm->RETURN exp ';'	\tline:%d  pos:%d \n",LinePos,ColPos);
		}
	|RETURN ';'	 {
		$$ = A_ReturnStm(A_Pos(),A_NullExp(A_Pos()));
	    fprintf(cparser_outfile , "Reduced by rule: 37	jump_stm->RETURN ';'	\tline:%d  pos:%d \n",LinePos,ColPos);
	 }
	;

exp_list:
	assignment_exp {
		$$ = A_ExpList(A_Pos(),$1,nullptr);
	}
	| assignment_exp ',' exp_list {
		$$ = A_ExpList(A_Pos(),$1,$3);
	}
    ;
exp:
	assignment_exp	 {
		$$ = $1;
		fprintf(cparser_outfile , "Reduced by rule: 38	exp->assignment_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|exp ',' assignment_exp {
		if($1->kind==A_seqExp){
			$1->u.seqExp = A_ExpList(A_Pos(),$3,$1->u.seqExp);
			$$ = $1;
		}else{
			$$ = A_SeqExp(A_Pos(), A_ExpList(A_Pos(),$3,A_ExpList(A_Pos(),$1,nullptr)));
		}
		fprintf(cparser_outfile , "Reduced by rule: 39	exp->exp ',' assignment_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|error{echoE();	parseSuccessfully=false;}
	;

primary_exp:
	ID	 {
		// $$ = A_VarExp(A_Pos(),A_Var(A_Pos(),S_Symbol($1)));
		$$ = A_VarExp(A_Pos(),A_Var(A_Pos(),S_Symbol(string($1))));
		fprintf(cparser_outfile , "Reduced by rule: 40	primary_exp->ID	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|C_INT	 {
		$$ = A_IntExp(A_Pos(),$1);
		fprintf(cparser_outfile , "Reduced by rule: 41	primary_exp->C_INT	\tline:%d  pos:%d \n",LinePos,ColPos);
		}
	|C_CHAR	 {
		$$ = A_CharExp(A_Pos(),$1);
		fprintf(cparser_outfile , "Reduced by rule: 42	primary_exp->C_CHAR	\tline:%d  pos:%d \n",LinePos,ColPos);
		}
	|C_FLOAT	 {
		$$ = A_FloatExp(A_Pos(),$1);
		fprintf(cparser_outfile , "Reduced by rule: 43	primary_exp->C_FLOAT	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|C_STRING	 {
		$$ = A_StringExp(A_Pos(),$1);
		fprintf(cparser_outfile , "Reduced by rule: 44	primary_exp->C_STRING	\tline:%d  pos:%d \n",LinePos,ColPos);
		}
	|'(' exp ')'	 {
		$$ = A_ParentExp(A_Pos(),$2);
		fprintf(cparser_outfile , "Reduced by rule: 45	primary_exp->'(' exp ')'	\tline:%d  pos:%d \n",LinePos,ColPos);
	 }
    ;

postfix_exp:
	primary_exp	 {
		$$ = $1;
		fprintf(cparser_outfile , "Reduced by rule: 46	postfix_exp->primary_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|postfix_exp '[' exp ']'	{
		$$ = A_ArrayElmExp(A_Pos(),$3,$1);
		fprintf(cparser_outfile , "Reduced by rule: 47	postfix_exp->postfix_exp '[' exp ']'	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|postfix_exp '(' argument_exp_list ')'	 {
		$$ = A_CallExp(A_Pos(),$1->u.varExp->sym,$3);
		fprintf(cparser_outfile , "Reduced by rule: 48	postfix_exp->postfix_exp '(' argument_exp_list ')'	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|postfix_exp '(' ')'	 {
		$$ = A_CallExp(A_Pos(),$1->u.varExp->sym ,nullptr);
		fprintf(cparser_outfile , "Reduced by rule: 49	postfix_exp->postfix_exp '(' ')'	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|postfix_exp '.' ID	 {
		// $$ = A_RecordElmExp(A_Pos(),$1,A_Var(A_Pos(),S_Symbol($3)));
		$$ = A_RecordElmExp(A_Pos(),$1,A_Var(A_Pos(),S_Symbol(string($3))));
		fprintf(cparser_outfile , "Reduced by rule: 50	postfix_exp->postfix_exp '.' ID	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|postfix_exp POINTER ID	 {
		// $$ = A_PointerExp(A_Pos(),$1,A_Var(A_Pos(),S_Symbol($3)));
		$$ = A_PointerExp(A_Pos(),$1,A_Var(A_Pos(),S_Symbol(string($3))));
		fprintf(cparser_outfile , "Reduced by rule: 51	postfix_exp->POINTER ID	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|postfix_exp SELF_ADD	 {
		$$ = A_AssignementExp(A_Pos(), A_assign,$1, A_OpExp(A_Pos(),A_add,$1,A_IntExp(A_Pos(),1)));
		fprintf(cparser_outfile , "Reduced by rule: 52	postfix_exp->postfix_exp SELF_ADD	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|postfix_exp SELF_SUB	 {
		$$ = A_AssignementExp(A_Pos(), A_assign,$1, A_OpExp(A_Pos(),A_sub,$1,A_IntExp(A_Pos(),1)));
//		$$ = A_OpExp(A_Pos(),A_sub,$1,A_IntExp(A_Pos(),1));
		fprintf(cparser_outfile , "Reduced by rule: 53	postfix_exp->postfix_exp SELF_SUB	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	;

argument_exp_list:
	assignment_exp	 {
		$$ = A_ExpList(A_Pos(), $1, nullptr);
		fprintf(cparser_outfile , "Reduced by rule: 54	argument_exp_list->assignment_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|assignment_exp ',' argument_exp_list {
		$$ = A_ExpList(A_Pos(), $1, $3);
		fprintf(cparser_outfile , "Reduced by rule: 55	argument_exp_list->argument_exp_list ',' assignment_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	;

unary_exp:
	postfix_exp	 {
		$$ = $1;
		fprintf(cparser_outfile , "Reduced by rule: 56	unary_exp->postfix_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|SELF_ADD unary_exp	 {
		$$ = A_UnaryExp(A_Pos(),A_selfAdd, $2);
		fprintf(cparser_outfile , "Reduced by rule: 57	unary_exp->SELF_ADD unary_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|SELF_SUB unary_exp	 {
		$$ = A_UnaryExp(A_Pos(),A_selfSub, $2);
		fprintf(cparser_outfile , "Reduced by rule: 58	unary_exp->SELF_SUB unary_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|'&' cast_exp	 {
		$$ = A_UnaryExp(A_Pos(),A_address, $2);
		fprintf(cparser_outfile , "Reduced by rule: 59	unary_exp->'&' cast_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|'*' cast_exp	 {
		$$ = A_UnaryExp(A_Pos(),A_memory, $2);
		fprintf(cparser_outfile , "Reduced by rule: 60	unary_exp->'*' cast_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|'+' cast_exp	 {
		$$ = A_UnaryExp(A_Pos(),A_positive, $2);
		fprintf(cparser_outfile , "Reduced by rule: 61	unary_exp->'+' cast_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|'-' cast_exp	 {
		$$ = A_UnaryExp(A_Pos(),A_negative, $2);
		fprintf(cparser_outfile , "Reduced by rule: 62	unary_exp->'-' cast_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|'~' cast_exp	 {
		$$ = A_UnaryExp(A_Pos(),A_bitNeg, $2);
		fprintf(cparser_outfile , "Reduced by rule: 63	unary_exp->'~' cast_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|'!' cast_exp	 {
		$$ = A_UnaryExp(A_Pos(),A_nor, $2);
		fprintf(cparser_outfile , "Reduced by rule: 64	unary_exp->'!' cast_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	 }
	|SIZEOF unary_exp	 {
		$$ = A_UnaryExp(A_Pos(),A_sizeof, $2);
		fprintf(cparser_outfile , "Reduced by rule: 65	unary_exp->SIZEOF unary_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	 }
	;

cast_exp:
	unary_exp	 {
		$$ = $1;
		fprintf(cparser_outfile , "Reduced by rule: 66	cast_exp->unary_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|'(' type_name ')' cast_exp	 {
		$$ =  A_CastExp(A_Pos(),$2,$4);
		fprintf(cparser_outfile , "Reduced by rule: 67	cast_exp->'(' type_name ')' cast_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	;

multiplicative_exp:
	cast_exp	 {
		$$ = $1;
		fprintf(cparser_outfile , "Reduced by rule: 68	multiplicative_exp->cast_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|multiplicative_exp '*' cast_exp	 {
		$$ = A_OpExp(A_Pos(),A_mul,$1,$3);
		fprintf(cparser_outfile , "Reduced by rule: 69	multiplicative_exp->multiplicative_exp '*' cast_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|multiplicative_exp '/' cast_exp	 {
		$$ = A_OpExp(A_Pos(),A_div,$1,$3);
		fprintf(cparser_outfile , "Reduced by rule: 70	multiplicative_exp->multiplicative_exp '/' cast_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|multiplicative_exp '%' cast_exp	 {
		$$ = A_OpExp(A_Pos(),A_mod,$1,$3);
		fprintf(cparser_outfile , "Reduced by rule: 71	multiplicative_exp->multiplicative_exp  cast_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	;

shift_exp:
	additive_exp	 {
		$$ = $1;
		fprintf(cparser_outfile , "Reduced by rule: 72	shift_exp->additive_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|shift_exp LEFT_SHIFT additive_exp	 {
		$$ = A_OpExp(A_Pos(),A_lShift,$1,$3);
		fprintf(cparser_outfile , "Reduced by rule: 73	shift_exp->shift_exp LEFT_SHIFT additive_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|shift_exp RIGHT_SHIFT additive_exp	 {
		$$ = A_OpExp(A_Pos(),A_rShift,$1,$3);
		fprintf(cparser_outfile , "Reduced by rule: 74	shift_exp->shift_exp RIGHT_SHIFT additive_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	;

relational_exp:
	shift_exp	 {
		$$ = $1;
		fprintf(cparser_outfile , "Reduced by rule: 75	relational_exp->shift_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|relational_exp '<' shift_exp	 {
		$$ = A_OpExp(A_Pos(),A_less,$1,$3);
		fprintf(cparser_outfile , "Reduced by rule: 76	relational_exp->relational_exp '<' shift_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|relational_exp '>' shift_exp	 {
		$$ = A_OpExp(A_Pos(),A_greater,$1,$3);
		fprintf(cparser_outfile , "Reduced by rule: 77	relational_exp->relational_exp '>' shift_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	 }
	|relational_exp LESS_EQUAL shift_exp	 {
		$$ = A_OpExp(A_Pos(),A_lEqual,$1,$3);
		fprintf(cparser_outfile , "Reduced by rule: 78	relational_exp->relational_exp LESS_EQUAL shift_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|relational_exp GREATER_EQUAL shift_exp	 {
		$$ = A_OpExp(A_Pos(),A_gEqual,$1,$3);
		fprintf(cparser_outfile , "Reduced by rule: 79	relational_exp->relational_exp GREATER_EQUAL shift_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	 ;

equality_exp:
	relational_exp	 {
		$$ = $1;
		fprintf(cparser_outfile , "Reduced by rule: 80	equality_exp->relational_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|equality_exp EQUAL relational_exp	 {
		$$ = A_OpExp(A_Pos(),A_equal,$1,$3);
		fprintf(cparser_outfile , "Reduced by rule: 81	equality_exp->equality_exp EQUAL relational_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|equality_exp UNEQUAL relational_exp	 {
		$$ = A_OpExp(A_Pos(),A_unEqual,$1,$3);
		fprintf(cparser_outfile , "Reduced by rule: 82	equality_exp->equality_exp UNEQUAL relational_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	 ;

AND_exp:
	equality_exp	 {
		$$ = $1;
		fprintf(cparser_outfile , "Reduced by rule: 83	AND_exp->equality_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	 }
	|AND_exp '&' equality_exp	 {
		$$ = A_OpExp(A_Pos(),A_and,$1,$3);
		fprintf(cparser_outfile , "Reduced by rule: 84	AND_exp->AND_exp '&' equality_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
     ;

additive_exp:
	multiplicative_exp	 {
		$$ = $1;
		fprintf(cparser_outfile , "Reduced by rule: 85	additive_exp->multiplicative_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	 }
	|additive_exp '+' multiplicative_exp	 {
		$$ = A_OpExp(A_Pos(),A_add,$1,$3);
		fprintf(cparser_outfile , "Reduced by rule: 86	additive_exp->additive_exp '+' multiplicative_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|additive_exp '-' multiplicative_exp	 {
		$$ = A_OpExp(A_Pos(),A_sub,$1,$3);
		fprintf(cparser_outfile , "Reduced by rule: 87	additive_exp->additive_exp '-' multiplicative_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	;

exclusive_OR_exp:
	AND_exp	 {
		$$ = $1;
		fprintf(cparser_outfile , "Reduced by rule: 88	exclusive_OR_exp->AND_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|exclusive_OR_exp '^' AND_exp	 {
		$$ = A_OpExp(A_Pos(),A_exOr,$1,$3);
		fprintf(cparser_outfile , "Reduced by rule: 89	exclusive_OR_exp->exclusive_OR_exp '^' AND_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	;

inclusive_OR_exp:
	exclusive_OR_exp	 {
		$$ = $1;
		fprintf(cparser_outfile , "Reduced by rule: 90	inclusive_OR_exp->exclusive_OR_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|inclusive_OR_exp '|' exclusive_OR_exp	 {
		$$ = A_OpExp(A_Pos(),A_inOr,$1,$3);
		fprintf(cparser_outfile , "Reduced by rule: 91	inclusive_OR_exp->inclusive_OR_exp '|' exclusive_OR_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	;

logical_AND_exp:
	inclusive_OR_exp	 {
		$$ = $1;
		fprintf(cparser_outfile , "Reduced by rule: 92	logical_AND_exp->inclusive_OR_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	 }
	|logical_AND_exp AND inclusive_OR_exp	 {
		$$ = A_OpExp(A_Pos(),A_logicalAnd,$1,$3);
		fprintf(cparser_outfile , "Reduced by rule: 93	logical_AND_exp->logical_AND_exp AND inclusive_OR_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	;

logical_OR_exp:
	logical_AND_exp	 {
		$$ = $1;
		fprintf(cparser_outfile , "Reduced by rule: 94	logical_OR_exp->logical_AND_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|logical_OR_exp OR logical_AND_exp	 {
		$$ = A_OpExp(A_Pos(),A_logicalOr,$1,$3);
		fprintf(cparser_outfile , "Reduced by rule: 95	logical_OR_exp->logical_OR_exp OR logical_AND_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
    ;

conditional_exp:
	logical_OR_exp	 {
		$$ = $1;
		fprintf(cparser_outfile , "Reduced by rule: 96	conditional_exp->logical_OR_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	 }
	|logical_OR_exp '?' exp ':' conditional_exp	 {
		$$ = A_ConditionalExp(A_Pos(), $1, $3, $5);
		fprintf(cparser_outfile , "Reduced by rule: 97	conditional_exp->logical_OR_exp '?' exp ':' conditional_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	;

assignment_exp:
	conditional_exp	 {
		$$ = $1;
		fprintf(cparser_outfile , "Reduced by rule: 98	assignment_exp->conditional_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|unary_exp '=' assignment_exp	 {
		$$ =  A_AssignementExp(A_Pos(),A_assign,$1,$3);
		fprintf(cparser_outfile , "Reduced by rule: 99	assignment_exp->unary_exp '=' assignment_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|unary_exp MUL_ASSIGN assignment_exp	 {
		$$ =  A_AssignementExp(A_Pos(),A_assign,$1,A_OpExp(A_Pos(),A_mul,$1,$3));
		fprintf(cparser_outfile , "Reduced by rule: 100	assignment_exp->unary_exp MUL_ASSIGN assignment_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
		}
	|unary_exp DIV_ASSIGN assignment_exp	 {
		$$ =  A_AssignementExp(A_Pos(),A_assign,$1,A_OpExp(A_Pos(),A_div,$1,$3));
		fprintf(cparser_outfile , "Reduced by rule: 101	assignment_exp->unary_exp DIV_ASSIGN assignment_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|unary_exp MOD_ASSIGN assignment_exp	 {
		$$ =  A_AssignementExp(A_Pos(),A_assign,$1,A_OpExp(A_Pos(),A_mod,$1,$3));
		fprintf(cparser_outfile , "Reduced by rule: 102	assignment_exp->unary_exp MOD_ASSIGN assignment_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|unary_exp ADD_ASSIGN assignment_exp	 {
		$$ =  A_AssignementExp(A_Pos(),A_assign,$1,A_OpExp(A_Pos(),A_add,$1,$3));
		fprintf(cparser_outfile , "Reduced by rule: 103	assignment_exp->unary_exp ADD_ASSIGN assignment_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|unary_exp SUB_ASSIGN assignment_exp	 {
		$$ =  A_AssignementExp(A_Pos(),A_assign,$1,A_OpExp(A_Pos(),A_sub,$1,$3));
		fprintf(cparser_outfile , "Reduced by rule: 104	assignment_exp->unary_exp SUB_ASSIGN assignment_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|unary_exp LEFT_SHIFT_ASSIGN assignment_exp	 {
		$$ =  A_AssignementExp(A_Pos(),A_assign,$1,A_OpExp(A_Pos(),A_lShift,$1,$3));
		fprintf(cparser_outfile , "Reduced by rule: 105	assignment_exp->unary_exp LEFT_SHIFT_ASSIGN assignment_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|unary_exp RIGHT_SHIFT_ASSIGN assignment_exp	 {
		$$ =  A_AssignementExp(A_Pos(),A_assign,$1,A_OpExp(A_Pos(),A_rShift,$1,$3));
		 fprintf(cparser_outfile , "Reduced by rule: 106	assignment_exp->unary_exp RIGHT_SHIFT_ASSIGN assignment_exp	\tline:%d  pos:%d \n",LinePos,ColPos);\
	}
	|unary_exp BIT_AND_ASSIGN assignment_exp	 {
		$$ =  A_AssignementExp(A_Pos(),A_assign,$1,A_OpExp(A_Pos(),A_and,$1,$3));
		fprintf(cparser_outfile , "Reduced by rule: 107	assignment_exp->unary_exp BIT_AND_ASSIGN assignment_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|unary_exp BIT_XOR_ASSIGN assignment_exp	 {
		$$ =  A_AssignementExp(A_Pos(),A_assign,$1,A_OpExp(A_Pos(),A_exOr,$1,$3));
		fprintf(cparser_outfile , "Reduced by rule: 108	assignment_exp->unary_exp BIT_XOR_ASSIGN assignment_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|unary_exp BIT_OR_ASSIGN assignment_exp	 {
		$$ =  A_AssignementExp(A_Pos(),A_assign,$1,A_OpExp(A_Pos(),A_inOr,$1,$3));
		fprintf(cparser_outfile , "Reduced by rule: 109	assignment_exp->unary_exp BIT_OR_ASSIGN assignment_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	 }
	;

constant_exp:
	conditional_exp	 {
		$$ = $1;
		fprintf(cparser_outfile , "Reduced by rule: 110	constant_exp->conditional_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	;

dec:
	specifiers init_dec_list ';'	 {
		$$ = A_VarDec(A_Pos(),$1,$2);
		fprintf(cparser_outfile , "Reduced by rule: 111	dec->specifiers init_dec_list ';'	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|specifiers ';'		 {
		if($1->kind==A_structOrUnionSpecifier)
			$$ = A_StructOrUnionDec(A_Pos(), $1);
		fprintf(cparser_outfile , "Reduced by rule: 111	dec->specifiers ';'	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|TYPEDEF type_name ID ';'  {
		//  $$ = A_TypeDec(A_Pos(),$2,S_Symbol($3));
		 $$ = A_TypeDec(A_Pos(),$2,S_Symbol(string($3)));
		 fprintf(cparser_outfile , "Reduced by rule: 111	dec->TYPEDEF specifiers ID';'	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|error  {echoE();	parseSuccessfully=false;}
	;

for_loop_dec:
    specifiers init_dec_list {
        $$ = A_VarDec(A_Pos(),$1,$2);
        fprintf(cparser_outfile , "Reduced by rule: 111.505	for_loop_dec->specifiers init_dec_list ';'	\tline:%d  pos:%d \n",LinePos,ColPos);
    }
    |error {echoE();	parseSuccessfully=false;}
    ;


specifiers:
	VOID  	 {
		$$ = A_VoidSpecifiers(A_Pos());
		fprintf(cparser_outfile , "Reduced by rule: 113	specifiers->VOID  	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|CHAR  	 {
		$$ = A_CharSpecifiers(A_Pos());
		fprintf(cparser_outfile , "Reduced by rule: 114	specifiers->CHAR  	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|INT	 {
		$$ = A_IntSpecifiers(A_Pos());
		fprintf(cparser_outfile , "Reduced by rule: 115	specifiers->INT	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|FLOAT	 {
		$$ = A_FloatSpecifiers(A_Pos());
		fprintf(cparser_outfile , "Reduced by rule: 116	specifiers->FLOAT	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|struct_or_union_specifier 	 {
		$$ = $1;
		fprintf(cparser_outfile , "Reduced by rule: 117	specifiers->struct_or_union_specifier 	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|td_name {
		// $$ =  A_NameTySpecifiers(A_Pos(),S_Symbol($1));
		$$ =  A_NameTySpecifiers(A_Pos(),S_Symbol(string($1)));
		fprintf(cparser_outfile , "Reduced by rule: 117.5	specifiers->td_name 	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|error{echoE();	parseSuccessfully=false;}
	;

init_dec_list:
	init_declarator	 {
		$$ = A_InitDecList(A_Pos(),$1,nullptr);
		fprintf(cparser_outfile , "Reduced by rule: 119	init_dec_list->init_declarator	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|init_declarator ',' init_dec_list  {
		$$ = A_InitDecList(A_Pos(),$1,$3);
		fprintf(cparser_outfile , "Reduced by rule: 120	init_dec_list->init_dec_list ',' init_declarator	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	;

init_declarator:
	declarator	 {
		$$ = A_InitDeclarator(A_Pos(),$1,nullptr);
		fprintf(cparser_outfile , "Reduced by rule: 121	init_declarator->declarator	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|declarator '=' initializer	 {
		$$ = A_InitDeclarator(A_Pos(),$1, $3);
		fprintf(cparser_outfile , "Reduced by rule: 122	init_declarator->declarator '=' initializer	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|error{echoE();	parseSuccessfully=false;}
   ;

struct_or_union_specifier:
	STRUCT ID '{' struct_dec_list '}'	 {
		// $$ = A_StructOrUnionSpecifiers(A_Pos(),S_Symbol($2),$4);
		$$ = A_StructOrUnionSpecifiers(A_Pos(),S_Symbol(string($2)),$4);
		fprintf(cparser_outfile , "Reduced by rule: 123	struct_or_union_specifier->STRUCT ID '{' struct_dec_list '}'	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|STRUCT '{' struct_dec_list '}'	 {
		$$ = A_StructOrUnionSpecifiers(A_Pos(),nullptr,$3);
		fprintf(cparser_outfile , "Reduced by rule: 124	struct_or_union_specifier->STRUCT '{' struct_dec_list '}'	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|STRUCT ID	 {
		// $$ = A_StructOrUnionSpecifiers(A_Pos(),S_Symbol($2),nullptr);
		$$ = A_StructOrUnionSpecifiers(A_Pos(),S_Symbol(string($2)),nullptr);
		fprintf(cparser_outfile , "Reduced by rule: 125	struct_or_union_specifier->STRUCT ID	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|error{echoE();	parseSuccessfully=false;}
	;

struct_dec_list:
	struct_dec	 {
		$$ = A_StructDecList(A_Pos(),$1,nullptr);
		fprintf(cparser_outfile , "Reduced by rule: 129	struct_dec_list->struct_dec	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|struct_dec struct_dec_list 	 {
		$$ = A_StructDecList(A_Pos(),$1,$2);
		fprintf(cparser_outfile , "Reduced by rule: 130	struct_dec_list->struct_dec_list struct_dec	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	;

struct_dec:
  	specifiers ';'	 {
		$$ = A_StructDec(A_Pos(), $1, nullptr);
		fprintf(cparser_outfile , "Reduced by rule: 131	struct_dec->specifiers ';'	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|specifiers struct_declarator_list ';'	 {
	    $$ = A_StructDec(A_Pos(), $1, $2);
		fprintf(cparser_outfile , "Reduced by rule: 132	struct_dec->specifiers struct_declarator_list ';'	\tline:%d  pos:%d \n",LinePos,ColPos);
	 }
	 |error{echoE();	parseSuccessfully=false;}
	;

struct_declarator_list:
	struct_declarator	 {
		$$ = A_StructDeclaratorList(A_Pos(),$1,nullptr);
		fprintf(cparser_outfile , "Reduced by rule: 133	struct_declarator_list->struct_declarator	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|struct_declarator ',' struct_declarator_list	 {
		$$ = A_StructDeclaratorList(A_Pos(),$1,$3);
		fprintf(cparser_outfile , "Reduced by rule: 134	struct_declarator_list->struct_declarator_list ',' struct_declarator	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	;

struct_declarator:
	declarator	 {
		$$ = $1;
		fprintf(cparser_outfile , "Reduced by rule: 135	struct_declarator->declarator	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|declarator':' constant_exp	 {
		fprintf(cparser_outfile , "Reduced by rule: 136	struct_declarator->declarator':' constant_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|':' constant_exp	 {
		fprintf(cparser_outfile , "Reduced by rule: 137	struct_declarator->':' constant_exp	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|error{echoE();	parseSuccessfully=false;}
	;

declarator:
	pointer direct_declarator	 {
	    $2->adrLevel = $1->level;
		$$ = $2;
		fprintf(cparser_outfile , "Reduced by rule: 138	declarator->pointer direct_declarator	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|direct_declarator	 {
		$$ = $1;
		fprintf(cparser_outfile , "Reduced by rule: 139	declarator->direct_declarator	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|error{echoE();	parseSuccessfully=false;}
	;


direct_declarator:
	ID	 {
		// $$ = A_VarDeclaractor(A_Pos(),0,S_Symbol($1));
		$$ = A_VarDeclaractor(A_Pos(),0,S_Symbol(string($1)));
		fprintf(cparser_outfile , "Reduced by rule: 140	direct_declarator->ID	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|'(' declarator ')'	 {
		fprintf(cparser_outfile , "Reduced by rule: 141	direct_declarator->'(' declarator ')'	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|direct_declarator '[' assignment_exp ']'	 {
		$$ = A_ArrayDeclaractor(A_Pos(), 0, $3, $1);
		fprintf(cparser_outfile , "Reduced by rule: 142	direct_declarator->direct_declarator '[' assignment_exp ']'	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|direct_declarator '[' ']'	 {
		$$ = A_ArrayDeclaractor(A_Pos(), 0, nullptr, $1);
		fprintf(cparser_outfile , "Reduced by rule: 143	direct_declarator->direct_declarator '[' ']'	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|direct_declarator '(' ')'    {
		assert($1->kind==A_varDeclaractor);
	    $$ = A_FuncDeclaractor(A_Pos(),0,$1->u.varDeclaractor,nullptr);
		fprintf(cparser_outfile , "Reduced by rule: 147	direct_declarator->direct_declarator '(' ')'      	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	;

func_declarator:
    direct_declarator '(' parameter_list ')'	 {
		assert($1->kind==A_varDeclaractor);
	    $$ = A_FuncDeclaractor(A_Pos(),0,$1->u.varDeclaractor,$3);
		fprintf(cparser_outfile , "Reduced by rule: 145	func_declarator->direct_declarator '(' parameter_list ')'	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|direct_declarator '(' ')'    {
		assert($1->kind==A_varDeclaractor);
	    $$ = A_FuncDeclaractor(A_Pos(),0,$1->u.varDeclaractor,nullptr);
		fprintf(cparser_outfile , "Reduced by rule: 147	func_declarator->direct_declarator '(' ')'      	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|pointer func_declarator	 {
        $2->adrLevel = $1->level;
        $$ = $2;
    }
    ;


pointer:
	'*'	 {
	    $$ = A_Pointer();
		fprintf(cparser_outfile , "Reduced by rule: 148	pointer->'*'	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
    |'*' pointer{
		$2->level++;
		$$ = $2;
		cout << "ooooooooo" << endl;
		fprintf(cparser_outfile , "Reduced by rule: 148.5	pointer->'*'	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|error{echoE();	parseSuccessfully=false;}
    ;

parameter_list:
	parameter_dec	 {
		$$ = $1;
		fprintf(cparser_outfile , "Reduced by rule: 149	pointer->parameter_dec	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|parameter_dec ',' parameter_list 	 {
		$$ = A_ParamList(A_Pos(),$1->spec,$1->decltor,$3);
		fprintf(cparser_outfile , "Reduced by rule: 150	pointer->parameter_list ',' parameter_dec	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	;

parameter_dec:
	specifiers declarator	 {
		$$ = A_ParamList(A_Pos(),$1,$2,nullptr);
		fprintf(cparser_outfile , "Reduced by rule: 151	parameter_dec->specifiers declarator	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|error{echoE();	parseSuccessfully=false;}
    ;

identifier_list:
	ID	 {
		fprintf(cparser_outfile , "Reduced by rule: 152	identifier_list->ID	\tline:%d  pos:%d \n",LinePos,ColPos);
	 }
	|identifier_list ',' ID	 {
		fprintf(cparser_outfile , "Reduced by rule: 153	identifier_list->identifier_list ',' ID	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	;

type_name:
	specifiers	{
		$$ = A_TypeName(A_Pos(),$1,0);
		fprintf(cparser_outfile , "Reduced by rule: 158	type_name->specifiers	\tline:%d  pos:%d \n",LinePos,ColPos);
	 }
	|specifiers pointer {
		$$ = A_TypeName(A_Pos(),$1,$2->level);
		fprintf(cparser_outfile , "Reduced by rule: 159	type_name->specifiers pointer	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|error{echoE();	parseSuccessfully=false;}
	;

td_name:
	TD ID	 {
		$$ = $2;
		fprintf(cparser_outfile , "Reduced by rule: 160	td_name->TD ID	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	;

initializer:
	assignment_exp   	 {
		$$ = A_SingleInitializer(A_Pos(),$1);
		fprintf(cparser_outfile , "Reduced by rule: 161	initializer->assignment_exp   	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|'{' exp_list '}'  	 {
	    $$ = A_InitListInitializer(A_Pos(),$2);
		fprintf(cparser_outfile , "Reduced by rule: 162	initializer->'{' initializer_list '}'  	\tline:%d  pos:%d \n",LinePos,ColPos);
	 }
	|'{' exp_list ',' '}'	 {
	    $$ = A_InitListInitializer(A_Pos(),$2);
		fprintf(cparser_outfile , "Reduced by rule: 163	initializer->'{' initializer_list ',' '}'	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|'{' error '}' {echoE();	parseSuccessfully=false;}
	|error{echoE();	parseSuccessfully=false;}
	;

func_def:
	specifiers func_declarator dec_list compound_stm {
		$$ = A_FunDec(A_Pos(),$1,$2,$4);
		fprintf(cparser_outfile , "Reduced by rule: 173	func_def->specifiers declarator dec_list compound_stm'.' ID	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|specifiers func_declarator compound_stm {
		$$ = A_FunDec(A_Pos(),$1,$2,$3);
		fprintf(cparser_outfile , "Reduced by rule: 174	func_def->specifiers declarator compound_stm	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|specifiers func_declarator ';'{
	    $$ = A_FunDec(A_Pos(),$1,$2,nullptr);
	    fprintf(cparser_outfile , "Reduced by rule: 174.5	func_def->specifiers declarator compound_stm	\tline:%d  pos:%d \n",LinePos,ColPos);
	}
	|error  {echoE();	parseSuccessfully=false;}
	;

%%
void yyerror(const char* s){
    fprintf(cparser_outfile , "Parse error:%s\n",s );
    //JumpToNext(yyin);
}

void JumpToNext(FILE* in){
    int token = yylex();
	while(token!=';'&&token!=-1){
		token = yylex();
	}
}

void echoE(){
    printf("\t[bcgc-parser]:语法错误:\n\t\t\what():此位置发现一个语法错误:[line:%d,col:%d]\n",LinePos, ColPos);
}

