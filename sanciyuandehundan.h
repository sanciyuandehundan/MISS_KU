#pragma once
#include "including.h"
#include "xiahui.h"
#include "chenpi.h"

class Log {
public:
	enum Target { hou = 1, huan_40_full = 2, huan_60_full = 3, huan_80_full = 4, huan_122_full = 5, huan_40_self = 6, huan_60_self = 7, huan_80_self = 8 };
	class Round;
	class Game;
	class Arrow {
	public:
		Round* parent;
		int ring;
		int position;
		/*
		��ʸ���캯��,r����,p��λ(1~12����)
		*/
		Arrow(int r, int p);
	};
	class Round {
	public:
		Game* parent;
		Target target;
		int distance;
		int arrow_num;
		Arrow* arrow[24];
		/*
		�ִι��캯��,t����,d����
		*/
		Round(Target t, int d);
		/*
		���ִμ����ʸ��¼,����ɹ�����true,ʧ����Ϊfalse
		*/
		bool add_arrow(Arrow* arr);
		/*
		���ָ����ŵļ�ʸ��¼,��������ڴ��������¼�����޸�
		*/
		void Clear_arrow(int index);
		/*
		��ո��ִ����м�ʸ��¼,��������ڴ��������¼�����޸�
		*/
		void Clear_all_arrow();
	};
	class Game {
	public:
		Log* parent;
		time_t gametime;
		Target target;
		int distance;
		int round_num;
		int arrow_num;
		Round* round[24];
		/*
		��������
		*/
		int Score_full();
		/*
		�����ܷ�
		*/
		int Score();
		/*
		��һ����������ִ�,����ɹ�����true,ʧ����Ϊfalse
		*/
		bool add_round(Round* ro);
		/*
		���ָ����ŵ��ִ�,��������ڴ��������¼�����޸�
		*/
		void Clear_round(int index);
		/*
		��ո��ִ������ִ�,��������ڴ��������¼�����޸�
		*/
		void Clear_all_round();
		/*
		�������캯��,time��ʼʱ��
		*/
		Game(time_t time);
	};
	string* master;
	vector<Game*> game;
	int game_num;
	int round_num_all;
	int arrow_num_all;
	long double lisan;
	/*
	����Ƿ�����ͬʱ��ı���
	*/
	bool Check_same(Game* g);
	/*
	�����������о�ת��Ϊ�ַ���
	*/
	static const char* TargetToString(Target ta);
	/*
	���ָ����ŵı���,��������ڴ��������¼�����޸�
	*/
	void Clear_all();
	/*
	���ָ����ŵı���,��������ڴ��������¼�����޸�
	*/
	void Clear(int index);
	/*
	���ɼ���ӱ���
	*/
	void add_game(Game* ga);
	/*
	����ɼ��ļ�,filename�ļ�·��
	*/
	bool Import(string filename);
	/*
	�����ɼ��ļ�,�ļ���Ϊ ����������.json
	*/
	bool Export();
	/*
	��ʾ�ɼ���Ϣ
	*/
	void Show();
	/*
	�޸Ĺ���������
	*/
	void set_master();
	/*
	�ɼ����캯��
	*/
	Log();
};
/*
���˵�,����ռ�ָ��,�ɼ�ʵ��ָ��
*/
void Menu_main(int *ru,Log* s);
/*
����˵�,����ռ�ָ��,�ɼ�ʵ��ָ��
*/
void Menu_input(int* ru, Log* s);
/*
����˵�,����ռ�ָ��,�ɼ�ʵ��ָ��
*/
void Menu_import(int* ru, Log* s);
/*
�����˵�,����ռ�ָ��,�ɼ�ʵ��ָ��
*/
void Menu_export(int* ru, Log* s);
/*
չʾ�ɼ��˵�,����ռ�ָ��,�ɼ�ʵ��ָ��
*/
void Menu_view(int* ru, Log* s);
/*
�����߲˵�,����ռ�ָ��,�ɼ�ʵ��ָ��
*/
void Menu_scoremaster(int* ru, Log* s);
/*
ɾ���ɼ��˵�,����ռ�ָ��,�ɼ�ʵ��ָ��
*/
void Menu_delete(int* ru, Log* s);