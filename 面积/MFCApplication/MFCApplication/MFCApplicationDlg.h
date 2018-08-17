
// MFCApplicationDlg.h: 头文件
//

#pragma once


// CMFCApplicationDlg 对话框
class CMFCApplicationDlg : public CDialogEx
{
// 构造
public:
	CMFCApplicationDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_iSign = 0;
	CString m_show;
	afx_msg void OnLbnSelchangeList1();
	CString m_parameter;
	afx_msg void OnBnClickedButton5();
	CString m_unit;
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedNum1();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedCircle();
	CString m_value;
	afx_msg void OnBnClickedRectangle();
	afx_msg void OnBnClickedSquare();
	afx_msg void OnBnClickedTriangle();
};
