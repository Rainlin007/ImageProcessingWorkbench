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

// ImageProcessingWorkbenchView.cpp : implementation of the CImageProcessingWorkbenchView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ImageProcessingWorkbench.h"
#endif

#include "ImageProcessingWorkbenchDoc.h"
#include "ImageProcessingWorkbenchView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageProcessingWorkbenchView

IMPLEMENT_DYNCREATE(CImageProcessingWorkbenchView, CScrollView)

BEGIN_MESSAGE_MAP(CImageProcessingWorkbenchView, CScrollView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CImageProcessingWorkbenchView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_BUTTON_TEST, &CImageProcessingWorkbenchView::OnButtonTest)
	ON_COMMAND(ID_HISBALANCE, &CImageProcessingWorkbenchView::OnHisbalance)
	ON_COMMAND(ID_GRAY, &CImageProcessingWorkbenchView::OnGray)
//	ON_WM_SIZE()
//	ON_WM_SIZING()
//	ON_WM_CREATE()
//	ON_WM_DESTROY()
ON_COMMAND(ID_HISTOGRAM, &CImageProcessingWorkbenchView::OnHistogram)
ON_COMMAND(ID_HISTOSPEC, &CImageProcessingWorkbenchView::OnHistospec)
ON_COMMAND(ID_EIGHTGRAY, &CImageProcessingWorkbenchView::OnEightgray)
END_MESSAGE_MAP()

// CImageProcessingWorkbenchView construction/destruction
CImageProcessingWorkbenchView::CImageProcessingWorkbenchView():RConnectionNode()
{
	// TODO: add construction code here


	
}

CImageProcessingWorkbenchView::~CImageProcessingWorkbenchView()
{
}

BOOL CImageProcessingWorkbenchView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// CImageProcessingWorkbenchView drawing

void CImageProcessingWorkbenchView::OnDraw(CDC* pDC)
{
	CImageProcessingWorkbenchDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	RImData*rm = RImData::GetInstance();
	if (rm->mImage.IsNull() ==false)
	{
		rm->mImage.Draw(pDC->m_hDC, CRect(0, 0, rm->mImage.GetWidth(), rm->mImage.GetHeight()));
		SetScrollSizes(MM_TEXT, CSize(rm->mImage.GetWidth(), rm->mImage.GetHeight()));
	}
	
	/*
	CString t;
	t.Format(_T("%d %d"), splitR,splitC);
	pDC->DrawText(t, new CRect(0, 0, 50, 50),0);*/
	// TODO: add draw code for native data here
}


// CImageProcessingWorkbenchView printing


void CImageProcessingWorkbenchView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CImageProcessingWorkbenchView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CImageProcessingWorkbenchView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CImageProcessingWorkbenchView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CImageProcessingWorkbenchView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CImageProcessingWorkbenchView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CImageProcessingWorkbenchView diagnostics

#ifdef _DEBUG
void CImageProcessingWorkbenchView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CImageProcessingWorkbenchView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CImageProcessingWorkbenchDoc* CImageProcessingWorkbenchView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageProcessingWorkbenchDoc)));
	return (CImageProcessingWorkbenchDoc*)m_pDocument;
}
#endif //_DEBUG


// CImageProcessingWorkbenchView message handlers

#include "RImageProcessing.h"
void CImageProcessingWorkbenchView::OnButtonTest()
{
	// TODO: Add your command handler code here
	AfxMessageBox(_T("hello"));
}



#include "MainFrm.h"


int CImageProcessingWorkbenchView::HandleMessage(RConnectionMessageType t, void* v)
{
	CString s;
	switch (t)
	{
	case RAL::NEW_DOCUMENT:
	case RAL::MIANVIEWUPDATE:
		Invalidate();
		break;
	case CREATE_NEWMAINVIEW:
		
		break;
	default:
		break;
	}
	return 0;
}

void CImageProcessingWorkbenchView::OnHisbalance()
{
	// TODO: Add your command handler code here
	int his[256];
	RImageProcessing::HisEqua(RImData::GetInstance()->mData,his);
	RImData::GetInstance()->UpdateShow();
}


void CImageProcessingWorkbenchView::OnGray()
{
	// TODO: Add your command handler code here
	RImageProcessing::Gray(RImData::GetInstance()->mData);
	RImData::GetInstance()->UpdateShow();
}


//void CImageProcessingWorkbenchView::OnSize(UINT nType, int cx, int cy)
//{
//	
//	
//	//CPoint cp = this->GetScrollPosition();
//	//CRect rc;
//	//this->GetClientRect(&rc);
//	//cs.SetWindowPos(this, cp.x, cp.y,20,20,0);
//
//
//	__super::OnSize(nType, cx, cy);
//	// TODO: Add your message handler code here
//}


//void CImageProcessingWorkbenchView::OnSizing(UINT fwSide, LPRECT pRect)
//{
//
//	__super::OnSizing(fwSide, pRect);
//	// TODO: Add your message handler code here
//	
//}


void CImageProcessingWorkbenchView::OnInitialUpdate()
{
	__super::OnInitialUpdate();
	SetScrollSizes(MM_TEXT, CSize(800, 600));
	// TODO: Add your specialized code here and/or call the base class
	
}


//int CImageProcessingWorkbenchView::OnCreate(LPCREATESTRUCT lpCreateStruct)
//{
//	if (__super::OnCreate(lpCreateStruct) == -1)
//		return -1;
//	//AfxMessageBox(_T("create"));
//	// TODO:  Add your specialized creation code here
//	/*cs.Create(_T(""), WS_CHILD | WS_VISIBLE | WS_TABSTOP, CRect(100, 100, 150, 150), this, 0);
//	cs.SetBackColor(TRANS_BACK);
//	cs.SetTextColor(RGB(0,0,0));*/
//	//RConnection::getInstance()->NotifyALLNode(RConnectionMessageType::CREATE_NEWMAINVIEW,0);
//	return 0;
//}


//BOOL CImageProcessingWorkbenchView::OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll)
//{
//	// TODO: Add your specialized code here and/or call the base class
//
//
//
//	CPoint cp = this->GetScrollPosition();
//	CRect rc;
//	this->GetClientRect(&rc);
//	//cs.SetWindowPos(this, cp.x + rc.Width() - 20, cp.y + rc.Height() - 20, 20, 20, 0);
//	//cs.SetWindowPos(this, cp.x, cp.y, 20, 20, 0);
//	return __super::OnScroll(nScrollCode, nPos, bDoScroll);
//}


//void CImageProcessingWorkbenchView::OnDestroy()
//{
//	__super::OnDestroy();
//	// TODO: Add your message handler code here
//}


void CImageProcessingWorkbenchView::OnHistogram()
{
	// TODO: Add your command handler code here
	Mat t;
	int his[256];
	RImageProcessing::Histogram(RImData::GetInstance()->mData,his);
	RImageProcessing::HistogramImage(his,t);
	imshow("Ö±·½Í¼", t);
}


void CImageProcessingWorkbenchView::OnHistospec()
{
	// TODO: Add your command handler code here
	float t[256];
	int u = 128;
	RImageProcessing::GaussDistribution256(t, 50,100);
	RImageProcessing::HisSpec(RImData::GetInstance()->mData,t);


	RImData::GetInstance()->UpdateShow();

}


void CImageProcessingWorkbenchView::OnEightgray()
{
	// TODO: Add your command handler code here

	RImageProcessing::EightGray(RImData::GetInstance()->mData);
	RImData::GetInstance()->UpdateShow();

}
