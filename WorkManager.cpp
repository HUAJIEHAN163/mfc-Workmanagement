#include"pch.h"
#include"WorkManager.h"

WorkManager::WorkManager()
{
    //this->WorkerNum = 500;//ְ��������
    //this->EmpArry = NULL;//ְ������
}

void WorkManager::Add_Emp()
{
    //�����¿ռ�
    //Worker** newSpace = new Worker*[WorkerNum];
    //��ԭ���ļ����ݵ���

    //
}

void WorkManager::exitsystem(HWND hChildWnd)
{
    int result = MessageBoxEx(hChildWnd, TEXT("��� ȷ�� �˳�"), TEXT("�˳�"), MB_ICONINFORMATION | MB_OKCANCEL, MB_USERICON);
    switch (result)/*ע�⣡ʹ��UnicodeӦ��TEXT��Χ�ִ�*/
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

//Ա�����Ա��������
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
    return TEXT("Ա��");
}

//������
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
    return TEXT("����");
}

WorkManager::~WorkManager()
{

}