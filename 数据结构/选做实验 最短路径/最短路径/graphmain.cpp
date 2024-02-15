#include <iostream>
#include <string>                   //�����׼���е�ͷ�ļ�
#include "graph.cpp"                //����graph.cpp�ļ�
using namespace std;
int visited[MaxSize];
int visited2[MaxSize];
int main(int argc, char* argv[])
{
	int i;
	int choose = 1;                      //����
	int which;                         //����ѡ�����	
	string name;                       //���붥���ֵ	                                                          
	string vname[7] = { "��ʳ�㳡","��һ��ѧ¥","�ڶ���ѧ¥","ͼ���","��һʵ��¥","�ڶ�ʵ��¥","�ִ���������" };  //��ʼ�������� �̲�ver2 P168(ͼ6-28)��ver3 �̲�P195(ͼ6-20)
	//string vname[7]={"v0","v1","v2","v3","v4","v5","v6"};  //��ʼ�������� �̲�ver2P185(ͼ6-51)
	int pos1;                           //����
	int pos2;                           //����
	int m;
	MGraph<string> g(vname, 7, 0);        //����Graph���� �̲�ver2 P168(ͼ6-28)��ver3 �̲�P195(ͼ6-20)
	//MGraph<string> g(vname,7,0);        //����Graph����  �̲�ver2 P185(ͼ6-51)
	while (choose == 1)                  //����
	{
		cout << "++++++++++++++++++++++++++++++++" << "\n";
		cout << "��Ҫ���������Ϣ�밴0" << "\n";		   //������Ҫ���еĲ��������
		cout << "��Ҫ�������һ��������Ϣ�밴1" << "\n";
		cout << "��Ҫ�ߵ���Ϣ����밴2" << "\n";
		cout << "��Ҫɾ���밴3" << "\n";
		cout << "��Ҫ�����밴4" << "\n";
		cout << "��Ҫɾ��ĳ�����밴5" << "\n";
		cout << "��Ҫ����ĳ�����밴6" << "\n";
		cout << "��Ҫ������ȱ����밴7" << "\n";
		cout << "��Ҫ������ȱ����밴8" << "\n";

		cout << "Dijkstra���·��(����Դ)�밴11" << "\n";
		cout << "Dijkstra���·��(�����)�밴12" << "\n";
		cout << "Floyd���·���밴13" << "\n";
		cout << "��Ҫ�˳��밴10" << "\n";
		cout << "++++++++++++++++++++++++++++++++" << "\n";
		cin >> which;
		switch (which)                  //����ѡ��
		{

		case 0:                   //���ͼ�ĸ������ֵ
			g.PutVex();

			break;

		case 1:                   //���ͼ�����ⶥ���ֵ
			try
			{
				int i;
				cout << "�����붥�㣺" << "\n";
				cin >> i;
				g.GetVex(i);

			}
			catch (string s)
			{
				cout << s << endl;
			}

			break;

		case 2:                       //���ͼ�еı�	     
			cout << "���еıߵ���ϢΪ:" << "\n";
			g.PutArc();
			break;

		case 3:                        //ɾ��hh����
			int hh;
			cout << "������Ҫɾ���Ķ���" << "\n";
			cin >> hh;
			try
			{
				g.DeleteVex(hh);
			}
			catch (string s)
			{
				cout << "ɾ��ʧ��:" << s<< endl;
			}
			break;

		case 4:                        //��nnλ�ò���ֵΪname�Ķ���
			int nn;
			cout << "������Ҫ����Ķ���λ�ü�����" << "\n";
			cin >> nn >> name;
			try
			{
				g.InsertVex(nn, name);
			}
			catch (string s)
			{
				cout << "����ʧ��:"<<s << endl;
			}
			break;

		case 5:                      //ɾ��������֮���·��         
			cout << "�����������㣺" << "\n";
			cin >> pos1 >> pos2;
			try
			{
				g.DeleteArc(pos1, pos2);
			}
			catch (string s)
			{
				cout << "ɾ��ʧ��:" <<s<< endl;
			}

			break;

		case 6:                   //����һ����         
			cout << "�����������㣺" << "\n";
			cin >> pos1 >> pos2;
			cout << "������·����" << "\n";
			cin >> m;
			try
			{
				g.InsertArc(pos1, pos2, m);
			}
			catch (string s)
			{
				cout << "����ʧ��:"<<s << endl;
			}

			break;

		case 7:                  //��ȱ���
			cout << "�����붥�㣺" << "\n";
			for (i = 0; i < MaxSize; i++)
				visited[i] = 0;
			int mm;
			cin >> mm;
			try
			{
				g.DFSTraverse(mm);
			}
			catch (string s)
			{
				cout << s << endl;
			}

			break;

		case 8:                  //��ȱ���
			cout << "�����붥�㣺" << "\n";

			for (i = 0; i < MaxSize; i++)
				visited2[i] = 0;
			int mr;
			cin >> mr;
			try
			{
				g.BFSTraverse(mr);
				cout << "\n";
			}
			catch (string s)
			{
				cout <<s << endl;
			}
			break;

		case 10:              //�˳�
			choose = 0;
			break;

		case 11:                  //Dijkstra ���·��
			cout << "������Դ�㣺" << endl;

			int from;
			cin >> from;
			g.Dijkstra(from);
			cout << endl;
			break;

		case 12:                  //Dijkstra ���·��		  
			int from1, to1;
			cout << "������Դ�㣺" << endl;
			cin >> from1;
			cout << "�������յ㣺" << endl;
			cin >> to1;
			g.Dijkstra2(from1, to1);
			cout << endl;
			break;
		case 13:                  //Floyd �����������·��

			g.Floyd();
			cout << endl;
			break;

		} //for switch
	}
	return 0;
}
