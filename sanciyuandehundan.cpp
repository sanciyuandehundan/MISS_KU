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

bool Score::add_game(Game* ga)
{
	if (list_hand == nullptr)return false;
	list_hand->get_last()->add_next(ga);
	return true;
}

void Score::Show()
{
	cout << "չʾ�ɼ���Ϣ,δʵ��" << endl;
}

Score::Score(string* ma)
{
	master = ma;
	list_hand = nullptr;
}

Score::Round::Round()
{
}

bool Score::Round::add_arrow(Arrow* arr)
{
	return false;
}

bool Score::Game::add_round(Round* ro)
{
	return false;
}

Score::Game* Score::Game::get_last()
{
	return this->next == nullptr ? this : this->next->get_last();
}

bool Score::Game::add_next(Game* ga)
{
	next = ga;
	ga->prev = this;
	return false;
}

Score::Arrow::Arrow()
{
}
