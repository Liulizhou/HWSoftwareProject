/*
 * HWGenetics.cpp
 * ���ڣ�2017��3��9��
 * ���������ļ�����������
 */
#include "HWGenetics.h"

/*
 * @description �޲ι��캯��,��ʼ����
 */
HWGenetics::HWGenetics() {
	// TODO Auto-generated constructor stub
	this->G = NULL;
	popSize = 0;
}

/*
 * @description ���캯������Graph��ʼ����
 */
HWGenetics::HWGenetics(HWGraph* G) {
	this->G = G;
	popSize = 0;
}

/*
 * @description ��������
 */
HWGenetics::~HWGenetics() {
	// TODO Auto-generated destructor stub
}

/*
 * @description �������
 */
void HWGenetics::idvEncode() {

}

/*
 * @description �������
 */
void HWGenetics::idvDecode() {

}
/*
 * @description ��ʼ����Ⱥ
 * @function 1.ȷ����Ⱥ��С 2.ȷ����Ⱥ�еĸ���
 */
void HWGenetics::initPopServer() {
	//ȷ����Ⱥ��С 1.�Զ���Ķ����� 2.ѡ��ȱȽϸߵķ�����
	map<int, int> vd;
	for (int i = 0; i < G->netVNum; i++) {
		vd.insert(map<int, int>::value_type(i, G->adjmulist[i].degree));
	}
	//���򣬴�С����

	//��һ��ѡ��������㷨
}

/*
 * @description ѡ������
 */
void HWGenetics::selectPopServers() {

}

/*
 * @description ��������·������
 */
void HWGenetics::calculationBPCost() {

}

/*
 * @description ��Ⱥ��������
 */
void HWGenetics::crossOperation() {

}

/*
 * @description ��Ⱥ��������
 */
void HWGenetics::varOperation() {

}
