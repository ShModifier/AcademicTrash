#include<iostream>
#include <string>                  //�����׼���е�ͷ�ļ�
#include "graph.h"                //����ͷ�ļ�
using namespace std;

/*
 *ǰ��������ͼ������
 *��    �룺��
 *��    �ܣ�ͼ�ĳ�ʼ��
 *��    ������
 *��������������һ���յ�ͼ
 */
template <class T>
MGraph<T>::MGraph(T a[], int n, int e)
{
	vertexNum = n;                 //������
	arcNum = e;                    //����
	int i, j, k;

	for (i = 0; i < vertexNum; i++)
		vertex[i] = a[i];
	for (i = 0; i < vertexNum; i++)    //��ʼ���ڽӾ���
		for (j = 0; j < vertexNum; j++)
			arc[i][j] = 10000;

	int Weight;
	for (k = 0; k < arcNum; k++)   //��������ÿһ���ߣ����޸��ڽӾ������ӦԪ��
	{
		cin >> i >> j >> Weight;                    //��������������������
		arc[i][j] = Weight;                  //���б߱�־

	}

	if (arcNum == 0)
	{
		//�����,���ڵ��ԣ��̲�ver2 P176(ͼ6-37),ver3 P217(ͼ6-52)
		InsertArc(0, 1, 6);
		InsertArc(0, 2, 4);
		InsertArc(0, 3, 5);
		InsertArc(1, 4, 1);
		InsertArc(2, 4, 1);
		InsertArc(3, 5, 2);
		InsertArc(4, 6, 9);
		InsertArc(4, 7, 7);
		InsertArc(5, 7, 4);
		InsertArc(6, 8, 2);
		InsertArc(7, 8, 4);
	}
}

/*
 *ǰ��������ͼ�Ѵ���
 *��    �룺��
 *��    �ܣ����ͼ�����ж����������Ϣ
 *��    ����ͼ�����ж����������Ϣ
 *����������ͼ���ֲ���
 */
template <class T>
void MGraph<T>::PrintVex()           //ȡ���ж���            
{                                   //����Դ���ǵ�0�����㣬�����������0
	int i = 0;
	for (i = 0; i < vertexNum; i++)
	{                            //���ͼ�����еĶ���
		cout << vertex[i] << endl;
	}
}

/*
 *ǰ��������ͼ�Ѵ���
 *���룺����i
 *���ܣ����ͼ�ж���i��������Ϣ
 *�����ͼ�ж���i��������Ϣ
 *����������ͼ���ֲ���
 */
template <class T>
void MGraph<T>::GetVex(int i)      //ȡ����i             
{
	//����Դ���ǵ�0�����㣬�����������0

	if (i > vertexNum - 1 || i < 0) throw  string("λ���쳣");              //����i���������׳��쳣
	else
		cout << vertex[i] << endl;
}

/*
 *ǰ��������ͼ�Ѵ���
 *��    �룺����name,λ��num
 *��    �ܣ���ͼ��numλ�ò���һ������name
 *��    ����������벻�ɹ����׳��쳣
 *�����������������ɹ���ͼ��������һ������
 */
template <class T>
void MGraph<T>::InsertVex(int num, T name)        //��ͼ�в���һ�����㣬����Ϊnum��ֵΪname
{
	//����Դ���ǵ�0�����㣬�����������0
	if (num<0 || num>vertexNum) throw string("λ���쳣");           //���num���벻��ȷ�׳��쳣
	int row;                                        //��
	int col;                                        //��
	int numv = vertexNum - 1;                      //���һ���������ڵ�λ��

	vertexNum++;                                   //��������1

	//��num~numv��������λ��ԭ���㵽���һ������������һλ
	for (int i = numv; i >= num; i--)
		vertex[i + 1] = vertex[i];

	vertex[num] = name;                            //��Ҫ����Ķ����ֵ����numλ����

	for (row = numv; row >= 0; row--)                      //�Ѵ�num�е����һ�е�Ԫ�ؾ�������һ��
	{
		for (col = numv; col >= num; col--)
			arc[row][col + 1] = arc[row][col];
		arc[row][num] = 10000;
	}

	for (row = numv; row >= num; row--)                   //�Ѵ�num�е����һ�е�Ԫ�ؾ�������һ��
		for (col = 0; col <= numv + 1; col++)
			arc[row + 1][col] = arc[row][col];
	for (col = 0; col < vertexNum; col++)
		arc[num][col] = 10000;                   //��numλ�����ڵ��С��е�ֵ����Ϊ�����
}

/*
 *ǰ��������ͼ�Ѵ���
 *��    �룺����pos
 *��    �ܣ���ͼ��ɾ������pos
 *��    �������ɾ�����ɹ����׳��쳣
 *�������������ɾ���ɹ���ͼ�м�����һ������,��Ӧ�����������ı�Ҳ��ȥ
 */
template <class T>
void MGraph<T>::DeleteVex(int pos)              //ɾ����pos������
{                                               //����Դ���ǵ�0�����㣬�����������0
	if (pos<0 || pos>vertexNum - 1) throw string("λ���쳣");        //���pos���벻��ȷ�׳��쳣
	int row;                                       //��
	int col;                                       //��
	int numv = vertexNum;                            //numv���ڶ�����

	for (int i = pos; i < numv - 1; i++)
		vertex[i] = vertex[i + 1];                       //�Ѵ�pos������ÿ�����λ��������ǰ��һλ

	vertexNum--;                                 //��������1

	for (row = 0; row < numv; row++)
	{
		for (col = pos; col < numv; col++)
			arc[row][col] = arc[row][col + 1];        //�Ѵ�pos�е����һ�е�Ԫ�ؾ���ǰ��һ��
		arc[row][numv - 1] = 10000;                    //��pos���ڵ����ϵ�ֵ��Ϊ�����
	}

	for (row = pos; row < numv; row++)
		for (col = 0; col < numv; col++)
			arc[row][col] = arc[row + 1][col];        //�Ѵ�pos�е����һ�е�Ԫ�ؾ�������һ��
}

/*
 *ǰ��������ͼ�Ѵ���
 *��    �룺����n��w
 *��    �ܣ���ͼ��ɾ������n��w �����ı�
 *��    �������ɾ�����ɹ����׳��쳣
 *�������������ɾ���ɹ���ͼ�м�����һ����
 */
template <class T>
void MGraph<T>::DeleteArc(int i, int j)        //��ͼ��ɾ��һ���ߣ�����������������ı��Ϊi��j
{
	if (i > vertexNum - 1 || j > vertexNum - 1 || i < 0 || j < 0) throw string("λ���쳣");;    //������벻��ȷ�׳��쳣
	if (arc[i][j] == 10000) {
		cout << "�Ӷ���" << i << "������" << j << "û�бߣ��޷�ɾ��" << endl;
	}
	else {
		arc[i][j] = 10000;
		arcNum--;
	}
}

/*
 *ǰ��������ͼ�Ѵ���
 *��    �룺����i��j
 *��    �ܣ���ͼ�в��붥��i��j�����������ı�
 *��    ����������벻�ɹ����׳��쳣
 *�����������������ɹ���ͼ��������һ����
 */
template <class T>
void MGraph<T>::InsertArc(int i, int j, int n)   //��ͼ�в���һ���ߣ�����������������ı��Ϊi��j
{
	if (i > vertexNum - 1 || j > vertexNum - 1 || i < 0 || j < 0) throw string("λ���쳣");   //������벻��ȷ�׳��쳣	
	arc[i][j] = n;
	arcNum++;
	//cout << "��" << vertex[i] << "��" << vertex[j] << "��·������Ϊ��" << arc[i][j] << "\n"; //��������������֮���·��
}

/*
 *ǰ��������ͼ�Ѵ���
 *��    �룺��������ʼ����v
 *��    �ܣ��Ӷ���v����������ȱ���ͼ
 *��    ����ͼ�ж����һ����������
 *����������ͼ���ֲ���
 */
template <class T>
void MGraph<T>::DFSTraverse(int v)     //������ȱ���ͼ
{

	if (v >= vertexNum) throw string("λ���쳣");  //������벻��ȷ�׳��쳣
	cout << vertex[v] << " ";
	visited[v] = 1;                    //�ѷ���v����	  
	for (int j = 0; j < vertexNum; j++)
	{
		if (arc[v][j] < 10000 && visited[j] == 0)
			DFSTraverse(j);
	}
}

/*
 *ǰ��������ͼ�Ѵ���
 *��    �룺��������ʼ����v
 *��    �ܣ��Ӷ���v����������ȱ���ͼ
 *��    ����ͼ�ж����һ����������
 *����������ͼ���ֲ���
 */
template <class T>
void MGraph<T>::BFSTraverse(int v)     //������ȱ���ͼ
{
	if (v >= vertexNum) throw string("λ���쳣");      //������벻��ȷ�׳��쳣

	//��ʼ������,������в���˳��洢�Ҳ��ᷢ�����
	int front = -1;
	int rear = -1;                         
	int Q[MaxSize];

	cout << vertex[v] << " ";                //�����ʶ������
	visited2[v] = 1;
	Q[++rear] = v;

	while (front != rear)
	{
		v = Q[++front];                     //����ͷԪ�س��Ӳ��͵�v��
		for (int j = 0; j < vertexNum; j++)
			if (arc[v][j] < 10000 && visited2[j] == 0) {
				cout << vertex[j] << " ";
				visited2[j] = 1;
				Q[++rear] = j;
			}
	}
}

template <class T>
void MGraph<T>::PrintArc()
{
	//�ǶԳƾ��󣬴�Ȩ����ͼ
	int row, col;
	for (row = 0; row < vertexNum; row++)
		for (col = 0; col < vertexNum; col++)
			if (arc[row][col] != 10000)
				cout << "��" << vertex[row] << "��" << vertex[col] << "��·������Ϊ��" << arc[row][col] <<endl;
}

//����ǰ�᣺(1)�ڵ���ŵ������������������򣻣�2���ߵ������������Ӧ
template <class T>
void MGraph<T>::KeyPath(int Vfrom, int Vto)
{
	int ve[MaxSize], vl[MaxSize];//���㣨�¼������翪ʼʱ�������ʼʱ��

	struct EdgeType
	{
		int from, to;//�������ʼ���ն˶�����
		int weight;//��Ȩ
		int ee, el;//�ߣ�������翪ʼʱ�������ʼʱ��
	};

	EdgeType edge[30];
	int vk, vj,i, j, k;

	//�����߱�
	int edgeCounter = 0;   //��Ч����Ŀ
	for (i = Vfrom; i <= Vto; i++)
	{
		for (int j = Vfrom + 1; j <= Vto; j++)
		{
			if (arc[i][j] > 0 && arc[i][j] < 10000)
			{
				edge[edgeCounter].from = i;
				edge[edgeCounter].to = j;
				edge[edgeCounter].weight = arc[i][j];
				edge[edgeCounter].ee = -1;
				edge[edgeCounter].el = -1;
				edgeCounter++;
			}
		}
	}
	//----------------------- ���¼��㶥��ͱ�����/����ʼʱ�䣬�߽�check������������������
	//����VE
	ve[Vfrom] = 0;
	int maxve = 0;
	cout << "ve[" << Vfrom << "]=" << ve[Vfrom] << "  ";

	for (vk = Vfrom + 1; vk <= Vto; vk++)
	{
		maxve = 0;
		for (vj = Vfrom; vj <= vk - 1; vj++)
		{//j��k�ıߴ��ڣ�������
			if (arc[vj][vk] > 0 && arc[vj][vk] < 10000 && (arc[vj][vk] + ve[vj] > maxve))
			{
				maxve = arc[vj][vk] + ve[vj];
			}
		}
		ve[vk] = maxve;
		cout << "ve[" << vk << "]=" << ve[vk] << "  ";
	}
	cout << endl << "--------------------" << endl;

	//����VL
	vl[Vto] = ve[Vto];
	cout << "vl[" << Vto << "]=" << ve[Vto] << "  ";
	int minvl = 10000;

	for (vk = Vto - 1; vk >= Vfrom; vk--)
	{
		minvl = 10000;
		for (vj = vk + 1; vj <= Vto; vj++)
		{//k��j�ıߴ��ڣ���������
			if (arc[vk][vj] > 0 && arc[vk][vj] < 10000 && (vl[vj] - arc[vk][vj] < minvl))
				minvl = vl[vj] - arc[vk][vj];
		}
		vl[vk] = minvl;
		cout << "vl[" << vk << "]=" << vl[vk] << "  ";
	}
	cout << endl << "--------------------" << endl;

	//����ee[i]
	for (i = 0; i < edgeCounter; i++)
	{
		edge[i].ee = ve[edge[i].from];
	}

	//����el[i]
	for (i = edgeCounter - 1; i >= 0; i--)
	{
		edge[i].el = vl[edge[i].to] - edge[i].weight;

	}

	cout << endl << "-----�ߵ���Ϣ---------------" << endl;
	cout << "ee[i]: ";
	for (i = 0; i < edgeCounter; i++)
		cout << edge[i].ee << ",";
	cout << endl;
	cout << "el[i]: ";
	for (i = 0; i < edgeCounter; i++)
		cout << edge[i].el << ",";
	cout << endl;
	cout << endl << "--------------------" << endl;

	//����ؼ��ڵ�
	cout << "��" << vertex[Vfrom] << " �� " << vertex[Vto] << "�ؼ��ڵ�Ϊ��";
	for (i = Vfrom; i <= Vto; i++)
	{
		if (ve[i] == vl[i])
			cout << vertex[i] << ", ";
	}
	cout << endl;

	//����ؼ���
	cout << "��" << vertex[Vfrom] << " �� " << vertex[Vto] << "�ؼ��(��)Ϊ��" << endl;
	for (i = 0; i < edgeCounter; i++)
	{
		if (edge[i].ee == edge[i].el)
		{
			cout << "< " << vertex[edge[i].from] << " , " << vertex[edge[i].to] << ">  " << edge[i].weight << endl;
		}
	}
	cout << endl << "--------------------" << endl;

	//������·������
	cout << "��" << vertex[Vfrom] << " �� " << vertex[Vto] << "����(���·������)Ϊ��";
	cout << vl[Vto] << endl;
}