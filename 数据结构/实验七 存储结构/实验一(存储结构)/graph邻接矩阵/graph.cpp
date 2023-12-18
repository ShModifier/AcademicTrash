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
	cout << "������Ϣ���£�" << endl;
	for (i = 0; i < vertexNum; i++)
	{
		vertex[i] = a[i]; //��������
		cout << a[i] << " ";
	}
	cout << endl;
	for (i = 0; i < vertexNum; i++)    //��ʼ���ڽӾ���
		for (j = 0; j < vertexNum; j++)
			arc[i][j] = 10000; //����䲻��ͨ

	int Weight;
	for (k = 0; k < arcNum; k++)   //��������ÿһ���ߣ����޸��ڽӾ������ӦԪ��
	{
		cout << "�����뻡ͷ����β��Ȩ�أ��ÿո�ֿ�" << endl;
		cin >> i >> j >> Weight;                    //��������������������
		arc[i][j] = Weight;                  //���б߱�־
	}

	if (arcNum == 0)
	{
		InsertArc(0, 1, 5);                   //�����,���ڵ���
		InsertArc(0, 2, 6);
		InsertArc(0, 3, 7);
		InsertArc(1, 3, 8);
		InsertArc(1, 4, 9);
		InsertArc(2, 0, 2);
		InsertArc(2, 4, 1);
		InsertArc(3, 1, 8);
		InsertArc(3, 4, 5);
		InsertArc(4, 2, 3);
		InsertArc(4, 3, 3);
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
void MGraph<T>::PrintVex()
{
	int i = 0;
	for (i = 0; i < vertexNum; i++)
	{
		cout << vertex[i] << "  ";
	}
	cout << endl;
}

/*
 *ǰ��������ͼ�Ѵ���
 *��    �룺����i
 *��    �ܣ���ͼ�ж���i����������Ϊvalue
 *��    ������
 *����������ͼ���ֲ���
 */
template <class T>
void MGraph<T>::PutVex(int i, T value)           //ȡ���ж���            
{                                   //����Դ���ǵ�0�����㣬�����������0
	if (i > vertexNum - 1 || i < 0) throw string("λ���쳣");              //����i���������׳��쳣
	vertex[i] = value;
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
void MGraph<T>::InsertVex(int num, T name)        //��ͼ�в���һ�����㣬����Ϊnum��ֵΪname
{                                                //����Դ���ǵ�0�����㣬�����������0
	if (num<0 || num>vertexNum) throw string("����λ���쳣");       //���num���벻��ȷ�׳��쳣
	int row;                                        //��
	int col;                                        //��
	int numv = vertexNum - 1;                          //���һ���������ڵ�λ��

	vertexNum++;                                   //��������1

	//��num~numv��������λ��ԭ���㵽���һ������������һλ
	for (int i = numv; i >= num; i--)
		vertex[i + 1] = vertex[i];

	vertex[num] = name;                            //��Ҫ����Ķ����ֵ����numλ����

	//����������
	for (row = numv; row >= 0; row--)                      //�Ѵ�num�е����һ�е�Ԫ�ؾ�������һ��
	{
		for (col = numv; col >= num; col--)
			arc[row][col + 1] = arc[row][col];
		arc[row][num] = 10000;						//��numλ�����ڵ���ֵ����Ϊ�����
	}

	for (row = numv; row >= num; row--)                   //�Ѵ�num�е����һ�е�Ԫ�ؾ�������һ��
		for (col = 0; col <= numv + 1; col++)
			arc[row + 1][col] = arc[row][col];

	for (col = 0; col < vertexNum; col++)
		arc[num][col] = 10000;                   //��numλ�����ڵ�������ֵ����Ϊ�����
}

/*
 *ǰ��������ͼ�Ѵ���
 *��    �룺����pos
 *��    �ܣ���ͼ��ɾ������pos
 *��    �������ɾ�����ɹ����׳��쳣
 *�������������ɾ���ɹ���ͼ�м�����һ������,��Ӧ�����������ı�Ҳ��ȥ
 */
template <class T>
void MGraph<T>::DeleteVex(int pos)              //ɾ����pos�����㣨posΪ�����ţ�
{                                               
	//����Դ���ǵ�0�����㣬�����������0
	if (pos<0 || pos>vertexNum - 1) throw string("λ���쳣");       //���pos���벻��ȷ�׳��쳣
	int row;                                       //��
	int col;                                       //��
	int numv = vertexNum;                            //numv���ڶ�����

	//pos���� 
	for (int i = pos; i < numv - 1; i++)
		vertex[i] = vertex[i + 1];                       //�Ѵ�pos������ÿ�����λ��������ǰ��һλ

	vertexNum--;                                 //��������1

	for (row = 0; row < numv; row++)
	{
		for (col = pos; col < numv; col++)
			arc[row][col] = arc[row][col + 1];        //�Ѵ�pos�е����һ�е�Ԫ�ؾ�������һ��
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
	if (i > vertexNum - 1 || j > vertexNum - 1 || i < 0 || j < 0) throw string("λ���쳣");    //������벻��ȷ�׳��쳣
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
	if (i > vertexNum-1 || j > vertexNum - 1 || i<0 || j<0) throw string("λ���쳣");   //������벻��ȷ�׳��쳣	
	
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
	if (v >= vertexNum) throw string("λ���쳣");   //������벻��ȷ�׳��쳣
	
	cout << vertex[v] << " ";
	visited[v] = 1;                    //�ѷ���v����	  
	for (int j = 0; j < vertexNum; j++)
	{
		if (arc[v][j] < 10000 && visited[j] == 0)//�����붥��v��ͨ�Ķ������ν��еݹ����
			DFSTraverse(j);
	}
}

template <class T>
void MGraph<T>::FDG_DFSTraverse(int v)     //������ȱ���ͼ,�ǵݹ��㷨
{
	int s[100]; //ʹ��ջʵ�ַǵݹ�������ȱ���
	int top = -1;
	int k;//��ǰջ��Ԫ��
	int flag;

	cout << "----������ȱ���ͼ,�ǵݹ��㷨----" << endl;
	if (v >= vertexNum) throw string("λ���쳣");   //������벻��ȷ�׳��쳣

	top++;  //��ʼ���ջ������
	s[top] = v;
	cout << vertex[v] << " ";
	visited[v] = 1;
	int j;

	while (top != -1)//ջ����
	{
		flag = 1;
		while (flag)
		{
			k = s[top];  //��ջ���ڵ�,ע��û��ջ
			for (j = 0; j < vertexNum; j++)  //Ѱ�Ҷ��ڵ���һ��δ���ʵ��ڽ��
			{
				if (arc[k][j] < 10000 && visited[j] == 0)
				{
					s[++top] = j;            //��ջ������
					cout << vertex[j] << " ";
					visited[j] = 1;
					break; //������ȣ�������ǰ����k���ڽӱߣ����´�ջ��ȡ����
				}
			}

			//�ڵ�k������δ���ʵ��ڽ��ʱ��ջ��Ԫ�س�ջ
			if (j == vertexNum)
			{
				top--;
				flag = 0;
			}
		}

	}
	cout << endl;
	cout << "----------------------------" << endl;
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
	
	while (front != rear)//���в���
	{
		v = Q[++front];                     //����ͷԪ�س��ӣ�v���ͷԪ��
		for (int j = 0; j < vertexNum; j++)
			//������ȱ�������ǰ����v�������ڽӵ㣨���д�v�����ɵ���Ķ��㣩
			if (arc[v][j] < 10000 && visited2[j] == 0) {
				cout << vertex[j] << " ";
				visited2[j] = 1;
				Q[++rear] = j; //�����ʶ������
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
				cout << "��" << vertex[row] << "��" << vertex[col] << "��·������Ϊ��" << arc[row][col] << "\n";
}
