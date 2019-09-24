/*************************************************************************
	> File Name: wifi.cpp
	> Author: qiaoyuhu
	> Mail: yuhuqiao@163.com 
	> Created Time: 2019年09月02日 星期一 16时46分13秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include "tinyxml2.h"
using namespace std;
using namespace tinyxml2;

string WifiMsg ;
string name ;
string passwd;
string encrypt;
void read()
{
	XMLDocument doc;
	if(doc.LoadFile("WIFI.xml")!=0)
	{
		cout << "LOAD FILE ERROR" <<endl;
	}
	XMLElement *root = doc.RootElement();
	XMLElement *WIFI = root->FirstChildElement("WIFI");
	if(WIFI)
	{
		 encrypt = WIFI->FirstChildElement("encrypt")->GetText();
		passwd = WIFI->FirstChildElement("passwd")->GetText();
		name=  WIFI->FirstChildElement("name")->GetText();
	}
	else
		cout << "ERROR"<<endl;
}	

void show()
{
	cout << "name : "<<name <<endl;
	cout << "passwd : "<<passwd<<endl;
	cout << "encrypt : "<<encrypt<<endl;
}

int main()
{
	read();
	show();

}
