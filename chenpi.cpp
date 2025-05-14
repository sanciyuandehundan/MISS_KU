#include "including.h"
#include "xiahui.h"
#include "chenpi.h"
#include "sanciyuandehundan.h"
#include <io.h>
#include <fcntl.h>

// 定义一些颜色和样式常量
#define COLOR_TITLE "\033[1;36m"  // 青色加粗
#define COLOR_MENU "\033[1;33m"  // 黄色加粗
#define COLOR_OPTION "\033[1;32m" // 绿色加粗
#define COLOR_RESET "\033[0m"     // 重置颜色


void Top(const char* c) {
    cout << COLOR_TITLE;
    cout << "════════════════════════════" << endl;
    cout << "  " << c << "  " << endl;
    cout << "════════════════════════════" << endl;
    cout << COLOR_RESET;
}

void Introduce_main(Score* s) {
    system("cls");
    Top("射箭成绩统计与分析系统");
    cout << COLOR_MENU;
    cout << "┌────────────────────────────┐" << endl;
    cout << "│     " << COLOR_OPTION << "1. 手动输入成绩" << COLOR_MENU << "        │" << endl;
    cout << "│     " << COLOR_OPTION << "2. 导入成绩文件" << COLOR_MENU << "        │" << endl;
    cout << "│     " << COLOR_OPTION << "3. 导出成绩文件" << COLOR_MENU << "        │" << endl;
    cout << "│     " << COLOR_OPTION << "4. 查看过往成绩" << COLOR_MENU << "        │" << endl;
    cout << "│     " << COLOR_OPTION << "5. 修改成绩归属" << COLOR_MENU << "        │" << endl;
    cout << "└────────────────────────────┘" << endl;
    cout << COLOR_RESET;
    cout << COLOR_OPTION << "请选择操作 (1-5): " << COLOR_RESET;
}

void Introduce_input(Score* s) {
    system("cls");
    Top("手动输入数据");
    cout << COLOR_MENU;
    cout << "┌────────────────────────────┐" << endl;
    cout << "│  " << COLOR_OPTION << "1. 设定靶子类型" << COLOR_MENU << "           │" << endl;
    cout << "│  " << COLOR_OPTION << "2. 设定距离" << COLOR_MENU << "               │" << endl;
    cout << "│  " << COLOR_OPTION << "3. 设定轮数" << COLOR_MENU << "               │" << endl;
    cout << "│  " << COLOR_OPTION << "4. 设定每轮箭数" << COLOR_MENU << "           │" << endl;
    cout << "│  " << COLOR_OPTION << "5. 开始输入" << COLOR_MENU << "               │" << endl;
    cout << "│  " << COLOR_OPTION << "6. 返回主菜单" << COLOR_MENU << "             │" << endl;
    cout << "└────────────────────────────┘" << endl;
    cout << COLOR_RESET;
    cout << COLOR_OPTION << "请选择操作 (1-6): " << COLOR_RESET;
}

void Introduce_import(Score* s) {
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
    cout << COLOR_RESET;
    cout << COLOR_OPTION << "请选择操作 (1-2): " << COLOR_RESET;
}

void Introduce_export(Score* s) {
    system("cls");
    Top("导出成绩文件");
    s->Show();
    cout << COLOR_MENU;
    cout << "┌────────────────────────────┐" << endl;
    cout << "│      " << COLOR_OPTION << "1. 开始导出" << COLOR_MENU << "           │" << endl;
    cout << "│      " << COLOR_OPTION << "2. 返回主菜单" << COLOR_MENU << "         │" << endl;
    cout << "└────────────────────────────┘" << endl;
    cout << COLOR_RESET;
    cout << COLOR_OPTION << "请选择操作 (1-2): " << COLOR_RESET;
}

void Introduce_view(Score* s) {
    system("cls");
    Top("查看过往成绩");
    s->Show();
    cout << COLOR_MENU;
    cout << "────────────────────────────────" << endl;
    cout << COLOR_OPTION << "按任意键返回主菜单..." << COLOR_RESET;
    system("pause > nul");
}

void Introduce_scoremaster(Score* s) {
    system("cls");
    Top("修改成绩归属");
    cout << COLOR_MENU;
    cout << "┌────────────────────────────┐" << endl;
    cout << "│ " << COLOR_OPTION << "1. 修改该份成绩的归属者" << COLOR_MENU << "    │" << endl;
    cout << "│ " << COLOR_OPTION << "2. 开始记录另一个人的成绩" << COLOR_MENU << "  │" << endl;
    cout << "│ " << COLOR_OPTION << "   (当前成绩将被自动导出)" << COLOR_MENU << "  │" << endl;
    cout << "│ " << COLOR_OPTION << "3. 返回主菜单" << COLOR_MENU << "              │" << endl;
    cout << "└────────────────────────────┘" << endl;
    cout << COLOR_RESET;
    cout << COLOR_OPTION << "请选择操作 (1-3): " << COLOR_RESET;
}

void rectangle_one_row(string s)
{
    cout << COLOR_TITLE;
    size_t length = s.length();  // 返回字节数（取决于编码）
    cout << "╔" << endl;
    for (int i = 0; i < length; i++) {
        cout << "═" << endl;
    }
    cout << "╗" << endl;
    cout << "<< c << " << endl;
    cout << "╚" << endl;
    for (int i = 0; i < length; i++) {
        cout << "═" << endl;
    }
    cout << "╝" << endl;
}
