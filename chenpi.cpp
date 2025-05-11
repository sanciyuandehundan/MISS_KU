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

//输出功能介绍，没有输入值，没有返回值
void Introduce_main() {
	system("cls");
	Top("射箭成绩统计与分析系统");
	cout << "1.手动输入成绩" << endl;
	cout << "2.导入成绩文件" << endl;
	cout << "3.导出成绩文件" << endl;
	cout << "4.查看过往成绩" << endl;
	cout << "5.选择成绩" << endl;
	cout << "要进行何种操作:";
}
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
void Introduce_import()
{
	Top("导入成绩文件");
}
void Introduce_export()
{
	Top("导出成绩文件");
}
void Introduce_view()
{
	Top("查看过往成绩");
}