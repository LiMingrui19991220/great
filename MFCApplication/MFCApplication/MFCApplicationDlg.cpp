
// MFCApplicationDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCApplication.h"
#include "MFCApplicationDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplicationDlg 对话框



CMFCApplicationDlg::CMFCApplicationDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION_DIALOG, pParent)
	, m_show(_T(""))
	, m_parameter(_T(""))
//	, m_unit(_T(""))
//	, m_value(_T(""))
	, m_tab(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplicationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_show);
	//DDX_Control(pDX, IDC_LIST1, 正方形);
	DDX_Text(pDX, IDC_EDIT3, m_parameter);
	//	DDX_Text(pDX, IDC_EDIT4, m_unit);
	//DDX_Text(pDX, IDC_EDIT5, m_value);
	DDX_Text(pDX, IDC_EDIT5, m_parameter);
	//DDX_Control(pDX, IDC_EDIT3, m_tab);
	DDX_Text(pDX, IDC_EDIT3, m_tab);
}

BEGIN_MESSAGE_MAP(CMFCApplicationDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_LBN_SELCHANGE(IDC_LIST1, &CMFCApplicationDlg::OnLbnSelchangeList1)
	//ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplicationDlg::OnBnClickedButton5)
	ON_EN_CHANGE(IDC_EDIT3, &CMFCApplicationDlg::OnEnChangeEdit3)
	//ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplicationDlg::OnBnClickedButton1)
	//ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplicationDlg::OnBnClickedButton8)
//	ON_BN_CLICKED(IDC_NUM1, &CMFCApplicationDlg::OnBnClickedNum1)
	//ON_BN_CLICKED(IDC_BUTTON17, &CMFCApplicationDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_CIRCLE, &CMFCApplicationDlg::OnBnClickedCircle)
	ON_BN_CLICKED(IDC_RECtangle, &CMFCApplicationDlg::OnBnClickedRectangle)
	ON_BN_CLICKED(IDC_SQUARE, &CMFCApplicationDlg::OnBnClickedSquare)
	ON_BN_CLICKED(IDC_TRIANGLE, &CMFCApplicationDlg::OnBnClickedTriangle)
	ON_BN_CLICKED(IDC_RADIO_CM, &CMFCApplicationDlg::OnBnClickedRadioCm)
	ON_BN_CLICKED(IDC_RADIO_INCH, &CMFCApplicationDlg::OnBnClickedRadioInch)
	ON_BN_CLICKED(IDC_EQUAL, &CMFCApplicationDlg::OnBnClickedEqual)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplicationDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CMFCApplicationDlg 消息处理程序

BOOL CMFCApplicationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplicationDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplicationDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplicationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}






void CMFCApplicationDlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void CMFCApplicationDlg::Calculate()
{
	UpdateData(TRUE);


	switch(m_iSign)
	{
	case 1:
		m_number1 = atof(m_parameter);//将编辑框的值返回为m_number1
		result = 3.14159*m_number1*m_number1;
		M_NUMBER1.Format("%g", m_number1);//将float转CString
		break;
	case 2:
		int i;//定义循环变量
		for (i = 0; i < 10; i++)
		{
			NUMBER1[i] = ' ';
			NUMBER2[i] = ' ';
		}//将两个数组清空
		if (m_parameter.GetAt(0) == ' ')
		{
			for (i = 1; i < m_parameter.GetLength(); i++)
			{
				if (m_parameter.GetAt(i) != ' '&&m_parameter.GetAt(i - 1) == ' ')//第一个点
				{
					point1 = i; break;
				}
			}
			for (i = 0; i < m_parameter.GetLength(); i++)
			{
				if (m_parameter.GetAt(i) != ' '&&m_parameter.GetAt(i - 1) == ' '&&i > point1)//第二个点
				{
					point2 = i; break;
				}
			}
		}
		else
		{
			point1 = 0;
			for (i = 0; i < m_parameter.GetLength(); i++)
			{
				if (m_parameter.GetAt(i) == ' '&&m_parameter.GetAt(i + 1) != ' '&&i > point1)
				{
					point2 = i + 1; break;
				}
			}
		}
			//分两种情况求出point1 point2
		for (i =point1; i < m_parameter.GetLength() && m_parameter.GetAt(i) != ' '; i++)
		{
			NUMBER1[i-point1]= m_parameter.GetAt(i);
		}
		NUMBER1[i] = '\0';
		for (i=point2; i <= m_parameter.GetLength() && m_parameter.GetAt(i) != ' '; i++)
		{
			NUMBER2[i-point2]= m_parameter.GetAt(i);
		}
		NUMBER2[i] = '\0';//识别字符串并将两个参数分别赋值
		M_NUMBER1 = NUMBER1;
		M_NUMBER2 = NUMBER2;//char转CString
		m_number1 = _ttof(M_NUMBER1);
		m_number2 = _ttof(M_NUMBER2);//CString转float
		result = m_number1 * m_number2;//求出结果
	// = 0;
		break;
	case 3://注释同case1
		m_number1=atof(m_parameter);
		result = m_number1 * m_number1;
		M_NUMBER1.Format("%g", m_number1);
		break;
	case 4://注释同case2
		int j;
		for (j = 0; j < 10; j++)
		{
			NUMBER1[j] = ' ';
			NUMBER2[j] = ' ';
		}
		if (m_parameter.GetAt(0) == ' ')
		{
			for (j = 1; j < m_parameter.GetLength(); j++)
			{
				if (m_parameter.GetAt(j) != ' '&&m_parameter.GetAt(j - 1) == ' ')//第一个点
				{
					point1 = j; break;
				}
			}
			for (j = 0; j < m_parameter.GetLength(); j++)
			{
				if (m_parameter.GetAt(j) != ' '&&m_parameter.GetAt(j - 1) == ' '&&j> point1)//第二个点
				{
					point2 = j; break;
				}
			}
		}
		else
		{
			point1 = 0;
			for (j = 0; j < m_parameter.GetLength(); j++)
			{
				if (m_parameter.GetAt(j) == ' '&&m_parameter.GetAt(j + 1) != ' '&&j > point1)
				{
					point2 = j + 1; break;
				}
			}
		}

		for (j = point1; j < m_parameter.GetLength() && m_parameter.GetAt(j)!= ' '; j++)
		{
			NUMBER1[j - point1] = m_parameter.GetAt(j);
		}
		NUMBER1[j] = '\0';
		for (j = point2; j <= m_parameter.GetLength() && m_parameter.GetAt(j) != ' '; j++)
		{
			NUMBER2[j - point2] = m_parameter.GetAt(j);
		}
			NUMBER2[j] = '\0';
		M_NUMBER1 = NUMBER1;
		M_NUMBER2 = NUMBER2;
		m_number1 = _ttof(M_NUMBER1);
		m_number2 = _ttof(M_NUMBER2);
		result = m_number1 * m_number2*0.5;
		//= 0;

		break;
	default:
		break;

	}
}

void CMFCApplicationDlg::Check()//检测函数，负责检测是否有不合法输入
{
	switch (m_iSign)
	{
	case 1:
    
	case 2:
		;
		break;
	case 3:
		;
		break;
	case 4:
		;
		break;
	default:
		break;

	}
}

void CMFCApplicationDlg::Transform()//转换函数，实现单位转换功能
{
	switch (m_iSign_unit)
	{
	case 1://单位厘米
		break;
	case 0://单位英寸
		result = result * 6.4516;
		break;
	default :
		break;
	}
	m_show.Format("%g", result);//将计算结果返回到m_show上
}

void CMFCApplicationDlg::Show()//展示功能，向使用者陈列参数和计算结果
{
	switch (m_iSign)
	{
	case 1:
		if (m_iSign_unit)
		MessageBox("输入半径为"+M_NUMBER1+"厘米"+"\t\r得出面积为"+m_show+"平方厘米");
		else
	    MessageBox("输入半径为" + M_NUMBER1 +"英寸"+ "\t\r得出面积为" + m_show + "平方厘米");
		break;
	case 2:
		if (m_iSign_unit)
			MessageBox("输入长为" + M_NUMBER1 + "厘米"+" 宽为" +M_NUMBER2+"厘米"+ "\t\r得出面积为" + m_show + "平方厘米");
		else
			MessageBox("输入长为" + M_NUMBER1 + "英寸" + " 宽为" + M_NUMBER2 +"英寸"+ "\t\r得出面积为" + m_show + "平方厘米");
		break;
	case 3:
		if (m_iSign_unit)
			MessageBox("输入边长为" + M_NUMBER1 + "厘米" + "\t\r得出面积为" + m_show + "平方厘米");
		else
			MessageBox("输入边长为" + M_NUMBER1 + "英寸" + "\t\r得出面积为" + m_show + "平方厘米");
		break;
	case 4:
		if (m_iSign_unit)
			MessageBox("输入底为" + M_NUMBER1 + "厘米" + " 高为" + M_NUMBER2 + "厘米" + "\t\r得出面积为" + m_show + "平方厘米");
		else
			MessageBox("输入底为" + M_NUMBER1 + "英寸" + " 高为" + M_NUMBER2 + "英寸" + "\t\r得出面积为" + m_show + "平方厘米");
		break;
	default:
		break;
	}

}

void CMFCApplicationDlg::OnBnClickedCircle()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_iSign = 1;//1状态代表圆
	m_tab = "请输入圆的半径";
	UpdateData(FALSE);
}


void CMFCApplicationDlg::OnBnClickedRectangle()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_iSign = 2;//2状态代表长方形
	m_tab = "请依次输入长方形的长和宽";
	UpdateData(FALSE);
}


void CMFCApplicationDlg::OnBnClickedSquare()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_iSign = 3;//3状态代表正方形
	m_tab = "请输入正方形的边长";
	UpdateData(FALSE);
}


void CMFCApplicationDlg::OnBnClickedTriangle()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_iSign = 4;//4状态代表三角形
	m_tab = "请依次输入三角形底和高";
	UpdateData(FALSE);
}

void CMFCApplicationDlg::OnBnClickedRadioCm()
{
	// TODO: 在此添加控件通知处理程序代码
	m_iSign_unit = 1;//1代表厘米
}


void CMFCApplicationDlg::OnBnClickedRadioInch()
{
	// TODO: 在此添加控件通知处理程序代码
	m_iSign_unit = 0;//0代表英寸
}


void CMFCApplicationDlg::OnBnClickedEqual()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	Check();
	Calculate();
	Transform();
	Show();
	UpdateData(FALSE);
}


void CMFCApplicationDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
