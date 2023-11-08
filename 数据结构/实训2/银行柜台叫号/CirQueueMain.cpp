//CirQueueMain.cpp
#include <iostream> 
using namespace std;
#include "CirQueue.cpp" 

//==================���й�̨�к�ϵͳ==============================
int main()
{
	//���д�����ſ��������У�������ѧ�����
	CirQueue<int> Vip;
	CirQueue<int> NVip;

	//ѡ����ʵ����ݽṹ��ģ��Vip�ͻ�����ͨ�ͻ������Ŷ�
	//Vip - Vip�ͻ��Ŷӣ�NVip - ��ͨ�ͻ��Ŷ�

	int CountVip = 0;				//��ǰ�Ŷӵ�Vip�ͻ�����
	int CountNVip = 0;			//��ǰ�Ŷӵ���ͨ�ͻ�����
	int PosNo = 0;				//��ǰ�����̨���
	int flag = 1;					//����ϵͳ�Ƿ�������б��
	int temp;					//��ʱ�������ɴ�ͻ����
	int choose;					//ϵͳ�����е�ѡ��

	while (flag == 1)
	{
		cout << "++++++++����ѡ��+++++++++" << endl;
		cout << "[1] Vip�ͻ�ȡ�ţ�������1" << endl;
		cout << "[2] ��ͨ�ͻ�ȡ�ţ�������2" << endl;
		cout << "[3] Vip��̨����Ա�кŷ���������3" << endl;
		cout << "[4] ��ͨ��̨����Ա�кŷ���������4" << endl;
		cout << "[5] �˳�ϵͳ�밴5" << endl;
		cout << "����ѡ���ǣ�      ";
		cin >> choose;
		cout << endl;

		if (choose == 3 || choose == 4)
		{
			cout << "     ���������Ĺ�̨���:";
			cin >> PosNo;
			cout << endl;
		}
		cout << "++++++++++++++++++++++++++" << endl;
		cout << "---------------------------" << endl;

		switch (choose)
		{
		case 1:
			//ʵ��Vip�ͻ�ȡ���Ŷӣ��������"�������Ϊ Vxxx ,ǰ���� xxx ���ڵȴ�"
			CountVip++;
			Vip.EnQueue(CountVip);
			cout << "�������Ϊ V" << CountVip << " ,ǰ���� " << CountVip - 1 << " ���ڵȴ�"<< endl;
			break;

		case 2:
			//ʵ����ͨ�ͻ�ȡ���Ŷӣ��������"�������Ϊ Nxxx ,ǰ���� xxx ���ڵȴ�"
			CountNVip++;
			Vip.EnQueue(CountNVip);
			cout << "�������Ϊ N" << CountNVip << " ,ǰ���� " << CountNVip - 1 << " ���ڵȴ�" << endl;
			break;

		case 3:
			//ʵ��Vip��̨����Ա�кŷ���
			//���ȷ����Ŷӵ�Vip�ͻ����������"�� Vip�ͻ� xx �ŵ�Vip��̨ xx �Ŵ�������"
			//�����Ŷӵ�Vip�ͻ����ɷ����Ŷӵ���ͨ�ͻ����������"����ͨ�ͻ� xx �ŵ�Vip��̨ xx �Ŵ�������"
			//�����޿ͻ��Ŷӣ������"û�пͻ����Ŷӣ���"
			if (Vip.Empty()!=1)
			{
				cout << "�� Vip�ͻ� " << CountVip << "�ŵ�Vip��̨ " << PosNo << "�Ŵ�������" << endl;
				Vip.DeQueue();
				CountVip--;
			}
			else if(NVip.Empty() != 1)
			{
				cout << "����ͨ�ͻ� " << CountNVip << "�ŵ�Vip��̨ " << PosNo << "�Ŵ�������" << endl;
				NVip.DeQueue();
				CountNVip--;
			}
			else 
			{
				cout << "û�пͻ����Ŷӣ���" << endl;
			}
			break;

		case 4:
			// ʵ����ͨ��̨����Ա�кŷ���
			// ���ȷ����Ŷӵ���ͨ�ͻ����������"����ͨ�ͻ� xx �ŵ���ͨ��̨ xx �Ŵ�������"
			// �����Ŷӵ���ͨ�ͻ����ɷ����Ŷӵ�Vip�ͻ����������"��Vip�ͻ� xx �ŵ���ͨ��̨ xx �Ŵ�������"
			//�����޿ͻ��Ŷӣ������"û�пͻ����Ŷӣ���"
			if (NVip.Empty() != 1)
			{
				cout << "����ͨ�ͻ� " << NVip.GetQueue() << "�ŵ���ͨ��̨ " << PosNo << "�Ŵ�������" << endl;
				NVip.DeQueue();
			}
			else if (Vip.Empty() != 1)
			{
				cout << "�� Vip�ͻ� " << Vip.GetQueue() << "�ŵ���ͨ��̨ " << PosNo << "�Ŵ�������" << endl;
				Vip.DeQueue();
			}
			else
			{
				cout << "û�пͻ����Ŷӣ���" << endl;
			}

			break;

		case 5:
			cout << "�˳����з���ϵͳ..." << endl;
			flag = 0;

			break;

		default:
			cout << "       �������������ѡ��" << endl;
			break;

		}
		cout << "---------------------------" << endl;


	} // while
	return 0;
}