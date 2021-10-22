/*�����ܣ�����׺���ʽת��Ϊ��׺���ʽ�ķ�����
  ԭʼ�ķ�������
           expr --> expr + term
                  | expr - term
                  | term
           term --> term * factor
                  | term / factor
                  | factor
         factor --> ( expr )
                  | ID
                  | NUM

  ������ݹ����﷨�Ƶ��ķ��뷽����
            expr --> term expr_rest
       expr_rest --> + term {print('+')} expr_rest
                   | - term {print('-')} expr_rest
                   | ��
            term --> factor term_rest
       term_rest --> * factor {print('*')} term_rest
                   | / factor {print('/')} term_rest
                   | ��
          factor --> ( {print('(')} expr ) {print(')')}
                   | NUM {print(value_of_token)}
                   | ID  {print(lexeme)}
*/
#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define TKN_NUM 973
#define TKN_ID 397

int numOfleft = 0;//��ƥ��������ŵĸ���������ƥ������
int LookAhead; //��ŵ�ǰ�Ĵʷ���Ԫ������
int tokenval = 0; char lexeme[1024];

void expr();
void expr_rest();
void term();
void term_rest();
void factor();

int GetToken()
{
	int t, i;
	while (1) {
		t = getchar();
		if (t == ' ' || t == '\t')
            //token�ǿո���Ʊ��������
			;
		else if (isdigit(t)) {
		    //token���޷�������(TKN_NUM)����ȡ�������ֵ��Ȼ�����tokenval
			tokenval = 0;
			do {
				tokenval = tokenval * 10 + t - '0';
				t = getchar();
			} while (isdigit(t));
            //��TKN_NUM������ų�����ĸ�����»���'_'����ǰtokenΪ�Ƿ�������������Ƿ����������˳�
			if(isalpha(t) || t == '_'){
                printf("�����˷Ƿ�������\"%d",tokenval);
                do{
                    putc(t,stdout);
                    t = getchar();
                }
                while(isalpha(t) || t == '_');
                putc('\"',stdout);
                exit(1);
			}
			//TKN_NUM��ȡ�ɹ�
			ungetc(t, stdin);
			return TKN_NUM;
		}
		else if (isalpha(t) || t == '_') {
            //token�Ǳ�����(TKN_ID)����ȡ��������Ȼ�����char *lexeme
			i = 0;
			do {
				lexeme[i++] = t; t = getchar();
			} while (isalpha(t) || isdigit(t) || t == '_');
			lexeme[i] = '\0'; ungetc(t, stdin);
			return TKN_ID;
		}
		else {
		    //token������ֵ������'+'��'-'��'*'��'/'��'('��')'��
			tokenval = 0;
			return t;
		}
	}
}
void Match(int t)
{
	if (LookAhead == t)
        //ƥ��ɹ���Ȼ�������ȡ��һ��token
		LookAhead = GetToken();
	else {
        //ƥ��ʧ�ܣ�����������ԭ��
        if(t == ')')
            printf("\nȱ��������\n");
        exit(1); //��������
	}

}
void expr() {
	term();
	expr_rest();
}

void expr_rest() {
	switch (LookAhead){
	case '+':
		Match('+');
		term();
		printf("+ ");
		expr_rest();
		break;
	case '-':
		Match('-');
		term();
		printf("- ");
		expr_rest();
		break;
	default:
		break;
	}
}

void term() {
	factor();
	term_rest();
}

void term_rest() {
	switch (LookAhead){
	case '*':
		Match('*');
		factor();
		printf("* ");
		term_rest();
		break;
	case '/':
		Match('/');
		factor();
		printf("/ ");
		term_rest();
		break;
    case ')':
        if(numOfleft <= 0){
            //�Ѿ�û�������ſ���ƥ���ˣ����Ƕ����������
            printf("\n�ж����������\n");
            exit(1);
        }
	default:
		break;
	}
}

void factor() {
    switch(LookAhead){
	case '(':
        //factor --> ( expr )
		Match('(');
		numOfleft++;
		printf("( ");
		expr();
		Match(')');
		numOfleft--;
		printf(") ");
		break;
	case TKN_ID:
	    //factor --> ID
		printf("%s ",lexeme);
		Match(LookAhead);
		break;
	case TKN_NUM:
	    //factor --> NUM
		printf("%d ",tokenval);
		Match(LookAhead);
		break;
	default:
		printf("ȱ�ٲ�����");
		exit(1);
		break;
    }
}

int main()
{
	printf("��������ʽ��\n");
	LookAhead = GetToken();
	printf("���׺���ʽΪ��\n");
	expr();
	return 0;
}
