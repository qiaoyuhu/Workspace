#include "utils.h"



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
	LOG4_DEBUG_FILE("123123");
	char data[125] ;
	string argu = "api.map.baidu.com/place/v2/search?query=双港地铁站&region=南昌市&city_limit=true&output=json&page_size=5&ak=CQjnEG0iwqPlSiggYruWelZtGIoj7wMU";
	string response;
	int res = Utils::Get(argu,&response);
	LOG4_DEBUG_CONSOLE("res : "<<res<<" response: "<<response)
}



