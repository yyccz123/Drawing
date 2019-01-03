﻿
// DrawingDoc.cpp: CDrawingDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Drawing.h"
#endif

#include "DrawingDoc.h"

#include <propkey.h>
#include "CShape.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CDrawingDoc

IMPLEMENT_DYNCREATE(CDrawingDoc, CDocument)

BEGIN_MESSAGE_MAP(CDrawingDoc, CDocument)
END_MESSAGE_MAP()

// CDrawingDoc 构造/析构

CDrawingDoc::CDrawingDoc() noexcept
{
	// TODO: 在此添加一次性构造代码
}

CDrawingDoc::~CDrawingDoc()
{
	this->DeleteContents();
}

void CDrawingDoc::DeleteContents()
{
	// 遍历图元对象指针数组
	for (int i = 0; i < m_Elements.GetSize(); i++)
	{
		// 直接释放对象指针指向的对象
		delete m_Elements[i];
	}
	// 清空图元对象指针数组
	m_Elements.RemoveAll();

	CDocument::DeleteContents();
}

BOOL CDrawingDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}

// CDrawingDoc 序列化

void CDrawingDoc::Serialize(CArchive &ar)
{
	// 当CArchive对象状态为储存时
	if (ar.IsStoring())
	{
		m_Elements.Serialize(ar);
	}
	else
	{
		m_Elements.Serialize(ar);
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CDrawingDoc::OnDrawThumbnail(CDC &dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont *pDefaultGUIFont = CFont::FromHandle((HFONT)GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont *pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CDrawingDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CDrawingDoc::SetSearchContent(const CString &value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CDrawingDoc 诊断

#ifdef _DEBUG
void CDrawingDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDrawingDoc::Dump(CDumpContext &dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

// CDrawingDoc 命令
