//LinkQueue.cpp
#include "LinkQueue.h"

/*
 * ǰ�����������в�����
 * ��    �룺��
 * ��    �ܣ���ʼ������
 * ��    ������
 * ��������������һ���ն���
 */

template <class T>
LinkQueue<T>::LinkQueue( )
{
	Node <T> *s;
	s=new Node<T>;
	s->next=NULL;
	front=rear=s;
}

/*
 * ǰ�����������д���
 * ��    �룺��
 * ��    �ܣ����ٶ���
 * ��    ������
 * �����������ͷŶ�����ռ�õĴ洢�ռ�
 */

template <class T>
LinkQueue<T>::~LinkQueue( )
{
	while(front)
	{
		Node <T> *p;
		p=front->next;
        delete front;
	    front=p;
	}
}

/*
 * ǰ�������������Ѵ���
 * ��    �룺Ԫ��ֵs
 * ��    �ܣ��ڶ�β����һ��Ԫ��
 * ��    ������
 * �����������������ɹ�����β������һ��Ԫ��
 */

template <class T> 
void LinkQueue<T>::EnQueue(T x)
{
	Node<T> *s;
    s=new Node<T>; 
    s->data=x;          //����һ��������Ϊx�Ľ��s
    s->next=NULL;
    rear->next=s;       //�����s���뵽��β
    rear=s;
}

/*
 * ǰ�������������Ѵ���
 * ��    �룺��
 * ��    �ܣ�ɾ����ͷԪ��
 * ��    �������ɾ���ɹ������ر�ɾԪ��ֵ�������׳�ɾ���쳣
 * �������������ɾ���ɹ�����ͷ������һ��Ԫ��
 */

template <class T>
T LinkQueue<T>::DeQueue()
{    
	Node <T> *p; int x;
    if (rear==front) throw "����";
    p=front->next; 
	x=p->data;                       //�ݴ��ͷԪ��
    front->next=p->next;             //����ͷԪ�����ڽ��ժ��
    if (p->next==NULL) rear=front;   //�жϳ���ǰ���г����Ƿ�Ϊ1
    delete p;
    return x;
}

/*
 * ǰ�������������Ѵ���
 * ��    �룺��
 * ��    �ܣ���ȡ��ͷԪ��
 * ��    ���������в��գ����ض�ͷԪ��
 * �������������в���
 */

template <class T> 
T LinkQueue<T>::GetQueue()
{
    if (front!=rear) 
		return front->next->data;
}

/*
 * ǰ�������������Ѵ���
 * ��    �룺��
 * ��    �ܣ��ж϶����Ƿ�Ϊ��
 * ��    �����������Ϊ�գ�����1�����򣬷���0
 * �������������в���
 */

template <class T> 
bool LinkQueue<T>::Empty( )
{
    if(front==rear) 
		return 1;
    else 
		return 0;
}