#include"slr.h"

enum sym getsym(string s)//��ȡ���ʶ�Ӧ��ö��ֵ
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


void SLR_1::read(string filename)//����ʷ��������������봮�ļ��������������������
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
			cout << "�Ƿ�����!" << endl;
			break;
		}
		else 
		waitinsym.push(getsym(q.front()));
		q.pop();
	}
}


void SLR_1::grammar_analysis()//�﷨����
{
	int i;
	int step=1;//��¼�����Ĳ���
	int num = 0;//ͳ���Ѿ��ƽ��˶��ٸ�����
	state.push(0);
	insym.push(octothorpe);
	cout <<endl<< "����|״̬ջ|����ջ|���봮|ACTION|GOTO" << endl;
	while (waitinsym.size() != 0)
	{
		if (ACTION[state.top()][waitinsym.front()] == err)//����
		{
			cout << "����:��"<<num+1<<"������" << sym_array[waitinsym.front()]<< endl;//��ʾ������λ�ú�����
			break;
		}
		else if (ACTION[state.top()][waitinsym.front()] ==acc)//acc
		{
			if (waitinsym.size() ==1)
			{
				action = ACTION[state.top()][waitinsym.front()];
				cout << "(" << step << ")|";
				showinfo();
				cout << "�﷨��ȷ!" << endl;
				showreduce();
			}
			else
				cout << "����!��ֹ�����治Ӧ���е���!" << endl;
			break;
		}
		else if (ACTION[state.top()][waitinsym.front()] >= 0)//�ƽ�
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
		else if (ACTION[state.top()][waitinsym.front()] < 0)//��Լ
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

void SLR_1::showstate()//��ʾ״̬ջ����
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

void SLR_1::showinsym()//��ʾ����ջ����
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

void SLR_1::showwaitinsym()//��ʾ���봮
{
	queue<int>temp = waitinsym;
	while(temp.size()!=0)
	{ 
		cout << sym_array[temp.front()] << " ";
		temp.pop();
	}
	cout << "|";
}

void SLR_1::showaction()//��ʾ����
{
	if (action == acc)
		cout << "acc" << "|��goto����"<<endl;
	else if (action >= 0)
		cout << "S" << action << "|��goto����" << endl;
	else if (action < 0)
		cout << "r" << -action << "|"<<go_to << endl;
}

void SLR_1::showinfo()//��ʾ��������
{
	showstate();
	showinsym();
	showwaitinsym();
	showaction();
}

void SLR_1::showreduce()//��ʾʹ�ù��Ĺ�Լʽ
{
	cout << endl << endl << "�����﷨����������ʹ�ù��Ĺ�Լʽ:" << endl;
	while (reducequeue.size() != 0)
	{
		cout  << "��"<<stepqueue.front()<<"��:"<<reduce_string[reducequeue.front()] << endl;
		stepqueue.pop();
		reducequeue.pop();
	}
}