#include "stdafx.h"

CRectD::CRectD(double l, double t, double r, double b)
{
	left = l;
	top = t;
	right = r;
	bottom = b;
}
//------------------------------------------------------------------------------
void CRectD::SetRectD(double l, double t, double r, double b)
{
	left = l;
	top = t;
	right = r;
	bottom = b;
}

//------------------------------------------------------------------------------
CSizeD CRectD::SizeD()
{
	CSizeD cz;
	cz.cx = fabs(right - left);	// ������ ������������� �������
	cz.cy = fabs(top - bottom);	// ������ ������������� �������
	return cz;
}

//----------------------------------------------------------------------------

CMatrix CreateTranslate2D(double dx, double dy)
// ��������� ������� ��� �������������� ��������� ������� ��� ��� �������� 
// �� dx �� ��� X � �� dy �� ��� Y � ������������� ������� ���������
// --- ��� ---
// ��������� ������� ��� �������������� ��������� ������� ��� �������� ������
// ������� ��������� �� -dx ��� X � �� -dy �� ��� Y ��� ������������� ��������� ������� 
{
	CMatrix TM(3, 3);
	TM(0, 0) = 1; TM(0, 2) = dx;
	TM(1, 1) = 1;  TM(1, 2) = dy;
	TM(2, 2) = 1;
	return TM;
}

//------------------------------------------------------------------------------------
CMatrix CreateRotate2D(double fi)
// ��������� ������� ��� �������������� ��������� ������� ��� ��� ��������
// �� ���� fi (��� fi>0 ������ ������� �������)� ������������� ������� ���������
// --- ��� ---
// ��������� ������� ��� �������������� ��������� ������� ��� �������� ������
// ������� ��������� �� ���� -fi ��� ������������� ��������� ������� 
// fi - ���� � ��������
{
	double fg = fmod(fi, 360.0);
	double ff = (fg / 180.0) * pi; // ������� � �������
	CMatrix RM(3, 3);
	RM(0, 0) = cos(ff); RM(0, 1) = -sin(ff);
	RM(1, 0) = sin(ff);  RM(1, 1) = cos(ff);
	RM(2, 2) = 1;
	return RM;
}


//------------------------------------------------------------------------------

CMatrix SpaceToWindow(CRectD& RS, CRect& RW)
// ���������� ������� ��������� ��������� �� ������� � �������
// RS - ������� � ������� ����������� - double
// RW - ������� � ������� ����������� - int
{
	CMatrix M(3, 3);
	CSize sz = RW.Size();	 // ������ ������� � ����
	int dwx = sz.cx;	     // ������
	int dwy = sz.cy;	     // ������
	CSizeD szd = RS.SizeD(); // ������ ������� � ������� �����������

	double dsx = szd.cx;    // ������ � ������� �����������
	double dsy = szd.cy;    // ������ � ������� �����������

	double kx = (double)dwx / dsx;   // ������� �� x
	double ky = (double)dwy / dsy;   // ������� �� y

	M(0, 0) = kx;  M(0, 1) = 0;    M(0, 2) = (double)RW.left - kx * RS.left;
	M(1, 0) = 0;   M(1, 1) = -ky;  M(1, 2) = (double)RW.bottom + ky * RS.bottom;
	M(2, 0) = 0;   M(2, 1) = 0;    M(2, 2) = 1;
	return M;
}

//------------------------------------------------------------------------------

void SetMyMode(CDC& dc, CRectD& RS, CRect& RW)
// ������������� ����� ����������� MM_ANISOTROPIC � ��� ���������
// dc - ������ �� ����� CDC MFC
// RS -  ������� � ������� ����������� - int
// RW -	 ������� � ������� ����������� - int  
{
	double dsx = RS.right - RS.left;
	double dsy = RS.top - RS.bottom;
	double xsL = RS.left;
	double ysL = RS.bottom;

	int dwx = RW.right - RW.left;
	int dwy = RW.bottom - RW.top;
	int xwL = RW.left;
	int ywH = RW.bottom;

	dc.SetMapMode(MM_ANISOTROPIC);
	dc.SetWindowExt((int)dsx, (int)dsy);
	dc.SetViewportExt(dwx, -dwy);
	dc.SetWindowOrg((int)xsL, (int)ysL);
	dc.SetViewportOrg(xwL, ywH);
}

CBlade::CBlade()            
{
	//double R = 20;
	//double H = 100;
	//double fi = 50;
	//double speed = 10;
	//double RoE = H, RoV = H;
	//double d = RoE + RoV;
	///*
	//CMatrix ECoords;
	//CMatrix MCoords;
	//CMatrix VCoords;
	//CMatrix PCoords;
	//*/

	//RS.SetRectD(-d, d, d, -d);					// ������� ������� � ������� �����������
	//RW.SetRect(0, 0, 600, 600);					// ������� � ����
	//MainPoint.SetRect(-R, R, R, -R);				// ������������� ������ - ��� ��������� �����
	////Lopast_1_Orbit.SetRect(-RoE, RoE, RoE, -RoE);	// ������������� ������ ����� - ��� ��������� �����
	////Lopast_2_Orbit.SetRect(-RoV, RoV, RoV, -RoV);
	//FirstTop.SetRect(-5, 5, 5, -5);
	//SecondTop.SetRect(-5, 5, 5, -5);
	//FirstBootom.SetRect(-5, 5, 5, -5);
	//SecondBootom.SetRect(-5, 5, 5, -5);
	//WayRotation.SetRect(-RoE, RoE, RoE, -RoE);


	//fiSB = 0 + fi / 4;
	//fiFB = 45 + fi / 4;
	//fiST = 0 - fi / 4;
	//fiFT = 45 - fi / 4;//���� ��������� ��� FT
	//wPoint = -speed;
	////dt = -speed;
	//dt = 0.1;


	////fiL1 = 0 + fi / 4;			// ������� ��������� ����� � ������� �������� ������, ����
	////fiL2 = 45 + fi / 4;			// ������� ��������� ���� � ������� �������� �����, ����

	////fiL11 = 0 - fi / 4;
	////fiL21 = 45 - fi / 4;


	////wLopast_1 = -speed;			// ������� �������� ����� � ������� �������� ������, ����/���.
	////// ������� �������� ���� � ������� �������� �����, ����/���.
	////wLopast_2 = -speed;



	//FTCoords.RedimMatrix(3);
	//STCoords.RedimMatrix(3);
	//FBCoords.RedimMatrix(3);
	//SBCoords.RedimMatrix(3);




	double rS = 30;       
	double RoE = 10 * rS;	 
	double d = RoE;		    
	RS.SetRectD(-d, d, d, -d);					// ������� ������� � ������� �����������
	RW.SetRect(0, 0, 690, 640);					// ������� � ����
	MainPoint.SetRect(-rS, rS, rS, -rS);
	FirstTop.SetRect(-5, 5, 5, -5);
	SecondTop.SetRect(-5, 5, 5, -5);
	FirstBootom.SetRect(-5, 5, 5, -5);
	SecondBootom.SetRect(-5, 5, 5, -5);
	WayRotation.SetRect(-RoE, RoE, RoE, -RoE);	
	fiSB = 215;
	fiFB = 205;			
	fiST = 25;			
	fiFT = 35;//���� ��������� ��� FT
	wPoint = -8;
	dt = 0.5;
	FTCoords.RedimMatrix(3);
	STCoords.RedimMatrix(3);
	FBCoords.RedimMatrix(3);
	SBCoords.RedimMatrix(3);
	FifthBladeCoords.RedimMatrix(3);
	SixthBladeCoords.RedimMatrix(3);
	SeventhBladeCoords.RedimMatrix(3);
	EighthBladeCoords.RedimMatrix(3);
}

void CBlade::SetNewCoords()
{
	double RoV = (WayRotation.right - WayRotation.left) / 2;
	double ff = (fiFT / 90.0) * pi;
	double x = RoV * cos(ff);
	double y = RoV * sin(ff);
	FTCoords(0) = x;
	FTCoords(1) = y;
	FTCoords(2) = 1;

	fiFT += wPoint * dt;
	CMatrix P = CreateRotate2D(fiFT);
	FTCoords = P * FTCoords;

	// For second blade
	ff = (fiST / 90.0) * pi;
	x = RoV * cos(ff);
	y = RoV * sin(ff);
	STCoords(0) = x;
	STCoords(1) = y;
	STCoords(2) = 1;

	fiST += wPoint * dt;
	P = CreateRotate2D(fiST);
	STCoords = P * STCoords;

	// For third blade
	ff = (fiFB / 90.0) * pi;
	x = RoV * cos(ff);
	y = RoV * sin(ff);
	FBCoords(0) = x;
	FBCoords(1) = y;
	FBCoords(2) = 1;

	fiFB += wPoint * dt;
	P = CreateRotate2D(fiFB);
	FBCoords = P * FBCoords;

	// For fourth blade
	ff = (fiSB / 90.0) * pi;
	x = RoV * cos(ff);
	y = RoV * sin(ff);
	SBCoords(0) = x;
	SBCoords(1) = y;
	SBCoords(2) = 1;

	fiSB += wPoint * dt;
	P = CreateRotate2D(fiSB);
	SBCoords = P * SBCoords;

	// Add new blades (5th and 6th):
	double fi5th = fiSB + 90;  // Set the angle for 5th blade
	RoV = (WayRotation.right - WayRotation.left) / 2;
	ff = (fi5th / 90.0) * pi;
	x = RoV * cos(ff);
	y = RoV * sin(ff);
	FifthBladeCoords(0) = x;
	FifthBladeCoords(1) = y;
	FifthBladeCoords(2) = 1;

	fi5th += wPoint * dt;
	P = CreateRotate2D(fi5th);
	FifthBladeCoords = P * FifthBladeCoords;

	double fi6th = fiFB + 90;  // Set the angle for 6th blade
	RoV = (WayRotation.right - WayRotation.left) / 2;
	ff = (fi6th / 90.0) * pi;
	x = RoV * cos(ff);
	y = RoV * sin(ff);
	SixthBladeCoords(0) = x;
	SixthBladeCoords(1) = y;
	SixthBladeCoords(2) = 1;

	fi6th += wPoint * dt;
	P = CreateRotate2D(fi6th);
	SixthBladeCoords = P * SixthBladeCoords;





}


void CBlade::Draw(CDC& dc)
{
	CBrush SBrush, EBrush, MBrush, VBrush, * pOldBrush;
	CRect R;

	SBrush.CreateSolidBrush(RGB(134, 255, 0));
	EBrush.CreateSolidBrush(RGB(0, 0, 255));
	MBrush.CreateSolidBrush(RGB(0, 255, 0));
	VBrush.CreateSolidBrush(RGB(128, 64, 64));

	dc.MoveTo(0, 0);
	dc.LineTo(FTCoords(0), FTCoords(1));
	DrawTriangle(FTCoords, STCoords, dc);

	DrawTriangle(FBCoords, SBCoords, dc);

	// Draw the new blades (triangles)
DrawTriangle(FifthBladeCoords, SixthBladeCoords, dc);
DrawTriangle(SixthBladeCoords, FifthBladeCoords, dc);

	pOldBrush = dc.SelectObject(&SBrush);    // Color red
	dc.Ellipse(MainPoint);

	dc.SelectObject(pOldBrush);  			//��������������� �������� �� pOldBrush 
}

void CBlade::DrawTriangle(CMatrix FTCoords, CMatrix STCoords, CDC& dc) // ������ ����������� � ��������� ����������
{
	CPen Pen(PS_SOLID, 3, RGB(255, 0, 0));
	CPen Pen2(PS_SOLID, 3, RGB(0, 0, 255));
	CBrush TBrush;
	TBrush.CreateSolidBrush(RGB(0, 0, 0));
	float dy = max(FTCoords(1), STCoords(1)) - min(FTCoords(1), STCoords(1));
	float dx = max(FTCoords(0), STCoords(0)) - min(FTCoords(0), STCoords(0));
	float y = 0;
	float x1 = 0;
	int x2 = 0;
	POINT points[3];
	points[0].x = 0;
	points[0].y = 0;
	points[1].x = FTCoords(0);
	points[1].y = FTCoords(1);
	points[2].x = STCoords(0);
	points[2].y = STCoords(1);
	dc.Polygon(points, 3);
	dc.SelectObject(&Pen);
	dc.SelectObject(&TBrush);
	if (FTCoords(0) < STCoords(0) && FTCoords(1) > STCoords(1)) 
	{
		if (dx > dy) 
		{
			float deltaY = dy / dx;
			for (int x = FTCoords(0); x <= STCoords(0); x++) 
			{
				dc.MoveTo(0, 0);
				dc.LineTo(x, FTCoords(1) - y);
				if (dy > y) 
				{
					y += deltaY;
				}
			}
		}
		else 
		{
			dc.SelectObject(&Pen2);
			float deltaX = dx / dy;
			for (int y = FTCoords(1); y >= STCoords(1); y--) 
			{
				dc.MoveTo(0, 0);
				dc.LineTo(FTCoords(0) + x1, y);
				if (dx > x1) 
				{
					x1 += deltaX;
				}
			}
		}

	}
	if (FTCoords(0) > STCoords(0) && FTCoords(1) > STCoords(1)) {

		if (dx > dy) 
		{
			float deltaY = dy / dx;
			for (int x = FTCoords(0); x >= STCoords(0); x--) 
			{
				dc.MoveTo(0, 0);
				dc.LineTo(x, FTCoords(1) - y);
				if (dy > y) 
				{
					y += deltaY;
				}
			}
		}
		else 
		{
			dc.SelectObject(&Pen2);
			float deltaX = dx / dy;
			for (int y = FTCoords(1); y >= STCoords(1); y--) 
			{
				dc.MoveTo(0, 0);
				dc.LineTo(FTCoords(0) - x1, y);
				if (dx > x1) 
				{
					x1 += deltaX;
				}
			}
		}
	}
	if (FTCoords(0) > STCoords(0) && FTCoords(1) < STCoords(1)) 
	{
		if (dx > dy) 
		{
			float deltaY = dy / dx;
			for (int x = FTCoords(0); x >= STCoords(0); x--) 
			{
				dc.MoveTo(0, 0);
				dc.LineTo(x, FTCoords(1) + y);
				if (dy > y) 
				{
					y += deltaY;
				}
			}
		}
		else 
		{
			dc.SelectObject(&Pen2);
			float deltaX = dx / dy;
			for (int y = FTCoords(1); y <= STCoords(1); y++) 
			{
				dc.MoveTo(0, 0);
				dc.LineTo(FTCoords(0) - x1, y);
				if (dx > x1) 
				{
					x1 += deltaX;
				}
			}
		}
	}
	if (FTCoords(0) < STCoords(0) && FTCoords(1) < STCoords(1)) 
	{
		if (dx > dy) 
		{
			float deltaY = dy / dx;
			for (int x = FTCoords(0); x <= STCoords(0); x++) 
			{
				dc.MoveTo(0, 0);
				dc.LineTo(x, FTCoords(1) + y);
				if (dy > y) 
				{
					y += deltaY;
				}
			}
		}
		else {
			dc.SelectObject(&Pen2);

			float deltaX = dx / dy;
			for (int y = FTCoords(1); y <= STCoords(1); y++) 
			{
				dc.MoveTo(0, 0);
				dc.LineTo(FTCoords(0) + x1, y);
				if (dx > x1) 
				{
					x1 += deltaX;
				}
			}
		}
	}
}


void CBlade::GetRS(CRectD& RSX)
// RS - ���������, ���� ������������ ��������� ������� �������
{
	RSX.left = RS.left;
	RSX.top = RS.top;
	RSX.right = RS.right;
	RSX.bottom = RS.bottom;
}







