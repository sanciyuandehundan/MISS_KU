#include "including.h"
#include "xiahui.h"
#include "chenpi.h"
#include "sanciyuandehundan.h"

Log *log_;
int ru;
int main()
{
	log_ = new Log();
	Menu_main(&ru, log_);
}