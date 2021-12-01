#ifndef YYSTYPE
#define YYSTYPE int
#endif
//终结符号
#define	ID	    0
#define	NUMBER	1
#define	TRUE	2
#define	FALSE	3
#define	IF	    4
#define	THEN	5
#define	ELSE	6
#define	WHILE	7
#define	DO	    8
#define	BREAK	9
#define	INT	    10
#define	CHAR	11
#define	FLOAT	12
#define	BOOL	13
#define	RELOP_LT	14
#define	RELOP_E	    15
#define	RELOP_GT	16
#define	RELOP_NE	17
#define	RELOP_EE	18
#define	RELOP_LE	19
#define	RELOP_GE	20
#define	OR	    21
#define	AND	    22
#define	uminus	23
#define OP_ADD  24
#define OP_SUB  25
#define OP_MUL  26
#define OP_DIV  27
#define OP_ASSIGN 28 //'='
#define COMMA   29 //','
#define PRTHS_L 30 //'('
#define PRTHS_R 31 //')'
#define BRK_L   32 //'['
#define BRK_R   33 //']'
#define BRS_L   34 //'{'
#define BRS_R   35 //'}'
#define SMCL    36 //';'
//非终结符号
#define PROGRAM 0
#define BLOCK   1
#define DECLS   2
#define DECL    3
#define TYPE    4
#define STMTS	5
#define STMT	6
#define EXPR	7
#define EXPR_RES 8
#define BOOL	9
#define TERM	10
#define TERM_RES 11
#define FACTOR 	12

extern YYSTYPE yylval;
