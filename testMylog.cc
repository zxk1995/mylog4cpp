 ///
 /// @file    testMylog.cc
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-06-11 19:55:42
 ///
 
#include "Mylog.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using namespace zxk666;

int main(void)
{
	Mylog * pInstance = Mylog::getInstance();

	LogWarn("this is a warn message %d",__LINE__);
	LogError("this is a error message %s", __FUNCTION__);
	LogInfo("this is a info message %s", __FILE__);
	LogDebug("this is a debug message %d", 10);

	pInstance->destory();

	return 0;
}
