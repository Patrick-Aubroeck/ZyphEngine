#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <string>

class Logger
{	
public:
	enum MessageType
	{
		FatalError,
		Error,
		Warning,
		Loading,
		Saving,
		Success
	};
	Logger(std::string loggerName);
	virtual ~Logger();
	void WriteMessage(std::string message, MessageType messagetype);
	void DeleteLogFile();
private:
	std::string ConvertEnumToString(MessageType messageType);
	std::string m_logfile;
	std::string m_loggerName;
};

#endif