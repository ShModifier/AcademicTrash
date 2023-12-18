//SeqStackMain.cpp
#include <iostream>
using namespace std;
#include "SeqStack.cpp"

void ChangToM(int n,int m);

int main()
{    
	for (int j = 0; j < 8; j++)
	{
		int n, m;
		cout << "������һ����ת�������� :";
		cin >> n;
		cout << endl;
		cout << "Ҫת���ɵĽ�����(2-9) :";
		cin >> m;
		cout << endl;

		ChangToM(n, m);
	}
    
	return 0;
}

/*��mȥ��ʮ�������������Եõ�һ���̺�����������mȥ���̣��ֻ�õ�һ���̺���������˽��У�
ֱ����Ϊ��ʱΪֹ��Ȼ����ȵõ���������Ϊm�������ĵ�λ��Чλ����õ���������Ϊm�������ĸ�λ��Чλ��������������*/
void ChangToM(int n,int m)
{ 
	//-------------------- ѧ����� ----------------------
  
	SeqStack<int> Result;
	int divisor; 
	int remainder;
	divisor = n;
	//��ʼ����ת��
	while (divisor != 0)
	{
		remainder = divisor % m;
		divisor = divisor / m;
		Result.Push(remainder);
	}
	//���ת���������ת�����Ϊ����
	cout << "ת�����Ϊ��";
	while (!Result.Empty())
	{
		int num = Result.Pop();
		cout << num;
	}
	cout << endl;
	cout << endl;
}
