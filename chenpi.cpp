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

//������ܽ��ܣ�û������ֵ��û�з���ֵ
void Introduce_main() {
	system("cls");
	Top("����ɼ�ͳ�������ϵͳ");
	cout << "1.�ֶ�����ɼ�" << endl;
	cout << "2.����ɼ��ļ�" << endl;
	cout << "3.�����ɼ��ļ�" << endl;
	cout << "4.�鿴�����ɼ�" << endl;
	cout << "5.ѡ��ɼ�" << endl;
	cout << "Ҫ���к��ֲ���:";
}
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
void Introduce_import()
{
	Top("����ɼ��ļ�");
}
void Introduce_export()
{
	Top("�����ɼ��ļ�");
}
void Introduce_view()
{
	Top("�鿴�����ɼ�");
}