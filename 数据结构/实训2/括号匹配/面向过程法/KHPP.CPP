#include <iostream>      //�������������
#include <string>
using namespace std;

int main()
{
	char myexp[100];
	cout<<"������һ������ʽ��������'(',')' :";
	gets_s(myexp);//�ӱ�׼�����ж�ȡ����
	cout<<myexp<< endl;

	char S[100];//ģ��ջ
	int top,i,flag;
	top=-1;//topջ��ָ��
	i=0;
	flag=1;//��ǰ�Ƿ�ƥ��ɹ�
 
	//while(myexp[i]!='\0')//�ַ���ƥ��δ����
	for(int j=0;j<sizeof(myexp);j++)
	{
		//------------------ ѧ����� --------------
		//1. ��Ϊ�����ţ�ѹջ
		//2. ��Ϊ�����ţ�
		//	ջ���գ����ջ��Ԫ�أ�ջ��Ϊ�����ţ���ƥ�䣬����ջ��Ԫ�أ�
		//	���򣬲�ƥ�䣬����ƥ�����
		if (myexp[j] == '(')
		{
			top++;
			flag=0;
			i = j;
	    }
		else if (myexp[j] == ')')
		{
			if (top>-1)
			{
				top--; 
				flag = 1;
			}
			else 
			{
				i = j;
				flag = 0;
				break;
			}
		}
		else 
		{
			continue;
		}
        //i++;//������һ��ƥ��
	}

  	if (flag==1&& top==-1)
		cout<<"����ƥ��ɹ���"<<endl;
	else
		cout<<"�����ڵ�"<<i+1<<"�����Ŵ�ƥ��ʧ�ܡ�"<<endl;
	return 0;
}

