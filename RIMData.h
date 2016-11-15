#pragma once
#include <opencv2/opencv.hpp>
using namespace cv;
namespace RIP
{
	class RImData
	{
	private:
		RImData();
		static RImData *self;


	public:
		Mat mData;
		Mat mDataOrg;
		CImage mImage;

	public:
		
		~RImData();
		void UpdateShow();
		static RImData* GetInstance();
		void Clear();
	};
}

using namespace RIP;

