#pragma once

#ifdef USE_LOGGING
#include <stdio.h>
#define LOG(...) do { printf(__VA_ARGS__); fflush(stdout); } while (0)
#else
#define LOG(...) 
#endif

#define SYSDVR_CRASH_MODULEID 0x69

#define ERR_RTSP_VIDEO MAKERESULT(SYSDVR_CRASH_MODULEID, 1)
#define ERR_RTSP_AUDIO MAKERESULT(SYSDVR_CRASH_MODULEID, 2)
#define ERR_TCP_VIDEO MAKERESULT(SYSDVR_CRASH_MODULEID, 3)
#define ERR_TCP_AUDIO MAKERESULT(SYSDVR_CRASH_MODULEID, 4)
#define ERR_USB_VIDEO MAKERESULT(SYSDVR_CRASH_MODULEID, 5)
#define ERR_USB_AUDIO MAKERESULT(SYSDVR_CRASH_MODULEID, 6)
#define ERR_RTSP_MULTI_NAL MAKERESULT(SYSDVR_CRASH_MODULEID, 7)
#define ERR_AUDIO_BATCH_SIZE MAKERESULT(SYSDVR_CRASH_MODULEID, 8)

#define ERR_IPC_INVHEADER MAKERESULT(SYSDVR_CRASH_MODULEID, 9)
#define ERR_IPC_INVSIZE MAKERESULT(SYSDVR_CRASH_MODULEID, 10)
#define ERR_IPC_INVMAGIC MAKERESULT(SYSDVR_CRASH_MODULEID, 11)
#define ERR_IPC_NOCLIENT MAKERESULT(SYSDVR_CRASH_MODULEID, 12)
#define ERR_IPC_UNKCMD MAKERESULT(SYSDVR_CRASH_MODULEID, 13)

#define ERR_MAIN_UNKMODE MAKERESULT(SYSDVR_CRASH_MODULEID, 14)
#define ERR_MAIN_UNKMODESET MAKERESULT(SYSDVR_CRASH_MODULEID, 15)
#define ERR_MAIN_SWITCHING MAKERESULT(SYSDVR_CRASH_MODULEID, 16)
#define ERR_MAIN_NOTRUNNING MAKERESULT(SYSDVR_CRASH_MODULEID, 18)

#define ERR_DEV_BUFSIZECHECK MAKERESULT(SYSDVR_CRASH_MODULEID, 17)

#define ERR_HIPC_UNKREQ MAKERESULT(11, 403)

/*
Debugging socket crash:
	Error module: 0xAn where n depends on the caller of CreateTCPListener
	the description is the check that failed in AttemptOpenTCPListener
*/
#define ERR_SOCK_FAIL(flag, error) MAKERESULT(0xA0 | flag, error)
#define ERR_SOCK_RTSP_1 1
#define ERR_SOCK_RTSP_2 2
#define ERR_SOCK_TCP_1 3
#define ERR_SOCK_TCP_2 4
#define ERR_SOCK_CONFIG_1 5
#define ERR_SOCK_CONFIG_2 6

//This is a version for the SysDVR Config app protocol, it's not shown anywhere and not related to the major version
#define SYSDVR_VERSION 10
#define TYPE_MODE_USB 1
#define TYPE_MODE_TCP 2
#define TYPE_MODE_RTSP 4
#define TYPE_MODE_NULL 3
#define TYPE_MODE_SWITCHING 999998
#define TYPE_MODE_ERROR 999999

#define CMD_GET_VER 100
#define CMD_GET_MODE 101

#define MODE_TO_CMD_SET(x) x
#define CMD_SET_TO_MODE(x) x

// Aliases provided for readability, use macro to convert mode <-> cmd in case the values ever change
#define CMD_SET_USB MODE_TO_CMD_SET(TYPE_MODE_USB)
#define CMD_SET_TCP MODE_TO_CMD_SET(TYPE_MODE_TCP)
#define CMD_SET_RTSP MODE_TO_CMD_SET(TYPE_MODE_RTSP)
#define CMD_SET_OFF MODE_TO_CMD_SET(TYPE_MODE_NULL)