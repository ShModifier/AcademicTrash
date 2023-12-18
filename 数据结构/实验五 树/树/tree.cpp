//�������еĳ�Ա�������ļ���Ϊtree.cpp
#include<iostream>
#include<string>
#include"tree.h"
using namespace std;
/*
 *ǰ����������������
 *��    �룺��
 *��    �ܣ�����һ����
 *��    ������
 *��������������һ���� 
 */

template<class T>
Tree<T>::Tree( )
{
	const int MaxSize = 100;
    int end = 0;
	int front = 0;//����ͷ
	int frontTemp=0;
	int rear  = 0;  //����β������˳����У����ٶ����ᷢ������
	int j = 0;	
	TNode<T>* queue[MaxSize]; //����һ������ 
	TNode<T>* tempNode;              //����ָ�������͵�ָ��  
	TNode<T>* brotherNode;   //����ָ��

	T ch;
    cout<<"�����봴��һ�����ĸ��������"<<endl;
	cin>>ch;
    root = new TNode<T>;
	root->data = ch;
	root->firstchild = NULL;
	root->rightsib = NULL;
    queue[rear++] = root;  

    while (!end)    //������������ - TODO �ж������쳣�����endֻ��0��1
	{ 
		T ch1,ch2;
		cout<<"�����븸������ݺͺ��ӽ�����ݶ�:"<<endl;
		cin>>ch1>>ch2;//ch1 ���ڵ����ݣ�ch2 �ӽڵ�����
		
		//�ҵ�����ĸ��ڵ�
		//tempNode = queue[front];//ͷ�����ӣ�ͬʱ��ͷԪ�صı�ʶ������ 
		frontTemp=front;
		tempNode = queue[frontTemp++];//ȡ��ͷ��㣬���ǳ���
		//��������������ݺ�ch1ƥ��Ľڵ�
		while((ch1 != tempNode->data) && (frontTemp<rear) ) 		
		{	//tempNode = queue[front++];
		    tempNode = queue[frontTemp++];
		}
        
		if (ch1 != tempNode->data) // ɨ����У�û�ҵ����׽ڵ�
		{
            cout<<"��ǰ����������Ϊ"<<ch1<<"�ĸ��׽ڵ㡣��������ڵ�ԣ���"<<endl;
			continue;
		}
		else {
			TNode<T>* p = new TNode<T>;       //����һ����㣨�ӽڵ㣩
			p->data = ch2;
			p->firstchild = NULL;
			p->rightsib = NULL;

			queue[rear++] = p;

			//---------���´��뽨�����ӹ�ϵ------------------
			if (tempNode->firstchild == NULL)
				tempNode->firstchild = p;//���ڵ����ӽڵ㣬��ǰ�ڵ��Ϊ��һ������
			else {
				brotherNode = tempNode->firstchild;  //����ָ��ָ����ĵ�һ������
				while (brotherNode->rightsib != NULL)          //����һ���������ֵܽ��
				{
					brotherNode = brotherNode->rightsib;//����ָ��ָ���һ�����ӵ����ֵ�
				}
				brotherNode->rightsib = p;
			}
			cout << "��������? ��������밴1�����밴0 " << endl;
			cin >> end;
		}
	}
}

/*
 *ǰ�����������Ѵ���
 *��    �룺��
 *��    �ܣ��ͷ����и����Ĵ洢�ռ�
 *��    ������
 *������������������ 
 */
template<class T>
Tree<T>::~Tree(void)
{
	Release(root);
}

/*
 *ǰ�����������Ѵ���
 *��    �룺��
 *��    �ܣ���ȡָ����������ָ��
 *��    ����ָ����������ָ��
 *���������������� 
 */
template<class T>
TNode<T>* Tree<T>::Getroot( )
{
	return root;
}

/*
 *ǰ�����������Ѵ���
 *��    �룺��
 *��    �ܣ�ǰ�������
 *��    �������н���һ����������
 *���������������� 
 */
template<class T>
void Tree<T>::PreOrder(TNode<T> *root)      //ǰ�������
{
	if (root == NULL)  return;     //�ݹ���õĽ�������
	else{
		cout<<root->data;          //��ӡ���ڵ�

		TNode<T>* p = root->firstchild;//����ָ��ָ����ڵ��һ������
		while (p != NULL)
		{
			PreOrder(p);    //���η��ʺ��ӣ�ǰ��ݹ����root�ĺ��ӽڵ�
			p = p->rightsib;
		}
	}
}
/*
 *ǰ�����������Ѵ���
 *��    �룺��
 *��    �ܣ����������
 *��    �������н���һ����������
 *���������������� 
 */
template<class T>
void Tree<T>::PostOrder(TNode<T> *root)
{ 
	if (root == NULL)  return;     //�ݹ���õĽ�������
	else{
		TNode<T>* p = root->firstchild;//����ָ��ָ����ڵ��һ������
		while (p != NULL)
		{
			PostOrder(p);    //���η��ʺ��ӣ�����ݹ����root�ĺ��ӽڵ�
			p = p->rightsib;
		}    
		cout << root->data;               //��ӡ��root���   
	}
} 

/*
 *ǰ�����������Ѵ���
 *��    �룺��
 *��    �ܣ����������
 *��    �������н���һ����������
 *����������������
 */
template<class T>
void Tree<T>::LevelOrder(TNode<T> *root)   
{		
	const int MAX_QUEUE_SIZE = 100;
	int front = 0;
	int rear  = 0;  //����˳����У����ٶ����ᷢ������		
	TNode<T>* queue[MAX_QUEUE_SIZE]; //����һ������ 
	TNode<T>* tempNode;      //����ָ�������͵�ָ��  
	TNode<T>* brotherNode;   //����ָ��

	if (root == NULL) return;//ѭ����������
	queue[rear++] = root;    //���������
	while (front != rear)    //���������н��
	{
		tempNode = queue[front++];//ͷ�����ӣ�ͬʱ��ͷԪ�صı�ʶ������
		cout<<tempNode->data;     //��ӡ��ͷ���    
		//ÿһ�η����굱ǰ�ڵ㣬����һ��������ӽڵ�������ӣ������нڵ�������ҡ����ϵ�������
		brotherNode = tempNode->firstchild;  //����ָ��ָ����ĵ�һ������
		while (brotherNode != NULL)          //����һ���������ֵܽ��
		{
			queue[rear++] = brotherNode;     //��һ�����ӽ�����
			brotherNode = brotherNode->rightsib;//����ָ��ָ���һ�����ӵ����ֵ�
		}
	}
}

/*
 *ǰ�����������Ѿ�����
 *��    �룺��
 *��    �ܣ��ͷ����Ĵ洢�ռ䣬������������
 *��    ������
 *������������������
 */
template <class T>
void Tree<T>::Release(TNode<T>* root)
{
	if (root != NULL){ 	
		Release (root->firstchild);   //�ͷŵ�һ������
		Release (root->rightsib);   //�ͷ����ֵ�
        delete root;
	}
}
