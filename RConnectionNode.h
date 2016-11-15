#pragma once
#include "stdafx.h"
#include "RConnection.h"



namespace RAL {
	class RConnection;
	enum RConnectionMessageType;


	class RConnectionNode
	{
		friend class RConnection;
	public:
		static RConnection *rc;
		RConnectionNode(bool isAdded=true);
		~RConnectionNode();
		void AddSelf();
	protected:
		virtual int HandleMessage(RConnectionMessageType, void*);
	};
}