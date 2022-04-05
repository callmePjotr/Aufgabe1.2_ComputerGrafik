
// ChildView.cpp: Implementierung der CChildView-Klasse
//

#include "pch.h"
#include "framework.h"
#include "Aufgabe1.2_ComputerGrafik.h"
#include "ChildView.h"

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