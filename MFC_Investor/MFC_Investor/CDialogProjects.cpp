// CDialogProjects.cpp: 实现文件
//

#include "stdafx.h"
#include "MFC_Investor.h"
#include "CDialogProjects.h"
#include "afxdialogex.h"


// CDialogProjects 对话框

IMPLEMENT_DYNAMIC(CDialogProjects, CDialog)

CDialogProjects::CDialogProjects(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_projects, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

CDialogProjects::~CDialogProjects()
{
}

void CDialogProjects::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogProjects, CDialog)
END_MESSAGE_MAP()


// CDialogProjects 消息处理程序
