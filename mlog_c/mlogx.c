/***************************************************************************
** 版权所有:  WeiLai Copyright (c) 2020-2030  ******************************
** 文件名称:  mlogx
** 当前版本:  v1.0
** 作    者:
** 完成日期: 2021-01-10_115325
** 修改记录:
** 修改记录:
** 修改日期:
** 版本号  :
** 修改人  :
** 修改内容:
***************************************************************************/


/*****************************头文件****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include "basetype.h"
#include "definepub.h"
#include "mlogx.h"

/*****************************宏定  义****************************************/

/*****************************结构体或类型定义*******************************/


/*****************************全局变量****************************************/


/*****************************本地变量****************************************/


/*****************************函数或类声明****************************************/


/*****************************函数或类实现****************************************/


/*****************************by extern "C"****************************************/
/*****************************头文件****************************************/


/*****************************宏定义****************************************/


#ifdef __cplusplus
extern "C" {
#endif

/*****************************结构体或类型定义*******************************/


/*****************************全局变量****************************************/


/*****************************本地变量****************************************/


/*****************************函数或类声明****************************************/


/*****************************函数或类实现****************************************/
/******************************************************************************
 * mlogxInitLogNode
 * 功能描述:初始化日志节点
 * 输入参数:
 * 输出参数:
 * 返回结果: 0-成功,其它-失败
 *
 * modification history
 * --------------------
 * 001, 2021-01-10 17:26:39,  written
 * --------------------
 ******************************************************************************/
CHAR *mlogxInitLogNode(CHAR *pBuf)
{
    int iLen = 0;
    WORD32 dwLen = strlen(pBuf) + 1;
    CHAR *pLogNode = (CHAR *)malloc(dwLen);
    CHECK_POINTER_RET(pLogNode, NULL);
    memset((void *)pLogNode,0,dwLen);
    iLen = snprintf(pLogNode, dwLen, "%s", pBuf);
    if(iLen < 0)
    {
        return NULL;
    }

    return pLogNode;
}

/******************************************************************************
 * mlogxInitMsgNode
 * 功能描述:初始化报文节点
 * 输入参数:
 * 输出参数:
 * 返回结果: 0-成功,其它-失败
 *
 * modification history
 * --------------------
 * 001, 2021-01-10 17:26:57,  written
 * --------------------
 ******************************************************************************/
BYTE *mlogxInitMsgNode(BYTE *pMsg, WORD32 dwLen)
{
    BYTE *pMsgNode = (BYTE *)malloc(dwLen);
    CHECK_POINTER_RET(pMsgNode, NULL);
    memset((void *)pMsgNode,0,dwLen);
    memcpy(pMsgNode, pMsg, dwLen);

    return pMsgNode;
}

/******************************************************************************
 * mlogxInitNode
 * 功能描述:
 * 输入参数:
 * 输出参数:
 * 返回结果: 0-成功,其它-失败
 *
 * modification history
 * --------------------
 * 001, 2021-01-10 17:18:38,  written
 * --------------------
 ******************************************************************************/
T_MlogNode *mlogxInitNode()
{
    T_MlogNode *pNode = (T_MlogNode *)MEMGET(sizeof(T_MlogNode));
    CHECK_POINTER_RET(pNode, NULL);
    memset((void *)pNode,0,sizeof(T_MlogNode));

    return pNode;
}

/******************************************************************************
 * mlogxFreeNode
 * 功能描述:释放节点
 * 输入参数:
 * 输出参数:
 * 返回结果: 0-成功,其它-失败
 *
 * modification history
 * --------------------
 * 001, 2021-01-10 17:18:56,  written
 * --------------------
 ******************************************************************************/
T_MlogNode *mlogxFreeNode(T_MlogNode *pNode)
{
    FREENODE(pNode->pLog);
    FREENODE(pNode->pMsg);
    FREENODE(pNode);

    return pNode;
}

/******************************************************************************
 * mlogxRecordLogMsg
 * 功能描述:记录日志和报文
 * 输入参数:
 * 输出参数:
 * 返回结果: 0-成功,其它-失败
 *
 * modification history
 * --------------------
 * 001, 2021-01-10 17:19:47,  written
 * --------------------
 ******************************************************************************/
T_MlogNode *mlogxRecordLogMsg(CHAR *pBuf, BYTE *pMsg, WORD32 dwMsgLen)
{
    CHECK_POINTER_RET(pBuf, NULL);
    CHECK_POINTER_RET(pMsg, NULL);

    T_MlogNode *pNode = mlogxInitNode();
    CHECK_POINTER_RET(pNode, NULL);
    pNode->pLog = mlogxInitLogNode(pBuf);
    pNode->pMsg = mlogxInitMsgNode(pMsg, dwMsgLen);

    return pNode;
}

/******************************************************************************
 * mlogxRecordLog
 * 功能描述:记录日志
 * 输入参数:
 * 输出参数:
 * 返回结果: 0-成功,其它-失败
 *
 * modification history
 * --------------------
 * 001, 2021-01-10 17:34:07,  written
 * --------------------
 ******************************************************************************/
T_MlogNode *mlogxRecordLog(CHAR *pBuf)
{
    CHECK_POINTER_RET(pBuf, NULL);
    T_MlogNode *pNode = mlogxInitNode();
    CHECK_POINTER_RET(pNode, NULL);
    pNode->pLog = mlogxInitLogNode(pBuf);

    return pNode;
}

/******************************************************************************
 * mlogxRecordMsg
 * 功能描述:记录报文
 * 输入参数:
 * 输出参数:
 * 返回结果: 0-成功,其它-失败
 *
 * modification history
 * --------------------
 * 001, 2021-01-10 17:35:28,  written
 * --------------------
 ******************************************************************************/
T_MlogNode *mlogxRecordMsg(BYTE *pMsg, WORD32 dwMsgLen)
{
    CHECK_POINTER_RET(pMsg, NULL);

    T_MlogNode *pNode = mlogxInitNode();
    CHECK_POINTER_RET(pNode, NULL);
    pNode->pMsg = mlogxInitMsgNode(pMsg, dwMsgLen);

    return pNode;
}



/******************************************************************************
 * mlogxByKey
 * 功能描述:根据key来记录
 * 输入参数:
 * 输出参数:
 * 返回结果: 0-成功,其它-失败
 *
 * modification history
 * --------------------
 * 001, 2021-01-10 21:50:01,  written
 * --------------------
 ******************************************************************************/
int mlogxByKey(CHAR *pKey, const CHAR *fmt, ...)
{
#define LOGBUFMAX (128)

    int len = 0;
    va_list args;

    va_start(args, fmt);
    len = _vscprintf( fmt, args ) // _vscprintf doesn't count
            + 1;                  // terminating '\0'

    CHAR *pBuf = (CHAR *)MEMGET(len);
    CHECK_POINTER_RET(pBuf, -1);
    memset((void *)pBuf,0,len);
    len = vsnprintf(pBuf, len, fmt, args);
    if(len < 0)
    {
        return -2;
    }

    mlogxRecordLog(pBuf);
    va_end(args);
    FREENODE(pBuf);

    return 0;
}



#ifdef __cplusplus
}
#endif







