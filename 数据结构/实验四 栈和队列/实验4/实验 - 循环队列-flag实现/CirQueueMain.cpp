//CirQueueMain.cpp
#include <iostream>        //�������������
using namespace std;
#include "CirQueue.cpp"    //�����Ա�����ļ�

int main()
{
	CirQueue<int>a;           //����ģ�����ʵ�� 

	if (a.Empty()) {

		cout << "ѭ�����п�,��10ִ����Ӳ���" << endl;
		try
		{
			a.EnQueue(10);                      //��Ӳ���
		}
		catch (string wrong)
		{
			cout << wrong << endl;
		}

		cout << "��ȡ��ͷԪ��:" << endl;
		try
		{
			cout << a.GetQueue() << endl;           //����ͷԪ��
		}
		catch (string wrong)
		{
			cout << wrong << endl;
		}

		cout << "��15ִ����Ӳ���" << endl;
		try
		{
			a.EnQueue(15);
		}
		catch (string wrong)
		{
			cout << wrong << endl;
		}

		cout << "��ȡ��ͷԪ��" << endl;
		try
		{
			cout << a.GetQueue() << endl;
		}
		catch (string wrong)
		{
			cout << wrong << endl;
		}

		cout << "ִ�г��Ӳ���" << endl;     //���Ӳ���
		try
		{
			a.DeQueue();
		}
		catch (string wrong)
		{
			cout << wrong << endl;
		}

		cout << "��ȡ��ͷԪ��:" << endl;
		try
		{
			cout << a.GetQueue() << endl;
		}
		catch (string wrong)
		{
			cout << wrong << endl;
		}
	}
	else {

		cout << "ѭ�����в���" << endl;
	}


	//========= ѧ����ɣ������������룬������Ʋ��Դ��룬��ѭ������ - �ӿպͶ��� ������в���===============

    if (!a.Empty()) {
        cout << "ѭ������Ϊ�գ���10ִ����Ӳ���" << endl;
        try
        {
            a.EnQueue(10); //��Ӳ���
        }
        catch (string wrong)
        {
            cout << wrong << endl;
        }

        cout << "��ȡ��ͷԪ��:" << endl;
        try
        {
            cout << a.GetQueue() << endl; //����ͷԪ��
        }
        catch (string wrong)
        {
            cout << wrong << endl;
        }
    }
    else
    {
        cout << "ѭ�����в���" << endl;

    }
    
	// ��������
    if (a.Full())
    {
        cout << "ѭ����������ִ�г��Ӳ���" << endl;
        try
        {
            a.DeQueue(); //���Ӳ���
        }
        catch (string wrong)
        {
            cout << wrong << endl;
        }
        cout << "��ȡ��ͷԪ��:" << endl;
        try
        {
            cout << a.GetQueue() << endl;
        }
        catch (string wrong)
        {
            cout << wrong << endl;
        }
    }
    else
    {
        cout << "ѭ�����в���" << endl;
    }
    return 0;

}



