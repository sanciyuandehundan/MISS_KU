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
                cout << "ÇëÊäÈë" << min << '~' << max << "Å¶~~:";
            }
        }
        catch (...) {
            cout << "ÇëÊäÈë" << min << '~' << max << "Å¶~~:";
        }
    } while (!valid);
}