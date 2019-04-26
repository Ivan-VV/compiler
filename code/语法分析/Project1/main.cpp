#include"slr.h"

//ACTION表，行号代表状态，列号代表对应的非终结符,负值表示归约，正值表示移进
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

//GOTO表，行号代表状态，列号代表对应的终结符
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

//归约表，行号表示第几个归约式，第1列表示归约的长度，第二列表示归约到哪个非终结符，因为只用到2-21号归约式，所以前两行没用
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

//符号对应的字符串数组，下标表示是哪个符号
string sym_array[] = {"begin","end","if","then","id",":=","+","*","-","(",")","or",
				"and","not","rop","true","false",";","#","S","L","K","A","C","B","E"};

//存储归约式字符串，行号表示第几个归约式
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
	cout << "请输入要分析的文件名:";
	cin >> filename;
	myslr.read(filename);
	myslr.grammar_analysis();

	system("pause");
	return 0;
}