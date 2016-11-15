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
		static void RImageProcessing::GaussDistribution256(float *data,float u, float d=25);//data为256元素数组，u为均值，d为方差
		static void EightGray(Mat & data);
	


	public: //assistance
		static void HistogramImage(int* his,Mat& hisGra);
	
	};

}
