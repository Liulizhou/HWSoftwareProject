/*
 * HWGenetics.h
 * 日期：2017年3月9日
 * 描述：文件主要将遗传学算法抽象成类，申明这个并实现遗传学算法
 */

#ifndef HWGENETICS_H_
#define HWGENETICS_H_

#include <iostream>
#include <vector>
#include <map>

#include "Graph/HWGraph.h"
using namespace std;

class HWGenetics {
public:
	HWGenetics();
	HWGenetics(HWGraph* G);
	void initPopServer(); //初始化服务器(种群),根据服务器数量来编码
	void selectPopServers(); //选择服务器
	void calculationBPCost(); //确定服务we器后，计算最优路径费用
	void crossOperation(); //交叉运算
	void varOperation(); //变异运算
	void idvEncode(); //个体编码
	void idvDecode(); //个体解码
	virtual ~HWGenetics();
private:
	struct idv {
		vector<int> codedValue; //编码值
		int value; //个体实际值
		double fitness; //适应度
	};
	int popSize;

	HWGraph* G;
};
#endif /* HWGENETICS_H_ */

