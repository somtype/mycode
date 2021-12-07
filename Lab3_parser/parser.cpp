#include "lex.yy.c"
#include <iostream>
#include <vector>
#define MAXN 50
using namespace std;
int map[MAXN][MAXN];
int lookahead;

void program();
void block();
void decls();
void decl();
void type();
void stmts();
void stmt();
void bool_();
void expr();
void expr_res();
void term();
void term_res();
void factor();
void error() { cout << "无法匹配" << endl; }
void match(int TokenID) {
    if (lookahead == TokenID) {
        lookahead = yylex();
    } else {
        cout << "需要" << TokenID << ",但收到" << yytext << endl;
        exit(1);
    }
}
void makeMap(){
    
}
void program() {
    cout << "Program -> Block\n" << endl;
    Block();
}

void block() {
    cout << "Block -> { decls stmts }" << endl;
    match('{');
    decls();
    stmts();
    match('}');
}

void decls() {
    int extend = map[DECLS][lookahead];
    if (extend == 1) {
        cout << "decls -> decl decls" << endl;
        decl();
        decls();
    } else if (extend == 2) {
        cout << "decls -> nul" << endl;
        return;
    } else {
        error();
    }
}

void decl() {
    type();
    match(ID);
}

void type() {
    int extend = map[TYPE][lookahead];
    if (extend == 1) {
        cout << "type -> int" << endl;
        match(INT);
    } else if (extend == 2) {
        cout << "type -> float" << endl;
        match(FLOAT);
    } else if (extend == 3) {
        cout << "type -> char" << endl;
        match(CHAR);
    } else {
        error();
    }
}

void stmts() {
    int extend = map[STMTS][lookahead];
    if (extend == 1) {
        cout << "stmts ->  stmt stmts" << endl;
        stmt();
        stmts();
    } else if (extend == 2) {
        cout << "stmts -> nul" << endl;
        return;
    } else {
        error();
    }
}

void stmt() {
    int extend = map[STMT][lookahead];
    if (extend == 1) {
        cout << "stmt -> id = expr ;" << endl;
        match(ID);
        match(OP_ASSIGN);
        expr();
        match(SMCL);
    } else if (extend == 2) {
        cout << "stmt -> if ( bool ) stmt";
        match(IF);
        match(PRTHS_L);
        bool_();
        match(PRTHS_R);
        stmt();
        if (lookahead == ELSE) {
            cout << " else stmt";
            match(ELSE);
            stmt();
        }
        cout << endl;
    } else if (extend == 3) {
        cout << "while ( bool ) stmt" << endl;
        match(WHILE);
        match(PRTHS_L);
        bool_();
        match(PRTHS_R);
        stmt();
    } else if (extend == 4) {
        cout << "stmt -> do stmt while ( bool ) ;" << endl;
        match(DO);
        stmt();
        match(WHILE);
        match(PRTHS_L);
        bool_();
        match(PRTHS_R);
        match(SMCL);
    } else if (extend == 5) {
        cout << "stmt -> break;" << endl;
        match(BREAK);
        match(SMCL);
    } else if (extend == 6) {
        cout << "stmt -> block" << endl;
        block();
    } else {
        error();
    }
}
void bool_() {
    expr();
    int extend = map[BOOL][lookahead];
    if (extend == 1) {
        cout << "bool -> expr < expr" << endl;
        match(RELOP_LT);
        expr();
    } else if (extend == 2) {
        cout << "bool -> expr <= expr" << endl;
        match(RELOP_LE);
        expr();
    } else if (extend == 3) {
        cout << "bool -> expr > expr" << endl;
        match(RELOP_GT);
        expr();
    } else if (extend == 4) {
        cout << "bool -> expr >= expr" << endl;
        match(RELOP_GE);
        expr();
    } else if (extend == 5) {
        cout << "bool -> expr";
        return;
    } else {
        error();
    }
}

void expr() {
    cout << "expr -> term expr_res" << endl;
    term();
    expr_res();
}

void expr_res() {
    int extend = map[EXPR_RES][lookahead];
    if (extend == 1) {
        cout << "expr_res -> + term expr_res" << endl;
        match(OP_ADD);
        term();
        expr_res();
    } else if (extend == 2) {
        cout << "expr_res -> - term expr_res" << endl;
        match(OP_SUB);
        term();
        expr_res();
    } else if (extend == 3) {
        cout << "expr_res -> nul" << endl;
        return;
    } else {
        error();
    }
}

void term() {
    cout << "term -> factor term_res" << endl;
    factor();
    term_res();
}

void term_res() {
    int extend = map[TERM_RES][lookahead];
    if (extend == 1) {
        cout << "term_res -> * factor term_res" << endl;
        match(OP_MUL);
        factor();
        term_res();
    } else if (extend == 2) {
        cout << "term_res -> / factor term_res" << endl;
        match(OP_DIV);
        factor();
        term_res();
    } else if (extend == 3) {
        cout << "term_res -> nul" << endl;
        return;
    } else {
        error();
    }
}

void factor() {
    int extend = map[FACTOR][lookahead];
    if (extend == 1) {
        cout << "factor -> ( expr )" << endl;
        match(PRTHS_L);
        expr();
        match(PRTHS_R);
    } else if (extend == 2) {
        cout << "factor -> id" << endl;
        match(ID);
    } else if (extend == 3) {
        cout << "factor -> num" << endl;
        match(NUMBER);
    } else {
        error();
    }
}

int main() {
    string filename;
    cout << "请输入要编译的源程序文件名：";
    cin >> filename;
    BeginCompileOneFile(filename.c_str());
    //当flex扫描到文件末尾，yylex函数返回0
    lookahead = yylex();
    Program();
    EndCompileOneFile();
    return 0;
}
