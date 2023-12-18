//CirQueue.cpp
#include <string>
using namespace std;
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
    //=========ѧ����ɣ��޸ĳ�ʼ�������������һ���ռ䣩����ʼ�� flag================
	front=rear=0;
    flag = false; // ��ʼ��flagΪfalse
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
    //=========ѧ����ɣ��ĳ�flagʵ�֣��ж϶���=================
    //if ((rear+1) % QueueSize ==front) throw string("�����쳣");
    if (flag)
    {
        throw string("�����쳣");
    }
    else
    {
        rear = (rear + 1) % QueueSize;   //��βָ����ѭ�������¼�1
        data[rear] = x;                //�ڶ�β������Ԫ��
        if (rear == front) 
        {
            flag = true;    // ����flagΪtrue����ʾ��������
        }
    }
   

    //=========ѧ����ɣ�����Ƿ�Ҫ��flag����ô��===============

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
    //=========ѧ����ɣ��ĳ�flagʵ�֣��ж϶ӿ�==================
    if (rear == front)
    {
        throw string("�ӿ��쳣");
    }
    else 
    {
        front = (front + 1) % QueueSize;    //��ͷָ����ѭ�������¼�1
        if (flag)
        {
            flag = false;   // ���з���״̬
        }
    }
    

    //=========ѧ����ɣ�����Ƿ�Ҫ��flag����ô��==================

    return data[front];             //��ȡ�����س���ǰ�Ķ�ͷԪ�أ�ע���ͷָ��
}

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
    //=========ѧ����ɣ��ĳ�flagʵ�֣��ж϶ӿ�==================
    if (rear == front)
    {
        throw string("�ӿ��쳣");
    }
    else
    {
        int i;
        i = (front + 1) % QueueSize;  //ע�ⲻҪ����ͷָ�븳ֵ
        return data[i];
    }
    
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
    //=========ѧ����ɣ��ĳ�flagʵ�֣��ж϶ӿ�==================
    if (front==rear) 
		return 1; 
	else 
		return 0;
}

/*
*ǰ�������������Ѵ���
* ��    �룺��
* ��    �ܣ��ж϶����Ƿ���
* ��    ������������������� true�����򣬷��� false
* �������������в���
*/

template <class T>
bool CirQueue<T>::Full()
{
    // �ж϶����Ƿ���
    if ((rear + 1) % QueueSize == front) {
        return true; // ������
    }
    else {
        return false; // ���в���
    }
}
