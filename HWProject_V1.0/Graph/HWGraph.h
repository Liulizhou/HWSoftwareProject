/*
 * HWGraph.h
 * ���ڣ�2017��3��9��
 * �������ڽӶ��ر�Ĺ�����ͼ�Ļ�������
 */

#ifndef GRAPH_HWGRAPH_H_
#define GRAPH_HWGRAPH_H_

#include <stdio.h>
#include <stdlib.h>
#include "../lib/lib_io.h"
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define NOTUSED -1 //��ʾ���ֶβ�����

#define MAX_VERTEX_NUM_NET 1000   //��������ڵ�����
#define MAX_VERTEXT_NUM_CSU 500   //���������߽ڵ�����

//������������
typedef int VType;
//״̬����
typedef int Status;
//���ʱ��
typedef enum {unvisited,isvisited}VisitIf;
//��������ࣺ����/������
typedef enum {CSUV, NEWV}VexKind;
//�ߵ����ࣺ��·/����·��
typedef enum {LINKE, CSUE}EdgeKind;

typedef struct EBox {
	VisitIf mark;	//���ʱ��
	EdgeKind eKind; //�ߵ�����
	int ivex;	//�߶���һ
	int jvex;	//�߶����
	struct EBox *ilink;	//ָ�������ڶ���һ����һ����,�����������ͬ��һ����
	struct EBox *jlink;	//ָ�������ڶ��������һ����,�������յ���ͬ��һ����
	int rentCost;	//�������÷�[1, 100]����Ϊ����·���������÷�(-1)
	int totalBDW;  //��·�ܴ���[0, 100], ��Ϊ����·�����ܴ������޴�(-1)
	int demand; //��Ϊ����·���������ߴ�������
	int transferred; //����·���������
}EBox;

typedef struct VexBox {
	VType data;
	VexKind vexKind;
	EBox *firstarc;	//ָ���һ�������ڸö���ı�
}VBox;


typedef struct {
	VBox adjmulist[MAX_VERTEX_NUM_NET + MAX_VERTEXT_NUM_CSU];
	int netVNum; //����ڵ�����
	int csuVNum;  //���ѽڵ�����
	int netArcNum;	//������·����
	int csuArcNum; //������·����
}HWGraph;

//����ͼ
Status CreateGraph(HWGraph *G, char* topo[MAX_EDGE_NUM], int line_num);

//��λһ������ֵΪͼ�е�λ�ã����򷵻�-1
int locateCSUVex(HWGraph* G,VType v);


//���ض����ֵ
VType GetVex(HWGraph G,int v);

//��ֵ
Status PutVex(HWGraph *G,VType v,VType value );

//����һ������
Status InsertVex(HWGraph *G,VType v);

//����һ�λ�
Status InsertArc(HWGraph *G,VType v,VType w);

//���ض���ֵΪv����һ���ڽӶ������ţ���������-1
int FirstAdjVex(HWGraph G,VType v);

//���ض���ֵΪv����ڶ���ֵΪw����һ����������
int NextAdjVex(HWGraph G,VType v,VType w);


//������ȱ���
Status DFSTraverse(HWGraph G);


//�ݹ�ʵ����ȱ����ڽӵ�
void DFS(HWGraph G,int i);

#endif /* GRAPH_HWGRAPH_H_ */

