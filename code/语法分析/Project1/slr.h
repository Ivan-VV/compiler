#include<iostream>
#include<fstream>
#include<stack>
#include<queue>
#include<string>
using namespace std;


#define err 100 //err表示出错,用100表示
#define acc 101 //acc用101表示

//符号集，0-18为终结符，19到25位为终结符
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


//ACTION表，行号代表状态，列号代表对应的非终结符,负值表示归约，正值表示移进
extern int ACTION[43][19];

//GOTO表，行号代表状态，列号代表对应的终结符
extern int GOTO[43][7];

//归约表，行号表示第几个归约式，第1列表示归约的长度，第二列表示归约到哪个非终结符,，因为只用到2-21号归约式，所以前两行没用
extern int REDUCE[22][2];

//符号对应的字符串数组，下标表示是哪个符号
extern string sym_array[];

//存储归约式字符串，行号表示第几个归约式
extern string reduce_string[];

class SLR_1 {
	
private:
	stack<int> state;//状态栈
	stack<int> insym;//符号栈
	queue<int> waitinsym;//待输入队列
	queue<int> reducequeue;//记录采用过的归约式
	queue<int> stepqueue;//记录归约式对应的步骤
	int action;//存储本次分析的动作，正为移进，负为归约
	int go_to;//存储本次分析的跳转
	void showstate();//显示状态栈内容
	void showinsym();//显示符号栈内容
	void showwaitinsym();//显示输入串
	void showaction();//显示动作
	void showinfo();//显示分析过程
	void showreduce();//显示使用过的归约式
public:
	void read(string filename);//读入词法分析产生的输入串文件，将其存入待输入队列中
	void grammar_analysis();//语法分析
};

enum sym getsym(string s);//获取单词对应的枚举值

void showrules();//显示文法