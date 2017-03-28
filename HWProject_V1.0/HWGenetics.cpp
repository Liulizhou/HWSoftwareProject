/*
 * HWGenetics.cpp
 * 日期：2017年3月9日
 * 描述：对文件进行描述吧
 */
#include "HWGenetics.h"

/*
 * @description 无参构造函数,初始化类
 */
HWGenetics::HWGenetics() {
	// TODO Auto-generated constructor stub
	this->G = NULL;
	popSize = 0;
}

/*
 * @description 构造函数，用Graph初始化类
 */
HWGenetics::HWGenetics(HWGraph* G) {
	this->G = G;
	popSize = 0;
}

/*
 * @description 析构函数
 */
HWGenetics::~HWGenetics() {
	// TODO Auto-generated destructor stub
}

/*
 * @description 个体编码
 */
void HWGenetics::idvEncode() {

}

/*
 * @description 个体解码
 */
void HWGenetics::idvDecode() {

}
/*
 * @description 初始化种群
 * @function 1.确定种群大小 2.确定种群中的个体
 */
void HWGenetics::initPopServer() {
	//确定种群大小 1.对顶点的度排序 2.选择度比较高的服务器
	map<int, int> vd;
	for (int i = 0; i < G->netVNum; i++) {
		vd.insert(map<int, int>::value_type(i, G->adjmulist[i].degree));
	}
	//排序，从小到大

	//第一次选择服务器算法
}

/*
 * @description 选择运算
 */
void HWGenetics::selectPopServers() {

}

/*
 * @description 计算最优路径费用
 */
void HWGenetics::calculationBPCost() {

}

/*
 * @description 种群交叉运算
 */
void HWGenetics::crossOperation() {

}

/*
 * @description 种群变异运算
 */
void HWGenetics::varOperation() {

}
