#pragma once
#define  _CRT_SECURE_NO_WARNINGS

// ����һЩ��ɫ����ʽ����
#define COLOR_TITLE "\033[1;36m"  // ��ɫ�Ӵ�
#define COLOR_MENU "\033[1;33m"  // ��ɫ�Ӵ�
#define COLOR_OPTION "\033[1;32m" // ��ɫ�Ӵ�
#define COLOR_RESET "\033[0m"     // ������ɫ

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