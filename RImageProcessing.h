#pragma once
#include <opencv2\opencv.hpp>
using namespace cv;
namespace RIP {}
using namespace RIP;

namespace RIP {
	class RImageProcessing
	{
	public:
		RImageProcessing();
		~RImageProcessing();
	public: //------Image Processing Algorithm
		static void Gray(Mat & data);
		static void HisEqua(Mat & data,int *his);
		static void RImageProcessing::Histogram(Mat& mData,int* his);
		static void RImageProcessing::HisSpec(Mat& data,float *hisSpe);
		static void RImageProcessing::GaussDistribution256(float *data,float u, float d=25);//dataΪ256Ԫ�����飬uΪ��ֵ��dΪ����
		static void EightGray(Mat & data);
	


	public: //assistance
		static void HistogramImage(int* his,Mat& hisGra);
	
	};

}
