#include "including.h"
#include "xiahui.h"
#include "chenpi.h"
#include "sanciyuandehundan.h"

void to_json(nlohmann::json& j, const Log::Target& t) {
	j = static_cast<int>(t); // 转成整数写入
}
void from_json(const nlohmann::json& j, Log::Target& t) {
	t = static_cast<Log::Target>(j.get<int>());
}
void to_json(nlohmann::json& j, const time_t& t) {
	j = static_cast<long long>(t); // 转成整数写入
}
void from_json(const nlohmann::json& j, time_t& t) {
	t = static_cast<time_t>(j.get<long long>());
}

void Menu_main(Log* s)
{
	bool con = true;
	int ru;
	while (con) {
		Introduce_main(s);
		input(&ru, 5, 1);
		switch (ru)
		{
		case 1://成绩输入
			Menu_input(s);
			break;
		case 2://成绩导入
			Menu_import(s);
			break;
		case 3://成绩导出
			Menu_export(s);
			break;
		case 4://成绩查询
			Menu_view(s);
			break;
		case 5://关闭程序
			s->Export();
			con = false;
			break;
		}
	}
}
//T

void Menu_input(Log* s)///////////////////////////////////////////////////////////////////
{
	bool con = true;
	int ru;
	while (con) {
		Introduce_input(s);
		input(&ru, 3, 1);
		switch (ru)
		{
		case 1:
			//rectangle_one_row("修改现有数据"); 
			Menu_input_edit(s);
			break;
		case 2:
			//rectangle_one_row("添加新数据"); 
			Menu_input_add(s);
			break;
		case 3:con = false; break;
		default:
			break;
		}
	}
}

void Menu_input_add(Log* s)
{

}

void Menu_input_edit(Log* s)
{
	s->Show();
	rectangle_one_row("请选择要修改的比赛数据");
	int ru,index;
	input(&index, s->game_num, 1);
	output("操作类型:\n1.修改\n2.删除\n3.选择轮次数据\n");
	input(&ru, 3, 1);
	switch (ru)
	{
	case 1:
		Menu_input_edit_edit(s);
		break;
	case 2:
		Menu_input_edit_delete(s);
		break;
	}
}

void Menu_input_edit_edit(Log* s)
{
	//int index = *ru;
	int ru;
	rectangle_one_row("请选择要修改的数据项");
	output("1.靶子类型\n2.距离\n");
	input(&ru, 2, 1);
}

void Menu_input_edit_delete(Log* s)
{
	//s->Clear(*ru - 1);
}

void Menu_import(Log* s)
{
	int ru;
	string pa;
	bool con = true;
	while (con) {
		Introduce_import(s);
		input(&ru, 2, 1);
		switch (ru)
		{
		case 1:
			cout << COLOR_RESET;
			cout << COLOR_OPTION << "请输入路径: " << COLOR_RESET;
			cin >> pa;
			s->Import(pa); break;
		case 2:con = false; break;
		default:
			break;
		}
	}
}
//T

void Menu_export(Log* s)
{
	int ru;
	bool con = true;
	while (con) {
		Introduce_export(s);
		input(&ru, 2, 1);
		switch (ru)
		{
		case 1:s->Export(); break;
		case 2:con = false; break;
		default:
			break;
		}
	}
}
//T

void Menu_view(Log* s)
{
	Introduce_view(s);
	s->Show();
}

void Menu_scoremaster(Log* s)
{
	int ru;
	bool con = true;
	while (con) {
		Introduce_scoremaster(s);
		input(&ru, 3, 1);
		switch (ru)
		{
		case 1:s->set_master(); break;
		case 2:
			s->Export();
			s->Clear_all();
			s->set_master();
			break;
		case 3:con = false; break;
		default:
			break;
		}
	}
}
//D

void Menu_delete(Log* s)
{
	int ru;
	bool con = true;
	while (con) {
		if (s->game_num == 0) {
			rectangle_one_row("已无可删除内容");
			con = false;
			continue;
		}
		Introduce_delete(s);
		input(&ru, 2, 0);
		switch (ru)
		{
		case 0:
			s->Show();
			input(&ru, s->game_num, 1);
			s->Clear(0);
			break;
		case 1:
			s->Clear_all(); 
			con = false;
			break;
		case 2:con = false;
		}
	}
}
//D

bool Log::Import(string filename)
{
	json* j = open_json(filename);
	if (j == nullptr) {
		rectangle_one_row("无法导入此文件");
		system("pause");
		return false;
	}
	if ((this->master == nullptr) || !(master->_Equal((*j)["master"]))) {
		master = new string((*j)["master"]);
	}
	for (json& game_json : (*j)["game"]) {
		Game* game = new Game(game_json["time"]);
		if (Check_same(game)) {
			delete game;
			continue;
		}
		game->target = game_json["target"];
		game->distance = game_json["distance"];
		this->add_game(game);

		for (json& round_json : game_json["round"]) {
			Round* round = new Round(round_json["target"], round_json["distance"]);
			game->add_round(round);
			for (json& arrow_json : round_json["arrow"]) {
				round->add_arrow(new Arrow(arrow_json["ring"], arrow_json["position"]));
			}
		}
	}
	delete j;
	return true;
}
//T

bool Log::Export()
{
	ofstream file(*master + ".json");
	if (!file.is_open()) {
		output("打开文件失败");
		return false;
	}
	json j;
	j["master"] = *master;
	j["game"] = json::array();

	for (Game* temp : game) {
		json j_g;
		j_g["target"] = temp->target;
		j_g["time"] = temp->gametime;
		j_g["distance"] = temp->distance;
		j_g["round"] = json::array();
		for (int i = 0; i < temp->round_num; ++i) {
			Round* r = temp->round[i];
			json j_r;
			j_r["target"] = r->target;
			j_r["distance"] = r->distance;
			j_r["arrow"] = json::array();
			for (int k = 0; k < r->arrow_num; ++k) {
				Arrow* a = r->arrow[k];
				json j_a;
				j_a["ring"] = a->ring;
				j_a["position"] = a->position;
				j_r["arrow"].push_back(j_a);
			}
			j_g["round"].push_back(j_r);
		}
		j["game"].push_back(j_g);
	}
	file << j.dump(4);
	system("pause");
	default_json(*master + ".json");
	file.close();
	return true;
}
//T

void Log::Clear_all()
{
	for (Game* g : game) {
		g->Clear_all_round();
		delete g;
	}
	game_num = 0;
	game.resize(0);
}
//T

void Log::Clear(int index)
{
	Game* g = game[index];
	for (int i = index; i < game_num - 1; i++) {
		game[i] = game[i + 1];
	}
	if (game_num > 1)game[game_num] = nullptr;
	g->Clear_all_round();
	delete g;
	game_num--;
	game.resize(game.size() - 1);
}
//T

void Log::add_game(Game* ga)
{
	ga->parent = this;
	game.push_back(ga);
	game_num++;
}
//T

void Log::Show()
{
	rectangle_one_row("成绩归属者:" + *master);
	rectangle_one_row("总轮数:" + to_string(game_num));
	rectangle_one_row("总组数:" + to_string(round_num_all));
	rectangle_one_row("总箭数:" + to_string(arrow_num_all));
	rectangle_one_row("离散值(越小越好):" + to_string(lisan));
	string o = "编号          时间                          离散值     总成绩       靶子类型    距离\n";
	string t;
	int i = 1;
	for (Game* g : game) {
		t = ctime(&(g->gametime));
		o += format("{:<14d}", i++) + format("{:<30s}", t.substr(0, t.find_last_not_of("\r\n") + 1)) + format("{:<11.4f}", lisan) + format("{:0>3d}/{:<9d}", g->Score(), g->Score_full()) + format("{:<12s}", TargetToString(g->target)) + format("{:<d}米", g->distance) + "\n";
	}
	output(o);
	//rectangle_one_row(o);
}

void Log::set_master()
{
	cout << COLOR_RESET;
	cout << COLOR_OPTION << "请输入欲修改归属者的名字: " << COLOR_RESET;
	cin >> *master;
}

Log::Log()
{
	if (!Import((*open_json("default.json"))["path"])) {
		rectangle_one_row("无法打开上次打开的文件");
		system("pause");
	}
}

int Log::Round::Score()
{
	int re = 0, i, j;
	for (j = 0; j < arrow_num; j++) {
		re += arrow[j]->ring;
		if (arrow[j]->ring == 11)re--;
	}
	return re;
}

int Log::Round::Score_full()
{
	return arrow_num * (target == hou ? 5 : 10);
}

void Log::Round::Show_arrow()
{
	string o = "编号      环    方位\n";
	int in = 1;
	for (int i = 0; i < arrow_num; i++) {
		o += format("{:<14d}", in++) + format("{:<d}", arrow[i]->ring) + format("{:<d}点钟方向", arrow[i]->position) + "\n";
	}
	output(o);
	//rectangle_one_row(o);
}

Log::Round::Round(Target t, int d)
{
	target = t;
	distance = d;
	arrow_num = 0;
}

bool Log::Round::add_arrow(Arrow* arr)
{
	if (arrow_num >= 23)return false;
	arr->parent = this;
	arrow[arrow_num] = arr;
	arrow_num++;
	parent->arrow_num++;
	parent->parent->arrow_num_all++;
	return true;
}

void Log::Round::Clear_arrow(int index)
{
	Arrow* anchor = arrow[index];
	for (int i = index; i < arrow_num - 1; i++) {
		arrow[i] = arrow[i + 1];
	}
	arrow[arrow_num] = nullptr;
	arrow_num--;
	parent->arrow_num--;
	parent->parent->arrow_num_all--;
	delete anchor;
}

void Log::Round::Clear_all_arrow()
{
	for (int i = 0; i < arrow_num; i++) {
		delete arrow[i];
	}
	parent->parent->arrow_num_all -= arrow_num;
	parent->arrow_num -= arrow_num;
	arrow_num = 0;
}

void Log::Game::Show_round()
{
	string o = "编号      箭矢总数    离散值     总成绩       靶子类型    距离\n";
	int in = 1;
	for (int i = 0; i < round_num; i++) {
		o += format("{:<14d}", in++) + format("{:<d}", round[i]->arrow_num) + format("{:<11.4f}", round[i]->lisan) + format("{:0>3d} / {:<9d}", round[i]->Score(), round[i]->Score_full()) + format("{:<12s}", TargetToString(round[i]->target)) + format("{:<d}米", round[i]->distance) + "\n";
	}
	output(o);
	//rectangle_one_row(o);
}

int Log::Game::Score_full()
{
	return round_num * arrow_num * (target == hou ? 5 : 10);
}

int Log::Game::Score()
{
	int re = 0, i, j;
	for (i = 0; i < round_num; i++) {
		for (j = 0; j < arrow_num; j++) {
			re += round[i]->arrow[j]->ring;
			if (round[i]->arrow[j]->ring == 11)re--;
		}
	}
	return re;
}

bool Log::Game::add_round(Round* ro)
{
	if (round_num >= 23)return false;
	ro->parent = this;
	round[round_num] = ro;
	round_num++;
	parent->round_num_all++;
	arrow_num += ro->arrow_num;
	return true;
}

void Log::Game::Clear_round(int index)
{
	Round* anchor = round[index];
	for (int i = index; i < round_num - 1; i++) {
		round[i] = round[i + 1];
	}
	round[round_num] = nullptr;
	anchor->Clear_all_arrow();
	delete anchor;
	parent->round_num_all--;
	round_num--;
}

void Log::Game::Clear_all_round()
{
	for (int i = 0; i < round_num; i++) {
		round[i]->Clear_all_arrow();
		delete round[i];
	}
	parent->round_num_all -= round_num;
	round_num = 0;
}

Log::Game::Game(time_t time)
{
	parent = nullptr;
	gametime = time;
	distance = 0;
	round_num = 0;
	arrow_num = 0;
}

Log::Arrow::Arrow(int r, int p)
{
	parent = nullptr;
	ring = r;
	position = p;
}

bool Log::Check_same(Game* g)
{
	for (Game* ga : game) {
		if (ga->gametime == g->gametime)return true;
	}
	return false;
}

const char* Log::TargetToString(Target ta)
{
	switch (ta)
	{
	case Log::hou:
		return "侯靶";
		break;
	case Log::huan_40_full:
		return "40全环靶";
		break;
	case Log::huan_60_full:
		return "60全环靶";
		break;
	case Log::huan_80_full:
		return "80全环靶";
		break;
	case Log::huan_122_full:
		return "122全环靶";
		break;
	case Log::huan_40_self:
		return "40半环靶";
		break;
	case Log::huan_60_self:
		return "60半环靶";
		break;
	case Log::huan_80_self:
		return "80半环靶";
		break;
	default:
		return "";
		break;
	}
}
