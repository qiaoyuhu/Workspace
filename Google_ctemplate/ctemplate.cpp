/*************************************************************************
  > File Name: ctemplate.cpp
  > Author: qiaoyuhu
  > Mail: yuhuqiao@163.com 
  > Created Time: 2019年10月08日 星期二 17时52分51秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string>
#include <dlfcn.h>
#include <google/template.h>

using namespace std;
int main()
{
	google::TemplateDictionary dict("example");
	dict.SetValue("table1_name", "example");

	for (int i=0; i<2; ++i)
	{
		google::TemplateDictionary* table1_dict;
		table1_dict = dict.AddSectionDictionary("TABLE1");
		table1_dict->SetValue("field1", "1");
		table1_dict->SetValue("field2", "2");

		// 这里有点类似于printf
		table1_dict->SetFormattedValue("field3", "%d", i);
	}

	std::string output;
	google::Template* tpl;
	tpl = google::Template::GetTemplate("example.html", google::DO_NOT_STRIP);
	tpl->Expand(&output, &dict);
	printf("%s\n", output.c_str());

	return 0;
}
