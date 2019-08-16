#ifndef _UTILS_H_
#define _UTILS_H_

#include <iostream>
#include <cstring>
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <curl/curl.h>
#include <log4cplus/appender.h>
#include <log4cplus/logger.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/fileappender.h>
#include <log4cplus/layout.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/helpers/loglog.h>
#include <log4cplus/loglevel.h>
using namespace std;
using namespace log4cplus;
using namespace log4cplus::helpers;

extern Logger rollFileLogger;
extern Logger consoleLogger;

#define LOG4_DEBUG_FILE(logEvent) LOG4CPLUS_DEBUG(rollFileLogger,logEvent);
#define LOG4_ERROR_FILE(logEvent) LOG4CPLUS_ERROR(rollFileLogger,logEvent);

#define LOG4_DEBUG_CONSOLE(logEvent) LOG4CPLUS_DEBUG(consoleLogger,logEvent);
#define LOG4_ERROR_CONSOLE(logEvent) LOG4CPLUS_ERROR(consoleLogger,logEvent);



struct MemoryStruct
{
	char *memory;
	size_t size;
	MemoryStruct()
	{
		memory = (char *)malloc(1);
		size = 0;
	}
	~MemoryStruct()
	{
		free(memory);
		memory = NULL;
		size = 0;
	}

};


enum POSTMODE   /** Post参数的方式 **/
{
	PARAMS,
	BODYRAW
};
class Utils
{
	public:
		Utils();
		~Utils();
		static int Post(std::string url , std::string argu, std::string *receive_json,POSTMODE ); //sel =1,body.raw(json)   else   Params
		static int Get(std::string url , std::string *response);
		static size_t write_memory_callback(void *ptr, size_t size, size_t nmemb, void *data);
		static void all_replace(string& str , const string old_value, const string new_value);

};





#endif
