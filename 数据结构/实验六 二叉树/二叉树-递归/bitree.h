//������BiTree������ṹBiNode,�ļ���Ϊbitree.h
#ifndef BITREE_H
#define BITREE_H

const int ASize = 20;
//"AB#D##C##";
//"ABD#G###CE##F##";
extern char PreOrderString[ASize];
extern int chCnt;
extern int Count;
extern int DeepL;
extern int DeepR;

template <class T>
struct BiNode   //�������Ľ��ṹ
{
  T data;       
  BiNode<T> *lchild, *rchild;
};

template <class T>
class BiTree
{
public:
             
	BiTree(int flag );     //�Ľ�����Ĺ���
    ~BiTree(void);         //�����������ͷŶ��������и����Ĵ洢�ռ�
	BiNode<T>* Getroot();  //���ָ�������ָ��
    void PreOrder(BiNode<T> *root);     //ǰ�����������
    void InOrder(BiNode<T> *root);      //�������������
    void PostOrder(BiNode<T> *root);    //�������������
    void LevelOrder(BiNode<T> *root);   //�������������
    void CountNode(BiNode<T>* root);    //����Ҷ�ӽڵ�
    void PrintLeafNode(BiNode<T>* root); //����ǰ��˳���ӡҶ�ӽڵ�
    int DepthTree(BiNode<T>* root); //������������

private:
    BiNode<T> *root;         //ָ�������ͷָ��
    BiNode<T> *Creat( );     //�вι��캯������
	BiNode<T> *Creat1( );    //�Ľ�����
    void Release(BiNode<T> *root);   //������������ 
};
#endif