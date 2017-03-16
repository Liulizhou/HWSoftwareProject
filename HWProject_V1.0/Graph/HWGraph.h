/*
 * HWGraph.h
 * 日期：2017年3月9日
 * 描述：邻接多重表的构建及图的基本操作
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
#define NOTUSED -1 //表示该字段不可用

#define MAX_VERTEX_NUM_NET 1000   //最大的网络节点数量
#define MAX_VERTEXT_NUM_CSU 500   //最大的消费者节点数量

//顶点数据类型
typedef int VType;
//状态返回
typedef int Status;
//访问标记
typedef enum {unvisited,isvisited}VisitIf;
//顶点的种类：网络/消费者
typedef enum {CSUV, NEWV}VexKind;
//边的种类：链路/消费路径
typedef enum {LINKE, CSUE}EdgeKind;

typedef struct EBox {
	VisitIf mark;	//访问标记
	EdgeKind eKind; //边的类型
	int ivex;	//边顶点一
	int jvex;	//边顶点二
	struct EBox *ilink;	//指向依附于顶点一的下一条边,类似于起点相同的一条弧
	struct EBox *jlink;	//指向依附于顶点二的下一条边,类似与终点想同的一条弧
	int rentCost;	//网络租用费[1, 100]，若为消费路径，无租用费(-1)
	int totalBDW;  //链路总带宽[0, 100], 若为消费路径，总带宽无限大(-1)
	int demand; //若为消费路径，消费者带宽需求
	int transferred; //网络路径传输带宽
}EBox;

typedef struct VexBox {
	VType data;
	VexKind vexKind;
	EBox *firstarc;	//指向第一条依附于该顶点的边
}VBox;


typedef struct {
	VBox adjmulist[MAX_VERTEX_NUM_NET + MAX_VERTEXT_NUM_CSU];
	int netVNum; //网络节点数量
	int csuVNum;  //消费节点数量
	int netArcNum;	//网络链路数量
	int csuArcNum; //消费链路数量
}HWGraph;

//创建图
Status CreateGraph(HWGraph *G, char* topo[MAX_EDGE_NUM], int line_num);

//定位一个顶点值为图中的位置，否则返回-1
int locateCSUVex(HWGraph* G,VType v);


//返回顶点的值
VType GetVex(HWGraph G,int v);

//赋值
Status PutVex(HWGraph *G,VType v,VType value );

//插入一个顶点
Status InsertVex(HWGraph *G,VType v);

//插入一段弧
Status InsertArc(HWGraph *G,VType v,VType w);

//返回顶点值为v的下一个邻接顶点的序号，否怎返回-1
int FirstAdjVex(HWGraph G,VType v);

//返回顶点值为v相对于顶点值为w的下一个顶点的序号
int NextAdjVex(HWGraph G,VType v,VType w);


//深度优先遍历
Status DFSTraverse(HWGraph G);


//递归实现深度遍历邻接点
void DFS(HWGraph G,int i);

#endif /* GRAPH_HWGRAPH_H_ */

