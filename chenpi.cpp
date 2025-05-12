#include "including.h"


void Top(const char* c)
{
	cout << "——————" << c << "——————" << endl;
}

void Introduce_main(Score* s) {
	system("cls");
	Top("射箭成绩统计与分析系统");
	cout << "1.手动输入成绩" << endl;
	cout << "2.导入成绩文件" << endl;
	cout << "3.导出成绩文件" << endl;
	cout << "4.查看过往成绩" << endl;
	cout << "5.修改成绩归属" << endl;
	cout << "要进行何种操作:";
}

void Introduce_input(Score* s)
{
	system("cls");
	Top("手动输入数据");
	cout << "1.设定靶子类型" << endl;
	cout << "2.设定距离" << endl;
	cout << "3.设定轮数" << endl;
	cout << "4.设定每轮箭数" << endl;
	cout << "5.开始输入" << endl;
	cout << "6.返回" << endl;
	cout << "要进行何种操作:";
}

void Introduce_import(Score* s)
{
	system("cls");
	Top("导入成绩文件");
	cout << "输入扩展名为.json的文件的文件路径(绝对路径)\n如果导入成绩归属者与现有成绩归属者相同则直接将文件内成绩添加至现有成绩\n如果导入成绩的归属者与现有成绩归属者不同,现有成绩文件将自动保存导出,并重置程序内数据" << endl;
	s->Show();
	cout << "1.开始导入" << endl;
	cout << "2.返回" << endl;
	cout << "要进行何种操作:";
}

void Introduce_export(Score* s)
{
	system("cls");
	Top("导出成绩文件");
	s->Show();
	cout << "1.开始导出" << endl;
	cout << "2.返回" << endl;
	cout << "要进行何种操作:";
}

void Introduce_view(Score* s)
{
	system("cls");
	Top("查看过往成绩");
	s->Show();
	system("pause");
}

void Introduce_scoremaster(Score* s)
{
	system("cls");
	Top("修改成绩归属");
	cout << "1.修改该份成绩的归属者" << endl;
	cout << "2.开始记录另一个人的成绩,当前成绩将被自动导出" << endl;
	cout << "3.返回" << endl;
	cout << "要进行何种操作:";
}
