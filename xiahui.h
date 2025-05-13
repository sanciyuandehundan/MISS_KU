#pragma once
#include "including.h"
#include "chenpi.h"
#include "sanciyuandehundan.h"
/*
ru 需要输入内容的变量的指针 max 输入最大值 min 输入最小值，要求输入错误不会导致崩溃，且再次出现输入提示，无需返回值
*/
void input(int* ru, int max, int min);

/*
从文件路径打开json文件并回传json类内容
*/
json* open_json(string s);