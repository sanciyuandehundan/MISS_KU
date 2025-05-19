#pragma once
#define  _CRT_SECURE_NO_WARNINGS

// 定义一些颜色和样式常量
#define COLOR_TITLE "\033[1;36m"  // 青色加粗
#define COLOR_MENU "\033[1;33m"  // 黄色加粗
#define COLOR_OPTION "\033[1;32m" // 绿色加粗
#define COLOR_RESET "\033[0m"     // 重置颜色

#include <iostream>
#include <ctime>
#include <cstdlib>
#include<stdio.h>
#include<stdlib.h>
#include<istream>
#include <fstream>
#include<string>
#include "json.hpp"
using json = nlohmann::json;
using namespace std;