#pragma once
#include "including.h"
#include "xiahui.h"
#include "chenpi.h"

class Score {
public:
	enum Target { hou = 1, huan_40_full = 2, huan_60_full = 3, huan_80_full = 4, huan_122_full = 5, huan_40_self = 6, huan_60_self = 7, huan_80_self = 8 };
	class Arrow {
	public:
		int ring;
		int position;
		Arrow(int r, int p);
	};
	class Round {
	public:
		Target target;
		int distance;
		int arrow_num;
		Arrow* arrows[24];
		Round(Target t, int d, int a);
		bool add_arrow(Arrow* arr);
	};
	class Game {
	public:
		Game* next;
		Game* prev;
		Target target;
		int distance;
		int round_num;
		int arrow_num;
		Round* rounds[24];
		bool add_round(Round* ro);
		Game* get_last();
		Game* get_anchor(int num);
		bool add_next(Game* ga);
	};
	string* master;
	Game* list_hand;
	long long game_num;
	long long round_num_all;
	long long arrow_num_all;
	long double lisan;

	bool add_game(Game* ga);
	bool Import(string filename);
	void Show();
	Score();
};
void Menu_main(int *ru,Score* s);
void Menu_input(int* ru, Score* s);
void Menu_import(int* ru, Score* s);
void Menu_export(int* ru, Score* s);
void Menu_view(int* ru, Score* s);
void Menu_scoremaster(int* ru, Score* s);