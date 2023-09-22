// ADDITEM.cpp: 实现文件
//

#include "pch.h"
#include "职工管理系统.h"
#include"职工管理系统Dlg.h"
#include "afxdialogex.h"
#include "ADDITEM.h"
#include"WorkManager.h"


// ADDITEM 对话框

IMPLEMENT_DYNAMIC(ADDITEM, CDialogEx)

ADDITEM::ADDITEM(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADDITEM, pParent)
	, m_name(_T(""))
	, m_id(0)
	, m_did(0)
{

}

ADDITEM::~ADDITEM()
{
}

void ADDITEM::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_name);
	DDX_Text(pDX, IDC_EDIT1, m_id);
	DDX_Text(pDX, IDC_EDIT3, m_did);
}


BEGIN_MESSAGE_MAP(ADDITEM, CDialogEx)
	ON_BN_CLICKED(IDOK, &ADDITEM::OnBnClickedOk)
END_MESSAGE_MAP()


// ADDITEM 消息处理程序

void ADDITEM::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);

	//在响应函数中，获取主窗口的指针。你可以使用AfxGetMainWnd函数来获取主窗口的指针
	C职工管理系统Dlg* pMainFrame = (C职工管理系统Dlg*)AfxGetMainWnd();
	//获取主窗口的编辑控件对象
	CEdit* pEditMain = (CEdit*)pMainFrame->GetDlgItem(IDC_EDIT1);
	//使用编辑控件对象的相应成员函数来更新数据
	Worker *worker = NULL;
	CString DeptName;
	switch (m_did)
	{
	case 1:
		worker = new Employee(m_id, m_name, m_did);
		DeptName = worker->getDeptName();
		delete worker;
		break;
	case 2:
		worker = new Manager(m_id, m_name, m_did);
		DeptName = worker->getDeptName();
		delete worker;
		break;
	default:
		break;
	}
	
	CString strText;
	strText = 
		TEXT("员工编号：") + (CString(std::to_string(m_id).c_str())) + 
		TEXT(" 员工名字：") + m_name + 
		TEXT(" 员工部门：") + DeptName;

	// 打开文件以追加写入的方式
//windows api操作文件练习
//HANDLE fn = CreateFile(Filename, GENERIC_READ,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
//LPBYTE lpWrk = (LPBYTE)GlobalAlloc(GPTR,GetFileSize(fn,NULL));
//if (lpWrk == NULL)
//{
//	CloseHandle(fn);
//}
//ReadFile(fn, lpWrk, GetFileSize(fn, NULL), NULL, NULL);
//WriteFile(fn, lpWrk, GetFileSize(fn, NULL), NULL, NULL);
//CloseHandle(fn);

	HANDLE hFile = CreateFile(_T("data.txt"), FILE_APPEND_DATA, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		// 将文件指针移动到文件末尾
		SetFilePointer(hFile, 0, NULL, FILE_END);

		// 将宽字符转换为多字节字符串
		int length = WideCharToMultiByte(CP_UTF8, 0, strText.GetString(), -1, nullptr, 0, nullptr, nullptr);
		string utf8Str(length, '\0');//指定的长度初始化了一个名为 utf8Str 的字符串，用空字符 '\0' 填充。
		WideCharToMultiByte(CP_UTF8, 0, strText.GetString(), -1, &utf8Str[0], length, nullptr, nullptr);

		// 将字符串写入文件
		WriteFile(hFile, utf8Str.c_str(), static_cast<DWORD>(utf8Str.length()), NULL, NULL);
		
		// 将文件指针移动到文件末尾并换行
		SetFilePointer(hFile, 0, NULL, FILE_END);
		const char* newline = "\r\n";
		WriteFile(hFile, newline, strlen(newline), NULL, NULL);

		// 关闭文件句柄
		CloseHandle(hFile);
	}

	//在控件当中显示文本数据
	// 假设你从子窗口获得了新的文本数据存储在strText中
	pEditMain->SetWindowText(strText);

	// 调用父类的 OnOK 函数以执行默认操作（关闭对话框）
	CDialogEx::OnOK();
}
