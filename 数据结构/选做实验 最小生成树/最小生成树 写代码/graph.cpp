#include<iostream>
#include <string>                  //�����׼���е�ͷ�ļ�
#include "graph.h"                //����ͷ�ļ�
using namespace std;

//�ڽӾ���  ����ͼ

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

	for (i = 0; i < vertexNum; i++)    //��ʼ���ڽӾ���,Ҳ��MAXSIZE��ȫ���ô�ֵ
		for (j = 0; j < vertexNum; j++)
			arc[i][j] = 10000;

	int Weight;
	for (k = 0; k < arcNum; k++)   //��������ÿһ���ߣ����޸��ڽӾ������ӦԪ��
	{
		cin >> i >> j >> Weight;                    //��������������������
		arc[i][j] = Weight;                  //���б߱�־
		arc[j][i] = Weight;
	}

	if (arcNum == 0)
	{
		//�����,���ڵ���,�̲ĵ�����P190 ͼ 6-16
		InsertArc(0, 1, 34);
		InsertArc(0, 2, 46);
		InsertArc(0, 5, 19);

		InsertArc(1, 4, 12);

		InsertArc(2, 3, 17);
		InsertArc(2, 5, 25);

		InsertArc(3, 4, 38);
		InsertArc(3, 5, 25);

		InsertArc(4, 5, 26);
	}
}

template <class T>
void MGraph<T>::PutVex(int i, T value)           //ȡ���ж���            
{
	if (i > vertexNum - 1 || i < 0) throw string("λ���쳣");
	vertex[i] = value;
}

/*
 *ǰ��������ͼ�Ѵ���
 *��    �룺��
 *��    �ܣ����ͼ�����ж����������Ϣ
 *��    ����ͼ�����ж����������Ϣ
 *����������ͼ���ֲ���
 */
template <class T>
void MGraph<T>::PrintVex()
{
	//����Դ���ǵ�0�����㣬�����������0
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
	if (i > vertexNum - 1 || i < 0)
		throw string("λ���쳣");              //����i���������׳��쳣
	else
		cout << vertex[i] << endl;                       //���ض���i	
}

/*
 *ǰ��������ͼ�Ѵ���
 *��    �룺����name,λ��num
 *��    �ܣ���ͼ��numλ�ò���һ������name
 *��    ����������벻�ɹ����׳��쳣
 *�����������������ɹ���ͼ��������һ������
 */
template <class T>
void MGraph<T>::InsertVex(int num, T name)        //��ͼ�в���һ�����㣬����Ϊi��ֵΪvalue
{                                                //����Դ���ǵ�0�����㣬�����������0
	if (num<0 || num>vertexNum) throw string("λ���쳣");       //���num���벻��ȷ�׳��쳣
	int row;                                        //��
	int col;                                        //��
	int numv = vertexNum - 1;                                      //���һ���������ڵ�λ��

	vertexNum++;                                   //��������1

	for (int i = numv; i >= num; i--)                      //i�����һ���������һ��λ�ÿ�ʼѭ��
		vertex[i + 1] = vertex[i];                       //�Ѵ�numλ�õĶ��㵽���һ������������һλ

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
	if (pos<0 || pos>vertexNum - 1) throw string("λ���쳣");       //���pos���벻��ȷ�׳��쳣
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
	//������벻��ȷ�׳��쳣
	if (i > vertexNum - 1 || j > vertexNum - 1 || i < 0 || j < 0) throw string("λ���쳣");    
	
	if (arc[i][j] == 10000)
	{
		cout << "����֮��û�бߣ��޷�ɾ��" << endl;
	}
	else {
		arc[i][j] = 10000;
		arc[j][i] = 10000;
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
void MGraph<T>::InsertArc(int i, int j, int n)   //��ͼ�в���һ���ߣ�����������������ı��Ϊi��j����Ȩn
{
	//������벻��ȷ�׳��쳣	
	if (i > vertexNum - 1 || j > vertexNum - 1 || i < 0 || j < 0) throw string("λ���쳣"); 
	
	if (arc[i][j] < 10000)
	{
		cout << "����֮���Ѵ��ڱߣ��޷�����" << endl;
	}
	else {
		arc[i][j] = n;
		arc[j][i] = n;
		arcNum++;
	}
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
	if (v >= vertexNum) throw string("λ���쳣");   //������벻��ȷ�׳��쳣

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
	if (v >= vertexNum) throw string("λ���쳣");   //������벻��ȷ�׳��쳣

	int front = -1;
	int rear = -1;                         //��ʼ������,������в���˳��洢�Ҳ��ᷢ�����
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
	int row, col;
	for (row = 0; row < vertexNum; row++)
		for (col = 0; col < vertexNum; col++)
			if (arc[row][col] < 10000)
				cout << "��" << vertex[row] << "��" << vertex[col] << "��·������Ϊ��" << arc[row][col] << endl;
}

/*����������ȱ����� ������������� �̲� p217 3(5)*/
template <class T>
void MGraph<T>::SpaningTree(int v)
{

	if (v >= vertexNum) throw string("λ���쳣");   //������벻��ȷ�׳��쳣

	visited[v] = 1;                    //�ѷ���v����

	for (int j = 0; j < vertexNum; j++)
	{
		if (arc[v][j] < 10000 && visited[j] == 0)
		{
			cout << "(v" << v << " , v" << j << ") " << arc[v][j] << endl;
			SpaningTree(j);
		}
	}
}

template<class T>
void MGraph<T>::BFSTree(int v)
{
	if (v >= vertexNum) throw string("λ���쳣");   //������벻��ȷ�׳��쳣
	int front = -1;
	int rear = -1;                         //��ʼ������,������в���˳��洢�Ҳ��ᷢ�����
	int Q[MaxSize];

	visited2[v] = 1;
	Q[++rear] = v;

	while (front != rear)
	{
		v = Q[++front];                     //����ͷԪ�س��Ӳ��͵�v��
		for (int j = 0; j < vertexNum; j++)
		{
			if (arc[v][j] < 10000 && visited2[j] == 0) {
				cout << "(v" << v << " , v" << j << ") " << arc[v][j] << endl;
				visited2[j] = 1;
				Q[++rear] = j;
			}
		}
	}
}

/* Prim�㷨 ��v��ʼ������С������*/
template <class T>
void MGraph<T>::Prim(int v)  
{
	cout << "===============================" << endl;
	cout << "��С������Prim �㷨" << endl;
	cout << "-------------------------------" << endl;

	int i, j, k;
	int adjvex[MaxSize]; //�������ڵ���Ϣ����ǰѡ�еĶ����±꣩
	int lowcost[MaxSize];//����������Ȩ��Ϣ����ǰ��������������Ȩ��

	//���¶������ʼ����v������Ϣ���Լ�������v��Ȩ��Ϣ
	for (i = 0; i < vertexNum; i++)
	{
		lowcost[i] = arc[v][i];
		adjvex[i] = v;
	}
	lowcost[v] = 0;

	for (k = 1; k < vertexNum; k++)  //ѭ��n-1�Σ���Ҫ�ҵ�n-1���ߣ�������С������
	{
		//���뵱ǰ����������̱ߵ��ڽӵ��±�j
		int min_cost = 10000;
		int	 j = -1;
		for (i = 0; i < vertexNum; i++)
		{
			if (lowcost[i] < min_cost && lowcost[i] != 0)
			{
				min_cost = lowcost[i];
				j = i;
			}
		}

		//ѡȡ��̱߼�����С������
		cout << "(v" << adjvex[j] << " , v" << j << ") " << lowcost[j] << endl;

		//�������ڶ�����Ϣ�ͱ�Ȩ��Ϣ��ע�⣺��j������Ȩ��lowcost�����������������ڵ�ͱ�Ȩ
		lowcost[j] = 0;
		for (i = 0; i < vertexNum; i++)
		{
			if (arc[i][j] < lowcost[i])
			{
				lowcost[i] = arc[i][j];
				adjvex[i] = j;
			}
		}
	}
	cout << "-------------------------------" << endl;
}

template <class T>
int MGraph<T>::FindRoot(int parent[], int v)
{
	int t = v;
	while (parent[t] > -1)
		t = parent[t];
	return t;
}

/* Kruskal�㷨 ������С������*/
template <class T>
void MGraph<T>::Kruskal()
{
	//�߱����鶨�壨Ϊ��������������Ȩ�����������μ�����С�������������򲻼��룬����n-1����Ϊֹ
	struct EdgeType
	{
		int from, to;
		int weight;
	}Edge[50];//���n*��n-1)/2���ߣ��ɸ��ݾ���Ӧ���޸�

	//�����߱�
	int i, j;
	int edgeNum = 0;
	for (i = 0; i < vertexNum; i++) // ɨ���ڽӾ���������,����ͼ�Գƾ���
	{
		for (j = i + 1; j < vertexNum; j++)
		{
			if (arc[i][j] < 10000)//���ڱ�
			{
				edgeNum++;
				Edge[edgeNum - 1].from = i;
				Edge[edgeNum - 1].to = j;
				Edge[edgeNum - 1].weight = arc[i][j];
			}
		}
	}

	//ʵ�֣��߼��������򣬿ɲ���ѡ������ --�ο��̲�Ver3  P268 SelectSort()
	for (i = 0; i < edgeNum - 1; i++)
	{
		int index=i;
		EdgeType temp;
		for (j = i+1; j < edgeNum - 1; j++)
		{
			if (Edge[j].weight < Edge[index].weight)
			{
				index = j;
			}
		}
		if (index != i)
		{
			temp = Edge[i];
			Edge[i] = Edge[index];
			Edge[index] = temp;
		}
	}




	//���μ���СȨ�ıߣ��ж��Ƿ���ֻ�����������������
	cout << "===========================" << endl;
	cout << "��С������ Kruskal �㷨" << endl;
	cout << "---------------------------" << endl;
	int parent[MaxSize];//���ڵ��±�����,��Ϊ-1��ʾ�Ӹ��ڵ�parent[i]������i���ڱߣ��ұ�ѡ�м�����С����������-1������ͨ
	for (i = 0; i < vertexNum; i++)
		parent[i] = -1;

	int num = 0;
	int vex1, vex2;

	//ʵ�֣��߼������м�鲢����n-1����
	for (i = 0; i < edgeNum; i++)
	{
		//�ҵ����ڵ㣬�ж��Ƿ���ֻ�
		vex1 = FindRoot(parent, Edge[i].from);
		vex2 = FindRoot(parent, Edge[i].to);
		//�޻������ߣ�����parent��Ϣ��һ��������һ�������ڵ�ҵ���һ����)
		if (vex1 != vex2)
		{
			cout << "(v" << Edge[i].from << ",v" << Edge[i].to << ")" << Edge[i].weight << endl;
			parent[Edge[i].to] = Edge[i].from;
			num++;
			if (num == vertexNum - 1)
			{
				break;
			}
		}
	}
	cout << "---------------------------" << endl;

}
