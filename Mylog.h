 ///
 /// @file    Mylog.h
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-06-10 15:53:37
 ///
 
#ifndef __MYLOG_H__
#define __MYLOG_H__

#include <iostream>

#include <log4cpp/Category.hh>

using std::cout;
using std::endl;

using namespace log4cpp;

namespace zxk666
{

class Mylog
{
public:
	static Mylog * getInstance();
	static void destory();
	template<typename... Args>
	void warn(const char * msg, Args... args)
	{
		_root.warn(msg, args...);
	}
	template<typename... Args>
	void error(const char * msg, Args... args)
	{
		_root.error(msg, args...);
	}
	template<typename... Args>
	void debug(const char * msg, Args... args)
	{
		_root.debug(msg, args...);
	}
	template<typename... Args>
	void info(const char * msg, Args... args)
	{
		_root.info(msg, args...);
	}

private:
	Mylog();
	~Mylog();

private:
	static Mylog * _pInstance;
	Category & _root;

};

}//end of namespace zxk666;

#define LogWarn(msg, ...) zxk666::Mylog::getInstance()->warn(msg, ##__VA_ARGS__)
#define LogError(msg, ...) zxk666::Mylog::getInstance()->error(msg, ##__VA_ARGS__)
#define LogDebug(msg, ...) zxk666::Mylog::getInstance()->debug(msg, ##__VA_ARGS__)
#define LogInfo(msg, ...) zxk666::Mylog::getInstance()->info(msg, ##__VA_ARGS__)

#endif
