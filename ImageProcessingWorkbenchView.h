// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// ImageProcessingWorkbenchView.h : interface of the CImageProcessingWorkbenchView class
//

#pragma once

#include "RConnection.h"
#include "ImageProcessingWorkbenchDoc.h"
#include "RImData.h"

#include "RSplitLabel.h"
class CImageProcessingWorkbenchView : public CScrollView, public RConnectionNode
{
protected: // create from serialization only
	CImageProcessingWorkbenchView();
	DECLARE_DYNCREATE(CImageProcessingWorkbenchView)

// Attributes
public:
	CImageProcessingWorkbenchDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CImageProcessingWorkbenchView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnButtonTest();


public:

	RSplitLabel cs;





public:
	virtual int HandleMessage(RConnectionMessageType, void*);

	afx_msg void OnHisbalance();
	afx_msg void OnGray();
//	afx_msg void OnSize(UINT nType, int cx, int cy);
//	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
	virtual void OnInitialUpdate();
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
//	virtual BOOL OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll = TRUE);
//	afx_msg void OnDestroy();
	afx_msg void OnHistogram();
	afx_msg void OnHistospec();
	afx_msg void OnEightgray();
};

#ifndef _DEBUG  // debug version in ImageProcessingWorkbenchView.cpp
inline CImageProcessingWorkbenchDoc* CImageProcessingWorkbenchView::GetDocument() const
   { return reinterpret_cast<CImageProcessingWorkbenchDoc*>(m_pDocument); }
#endif
