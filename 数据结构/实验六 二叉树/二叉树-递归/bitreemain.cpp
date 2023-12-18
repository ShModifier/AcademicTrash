//�����������������ļ���Ϊbitreemain.cpp
#include<iostream>
#include<string>
#include"bitree.cpp"
using namespace std;

//char PreOrderString[]="AB#D##C##";
char PreOrderString[]="ABD##EH###CF#I##G##";
int chCnt = 0;
int Count = 0;
int DeepL = 0, DeepR = 0;


int main()
{	
    //��ǰ�򴴽�һ���� p144 5-24 (AB#D##C##) �� p141 5-20 (ABD#G###CE##F##)�������桿

	//BiTree<string> bt(1); //----��������-------       
    BiTree<string> bt(0); //-----��PreOrderString, �Զ�����-----
       
	BiNode<string>* root = bt.Getroot( );  //��ȡָ�������ָ�� 

	cout<<"------ǰ�����------ "<<endl;
	bt.PreOrder(root);
    cout<<endl;
   

	cout<<"------�������------ "<<endl;
	bt.InOrder(root);
	cout<<endl;


	cout<<"------�������------ "<<endl;
	bt.PostOrder(root);
	cout<<endl;
   

	cout<<"------�������------ "<<endl;
	bt.LevelOrder(root);
	cout<<endl;

	cout << "------�㷨��Ʋ���------ " << endl;
	cout << "------���������------ " << endl;
	bt.CountNode(root);
	cout << "�˶������й���" << Count << "�����" << endl;

	cout << "------ǰ������ӡҶ�ӽڵ�------ " << endl;
	bt.PrintLeafNode(root);
	cout << endl;

	cout << "------������������------ " << endl;
	cout << "���������Ϊ" << bt.DepthTree(root) << endl;



	return 0;
}