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
		箭矢构造函数,r环数,p方位(1~12点钟)
		*/
		Arrow(int r, int p);
	};
	class Round {
	public:
		Game* parent;
		long double lisan;
		int arrow_num;
		Arrow* arrow[24];
		/*
		计算总分
		*/
		int Score();
		/*
		计算满分
		*/
		int Score_full();
		/*
		显示箭矢信息
		*/
		bool Show_arrow();
		/*
		轮次构造函数,t靶子,d距离
		*/
		Round();
		/*
		往轮次加入箭矢记录,加入成功返回true,失败则为false
		*/
		bool add_arrow(Arrow* arr);
		/*
		清空指定序号的箭矢记录,包含清除内存和数量记录变量修改
		*/
		void Clear_arrow(int index);
		/*
		清空该轮次所有箭矢记录,包含清除内存和数量记录变量修改
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
		long double lisan;
		Round* round[24];
		/*
		显示轮次信息
		*/
		bool Show_round();
		/*
		计算满分
		*/
		int Score_full();
		/*
		计算总分
		*/
		int Score();
		/*
		往一场比赛添加轮次,加入成功返回true,失败则为false
		*/
		bool add_round(Round* ro);
		/*
		清空指定序号的轮次,包含清除内存和数量记录变量修改
		*/
		void Clear_round(int index);
		/*
		清空该轮次所有轮次,包含清除内存和数量记录变量修改
		*/
		void Clear_all_round();
		/*
		比赛构造函数,time开始时间
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
	检查是否有相同时间的比赛
	*/
	bool Check_same(Game* g);
	/*
	将靶子类型列举转换为字符串
	*/
	static const char* TargetToString(Target ta);
	/*
	清空指定序号的比赛,包含清除内存和数量记录变量修改
	*/
	void Clear_all();
	/*
	清空指定序号的比赛,包含清除内存和数量记录变量修改
	*/
	void Clear(int index);
	/*
	往成绩添加比赛
	*/
	void add_game(Game* ga);
	/*
	导入成绩文件,filename文件路径
	*/
	bool Import(string filename);
	/*
	导出成绩文件,文件名为 归属者名字.json
	*/
	bool Export();
	/*
	显示成绩信息
	*/
	bool Show();
	/*
	修改归属者名字
	*/
	void set_master();
	/*
	成绩构造函数
	*/
	Log();
};
/*
主菜单,输入空间指针,成绩实例指针
*/
void Menu_main(Log* s);
/*
修改菜单,输入空间指针,成绩实例指针
*/
void Menu_game(Log* s);
/*
输入菜单_修改_修改,输入空间指针,成绩实例指针
*/
void Menu_game_amend(Log::Game* g);
/*
输入菜单_修改_增加,输入空间指针,成绩实例指针
*/
void Menu_game_addround(Log::Game* g);
/*
添加比赛菜单,输入空间指针,成绩实例指针
*/
void Menu_addgame(Log* s);
/*
输入菜单_修改_轮次,输入空间指针,成绩实例指针
*/
void Menu_game_round(Log::Game* g);
/*
导入菜单,输入空间指针,成绩实例指针
*/
void Menu_import(Log* s);
/*
导出菜单,输入空间指针,成绩实例指针
*/
void Menu_export(Log* s);
/*
展示成绩菜单,输入空间指针,成绩实例指针
*/
void Menu_view(Log* s);
/*
归属者菜单
*/
void Menu_Logmaster(Log* s);