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
	string vname[6] = { "v0","v1","v2","v3","v4","v5" };  //��ʼ��������
	int pos1;                           //����
	int pos2;                           //����
	int m;
	MGraph<string> g(vname, 6, 0);        //����Graph����,ע��������ͼ
	while (choose == 1)                  //����
	{
		cout << "==================================" << "\n";
		cout << "��Ҫ���������Ϣ�밴0" << "\n";		   //������Ҫ���еĲ��������
		cout << "��Ҫ�������һ��������Ϣ�밴1" << "\n";
		cout << "��Ҫ�ߵ���Ϣ����밴2" << "\n";
		cout << "��Ҫɾ���밴3" << "\n";
		cout << "��Ҫ�����밴4" << "\n";
		cout << "��Ҫɾ��ĳ�����밴5" << "\n";
		cout << "��Ҫ����ĳ�����밴6" << "\n";
		cout << "��Ҫ������ȱ����밴7" << "\n";
		cout << "��Ҫ������ȱ����밴8" << "\n";
		cout << "��С������Prim �㷨 �밴9" << "\n";
		cout << "������������� �밴10" << "\n";
		cout << "��С������ Kruskal �㷨 �밴11" << "\n";
		cout << "��Ҫ�˳��밴12" << "\n";
		cout << "==================================" << "\n";
		cin >> which;
		switch (which)                  //����ѡ��
		{

		case 0:                   //���ͼ�ĸ������ֵ
			g.PrintVex();

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
				cout <<s<< "���������ȷ��" << endl;
			}

			break;

		case 2:                       //���ͼ�еı�	     
			cout << "���еıߵ���ϢΪ:" << "\n";
			g.PrintArc();
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
				cout << s<<"��ɾ��ʧ�ܣ�" << endl;
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
				cout << s<<"������ʧ�ܣ�" << endl;
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
				cout << s<<"������ʧ�ܣ�" << endl;
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
				cout << s<<",����ʧ�ܣ�" << endl;
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
				cout <<s<< "������ʧ�ܣ�" << endl;
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
				cout << s<<"������ʧ�ܣ�" << endl;
			}
			break;

		case 9:
			cout << "��������С��������ʼ�����ţ�" << "\n";
			int vs;
			cin >> vs;
			g.Prim(vs);  //������㿪ʼ������С������

			break;
		case 10:
			cout << "===============================" << endl;
			cout << "������ȱ������������������" << endl;
			cout << "-------------------------------" << endl;
			for (i = 0; i < MaxSize; i++)
				visited[i] = 0;
			cout << "��������������ʼ�����ţ�" << "\n";
			cin >> vs;
			g.SpaningTree(vs);  //������ȱ������������������ �̲�ver3 p217 3(5)
			break;

		case 11:
			g.Kruskal();
			break;
		case 12:              //�˳�
			choose = 0;
			break;
		}
	}
	return 0;
}
