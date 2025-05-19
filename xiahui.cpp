#include "including.h"
#include "xiahui.h"
#include "chenpi.h"
#include "sanciyuandehundan.h"

void input(int* ru, int max, int min) {
    string input_str;
    bool valid = false;
    cout << COLOR_RESET;
    cout << COLOR_OPTION << "������ (" << min << '~' << max << "): " << COLOR_RESET;
    do {
        getline(cin, input_str);
        bool is_all_digits = true;
        for (char c : input_str) {
            if (!isdigit(c)) {
                is_all_digits = false;
                break;
            }
        }
        if (is_all_digits && !input_str.empty()) {
            try {
                *ru = stoi(input_str);
                if (*ru >= min && *ru <= max) {
                    valid = true;
                }
                else {
                    cout << "������" << min << '~' << max << ":";
                }
            }
            catch (...) {
                cout << "������" << min << '~' << max << ":";
            }
        }
        else cout << "������" << min << '~' << max << ":";
    } while (!valid);
}

json* open_json(string s)
{
    ifstream file(s);
    if (!file.is_open()) {
        cout << "���ļ�ʧ��" << endl;
        return nullptr;
    }
    json* j = new json();
    file >> *j;
    file.close();
    //cout << (*j)["path"];
    return j;
}

void default_json(string s)
{

}
