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
		TRACE0("δ�ܴ�����������\n");
		return -1;      // δ�ܴ���
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
	// TODO: �ڴ˴������Ϣ����������
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
	CMFCPropertyGridProperty* pGroup = new CMFCPropertyGridProperty(_T("ͼ������"));
	CString	 t;
	ImageProperty[0]=new  CMFCPropertyGridProperty(_T("�߶ȣ�"), (_variant_t)0, _T("����"));
	ImageProperty[1] = new  CMFCPropertyGridProperty(_T("��ȣ�"), (_variant_t)0, _T("����"));

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
	// TODO: �ڴ˴������Ϣ����������
	//CMenu   menu;
	//menu.LoadMenu(IDR_PROPERTY);//���ز˵���Դ 
	//CMenu*   pPopup = menu.GetSubMenu(0);
	//ASSERT(pPopup != NULL);
	//pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON, point.x, point.y, this); //����굱ǰλ�õ����˵�
}
