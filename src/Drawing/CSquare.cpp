#include "stdafx.h"
#include "util.h"
#include "CSquare.h"

IMPLEMENT_SERIAL(CSquare, CObject, 1)

CSquare::CSquare()
	: CShape(SQUARE, 0, 0), width(100)
{

}

CSquare::CSquare(const CSquare & square) : CShape(square)
{
	square.GetShapeValue(NULL, NULL, NULL, &width);
}

CSquare::CSquare(int orgX, int orgY, int width)
	: CShape(SQUARE, orgX, orgY), width(width)
{
}

CSquare::CSquare(int orgX, int orgY, int width, COLORREF fillColor, int fillType, COLORREF borderColor, int borderWidth, int borderType)
	: CShape(SQUARE, orgX, orgY, fillColor, fillType, borderColor, borderWidth, borderType), width(width)
{
}

bool CSquare::IsMatched(CPoint pnt)
{
	// X �᷽��ľ���ƫ��������
	long abs_offsetX = abs(pnt.x - OrgX);
	// Y �᷽��ľ���ƫ��������
	long abs_offsetY = abs(pnt.y - OrgY);

	double half_of_width = width / 2.0;

	return abs_offsetX <= half_of_width && abs_offsetY <= half_of_width;
}

void CSquare::Serialize(CArchive & ar)
{
	if (ar.IsStoring())
	{
		ar << width;
	}
	else
	{
		ar >> width;
	}
	CShape::Serialize(ar);
}

void CSquare::SetShapeValue(ElementType type, int orgX, int orgY, int width)
{
	CShape::SetShapeValue(type, orgX, orgY);
	this->width = width;
}

void CSquare::GetShapeValue(ElementType * type, int * orgX, int * orgY, int *width) const
{
	CShape::GetShapeValue(type, orgX, orgY);
	PTR_ASSIGN(width, this->width);
}

void CSquare::ToDraw(CDC * pDC)
{
	pDC->Rectangle(OrgX - width / 2, OrgY - width / 2, OrgX + width / 2, OrgY + width / 2);
}