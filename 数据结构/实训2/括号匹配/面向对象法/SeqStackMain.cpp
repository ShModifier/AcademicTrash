//SeqStackMain.cpp
#include <iostream> 
using namespace std;
#include "SeqStack.cpp"
#include <string>
int main()
{    
	//������ʽ���Զ���������
    char myexp[100];
	cout<<"������һ�����ʽ��������'(',')' :";
	cin >> myexp;
	
	cout<<"'"<<myexp<<"'"<< endl;
	
	//����˳��ջ��ʵ��
	SeqStack<char> S;
    
    int i,flag;
	i=0;
	flag=1;//ƥ���Ƿ���1Ϊƥ�䣬0Ϊ�޷�ƥ��
	int len = sizeof(myexp);
	for (int j = 0; j < len; j++)
	{
		if (myexp[j] == '(')
		{
			flag = 0;
			S.Push('(');
			i = j;
		}
		else if(myexp[j] == ')')
		{
			if (S.Empty())
			{
				flag = 0;
				i = j;
			}
			else 
			{
				flag = 1;
				S.Pop();
			}
		}
		else
		{
			continue;
		}
	}

	if (flag == 1 && S.GetTop()!=-1)
	{
		cout << "����ƥ��ɹ���" << endl;
	}
	else 
	{
		cout << "�����ڵ�" << i+1 <<"�����Ŵ�ƥ��ʧ��" << endl;
	}

	//------------------ ѧ����� --------------
	/*-----------------����ƥ�����---------------
	�ַ���ƥ��δ������
	1. ��Ϊ�����ţ�ѹջ
	2. ��Ϊ�����ţ�
		ջ���գ����ջ��Ԫ�أ�ջ��Ϊ�����ţ���ƥ�䣬����ջ��Ԫ�أ�
		���򣬲�ƥ�䣬����ƥ�����
	������һ��ƥ��
	*/


	//ƥ�������ջ�գ���ƥ��Ǻ�Ϊ1�����������ƥ��ɹ�����
	//�������ƥ��ʧ��λ�ã��������ڵ�xxx�����Ŵ�ƥ��ʧ�ܡ���
	return 0;
}

