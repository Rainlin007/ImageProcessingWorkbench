#include "stdafx.h"
#include "RConnection.h"
using namespace RAL;


RConnection* RConnection::getInstance()
{
	if (instance == NULL)   instance = new RConnection();
	return instance;
}
RConnection::RConnection() 
{ 
	RConnectionNode::rc = this; 
}
RConnection::~RConnection() 
{
}

void RConnection::AddNode( RConnectionNode* node) { mData.push_back(node); }
void RConnection::RemoveNode(RConnectionNode* id)
{ 
	auto t = mData.begin();
	while (t!=mData.end())
	{
		if (*t == id)
		{
			mData.erase(t);
			break;
		}
		t++;
	}
}
void RConnection::NotifyALLNode(RConnectionMessageType rt, void* content)
{
	auto t = mData.begin();
	while (t != mData.end())
	{
		(*t)->HandleMessage(rt, content);
		t++;
	}
}

RConnection* RConnection::instance = 0;
RConnection * RConnectionNode::rc = NULL;
