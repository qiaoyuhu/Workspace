#include <cstdio>
#include <cstdlib>
#include <string>
#include <log4cplus/appender.h>
#include <log4cplus/logger.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/fileappender.h>
#include <log4cplus/layout.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/helpers/loglog.h>
#include <log4cplus/loglevel.h>

#define LOG4_DEBUG_FILE(logEvent) LOG4CPLUS_DEBUG(rollFileLogger,logEvent);
#define LOG4_ERROR_FILE(logEvent) LOG4CPLUS_ERROR(rollFileLogger,logEvent);

#define LOG4_DEBUG_CONSOLE(logEvent) LOG4CPLUS_DEBUG(consoleLogger,logEvent);
#define LOG4_ERROR_CONSOLE(logEvent) LOG4CPLUS_ERROR(consoleLogger,logEvent);

using namespace log4cplus;
using namespace log4cplus::helpers;



using namespace std;


Logger rollFileLogger       = Logger::getInstance("rollFileLogger");
Logger consoleLogger        = Logger::getInstance("consoleLogger");
Logger voiceRollFileLogger  = Logger::getInstance("voiceRollFileLogger");
Logger orderRollFileLogger  = Logger::getInstance("tradeRollFileLogger");
Logger radarInfoLogger      = Logger::getInstance("radarInfoLogger");
Logger PcAdverInfoLogger    = Logger::getInstance("adverInfoLogger");

void log4cplusInitialize()
{
	string formate = "%D[%l] %p %m%n";
	SharedAppenderPtr rollFileAppender(new RollingFileAppender("log.log", 20*1024*1024, 50));
	auto_ptr<Layout>rollFilelayout(new PatternLayout(formate));
	rollFileAppender->setLayout(rollFilelayout);
	rollFileLogger.addAppender(rollFileAppender);
	rollFileLogger.setLogLevel(ALL_LOG_LEVEL);
	
	
	SharedAppenderPtr consoleAppender(new ConsoleAppender());
	auto_ptr<Layout>consoleLayout(new PatternLayout(formate));
	consoleAppender->setLayout(consoleLayout);
	consoleLogger.addAppender(consoleAppender);
	consoleLogger.setLogLevel(ALL_LOG_LEVEL);
}

int main()
{
	 log4cplusInitialize();
	LOG4_DEBUG_CONSOLE("123");
	LOG4_ERROR_FILE("123");
}





