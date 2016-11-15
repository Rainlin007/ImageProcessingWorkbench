#pragma once
#include "afxshelltreectrl.h"
namespace  RNV
{
	class RCMFCShellTreeCtrl :
		public CMFCShellTreeCtrl
	{
	public:
		RCMFCShellTreeCtrl();
		~RCMFCShellTreeCtrl();
		DECLARE_MESSAGE_MAP()
		afx_msg void OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult);
	};
}

using namespace RNV;
