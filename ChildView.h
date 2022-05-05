
// ChildView.h: Schnittstelle der CChildView-Klasse
//


#pragma once


// CChildView-Fenster

class CChildView : public CWnd
{
// Konstruktion
public:
	CChildView();

// Attribute
public:

// Vorgänge
public:
	double xdmin;
	double xddelta;
	double ydmin;
	double yddelta;
	int m_height;
	int m_width;

// Überschreibungen
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	void JuliaMalen();
	void MandelbrotMalen();

// Implementierung
public:
	virtual ~CChildView();

	// Generierte Funktionen für die Meldungstabellen
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDiagonaleD();
	afx_msg void OnDiagonaleAufgabe1();
	afx_msg void OnDiagonaleAufgabe1_3();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDiagonaleMandelbrot();
	afx_msg void OnVektorQuadrat();
	afx_msg void OnVektorWuerfelrotieren();
	afx_msg void OnVektorQuadratrotieren();
	void GLInit(int Breite, int Hoehe, int Modus);
	void Bunter_Einheitswuerfel();
	void Achsenkreuz(float l);
	afx_msg void OnOpenglAufgabe5();
};

