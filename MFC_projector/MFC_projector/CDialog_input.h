#pragma once


// CDialog_input 对话框

class CDialog_input : public CDialog
{
	DECLARE_DYNAMIC(CDialog_input)

public:
	CDialog_input(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialog_input();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_INPUT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit1;
	CEdit medit2;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	virtual BOOL OnInitDialog();
};
