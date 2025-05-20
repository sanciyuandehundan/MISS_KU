#pragma once
#include "including.h"
#include "xiahui.h"
#include "sanciyuandehundan.h"

/*
输出左右被线条包围的标题
*/
void Top(const char* c);
/*
主界面介绍,输入范围7~1
*/
void Introduce_main(Log* s);
/*
手动输入界面介绍,输入范围6~1
*/
void Introduce_input(Log* s);
/*
导入界面介绍,输入范围2~1
*/
void Introduce_import(Log* s);
/*
导出界面介绍,输入范围2~1
*/
void Introduce_export(Log* s);
/*
删除界面介绍,输入范围2~0
*/
void Introduce_delete(Log* s);
/*
查询界面介绍,输入范围无
*/
void Introduce_view(Log* s);
/*
修改成绩归属者介绍,输入范围3~1
*/
void Introduce_scoremaster(Log* s);
/*
自适应方框,单行
*/
void rectangle_one_row(string s);
/*
自适应方框,多行
*/
void output(string s);