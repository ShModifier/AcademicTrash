//�������еĳ�Ա�������ļ���Ϊbitree.cpp
#include<iostream>
#include<string>
#include"bitree.h"
using namespace std;

/*
 *ǰ��������������������
 *��    �룺��
 *��    �ܣ�����һ�ö�����
 *��    ������
 *��������������һ�ö����� 
 */
template<class T>
BiTree<T>::BiTree( int flag)
{   if (flag>0)
    	this->root = Creat( ); //��������
    else
	    this->root = Creat1( );	 //�Զ�
}

/*
 *ǰ���������������Ѵ���
 *��    �룺��
 *��    �ܣ��ͷŶ��������и����Ĵ洢�ռ�
 *��    ������
 *���������������������� 
 */
template<class T>
BiTree<T>::~BiTree(void)
{
	Release(root);
}

/*
 *ǰ���������������Ѵ���
 *��    �룺��
 *��    �ܣ���ȡָ�������������ָ��
 *��    ����ָ�������������ָ��
 *�������������������� 
 */
template<class T>
BiNode<T>* BiTree<T>::Getroot( )
{
	return root;
}

/*
 *ǰ���������������Ѵ���
 *��    �룺��
 *��    �ܣ�ǰ�����������
 *��    �����������н���һ����������
 *�������������������� 
 */
template<class T>
void BiTree<T>::PreOrder(BiNode<T> *root)
{
	if(root==NULL)  return;
	else{		
		cout<<root->data<<" ";
        PreOrder(root->lchild);
		PreOrder(root->rchild);
	}
}

/*
 *ǰ���������������Ѵ���
 *��    �룺��
 *��    �ܣ��������������
 *��    �����������н���һ����������
 *�������������������� 
 */
template <class T>
void BiTree<T>::InOrder (BiNode<T> *root)
{
    if (root==NULL)  return;      //�ݹ���õĽ�������	          
    else{	
        InOrder(root->lchild);    //����ݹ����root��������
        cout<<root->data<<" ";    //���ʸ�����������
        InOrder(root->rchild);    //����ݹ����root��������
	}
}

/*
 *ǰ���������������Ѵ���
 *��    �룺��
 *��    �ܣ��������������
 *��    �����������н���һ����������
 *�������������������� 
 */
template <class T>
void BiTree<T>::PostOrder(BiNode<T> *root)
{ 
    if (root==NULL)   return;       //�ݹ���õĽ�������
    else{	
        PostOrder(root->lchild);    //����ݹ����root��������
        PostOrder(root->rchild);    //����ݹ����root��������
        cout<<root->data<<" ";      //���ʸ�����������
	}
}

/*
 *ǰ���������������Ѵ���
 *��    �룺��
 *��    �ܣ��������������
 *��    �����������н���һ����������
 *��������������������
 */
template <class T>
void BiTree<T>::LevelOrder(BiNode<T> *root)
{
	const int MaxSize = 100;

	int front = 0;
	int rear = 0;  //����˳����У����ٶ����ᷢ������

	BiNode<T>* Q[MaxSize];
    BiNode<T>* q;

	if (root==NULL) return;
	else{
		Q[rear++] = root;
		while (front != rear)
		{
			q = Q[front++];
     		cout<<q->data<<" "; 		
    		if (q->lchild != NULL)    Q[rear++] = q->lchild;		
			if (q->rchild != NULL)    Q[rear++] = q->rchild;
		}
	}
}


/*
 *ǰ���������ն�����
 *��    �룺����ch;
 *��    �ܣ���ʼ��һ�ö�����,���캯������
 *��    ������
 *��������������һ�ö�����
 */
template <class T>
BiNode<T>* BiTree<T>::Creat( )
{
	BiNode<T>* bt;
	T ch;
	cout<<"�����봴��һ�ö������Ľ������"<<endl;
	cin>>ch;
    if (ch=="#") bt = NULL;
    else{ 
	     bt = new BiNode<T>;       //����һ�����
         bt->data=ch;
         bt->lchild = Creat( );    //�ݹ齨��������
         bt->rchild = Creat( );    //�ݹ齨��������
    } 
    return bt;
}

//-------------�Զ�����--------------------------------
template <class T>
BiNode<T>* BiTree<T>::Creat1( )
{
	BiNode<T>* bt;
	T ch;

	ch=PreOrderString[chCnt]; //PreOrderString ȫ�ֱ���
	chCnt++;

    if (ch=="#") bt = NULL;
    else{ 
	     bt = new BiNode<T>;       //����һ�����
         bt->data=ch;
         bt->lchild = Creat1( );    //�ݹ齨��������
         bt->rchild = Creat1( );    //�ݹ齨��������
    } 
    return bt;
}


/*
 *ǰ���������������Ѿ�����
 *��    �룺��
 *��    �ܣ��ͷŶ������Ĵ洢�ռ䣬������������
 *��    ������
 *����������������������
 */
template<class T>
void BiTree<T>::Release(BiNode<T>* root)
{
  if (root != NULL){                  
	  Release(root->lchild);   //�ͷ�������
      Release(root->rchild);   //�ͷ�������
      delete root;
  }  
}

template<class T>
void BiTree<T>::CountNode(BiNode<T>* root)
{
	if (root == NULL) return;
	else
	{
		Count++;  //����ȫ�־�̬��������ʼ��Ϊ0
		CountNode(root->lchild);
		CountNode(root->rchild);
	}
}

template<class T>
void BiTree<T>::PrintLeafNode(BiNode<T>* root)
{
	if (root == NULL) return;
	else
	{
		if (root->lchild == NULL && root->rchild == NULL)
		{
			cout <<root->data<<" ";
		}
		PrintLeafNode(root->lchild);
		PrintLeafNode(root->rchild);
	}
}

template<class T>
int BiTree<T>::DepthTree(BiNode<T>* root)
{
	if (root == NULL) return 0;
	else
	{
		DeepL = DepthTree(root->lchild);
		DeepR = DepthTree(root->rchild);
		return max(DeepL, DeepR) + 1;
	}
}

