#include "stdafx.h"
#include "RConnectionNode.h"


RConnectionNode::RConnectionNode(bool isAdded)
{
	if (isAdded)
		AddSelf();
}
RConnectionNode::~RConnectionNode()
{
	rc->RemoveNode(this);
}

//virtual int HandleMessage(RConnectionMessageType, void*);


int RConnectionNode::HandleMessage(RConnectionMessageType type, void* pData)
{
	return 0;
}

void RConnectionNode::AddSelf()
{
	rc->AddNode(this);
}