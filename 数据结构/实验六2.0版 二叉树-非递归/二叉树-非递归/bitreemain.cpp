//�����������������ļ���Ϊbitreemain.cpp
#include<iostream>
#include<string>
#include"bitree.cpp"
using namespace std;

//char PreOrderString[]="AB#D##C##";
char PreOrderString[]="ABD#G###CE##F##";
int chCnt = 0; 

void main()
{	
    //��ǰ�򴴽�һ���� p144 5-24 (AB#D##C##) �� p141 5-20 (ABD#G###CE##F##)�������桿
	      
    BiTree<string> bt;
                         
	BiNode<string>* root = bt.Getroot( );  //��ȡָ�������ָ�� 

	cout<<"------ǰ�����------ "<<endl;
	bt.PreOrder(root);
    cout<<endl;
    cout<<"------�ǵݹ�ǰ�����------ "<<endl;
	bt.fdg_PreOrder(root);
	cout<<endl<<endl;

	cout<<"------�������------ "<<endl;
	bt.InOrder(root);
	cout<<endl;
	cout<<"------�ǵݹ��������------ "<<endl;
	bt.fdg_InOrder(root);
	cout<<endl<<endl;

	cout<<"------�������------ "<<endl;
	bt.PostOrder(root);
	cout<<endl;
    cout<<"------�ǵݹ�������------ "<<endl;
	bt.fdg_PostOrder(root);
	cout<<endl<<endl;

	cout<<"------�������------ "<<endl;
	bt.LevelOrder(root);
	cout<<endl;

	cout << "------�ڶ������в���X------ " << endl;
	string search;
	cout << "������Ҫ���ҵ�Ԫ��" << endl;
	cin >> search;
	bt.Search(root, search);
	cout << endl;



}