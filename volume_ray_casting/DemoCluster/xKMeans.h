//  *****************************************************************
//	xKMeans       version: 1.0 	
//  ----------------------------------------------------------------
//  Purpose:    A simple implementation of K-Means Cluster Algorithm
//	Author:		JH Wu [ jh.wu@siat.ac.cn ]
//  Date:       2010/07/30  10:11
//	----------------------------------------------------------------
//	Copyright (c) 2010 - All Rights Reserved
//
//  Center for Human-Computer Interaction,
//  Shenzhen Institute of Advanced Integration Technology, 
//  Chinese Academy of Sciences/The Chinese University of Hong Kong
//  *****************************************************************
//
//  *****************************************************************
#pragma once

#include "xCluster.h"

class CxKMeans:public CxCluster
{	
protected:

//	virtual void  DistributeSamples();    // Step 2 ���ݻ���
	virtual bool  CalNewClusterCenters(); // Step 3 ���¼����µ���������;
    virtual double CalFitCost();

public:

	CxKMeans(int nPattern, int nDim, int nCluster):
	         CxCluster(nPattern, nDim, nCluster){}

	~CxKMeans(void) {}
	
  	void   InitClusters();          // Step 1 �����ʼ��K������;

//	int    Run(double epislon = EPISLON);
//	double Run(int nIter);
	
};
// Note:
// K-Means�����㷨�Ľ���ܵ��������ĸ����Լ���ʼ�������ĵ�ѡ��Ӱ��,
// Ҳ�յ���Ʒ�������ʼ����д���Ӱ��.�����Ʒ�ļ������Ա������γɼ���
// ��Զ��С������������㷨��������.
// end.