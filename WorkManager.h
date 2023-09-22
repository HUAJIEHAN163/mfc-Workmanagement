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

	int WorkerNum;//职工总人数
	//Worker** EmpArry;//职工数组
	//二级指针声明一个指向指针的数组
	//int* arr[5];  // 整数类型的指针数组
	//int** p = arr;  // 指向指针数组的指针（二级指针）
};

//职工抽象类
class Worker 
{
public:
	//显示个人信息
	virtual void showinfo() = 0;
	//获取岗位名称
	virtual CString getDeptName() = 0;

	int m_Id;//职工编号
	CString m_Name;//职工姓名
	int m_Dept;//部门编号
};

//职工类
class Employee :public Worker
{
public:
	Employee(int id, CString name, int dId);
	//显示个人信息
	virtual void showinfo();
	//获取岗位名称
	virtual CString getDeptName();
};

//经理类
class Manager :public Worker
{
public:
	Manager(int id, CString name, int dId);
	//显示个人信息
	virtual void showinfo();
	//获取岗位名称
	virtual CString getDeptName();
};