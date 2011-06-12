//  *************************************************************************
//	xClusterFilter       version: 1.0 	
//  -------------------------------------------------------------------------
//  Purpose:    �����㷨��
//	Author:		JH Wu [ jh.wu@siat.ac.cn ; jianhuang.wu@gmail.com ]
//  Date:       2010/08/05  15:49
//	-------------------------------------------------------------------------
//	Copyright (c) 2010 - All Rights Reserved
//
//  Center for Human-Computer Interaction,
//  Shenzhen Institutes of Advanced Technology, Chinese Academy of Sciences
//  *************************************************************************
//
//  *************************************************************************
#pragma once



// The following ifdef block is the standard way of creating macros 
// which make exporting from a DLL simpler. All files within this DLL 
// are compiled with the FILTER_EXPORTS symbol defined on the command line. 
// this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include 
// this file see FILTER_API functions as being imported from a DLL, 
// whereas this DLL sees symbols defined with this macro as being exported.

#ifdef CLUSTER_FILTER_EXPORTS
#define WUJH_CLUSTER_FILTER_API __declspec(dllexport)
#else
#define WUJH_CLUSTER_FILTER_API __declspec(dllimport)
#endif


#include <vector>
using std::vector;
#pragma warning(push)
#pragma warning(disable:4251)


struct Sample  // ����;
{
	vector<double> pattern;
};

struct Group  // ����;
{
	vector<double> center; // ��������;
	vector<int>    member; // Index of data belonging to this cluster
};

const double cERROR = 0.000001;

enum {KMEANS = 0,      // K��ֵ;
      FUZZY_CMEANS,    // ģ��C��ֵ;
      PSO_CLUSTER,     // ����Ⱥ����
      PSO_KMEANS,      // ��������Ⱥ�Ż���K��ֵ;
      PSO_FUZZY_CMEANS // ��������Ⱥ�Ż���ģ��C��ֵ; 
     };

class WUJH_CLUSTER_FILTER_API CxClusterFilter
{
public:
	CxClusterFilter(void);
	~CxClusterFilter(void);

	int m_nCluster;   // �ֳɼ���;

	int m_nParticle;  // �����ѡ���3������Ⱥ�����㷨,
	                  // ����Ҫ�������ӵĸ���;

	vector<Sample> m_ArraySample;  // �洢�����������;
	vector<Group>  m_ArrayGroup;   // �洢������;

	double Run(int nMethod = KMEANS, int nIter = 200);       // ���ؾ���׼�����;
	double Run(int nMethod = KMEANS, double error = cERROR); // ���ؾ���׼�����;

};

#pragma warning(pop)
