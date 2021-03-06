#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include "./operate_config.h"

namespace operateconfig { class CConfig; }
namespace operateconfig { class File_not_found; }
namespace operateconfig { class Key_not_found; }

int main(void) {
	std::string temp;
	int port;
	std::string ipAddress;
	std::string username;
	std::string password;
	bool isCool = false;
	std::string TITLE_3V3;
	const char Config[] = "config.txt";

	// /Users/sakishum1118/MyCCpp/try_catch
	// 读配置文件，失败返回一个 异常类对象
	try {
		// Code that could throw an exception
		ConfigHandle.init(Config);
	} 
	catch (operatorconfig::File_not_found &filenf) {
		std::cerr << "**Warring: Attemped to open no exist file <" << filenf.filename << ">." << std::endl;
		return EXIT_FAILURE;
	}

	// 新增
	ConfigHandle.add("saki", "shum");

	// 获取
	temp = ConfigHandle.read("saki", temp);		// 读取整型
	port = ConfigHandle.read("port", 0);		// 读取字符串
	ipAddress = ConfigHandle.read("ipAddress", ipAddress);
	username = ConfigHandle.read("username", username);
	password = ConfigHandle.read("password", password);
	// 读取一个值，失败返回一个异常类对象
	try {
		isCool = ConfigHandle.read<bool>("isCool");		// 读取布尔值
	} catch (operatorconfig::Key_not_found &keynf) {
		std::cerr << "**Warrning: Attemped to vist no exist key <" << keynf.key << ">." << std::endl;
		return EXIT_FAILURE;
	}
	TITLE_3V3 = ConfigHandle.read("3V3_TITLE", TITLE_3V3);

	std::cout << "saki      :" << temp << std::endl;
	std::cout << "port      :" << port << std::endl;
	std::cout << "ipAddress :" << ipAddress << std::endl;
	std::cout << "username  :" << username << std::endl;
	std::cout << "password  :" << password << std::endl;
    if (isCool) { 
		printf("isCool    :Found isCool TRUE\n"); 
	} else {
		printf("isCool    :Found isCool FALSE\n");
	}
	std::cout << "TITLE_3V3 :" << TITLE_3V3 << std::endl;
	return EXIT_SUCCESS;
}
