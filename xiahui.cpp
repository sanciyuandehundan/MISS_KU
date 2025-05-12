#include "including.h"

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
                cout << "������" << min << '~' << max << "Ŷ~~:";
            }
        }
        catch (...) {
            cout << "������" << min << '~' << max << "Ŷ~~:";
        }
    } while (!valid);
}

json* open_json(string s)
{
    ifstream file("default.json");
    if (!file.is_open()) {
        cerr << "Failed to open the file." << endl;
        return;
    }
    json j;
    file >> j;
    file.close();
    return &j;
}
