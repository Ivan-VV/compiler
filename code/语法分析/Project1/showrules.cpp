#include"slr.h"

void showrules()//��ʾ�ķ�
{
	cout <<"ѧ��:31116102"<<endl<<"����:��һ��"<<endl<<"�༶:�ƿ�162"<<endl
		<< "���ķ�Ϊ��������ķ���" << endl
		<< "(1) S'->S               (12) E->-E " << endl
		<< "(2) S->CS               (13) E->(E) " << endl
		<< "(3) S->begin L end      (14) E->id " << endl
		<< "(4) S->A                (15) B->B or B " << endl
		<< "(5) C->if B then        (16) B->B and B " << endl
		<< "(6) L->S                (17) B->not B " << endl
		<< "(7) L->KS               (18) B->(B) " << endl
		<< "(8) K->L;               (19) B->-E rop E " << endl
		<< "(9) A->id:=E            (20) B->true " << endl
		<< "(10) E->E+E             (21) B->false " << endl
		<< "(11) E->E*E" << endl;
		
}