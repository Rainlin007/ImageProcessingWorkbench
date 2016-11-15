#include "StdAfx.h"
#include "PropertyPane.h"
#include "RIMData.h"

CPropertyPane::CPropertyPane(void)
{
}


CPropertyPane::~CPropertyPane(void)
{
}
BEGIN_MESSAGE_MAP(CPropertyPane, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()


int CPropertyPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	CRect rectDummy;
	rectDummy.SetRectEmpty();

	if (!m_wndPropList.Create(WS_VISIBLE | WS_CHILD, rectDummy, this, 2))
	{
		TRACE0("未能创建属性网格\n");
		return -1;      // 未能创建
	}


	initPropertyList();



	return 0;
}


void CPropertyPane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);
	if (GetSafeHwnd() == NULL || (AfxGetMainWnd() != NULL && AfxGetMainWnd()->IsIconic()))
	{
		return;
	}

	CRect rectClient;
	GetClientRect(rectClient);
	m_wndPropList.SetWindowPos(NULL, -1, -1, cx, cy, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);
	// TODO: 在此处添加消息处理程序代码
}



void CPropertyPane::SetPropListFont()
{
	::DeleteObject(m_fntPropList.Detach());

	LOGFONT lf;
	afxGlobalData.fontRegular.GetLogFont(&lf);

	NONCLIENTMETRICS info;
	info.cbSize = sizeof(info);

	afxGlobalData.GetNonClientMetrics(info);

	lf.lfHeight = info.lfMenuFont.lfHeight;
	lf.lfWeight = info.lfMenuFont.lfWeight;
	lf.lfItalic = info.lfMenuFont.lfItalic;

	m_fntPropList.CreateFontIndirect(&lf);

	m_wndPropList.SetFont(&m_fntPropList);
}



int CPropertyPane::HandleMessage(RConnectionMessageType mt, void* ptr)
{
	switch (mt)
	{
	case RConnectionMessageType::OPEN_NEW_IMAGE:
		ImageProperty[0]->SetValue((_variant_t)RImData::GetInstance()->mDataOrg.rows);
		ImageProperty[1]->SetValue((_variant_t)RImData::GetInstance()->mDataOrg.cols);
		break;
	default:
		break;
	}
	return 0;
}


void CPropertyPane::SetGaussian()
{
	CMFCPropertyGridProperty* pGroup = new CMFCPropertyGridProperty(_T("图像属性"));
	CString	 t;
	ImageProperty[0]=new  CMFCPropertyGridProperty(_T("高度："), (_variant_t)0, _T("参数"));
	ImageProperty[1] = new  CMFCPropertyGridProperty(_T("宽度："), (_variant_t)0, _T("参数"));

	for (int i=0;i<2;i++)
	{
		ImageProperty[i]->AllowEdit(FALSE);
		pGroup->AddSubItem(ImageProperty[i]);
	}
	m_wndPropList.AddProperty(pGroup);


}

void CPropertyPane::initPropertyList()
{
	SetPropListFont();
	m_wndPropList.EnableHeaderCtrl(FALSE);
	m_wndPropList.EnableDescriptionArea();
	m_wndPropList.SetVSDotNetLook();
	m_wndPropList.MarkModifiedProperties();
	SetGaussian();
}
#include "resource.h"
void CPropertyPane::OnContextMenu(CWnd*  pWnd, CPoint  point)
{
	// TODO: 在此处添加消息处理程序代码
	//CMenu   menu;
	//menu.LoadMenu(IDR_PROPERTY);//加载菜单资源 
	//CMenu*   pPopup = menu.GetSubMenu(0);
	//ASSERT(pPopup != NULL);
	//pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON, point.x, point.y, this); //在鼠标当前位置弹出菜单
}
