
// ChildView.cpp: реализация класса CChildView
//

#include "stdafx.h"
#include "Lab09.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CChildView::CChildView()
{		
	Index = 0;
}

CChildView::~CChildView()
{
}

// Реализация карты сообщений
BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	// сообщения меню выбора

	ON_COMMAND(ID_Lines_Lagr, &CChildView::OnLagr)
	ON_COMMAND(ID_Lines_Bezier, &CChildView::OnBezier)
	ON_COMMAND(ID_Lines_Bezier1, &CChildView::OnBezier1)
	ON_COMMAND(ID_Lines_Bezier2, &CChildView::OnBezier2)
	ON_COMMAND(ID_Lines_Bezier3, &CChildView::OnBezier3)
	ON_COMMAND(ID_Lines_Bezier4, &CChildView::OnBezier4)
END_MESSAGE_MAP()



// Обработчики сообщений CChildView

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint()
{
	CPaintDC dc(this); // контекст устройства для рисования

	if (Index == 1)
	{
		PenLine.Set(PS_SOLID, 0, RGB(0, 255, 0));
		Graph.SetPenLine(PenLine);
		Graph.Draw(dc, 0, 1);

		// Вторая линия линия		
		PenLine.Set(PS_SOLID, 2, RGB(255, 0, 0));
		Graph.SetPenLine(PenLine);
		Graph.DrawLagr(dc);
	}
	if (Index == 2)
	{
		PenLine.Set(PS_SOLID, 0, RGB(0, 255, 0));
		Graph.SetPenLine(PenLine);
		Graph.Draw(dc, 0, 1);

		// Вторая линия линия		
		PenLine.Set(PS_SOLID, 2, RGB(255, 0, 0));
		Graph.SetPenLine(PenLine);
		Graph.DrawBezier(dc, N_Bezier);
	}
	if (Index == 3)
	{
		PenLine.Set(PS_SOLID, 0, RGB(0, 255, 0));
		Graph.SetPenLine(PenLine);
		Graph.Draw(dc, 0, 1);

		// Вторая линия линия		
		PenLine.Set(PS_SOLID, 2, RGB(255, 0, 0));
		Graph.SetPenLine(PenLine);
		Graph.DrawBezier(dc, N_Bezier);
	}
	if (Index == 4)
	{
		PenLine.Set(PS_SOLID, 0, RGB(0, 255, 0));
		Graph.SetPenLine(PenLine);
		Graph.Draw(dc, 0, 1);

		// Вторая линия линия		
		PenLine.Set(PS_SOLID, 2, RGB(255, 0, 0));
		Graph.SetPenLine(PenLine);
		Graph.DrawBezier(dc, N_Bezier);
	}
	if (Index == 5)
	{
		PenLine.Set(PS_SOLID, 0, RGB(0, 255, 0));
		Graph.SetPenLine(PenLine);
		Graph.Draw(dc, 0, 1);

		// Вторая линия линия		
		PenLine.Set(PS_SOLID, 2, RGB(255, 0, 0));
		Graph.SetPenLine(PenLine);
		Graph.DrawBezier(dc, N_Bezier);
	}
	if (Index == 6)
	{
		PenLine.Set(PS_SOLID, 0, RGB(0, 255, 0));
		Graph.SetPenLine(PenLine);
		Graph.Draw(dc, 0, 1);

		// Вторая линия линия		
		PenLine.Set(PS_SOLID, 2, RGB(255, 0, 0));
		Graph.SetPenLine(PenLine);
		Graph.DrawBezier(dc, N_Bezier);
	}
}



void CChildView::OnLagr()
{
	double dx = pi / 4;
	double xL = 0;
	double xH = pi;
	int N = (xH - xL) / dx;
	X.RedimMatrix(N + 1);
	Y.RedimMatrix(N + 1);
	for (int i = 0; i <= N; i++)
	{
		X(i) = xL + i * dx;	
		Y(i) = pow(2 + cos(X(i)), sin(2 * X(i)));
	}
	RW.SetRect(100, 50, 500, 350);
	Graph.SetParams(X, Y, RW);
	Index = 1;
	Invalidate();
}



void CChildView::OnBezier()
{
	double dt = pi / 4;
	int N = 9;
	X.RedimMatrix(N);
	Y.RedimMatrix(N);
	for (int i = 0; i < N; i++)
	{
		X(i) = i * dt;
		Y(i) = sin(i*dt);
	}
	N_Bezier = 50;
	RW.SetRect(100, 50, 500, 350);
	Graph.SetParams(X, Y, RW);
	Index = 2;
	this->Invalidate();
}



void CChildView::OnBezier1()
{
	double dt = pi / 3;
	int N = 4;
	X.RedimMatrix(N);
	Y.RedimMatrix(N);
	Y(0) = 0;
	X(1) = 1 * dt;
	Y(1) = dt;
	X(2) = 4 * dt;
	Y(2) = dt;
	X(3) = 5 * dt;
	Y(3) = 0;
	N_Bezier = 50;
	RW.SetRect(100, 50, 500, 350);
	Graph.SetParams(X, Y, RW);
	Index = 3;
	this->Invalidate();
}



void CChildView::OnBezier2()
{
	double dt = pi / 2;
	int N = 3;
	X.RedimMatrix(N);
	Y.RedimMatrix(N);
	X(0) = 0;
	Y(0) = 0;
	X(1) = 1.5 * dt;
	Y(1) = 2;
	X(2) = 3*dt;
	Y(2) = 0;
	N_Bezier = 50;
	RW.SetRect(100, 50, 500, 350);
	Graph.SetParams(X, Y, RW);
	Index = 4;
	this->Invalidate();
}



void CChildView::OnBezier3()
{
	double dt = pi / 2;
	int N = 5;
	X.RedimMatrix(N);
	Y.RedimMatrix(N);
	for (int i = 0; i < N; i++)
	{
		X(i) = i * dt;
		Y(i) = sin(i*dt);
	}
	N_Bezier = 50;
	RW.SetRect(100, 50, 500, 350);
	Graph.SetParams(X, Y, RW);
	Index = 5;
	this->Invalidate();
}



void CChildView::OnBezier4()
{
	double dt = pi / 4;
	int N = 4;
	X.RedimMatrix(N);
	Y.RedimMatrix(N);
	X(0) = 2*dt;
	Y(0) = 0;
	X(1) = 7 * dt;
	Y(1) = 3;
	X(2) = 0;
	Y(2) = 3;
	X(3) = 5 * dt;
	Y(3) = 0;
	N_Bezier = 50;
	RW.SetRect(100, 50, 500, 350);
	Graph.SetParams(X, Y, RW);
	Index = 6;
	this->Invalidate();
}