#pragma once
#include <string>
#include <opencv2/opencv.hpp>
using namespace std; 
using namespace cv;
namespace RAL
{
	class RUtil
	{
	private:
		RUtil();
		~RUtil();
	public:
		static void CStringTostring(CString&, std::string &);
		static void MatToCImage(Mat& mat, CImage& cImage);
	};
}
using namespace RAL;