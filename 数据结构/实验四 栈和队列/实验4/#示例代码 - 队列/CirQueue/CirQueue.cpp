//CirQueue.cpp
#include "CirQueue.h"

/*
 * ǰ�����������в�����
 * ��    �룺��
 * ��    �ܣ���ʼ������
 * ��    ������
 * ��������������һ���ն���
 */

template <class T>
CirQueue<T>::CirQueue( ) 
{
	front=rear=0;
} 

/*
 * ǰ�������������Ѵ���
 * ��    �룺��
 * ��    �ܣ����ٶ���
 * ��    ������
 * �����������ͷŶ�����ռ�õĴ洢�ռ�
 */

template <class T>
CirQueue<T>::~CirQueue( )
{

}

/*
 * ǰ�������������Ѵ���
 * ��    �룺Ԫ��ֵx
 * ��    �ܣ��ڶ�β����һ��Ԫ��
 * ��    ����������벻�ɹ����׳��쳣
 * �����������������ɹ�����β������һ��Ԫ��
 */

template <class T> 
void CirQueue<T>::EnQueue(T x)
{
    if ((rear+1) % QueueSize ==front) throw "����";
    rear=(rear+1) % QueueSize;   //��βָ����ѭ�������¼�1
    data[rear]=x;                //�ڶ�β������Ԫ��
}

/*
 * ǰ�������������Ѵ���
 * ��    �룺��
 * ��    �ܣ�ɾ����ͷԪ��
 * ��    �������ɾ���ɹ������ر�ɾԪ��ֵ�������׳�ɾ���쳣
 * �������������ɾ���ɹ�����ͷ������һ��Ԫ��
 */

template <class T> 
T CirQueue<T>::DeQueue( )
{
    if (rear==front) throw "����"; 
    front=(front+1) % QueueSize;    //��ͷָ����ѭ�������¼�1
    return data[front];             //��ȡ�����س���ǰ�Ķ�ͷԪ�أ�ע���ͷָ��
}
                                   //ָ���ͷԪ�ص�ǰһ��λ��
/*
 * ǰ�������������Ѵ���
 * ��    �룺��
 * ��    �ܣ���ȡ��ͷԪ��
 * ��    ���������в��գ����ض�ͷԪ��
 * �������������в���
 */

template <class T>
T CirQueue<T>::GetQueue( )
{   
    int i;
    if (rear==front) throw "����"; 
    i=(front+1) % QueueSize;  //ע�ⲻҪ����ͷָ�븳ֵ
    return data[i];
}

/*
 * ǰ�������������Ѵ���
 * ��    �룺��
 * ��    �ܣ��ж϶����Ƿ�Ϊ��
 * ��    �����������Ϊ�գ�����1�����򣬷���0
 * �������������в���
 */

template <class T> 
bool CirQueue<T>::Empty( ) 
{
    if (front==rear) 
		return 1; 
	else 
		return 0;
}