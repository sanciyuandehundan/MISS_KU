#include "including.h"
#include "xiahui.h"
#include "chenpi.h"
#include "sanciyuandehundan.h"

void to_json(nlohmann::json& j, const Log::Target& t) {
	j = static_cast<int>(t); // ת������д��
}
void from_json(const nlohmann::json& j, Log::Target& t) {
	t = static_cast<Log::Target>(j.get<int>());
}
void to_json(nlohmann::json& j, const time_t& t) {
	j = static_cast<long long>(t); // ת������д��
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
		input(&ru, 7, 1);
		switch (ru)
		{
		case 1://�ɼ��޸�
			Menu_game(s);
			break;
		case 2://�ɼ����
			Menu_addgame(s);
			break;
		case 3://�ɼ�����
			Menu_import(s);
			break;
		case 4://�ɼ�����
			Menu_export(s);
			break;
		case 5://�ɼ���ѯ
			Menu_view(s);
			break;
		case 6:
			Menu_Logmaster(s);
			break;
		case 7://�رճ���
			s->Export();
			con = false;
			break;
		}
	}
}

void Menu_game(Log* s)
{
	system("cls");
	Top("�༭���гɼ�");
	if (!s->Show()) {
		Stop();
		return;
	}
	output("��ѡ��Ҫ�޸ĵı�������");
	int ru, index;
	input(&index, s->game_num, 1);
	index--;
	system("cls");
	Top("���������޸�");
	Log::Game* g = s->game[index];
	g->Show_round();
	output("��������:\n1.����ִ�\n2.�޸�\n3.ɾ��\n4.ѡ���ִ�����\n");
	input(&ru, 4, 1);
	switch (ru)
	{
	case 1:
		Menu_game_addround(g);
		break;
	case 2:
		Menu_game_amend(g);
		break;
	case 3:
		s->Clear(index);
		break;
	case 4:
		Menu_game_round(g);
		break;
	}
}

void Menu_game_amend(Log::Game* g)
{
	int ru;
	system("cls");
	Top("�޸ı�������");
	output("1.��������\n2.����\n��ѡ��Ҫ�޸ĵ�������");
	input(&ru, 2, 1);
	switch (ru)
	{
	case 1:
		output("1.���\n2.40ȫ����\n3.60ȫ����\n4.80ȫ����\n5.122ȫ����\n6.40�뻷��\n7.60�뻷��\n8.80�뻷��\n���������޸ĵİ�������");
		input(&ru, 8, 1);
		g->target = static_cast<Log::Target>(ru);
		break;
	case 2:
		output("���������޸ĵľ���(��)");
		input(&ru, 2100000000, 0);
		g->distance = ru;
		break;
	}
}

void Menu_game_addround(Log::Game* g)
{
	system("cls");
	Top("����ִ�");
	bool con = true;
	int r, p;
	Log::Arrow* a;
	Log::Round* ro = new Log::Round();
	if (!g->add_round(ro)) {
		output("�Ѵﵥ�α����ִ�����,�޷����");
		return;
	}
	while (con) {
		system("cls");
		Top("��¼��ʸ����");
		ro->Show_arrow();
		output("�������������\n1.��Ӽ�ʸ\n2.�˳���¼");
		input(&r, 2, 1);
		switch (r)
		{
		case 1:
			output("�����뻷" + (string)((g->target == Log::Target::hou) ? ("(���Ļ�5+����6)(M����0)") : ("(����X����11)(M����0)")));
			input(&r, (g->target == Log::Target::hou ? 6 : 11), 0);
			if (r != 6 && r != 11 && r != 0) {
				output("�����뷽λ(12����12���ӷ���,�Դ�����)");
				input(&p, 12, 1);
			}
			else {
				p = 0;
			}
			a = new Log::Arrow(r, p);
			if (!ro->add_arrow(a)) {
				output("�Ѵﵥ�ּ�ʸ����,�޷����");
				con = false;
			}
			break;
		case 2:
			con = false;
			break;
		}
	}
}

void Menu_addgame(Log* s)
{
	system("cls");
	Top("��ӱ�����¼");
	bool con = true;
	int tar, dis;
	Log::Game* g;
	output("1.���\n2.40ȫ����\n3.60ȫ����\n4.80ȫ����\n5.122ȫ����\n6.40�뻷��\n7.60�뻷��\n8.80�뻷��\n����������ð�");
	input(&tar, 8, 1);
	output("�������������(��)");
	input(&dis, 2100000000, 0);
	g = new Log::Game(time(0));
	g->target = static_cast<Log::Target>(tar);
	g->distance = dis;
	s->add_game(g);
	while (con)
	{
		system("cls");
		Top("����ִμ�¼");
		output("1.����ִ�\n2.����\n�������������");
		input(&tar, 2, 1);
		switch (tar)
		{
		case 1:
			Menu_game_addround(g);
			break;
		case 2:
			con = false;
			break;
		}
	}
}

void Menu_game_round(Log::Game* g)
{
	system("cls");
	Top("�޸��ִ�����");
	bool con = true;
	if (!g->Show_round()) {
		Stop();
		return;
	}
	output("��ѡ��Ҫ�޸ĵ��ִ�����");
	int ru, index, r, p;
	Log::Arrow* a;
	input(&index, g->round_num, 1);
	index--;
	Log::Round& ro = *(g->round[index]);
	while (con) {
		system("cls");
		Top("�޸��ִ�����");
		output("��������:\n1.��Ӽ�ʸ\n2.ɾ����ʸ\n3.ɾ�����ִ�\n4.����");
		input(&ru, 4, 1);
		switch (ru)
		{
		case 1:
			output("�����뻷" + (string)((g->target == Log::Target::hou) ? ("(���Ļ�5+����6)(M����0)") : ("(����X����11)(M����0)")));
			input(&r, (g->target == Log::Target::hou ? 6 : 11), 0);
			output("�����뷽λ(12����12���ӷ���,�Դ�����)");
			input(&p, 12, 1);
			a = new Log::Arrow(r, p);
			ro.add_arrow(a);
			break;
		case 2:
			ro.Show_arrow();
			output("��ѡ����ɾ���ļ�ʸ���");
			input(&ru, ro.arrow_num, 1);
			ru--;
			ro.Clear_arrow(ru);
			break;
		case 3:
			g->Clear_round(index);
			con = false;
			break;
		case 4:
			con = false;
			break;
		}
	}
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
			output("������·��");
			cin >> pa;
			s->Import(pa); break;
		case 2:con = false; break;
		default:
			break;
		}
	}
}

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

void Menu_view(Log* s)
{
	int gi, ri;
	bool con1 = true, con2 = true, con3 = true;
	while (con1)
	{
		Introduce_view(s);
		if (!s->Show()) {
			Stop();
			return;
		}
		output("���������鿴�������,0�Ƿ���");
		input(&gi, s->game_num, 0);
		if (!gi)break;
		gi--;
		Log::Game& g = *(s->game[gi]);
		while (con2) {
			system("cls");
			Top("�鿴����");
			if (!g.Show_round()) {
				Stop();
				return;
			}
			output("���������鿴�ִα��,0�Ƿ���");
			input(&ri, g.round_num, 0);
			if (!ri)break;
			ri--;
			Log::Round& r = *(s->game[gi]->round[ri]);
			system("cls");
			Top("�鿴�ִ�");
			;
			if (!r.Show_arrow()) {
				Stop();
				return;
			}
			Stop();
		}
	}
}

void Menu_Logmaster(Log* s)
{
	system("cls");
	Top("�������޸�");
	int ru;
	output("1.�޸ĸ÷ݳɼ�������\n2.��ʼ��¼��һ�������ߵĳɼ�\n�������������");
	input(&ru, 2, 1);
	switch (ru)
	{
	case 1:s->set_master(); break;
	case 2:
		s->Export();
		s->Clear_all();
		s->set_master();
		Menu_addgame(s);
		break;
	}
}

bool Log::Import(string filename)
{
	json* j = open_json(filename);
	if (j == nullptr) {
		output("�޷�������ļ�");
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
			Round* round = new Round();
			game->add_round(round);
			for (json& arrow_json : round_json["arrow"]) {
				round->add_arrow(new Arrow(arrow_json["ring"], arrow_json["position"]));
			}
		}
	}
	delete j;
	return true;
}

bool Log::Export()
{
	ofstream file(*master + ".json");
	if (!file.is_open()) {
		output("���ļ�ʧ��");
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

void Log::Clear_all()
{
	for (Game* g : game) {
		g->Clear_all_round();
		delete g;
	}
	game_num = 0;
	game.resize(0);
	Lisan_average_g();
}

void Log::Clear(int index)
{
	Game* g = game[index];
	for (int i = index; i < game_num - 1; i++) {
		game[i] = game[i + 1];
	}
	game[--game_num] = nullptr;
	g->Clear_all_round();
	delete g;
	game.resize(game.size() - 1);
	Lisan_average_g();
}

void Log::add_game(Game* ga)
{
	ga->parent = this;
	game.push_back(ga);
	game_num++;
}

bool Log::Show()
{
	output("�ɼ�������:" + *master + '\n' + "������:" + to_string(game_num) + '\n' + "������:" + to_string(round_num_all) + '\n' + "�ܼ���:" + to_string(arrow_num_all) + '\n' + "��ɢֵ(ԽСԽ��,����ֵ��ʾ���Ǽ�ʸ�ֲ��ܼ���,���Ƿ���):" + to_string(lisan_average));
	if (game_num == 0) {
		output("�ޱ���");
		return false;
	}
	string o = "���          ʱ��                          ��ɢֵ     �ܳɼ�       ��������    ����\n";
	string t;
	int i = 1;
	for (Game* g : game) {
		t = ctime(&(g->gametime));
		o += format("{:<14d}", i++) + format("{:<30s}", t.substr(0, t.find_last_not_of("\r\n") + 1)) + format("{:<11.4f}", lisan_average) + format("{:0>3d}/{:<9d}", g->Score(), g->Score_full()) + format("{:<12s}", TargetToString(g->target)) + format("{:<d}��", g->distance) + "\n";
	}
	output(o);
	return true;
	//rectangle_one_row(o);
}

void Log::set_master()
{
	output("���������޸Ĺ���������");
	cin >> *master;
}

Log::Log()
{
	json* d = open_json("default.json");
	string p;
	if (d != nullptr)p = (*d)["path"];
	if (!Import(p)) {
		output("�޷����ϴδ򿪵��ļ�,�Ѵ���ȫ�¼�¼");
		master = new string("null");
		game_num = 0;
		round_num_all = 0;
		arrow_num_all = 0;
		lisan_average = 0;
		system("pause");
	}
}

void Log::Round::Lisan()
{
	double theta, d, x, y;
	int maxScore = parent->target == hou ? 6 : 11;
	int N = arrow_num;
	if (N == 0) {
		lisan = 0;
		return;
	}
	double sum_d2 = 0.0, sum_x = 0.0, sum_y = 0.0;
	for (int i = 0; i < arrow_num; i++) {
		d = maxScore - arrow[i]->ring;
		theta = arrow[i]->position * M_PI / 6.0;   // 12 �̶ȣ�360��/12 = 30�� = ��/6
		x = d * cos(theta);
		y = d * sin(theta);

		sum_d2 += d * d;
		sum_x += x;
		sum_y += y;
	}

	double mean_d2 = sum_d2 / N;
	double mx = sum_x / N, my = sum_y / N;
	double variance = mean_d2 - (mx * mx + my * my);
	lisan = variance;  // ��ɢֵ��ԽСԽ����
}

int Log::Round::Score()
{
	int re = 0, j;
	for (j = 0; j < arrow_num; j++) {
		re += arrow[j]->ring;
		if (arrow[j]->ring == 11)re--;
	}
	return re;
}

int Log::Round::Score_full()
{
	return arrow_num * (parent->target == hou ? 5 : 10);
}

bool Log::Round::Show_arrow()
{
	if (arrow_num == 0) {
		output("�޼�ʸ");
		return false;
	}
	string o = "���      ��    ��λ\n";
	int in = 1;
	for (int i = 0; i < arrow_num; i++) {
		o += format("{:<10d}", in++) + format("{:<6d}", arrow[i]->ring) + format("{:<d}���ӷ���", arrow[i]->position) + "\n";
	}
	output(o);
	return true;
	//rectangle_one_row(o);
}

Log::Round::Round()
{
	arrow_num = 0;
}

bool Log::Round::add_arrow(Arrow* arr)
{
	if (arrow_num >= 24)return false;
	arr->parent = this;
	arrow[arrow_num] = arr;
	arrow_num++;
	parent->arrow_num++;
	parent->parent->arrow_num_all++;
	Lisan();
	parent->Lisan_average();
	parent->parent->Lisan_average_g();
	return true;
}

void Log::Round::Clear_arrow(int index)
{
	Arrow* anchor = arrow[index];
	for (int i = index; i < arrow_num - 1; i++) {
		arrow[i] = arrow[i + 1];
	}
	arrow[--arrow_num] = nullptr;
	parent->arrow_num--;
	parent->parent->arrow_num_all--;
	delete anchor;
	Lisan();
}

void Log::Round::Clear_all_arrow()
{
	for (int i = 0; i < arrow_num; i++) {
		delete arrow[i];
	}
	parent->parent->arrow_num_all -= arrow_num;
	parent->arrow_num -= arrow_num;
	arrow_num = 0;
	Lisan();
}

void Log::Game::Lisan_average()
{
	lisan_average = 0;
	for (int i = 0; i < round_num; i++) {
		lisan_average += round[i]->lisan;
	}
	lisan_average /= round_num;
}

bool Log::Game::Show_round()
{
	if (arrow_num == 0) {
		output("���ִ�");
		return false;
	}
	string o = "���      ��ʸ����    ��ɢֵ     �ܳɼ�\n";
	int in = 1;
	for (int i = 0; i < round_num; i++) {
		o += format("{:<10d}", in++) + format("{:<12d}", round[i]->arrow_num) + format("{:<11.4f}", round[i]->lisan) + format("{:0>3d} / {:<9d}", round[i]->Score(), round[i]->Score_full()) + "\n";
	}
	output(o);
	return true;
	//rectangle_one_row(o);
}

int Log::Game::Score_full()
{
	return arrow_num * (target == hou ? 5 : 10);
}

int Log::Game::Score()
{
	int re = 0, i, j;
	for (i = 0; i < round_num; i++) {
		for (j = 0; j < round[i]->arrow_num; j++) {
			re += round[i]->arrow[j]->ring;
			if (round[i]->arrow[j]->ring == 11)re--;
		}
	}
	return re;
}

bool Log::Game::add_round(Round* ro)
{
	if (round_num >= 24)return false;
	ro->parent = this;
	round[round_num] = ro;
	round_num++;
	parent->round_num_all++;
	arrow_num += ro->arrow_num;
	Lisan_average();
	parent->Lisan_average_g();
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
	Lisan_average();
}

void Log::Game::Clear_all_round()
{
	for (int i = 0; i < round_num; i++) {
		round[i]->Clear_all_arrow();
		delete round[i];
	}
	parent->round_num_all -= round_num;
	round_num = 0;
	Lisan_average();
}

Log::Game::Game(time_t time)
{
	parent = nullptr;
	gametime = time;
	distance = 0;
	round_num = 0;
	lisan_average = 0;
	arrow_num = 0;
}

Log::Arrow::Arrow(int r, int p)
{
	parent = nullptr;
	ring = r;
	position = p;
}

void Log::Lisan_average_g()
{
	lisan_average = 0;
	for (int i = 0; i < game_num; i++) {
		lisan_average += game[i]->lisan_average;
	}
	lisan_average /= game_num;
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
		return "���";
		break;
	case Log::huan_40_full:
		return "40ȫ����";
		break;
	case Log::huan_60_full:
		return "60ȫ����";
		break;
	case Log::huan_80_full:
		return "80ȫ����";
		break;
	case Log::huan_122_full:
		return "122ȫ����";
		break;
	case Log::huan_40_self:
		return "40�뻷��";
		break;
	case Log::huan_60_self:
		return "60�뻷��";
		break;
	case Log::huan_80_self:
		return "80�뻷��";
		break;
	default:
		return "";
		break;
	}
}