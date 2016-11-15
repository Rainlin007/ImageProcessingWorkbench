#include "stdafx.h"
#include "RCMFCShellTreeCtrl.h"
#include "RImData.h"

RCMFCShellTreeCtrl::RCMFCShellTreeCtrl()
{
	this->SetFlags((SHCONTF)(SHCONTF_FOLDERS | SHCONTF_NONFOLDERS));
}


RCMFCShellTreeCtrl::~RCMFCShellTreeCtrl()
{
}
BEGIN_MESSAGE_MAP(RNV::RCMFCShellTreeCtrl, CMFCShellTreeCtrl)
	ON_NOTIFY_REFLECT(NM_DBLCLK, &RCMFCShellTreeCtrl::OnNMDblclk)
END_MESSAGE_MAP()

#include "RUtil.h"
#include "MainFrm.h"
void RNV::RCMFCShellTreeCtrl::OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
	CString t,m,n;
	GetItemPath(t,GetParentItem(this->GetSelectedItem()));
	if (t.GetLength() != 0)
	{
		CString k;
		if (t[t.GetLength() - 1]!=_T('\\'))
		{
			k = _T("\\");
		}
		t += k + GetItemText(this->GetSelectedItem());
	}
	m = PathFindExtension(t);
	GetItemPath(n, GetSelectedItem());
	RImData *rm = RImData::GetInstance();
	if (n==_T(""))
	{
		if (AfxMessageBox(_T("是否打开 ") + GetItemText(GetSelectedItem()) + _T(" ？"), MB_OKCANCEL) == IDOK)
		{
			std::string m;
			RUtil::CStringTostring(t, m);
			rm->mData= imread(m);
			rm->mDataOrg = rm->mData.clone();
			if (rm->mData.empty())
			{
				AfxMessageBox(_T("打开失败！"));
			}
			else
			{
				rm->UpdateShow();
				CString t(GetItemText(GetSelectedItem()));
				RConnection::getInstance()->NotifyALLNode(RConnectionMessageType::OPEN_NEW_IMAGE, &t);


				RConnection::getInstance()->NotifyALLNode(RConnectionMessageType::MIANVIEWUPDATE, 0);
			}
		}
	}

}
