#include"pch.h"
#include"WorkManager.h"

WorkManager::WorkManager()
{
    //this->WorkerNum = 500;//职工总人数
    //this->EmpArry = NULL;//职工数组
}

void WorkManager::Add_Emp()
{
    //开辟新空间
    //Worker** newSpace = new Worker*[WorkerNum];
    //将原来文件数据导入

    //
}

void WorkManager::exitsystem(HWND hChildWnd)
{
    int result = MessageBoxEx(hChildWnd, TEXT("点击 确认 退出"), TEXT("退出"), MB_ICONINFORMATION | MB_OKCANCEL, MB_USERICON);
    switch (result)/*注意！使用Unicode应用TEXT包围字串*/
    {
        case IDOK:
          exit(0); 
          break;
        case IDCANCEL:
            break;
        default:
            break;
    }
}

//员工类成员函数定义
Employee::Employee(int id, CString name, int dId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_Dept = dId;
}

void Employee::showinfo()
{
    CString deptname;
    deptname = this->getDeptName();
}

CString Employee::getDeptName()
{
    return TEXT("员工");
}

//经理类
Manager::Manager(int id, CString name, int dId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_Dept = dId;
}

void Manager::showinfo()
{
    CString deptname;
    deptname = CString(this->getDeptName());
}

CString Manager::getDeptName()
{
    return TEXT("经理");
}

WorkManager::~WorkManager()
{

}