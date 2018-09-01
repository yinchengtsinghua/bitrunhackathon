#pragma once


// CDialogpasswordTools 对话框
#include <iostream>
#include <ctime>
using namespace std;

class CDialogpasswordTools : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogpasswordTools)

public:
	CDialogpasswordTools(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogpasswordTools();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_tools };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_tree1;
	CEdit m_edit1;
	CListBox m_list;
	CEdit m_edit2;
	CEdit m_edit4;
	CSliderCtrl m_slider;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	virtual BOOL OnInitDialog();
	CString mypass;
	string randstr(string strCharElem, int nOutStrLen);
};
