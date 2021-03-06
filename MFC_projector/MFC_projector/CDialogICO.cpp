// CDialogICO.cpp: 实现文件
//

#include "stdafx.h"
#include "MFC_projector.h"
#include "CDialogICO.h"
#include "afxdialogex.h"


// CDialogICO 对话框

IMPLEMENT_DYNAMIC(CDialogICO, CDialog)

CDialogICO::CDialogICO(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOGICO, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

CDialogICO::~CDialogICO()
{
}

void CDialogICO::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_EDIT3, m_edit3);
	DDX_Control(pDX, IDC_EDIT4, m_edit4);
	DDX_Control(pDX, IDC_EDIT5, m_edit5);
	DDX_Control(pDX, IDC_EDIT7, m_edit6);
	DDX_Control(pDX, IDC_EDIT6, medit_6);
	DDX_Control(pDX, IDC_COMBO1, m_com);
}


BEGIN_MESSAGE_MAP(CDialogICO, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialogICO::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDialogICO::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDialogICO::OnBnClickedButton3)
END_MESSAGE_MAP()


// CDialogICO 消息处理程序


void CDialogICO::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString mystr1;
	CString mystr2;
	CString mystr3;
	CString mystr4;
	CString mystr5;
	CString mystr6;
	CString mystr7;
	m_edit1.GetWindowTextW(mystr1);
	m_edit2.GetWindowTextW(mystr2);
	m_edit3.GetWindowTextW(mystr3);
	m_edit4.GetWindowTextW(mystr4);
	m_edit5.GetWindowTextW(mystr5);
	m_edit6.GetWindowTextW(mystr6);
	medit_6.GetWindowTextW(mystr7);
	Sleep(5000);
	
	MessageBox(L"发行代币成功,代币名称"+ mystr1 +L"  \r\n代币总量"+mystr2, L"发行代币",0);
}


void CDialogICO::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_edit1.SetWindowTextW(L"");
	m_edit2.SetWindowTextW(L"");
	m_edit3.SetWindowTextW(L"");
	m_edit4.SetWindowTextW(L"");
	m_edit5.SetWindowTextW(L"");
	m_edit6.SetWindowTextW(L"");
	medit_6.SetWindowTextW(L"");
}


BOOL CDialogICO::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	m_edit1.SetWindowTextW(L"YinchengEOS");
	m_edit2.SetWindowTextW(L"10000000000000");
	m_edit3.SetWindowTextW(L"0.00000001");
	m_edit4.SetWindowTextW(L"7000000000000");
	m_edit5.SetWindowTextW(L"1");
	m_edit6.SetWindowTextW(L"0");
	medit_6.SetWindowTextW(L"3000000000000");

	this->SetWindowTextW(L"发行代币");



	m_com.AddString(_T("EOS"));
	// 为组合框控件的列表框添加列表项“百度”   
	m_com.AddString(_T("Ethereum"));

	// 默认选择第一项   
	m_com.SetCurSel(0);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDialogICO::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(L"请联系yincheng03@mails.tinghua.edu.cn发行代币", L"发行代币", 0);
}
