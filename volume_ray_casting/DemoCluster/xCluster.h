//  *************************************************************************
//	xCluster       version: 1.0 	
//  -------------------------------------------------------------------------
//  Purpose:    An abstract class of Cluster;
//	Author:		JH Wu [ jh.wu@siat.ac.cn ]
//  Date:       2010/08/03  11:22
//	-------------------------------------------------------------------------
//	Copyright (c) 2010 - All Rights Reserved
//
//  Center for Human-Computer Interaction,
//  Shenzhen Institutes of Advanced Technology, Chinese Academy of Sciences
//  *************************************************************************
//
//  *************************************************************************
#pragma once

#include <vector>
using std::vector;
const double EPISLON = 0.000001;


struct Pattern  // ����;
{
	vector<double> pattern;
};
 
struct Cluster  // ����;
{
	vector<double> center; // ��������;
	vector<int>    member; // Index of data belonging to this cluster
};

class CxCluster
{
private:

	int m_nPattern;  // ����������
	int m_nDim;      // ����ά��;
	int m_nCluster;  // �������;

	double m_Error;  // �����������;

protected:

	virtual void   DistributeSamples(); // ���������ԭ���������;
	virtual bool   CalNewClusterCenters() = 0; 
	virtual double CalFitCost() = 0; // �������׼��������;

	int    FindClosestCluster(int p); // return index of cluster closest to pattern p

	double CalEuclideanNorm(const vector<double>& p1, const vector<double>& p2); // ����֮��ŷʽ����;
	double CalEuclideanNorm(int c, int p);   // �������������ľ���,

	//��С�����ھ���,��󻯾ۼ����
	double CalFitCostMinMax(double w1 = 0.5, double w2 = 0.5);

public:

	CxCluster(int nPattern, // ��������;
		      int nDim,     // ����ά��;
			  int nCluster);// �������;

	virtual~CxCluster(void) {}

	vector<Pattern> m_ArrayPattern; // �洢����������;
	vector<Cluster> m_ArrayCluster; // ������;
	vector<int> m_ArrayLabel; // �������������

	int GetDim()      { return m_nDim;     }
	int NumClusters() { return m_nCluster; }
	int NumPatterns() { return m_nPattern; }

	void SetError(double e) { m_Error = e; }
	double GetError() {return m_Error;     }

	virtual void  InitClusters(); // STEP 1;

	                                              // ������̵�����������
	virtual double Run(int nIter);                // 1.��������, ���ؾ���׼�����;
	virtual double Run(double epsilon = EPISLON); // 2.���ı仯���,���ؾ���׼�����;

};
