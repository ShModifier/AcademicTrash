//CirQueue.h
#ifndef CIRQUEUE_H
#define CIRQUEUE_H

//�������ڵ��ԺͲ���!
const int QueueSize=3;  //����洢����Ԫ�ص��������󳤶�

template <class T>        //����ģ����CirQueue
class CirQueue
{
public:
    CirQueue( );        //���캯�����ÿն�
    ~ CirQueue( );               //��������
    void EnQueue(T x);           //��Ԫ��x���
    T DeQueue( );                //����ͷԪ�س���
    T GetQueue( );               //ȡ��ͷԪ�أ�����ɾ����
    bool Empty( );               //�ж϶����Ƿ�Ϊ��
    bool Full();
private:
    T data[QueueSize];           //��Ŷ���Ԫ�ص�����
    int front, rear;    //��ͷ�Ͷ�βָ�룬�ֱ�ָ���ͷԪ�ص�ǰһ��λ�úͶ�βԪ�ص�λ��
    bool flag;
    /*---------------------�ĳ�flagʵ��-------------------*/
};

#endif