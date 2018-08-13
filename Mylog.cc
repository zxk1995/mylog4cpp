///
/// @file    Mylog.cc
/// @author  zxk666(1332971744@qq.com)
/// @date    2018-06-10 15:53:37
///

#include "Mylog.h"

#include <log4cpp/FileAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/PatternLayout.hh>

using namespace zxk666;

Mylog * Mylog::_pInstance = NULL;//静态变量初始化应放在实现函数中

Mylog * Mylog::getInstance()
{
	if(_pInstance == NULL)
	{
		_pInstance = new Mylog();
	}
	return _pInstance;
}

void Mylog::destory()
{
	if(_pInstance)
	{
		delete _pInstance;
	}
}

Mylog::Mylog()
: _root(Category::getRoot().getInstance("root"))
{
	PatternLayout* pLayout1 = new PatternLayout();
	pLayout1->setConversionPattern("%d: [%p] [%c]:%m%n");
	PatternLayout* pLayout2 = new PatternLayout();
	pLayout2->setConversionPattern("%d: [%p] [%c]:%m%n");

	Appender* fileAppender = new FileAppender("fileAppender","zxk.log");
	fileAppender->setLayout(pLayout1);

	OstreamAppender* ostreamAppender = new OstreamAppender("ostreamAppender",&cout);
	ostreamAppender->setLayout(pLayout2);

	_root.addAppender(fileAppender);
	_root.addAppender(ostreamAppender);
	_root.setPriority(Priority::DEBUG);
}

Mylog::~Mylog()
{
	Category::shutdown();
}

