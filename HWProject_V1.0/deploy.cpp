#include "deploy.h"

#include "Graph/HWGraph.h"
#include "HWGenetics.h"

//You need to complete the function 
void deploy_server(char * topo[MAX_EDGE_NUM], int line_num,char * filename)
{
	//构造图
    HWGraph* G;
    CreateGraph(G, topo, line_num);
    //初始化所有度
    initAllVexDegree(G);
    HWGenetics genetics(G);
	// Output demo
	char * topo_file = (char *)"17\n\n0 8 0 20\n21 8 0 20\n9 11 1 13\n21 22 2 20\n23 22 2 8\n1 3 3 11\n24 3 3 17\n27 3 3 26\n24 3 3 10\n18 17 4 11\n1 19 5 26\n1 16 6 15\n15 13 7 13\n4 5 8 18\n2 25 9 15\n0 7 10 10\n23 24 11 23";

	write_result(topo_file, filename);

}
