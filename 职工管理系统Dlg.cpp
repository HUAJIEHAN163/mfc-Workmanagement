
// 职工管理系统Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "职工管理系统.h"
#include "职工管理系统Dlg.h"
#include "afxdialogex.h"
#include"WorkManager.h"


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


// C职工管理系统Dlg 对话框



C职工管理系统Dlg::C职工管理系统Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)
	, CString_Item(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C职工管理系统Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
	DDX_Text(pDX, IDC_EDIT1, CString_Item);
	DDX_Text(pDX, IDC_EDIT2, m_text);
	DDX_Control(pDX, IDC_EDIT2, m_EditText);
}

BEGIN_MESSAGE_MAP(C职工管理系统Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &C职工管理系统Dlg::OnBnClickedButtonExit)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &C职工管理系统Dlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_SHOW, &C职工管理系统Dlg::OnBnClickedButtonShow)
	ON_EN_CHANGE(IDC_EDIT1, &C职工管理系统Dlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// C职工管理系统Dlg 消息处理程序

BOOL C职工管理系统Dlg::OnInitDialog()
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

void C职工管理系统Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C职工管理系统Dlg::OnPaint()
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
HCURSOR C职工管理系统Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C职工管理系统Dlg::OnBnClickedButtonExit()
{
	// TODO: 在此添加控件通知处理程序代码
	// 获取子窗口对象指针,GetDlgItem有两个参数或一个参数，一个参数（控件ID）时必须用在对话框中，否则需要传入一个句柄
	CWnd* pChildWnd = CWnd::GetDlgItem(IDC_BUTTON_EXIT); 
	HWND hChildWnd = pChildWnd->GetSafeHwnd(); // 获取子窗口句柄
	WM.exitsystem(hChildWnd);
}


void C职工管理系统Dlg::OnBnClickedButtonAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	additem.DoModal();
}


void C职工管理系统Dlg::OnBnClickedButtonShow()
{
	// TODO: 在此添加控件通知处理程序代码
	//显示文档中的信息
	HANDLE hFile = CreateFile(_T("data.txt"), GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL,TEXT("无数据，请先添加"),MB_OK);
		CloseHandle(hFile);
	}
	else
	{
		char* hGlobal = (char*)GlobalAlloc(GPTR, GetFileSize(hFile, NULL));
		if (hGlobal == NULL)
		{
			CloseHandle(hFile);
		}
		else
		{
			ReadFile(hFile, hGlobal, GetFileSize(hFile, NULL), NULL, NULL);
			//string strNum = std::to_string(GetFileSize(hFile, NULL));
			//MessageBox(strNum, L"Title", MB_OK);
			int nWideLength = MultiByteToWideChar(CP_UTF8, 0, hGlobal, -1, NULL, 0);
			WCHAR* pwBuffer = new WCHAR[nWideLength];
			MultiByteToWideChar(CP_UTF8, 0, hGlobal, -1, pwBuffer, nWideLength);

			m_EditText.SetWindowTextW(pwBuffer);
			
			GlobalFree(hGlobal);
			delete[] pwBuffer;
			CloseHandle(hFile);
		}
	}
}



void C职工管理系统Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	//CString_Item = "test";
}
