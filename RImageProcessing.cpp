#include "stdafx.h"
#include "RImageProcessing.h"
#include "RImData.h"
#include <math.h>
RImageProcessing::RImageProcessing()
{
}


RImageProcessing::~RImageProcessing()
{
}



void RImageProcessing::HisEqua(Mat &mData,int *T)
{
	int his[256];
	Histogram(mData, his);
	int k = 0;
	int M = mData.rows;
	int N = mData.cols;
	int MN = M*N;
	for (int i = 0; i < 256; i++)
	{
		k += his[i];
		T[i] = (255.0f / MN)*k;
	}
	auto t = mData.begin<Vec3b>();
	while (t != mData.end<Vec3b>())
	{
		(*t)[0] = T[(*t)[0]];
		(*t)[1] = T[(*t)[1]];
		(*t)[2] = T[(*t)[2]];
		t++;
	}
}

void RImageProcessing::Gray(Mat &data)
{
	Mat mData = data;
	auto t = mData.begin<Vec3b>();
	while (t != mData.end<Vec3b>())
	{
		uchar k = ((*t)[0] + (*t)[1] + (*t)[2]) / 3;
		(*t)[0] = k;
		(*t)[1] = k;
		(*t)[2] = k;
		t++;
	}
}

void RImageProcessing::Histogram(Mat &mData, int* his)
{
	memset(his, 0, sizeof(int) * 256);
	int max = 0;
	auto t = mData.begin<Vec3b>();
	while (t != mData.end<Vec3b>())
	{
		his[(*t)[0]]++;
		t++;
	}
}

void RImageProcessing::HisSpec(Mat & mData,float *hisSpe)
{
	int T[256], his[256];
	Mat m;
	Histogram(mData,his);
	int k = 0;
	int M = mData.rows;
	int N = mData.cols;
	int MN = M*N;
	for (int i = 0; i < 256; i++)
	{
		k += his[i];
		T[i] = (255.0f / MN)*k;
	}
	int GR[256],G[256],S[256];
	float z=0;
	int  q = 0;;
	for (int i = 0; i < 256; i++)
	{
		z += hisSpe[i];
		G[i] = 255 * z;
	}
	GR[0] = 0;
	for (int i=1;i<256;i++)
	{
		if (G[q]> i)
			GR[i] = GR[i - 1];
		else
		{
			
			GR[i] = ++q;
		}
	}
	for (int i = 0; i < 256; i++)
		S[i] = GR[T[i]];

	long p=0;
	auto t = mData.begin<Vec3b>();
	while (t != mData.end<Vec3b>())
	{
		(*t)[0] = S[(*t)[0]];
		(*t)[1] = S[(*t)[1]];
		(*t)[2] = S[(*t)[2]];
		p += (*t)[0];
		t++;
	}

	CString cs;
	cs.Format(_T("%d"), p/MN);

	AfxMessageBox(cs);


}

#define PI 3.1415926
void RImageProcessing::GaussDistribution256(float *data, float u, float d)
{
	float t = 0;
	for (int i=0;i<256;i++)
	{
		data[i]=1 / sqrt(2 * PI*d)*exp(-(i - u)*(i - u) / (2 * d));
		t += data[i];
	}
	for (int i = 0; i < 256; i++)
	{
		data[i] /= t;
	}
}

void RImageProcessing::EightGray(Mat & mData)
{
	auto t = mData.begin<Vec3b>();
	while (t != mData.end<Vec3b>())
	{
		int i = 0;
		uchar m = 0x80;
		for (i = 0; ((*t)[0]&m)==0; i++);
		{
			m <<= 1;
		}
		(*t)[2]=(*t)[1]=(*t)[0] = ((*t)[0] & m);
		t++;
	}
}



void RImageProcessing::HistogramImage(int* his, Mat& hisGra)
{
	int max = 0;
	for (int i = 0; i < 256; i++)
		max < his[i] ? max = his[i] : 0;
	Mat ima(300, 300, CV_8UC3);
	line(ima, Point(15, 285), Point(285, 285), Scalar(0, 0, 0));
	line(ima, Point(15, 285), Point(15, 15), Scalar(0, 0, 0));
	for (int i = 0; i < 256; i++)
	{
		line(ima, Point(15 + i, 285), Point(15 + i, 285 - 256 * ((his[i] + 0.0f) / max)), Scalar(0, 255, 255));
	}
	hisGra = ima;
}