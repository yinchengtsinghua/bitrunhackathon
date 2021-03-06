// CDialogFa.cpp: 实现文件
//

#include "stdafx.h"
#include "MFC_projector.h"
#include "CDialogFa.h"
#include "afxdialogex.h"


// CDialogFa 对话框

IMPLEMENT_DYNAMIC(CDialogFa, CDialog)

CDialogFa::CDialogFa(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_fa, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

CDialogFa::~CDialogFa()
{
}

void CDialogFa::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, m_edit1);
	DDX_Control(pDX, IDC_EDIT1, m_edit2);
}


BEGIN_MESSAGE_MAP(CDialogFa, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialogFa::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDialogFa::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDialogFa::OnBnClickedButton3)
END_MESSAGE_MAP()


// CDialogFa 消息处理程序


void CDialogFa::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
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
		m_edit1.SetWindowTextW(strFilePath);
		//SetDlgItemText(IDC_SAVE_EDIT, strFilePath);
	}
}


void CDialogFa::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(L"递交成功", L"发布公告成功", 0);
}


void CDialogFa::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	m_edit1.SetWindowTextW(L"");
	m_edit2.SetWindowTextW(L"");
}





BOOL CDialogFa::OnInitDialog()
{
	CDialog::OnInitDialog();


		this->SetWindowTextW(L"发布信息");
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
