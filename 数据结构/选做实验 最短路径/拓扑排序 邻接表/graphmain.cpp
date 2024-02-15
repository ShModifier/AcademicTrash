//graphmain.cpp
#include <iostream>
#include <string>
#include "graph.cpp"
using namespace std;
int visited[MaxSize];
int MyFlag=0;

void main( )
{
	int which;
	int pos1,pos2;
	int j;
	string name;
	int choose=1;
//	string a[6] = {"A","B","C","D","E","F"};   //�̲�ver2,P174 ͼ6-35
	string a[6] = {"v0","v1","v2","v3","v4","v5"};   //�̲�ver3 P202 ͼ6-27
	ALGraph<string> algraphTest( a, 6, 0);        //����ͼ ע��������ͼ
	while ( choose==1 )                                      //����
	{ cout<<"===================================="<<endl;
	  cout << "��Ҫ���������Ϣ�밴0" << endl;		         //������Ҫ���еĲ��������
	  cout << "��Ҫ�������һ��������Ϣ�밴1" << endl;
      cout << "��Ҫ���붥���밴2" << endl;
      cout << "��Ҫ�޸Ķ����밴3" << endl;
      cout << "��Ҫɾ�������밴4" << endl;      	  
	  cout << "��Ҫ������ȱ����밴5" << endl;
	  cout << "��Ҫ������ȱ����밴6" << endl;
	  cout << "��Ҫɾ�����밴7" << endl;
	  cout << "��Ҫ������밴8" << endl;
      cout << "���� ���  ���ȱ������ж������Ƿ����ͨ· �밴 9" << endl;
	  cout << "���� ���  ���ȱ������ж������Ƿ����ͨ· �밴 10" << endl;
	  cout << "���������밴11" << endl;
	  cout << "��Ҫ�˳��밴12" << endl;
	  cout<<"===================================="<<endl;
      cin >> which;
      switch( which )                                        //����ѡ��
	  {
		 case 0:
			 for(j=0;j<6;j++ )
				cout<<algraphTest.GetVex(j)<<" ";              //�������
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
		    catch(char* s)
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
		   catch(char* s)
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
		   catch(char* s)
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
		   catch(char* s)
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
		   catch(char* s)
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
		   catch(char*s)
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
			   catch(char* s)
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
		   catch(char* s)
		   {
				cout<<s<<endl;
		   }
          
	        break;

      case 9:
		   cout<<"---------------------------------------"<<endl;
		   cout<<"���ڹ�����ȱ������ж������Ƿ����ͨ·"<<endl;
		   cout<<"---------------------------------------"<<endl;
		   cout<<"�����������㣺"<<"\n";
		   cin>>pos1>>pos2;
		   //���ڹ�����ȱ������ж������Ƿ����ͨ· 1:���ڣ�0:������
		   for ( j=0; j<MaxSize; j++) 
			   visited[j] = 0;
           if ( algraphTest.BFSTconJudge( pos1,pos2 )>0 ) 
			   cout<<"����ͨ·!"<<endl;
		   else
              cout<<"����ͨ!"<<endl;
		    cout<<"---------------------------------------"<<endl;
				
		   break;
	case 10:
		 cout<<"---------------------------------------"<<endl;
		   cout<<"����������ȱ������ж������Ƿ����ͨ·"<<endl;
		  cout<<"---------------------------------------"<<endl;	
	    	cout<<"�����������㣺"<<"\n";
		   cin>>pos1>>pos2;
		   //����������ȱ������ж������Ƿ����ͨ· 1:���ڣ�0:������
		   for ( j=0; j<MaxSize; j++) 
			   visited[j] = 0;
		   MyFlag=0; //ȫ�ֱ�Ǳ���
           algraphTest.DFSTconJudge( pos1,pos2 );
           if (MyFlag >0 ) 
			   cout<<"����ͨ·!"<<endl;
		   else
              cout<<"����ͨ!"<<endl;
		   cout<<"---------------------------------------"<<endl;
				
		   break;

	 case 11:
           algraphTest.TopSort();
		   break;
     case 12:                                             //�˳�
		   choose=0;
           break;
	  }
   }
}
 