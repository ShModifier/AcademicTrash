//�й�����ʵ�ֵ����������ļ���Ϊtreemain.cpp
#include <iostream>
#include <string>
#include"tree.cpp"
using namespace std;

void main() 
{
    Tree<string> t; //����һ����
    /*
       ����Խ̲�P130 ͼ5-3 (a) �ɰ����·�ʽ���룺
	   A
	   A B
	   C G   //�����������
	   
	   B D
	   B E
	   B F

       C G   //�����������
	   
	   A C
	   C G
	   C H
	   E I
      */
	/*
		ѡ����1
		
	*/

	TNode<string>* p = t.Getroot( );  //��ȡָ�������ָ�� 
	cout<<"------ǰ�����------ "<<endl;
	t.PreOrder(p);
	cout<<endl;
	cout<<"------�������------ "<<endl;
	t.PostOrder(p);
	cout<<endl;
	cout<<"------�������------ "<<endl;
	t.LevelOrder(p);
	cout<<endl;
}