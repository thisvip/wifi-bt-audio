/*
********************************************************************************************
*
*        Copyright (c): Fuzhou Rockchip Electronics Co., Ltd
*                             All rights reserved.
*
* FileName: App\music\media_update.c
* Owner: ctf
* Date: 2015.9.16
* Time:
* Version: 1.0
* Desc:
* History:
*    <author>    <date>       <time>     <version>     <Desc>
*     ctf      2015.9.16                    1.0
********************************************************************************************
*/


#include "BspConfig.h"
#ifdef __APP_MEDIA_UPDATE_C__


/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   #include define
*
*---------------------------------------------------------------------------------------------------------------------
*/
#define NOT_INCLUDE_OTHER
#include "typedef.h"
#include "RKOS.h"
#include "Bsp.h"
#include "global.h"
#include "SysInfoSave.h"
#include "TaskPlugin.h"
#include "device.h"
#include "ModuleInfoTab.h"
#include "FwAnalysis.h"
#include "PowerManager.h"
#include "media_update.h"
#include "MsgDevice.h"

/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   #define / #typedef define
*
*---------------------------------------------------------------------------------------------------------------------
*/



/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   local variable define
*
*---------------------------------------------------------------------------------------------------------------------
*/


/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   global variable define
*
*---------------------------------------------------------------------------------------------------------------------
*/



/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   local function declare
*
*---------------------------------------------------------------------------------------------------------------------
*/



/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   API(common) define
*
*---------------------------------------------------------------------------------------------------------------------
*/

/*******************************************************************************
** Name: media_update
** Input:
** Return:
** Owner:ctf
** Date: 2016.1.26
** Time: 18:00:52
*******************************************************************************/
_APP_MEDIA_UPDATE_COMMON_
COMMON FUN void UpdateMediaLibray(void)
{
    FREQ_EnterModule(FREQ_MEDIAUPDATA);

    MainTask_SetTopIcon(MAINTASK_SYS_MEDIA_UPDATE);

    FW_LoadSegment(SEGMENT_ID_FILEINFO_SAVE, SEGMENT_OVERLAY_ALL);
    SearchAndSaveMusicInfo();
    FW_RemoveSegment(SEGMENT_ID_FILEINFO_SAVE);

    FW_LoadSegment(SEGMENT_ID_FILEINFO_SORT, SEGMENT_OVERLAY_ALL);
    SortUpdateFun(&(gSysConfig.MedialibPara), gSysConfig.MediaLibrayStartLBA);
    FW_RemoveSegment(SEGMENT_ID_FILEINFO_SORT);

    gSysConfig.MedialibPara.MediaUpdataFlag = 0;

    MainTask_DeleteTopIcon(MAINTASK_SYS_MEDIA_UPDATE);

    FREQ_ExitModule(FREQ_MEDIAUPDATA);

    RKTaskDelete(TASK_ID_MEDIA_UPDATE, 0, ASYNC_MODE);




}

/*******************************************************************************
** Name: MediaUpdate_Enter
** Input:void
** Return: void
** Owner:ctf
** Date: 2015.9.16
** Time:
*******************************************************************************/
_APP_MEDIA_UPDATE_COMMON_
COMMON API void MediaUpdate_Enter(void)
{
    UpdateMediaLibray();

    while(1)
    {
        rkos_sleep(10000);
        rk_printf("delete media update task");
    }
}

/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   local function(common) define
*
*---------------------------------------------------------------------------------------------------------------------
*/



/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   API(init) define
*
*---------------------------------------------------------------------------------------------------------------------
*/
/*******************************************************************************
** Name: MediaUpdate_DeInit
** Input:void *pvParameters
** Return: rk_err_t
** Owner:ctf
** Date: 2015.9.16
** Time:
*******************************************************************************/
_APP_MEDIA_UPDATE_INIT_
INIT API rk_err_t MediaUpdate_DeInit(void *pvParameters)
{
    return RK_SUCCESS;
}
/*******************************************************************************
** Name: MediaUpdate_Init
** Input:void *pvParameters, void *arg
** Return: rk_err_t
** Owner:ctf
** Date: 2015.9.16
** Time:
*******************************************************************************/
_APP_MEDIA_UPDATE_INIT_
INIT API rk_err_t MediaUpdate_Init(void *pvParameters, void *arg)
{
    return RK_SUCCESS;
}

/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   local function(init) define
*
*---------------------------------------------------------------------------------------------------------------------
*/



/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   API(shell) define
*
*---------------------------------------------------------------------------------------------------------------------
*/



/*
*---------------------------------------------------------------------------------------------------------------------
*
*                                                   local function(shell) define
*
*---------------------------------------------------------------------------------------------------------------------
*/


#endif
