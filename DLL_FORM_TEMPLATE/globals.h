#ifndef _GLOBALS_
#define _GLOBALS_

#pragma once
#pragma managed( push, off )
#pragma warning( disable: 4996 )

#define VC_EXTRALEAN
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <iostream>
#include <fstream>
#include <Tlhelp32.h>
#include <detours.h>
#include <WinSock2.h>
#include <inaddr.h>
#include <mbstring.h>
#include <mswsock.h>
#include <shellapi.h>

#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "Ws2_32.lib")

#include "resource.h"
#include "xor.h"

#pragma managed( pop )

#endif