//  *************************************************************************
//	xFuzzyCMeans       version: 1.0 	
//  -------------------------------------------------------------------------
//  Purpose:    Fuzzy C-Means Cluster
//	Author:		JH Wu [ jh.wu@siat.ac.cn ]
//  Date:       2010/08/02  11:21
//	-------------------------------------------------------------------------
//	Copyright (c) 2010 - All Rights Reserved
//
//  Center for Human-Computer Interaction,
//  Shenzhen Institutes of Advanced Technology, Chinese Academy of Sciences
//  *************************************************************************
//
//  *************************************************************************
#pragma once

#include "xCluster.h"

class CxFuzzyCMeans:public CxCluster
{
private:

	int                     m_M;        // ģ��ָ��;
	vector<vector<double> > m_FuzzyMat; // ģ������;

protected:

	void   DistributeSamples();     
	bool   CalNewClusterCenters(); 
    int    FindMaxDegreeCluster(int p); // �����������������Ӧ�ľ�������;

	double CalFitCost();     // ����Ŀ�꺯��
	void   CalFuzzyMatrix(); // ����ģ������;

public:

	CxFuzzyCMeans(int nPattern, int nDim, int nCluster):
	             CxCluster(nPattern, nDim, nCluster){m_M = 2;}

	CxFuzzyCMeans(int nCluster);
	~CxFuzzyCMeans(void) {}
	
	void SetM(int m)  { m_M = m;  }
	int  GetM()       {return m_M;}

	// ��ʼ��������,
	void InitClusters(); // ��һ���Ǵ��������ѡ��K��������Ϊ��ʼ����;FCM-V
	void InitClusters2();// �ڶ������������ÿ��������������,Ȼ�����������; FCM-U

 	virtual double Run(double epsilon = EPISLON);
	virtual double Run(int nIter);


};

// NOTE:
// ģ��C��ֵ����Ҫȱ���ǶԳ�ʼֵ����,�㷨�����������ֲ���.
// ��������������,ģ��ϵ����ȷ��.
