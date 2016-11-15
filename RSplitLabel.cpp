#include "stdafx.h"
#include "RSplitLabel.h"


RSplitLabel::RSplitLabel()
{
	m_TextColor = RGB(0, 0, 0);
	m_BackColor = TRANS_BACK;
}


RSplitLabel::~RSplitLabel()
{
}
BEGIN_MESSAGE_MAP(RNV::RSplitLabel, CStatic)
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR_REFLECT()
END_MESSAGE_MAP()


HBRUSH RNV::RSplitLabel::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CStatic::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here

	// TODO:  Return a different brush if the default is not desired
	return hbr;
}


BOOL RNV::RSplitLabel::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default

	return CStatic::OnEraseBkgnd(pDC);
}


HBRUSH RNV::RSplitLabel::CtlColor(CDC* pDC, UINT nCtlColor)
{
	m_Brush.DeleteObject();

	if (m_BackColor == TRANS_BACK) {
		m_Brush.CreateStockObject(HOLLOW_BRUSH);
		pDC->SetBkMode(TRANSPARENT);
	}
	else {
		m_Brush.CreateSolidBrush(m_BackColor);
		pDC->SetBkColor(m_BackColor);
	}

	pDC->SetTextColor(m_TextColor);

	return (HBRUSH)m_Brush;
}

void RNV::RSplitLabel::UpdateCtrl()
{
	CWnd* pParent = GetParent();
	CRect rect;

	GetWindowRect(rect);
	pParent->ScreenToClient(rect);
	rect.DeflateRect(2, 2);

	pParent->InvalidateRect(rect, FALSE);
}

