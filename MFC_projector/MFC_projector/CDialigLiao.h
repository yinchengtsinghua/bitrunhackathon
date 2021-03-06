#pragma once


// CDialigLiao 对话框

class CDialigLiao : public CDialog
{
	DECLARE_DYNAMIC(CDialigLiao)

public:
	CDialigLiao(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialigLiao();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Liao };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	CRichEditCtrl m_redit1;
	CRichEditCtrl m_redit2;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	virtual BOOL OnInitDialog();
	CImageList m_ImageList;
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
};
