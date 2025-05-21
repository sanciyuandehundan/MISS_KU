#include "including.h"
#include "xiahui.h"
#include "chenpi.h"
#include "sanciyuandehundan.h"
#include <io.h>
#include <fcntl.h>

void Top(const char* c) {
    cout << COLOR_TITLE;
    cout << "════════════════════════════" << endl;
    cout << "  " << c << "  " << endl;
    cout << "════════════════════════════" << endl;
    cout << COLOR_RESET;
}

void Introduce_main(Log* s) {
    system("cls");
    Top("射箭成绩统计与分析系统");
    cout << COLOR_MENU;
    cout << "┌────────────────────────────┐" << endl;
    cout << "│     " << COLOR_OPTION << "1. 手动输入成绩" << COLOR_MENU << "        │" << endl;
    cout << "│     " << COLOR_OPTION << "2. 导入成绩文件" << COLOR_MENU << "        │" << endl;
    cout << "│     " << COLOR_OPTION << "3. 导出成绩文件" << COLOR_MENU << "        │" << endl;
    cout << "│     " << COLOR_OPTION << "4. 查看过往成绩" << COLOR_MENU << "        │" << endl;
    cout << "│     " << COLOR_OPTION << "5. 修改成绩归属" << COLOR_MENU << "        │" << endl;
    cout << "│     " << COLOR_OPTION << "6. 删除过往成绩" << COLOR_MENU << "        │" << endl;
    cout << "│     " << COLOR_OPTION << "7. 退出程序    " << COLOR_MENU << "        │" << endl;
    cout << "└────────────────────────────┘" << endl;
}

void Introduce_input(Log* s) {
    system("cls");
    Top("手动输入数据");
    cout << COLOR_MENU;
    cout << "┌────────────────────────────┐" << endl;
    cout << "│    " << COLOR_OPTION << "1. 修改现有数据" << COLOR_MENU << "         │" << endl;
    cout << "│    " << COLOR_OPTION << "2. 添加新数据" << COLOR_MENU << "           │" << endl;
    cout << "│    " << COLOR_OPTION << "3. 返回主菜单" << COLOR_MENU << "           │" << endl;
    cout << "└────────────────────────────┘" << endl;
}

void Introduce_import(Log* s) {
    system("cls");
    Top("导入成绩文件");
    cout << COLOR_MENU;
    cout << "────────────────────────────────" << endl;
    cout << " 输入扩展名为 .json 的文件路径 (绝对路径)\n\n";
    cout << " * 如果导入成绩归属者与现有成绩归属者相同\n";
    cout << "   则直接将文件内成绩添加至现有成绩\n";
    cout << " * 如果导入成绩的归属者与现有成绩归属者不同\n";
    cout << "   现有成绩文件将自动保存导出,并重置程序内数据\n";
    cout << "────────────────────────────────" << endl;
    s->Show();
    cout << "┌────────────────────────────┐" << endl;
    cout << "│   " << COLOR_OPTION << "1. 开始导入" << COLOR_MENU << "              │" << endl;
    cout << "│   " << COLOR_OPTION << "2. 返回主菜单" << COLOR_MENU << "            │" << endl;
    cout << "└────────────────────────────┘" << endl;
}

void Introduce_export(Log* s) {
    system("cls");
    Top("导出成绩文件");
    s->Show();
    cout << COLOR_MENU;
    cout << "┌────────────────────────────┐" << endl;
    cout << "│      " << COLOR_OPTION << "1. 开始导出" << COLOR_MENU << "           │" << endl;
    cout << "│      " << COLOR_OPTION << "2. 返回主菜单" << COLOR_MENU << "         │" << endl;
    cout << "└────────────────────────────┘" << endl;
}

void Introduce_delete(Log* s)
{
    system("cls");
    Top("删除过往成绩");
    cout << COLOR_MENU;
    cout << "┌─────────────────────────────────────┐" << endl;
    cout << "│   " << COLOR_OPTION << "0.查看全部并选择指定序号成绩删除" << COLOR_MENU << "  │" << endl;
    cout << "│   " << COLOR_OPTION << "1.全部删除" << COLOR_MENU << "                        │" << endl;
    cout << "│   " << COLOR_OPTION << "2.返回主菜单" << COLOR_MENU << "                      │" << endl;
    cout << "└─────────────────────────────────────┘" << endl;
}

void Introduce_view(Log* s) {
    system("cls");
    Top("查看过往成绩");
    s->Show();
    cout << COLOR_MENU;
    cout << "────────────────────────────────" << endl;
    cout << COLOR_OPTION << "按任意键返回主菜单..." << COLOR_RESET;
    system("pause > nul");
}

void Introduce_scoremaster(Log* s) {
    system("cls");
    Top("修改成绩归属");
    cout << COLOR_MENU;
    cout << "┌────────────────────────────┐" << endl;
    cout << "│ " << COLOR_OPTION << "1. 修改该份成绩的归属者" << COLOR_MENU << "    │" << endl;
    cout << "│ " << COLOR_OPTION << "2. 开始记录另一个人的成绩" << COLOR_MENU << "  │" << endl;
    cout << "│ " << COLOR_OPTION << "   (当前成绩将被自动导出)" << COLOR_MENU << "  │" << endl;
    cout << "│ " << COLOR_OPTION << "3. 返回主菜单" << COLOR_MENU << "              │" << endl;
    cout << "└────────────────────────────┘" << endl;
}

void rectangle_one_row(string s)
{
    cout << COLOR_TITLE;
    size_t length = s.length();  // 返回字节数（取决于编码）
    cout << "╔";
    for (int i = 0; i < length; i++) {
        cout << "═" ;
    }
    cout << "╗" << endl;
    cout<<"║" << s << "║" << endl; 
    cout << "╚" ;
    for (int i = 0; i < length; i++) {
        cout << "═" ;
    }
    cout << "╝" << endl;
}

void output(string s)
{
    int length = 0;
    int max = 0;
    cout << COLOR_TITLE;
    for (char c : s) {
        if (c != '\n') length++;
        else {
            if (length > max) max = length;
            length = 0;
        }
    }
    cout << "╔";
    for (int i = 0; i < max; i++) {
        cout << "═";
    }
    cout << "╗" << endl;
    cout << "║";
    for (long long i = 0; i < s.length();i++) {
        if (s[i] != '\n') {
            cout << s[i];
        }
        else {
            cout << "║" << endl;
            if (s[i + 1] != '\0') cout << "║";
        }
    }
    cout << "╚";
    for (int i = 0; i < max; i++) {
        cout << "═";
    }
    cout << "╝" << endl;
}
