#pragma once

#include <sys/socket.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <regex.h>
#include <dirent.h>
#include <time.h>

#include "common.h"

#define VALUE_PORT 12345
#define VALUE_ROOT 54321

//字符串处理
void strreplace(char*sentence, char src, char dest);
void intToString(int n, char* s);
void convertToUpperCase(char* sentence);
void removeLineFeed(char* sentence);

int getIpFromPortMsg(char* param, char* clientIp);
int getPortFromPortMsg(char* param, int* pClientPort);
int getCommandFromSentence(char* sentence, char* command, char* parameter);
void getFileNameFromPath(char* fileName ,char* filePath);

void makeStartTransferMsg(char*startTransferMsg, char*fileName);
void makePasvPortMsg(char* pasvMsg, int pasvPort);
void makeAbsolutePath(char* filePath, char* rootPath, char* fineName);

//参数检查
int checkPassParam(char* param);
int checkPortParam(char* param);
int checkListParam(char* param);

//检查路径中是否包含../
int checkPath(char* path);

//信息传输
int recvSentence(int connfd, char* sentence);
int sendMsg(int connfd, char* sentence);
int recvFile(int connfd, char* fileName);
int sendFile(int connfd, char* fileName);
int sendDirectoryInfo(int fileConnfd, char* directoryPath, char* listData);
int sendFileInfo(int fileConnfd, char* filePath, char* fileName,char* listData);
int sendDirectoryInfoSimple(int fileConnfd, char* directoryPath, char* listData);
int sendFileInfoSimple(int fileConnfd, char* filePath, char* fileName,char* listData);
//socket相关
int createSocket();
int bindSocketToServer(int sockfd, int port);
int setSocketOption(int sockfd);
int startSocketListening(int sockfd, int maxQueueLength);
void closeSocket(int* pSockfd);
int sendConnectRequest(int sockfd, char* serverIp, int serverPort);

int getParamsFromCli(int argc, char**argv);
