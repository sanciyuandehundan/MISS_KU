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
	cout << "������������" << c << "������������" << endl;
}

/*
���������,���뷶Χ4~1
*/
void Introduce_main() {
	system("cls");
	Top("����ɼ�ͳ�������ϵͳ");
	cout << "1.�ֶ�����ɼ�" << endl;
	cout << "2.����ɼ��ļ�" << endl;
	cout << "3.�����ɼ��ļ�" << endl;
	cout << "4.�鿴�����ɼ�" << endl;
	cout << "Ҫ���к��ֲ���:";
}

/*
�ֶ�����������,���뷶Χ4~1
*/
void Introduce_input()
{
	system("cls");
	Top("�ֶ���������");
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
}

/*
����������,���뷶Χ4~1
*/
void Introduce_import()
{
	system("cls");
	Top("����ɼ��ļ�");
}

/*
�����������,���뷶Χ4~1
*/
void Introduce_export()
{
	system("cls");
	Top("�����ɼ��ļ�");
}

/*
��ѯ�������,���뷶Χ4~1
*/
void Introduce_view()
{
	system("cls");
	Top("�鿴�����ɼ�");
}