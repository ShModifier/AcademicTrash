//graph.h
#ifndef GRAPH_H                  //����ͷ�ļ�
#define GRAPH_H                
using namespace std;
const int MaxSize=12;  
extern int visited[MaxSize];

struct ArcNode                   //����߱���
{
  int adjvex;                    //�ڽӵ���
  ArcNode *next;                 //ָ����һ���߽���ָ��
};
template <class T>
struct VertexNode               //���嶥�����
{
  T vertex;                     //���������
  ArcNode *firstedge;           //�߱��ͷָ��
};
template <class T>
class ALGraph
{
public:
   ALGraph(T a[ ], int n, int e);   //���캯������ʼ��һ����n������e���ߵ�ͼ
   ~ALGraph();                      //�����������ͷ��ڽӱ��и��߱���Ĵ洢�ռ�
   T GetVex(int i);                 //ȡͼ�е�i������������Ϣ
   void PutVex(int i, T value);     //��ͼ�е�i���������������Ϊvalue
   void InsertVex(int i, T value);  //��ͼ�в���һ�����㣬����Ϊi��ֵΪvalue
   void DeleteVex(int i);           //ɾ��ͼ�е�i������
   void InsertArc(int i, int j);    //��ͼ�в���һ���ߣ�����������������ı��Ϊi��j
   void DeleteArc(int i, int j);    //��ͼ��ɾ��һ���ߣ�����������������ı��Ϊi��j
   void DFSTraverse(int v);         //������ȱ���ͼ
   void BFSTraverse(int v);         //������ȱ���ͼ
   int GetVNum();
   void PrintArc();
private:
   VertexNode<T> adjlist[MaxSize];  //��Ŷ���������
   int vertexNum, arcNum;           //ͼ�Ķ������ͱ���
};
#endif