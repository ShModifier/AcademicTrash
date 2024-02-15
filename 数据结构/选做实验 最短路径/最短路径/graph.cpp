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
		//�����,���ڵ���,�̲�ver2 P168(ͼ6-28)��ver3 �̲�P195(ͼ6-20)
		InsertArc(0, 1, 10);
		InsertArc(0, 2, 10);
		InsertArc(0, 3, 12);
		InsertArc(1, 3, 5);
		InsertArc(1, 6, 6);
		InsertArc(1, 2, 2);
		InsertArc(1, 4, 4);
		InsertArc(1, 5, 3);
		InsertArc(2, 3, 1);
		InsertArc(2, 5, 4);
		InsertArc(2, 6, 5);
		InsertArc(2, 4, 6);
		InsertArc(3, 4, 4);
		InsertArc(3, 5 ,3);
		InsertArc(4, 5, 2);
		InsertArc(4, 6, 7);
		InsertArc(5, 6, 2);





		//�����,���ڵ���,�̲�ver2  P185(ͼ6-51)
	   /* InsertArc(1,2,4);
		InsertArc(1,3,15);
		InsertArc(1,5,15);

		InsertArc(2,5,15);
		InsertArc(2,4,20);
		InsertArc(2,6,15);

		InsertArc(3,1,10);
		InsertArc(3,2,10);
		InsertArc(3,4,60);

		InsertArc(4,2,30);
		InsertArc(4,6,20);
		*/
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
void MGraph<T>::PutVex()           //ȡ���ж���            
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
	if (i > vertexNum - 1 || i < 0)
		throw string("λ���쳣");              //����i���������׳��쳣
	else
		cout << vertex[i]<< endl;                       //���ض���i	
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
	if (num<0 || num>vertexNum) throw string("����λ���쳣");       //���num���벻��ȷ�׳��쳣
	int row;                                        //��
	int col;                                        //��
	int numv = vertexNum-1;//���һ���������ڵ�λ��
	
	vertexNum++;                                   //��������1
	
	//��num~numv��������λ��ԭ���㵽���һ������������һλ
	for (int i = numv; i >= num; i--)
		vertex[i + 1] = vertex[i];

	vertex[num] = name;                            //��Ҫ����Ķ����ֵ����numλ����

	//���������飡������������������
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
void MGraph<T>::DeleteVex(int pos)              //ɾ����pos������
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

	if (v >= vertexNum) throw string("λ���쳣");   //������벻��ȷ�׳��쳣

	cout << vertex[v] << " ";
	visited[v] = 1;                    //�ѷ���v����	  
	for (int j = 0; j < vertexNum; j++)
	{
		if (arc[v][j] < 10000 && visited[j] == 0)//�����붥��v��ͨ�Ķ������ν��еݹ����
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
void MGraph<T>::PutArc()
{
	//�ǶԳƾ��󣬴�Ȩ����ͼ
	int row, col;
	for (row = 0; row < vertexNum; row++)
		for (col = 0; col < vertexNum; col++)
			if (arc[row][col] != 10000)
				cout << "��" << vertex[row] << "��" << vertex[col] << "��·������Ϊ��" << arc[row][col] << "\n";

}

//̰����˼��
template <class T>
void MGraph<T>::Dijkstra(int v) //����Դ
{
	int dist[MaxSize];//v�������������
	int i, k;
	int s[MaxSize];
	T path[MaxSize];//��ʵ��Ĭ�Ͻڵ������������ִ�

	for (i = 0; i < vertexNum; i++)
	{
		dist[i] = arc[v][i];

		if (dist[i] != 10000) 
			path[i] = vertex[v] + "->" + vertex[i];//��ʵ��Ĭ�Ͻڵ������������ִ�
		else  
			path[i] = "";
	}

	s[0] = v;
	dist[v] = 0;
	int num = 1;

	//�۲�dist����ı仯����������������������������������

	while (num < vertexNum)
	{
		//�ҵ���һ��dist��Ϊ0�Ķ���
		for (i = 0; i < vertexNum; i++)
			if (dist[i] != 0) { k = i;  break; }

		//�ҵ�dist��Ϊ0������dist��С���Ǹ�
		for (i = 0; i < vertexNum; i++)
			if (dist[i] != 0 && dist[i] < dist[k])    
				k = i;

		if (dist[k] != 10000)
			cout << path[k] << "(" << dist[k] << ")" << endl;

		s[num++] = k;//���˶�������ѷ�������

		//���¾���
		for (i = 0; i < vertexNum; i++)
			if (dist[i] > dist[k] + arc[k][i])
			{
				dist[i] = dist[k] + arc[k][i];
				path[i] = path[k] + "->" + vertex[i];
			}

		dist[k] = 0;//���˶������ѷ��ʣ������´ε����н���dist�Ƚ�
	} // for while
}


template <class T>
void MGraph<T>::Dijkstra2(int v, int vto) //��������·��
{
	int dist[MaxSize], i, k;
	int s[MaxSize];
	T path[MaxSize];

	for (i = 0; i < vertexNum; i++)
	{
		dist[i] = arc[v][i];
		if (dist[i] != 10000) path[i] = vertex[v] + "->" + vertex[i];
		else  path[i] = "";
	}

	s[0] = v;
	dist[v] = 0;
	int num = 1;

	while (num < vertexNum)
	{
		for (i = 0; i < vertexNum; i++)
			if (dist[i] != 0) 
			{ k = i;  break; }

		for (i = 0; i < vertexNum; i++)
			if (dist[i] != 0 && dist[i] < dist[k])    
				k = i;

		if (k == vto)
		{
			cout << path[k] << "(" << dist[k] << ")" << endl;
			return; //��ֹ����
		}

		s[num++] = k;

		for (i = 0; i < vertexNum; i++)
			if (dist[i] > dist[k] + arc[k][i])
			{
				dist[i] = dist[k] + arc[k][i];
				path[i] = path[k] + "->" + vertex[i];
			}
		dist[k] = 0;
	} // for while
}

//www.bilibili.com/video/BV1q4411M7r9/

//��̬�滮˼��
template <class T>
void MGraph<T>::Floyd()
{
	int dist[MaxSize][MaxSize], i, j, k;
	T path[MaxSize][MaxSize];

	//�����ڽӾ�����Ϣ����ʼ��dist�����path��ֱ���������֣�
	for (i = 0; i < vertexNum; i++)
		for (j = 0; j < vertexNum; j++)
		{
			dist[i][j] = arc[i][j];
			if (dist[i][j] != 10000)
				path[i][j] = vertex[i] + "->" + vertex[j];
			else path[i][j] = "";
		}

	for (k = 0; k < vertexNum; k++)
		for (i = 0; i < vertexNum; i++)
			for (j = 0; j < vertexNum; j++)
				if (dist[i][k] + dist[k][j] < dist[i][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = path[i][k] + "->" + path[k][j];
				}

	for (i = 0; i < vertexNum; i++)    //���   
		for (j = 0; j < vertexNum; j++)
			if (i != j && dist[i][j] != 10000)
				cout << path[i][j] << "(" << dist[i][j] << ")" << endl;


}