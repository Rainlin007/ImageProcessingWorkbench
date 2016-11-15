#pragma once
#include "afxwin.h"
namespace RNV
{
	#define TRANS_BACK -1
	class RSplitLabel :
		public CStatic
	{
	public:
		RSplitLabel();
		~RSplitLabel();
		DECLARE_MESSAGE_MAP()
		afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
		afx_msg BOOL OnEraseBkgnd(CDC* pDC);
		afx_msg HBRUSH RNV::RSplitLabel::CtlColor(CDC* pDC, UINT nCtlColor);


	private:
		COLORREF m_TextColor;
		COLORREF m_BackColor;
		CBrush   m_Brush;

		// Operations
	public:
		void SetTextColor(COLORREF col) {
			m_TextColor = col;
			UpdateCtrl();
		}
		void SetBackColor(COLORREF col) {
			m_BackColor = col;
			UpdateCtrl();
		}

	private:
		void UpdateCtrl();
	protected:
		//{{AFX_MSG(CStaticTrans)
		//}}AFX_MSG

	public:
		
	};

}

using namespace RNV;

