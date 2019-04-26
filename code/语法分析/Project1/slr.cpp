#include"slr.h"

enum sym getsym(string s)//获取单词对应的枚举值
{
	int i;
	for (i = 0; i <= 18; i++)
		if (sym_array[i] == s) break;
	switch (i)
	{
	case 0:return beginsym; break;
	case 1:return endsym; break;
	case 2:return ifsym; break;
	case 3:return thensym; break;
	case 4:return idsym; break;
	case 5:return beingsym; break;
	case 6:return addsym; break;
	case 7:return multisym; break;
	case 8:return subsym; break;
	case 9:return lbrack; break;
	case 10:return rbrack; break;
	case 11:return orsym; break;
	case 12:return andsym; break;
	case 13:return notsym; break;
	case 14:return ropsym; break;
	case 15:return truesym; break;
	case 16:return falsesym; break;
	case 17:return semicolon; break;
	case 18:return octothorpe; break;
	default:return A; break;
	}
}


void SLR_1::read(string filename)//读入词法分析产生的输入串文件，将其存入待输入队列中
{
	ifstream fin;
	fin.open(filename.c_str(), ios::in);

	queue<string> q;
	string tmp;

	while (fin >> tmp)
	{
		q.push(tmp);
	}
	while (q.size() != 0)
	{
		if (getsym(q.front()) == A)
		{
			cout << "非法单词!" << endl;
			break;
		}
		else 
		waitinsym.push(getsym(q.front()));
		q.pop();
	}
}


void SLR_1::grammar_analysis()//语法分析
{
	int i;
	int step=1;//记录分析的步数
	int num = 0;//统计已经移进了多少个单词
	state.push(0);
	insym.push(octothorpe);
	cout <<endl<< "步骤|状态栈|符号栈|输入串|ACTION|GOTO" << endl;
	while (waitinsym.size() != 0)
	{
		if (ACTION[state.top()][waitinsym.front()] == err)//出错
		{
			cout << "出错:第"<<num+1<<"个单词" << sym_array[waitinsym.front()]<< endl;//显示出错单词位置和类型
			break;
		}
		else if (ACTION[state.top()][waitinsym.front()] ==acc)//acc
		{
			if (waitinsym.size() ==1)
			{
				action = ACTION[state.top()][waitinsym.front()];
				cout << "(" << step << ")|";
				showinfo();
				cout << "语法正确!" << endl;
				showreduce();
			}
			else
				cout << "出错!终止符后面不应该有单词!" << endl;
			break;
		}
		else if (ACTION[state.top()][waitinsym.front()] >= 0)//移进
		{
			action = ACTION[state.top()][waitinsym.front()];
			cout << "(" << step << ")|";
			showinfo();
			state.push(ACTION[state.top()][waitinsym.front()]);
			insym.push(waitinsym.front());
			waitinsym.pop();
			num++;
			step++;
		}
		else if (ACTION[state.top()][waitinsym.front()] < 0)//归约
		{
			int temp = ACTION[state.top()][waitinsym.front()];
			reducequeue.push(-temp);
			action =temp;
			cout << "("<<step<<")|";
			showstate();
			showinsym();
			showwaitinsym();
			for (i = 0; i <REDUCE[-temp][0]; i++)
			{
				state.pop();
				insym.pop();
			}
			insym.push(REDUCE[-temp][1]);
			go_to = GOTO[state.top()][insym.top() - 19];
			showaction();
			state.push(GOTO[state.top()][insym.top() - 19]);
			stepqueue.push(step++);
		}
	}
}

void SLR_1::showstate()//显示状态栈内容
{
	stack<int>temp1 = state;
	stack<int>temp2;
	while(temp1.size()!=0)
	{
		temp2.push(temp1.top());
		temp1.pop();
	}
	while (temp2.size() != 0)
	{
		if (temp2.top() >= 10)
			cout << "(" << temp2.top() << ")";
		else
			cout << temp2.top();
		temp2.pop();
	}
	cout << "|";
}

void SLR_1::showinsym()//显示符号栈内容
{
	stack<int>temp1 = insym;
	stack<int>temp2;
	while (temp1.size()!= 0)
	{
		temp2.push(temp1.top());
		temp1.pop();
	}
	while (temp2.size()!= 0)
	{
		cout << sym_array[temp2.top()]<<" ";
		temp2.pop();
	}
	cout << "|";
}

void SLR_1::showwaitinsym()//显示输入串
{
	queue<int>temp = waitinsym;
	while(temp.size()!=0)
	{ 
		cout << sym_array[temp.front()] << " ";
		temp.pop();
	}
	cout << "|";
}

void SLR_1::showaction()//显示动作
{
	if (action == acc)
		cout << "acc" << "|无goto动作"<<endl;
	else if (action >= 0)
		cout << "S" << action << "|无goto动作" << endl;
	else if (action < 0)
		cout << "r" << -action << "|"<<go_to << endl;
}

void SLR_1::showinfo()//显示分析过程
{
	showstate();
	showinsym();
	showwaitinsym();
	showaction();
}

void SLR_1::showreduce()//显示使用过的归约式
{
	cout << endl << endl << "本次语法分析过程中使用过的归约式:" << endl;
	while (reducequeue.size() != 0)
	{
		cout  << "第"<<stepqueue.front()<<"步:"<<reduce_string[reducequeue.front()] << endl;
		stepqueue.pop();
		reducequeue.pop();
	}
}