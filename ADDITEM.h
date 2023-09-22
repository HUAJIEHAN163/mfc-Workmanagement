#pragma once
#include "afxdialogex.h"


// ADDITEM 对话框

class ADDITEM : public CDialogEx
{
	DECLARE_DYNAMIC(ADDITEM)

public:
	ADDITEM(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ADDITEM();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADDITEM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_name;
	int m_id;
	int m_did;
	afx_msg void OnBnClickedOk();
};
