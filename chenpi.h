#pragma once
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <cstdlib>
#include<stdio.h>
#include<stdlib.h>
#include<istream>
#include<string>
#include "xiahui.h"
#include "chenpi.h"
#include "sanciyuandehundan.h"
using namespace std;

/*
������ұ�������Χ�ı���
*/
void Top(const char* c);
/*
���������,���뷶Χ5~1
*/
void Introduce_main(Score* s);
/*
�ֶ�����������,���뷶Χ6~1
*/
void Introduce_input(Score* s);
/*
����������,���뷶Χ2~1
*/
void Introduce_import(Score* s);
/*
�����������,���뷶Χ2~1
*/
void Introduce_export(Score* s);
/*
��ѯ�������,���뷶Χ��
*/
void Introduce_view(Score* s);
/*
�޸ĳɼ������߽���,���뷶Χ3~1
*/
void Introduce_scoremaster(Score* s);