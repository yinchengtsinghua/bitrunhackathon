#pragma once


// CDialogPassword 对话框

class CDialogPassword : public CDialog
{
	DECLARE_DYNAMIC(CDialogPassword)

public:
	CDialogPassword(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogPassword();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_password };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit;
	CListBox m_edit2;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
