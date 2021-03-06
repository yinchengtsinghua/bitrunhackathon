// CDialogViewCost.cpp: 实现文件
//

#include "stdafx.h"
#include "MFC_Investor.h"
#include "CDialogViewCost.h"
#include "afxdialogex.h"


// CDialogViewCost 对话框

IMPLEMENT_DYNAMIC(CDialogViewCost, CDialogEx)

CDialogViewCost::CDialogViewCost(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ViewCost, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

CDialogViewCost::~CDialogViewCost()
{
}

void CDialogViewCost::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}


BEGIN_MESSAGE_MAP(CDialogViewCost, CDialogEx)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CDialogViewCost::OnNMClickList1)
END_MESSAGE_MAP()


// CDialogViewCost 消息处理程序





BOOL CDialogViewCost::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	// TODO:  在此添加额外的初始化
	LONG lStyle;
	lStyle = GetWindowLong(m_list.m_hWnd, GWL_STYLE);//获取当前窗口style 
	lStyle &= ~LVS_TYPEMASK; //清除显示方式位 
	lStyle |= LVS_REPORT; //设置style 
	SetWindowLong(m_list.m_hWnd, GWL_STYLE, lStyle);//设置style

	DWORD dwStyle = m_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;//选中某行使整行高亮（只适用与report风格的listctrl） 
	dwStyle |= LVS_EX_GRIDLINES;//网格线（只适用与report风格的listctrl） 
	dwStyle |= LVS_EX_CHECKBOXES;//item前生成checkbox控件

	m_list.InsertColumn(0, L"花销类型", LVCFMT_LEFT, 100);//插入列 
	m_list.InsertColumn(1, L"花销金额", LVCFMT_LEFT, 100);
	m_list.InsertColumn(2, L"花销说明", LVCFMT_LEFT, 500);

	int nRow = 0;
	nRow = m_list.InsertItem(0, L"支付顾问佣金");//插入行
	m_list.SetItemText(0, 1, _T("10000"));
	m_list.SetItemText(0, 2, _T("支付给李哭去教授站台费用"));



	nRow = m_list.InsertItem(0, L"员工token激励");//插入行
	m_list.SetItemText(0, 1, _T("20000"));
	m_list.SetItemText(0, 2, _T("支付给优秀员工张小虎激励"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDialogViewCost::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	int nId;
	//首先得到点击的位置
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		MessageBox(L"请至少选择一项", L"提示", MB_ICONEXCLAMATION);
		return;
	}
	//得到行号，通过POSITION转化
	nId = (int)m_list.GetNextSelectedItem(pos);
	str.Format(L"%d", nId);
	//MessageBox(L"您选中第" + str + L"行");
	//得到列中的内容（0表示第一列，同理1,2,3...表示第二，三，四...列）
	str = m_list.GetItemText(nId, 1);
	//m_edit1.SetWindowTextW(str);
	str = m_list.GetItemText(nId, 2);
	m_edit.SetWindowTextW(str);
	*pResult = 0;
}
