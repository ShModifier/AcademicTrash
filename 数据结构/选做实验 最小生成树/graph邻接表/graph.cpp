//graph.cpp
#include<iostream>
#include "graph.h"//����ͷ�ļ�

/*
 *ǰ��������ͼ������
 *��    �룺��
 *��    �ܣ�ͼ�ĳ�ʼ��
 *��    ������
 *�����������õ�һ������ͼ
 */
template <class T>
ALGraph<T>::ALGraph(T a[], int n, int e)
{
	arcNum = e;                             //����
	vertexNum = n;                            //������
	int i, j;
	for (i = 0; i < vertexNum; i++)
	{
		VertexNode<T> tempvertex;
		tempvertex.vertex = a[i];
		tempvertex.firstedge = NULL;
		adjlist[i] = tempvertex;
	}
	for (int k = 0; k < arcNum; k++)           //��������ÿһ���ߣ�������Ӧ�߱��в�����
	{
		cout << "���������������������������";
		cin >> i >> j;                         //�������������������������
		ArcNode* s = new ArcNode; s->adjvex = j;  //����һ���߱���s
		s->next = adjlist[i].firstedge;      //�����s���뵽���i�ı߱�ı�ͷ  
		adjlist[i].firstedge = s;
	}
	if (arcNum == 0)
	{
		InsertArc(0, 1);                   //�����,���ڵ���
		InsertArc(0, 2);
		InsertArc(0, 3);
		InsertArc(1, 3);
		InsertArc(1, 4);
		InsertArc(2, 0);
		InsertArc(2, 4);
		InsertArc(3, 1);
		InsertArc(3, 4);
		InsertArc(4, 2);
		InsertArc(4, 3);
	}
}

/*   ǰ��������ͼ�Ѵ���
 *   ��    �룺��
 *   ��    �ܣ�����ͼ
 *   ��    ������
 *   �����������ͷ�ͼ��ռ�õĴ洢�ռ�
 */
template <class T>
ALGraph<T>::~ALGraph()
{
	//ɾ���߱���
	for (int i = 0; i < vertexNum; i++)
	{
		ArcNode* p = adjlist[i].firstedge;
		while (p != NULL)                                              //ѭ��ɾ��
		{
			adjlist[i].firstedge = p->next;
			delete p;                                                 //�ͷŽ��ռ�
			p = adjlist[i].firstedge;
		}
	}
}

/*
 *ǰ��������ͼ�Ѵ���
 *��    �룺����i
 *��    �ܣ����ͼ�ж���i��������Ϣ
 *��    ����ͼ�ж���i��������Ϣ
 *����������ͼ���ֲ���
 */
template <class T>
T ALGraph<T>::GetVex(int i)
{
	if (i > vertexNum-1 || i < 0) throw string("���붥���λ�ò���ȷ"); //����i���������׳��쳣
	return adjlist[i].vertex;                               //���ص�i�������������  
}

/*
 *ǰ��������ͼ�Ѵ���
 *��    �룺����i
 *��    �ܣ���ͼ�ж���i����������Ϊvalue
 *��    ������
 *����������ͼ���ֲ���
 */
template <class T>
void ALGraph<T>::PutVex(int i, T value)
{
	if (i > vertexNum-1 || i < 0) throw string("���붥���λ�ò���ȷ"); //����i���������׳��쳣
	adjlist[i].vertex = value;                              //��i���������������Ϊvalue
}

/*
 *ǰ��������ͼ�Ѵ���
 *��    �룺����value,λ��i
 *��    �ܣ���ͼ��iλ�ò���һ������name
 *��    ����������벻�ɹ����׳��쳣
 *�����������������ɹ���ͼ��������һ������
 */
template <class T>
void ALGraph<T>::InsertVex(int i, T value)
{
	if (i > vertexNum || i<0 || i>MaxSize) throw string("���붥���λ�ò���ȷ"); //����i���������׳��쳣

	if (i < vertexNum) {
		// ��������ţ���Ŵ��ڵ���i�Ľ���ż�1
		ArcNode* s;
		int k;
		//����߱��ж�����
		for (k = 0; k < vertexNum; k++)              
			if (adjlist[k].firstedge != NULL)
			{
				s = adjlist[k].firstedge;
				while (s != NULL)
				{
					if (s->adjvex >= i)
						s->adjvex++;
					s = s->next;
				}
			}

		//����������㣬���i+1��n�Ķ����ڶ���������������
		for (k = vertexNum; k >= i + 1; k--)           
		{
			adjlist[k] = adjlist[k - 1];
		}
	}
	vertexNum++;   //��������1      

	//************************************
	VertexNode<T> tempvertex;
	tempvertex.vertex = value;
	tempvertex.firstedge = NULL;
	adjlist[i] = tempvertex;  	                    //��i���������������Ϊvalue	

}

/*
 *ǰ��������ͼ�Ѵ���
 *��    �룺����i
 *��    �ܣ���ͼ��ɾ������i
 *��    �������ɾ�����ɹ����׳��쳣
 *�������������ɾ���ɹ���ͼ�м�����һ������,��Ӧ�����������ı�Ҳ��ȥ
 */
template <class T>
void ALGraph<T>::DeleteVex(int i)              //ɾ����㼰��Ӧ�ı�
{
	//��Ч��ɾ������0~n-1
	if (i<0 || i>vertexNum - 1) throw string("λ���쳣");       //��������������׳��쳣
	int k;

	//--------------ɾ����ȱ�----------------------------       
	for (k = 0; k < vertexNum; k++) 
		if (k != i)	 DeleteArc(k, i);

	//--------------ɾ�����ȱߣ���������----------------------------                             
	if (adjlist[i].firstedge != NULL)
	{
		ArcNode* p = adjlist[i].firstedge;
		while (p != NULL)                                              //ѭ��ɾ��
		{
			adjlist[i].firstedge = p->next;
			delete p;                                                 //�ͷŽ��ռ�
			p = adjlist[i].firstedge;
		}
	}

	//-------//����������㣬���i��n-1�Ķ����ڶ�����������ǰ��-----------
	for (k = i; k < vertexNum - 1; k++)
	{
		adjlist[k] = adjlist[k + 1];
	}

	vertexNum--;                             //��������1

	//-------------------��������ţ���Ŵ���i�Ľ���ż�1-----------------------
	ArcNode* s;
	for (k = 0; k < vertexNum; k++) 
		if (adjlist[k].firstedge != NULL)
		{
			s = adjlist[k].firstedge;
			while (s != NULL)
			{
				if (s->adjvex > i)
					s->adjvex--;
				s = s->next;
			}
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
void ALGraph<T>::InsertArc(int i, int j)
{
	if (i > vertexNum - 1 || j > vertexNum - 1 || i<0 || j<0) throw string("λ���쳣");//��������������׳��쳣

	//����һ��i��j�ıߣ��������߱�ڵ㣬adjvex�ڽӵ��±�j������i���ı߱�
	ArcNode* s = new ArcNode; s->adjvex = j;      //����һ���߱���s
	//�����s���뵽���i�ı߱�ı�ͷ  (�ɸ�д ���뵽��β��
	s->next = adjlist[i].firstedge;    
	adjlist[i].firstedge = s;
}

/*
 *ǰ��������ͼ�Ѵ���
 *��    �룺����i��j
 *��    �ܣ���ͼ��ɾ������i��j �����ı�
 *��    �������ɾ�����ɹ����׳��쳣
 *�������������ɾ���ɹ���ͼ�м�����һ����
*/
template <class T>
void ALGraph<T>::DeleteArc(int i, int j)
{
	if (i > vertexNum-1 || j > vertexNum - 1 || i<0 || j<0) throw string("λ���쳣");  //��������������׳��쳣
	
	int flag = 0;//�Ƿ�ɾ�����Ǳ߱��һ����㣬1�ǵ�һ����㣬0�ǵ�һ��
	
	ArcNode* s;//ָ���ɾ�߱���
	ArcNode* pre;//ָ���ɾ�߱����ǰһ�����
	//s��preָ�򶥵�i�ı߱��һ�����
	s = adjlist[i].firstedge;
	pre = adjlist[i].firstedge;

	while (s != NULL && s->adjvex != j)
	{
		pre = s;
		s = s->next;
		flag = 1;
	}

	if (s != NULL)
	{
		if (flag == 0)
			adjlist[i].firstedge = s->next;  //ɾ����һ�����
		else
			pre->next = s->next;//������ɾ���
		delete s;
		cout << "ɾ���Ӷ���" << i << "������" << j << "�ı�" << endl;
	}
	else {
		cout << "�Ӷ���" << i << "������" << j << "û�бߣ��޷�ɾ��" << endl;
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
void ALGraph<T>::DFSTraverse(int v)
{
	if (v > vertexNum-1) throw string("λ���쳣");                          //��������������׳��쳣

	ArcNode* p;
	int j;
	cout << adjlist[v].vertex << " ";

	visited[v] = 1;
	
	p = adjlist[v].firstedge;//����v�߱�ĵ�һ�����

	while (p)                                                //������������v���ڽӵ�j
	{
		j = p->adjvex;
		if (visited[j] == 0) 
			DFSTraverse(j); //�ݹ�ʵ��������ȣ��Ӷ���v��ʼ��������ͨ�Ķ���
		p = p->next;
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
void ALGraph<T>::BFSTraverse(int v)
{
	if (v > vertexNum-1) throw string("λ���쳣");                           //��������������׳��쳣

	int front, rear, j;
	int Q[MaxSize];//�����Ŷ���
	front = rear = -1;       //��ʼ������, ������в���˳��洢�Ҳ��ᷢ�����

	ArcNode* p;                                              //����һ���߱���p

	cout << adjlist[v].vertex << " ";  
	visited[v] = 1; 
	Q[++rear] = v; //�����ʶ������

	while (front != rear) //���в���
	{
		v = Q[++front]; //��ǰ��ͷ�������

		//��������v���ڽӵ㣨�Ӷ���v������ͨ�Ķ��㣩
		p = adjlist[v].firstedge;           //�߱��еĹ���ָ��p��ʼ��
		while (p)
		{
			j = p->adjvex;
			if (visited[j] == 0) {
				cout << adjlist[j].vertex << " "; 
				visited[j] = 1; 
				Q[++rear] = j;//�ѷ��ʶ������
			}
			p = p->next;
		}
	}
	cout << endl;
}

template <class T>
int ALGraph<T>::GetVNum()
{
	return vertexNum;
}

//������б���Ϣ
template <class T>
void ALGraph<T>::PrintArc()
{
	int i;
	ArcNode* p;

	for (i = 0; i < vertexNum; i++)
	{
		cout << adjlist[i].vertex << " ";
		p = adjlist[i].firstedge;
		while (p)
		{
			cout << "-->";
			cout << "������" << p->adjvex;
			p = p->next;
		}
		cout << "^" << endl;
	}
}