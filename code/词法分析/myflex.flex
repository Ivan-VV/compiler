%{
	FILE *fout;
	int flag=1;
%}

BEGINSYM "begin"
ENDSYM "end"
IFSYM "if"
THENSYM "then"
BEINGSYM ":="
ADDSYM "+"
MULTISYM "*"
SUBSYM "-"
LBRACK "("
RBRACK ")"
ORSYM "or"
ANDSYM "and"
NOTSYM "not"
ROPSYM ">="|"<="|"<>"|"=="|">"|"<"
TRUESYM "true"
FALSESYM "false"
SEMICOLON ";"
IDSYM [a-zA-Z][a-zA-Z0-9]*

%%

{BEGINSYM} {fputs("begin ",fout);}
{ENDSYM} {fputs("end ",fout);}
{IFSYM} {fputs("if ",fout);}
{THENSYM} {fputs("then ",fout);}
{BEINGSYM} {fputs(":= ",fout);}
{ADDSYM} {fputs("+ ",fout);}
{MULTISYM} {fputs("* ",fout);}
{SUBSYM} {fputs("- ",fout);}
{LBRACK} {fputs("( ",fout);}
{RBRACK} {fputs(") ",fout);}
{ORSYM} {fputs("or ",fout);}
{ANDSYM} {fputs("and ",fout);}
{NOTSYM} {fputs("not ",fout);}
{ROPSYM} {fputs("rop ",fout);}
{TRUESYM} {fputs("true ",fout);}
{FALSESYM} {fputs("false ",fout);}
{SEMICOLON} {fputs("; ",fout);}
{IDSYM} {fputs("id ",fout);}
[^" "] {fputs("�Ƿ�����",fout);fputs(yytext,fout);fputs(" ",fout);printf("�Ƿ�����");puts(yytext);printf("\n");flag=0;}
%%
int main()
{
	char readname[20];
	char writename[20];
	printf("ѧ��:31116102\n����:��һ��\n�༶:�ƿ�162\n���ķ�Ϊ��������ķ�:\n");
	printf("(1) S'->S               (12) E->-E \n");
	printf("(2) S->CS               (13) E->(E) \n");
	printf("(3) S->begin L end      (14) E->id \n");
	printf("(4) S->A                (15) B->B or B \n");
	printf("(5) C->if B then        (16) B->B and B \n");
	printf("(6) L->S                (17) B->not B \n");
	printf("(7) L->KS               (18) B->(B) \n");
	printf("(8) K->L;               (19) B->-E rop E \n");
	printf("(9) A->id:=E            (20) B->true \n");
	printf("(10) E->E+E             (21) B->false \n");
	printf("(11) E->E*E\n");
	printf("������Ҫ���дʷ��������ļ���:\n");
	gets(readname);
	printf("������Ҫд��ʷ�����������ļ���:\n");
	gets(writename);
	fout=fopen(writename,"w");
	yyin=fopen(readname,"r");
		yylex();
	fclose(yyin);
	fputs("# ",fout);
	fclose(fout);
	if(flag==1)
		printf("�ʷ��������,�ɹ�!�����д���ļ�\n");
	else
		printf("�ʷ��������,ʧ��!���зǷ�����,�����д���ļ�\n");
	system("pause");
	return 0;
}
int yywrap()
{
	return 1;
}
