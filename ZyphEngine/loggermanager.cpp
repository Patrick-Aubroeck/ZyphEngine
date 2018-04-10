#include "loggermanager.h"

LoggerManager* LoggerManager::m_LoggerManager = NULL;

LoggerManager::~LoggerManager()
{
	ReleaseAllLoggers();
}

LoggerManager* LoggerManager::GetInstance()
{
	if (!m_LoggerManager)
	{
		m_LoggerManager = new LoggerManager();
	}
	return m_LoggerManager;
}

Logger* LoggerManager::AcquireLogger(std::string argLoggerName)
{
	if (!m_loggers[argLoggerName])
	{
		Logger* logger = new Logger(argLoggerName);
		m_loggers[argLoggerName] = logger;
	}

	return m_loggers[argLoggerName];
}

void LoggerManager::ReleaseLogger(std::string argLoggerName)
{
	if (m_loggers[argLoggerName])
	{
		delete m_loggers[argLoggerName];
	}
}

void LoggerManager::ReleaseAllLoggers()
{
	for (std::map<std::string, Logger*>::iterator iterator = m_loggers.begin(); iterator != m_loggers.end(); ++iterator) {
		delete iterator->second;
	}
}

