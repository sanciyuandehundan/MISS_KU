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
class Score {
public:
	enum Target { hou = 1, huan_40_full = 2, huan_60_full = 3, huan_80_full = 4, huan_122_full = 5, huan_40_self = 6, huan_60_self = 7, huan_80_self = 8 };
	class Round {
		Target target;
		int distance;
		int arrow_num;
	};
	class Game {
		Target target;
		int distance;
		int round_num;
		int arrow_num;
		Round* round[24];
	};
	string master;
	Game* list_hand;

	bool Import(string s);
	void Show();
	Score();

};
void Menu_main(int *ru,Score* s);
void Menu_input(int* ru, Score* s);
void Menu_import(int* ru, Score* s);
void Menu_export(int* ru, Score* s);
void Menu_view(int* ru, Score* s);
void Menu_scoremaster(int* ru, Score* s);