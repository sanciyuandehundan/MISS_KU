#include "including.h"
#include "xiahui.h"
#include "chenpi.h"
#include "sanciyuandehundan.h"

void Menu_main(int* ru, Score* s)
{
	while (1) {
		Introduce_main(s);
		input(ru, 5, 1);
		switch (*ru)
		{
		case 1://成绩输入
			Menu_input(ru,s);
			break;
		case 2://成绩导入
			Menu_import(ru, s);
			break;
		case 3://成绩导出
			Menu_export(ru, s);
			break;
		case 4://成绩查询
			Menu_view(ru, s);
			break;
		case 5://成绩归属
			Menu_scoremaster(ru, s);
			break;
		}
	}
}

void Menu_input(int* ru, Score* s)
{
	bool con = true;
	while (con) {
		Introduce_input(s);
		input(ru, 6, 1);
		switch (*ru)
		{
		case 1:cout << "未实现" << endl; system("pause"); break;
		case 2:cout << "未实现" << endl; system("pause"); break;
		case 3:cout << "未实现" << endl; system("pause"); break;
		case 4:cout << "未实现" << endl; system("pause"); break;
		case 5:cout << "未实现" << endl; system("pause"); break;
		case 6:con = false; break;
		default:
			break;
		}
	}
}

void Menu_import(int* ru, Score* s)
{
	bool con = true;
	while (con) {
		Introduce_import(s);
		input(ru, 2, 1);
		switch (*ru)
		{
		case 1:cout << "未实现" << endl; system("pause"); break;
		case 2:con = false; break;
		default:
			break;
		}
	}
}

void Menu_export(int* ru, Score* s)
{
	bool con = true;
	while (con) {
		Introduce_export(s);
		input(ru, 2, 1);
		switch (*ru)
		{
		case 1:cout << "未实现" << endl; system("pause"); break;
		case 2:con = false; break;
		default:
			break;
		}
	}
}

void Menu_view(int* ru, Score* s)
{
	Introduce_view(s);
}

void Menu_scoremaster(int* ru, Score* s)
{
	bool con = true;
	while (con) {
		Introduce_scoremaster(s);
		input(ru, 3, 1);
		switch (*ru)
		{
		case 1:cout << "未实现" << endl; system("pause"); break;
		case 2:cout << "未实现" << endl; system("pause"); break;
		case 3:con = false; break;
		default:
			break;
		}
	}
}

bool Score::Import(string filename)
{
	json* j = open_json(filename);
	this->master = new string((*j)["master"]);
	this->game_num = (*j)["game_num"];
	this->round_num_all = (*j)["round_num_all"];
	this->arrow_num_all = (*j)["arrow_num_all"];
	this->lisan = (*j)["lisan"];
	for (json& game_json : (*j)["game"]) {
		Game* game = new Game();
		game->target = static_cast<Target>(game_json["target"]);
		game->distance = game_json["distance"];
		game->round_num = game_json["round_num"];
		game->arrow_num = game_json["arrow_num"];

		for (json& round_json : game_json["round"]) {
			Round* round = new Round(static_cast<Target>(round_json["target"]), round_json["distance"], round_json["arrow_num"]);

			for (json& arrow_json : round_json["arrow"]) {
				round->add_arrow(new Arrow(arrow_json["ring"], arrow_json["position"]));
			}
			game->add_round(round);
		}
		this->add_game(game);
	}
	return true;
}

bool Score::add_game(Game* ga)
{
	if (list_hand == nullptr) {
		list_hand = ga;
	}
	list_hand->get_last()->add_next(ga);
	return true;
}

void Score::Show()
{
	Game* temp=list_hand;
	cout << "成绩归属者:" << master->c_str()<<endl;
	cout << "总轮数:" << game_num<<endl;
	cout << "总组数:" << round_num_all<<endl;
	cout << "总箭数:" << arrow_num_all<<endl;
	cout << "离散系数(越小越好):" << lisan << endl;
	for (long long i = 0; i < game_num; i++) {
		
	}
}

Score::Score()
{
	Import((*open_json("default.json"))["path"]);
}

Score::Round::Round(Target t, int d, int a)
{
	target = t;
	distance = d;
	arrow_num = a;
}

bool Score::Round::add_arrow(Arrow* arr)//aaaaaa
{
	return false;
}

bool Score::Game::add_round(Round* ro)//aaaaaa
{
	return false;
}

Score::Game* Score::Game::get_last()
{
	return this->next == nullptr ? this : this->next->get_last();
}

Score::Game* Score::Game::get_anchor(int num)
{
	return num ? next->get_anchor(num - 1) : this;
}

bool Score::Game::add_next(Game* ga)
{
	next = ga;
	ga->prev = this;
	return false;
}

Score::Arrow::Arrow(int r, int p)
{
	ring = r;
	position = p;
}
