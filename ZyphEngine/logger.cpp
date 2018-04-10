#include "logger.h"

#include <iostream>
#include <fstream>
#include <ctime>

Logger::Logger(std::string argLoggerName) :
	m_logfile("../Logs/" + argLoggerName + ".txt"),
	m_loggerName(argLoggerName)
{

}

Logger::~Logger()
{

}

/// <summary>write a message in the logfile</summary>
/// <param name ="message"> the message that has to be logged into the logfile </param>
/// <param name ="messageType"> Enumtype gives extra information about the message </param>
/// <remark>will set the current time and date using localtime </remark>
void Logger::WriteMessage(std::string argmessage, MessageType argMessagetype)
{
	std::ofstream myFile(m_logfile.c_str(), std::ios::out | std::ios::app);
	
	if (myFile.is_open())
	{
		std::string errorType = ConvertEnumToString(argMessagetype);
		time_t currenttime = time(0);
		tm* localtimePtr = localtime(&currenttime);

		myFile << "Date: " << (localtimePtr->tm_mon + 1) << "/" << localtimePtr->tm_mday << "/" << (localtimePtr->tm_year + 1900)
		       << ":" << localtimePtr->tm_hour << ":" << localtimePtr->tm_min << ":" << localtimePtr->tm_sec
		       << "  {" << errorType << "} " << "  " << argmessage 
			   << std::endl;
	}

	myFile.close();
}

void Logger::DeleteLogFile()
{
	remove(m_logfile.c_str());
}

std::string Logger::ConvertEnumToString(MessageType argMessageType)
{
	switch (argMessageType)
	{
	case FatalError:
		return "FATALERROR";
	case Error:
		return "ERROR";
	case Warning:
		return "WARNING";
	case Loading:
		return "LOADING";
	case Saving:
		return "SAVING";
	case Success:
		return "SUCCESS";
	default:
		return "DEFAULT";
	}
}
