#include <cstdio>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <sys/time.h>
#include <vector>
#include <errno.h>

#define INVALID_FD -1

int main()
{
	/*
		1、创建socket，初始化，设置地址信息
		2、监听服务器地址
		3、while true中，初始化fd_set，将所有监听的客户端socket放进fd_set
		4、select
		5、分析select结果
	*/

	int listenFd = socket(AF_INET, SOCK_STREAM, 0);
	if (listenFd == INVALID_FD)
	{
		std::cout << "invalid socket, return -1" << std::endl;
		return -1;
	}

	struct sockaddr_in bindAddr;
	bindAddr.sin_family = AF_INET;
	bindAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	bindAddr.sin_port = htons(9000);

	if (bind(listenFd, (struct sockaddr*)&bindAddr, sizeof(bindAddr)) < 0)
	{
		std::cout << "bind addr failed, reutnr -1" << std::endl;
		close(listenFd);
		return -1;
	}

	if (listen(listenFd, SOMAXCONN) == -1)
	{
		std::cout << "listen failed, reutrn -1" << std::endl;
		close(listenFd);
		return -1;
	}

	std::vector<int> clientVec;
	int maxfd = 0;

	while (true)
	{
		fd_set fdSet;
		FD_ZERO(&fdSet);

		FD_SET(listenFd, &fdSet);
		maxfd = listenFd;
		
		for (int i = 0; i < clientVec.size(); i++)
		{
			if (clientVec[i] == INVALID_FD)
				continue;

			FD_SET(clientVec[i], &fdSet);
			if (maxfd < clientVec[i])
				maxfd = clientVec[i];
		}
		std::cout << "client size is:" << clientVec.size() << ",maxFd is:" << maxfd << std::endl;

		timeval tm;
		tm.tv_sec = 10;
		tm.tv_usec = 0;

		int ret = select(maxfd + 1, &fdSet, NULL, NULL, &tm);
		std::cout << "ret is:" << ret << std::endl;
		if (ret == -1)
		{
			if (errno != EINTR)
				break;
		}
		else if (ret == 0)
		{
			continue;
		}
		else
		{
			std::cout << "select respone" << std::endl;
			if (FD_ISSET(listenFd, &fdSet))
			{
				struct sockaddr_in clientAddr;
				socklen_t clientaddrlen = sizeof(clientAddr);

				int clientFd = accept(listenFd, (struct sockaddr*)&clientAddr, &clientaddrlen);
				if (clientFd == INVALID_FD)
					break;

				std::cout << "accept a client connection, fd: " << clientFd << std::endl;
				clientVec.push_back(clientFd);
			}
			else
			{
				char recvBuf[64];
				for (int i = 0; i < clientVec.size(); i++)
				{
					if (clientVec[i] != INVALID_FD && FD_ISSET(clientVec[i], &fdSet))
					{
						memset(recvBuf, 0, sizeof(recvBuf));
						int length = recv(clientVec[i], recvBuf, 64, 0);
						if (length <= 0)
						{
							std::cout << "recv data error,clientFd is: " << clientVec[i] << std::endl;
							close(clientVec[i]);
							clientVec[i] = INVALID_FD;
							continue;
						}
						std::cout << "clientfd: " << clientVec[i] << ", recv data is: " << recvBuf << std::endl;
					}
				}
			}
		}
	}

	for (int i = 0; i < clientVec.size(); i++)
	{
		if (clientVec[i] != INVALID_FD)
		{
			close(clientVec[i]);
		}
	}

	close(listenFd);

	return 0;
}