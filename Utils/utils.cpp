#include "utils.h"


int Utils::Get(string url,string *response)
{
	LOG4_DEBUG_CONSOLE("Get");
	LOG4_DEBUG_FILE("Get");
	int timeout =  10;
	//int timeout =  stoi(g_configParaInstance.CurlTimeout);
	CURLcode res = curl_global_init(CURL_GLOBAL_ALL);//初始化除CURL_GLOBAL_ACK_EINTR外的所有系统。
	if(CURLE_OK != res)
	{
		LOG4_DEBUG_FILE("Get() curl init failed");
		return res;
	}
	else
		LOG4_DEBUG_FILE("curl init Successfully");
	CURL *pCurl = curl_easy_init();
	if(pCurl)
	{
		curl_easy_setopt(pCurl,CURLOPT_URL,url.c_str());
		curl_easy_setopt(pCurl, CURLOPT_FOLLOWLOCATION, 1L);//允许重定向
		curl_easy_setopt(pCurl, CURLOPT_NOSIGNAL, 1L); //将返回结果通过回调函数写到自定义的对象中

		MemoryStruct oDataChunk;						////请求结果的保存格式
		curl_easy_setopt(pCurl, CURLOPT_WRITEDATA, &oDataChunk);
		curl_easy_setopt(pCurl, CURLOPT_WRITEFUNCTION ,write_memory_callback);
		curl_easy_setopt(pCurl, CURLOPT_TIMEOUT, 10);
		curl_easy_setopt(pCurl,CURLOPT_CONNECTTIMEOUT,timeout);//
		res = curl_easy_perform(pCurl);
		long res_code=0;

		if(res == CURLE_OK)
		{            
			res=curl_easy_getinfo(pCurl, CURLINFO_RESPONSE_CODE, &res_code);
			if((res == CURLE_OK) && res_code)
			{                
				*response = oDataChunk.memory;
			}
			else
			{
				LOG4_ERROR_CONSOLE("ERROR Get curl_easy_getinfo res : "<< res<<"res_code: "<<res_code<<endl );
				LOG4_ERROR_FILE("ERROR Get curl_easy_getinfo res : "<< res <<"res_code: "<<res_code<<endl);
			}
		}
		else
		{
			LOG4_ERROR_CONSOLE("ERROR Get curl_easy_perfrom res : "<< res<<endl );
			LOG4_ERROR_FILE("ERROR Get curl_easy_perfrom res : "<< res <<endl);
		}
		curl_easy_cleanup(pCurl);
		return res;
	}
	else
	{
		LOG4_ERROR_CONSOLE("Init CURL GET failed...");
		LOG4_ERROR_FILE(" Init CURL GET failed...");
		return -1;
	}
}




int Utils::Post(string url , string argu,string *receive_json,POSTMODE sel) //sel =1,body.raw(json)   else   Params
{
	int timeout =  10;
	//int timeout =  stoi(g_configParaInstance.CurlTimeout);

	CURLcode res = curl_global_init(CURL_GLOBAL_ALL);//初始化除CURL_GLOBAL_ACK_EINTR外的所有系统。
	if(CURLE_OK != res)
	{
		LOG4_DEBUG_FILE("Post() curl init failed");
		return res;
	}
	CURL *pCurl ;
	pCurl = curl_easy_init();//外部接口，用于创建,分配并返回一个初始化的CURL句柄，作为其他curl_easy函数的作用对象。
	if( NULL == pCurl)
	{
		LOG4_ERROR_CONSOLE("Init CURL POST failed...");
		LOG4_ERROR_FILE("Init CURL POST failed...");
		return -1;

	}
	//	string url = "http://172.16.0.80:8080";
	curl_slist *pList = NULL;
	if(sel ==1)
		pList = curl_slist_append(pList,"Content-Type:application/json; charset=UTF-8");
	else
		pList = curl_slist_append(pList,"Content-Type:application/x-www-form-urlencoded; charset=UTF-8");
	pList = curl_slist_append(pList,"Accept:application/json, text/javascript, */*; q=0.01");
	pList = curl_slist_append(pList,"Accept-Language:zh-CN,zh;q=0.8");
	curl_easy_setopt(pCurl, CURLOPT_HTTPHEADER, pList);	//CURLOPT_HTTPHEADER:设置HTTP请求的头信息
	curl_easy_setopt(pCurl, CURLOPT_URL, url.c_str() ); //CURLOPT_URL:请求的url地址
	curl_easy_setopt(pCurl, CURLOPT_HEADER, 0L); //启用时会将头文件的信息作为数据流输
	curl_easy_setopt(pCurl, CURLOPT_FOLLOWLOCATION, 1L);//允许重定向
	curl_easy_setopt(pCurl, CURLOPT_NOSIGNAL, 1L); //将返回结果通过回调函数写到自定义的对象中
	curl_easy_setopt(pCurl, CURLOPT_TIMEOUT, 10);
	curl_easy_setopt(pCurl,CURLOPT_CONNECTTIMEOUT,timeout);//

	MemoryStruct oDataChunk;						////请求结果的保存格式
	curl_easy_setopt(pCurl, CURLOPT_WRITEDATA, &oDataChunk);
	curl_easy_setopt(pCurl, CURLOPT_WRITEFUNCTION ,Utils::write_memory_callback);
	//curl_easy_setopt(pCurl, CURLOPT_VERBOSE, 1L); //启用时会汇报所有的信息 //post表单参数
	string strJsonData = argu;

	//POST：需要设置CURLOPT_POST为true，设置CURLOPT_POSTFIELDS、CURLOPT_POSTFIELDSIZE
	curl_easy_setopt(pCurl, CURLOPT_POST, 1L);						//post需要将CURLOPT_POST置为true
	curl_easy_setopt(pCurl, CURLOPT_POSTFIELDS, strJsonData.c_str());//post 参数
	curl_easy_setopt(pCurl, CURLOPT_POSTFIELDSIZE, strJsonData.size());
	res = curl_easy_perform(pCurl);
	long res_code=0;
	if(res == CURLE_OK)
	{
		res=curl_easy_getinfo(pCurl, CURLINFO_RESPONSE_CODE, &res_code);
		if(res == CURLE_OK && res_code)
		{
			*receive_json = oDataChunk.memory;
		}
		else
		{
			LOG4_ERROR_CONSOLE("ERROR Post curl_easy_getinfo res : "<< res<<"res_code: "<<res_code<<endl );
			LOG4_ERROR_FILE("ERROR Post curl_easy_getinfo res : "<< res <<"res_code: "<<res_code<<endl);
		}
	}
	else
	{
		LOG4_ERROR_CONSOLE("ERROR Post curl_easy_perfrom res : "<< res<<endl );
		LOG4_ERROR_FILE("ERROR Post curl_easy_perfrom res : "<< res <<endl);
	}

	curl_slist_free_all(pList);
	curl_easy_cleanup(pCurl);
	curl_global_cleanup();
	return res;
}



size_t Utils::write_memory_callback(void *ptr, size_t size, size_t nmemb, void *data)
{    
	size_t realsize = size * nmemb;
	struct MemoryStruct *mem = (struct MemoryStruct *)data;
	mem->memory = (char *)realloc(mem->memory, mem->size + realsize + 1);
	if (mem->memory)
	{
		memcpy(&(mem->memory[mem->size]), ptr, realsize);
		mem->size += realsize; mem->memory[mem->size] = 0;
	}
	return realsize;
}

void Utils::all_replace(string& str , const string old_value, const string new_value)
{
	while(1)
	{
		int pos =0;
		if((pos = str.find(old_value,0))!=string::npos)
		{
			str.replace(pos,old_value.length(),new_value);
		}
		else
			break;
	}
}

