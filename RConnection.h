#pragma once
#include "RConnectionNode.h"
#include <list>
#include <string>
using namespace std;
namespace RAL {


	class RConnectionNode;

	enum RConnectionMessageType
	{
		INIT,
		MIANVIEWUPDATE,
		NEW_DOCUMENT,
		CREATE_NEWMAINVIEW,
		OPEN_NEW_IMAGE,
		OUTPUT_DATA								//²ÎÊýÎªCString*
	};

	class RConnection
	{
	private:
		list<RConnectionNode*> mData;
		static RConnection* instance;
	public:
		static RConnection* getInstance();
		RConnection();
		~RConnection();

		void AddNode(RConnectionNode* node);
		void RemoveNode(RConnectionNode*id);
		void NotifyALLNode(RConnectionMessageType rt, void* content);

	};
}
using namespace RAL;


