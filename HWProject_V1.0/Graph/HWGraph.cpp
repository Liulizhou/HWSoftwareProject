/*
 * HWGraph.cpp
 * 日期：2017年3月9日
 * 描述：对文件进行描述吧
 */

#include "HWGraph.h"

/*
* @description:创建图(无向图/网)
*/
Status CreateGraph(HWGraph* G, char* topo[MAX_EDGE_NUM], int line_num) {
	EBox *edgeBox;
    int index = 1; //读取topo的行数，这里 1 表示第一行，即topo[index - 1]
	//读取网络节点数量，消费节点数量，网络链路数量， 消费链路数量（这里消费链路数量=消费节点数量）
	sscanf(topo[index - 1], "%d %d %d", &(G->netVNum), &(G->netArcNum), &(G->csuVNum));
	G->csuArcNum = G->csuVNum;
	//初始化所有顶点的值, 网络节点编号从0开始，消费节点编号从0开始
	for (int i = 0; i < G->netVNum; i++) {
		G->adjmulist[i].data = i;
		G->adjmulist[i].degree = NOTUSED;
		G->adjmulist[i].vexKind = NEWV;
		G->adjmulist[i].firstarc = NULL;
	}
	for (int i = G->netVNum; i < G->netVNum + G->csuVNum; i++) {
		G->adjmulist[i].data = i - G->netVNum;
		G->adjmulist[i].degree = NOTUSED;
		G->adjmulist[i].vexKind = CSUV;
		G->adjmulist[i].firstarc = NULL;
	}

	//确定点边关系
	for (int i = 0; i < G->netArcNum; i++) { //网络节点
		index += 4;
		int inetVex, jnetVex, totalBDW, rentCost;
		sscanf(topo[index - 1], "%d %d %d %d", &inetVex, &jnetVex, &totalBDW, &rentCost);
		//创建网络链路
		edgeBox = (EBox *) malloc(sizeof(struct EBox));
		if (!edgeBox)
			exit(OVERFLOW);
		edgeBox->ivex = inetVex;
		edgeBox->jvex = jnetVex;
		edgeBox->mark = unvisited;
		//初始化权重
		edgeBox->totalBDW = totalBDW;
		edgeBox->rentCost = rentCost;
		edgeBox->demand = NOTUSED;
		edgeBox->transferred = NOTUSED;
		edgeBox->ilink = (G->adjmulist[inetVex]).firstarc;
		edgeBox->jlink = (G->adjmulist[jnetVex]).firstarc;
		G->adjmulist[inetVex].firstarc = edgeBox;
		G->adjmulist[jnetVex].firstarc = edgeBox;
		index++;
		//this is test
	}
	for (int i = 0; i < G->csuVNum; i++) {//消费者节点
        //通过节点的值获取节点在图中的编号
		index = index + 1;
		int icsuVexData, jnetVex, demand;
		sscanf(topo[index - 1], "%d %d %d", &icsuVexData, &jnetVex, &demand);
		int icsuVex = locateCSUVex(G, icsuVexData);
		//创建消费链路
		edgeBox = (EBox *) malloc(sizeof(struct EBox));
		if (!edgeBox)
			exit(OVERFLOW);
		edgeBox->ivex = icsuVex;
	    edgeBox->jvex = jnetVex;
		edgeBox->mark = unvisited;
		//初始化权重
		edgeBox->totalBDW = NOTUSED;
		edgeBox->rentCost = NOTUSED;
		edgeBox->demand = demand;
		edgeBox->transferred = NOTUSED;
		edgeBox->ilink = G->adjmulist[icsuVex].firstarc;
		edgeBox->jlink = G->adjmulist[jnetVex].firstarc;
		G->adjmulist[icsuVex].firstarc = edgeBox;
		G->adjmulist[jnetVex].firstarc = edgeBox;
		index++;
	}
	return OK;
}

/*
 * description 初始化所有顶点度，不包括消费者节点
 */
Status initAllVexDegree(HWGraph* G) {
	for (int i = 0; i < G->netVNum; i++) { //遍历所有网络节点，并求度
		G->adjmulist[i].degree = getVexDegree(G, i);
	}
	return OK;
}

/*
 * description 求给定顶点的度
 */
int getVexDegree(HWGraph* G, int v) {
	int degree = 0;
	EBox* ebox = G->adjmulist[v].firstarc;
	if (ebox != NULL) {
		degree++;
		if (ebox->ivex == v)
			ebox = ebox->ilink;
		else
			ebox = ebox->jlink;
	}
	return degree;
}

/*
* @description:定位一个顶点值在图中的位置,无则返回-1
*/

int locateCSUVex(HWGraph* G,int v) {
	return G->netVNum + v;
}


/*
* @description:返回顶点v的值
*/
int GetVex(HWGraph* G,int v) {
	return OK;
}


/*
* @description:对顶点值为v的顶点赋值为value
*/
Status PutVex(HWGraph *G,int v,int value) {
	return OK;
}


/*
* @description:返回顶点值为v的下一个邻接点的序号，否则返回-1
*/
int FirstAdjVex(HWGraph* G,int v) {
	return OK;
}


/*
* @description:返回顶点值为v相对于顶点值为w的下一个邻接顶点的序号
*/
int NextAdjVex(HWGraph* G,int v,int w) {
	return OK;
}


/*
* @description:插入一个顶点
*/
Status InsertVex(HWGraph* G,int v) {
	return OK;
}


/*
* @description:插入一段弧
*/
Status InsertArc(HWGraph* G,int v,int w) {

	return OK;

}



/*
 * @description:深度优先遍历图
 */
Status DFSTraverse(HWGraph* G) {
	return OK;
}


/*
 * @description:递归实现深度优先遍历
 */
void DFS(HWGraph* G,int i) {

}

