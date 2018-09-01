// CMoneyDialog.cpp: 实现文件
//

#include "stdafx.h"
#include "MFC_projector.h"
#include "CMoneyDialog.h"
#include "afxdialogex.h"


// CMoneyDialog 对话框

IMPLEMENT_DYNAMIC(CMoneyDialog, CDialog)

CMoneyDialog::CMoneyDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_jie, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif
	id = 0;
}

CMoneyDialog::~CMoneyDialog()
{
}

void CMoneyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_com);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_EDIT3, m_edit3);
}


BEGIN_MESSAGE_MAP(CMoneyDialog, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CMoneyDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMoneyDialog::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMoneyDialog::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMoneyDialog 消息处理程序


BOOL CMoneyDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	
	
	// 为组合框控件的列表框添加列表项“百度”   
	
	this->SetWindowTextW(L"处理业务");

	m_com.AddString(_T("报销"));
	m_com.AddString(_T("借款"));
	
	m_com.AddString(_T("预算"));


	m_com.SetCurSel(this->id);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

BOOL CMoneyDialog::getit()
{



	// 默认选择第一项   
	


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CMoneyDialog::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR szFilter[] = _T("Word文件(*.doc)|*.doc|所有文件(*.*)|*.*||");
	// 构造保存文件对话框   
	//CFileDialog fileDlg(FALSE, _T("选择文件"), _T("选择白皮书"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);
	CFileDialog fileDlg(TRUE, _T("说明文件"), NULL, 0, szFilter, this);

	CString strFilePath;

	// 显示保存文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“保存”按钮，则将选择的文件路径显示到编辑框里   
		strFilePath = fileDlg.GetPathName();
		m_edit2.SetWindowTextW(strFilePath);
		//SetDlgItemText(IDC_SAVE_EDIT, strFilePath);
	}
}


void CMoneyDialog::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	if (this->id == 0) {
		MessageBox(L"请求借款成功,投资人会尽快处理您的请求", L"发起请求", 0);
	}
	else if (this->id == 1)
	{
		MessageBox(L"请求报销成功,投资人会尽快处理您的请求", L"发起请求", 0);
	}
	else {
		MessageBox(L"请求预算成功,投资人会尽快处理您的请求", L"发起请求", 0);
	}
}


void CMoneyDialog::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	m_edit1.SetWindowTextW(L"");
	m_edit2.SetWindowTextW(L"");
	m_edit3.SetWindowTextW(L"");

}
