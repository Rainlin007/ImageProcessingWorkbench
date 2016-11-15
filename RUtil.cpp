#include "stdafx.h"
#include "RUtil.h"


RUtil::RUtil()
{
}


RUtil::~RUtil()
{
}



void RUtil::CStringTostring(CString& m_str, string &str)
{
	char *chr = new char[m_str.GetLength() + 1];
	WideCharToMultiByte(CP_ACP, 0, m_str.GetBuffer(), -1, chr, m_str.GetLength() + 1, NULL, NULL);
	str = chr;
}




void RUtil::MatToCImage(Mat& mat, CImage& cImage)
{
	int width = mat.cols;
	int height = mat.rows;
	int channels = mat.channels();

	cImage.Destroy();//��һ���Ƿ�ֹ�ظ���������ڴ�����  
	cImage.Create(width, height, 8 * channels);

	uchar* ps;
	uchar* pimg = (uchar*)cImage.GetBits(); //��ȡCImage�����ش�������ָ��  
	int step = cImage.GetPitch();//ÿ�е��ֽ���,ע���������ֵ�����и�  

								 // �����1��ͨ����ͼ��(�Ҷ�ͼ��) DIB��ʽ����Ҫ�Ե�ɫ������    
								 // CImage�������˵�ɫ�壬����Ҫ�������и�ֵ��  
	if (1 == channels)
	{
		RGBQUAD* ColorTable;
		int MaxColors = 256;
		//�������ͨ��CI.GetMaxColorTableEntries()�õ���С(�������CI.Load����ͼ��Ļ�)    
		ColorTable = new RGBQUAD[MaxColors];
		cImage.GetColorTable(0, MaxColors, ColorTable);//������ȡ��ָ��    
		for (int i = 0; i<MaxColors; i++)
		{
			ColorTable[i].rgbBlue = (BYTE)i;
			//BYTE��ucharһ���£���MFC�ж�����    
			ColorTable[i].rgbGreen = (BYTE)i;
			ColorTable[i].rgbRed = (BYTE)i;
		}
		cImage.SetColorTable(0, MaxColors, ColorTable);
		delete[]ColorTable;
	}


	for (int i = 0; i < height; i++)
	{
		ps = mat.ptr<uchar>(i);
		for (int j = 0; j < width; j++)
		{
			if (1 == channels)
			{
				*(pimg + i*step + j) = ps[j];
				//*(pimg + i*step + j) = 105;  
			}
			else if (3 == channels)
			{
				*(pimg + i*step + j * 3) = ps[j * 3];
				*(pimg + i*step + j * 3 + 1) = ps[j * 3 + 1];
				*(pimg + i*step + j * 3 + 2) = ps[j * 3 + 2];
			}
		}
	}
}