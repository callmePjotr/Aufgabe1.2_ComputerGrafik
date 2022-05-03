
// ChildView.cpp: Implementierung der CChildView-Klasse
//

#include "pch.h"
#include "framework.h"
#include "Aufgabe1.2_ComputerGrafik.h"
#include "ChildView.h"
#include "Vektor2.h"
#include "time.h"
#include <iostream>
#include <cstdlib>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static int choose;

// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_DIAGONALE_D, &CChildView::OnDiagonaleD)
	ON_COMMAND(ID_DIAGONALE_AUFGABE1, &CChildView::OnDiagonaleAufgabe1)
	ON_COMMAND(ID_DIAGONALE_AUFGABE2, &CChildView::OnDiagonaleAufgabe1_3)
	
	ON_WM_RBUTTONUP()

	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_DIAGONALE_MANDELBROT, &CChildView::OnDiagonaleMandelbrot)
	ON_COMMAND(ID_VEKTOR_QUADRAT, &CChildView::OnVektorQuadrat)

	ON_COMMAND(ID_VEKTOR_WUERFELROTIEREN, &CChildView::OnVektorWuerfelrotieren)
	ON_COMMAND(ID_VEKTOR_QUADRATROTIEREN, &CChildView::OnVektorQuadratrotieren)
END_MESSAGE_MAP()



// CChildView-Meldungshandler

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
	CPaintDC dc(this); // Gerätekontext zum Zeichnen
	
	// TODO: Fügen Sie hier Ihren Meldungshandlercode ein.
	
	// Rufen Sie nicht CWnd::OnPaint() zum Zeichnen von Nachrichten auf
}



void CChildView::OnDiagonaleD()
{
	// TODO: Fügen Sie hier Ihren Befehlshandlercode ein.

	CRect rc, rp;
	GetClientRect(&rc);
	GetParent()->GetWindowRect(rp);


	int diffx = rp.Width() - rc.Width();
	int diffy = rp.Height() - rc.Height();


	GetParent()->SetWindowPos(NULL, 50, 50, 700 + diffx, 700 + diffy, SWP_SHOWWINDOW);

	UpdateWindow();

	CDC* pDC = GetDC();
	for (int i = 0; i < 700; i++) {
		pDC->SetPixel(i, i, RGB(255, 0, 0));
	}



}


void CChildView::OnDiagonaleAufgabe1()
{
	// TODO: Fügen Sie hier Ihren Befehlshandlercode ein.





	CRect rc, rp;
	GetClientRect(&rc);
	GetParent()->GetWindowRect(rp);


	int diffx = rp.Width() - rc.Width();
	int diffy = rp.Height() - rc.Height();


	GetParent()->SetWindowPos(NULL, 50, 50, 700 + diffx, 700 + diffy, SWP_SHOWWINDOW);

	UpdateWindow();

	xdmin = -1.6;
	xddelta = 3.2;
	ydmin = -1.6;
	yddelta = 3.2;

//	CDC* pDC = GetDC();
	choose = 2;
	JuliaMalen();

}
void CChildView::JuliaMalen(){
		CDC* pDC = GetDC();
		int xp, xpmin = 0, xpdelta = 700;
		int yp, ypmin = 0, ypdelta = 700;

		double xd, yd;

		for (int xp = 0; xp < 700; xp++) {
			for (yp = 0; yp < 700; yp++) {
				xd = xdmin + xp * xddelta / xpdelta;
				yd = ydmin + yp * yddelta / ypdelta;
				double a_alt = xd;
				double b_alt = yd;
				double a_neu, b_neu;
				int n;
				double ab2;

				for (n = 1; n < 255; n++) {
					a_neu = a_alt * a_alt - b_alt * b_alt - 0.75;
					b_neu = 2 * a_alt * b_alt + 0.06;
					b_alt = b_neu;
					a_alt = a_neu;
					ab2 = a_neu * a_neu + b_neu * b_neu;
					if (ab2 > 4) {
						break;
					}


				}
				if (ab2 > 4) {
					pDC->SetPixel(xp, yp, RGB(n, 0, (int)ab2));
				}
				else {
					pDC->SetPixel(xp, yp, RGB(n, 0, n));
				}
			}
		}
	}
	





void CChildView::MandelbrotMalen() {

	CDC* pDC = GetDC();
	int xp, xpmin = 0, xpdelta = 700;
	int yp, ypmin = 0, ypdelta = 700;

	double xd, yd;


	for (int xp = 0; xp < 700; xp++) {
		for (yp = 0; yp < 700; yp++) {
			xd = xdmin + xp * xddelta / xpdelta;
			yd = ydmin + yp * yddelta / ypdelta;
			double a_alt = xd;
			double b_alt = yd;
			double a_neu, b_neu;
			int n;
			double ab2;

			for (n = 1; n < 255; n++) {
				a_neu = a_alt * a_alt - b_alt * b_alt +xd;
				b_neu = 2 * a_alt * b_alt + yd;
				b_alt = b_neu;
				a_alt = a_neu;
				ab2 = a_neu * a_neu + b_neu * b_neu;
				if (ab2 > 4) {
					break;
				}


			}
			if (ab2 > 4) {
				pDC->SetPixel(xp, yp, RGB(n, 0, (int)ab2));
			}
			else {
				pDC->SetPixel(xp, yp, RGB(n, 0, n));
			}
		}



		}
	}




void CChildView::OnDiagonaleAufgabe1_3()
{
	// TODO: Fügen Sie hier Ihren Befehlshandlercode ein.

}


void CChildView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Fügen Sie hier Ihren Meldungshandlercode ein, und/oder benutzen Sie den Standard.

	double xd = xdmin + point.x * xddelta / 700.;
	double yd = ydmin + point.y * yddelta / 700.;

	xddelta = xddelta / 2;
	yddelta = yddelta / 2;

	xdmin = xd - xddelta / 2;
	ydmin = yd - yddelta / 2;

	if (choose==2) {
		JuliaMalen();
	}
	if (choose==1) {
		MandelbrotMalen();
	}


	CWnd::OnRButtonUp(nFlags, point);
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Fügen Sie hier Ihren Meldungshandlercode ein, und/oder benutzen Sie den Standard.

	double xd = xdmin + point.x * xddelta / 700.;
	double yd = ydmin + point.y * yddelta / 700.;

	xddelta = xddelta * 2;
	yddelta = yddelta * 2;

	xdmin = xd - xddelta / 2;
	ydmin = yd - yddelta / 2;

	if (choose==2) {
		JuliaMalen();
	}
	if (choose==1) {
		MandelbrotMalen();
	}
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnDiagonaleMandelbrot()
{
	// TODO: Fügen Sie hier Ihren Befehlshandlercode ein.
	CRect rc, rp;
	GetClientRect(&rc);
	GetParent()->GetWindowRect(rp);


	int diffx = rp.Width() - rc.Width();
	int diffy = rp.Height() - rc.Height();


	GetParent()->SetWindowPos(NULL, 50, 50, 700 + diffx, 700 + diffy, SWP_SHOWWINDOW);

	UpdateWindow();

	xdmin = -2.0;
	xddelta = 2.5;
	ydmin = -1.25;
	yddelta = 2.5;
	choose = 1;
	MandelbrotMalen();
}




void CChildView::OnVektorQuadrat()
{
	Vektor2 Quadrat[4];
	Quadrat[0] = Vektor2(50, 50);
	Quadrat[1] = Vektor2(150, 50);
	Quadrat[2] = Vektor2(150, 150);
	Quadrat[3] = Vektor2(50, 150);

	CDC* pDC = GetDC();
	CRect rect;
	GetClientRect(&rect);


	Matrix2 MT;
	MT.setTrans(10, 0);
	for (int anim = 0; anim < 50; anim++) {
		pDC->FillSolidRect(rect, RGB(255, 255, 0));

		for (int i = 0; i < 4; i++) {
			Quadrat[i] = MT * Quadrat[i];
		}
		pDC->MoveTo(Quadrat[3].vek[0], Quadrat[3].vek[1]);
		for (int i = 0; i < 4; i++) {
			pDC->LineTo(Quadrat[i].vek[0], Quadrat[i].vek[1]);
		}
		Sleep(100);

}

}


void CChildView::OnVektorWuerfelrotieren()
{
	Vektor3 wuerfel[8];
	wuerfel[0] = Vektor3(50, 50, 50); 
	wuerfel[1] = Vektor3(150, 50,50);
	wuerfel[2] = Vektor3(150, 150,150);
	wuerfel[3] = Vektor3(50, 150,50);
	wuerfel[4] = Vektor3(50, 50,150);
	wuerfel[5] = Vektor3(150, 50,150);
	wuerfel[6] = Vektor3(150, 50, 150);
	wuerfel[7] = Vektor3(50, 150,150);

	CDC* pDC = GetDC();
	CRect rect;
	GetClientRect(&rect);

	pDC->MoveTo(wuerfel[3].vek[0], wuerfel[3].vek[1]);
	for (int i = 0; i < 4; i++) {
		pDC->LineTo(wuerfel[i].vek[0], wuerfel[i].vek[1]);
	}

	//hinten

	pDC->MoveTo(wuerfel[7].vek[0], wuerfel[7].vek[1]);
	for (int i = 0; i < 8; i++) {
		pDC->LineTo(wuerfel[i].vek[0], wuerfel[i].vek[1]);
	}

	for (int i = 0; i < 4; i++) {
		pDC->MoveTo(wuerfel[i].vek[0], wuerfel[i].vek[1]);
		pDC->LineTo(wuerfel[i+4].vek[0], wuerfel[i+4].vek[1]);
	}

}


void CChildView::OnVektorQuadratrotieren()
{
	Vektor2 Quadrat[4];
	Quadrat[0] = Vektor2(50, 50);
	Quadrat[1] = Vektor2(150, 50);
	Quadrat[2] = Vektor2(150, 150);
	Quadrat[3] = Vektor2(50, 150);

	CDC* pDC = GetDC();
	CRect rect;
	GetClientRect(&rect);

	//Quadrat zeichnen
	pDC->MoveTo(Quadrat[3].vek[0], Quadrat[3].vek[1]);
	for (int i = 0; i < 4; i++) {
		pDC->LineTo(Quadrat[i].vek[0], Quadrat[i].vek[1]);
	}

	//Quadrat in den Ursprung verschieben
	Matrix2 MT;
	MT.setTrans(-100, -100);


	//Quadrat rotieren
	Matrix2 RotMat;
	RotMat.setRotation(10);

	
	//Quadrat zurückschieben
	Matrix2 TransMatr;
	TransMatr.setTrans(100, 100);

	for (int dreh = 0; dreh < 50; dreh++) {
		for (int i = 0; i < 4; i++) {
			Quadrat[i] = MT * Quadrat[i];
			Quadrat[i] = RotMat * Quadrat[i];
			Quadrat[i] = TransMatr * Quadrat[i];
		}

		pDC->MoveTo(Quadrat[3].vek[0], Quadrat[3].vek[1]);
		for (int i = 0; i < 4; i++) {
			pDC->LineTo(Quadrat[i].vek[0], Quadrat[i].vek[1]);
		}

		pDC->FillSolidRect(rect, RGB(255, 255, 255));

		Sleep(100);
	}
	
}
