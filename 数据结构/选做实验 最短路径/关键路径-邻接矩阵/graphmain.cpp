#include <iostream>
#include <string>                   //�����׼���е�ͷ�ļ�
#include "graph.cpp"                //����graph.cpp�ļ�
using namespace std;
int visited[MaxSize];
int visited2[MaxSize];

int main(int argc, char* argv[])
{
	int i;
   	int choose=1;                      //����
    int which;                         //����ѡ�����	
	string name;                       //���붥���ֵ
	//��ʼ��������,�̲�ver2 P176(ͼ6-37),ver3 P217(ͼ6-52)
    string vname[9]={"v0","v1","v2","v3","v4","v5","v6","v7","v8"};  
    int pos1;                           //����
	int pos2;                           //����
	int m;                                                   
	MGraph<string> g(vname,9,0);        //����Graph����
   while ( choose==1 )                  //����
	{
	  cout<<"+++++++++++++++++++++++++++++++++"<<endl;
	  cout << "��Ҫ���������Ϣ�밴0" << "\n";		   //������Ҫ���еĲ��������
	  cout << "��Ҫ�������һ��������Ϣ�밴1" << "\n";
      cout << "��Ҫ�ߵ���Ϣ����밴2" << "\n";
      cout << "��Ҫɾ���밴3" << "\n";
      cout << "��Ҫ�����밴4" << "\n";	  
	  cout << "��Ҫɾ��ĳ�����밴5" << "\n";
	  cout << "��Ҫ����ĳ�����밴6" << "\n";
	  cout << "��Ҫ������ȱ����밴7" << "\n";
	  cout << "��Ҫ������ȱ����밴8" << "\n";
	  cout << "��Ҫ�˳��밴10" << "\n";
	  cout << "����ؼ�·���밴11" << "\n";
	  cout<<"+++++++++++++++++++++++++++++++++"<<endl;
      cin >> which;
      switch( which )                  //����ѡ��
	  {
         
	   case 0:                   //���ͼ�ĸ������ֵ
		     g.PrintVex();                                
			
		    break;      
	   
	   case 1:                   //���ͼ�����ⶥ���ֵ
		  try
		  {
			 int i;
			 cout<<"�����붥�㣺"<<"\n";
		     cin>>i;
			 g.GetVex(i);				              
                        
		  }
		  catch(char*)
		  {
			 cout<<"�������ȷ��"<<endl;
		  }
			
		    break;
	  
	   case 2:                       //���ͼ�еı�	     
		    cout<<"���еıߵ���ϢΪ:"<<"\n";
		    g.PrintArc();
		    break;                

       case 3:                        //ɾ��hh����
  	       int hh ;
		   cout<<"������Ҫɾ���Ķ���"<<"\n";
	       cin>>hh;
	       try
		   {
			  g.DeleteVex(hh);                 
		   }
		   catch(char*)
		   {
		      cout<<"ɾ��ʧ�ܣ�"<<endl;
		   }
			break;

       case 4:                        //��nnλ�ò���ֵΪname�Ķ���
	      int nn ;
		  cout<<"������Ҫ����Ķ���λ�ü�����"<<"\n";
	      cin>>nn>>name;			   
	      try
		  {
			  g.InsertVex(nn,name); 
		  }
		  catch(char*)
		  {
			  cout<<"����ʧ�ܣ�"<<endl;
		  }
			break;

       case 5:                      //ɾ��������֮���·��         
	      cout<<"�����������㣺"<<"\n";
		  cin>>pos1>>pos2;
		  try
		  {
			 g.DeleteArc(pos1,pos2); 
		  }
		  catch(char*)
		  {
		     cout<<"����ʧ�ܣ�"<<endl;
		  }
          
	        break;

       case 6:                   //����һ����         
	      cout<<"�����������㣺"<<"\n";
		  cin>>pos1>>pos2;
		  cout<<"������·����"<<"\n";
		  cin>>m;
		  try
		  {
			 g.InsertArc(pos1,pos2,m);
		  }
		  catch(char*)
		  {
			 cout<<"����ʧ�ܣ�"<<endl;
		  }
          
	        break;

       case 7:                  //��ȱ���
		  cout<<"�����붥�㣺"<<"\n";
		  for (i=0; i<MaxSize; i++)                                                   
			 visited[i] = 0;
		  int mm;
		  cin>>mm;
		  try
		  {
		     g.DFSTraverse(mm);
		  }
		  catch(char*)
		  {
		     cout<<"����ʧ�ܣ�"<<endl;
		  }
              
		    break;

       case 8:                  //��ȱ���
		  cout<<"�����붥�㣺"<<"\n";		  
		  
		  for (i=0; i<MaxSize; i++) 
		      visited2[i]=0;
			 int mr;
		     cin>>mr;		  
		  try
		  {
			 g.BFSTraverse(mr);
		     cout<<"\n";
		  }
		  catch(char*)
		  {
		     cout<<"����ʧ�ܣ�"<<endl;
		  }              
		    break;
			
       case 10:              //�˳�
              choose=0;
            break;  
	   case 11: 
		    cout<<"------------�ؼ�·��-----------------"<<endl;
			int vf,vt;
			cout<<"�����:";
			cin>>vf;
            cout<<"�յ���:";
			cin>>vt;
			cout<<endl;	
			g.KeyPath(vf,vt);
			break;  
  }
 }		  
return 0;
 }
 