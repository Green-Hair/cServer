#ifndef __INCLIBS_H__
#define __INCLIBS_H__

#include "sqlite3.h"
#include "cJSON.h"
#include <winsock2.h>
#include <windows.h>
#include <process.h>

typedef signed char _i8;
typedef unsigned char _u8;
typedef signed short _i16;
typedef unsigned short _u16;
typedef signed int _i32;
typedef unsigned int _u32;
typedef signed long long _i64;
typedef unsigned long long _u64;
typedef char _c;
typedef char * _s;

typedef struct tagConfig
{
    _u16 port;
    _u32 max_conn;
    _u32 max_reg;
    _s server_name;
    _s server_description;
    SYSTEM_INFO si;
}Config;

typedef struct tagServer
{
    WSADATA wsaData;
    SOCKADDR_IN servAddr;
    SOCKET hServSock;
    HANDLE hIOCP;
    HANDLE *hWorkerThreads;
    HANDLE eServerRunning;
}Server;

_i32 LoadConfig(Config* config);
_i32 InitServer(Server* server,Config *config);
_i32 StartServer(Server* server);
_i32 StopServer(Server* server);
_i32 RestartServer(Server* server);


#endif