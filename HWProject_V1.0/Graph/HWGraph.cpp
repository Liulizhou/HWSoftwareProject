/*
 * HWGraph.cpp
 * ���ڣ�2017��3��9��
 * ���������ļ�����������
 */

#include "HWGraph.h"

/*
* @description:����ͼ(����ͼ/��)
*/
Status CreateGraph(HWGraph* G, char* topo[MAX_EDGE_NUM], int line_num) {
	EBox *edgeBox;
    int index = 1; //��ȡtopo������������ 1 ��ʾ��һ�У���topo[index - 1]
	//��ȡ����ڵ����������ѽڵ�������������·������ ������·����������������·����=���ѽڵ�������
	sscanf(topo[index - 1], "%d %d %d", &(G->netVNum), &(G->netArcNum), &(G->csuVNum));
	G->csuArcNum = G->csuVNum;
	//��ʼ�����ж����ֵ, ����ڵ��Ŵ�0��ʼ�����ѽڵ��Ŵ�0��ʼ
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

	//ȷ����߹�ϵ
	for (int i = 0; i < G->netArcNum; i++) { //����ڵ�
		index += 4;
		int inetVex, jnetVex, totalBDW, rentCost;
		sscanf(topo[index - 1], "%d %d %d %d", &inetVex, &jnetVex, &totalBDW, &rentCost);
		//����������·
		edgeBox = (EBox *) malloc(sizeof(struct EBox));
		if (!edgeBox)
			exit(OVERFLOW);
		edgeBox->ivex = inetVex;
		edgeBox->jvex = jnetVex;
		edgeBox->mark = unvisited;
		//��ʼ��Ȩ��
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
	for (int i = 0; i < G->csuVNum; i++) {//�����߽ڵ�
        //ͨ���ڵ��ֵ��ȡ�ڵ���ͼ�еı��
		index = index + 1;
		int icsuVexData, jnetVex, demand;
		sscanf(topo[index - 1], "%d %d %d", &icsuVexData, &jnetVex, &demand);
		int icsuVex = locateCSUVex(G, icsuVexData);
		//����������·
		edgeBox = (EBox *) malloc(sizeof(struct EBox));
		if (!edgeBox)
			exit(OVERFLOW);
		edgeBox->ivex = icsuVex;
	    edgeBox->jvex = jnetVex;
		edgeBox->mark = unvisited;
		//��ʼ��Ȩ��
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
 * description ��ʼ�����ж���ȣ������������߽ڵ�
 */
Status initAllVexDegree(HWGraph* G) {
	for (int i = 0; i < G->netVNum; i++) { //������������ڵ㣬�����
		G->adjmulist[i].degree = getVexDegree(G, i);
	}
	return OK;
}

/*
 * description ���������Ķ�
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
* @description:��λһ������ֵ��ͼ�е�λ��,���򷵻�-1
*/

int locateCSUVex(HWGraph* G,int v) {
	return G->netVNum + v;
}


/*
* @description:���ض���v��ֵ
*/
int GetVex(HWGraph* G,int v) {
	return OK;
}


/*
* @description:�Զ���ֵΪv�Ķ��㸳ֵΪvalue
*/
Status PutVex(HWGraph *G,int v,int value) {
	return OK;
}


/*
* @description:���ض���ֵΪv����һ���ڽӵ����ţ����򷵻�-1
*/
int FirstAdjVex(HWGraph* G,int v) {
	return OK;
}


/*
* @description:���ض���ֵΪv����ڶ���ֵΪw����һ���ڽӶ�������
*/
int NextAdjVex(HWGraph* G,int v,int w) {
	return OK;
}


/*
* @description:����һ������
*/
Status InsertVex(HWGraph* G,int v) {
	return OK;
}


/*
* @description:����һ�λ�
*/
Status InsertArc(HWGraph* G,int v,int w) {

	return OK;

}



/*
 * @description:������ȱ���ͼ
 */
Status DFSTraverse(HWGraph* G) {
	return OK;
}


/*
 * @description:�ݹ�ʵ��������ȱ���
 */
void DFS(HWGraph* G,int i) {

}

