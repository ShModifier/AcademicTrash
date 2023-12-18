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
	string vname[5] = { "V0-���","V1-�㹤��","V2-�㽭��ý","V3-����","V4-����" };  //��ʼ��������
	int pos1;                           //����
	int pos2;                           //����
	int m;
	MGraph<string> g(vname, 5, 0);        //����Graph����
	//MGraph<string> g(vname, 5, 11);   //�ֶ������

	while (choose == 1)                  //����
	{

		cout << "==================================" << "\n";
		cout << "��Ҫ���������Ϣ�밴0" << "\n";		   //������Ҫ���еĲ��������
		cout << "��Ҫ�������һ��������Ϣ�밴1" << "\n";
		cout << "��Ҫ�������Ϣ�밴2" << "\n";
		cout << "��Ҫɾ�������밴3" << "\n";
		cout << "��Ҫ���붥���밴4" << "\n";
		cout << "��Ҫɾ��ĳ�����밴5" << "\n";
		cout << "��Ҫ����ĳ�����밴6" << "\n";
		cout << "��Ҫ������ȱ����밴7" << "\n";
		cout << "��Ҫ������ȱ����밴8" << "\n";
		cout << "��Ҫ�˳��밴10" << "\n";
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
				cout << s << endl;
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
				cout << s << "��ɾ��ʧ�ܣ�" << endl;
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
				cout << s << ", ����ʧ�ܣ�" << endl;
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
				cout << s << "������ʧ�ܣ�" << endl;
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
				cout << s << "������ʧ�ܣ�" << endl;
			}

			break;

		case 7:                  //��ȱ���
			cout << "�����붥�㣺" << "\n";
			int mm;
			cin >> mm;

			for (i = 0; i < MaxSize; i++)
				visited[i] = 0;
			cout << endl;
			cout << "----�ݹ��㷨----" << endl;
			try {
				g.DFSTraverse(mm);   //�ݹ��㷨
			}
			catch (string s)
			{
				cout << s << "������ʧ�ܣ�" << endl;
			}
			cout << endl;
			cout << "-----------------------" << endl;

			//------------------------------
			cout << endl;
			for (i = 0; i < MaxSize; i++)
				visited[i] = 0;
			try {
				g.FDG_DFSTraverse(mm);  //�ǵݹ��㷨             
			}
			catch (string s)
			{
				cout << s << "������ʧ�ܣ�" << endl;
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
				cout << endl;
			}
			catch (string s)
			{
				cout << s<<"������ʧ�ܣ�" << endl;
			}
			break;

		case 10:              //�˳�
			choose = 0;
			break;
		}
	}
	return 0;
}
