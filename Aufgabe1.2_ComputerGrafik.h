
// Aufgabe1.2_ComputerGrafik.h: Hauptheaderdatei für die Aufgabe1.2_ComputerGrafik-Anwendung
//
#pragma once

#ifndef __AFXWIN_H__
	#error "'pch.h' vor dieser Datei für PCH einschließen"
#endif

#include "resource.h"       // Hauptsymbole


// CAufgabe12ComputerGrafikApp:
// Siehe Aufgabe1.2_ComputerGrafik.cpp für die Implementierung dieser Klasse
//

class CAufgabe12ComputerGrafikApp : public CWinApp
{
public:
	CAufgabe12ComputerGrafikApp() noexcept;


// Überschreibungen
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementierung

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CAufgabe12ComputerGrafikApp theApp;
