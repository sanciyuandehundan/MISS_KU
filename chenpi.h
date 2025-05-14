#pragma once
#include "including.h"
#include "xiahui.h"
#include "sanciyuandehundan.h"

/*
输出左右被线条包围的标题
*/
void Top(const char* c);
/*
主界面介绍,输入范围5~1
*/
void Introduce_main(Score* s);
/*
手动输入界面介绍,输入范围6~1
*/
void Introduce_input(Score* s);
/*
导入界面介绍,输入范围2~1
*/
void Introduce_import(Score* s);
/*
导出界面介绍,输入范围2~1
*/
void Introduce_export(Score* s);
/*
查询界面介绍,输入范围无
*/
void Introduce_view(Score* s);
/*
修改成绩归属者介绍,输入范围3~1
*/
void Introduce_scoremaster(Score* s);
/*
自适应方框
*/
void rectangle_one_row(string s);