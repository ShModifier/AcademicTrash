//CirQueueMain.cpp
#include <iostream>        //�������������
using namespace std;
#include "CirQueue.cpp"    //�����Ա�����ļ�

void main()
{
    CirQueue<int>a;           //����ģ�����ʵ�� 
	
	if(a.Empty( )){
	
		cout<<"ѭ�����п�,��10ִ����Ӳ���:"<<endl;
		try
		{
			a.EnQueue(10);                      //��Ӳ���
		}
		catch(char* wrong)
		{
			cout<<wrong;
		}

		cout<<"��ȡ��ͷԪ��:"<<endl;
		cout<<a.GetQueue( )<<endl;           //����ͷԪ��
    
		cout<<"��15ִ����Ӳ���:"<<endl;
		try
		{	
			a.EnQueue(15);
		}
		catch(char* wrong)
		{
			cout<<wrong;
		}
		cout<<"��ȡ��ͷԪ��:"<<endl;
		cout<<a.GetQueue( )<<endl;
	
	    cout<<"ִ�г��Ӳ���:"<<endl;     //���Ӳ���
	    a.DeQueue( );                 

	    cout<<"��ȡ��ͷԪ��:"<<endl;
	    cout<<a.GetQueue( )<<endl;
	}
	else{
	
	    cout<<"ѭ�����в���"<<endl;
	}

}