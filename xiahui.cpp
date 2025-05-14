#include "including.h"
#include "xiahui.h"
#include "chenpi.h"
#include "sanciyuandehundan.h"

void input(int* ru, int max, int min) {
    string input_str;
    bool valid = false;
    do {
        getline(cin, input_str);
        try {
            *ru = stoi(input_str);
            if (*ru >= min && *ru <= max) {
                valid = true;
            }
            else {
                cout << "请输入" << min << '~' << max << "哦~~:";
            }
        }
        catch (...) {
            cout << "请输入" << min << '~' << max << "哦~~:";
        }
    } while (!valid);
}

json* open_json(string s)
{
    ifstream file(s);
    if (!file.is_open()) {
        cout << "打开文件失败" << endl;
        return nullptr;
    }
    json* j = new json();
    file >> *j;
    file.close();
    //cout << (*j)["path"];
    return j;
}
