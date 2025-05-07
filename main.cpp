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

int ru;
int main()
{
	while (1) {
		introduce();
		input(&ru,5,1);
		switch (ru)
		{
		case 1://成绩输入
			
			break;
		case 2://成绩导入
			
			break;
		case 3://成绩导出
			break;
		case 4://成绩查询
			break;
		case 5://成绩分析
			break;
		default:
			break;
		}
	}
}