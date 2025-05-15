#include "including.h"
#include "xiahui.h"
#include "chenpi.h"
#include "sanciyuandehundan.h"

void to_json(nlohmann::json& j, const Score::Target& t) {
	j = static_cast<int>(t); // 转成整数写入
}
void from_json(const nlohmann::json& j, Score::Target& t) {
	t = static_cast<Score::Target>(j.get<int>());
}
void to_json(nlohmann::json& j, const time_t& t) {
	j = static_cast<long long>(t); // 转成整数写入
}
void from_json(const nlohmann::json& j, time_t& t) {
	t = static_cast<time_t>(j.get<long long>());
}

void Menu_main(int* ru, Score* s)
{
	while (1) {
		Introduce_main(s);
		input(ru, 5, 1);
		switch (*ru)
		{
		case 1://成绩输入
			Menu_input(ru, s);
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
	string pa;
	bool con = true;
	while (con) {
		Introduce_import(s);
		input(ru, 2, 1);
		switch (*ru)
		{
		case 1:
			cout << "请输入路径:";
			cin >> pa;
			s->Import(pa); break;
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
		case 1:s->Export(); break;
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

bool Score::Import(string filename)//缺少同归属者分支
{
	json* j = open_json(filename);
	if ((this->master == nullptr) || !(master->_Equal((*j)["master"]))) {
		master = new string((*j)["master"]);
		round_num_all = (*j)["round_num_all"];
		arrow_num_all = (*j)["arrow_num_all"];
		lisan = (*j)["lisan"];
		for (json& game_json : (*j)["game"]) {
			Game* game = new Game(game_json["time"]);
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
	else {

	}
}

bool Score::Export()
{
	ofstream file(*master + ".json");
	if (!file.is_open()) {
		cout << "打开文件失败" << endl;
		return false;
	}
	json j;
	j["master"] = *master;
	j["game_num"] = game_num;
	j["round_num_all"] = round_num_all;
	j["arrow_num_all"] = arrow_num_all;
	j["lisan"] = lisan;
	j["game"] = json::array();

	Game* temp = list_hand;
	while (temp != nullptr) {
		json j_g;
		j_g["target"] = temp->target;
		j_g["time"] = temp->gametime;
		j_g["distance"] = temp->distance;
		j_g["round_num"] = temp->round_num;
		j_g["arrow_num"] = temp->arrow_num;
		j_g["round"] = json::array();
		for (int i = 0; i < temp->round_num; ++i) {
			Round* r = temp->round[i];
			json j_r;
			j_r["target"] = r->target;
			j_r["distance"] = r->distance;
			j_r["arrow_num"] = r->arrow_num;
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
		temp = temp->next;
	}
	file << j.dump(4);
	cout << j.dump(4);
	system("pause");
	default_json(*master + ".json");
	file.close();
	return false;
}

void Score::Clear_all()
{
	Game* anchor1 = list_hand->get_last();
	Game* anchor2 = list_hand->get_last();
	for (long long i = 0; i < game_num; i++) {
		anchor2 = anchor1->prev;
		anchor1->Clear_all_round();
		delete anchor1;
		anchor1 = anchor2;
	}
	game_num = 0;
}

void Score::Clear(int index)
{
	Game* anchor = list_hand->get_anchor(index);
	if (anchor->prev != nullptr) {
		anchor->prev->next = anchor->next;
		if (anchor->next != nullptr)anchor->next->prev = anchor->prev;
	}
	anchor->Clear_all_round();
	delete anchor;
	game_num--;
}

bool Score::add_game(Game* ga)
{
	if (list_hand == nullptr) {
		list_hand = ga;
		ga->parent = this;
		round_num_all = list_hand->round_num;
		arrow_num_all = list_hand->arrow_num;
		game_num++;
		return false;
	}
	list_hand->get_last()->add_next(ga);
	ga->parent = this;
	round_num_all += ga->round_num;
	arrow_num_all += ga->arrow_num;
	game_num++;
	return true;
}

void Score::Show()
{
	Game* temp = list_hand;
	cout << "成绩归属者:" << master->c_str() << endl;
	cout << "总轮数:" << game_num << endl;
	cout << "总组数:" << round_num_all << endl;
	cout << "总箭数:" << arrow_num_all << endl;
	cout << "离散系数(越小越好):" << lisan << endl;
	//while (temp != nullptr) {

	//}
}

void Score::set_master()
{
	cout << "请输入欲修改归属者的名字:";
	cin >> *master;
}

Score::Score()
{
	Import((*open_json("default.json"))["path"]);
}

Score::Round::Round(Target t, int d)
{
	target = t;
	distance = d;
	arrow_num = 0;
}

bool Score::Round::add_arrow(Arrow* arr)
{
	if (arrow_num >= 23)return false;
	arr->parent = this;
	arrow[arrow_num] = arr;
	arrow_num++;
	parent->arrow_num++;
	parent->parent->arrow_num_all++;
	return true;
}

void Score::Round::Clear_arrow(int index)
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

void Score::Round::Clear_all_arrow()
{
	for (int i = 0; i < arrow_num; i++) {
		delete arrow[i];
	}
	parent->parent->arrow_num_all -= arrow_num;
	parent->arrow_num -= arrow_num;
	arrow_num = 0;
}

bool Score::Game::add_round(Round* ro)
{
	if (round_num >= 23)return false;
	ro->parent = this;
	round[round_num] = ro;
	round_num++;
	parent->round_num_all++;
	arrow_num += ro->arrow_num;
	return true;
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
	return true;
}

void Score::Game::Clear_round(int index)
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

void Score::Game::Clear_all_round()
{
	for (int i = 0; i < round_num; i++) {
		round[i]->Clear_all_arrow();
		delete round[i];
	}
	parent->round_num_all -= round_num;
	round_num = 0;
}

Score::Game::Game(time_t time)
{
	gametime = time;
	distance = 0;
	round_num = 0;
	arrow_num = 0;
}

Score::Arrow::Arrow(int r, int p)
{
	ring = r;
	position = p;
}