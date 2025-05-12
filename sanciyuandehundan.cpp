#include "including.h"

void Menu_main(int* ru, Score* s)
{
	while (1) {
		Introduce_main(s);
		input(ru, 5, 1);
		switch (*ru)
		{
		case 1://�ɼ�����
			Menu_input(ru,s);
			break;
		case 2://�ɼ�����
			Menu_import(ru, s);
			break;
		case 3://�ɼ�����
			Menu_export(ru, s);
			break;
		case 4://�ɼ���ѯ
			Menu_view(ru, s);
			break;
		case 5://�ɼ�����
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
		case 1:cout << "δʵ��" << endl; system("pause"); break;
		case 2:cout << "δʵ��" << endl; system("pause"); break;
		case 3:cout << "δʵ��" << endl; system("pause"); break;
		case 4:cout << "δʵ��" << endl; system("pause"); break;
		case 5:cout << "δʵ��" << endl; system("pause"); break;
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
		case 1:cout << "δʵ��" << endl; system("pause"); break;
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
		case 1:cout << "δʵ��" << endl; system("pause"); break;
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
		case 1:cout << "δʵ��" << endl; system("pause"); break;
		case 2:cout << "δʵ��" << endl; system("pause"); break;
		case 3:con = false; break;
		default:
			break;
		}
	}
}

bool Score::Import(string s)
{
	
}

bool Score::add_game(Game* ga)
{
	if (list_hand == nullptr)return false;
	list_hand->get_last()->add_next(ga);
	return true;
}

void Score::Show()
{
	Game* temp=list_hand;
	cout << "�ɼ�������:" << master->c_str()<<endl;
	cout << "������:" << game_num<<endl;
	cout << "������:" << round_num_all<<endl;
	cout << "�ܼ���:" << arrow_num_all<<endl;
	cout << "��ɢϵ��(ԽСԽ��):" << lisan << endl;
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
