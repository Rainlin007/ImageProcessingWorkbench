#include "stdafx.h"
#include "RIMData.h"
#include "RConnection.h"
#include "RUtil.h"
RImData::RImData()
{
}


RImData::~RImData()
{
}

void RImData::UpdateShow()
{
	RUtil::MatToCImage(mData, mImage);
	RConnection::getInstance()->NotifyALLNode(RConnectionMessageType::MIANVIEWUPDATE, 0);
}

RImData* RImData::GetInstance()
{
	if (RImData::self == 0)
		RImData::self = new RImData();
	return self;
}



void RImData::Clear()
{
	if(self!=0)
		delete self;
	self = 0;
}



RImData * RImData::self = 0;
