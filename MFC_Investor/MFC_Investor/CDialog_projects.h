#pragma once


// CDialog_projects 对话框

class CDialog_projects : public CDialog
{
	DECLARE_DYNAMIC(CDialog_projects)

public:
	CDialog_projects(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialog_projects();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_projects };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_list;
	CEdit m_edit1;
	CEdit m_edit2;
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButton2();
};
