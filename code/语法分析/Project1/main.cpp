#include"slr.h"

//ACTION���кŴ���״̬���кŴ����Ӧ�ķ��ս��,��ֵ��ʾ��Լ����ֵ��ʾ�ƽ�
int ACTION[43][19] = {
{2,	err,	22,	err,	8,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	acc},
{2,	err,	22,	err,	8,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err},
{err,	4,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	41,	err},
{-3,	-3,	-3,	err,	-3,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	-3,	-3},
{2,	err,	err,	err,	8,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err},
{err,	-7,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	-7,	err},
{-4,	-4,	-4,	err,	-4,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	-4,	-4},
{err,	err,	err,	err,	err,	9,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	15,	err,	err,	err,	13,	14,	err,	err,	err,	err,	err,	err,	err,	err,	err},
{err,	-9,	err,	err,	err,	err,	11,	12,	err,	err,	err,	err,	err,	err,	err,	err,	err,	-9,	-9},
{err,	err,	err,	err,	15,	err,	err,	err,	13,	14,	err,	err,	err,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	15,	err,	err,	err,	13,	14,	err,	err,	err,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	15,	err,	err,	err,	13,	14,	err,	err,	err,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	15,	err,	err,	err,	13,	14,	err,	err,	err,	err,	err,	err,	err,	err,	err},
{err,	-14,	err,	-14,	err,	err,	-14,	-14,	err,	err,	-14,	-14,	-14,	err,	-14,	err,	err,	-14,	-14},
{err,	-10,	err,	-10,	err,	err,	-10,	12,	err,	err,	-10,	-10,	-10,	err,	-10,	err,	err,	-10,	-10},
{err,	-11,	err,	-11,	err,	err,	-11,	-11,	err,	err,	-11,	-11,	-11,	err,	-11,	err,	err,	-11,	-11},
{err,	-12,	err,	-12,	err,	err,	-12,	-12,	err,	err,	-12,	-12,	-12,	err,	-12,	err,	err,	-12,	-12},
{err,	err,	err,	err,	err,	err,	11,	12,	err,	err,	20,	err,	err,	err,	err,	err,	err,	err,	err},
{err,	-13,	err,	-13,	err,	err,	-13,	-13,	err,	err,	-13,	-13,	-13,	err,	-13,	err,	err,	-13,	-13},
{2,	err,	22,	err,	8,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	15,	err,	err,	err,	13,	28,	err,	err,	err,	27,	err,	29,	30,	err,	err},
{err,	err,	err,	err,	err,	err,	11,	12,	err,	err,	err,	err,	err,	err,	24,	err,	err,	err,	err},
{err,	err,	err,	err,	15,	err,	err,	err,	13,	14,	err,	err,	err,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	-19,	err,	err,	11,	12,	err,	err,	-19,	-19,	-19,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	31,	err,	err,	err,	err,	err,	err,	err,	32,	34,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	15,	err,	err,	err,	13,	28,	err,	err,	err,	27,	err,	29,	30,	err,	err},
{err,	err,	err,	err,	15,	err,	err,	err,	13,	28,	err,	err,	err,	27,	err,	29,	30,	err,	err},
{err,	err,	err,	-20,	err,	err,	err,	err,	err,	err,	-20,	-20,	-20,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	-21,	err,	err,	err,	err,	err,	err,	-21,	-21,	-21,	err,	err,	err,	err,	err,	err},
{-5,	err,	-5,	err,	-5,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	15,	err,	err,	err,	13,	28,	err,	err,	err,	27,	err,	29,	30,	err,	err},
{err,	err,	err,	-15,	err,	err,	err,	err,	err,	err,	-15,	-15,	34,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	15,	err,	err,	err,	13,	28,	err,	err,	err,	27,	err,	29,	30,	err,	err},
{err,	err,	err,	-16,	err,	err,	err,	err,	err,	err,	-16,	-16,	-16,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	-17,	err,	err,	err,	err,	err,	err,	-17,	-17,	-17,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	38,	32,	34,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	-18,	err,	err,	err,	err,	err,	err,	-18,	-18,	-18,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	err,	err,	11,	12,	err,	err,	20,	err,	err,	err,	24,	err,	err,	err,	err},
{-2,	-2,	-2,	err,	-2,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	-2,	-2},
{-8,	err,	-8,	err,	-8,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err},
{err,	-6,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	err,	-6,	err},
};

//GOTO���кŴ���״̬���кŴ����Ӧ���ս��
int GOTO[43][7] = {
{1,	err,	err,	7,	21,	err,	err},
{err,	err,	err,	err,	err,	err,	err},
{42,	3,	5,	7,	21,	err,	err},
{err,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	err,	err,	err},
{6,	err,	err,	7,	err,	err,	err},
{err,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	err,	err,	10},
{err,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	err,	err,	16},
{err,	err,	err,	err,	err,	err,	17},
{err,	err,	err,	err,	err,	err,	18},
{err,	err,	err,	err,	err,	err,	19},
{err,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	err,	err,	err},
{40,	err,	err,	7,	21,	err,	err},
{err,	err,	err,	err,	err,	26,	23},
{err,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	err,	err,	25},
{err,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	err,	36,	23},
{err,	err,	err,	err,	err,	37,	39},
{err,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	err,	33,	23},
{err,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	err,	35,	23},
{err,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	err,	err,	err},
{err,	err,	err,	err,	err,	err,	err},
};

//��Լ���кű�ʾ�ڼ�����Լʽ����1�б�ʾ��Լ�ĳ��ȣ��ڶ��б�ʾ��Լ���ĸ����ս������Ϊֻ�õ�2-21�Ź�Լʽ������ǰ����û��
int REDUCE[22][2] = {
{0,0},
{0,0},
{2,S},
{3,S},
{1,S},
{3,C},
{1,L},
{2,L},
{2,K},
{3,A},
{3,E},
{3,E},
{2,E},
{3,E},
{1,E},
{3,B},
{3,B},
{2,B},
{3,B},
{3,B},
{1,B},
{1,B},
};

//���Ŷ�Ӧ���ַ������飬�±��ʾ���ĸ�����
string sym_array[] = {"begin","end","if","then","id",":=","+","*","-","(",")","or",
				"and","not","rop","true","false",";","#","S","L","K","A","C","B","E"};

//�洢��Լʽ�ַ������кű�ʾ�ڼ�����Լʽ
string reduce_string[] =
{
	"",
	"S'->S",
	"S->CS",
	"S->begin L end",
	"S->A",
	"C->if B then",
	"L->S",
	"L->KS",
	"K->L;",
	"A->id:=E",
	"E->E+E",
	"E->E*E",
	"E->-E",
	"E->(E)",
	"E->id",
	"B->B or B",
	"B->B and B",
	"B->not B",
	"B->(B)",
	"B->-E rop E",
	"B->true",
	"B->false"
};

int main()
{
	string filename;
	SLR_1 myslr;
	showrules();
	cout << "������Ҫ�������ļ���:";
	cin >> filename;
	myslr.read(filename);
	myslr.grammar_analysis();

	system("pause");
	return 0;
}