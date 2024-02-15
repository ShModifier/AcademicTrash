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
		//�����,���ڵ��� �̲�ver3 P202 ͼ6-27
		//B
		InsertArc(1, 0);
		InsertArc(1, 3);
		//C
		InsertArc(2, 0);
		InsertArc(2, 3);
		//D
		InsertArc(3, 0);
		InsertArc(3, 5);
		//E
		InsertArc(4, 2);
		InsertArc(4, 3);
		InsertArc(4, 5);

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
	if (i > vertexNum || i < 0) throw string("���붥���λ�ò���ȷ"); //����i���������׳��쳣
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
	if (i > vertexNum || i < 0) throw string("���붥���λ�ò���ȷ"); //����i���������׳��쳣
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
	if (i > vertexNum || i < 0) throw string("���붥���λ�ò���ȷ"); //����i���������׳��쳣

	ArcNode* s;
	int k;
	for (k = 0; k < vertexNum; k++)               // ��������ţ���Ŵ��ڵ���i�Ľ���ż�1
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

	for (k = vertexNum; k >= i + 1; k--)           //�����������
	{
		adjlist[k] = adjlist[k - 1];
	}
	vertexNum++;   //��������1                           

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
	if (i < 0 || i >= vertexNum) throw string("λ���쳣");       //��������������׳��쳣
	int k;

	for (k = 0; k < vertexNum; k++)               //ɾ����ȱ�
		if (k != i)	 DeleteArc(k, i);


	if (adjlist[i].firstedge != NULL)          //ɾ�����ȱ�
	{

		ArcNode* p = adjlist[i].firstedge;
		while (p != NULL)                                              //ѭ��ɾ��
		{
			adjlist[i].firstedge = p->next;
			delete p;                                                 //�ͷŽ��ռ�
			p = adjlist[i].firstedge;
		}
	}

	for (k = i; k < vertexNum - 1; k++)           //�����������
	{
		adjlist[k] = adjlist[k + 1];
	}

	vertexNum--;                             //��������1
	//--------------------------------------------------------------------------
	ArcNode* s;
	for (k = 0; k < vertexNum; k++)               // ��������ţ���Ŵ���i�Ľ���ż�1
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
	if (i > vertexNum - 1 || j > vertexNum - 1 || i < 0 || j < 0) throw string("λ���쳣");//��������������׳��쳣
	ArcNode* s = new ArcNode; s->adjvex = j;      //����һ���߱���s
	s->next = adjlist[i].firstedge;             //�����s���뵽���i�ı߱�ı�ͷ  
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
	if (i > vertexNum - 1 || j > vertexNum - 1 || i < 0 || j < 0) throw string("λ���쳣");  //��������������׳��쳣
	ArcNode* s;
	int flag = 0;
	ArcNode* pre;
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
			adjlist[i].firstedge = s->next;
		else
			pre->next = s->next;
		delete s;
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
	if (v >= vertexNum) throw string("λ���쳣");                          //��������������׳��쳣
	ArcNode* p;
	int j;
	cout << adjlist[v].vertex << " ";
	visited[v] = 1;
	p = adjlist[v].firstedge;
	while (p)                                                //������������v���ڽӵ�j
	{
		j = p->adjvex;
		if (visited[j] == 0) DFSTraverse(j);
		p = p->next;
	}

}


 //������ȶ����ȱ������ж������Ƿ����ͨ·, 1:���ڣ�0:������
template <class T>
void ALGraph<T>::DFSTconJudge(int vi, int vj)  
{
	if (MyFlag > 0)// MyFlag ȫ�ֱ��� ��ǣ�1��ʾ����ͨ·������Ϊ0
		return;  
	if (vi >= vertexNum || vj >= vertexNum || vi <0 || vj<0) throw string("λ���쳣");                          //��������������׳��쳣
	
	ArcNode* p;
	int j;
	cout << adjlist[vi].vertex << " ";
	visited[vi] = 1;

	p = adjlist[vi].firstedge;
	while (p)    //������������v���ڽӵ�j
	{
		j = p->adjvex;
		if (j == vj)
		{
			cout << adjlist[j].vertex << " ";   MyFlag = 1; return;
		}

		if (visited[j] == 0) DFSTconJudge(j, vj);

		p = p->next;
	}
}

template <class T>
void ALGraph<T>::BFSTraverse(int v)
{
	if (v >= vertexNum || v<0) throw string("λ���쳣");   //��������������׳��쳣

	int front, rear, j;
	ArcNode* p;                                              //����һ���߱���p
	
	int Q[MaxSize];
	front = rear = -1;    //��ʼ������, ������в���˳��洢�Ҳ��ᷢ�����
	cout << adjlist[v].vertex << " ";  visited[v] = 1; Q[++rear] = v; //�����ʶ������
	
	while (front != rear)
	{
		v = Q[++front];
		p = adjlist[v].firstedge;                                //�߱��еĹ���ָ��p��ʼ��
		while (p)
		{
			j = p->adjvex;
			if (visited[j] == 0)
			{
				cout << adjlist[j].vertex << " "; visited[j] = 1; Q[++rear] = j;
			}
			p = p->next;
		}
	}
	cout << endl;
}

//���ڹ�����ȱ������ж������Ƿ����ͨ·, 1:���ڣ�0:������
template <class T>
int ALGraph<T>::BFSTconJudge(int vi, int vj)         
{
	if (vi >= vertexNum || vj >= vertexNum || vi < 0 || vj < 0) throw string("λ���쳣");

	int front, rear, j;
	ArcNode* p;             //����һ���߱���p
	int Q[MaxSize];
	front = rear = -1;       //��ʼ������, ������в���˳��洢�Ҳ��ᷢ�����
	
	cout << adjlist[vi].vertex << " ";  visited[vi] = 1; Q[++rear] = vi; //�����ʶ������
	
	while (front != rear)
	{
		vi = Q[++front];
		p = adjlist[vi].firstedge;                                //�߱��еĹ���ָ��p��ʼ��
		while (p)
		{//����δ�����ڽӵ㣬���ʣ��������
			j = p->adjvex;
			if (visited[j] == 0)
			{
				cout << adjlist[j].vertex << " "; visited[j] = 1; Q[++rear] = j;
			}

			if (j == vj) return 1;//������ȱ��������ڽӵ��з���vj��˵������ͨ·
			
			p = p->next;
		}
	}
	cout << endl;
	return 0;
}


//��������
template <class T>
void ALGraph<T>::TopSort()
{
	ArcNode* p;
	int i, j, k;

	//==================���㶥����е������=====================
	for (i = 0; i < vertexNum; i++)
		adjlist[i].in = 0;
	for (i = 0; i < vertexNum; i++)   //ɨ�趥���
	{
		p = adjlist[i].firstedge;
		while (p != NULL)            //ɨ�趥��i �ı߱�,�������
		{
			k = p->adjvex;
			adjlist[k].in++;	//�Ӷ���i���������Ķ�����ȼ�1
			p = p->next;
		}

	}

	cout << "===========================" << endl;
	cout << "--------��������-----------" << endl;
	
	int S[100];//����ջ
	int top = -1;
	int count = 0;//���������������� = �������������л�·
	
	for (i = 0; i < vertexNum; i++)
		if (adjlist[i].in == 0)//û����ߵĶ��㣬ѹջ
		{
			top++;
			S[top] = i;
		}

	while (top != -1)
	{
		j = S[top];
		top--;//ջ��Ԫ�س�ջ��������������
		cout << adjlist[j].vertex << ", ";
		count++;

		p = adjlist[j].firstedge;
		while (p != NULL)            //ɨ�趥��j �ı߱�,�������
		{
			k = p->adjvex;
			adjlist[k].in--; //��ջ�Ķ��������ߵ����-1

			if (adjlist[k].in == 0)//�����ȣ�����kû�������ѹջ
			{
				top++;
				S[top] = k;
			}
			p = p->next;
		}
	}
	
	cout << endl;
	if (count < vertexNum)//���������껹ʣ�ඥ�㣨�޷����������������У�������ڻ�
		cout << " �л�·!!!" << endl;
	cout << "------------------------" << endl;
}