﻿#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "../FTPService/FtpClient.h"


int main()
{
	FtpClient client;
	client.connect("127.0.0.1");
	std::cout << "Conneted to remote server." << std::endl;
	while (true) {
		std::string command_str, local_file, remote_file;
		std::cin >> command_str;
		if (command_str == "get") {
			std::cin >> remote_file >> local_file;
			client.get(remote_file, local_file);
		}
		else if (command_str == "put") {
			std::cin >> local_file >> remote_file;
			client.put(local_file, remote_file);
		}
		else if (command_str == "pwd") {
			client.pwd();
		}
		else if (command_str == "cd") {
			std::string s;
			std::cin >> s;
			client.cd(s);
		}
		else if (command_str == "dir") {
			client.dir();
		}
		else if (command_str == "quit") {
			client.quit();
			break;
		}
		else {
			std::cout << "Bad command." << std::endl;
		}
	}
	return 0;
}
