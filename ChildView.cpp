
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
#include <gl/Gl.h>
#include <gl/GLU.h>


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
	ON_COMMAND(ID_OPENGL_AUFGABE5, &CChildView::OnOpenglAufgabe5)
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



// Achtung!!!
// Funktionsdefinitionen auch in Header-Datei �bernehmen

void CChildView::GLInit(int Breite, int Hoehe, int Modus)
{
	static HDC         hdc;
	static HGLRC       hglrc;
	int         iPixelFormat;
	HWND hwnd = GetSafeHwnd();


	static PIXELFORMATDESCRIPTOR pfd =	//pfd legt das Aussehen der Szene fest
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,						//Versionsnummer
		PFD_DRAW_TO_WINDOW |	//pfd muss Windows unterst�tzen
		PFD_SUPPORT_OPENGL |	//pfd muss OpenGL unterst�tzen
		PFD_DOUBLEBUFFER ,		//Doppelpuffer wird unterst�tzt
		PFD_TYPE_RGBA,			//RGBA-Farbformat ausw�hlen
		32,						//Bit-Farbtiefe
		0, 0, 0, 0, 0, 0,		//Farbbits werden ignoriert
		0,						//kein Alphapuffer
		0,						//Schiebebit ignoriert
		0,						//kein Ansammlungspuffer
		0, 0, 0, 0,				//Ansammlungsbits werden ignoriert
		16,						//16bit Z-Puffer (Tiefenpuffer)
		16,						//Masken-Puffer
		0,						//keinen Hilfs-Puffer
		PFD_MAIN_PLANE,			//Festlegung der Zeichenebene (Hauptebene)
		0,						//reserviert
		0, 0, 0					//Ebenenmasken werden ignoriert 
	};
	CDC* pDC = GetDC();
	CRect gesamt, client;
	GetWindowRect(&gesamt);
	GetClientRect(&client);
	int diff_x = gesamt.Width() - client.Width();
	int diff_y = gesamt.Height() - client.Height();
	m_height = Hoehe;
	m_width = Breite;

	switch (Modus)
	{
	case 1:  // Modus 1 -> Initialisierung

		// ---------- Fenstergr��e
		GetParent()->SetWindowPos(&wndTop,
			50, 50, m_height + diff_x, m_width + diff_y, 0);
		//		GetParent()->ShowWindow(SW_NORMAL);
		GetParent()->RedrawWindow();
		// ------ Device Context
		hdc = pDC->GetSafeHdc();

		// ------ Pixelformat einstellen (OpenGL-f�hig)
		iPixelFormat = ChoosePixelFormat(hdc, &pfd);
		SetPixelFormat(hdc, iPixelFormat, &pfd);

		// ----  Rendering-Context erstellen und zuweisen
		hglrc = wglCreateContext(hdc);
		if (hglrc == NULL) { SetWindowText(CString("Fehler beim RC !")); Sleep(2000); }
		wglMakeCurrent(hdc, hglrc);
		break;

	case 0:  // Modus 0 -> Beenden
		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(hglrc);

		ReleaseDC(pDC);
		break;
	}
	return;

}

void CChildView::Bunter_Einheitswuerfel()
{
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);          // gr�n bei z = -0.5
	glNormal3f(0, 0, -1);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);

	glColor3f(1, 0, 0);        // rot bei z = 0.5
	glNormal3f(0, 0, 1);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);

	glColor3f(1, 0.75, 0.25);  // orange bei y = -0.5
	glNormal3f(0, -1, 0);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);

	glColor3f(0, 0, 1);          // blau bei y = 0.5
	glNormal3f(0, 1, 0);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);

	glColor3f(1, 0, 1);          // lila bei x =  0.5
	glNormal3f(-1, 0, 0);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, -0.5);

	glColor3f(1, 1, 0);          // gelb bei x = -0.5
	glNormal3f(1, 0, 0);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();
}

void CChildView::Achsenkreuz(float l)
{
	GLfloat Pfeil = (float)0.05;

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex3f(-l, 0, 0);  // Achsen
	glVertex3f(l, 0, 0);

	glVertex3f(0, -l, 0);
	glVertex3f(0, l, 0);

	glVertex3f(0, 0, -l);
	glVertex3f(0, 0, l);

	glVertex3f(l, 0, 0);  // Pfeile
	glVertex3f(l - Pfeil, Pfeil, 0);

	glVertex3f(l, 0, 0);
	glVertex3f(l - Pfeil, -Pfeil, 0);

	glVertex3f(0, l, 0);  // Pfeile
	glVertex3f(0, l - Pfeil, Pfeil);

	glVertex3f(0, l, 0);
	glVertex3f(0, l - Pfeil, -Pfeil);

	glVertex3f(0, 0, l);  // Pfeile
	glVertex3f(Pfeil, 0, l - Pfeil);

	glVertex3f(0, 0, l);
	glVertex3f(-Pfeil, 0, l - Pfeil);
	glEnd();
}

void CChildView::OnOpenglAufgabe5()
{



	GLInit(700, 700, 1);
	glClearColor(1.0, 1.0, 1.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glFrustum(-1, 1, -1, 1, 1.5, 6);
	gluLookAt(1.0, 1.0, 3.0,		//Augpunkt
		0.0, 0.0, 0.0,		//Zielpunkt
		0.0, 1.0, 0.0);		//Up-Vektor

	for (int i = 0; i < 5000; i+=2) {
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);



	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	Achsenkreuz(1.2);



	glRotated(i, 1.0, 0, 0);
	glRotated(i, 0, 0, 1.0);
	Bunter_Einheitswuerfel();


	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glScaled(1.2, 1.2, 1.2);
	Bunter_Einheitswuerfel();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);




	
		glLoadIdentity();
		glScaled(0.5, 0.5, 0.5);
		glRotated(i, 1.0, 0, 0);
		glRotated(i, 0, 0, 1.0);
		glTranslated(1, 0, 0);
		glRotated(i, 1.0, 0, 0);
		Bunter_Einheitswuerfel();

		glLoadIdentity();
		glScaled(0.5, 0.5, 0.5);
		glRotated(i, 1.0, 0, 0);
		glRotated(i, 0, 0, 1.0);
		glTranslated(-1, 0, 0);
		glRotated(i, 1.0, 0, 0);
		Bunter_Einheitswuerfel();

		glLoadIdentity();
		glScaled(0.5, 0.5, 0.5);
		glRotated(i, 1.0, 0, 0);
		glRotated(i, 0, 0, 1.0);
		glTranslated(0, 1, 0);
		glRotated(i, 0, 1.0, 0);
		Bunter_Einheitswuerfel();


		glLoadIdentity();
		glScaled(0.5, 0.5, 0.5);
		glRotated(i, 1.0, 0, 0);
		glRotated(i, 0, 0, 1.0);
		glTranslated(0, -1, 0);
		glRotated(i, 0, 1.0, 0);
		Bunter_Einheitswuerfel();

		glLoadIdentity();
		glScaled(0.5, 0.5, 0.5);
		glRotated(i, 1.0, 0, 0);
		glRotated(i, 0, 0, 1.0);
		glTranslated(0, 0, 1);
		glRotated(i, 0, 0, 1.0);
		Bunter_Einheitswuerfel();

		glLoadIdentity();
		glScaled(0.5, 0.5, 0.5);
		glRotated(i, 1.0, 0, 0);
		glRotated(i, 0, 0, 1.0);
		glTranslated(0, 0, -1);
		glRotated(i, 0, 0, 1.0);
		Bunter_Einheitswuerfel();

	
	

	SwapBuffers(wglGetCurrentDC());
	Sleep(10);

}



		GLInit(0, 0, 0);
		
	
}
