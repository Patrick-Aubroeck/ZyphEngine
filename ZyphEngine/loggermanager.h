#ifndef _LOGGERMANAGER_H_
#define _LOGGERMANAGER_H_

#include <string>
#include <map>// ?? needed ??

#include "logger.h"

class LoggerManager
{
private:
	std::map<std::string, Logger*> m_loggers;
private:
	virtual ~LoggerManager();
	static LoggerManager* m_LoggerManager;

public:
	static LoggerManager* GetInstance();
	Logger* AcquireLogger(std::string loggerName);
	void ReleaseLogger(std::string loggerName);
	void ReleaseAllLoggers();
};



#endif