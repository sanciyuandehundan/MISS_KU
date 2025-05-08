#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <cstdlib>
#include<stdio.h>
#include<stdlib.h>
#include "xiahui.h"
#include "chenpi.h"
#include "sanciyuandehundan.h"
using namespace std;



void Top(const char* c)
{
	cout << "——————" << c << "——————" << endl;
}

/*
主界面介绍,输入范围4~1
*/
void Introduce_main() {
	system("cls");
	Top("射箭成绩统计与分析系统");
	cout << "1.手动输入成绩" << endl;
	cout << "2.导入成绩文件" << endl;
	cout << "3.导出成绩文件" << endl;
	cout << "4.查看过往成绩" << endl;
	cout << "要进行何种操作:";
}

/*
手动输入界面介绍,输入范围4~1
*/
void Introduce_input()
{
	system("cls");
	Top("手动输入数据");
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
}

/*
导入界面介绍,输入范围4~1
*/
void Introduce_import()
{
	system("cls");
	Top("导入成绩文件");
}

/*
导出界面介绍,输入范围4~1
*/
void Introduce_export()
{
	system("cls");
	Top("导出成绩文件");
}

/*
查询界面介绍,输入范围4~1
*/
void Introduce_view()
{
	system("cls");
	Top("查看过往成绩");
}