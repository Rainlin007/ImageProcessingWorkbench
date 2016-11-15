#pragma once
#include "afxdockablepane.h"
#include "RConnectionNode.h"
class CPropertyPane :
	public CDockablePane, public RConnectionNode
{
public:

	CMFCPropertyGridProperty* ImageProperty[2];
	CMFCPropertyGridProperty* guassiand[4];



	CFont m_fntPropList;




	CPropertyPane(void);
	~CPropertyPane(void);




	CMFCPropertyGridCtrl m_wndPropList;


	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);



	void CPropertyPane::SetPropListFont();
	void SetGaussian();
	void CPropertyPane::initPropertyList();




protected:
	virtual int HandleMessage(RConnectionMessageType, void*);
public:
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
};

