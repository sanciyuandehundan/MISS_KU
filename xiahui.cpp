#include "including.h"
#include "xiahui.h"
#include "chenpi.h"
#include "sanciyuandehundan.h"

void input(int* ru, int max, int min) {
    string input_str;
    bool valid = false;
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
                    cout << "ÇëÊäÈë" << min << '~' << max << ":";
                }
            }
            catch (...) {
                cout << "ÇëÊäÈë" << min << '~' << max << ":";
            }
        }
        else cout << "ÇëÊäÈë" << min << '~' << max << ":";
    } while (!valid);
}

json* open_json(string s)
{
    ifstream file(s);
    if (!file.is_open()) {
        cerr << "Failed to open the file." << endl;
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
