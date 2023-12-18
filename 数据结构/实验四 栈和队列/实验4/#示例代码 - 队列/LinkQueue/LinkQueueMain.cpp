//LinkQueueMain.cpp
#include<iostream>       //�������������
using namespace std;
#include"LinkQueue.cpp"  //�����Ա�����ļ�

void main()
{
    LinkQueue<int> a;         //����ģ�����ʵ�� 
    
	if (a.Empty()){
	
		cout<<"�ӿ�,��10ִ����Ӳ���:\n";
		try
		{
			a.EnQueue(10);             //��Ӳ���
		}
		catch(char* wrong)
		{
			cout<< wrong;
		}
		cout<<"�鿴��ͷԪ��:"<<endl;
		cout<<a.GetQueue( )<<endl;  //����ͷԪ��

		cout<<"��15ִ����Ӳ���:"<<endl;
		try
		{
			a.EnQueue(15);
		}
		catch(char* wrong)
		{
			cout<< wrong;
		}
		cout<<"�鿴��ͷԪ��:"<<endl;
		cout<<a.GetQueue()<<endl;

	
		cout<<"ִ�г��Ӳ���:"<<endl;  //���Ӳ���
		a.DeQueue( );              

		cout<<"�鿴��ͷԪ��:"<<endl;
		cout<<a.GetQueue( )<<endl;
	}
	else{
	
		cout<<"���в���";
	}
	a.~LinkQueue( );
}
