#include "lex.yy.c"
#include <iostream>
#define MAXN 50
using namespace std;
int lookahead;
int main() {
  string filename;
  cout << "请输入要编译的源程序文件名：";
  cin >> filename;
  BeginCompileOneFile(filename.c_str());
  //当flex扫描到文件末尾，yylex函数返回0
  lookahead = yylex();
  program();
  EndCompileOneFile();
  return 0;
}

void error() { cout << "无法匹配" << endl; }

void match(int TokenID) {
  if (lookahead == TokenID) {
    lookahead = yylex();
  } else {
    cout << "需要" << TokenID << ",但收到" << yytext << endl;
    exit(1);
  }
}

void program() {
  cout << "Program -> Block" << endl;
  block();
}

void block() {
  cout << "Block -> { decls stmts }" << endl;
  match(BRS_L);
  decls();
  stmts();
  match(BRS_R);
}

void decls() {
  if (lookahead == INT || lookahead == FLOAT || lookahead == CHAR) {
    cout << "decls -> decl decls" << endl;
    decl();
    decls();
  } else if (lookahead == ID || lookahead == IF || lookahead == WHILE ||
             lookahead == DO || lookahead == BREAK || lookahead == BRS_L) {
    cout << "decls -> nul" << endl;
  } else {
    error();
  }
}

void decl() {
  cout << "decl -> type id ;" << endl;
  type();
  match(ID);
  match(SMCL);
}

void type() {
  if (lookahead == INT) {
    cout << "type -> int" << endl;
    match(INT);
  } else if (lookahead == FLOAT) {
    cout << "type -> float" << endl;
    match(FLOAT);
  } else if (lookahead == CHAR) {
    cout << "type -> char" << endl;
    match(CHAR);
  } else {
    error();
  }
}

void stmts() {
  if (lookahead == ID || lookahead == IF || lookahead == WHILE ||
      lookahead == DO || lookahead == BREAK || lookahead == BRS_L) {
    cout << "stmts -> stmt stmts" << endl;
    stmt();
    stmts();
  } else if (lookahead == BRS_R) {
    cout << "stmts -> nul" << endl;
    return;
  } else {
    error();
  }
}

void stmt() {
  if (lookahead == ID) {
    cout << "stmt -> id = expr ;" << endl;
    match(ID);
    match(OP_ASSIGN);
    expr();
    match(SMCL);
  } else if (lookahead == IF) {
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
  } else if (lookahead == WHILE) {
    cout << "stmt -> while ( bool ) stmt" << endl;
    match(WHILE);
    match(PRTHS_L);
    bool_();
    match(PRTHS_R);
    stmt();
  } else if (lookahead == DO) {
    cout << "stmt -> do stmt while ( bool ) ;" << endl;
    match(DO);
    stmt();
    match(WHILE);
    match(PRTHS_L);
    bool_();
    match(PRTHS_R);
    match(SMCL);
  } else if (lookahead == BREAK) {
    cout << "stmt -> break;" << endl;
    match(BREAK);
    match(SMCL);
  } else if (lookahead == BRS_L) {
    cout << "stmt -> block" << endl;
    block();
  } else {
    error();
  }
}
void bool_() {
  cout << "bool -> expr bool_res" << endl;
  expr();
  if (lookahead == RELOP_LT) {
    cout << "bool_res -> < expr" << endl;
    match(RELOP_LT);
    expr();
  } else if (lookahead == RELOP_LE) {
    cout << "bool_res -> <= expr" << endl;
    match(RELOP_LE);
    expr();
  } else if (lookahead == RELOP_GT) {
    cout << "bool_res -> > expr" << endl;
    match(RELOP_GT);
    expr();
  } else if (lookahead == RELOP_GE) {
    cout << "bool_res -> >= expr" << endl;
    match(RELOP_GE);
    expr();
  } else if (lookahead == PRTHS_R) {
    cout << "bool_res -> nul";
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
  if (lookahead == OP_ADD) {
    cout << "expr_res -> + term expr_res" << endl;
    match(OP_ADD);
    term();
    expr_res();
  } else if (lookahead == OP_SUB) {
    cout << "expr_res -> - term expr_res" << endl;
    match(OP_SUB);
    term();
    expr_res();
  } else if (lookahead == RELOP_LT || lookahead == RELOP_LE ||
             lookahead == RELOP_GT || RELOP_GE || lookahead == PRTHS_R ||
             lookahead == SMCL) {
    cout << "expr_res -> nul" << endl;
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
  if (lookahead == OP_MUL) {
    cout << "term_res -> * factor term_res" << endl;
    match(OP_MUL);
    factor();
    term_res();
  } else if (lookahead == OP_DIV) {
    cout << "term_res -> / factor term_res" << endl;
    match(OP_DIV);
    factor();
    term_res();
  } else if (lookahead == OP_ADD || lookahead == OP_SUB ||
             lookahead == RELOP_LT || lookahead == RELOP_LE ||
             lookahead == RELOP_GT || RELOP_GE || lookahead == PRTHS_R ||
             lookahead == SMCL) {
    cout << "term_res -> nul" << endl;
  } else {
    error();
  }
}

void factor() {
  if (lookahead ==  PRTHS_L) {
    cout << "factor -> ( expr )" << endl;
    match(PRTHS_L);
    expr();
    match(PRTHS_R);
  } else if (lookahead == ID) {
    cout << "factor -> id" << endl;
    match(ID);
  } else if (lookahead == NUMBER) {
    cout << "factor -> num" << endl;
    match(NUMBER);
  } else {
    error();
  }
}
