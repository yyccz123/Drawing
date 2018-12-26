#pragma once
#include<afx.h>
#include<afxwin.h>

enum ElementType { NOTSET, SQUARE, RECTANGLE, CIRCLE, ELLIPSE, TRIANGLE, TEXT };

/*������ CShape*/
class CShape : public CObject
{
public:
	CShape(ElementType type, int orgX, int orgY);
	CShape(ElementType type, int orgX, int orgY, COLORREF borderColor, int borderType, int borderWidth, COLORREF fillColor, int fillType);
	virtual void Draw(CDC * pDC) = 0;
	virtual bool IsMatched(CPoint pnt) = 0;

protected:
	ElementType Type;
	int OrgX;
	int OrgY;
	COLORREF BorderColor = RGB(0, 0, 0);
	int BorderType = 0;
	int BorderWidth = 0;
	COLORREF FillColor = RGB(0, 0, 0);
	int FillType = 6;

private:

};

/*��������*/
class CSquare :public CShape
{
public:
	CSquare();
	CSquare(int orgX, int orgY, int width);
	CSquare(int orgX, int orgY, int width, COLORREF borderColor, int borderType, int borderWidth, COLORREF fillColor, int fillType);
	virtual void Draw(CDC * pDC);
	virtual bool IsMatched(CPoint pnt);
	virtual void Serialize(CArchive &ar);
private:
	int width;
	DECLARE_SERIAL(CSquare)
};

/*Բ��*/
class CCircle :public CShape
{
public:
	CCircle();
	CCircle(int orgX, int orgY, int radius);
	CCircle(int orgX, int orgY, int radius, COLORREF borderColor, int borderType, int borderWidth, COLORREF fillColor, int fillType);

	virtual void Draw(CDC * pDC);
	virtual bool IsMatched(CPoint pnt);
	virtual void Serialize(CArchive &ar);

private:
	int radius;
};

/*����*/
class CRectangle :public CShape
{
public:
	CRectangle();
	CRectangle(int orgX, int orgY, int width, int height);
	CRectangle(int orgX, int orgY, int width, int height, COLORREF borderColor, int borderType, int borderWidth, COLORREF fillColor, int fillType);

	virtual void Draw(CDC * pDC);
	virtual bool IsMatched(CPoint pnt);
	virtual void Serialize(CArchive &ar);

private:
	int width;
	int height;
};

/*������*/
class CTriangle :public CShape
{
public:
	CTriangle();
	CTriangle(int orgX, int orgY, int width);
	CTriangle(int orgX, int orgY, int width, COLORREF borderColor, int borderType, int borderWidth, COLORREF fillColor, int fillType);

	virtual void Draw(CDC * pDC);
	virtual bool IsMatched(CPoint pnt);
	virtual void Serialize(CArchive &ar);

private:
	int width;
};

/*�ı�*/
class CText :public CShape
{
public:
	CText();
	CText(int orgX, int orgY, CString text, int height, int angle);
	CText(int orgX, int orgY, CString text, int height, int angle,COLORREF borderColor, int borderType, int borderWidth, COLORREF fillColor, int fillType);

	virtual void Draw(CDC * pDC);
	virtual bool IsMatched(CPoint pnt);
	virtual void Serialize(CArchive &ar);

private:
	CString text;
	int height;
	int angle;
};


/*��Բ*/
class CEllipse :public CShape
{
public:
	CEllipse();
	CEllipse(int orgX, int orgY, int width, int height);
	CEllipse(int orgX, int orgY, int width, int height, COLORREF borderColor, int borderType, int borderWidth, COLORREF fillColor, int fillType);


	virtual void Draw(CDC * pDC);
	virtual bool IsMatched(CPoint pnt);
	virtual void Serialize(CArchive &ar);

private:
	int width;
	int height;
};
