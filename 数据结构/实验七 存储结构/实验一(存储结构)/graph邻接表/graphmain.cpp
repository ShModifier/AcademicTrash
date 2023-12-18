//graphmain.cpp
#include <iostream>
#include <string>
#include "graph.cpp"
using namespace std;

int visited[MaxSize];
  
void main( )
{
	int which;
	int pos1,pos2;
	int j;
	string name;
	int choose=1;
	string vname[5]={"V0-���","V1-�㹤��","V2-�㽭��ý","V3-����","V4-����"};  //��ʼ��������
	ALGraph<string> algraphTest( vname, 5, 0);        //����ͼ
	while ( choose==1 )                                      //����
	{
	  cout << "====================================" << endl;	
	   cout << "��Ҫ���������Ϣ�밴0" << endl;		         //������Ҫ���еĲ��������
	  cout << "��Ҫ�������һ��������Ϣ�밴1" << endl;
      cout << "��Ҫ���붥���밴2" << endl;
      cout << "��Ҫ�޸Ķ����밴3" << endl;
      cout << "��Ҫɾ�������밴4" << endl;      	  
	  cout << "��Ҫ������ȱ����밴5" << endl;
	  cout << "��Ҫ������ȱ����밴6" << endl;
	  cout << "��Ҫɾ�����밴7" << endl;
	  cout << "��Ҫ������밴8" << endl;
	  cout << "��Ҫ�������Ϣ�밴9" << endl;
	  cout << "��Ҫ�˳��밴10" << endl;
	  cout << "====================================" << endl;
      cin >> which;
      switch( which )                                        //����ѡ��
	  {
		 case 0:
			 for(j=0;j< algraphTest.GetVNum(); j++)
				cout<<"�����ţ�"<<j <<", ���ݣ�"<<algraphTest.GetVex(j) << endl;              //�������
			 cout<<endl; 
			 break;
		 case 1:
			int i;
			cout<<"�����붥�㣺"<<endl;
			cin>>i;
			try
			{
				cout<<algraphTest.GetVex(i)<<endl;              //���i�����������
			}
		    catch(string s)
			{
			  cout<<s<<endl;
			}
		    break;
	    case 2:                                               //��ͼ�е�iλ�ò���һ����ֵΪname
		   cout<<"�����붥�㼰���֣�"<<endl;
		   cin>>i>>name;
		   try
		   {
			  algraphTest.InsertVex(i, name);					              
                        
		   }
		   catch(string s)
		   {
			  cout<<s<<endl;
		   }
		   break;
		case 3:                                               //�޸�ͼ��һ�����ֵ
		   cout<<"�����붥�㼰���֣�"<<endl;
		   cin>>i>>name;
		   try
		   {
			   algraphTest.PutVex(i, name);					              
		   }
		   catch(string s)
		   {
				cout<<s<<endl;
		   }
		   break;
		case 4:                                               //ɾ��ͼ��һ�����ֵ
		   cout<<"�����붥�㣺"<<endl;
		   cin>>i;
		   try
		   {
			    algraphTest.DeleteVex(i);					              
		   }
		   catch(string s)
		   {
				cout<<s<<endl;
		   }
		   break;
		case 5:                                               //ͼ�������������
		   cout<<"�����붥�㣺"<<endl;
		   cin>>i;
		   cout<<endl<<"�ӵ�"<<i<<"������������ȱ���ͼ"<<endl;
		   try
		   {
				for (int ii=0; ii<MaxSize; ii++) visited[ii] = 0;
	            algraphTest.DFSTraverse(i); 
				cout<<endl;
		   }
		   catch(string s)
		   {
				cout<<s<<endl;
		   }
		   break;
		case 6:                                               //ͼ�Ĺ����������
		   cout<<"�����붥�㣺"<<endl;
		   cin>>i;
		   cout<<endl<<"�ӵ�"<<i<<"�����������ȱ���ͼ"<<endl;
		   try
		   {
				for (int ii=0; ii<MaxSize; ii++) visited[ii] = 0;
				algraphTest.BFSTraverse(i);					              
		   }
		   catch(string s)
		   {
				cout<<s<<endl;
		   }
		   break;
	  case 7:                      //ɾ����       
			  cout<<"�����������㣺"<<"\n";
			 
			  cin>>pos1>>pos2;
			  try
			  {
				 algraphTest.DeleteArc(pos1,pos2); 
			  }
			   catch(string s)
			   {
				cout<<s<<endl;
			   }
          
				break;

       case 8:                   //����һ����         
	      cout<<"�����������㣺"<<"\n";
		  cin>>pos1>>pos2;
		  
		  try
		  {
			 algraphTest.InsertArc(pos1,pos2);
		  }
		   catch(string s)
		   {
				cout<<s<<endl;
		   }
          
	        break;

	   case 9:
		   algraphTest.PrintArc();
		   break;

		case 10:                                             //�˳�
		   choose=0;
           break;
	  }
   }
}
 