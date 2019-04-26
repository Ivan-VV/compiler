#include<iostream>
#include<fstream>
#include<stack>
#include<queue>
#include<string>
using namespace std;


#define err 100 //err��ʾ����,��100��ʾ
#define acc 101 //acc��101��ʾ

//���ż���0-18Ϊ�ս����19��25λΪ�ս��
enum sym {
	beginsym,// begin
	endsym,// endsym
	ifsym,// ifsym
	thensym,// thensym
	idsym,// idsym
	beingsym,// := 
	addsym,// +
	multisym,// *
	subsym,// -
	lbrack,// (
	rbrack,// )
	orsym,// or
	andsym,// and
	notsym,// not
	ropsym,// rop	
	truesym,// TRUE
	falsesym,// FALSE
	semicolon,// ;	
	octothorpe,// #
	S,
	L,
	K,
	A,
	C,
	B,
	E,
};


//ACTION���кŴ���״̬���кŴ����Ӧ�ķ��ս��,��ֵ��ʾ��Լ����ֵ��ʾ�ƽ�
extern int ACTION[43][19];

//GOTO���кŴ���״̬���кŴ����Ӧ���ս��
extern int GOTO[43][7];

//��Լ���кű�ʾ�ڼ�����Լʽ����1�б�ʾ��Լ�ĳ��ȣ��ڶ��б�ʾ��Լ���ĸ����ս��,����Ϊֻ�õ�2-21�Ź�Լʽ������ǰ����û��
extern int REDUCE[22][2];

//���Ŷ�Ӧ���ַ������飬�±��ʾ���ĸ�����
extern string sym_array[];

//�洢��Լʽ�ַ������кű�ʾ�ڼ�����Լʽ
extern string reduce_string[];

class SLR_1 {
	
private:
	stack<int> state;//״̬ջ
	stack<int> insym;//����ջ
	queue<int> waitinsym;//���������
	queue<int> reducequeue;//��¼���ù��Ĺ�Լʽ
	queue<int> stepqueue;//��¼��Լʽ��Ӧ�Ĳ���
	int action;//�洢���η����Ķ�������Ϊ�ƽ�����Ϊ��Լ
	int go_to;//�洢���η�������ת
	void showstate();//��ʾ״̬ջ����
	void showinsym();//��ʾ����ջ����
	void showwaitinsym();//��ʾ���봮
	void showaction();//��ʾ����
	void showinfo();//��ʾ��������
	void showreduce();//��ʾʹ�ù��Ĺ�Լʽ
public:
	void read(string filename);//����ʷ��������������봮�ļ��������������������
	void grammar_analysis();//�﷨����
};

enum sym getsym(string s);//��ȡ���ʶ�Ӧ��ö��ֵ

void showrules();//��ʾ�ķ�