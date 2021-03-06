// dllmain.cpp: DllMain 的实现。

#include "stdafx.h"
#include "resource.h"
#include "MFCprojectorHandlers_i.h"
#include "dllmain.h"
#include "xdlldata.h"

CMFCprojectorHandlersModule _AtlModule;

class CMFCprojectorHandlersApp : public CWinApp
{
public:

// 重写
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CMFCprojectorHandlersApp, CWinApp)
END_MESSAGE_MAP()

CMFCprojectorHandlersApp theApp;

BOOL CMFCprojectorHandlersApp::InitInstance()
{
	if (!PrxDllMain(m_hInstance, DLL_PROCESS_ATTACH, nullptr))
		return FALSE;
	return CWinApp::InitInstance();
}

int CMFCprojectorHandlersApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}
