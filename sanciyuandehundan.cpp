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

class Score{
	
};

void Menu_main(int* ru)
{
	while (1) {
		introduce_main();
		input(ru, 4, 1);
		switch (*ru)
		{
		case 1://�ɼ�����
			Menu_input(ru);
			break;
		case 2://�ɼ�����
			Menu_import(ru);
			break;
		case 3://�ɼ�����
			Menu_export(ru);
			break;
		case 4://�ɼ���ѯ
			Menu_view(ru);
			break;
		}
	}
}

void Menu_input(int* ru)
{
	introduce_input();
	input(ru, 11, 0);
}

void Menu_import(int* ru)
{
	introduce_import();
	input(ru, 2, 1);
}

void Menu_export(int* ru)
{
	introduce_export();
	input(ru, 2, 1);
}

void Menu_view(int* ru)
{
	introduce_view();
	input(ru, 2, 1);
}
