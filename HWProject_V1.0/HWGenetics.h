/*
 * HWGenetics.h
 * ���ڣ�2017��3��9��
 * �������ļ���Ҫ���Ŵ�ѧ�㷨������࣬���������ʵ���Ŵ�ѧ�㷨
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
	void initPopServer(); //��ʼ��������(��Ⱥ),���ݷ���������������
	void selectPopServers(); //ѡ�������
	void calculationBPCost(); //ȷ������we���󣬼�������·������
	void crossOperation(); //��������
	void varOperation(); //��������
	void idvEncode(); //�������
	void idvDecode(); //�������
	virtual ~HWGenetics();
private:
	struct idv {
		vector<int> codedValue; //����ֵ
		int value; //����ʵ��ֵ
		double fitness; //��Ӧ��
	};
	int popSize;

	HWGraph* G;
};
#endif /* HWGENETICS_H_ */

