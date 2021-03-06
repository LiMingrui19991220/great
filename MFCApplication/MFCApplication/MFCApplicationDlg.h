
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
	double result = 0;
	int m_iSign = 0;//计算的种类分别对应1,2,3,4
	int m_iSign_unit = 1;//单位分别对应1,0，默认厘米
	int m_iSign_check = 0;//检查的状态
	int point1;
	int point2;//标记出两个数开始的位置
	//int m_iSign_transform = 0;//0,1分别为两种单位
	double m_number1;
	double m_number2;
	char NUMBER1[10];
	char NUMBER2[10];
	void Calculate();
	void Check();
	void Transform();
	void Show();
	CString m_show;
	CString M_NUMBER1;
	CString M_NUMBER2;
//	CString m_value;
	CString m_tab;
//	CButton m_CM;
	CString m_parameter;
//	CString m_unit;
	afx_msg void OnEnChangeEdit3();
//	afx_msg void OnBnClickedButton1();
//	afx_msg void OnBnClickedButton8();
//	afx_msg void OnBnClickedNum1();
//	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedCircle();
	afx_msg void OnBnClickedRectangle();
	afx_msg void OnBnClickedSquare();
	afx_msg void OnBnClickedTriangle();
//	afx_msg void OnBnClickedCm();
	afx_msg void OnBnClickedRadioCm();
	afx_msg void OnBnClickedRadioInch();
	afx_msg void OnBnClickedEqual();
	afx_msg void OnEnChangeEdit1();
};
