#pragma once

//服务器的回复字符串
extern char* startTransferPart;
extern char* typeMsg;
extern char* portMsg;
extern char* sysStatusMsg;
extern char* welcomeMsg;
extern char* goodbyeMsg;
extern char* fileSentMsg;
extern char* pasvMsgPart;
extern char* loginSuccessMsg;
extern char* mkdSuccessMsgPart;
extern char* rmdSuccessMsgPart;
extern char* cwdSuccessMsgPart;

extern char* requirePassMsg;

extern char* cannotConnectError;
extern char* noPortError;
extern char* networkError;

extern char* syntaxError;
extern char* typeError;
extern char* portSyntaxError;
extern char* unknownUserError;
extern char* invalidPathError;
extern char* noAvailablePortError;
extern char* notLoginError;
extern char* fileNotExistError;
extern char* mkdFailError;
extern char* rmdFailError;
extern char* cwdFailError;

//服务器的配置
extern int port; 
extern char* rootPath;
extern char* serverIp;