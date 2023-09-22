#pragma once
#include<iostream>
#include<string>
#include<windows.h>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

class WorkManager
{
public:
	WorkManager();
	~WorkManager();

	void exitsystem(HWND hChildWnd);
	void Add_Emp();

	int WorkerNum;//ְ��������
	//Worker** EmpArry;//ְ������
	//����ָ������һ��ָ��ָ�������
	//int* arr[5];  // �������͵�ָ������
	//int** p = arr;  // ָ��ָ�������ָ�루����ָ�룩
};

//ְ��������
class Worker 
{
public:
	//��ʾ������Ϣ
	virtual void showinfo() = 0;
	//��ȡ��λ����
	virtual CString getDeptName() = 0;

	int m_Id;//ְ�����
	CString m_Name;//ְ������
	int m_Dept;//���ű��
};

//ְ����
class Employee :public Worker
{
public:
	Employee(int id, CString name, int dId);
	//��ʾ������Ϣ
	virtual void showinfo();
	//��ȡ��λ����
	virtual CString getDeptName();
};

//������
class Manager :public Worker
{
public:
	Manager(int id, CString name, int dId);
	//��ʾ������Ϣ
	virtual void showinfo();
	//��ȡ��λ����
	virtual CString getDeptName();
};