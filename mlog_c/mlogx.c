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
T_MlogKey *pKeyRoot = NULL;

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
 * mlogxFindKey
 * 功能描述:查找记录的KEY
 * 输入参数:
 * 输出参数:
 * 返回结果: 0-成功,其它-失败
 *
 * modification history
 * --------------------
 * 001, 2021-01-10 23:11:05,  written
 * --------------------
 ******************************************************************************/
T_MlogKey *mlogxFindKey(CHAR *pKey)
{
    T_MlogKey * pt =pKeyRoot;
    while (pt) {
        if (strcmp(pt->mName, pKey) == 0)
        {
            return pt;
        }
        pt = pt->pNext;
    }
    return NULL;
}

/******************************************************************************
 * mlogxInitKeyNode
 * 功能描述:初始化Key节点
 * 输入参数:
 * 输出参数:
 * 返回结果: 0-成功,其它-失败
 *
 * modification history
 * --------------------
 * 001, 2021-01-10 23:14:00,  written
 * --------------------
 ******************************************************************************/
T_MlogKey *mlogxInitKeyNode(CHAR *pKey)
{
    int iLen = 0;
    T_MlogKey *pKeyNode = (T_MlogKey *)malloc(sizeof(T_MlogKey));
    CHECK_POINTER_RET(pKeyNode, NULL);
    memset((void *)pKeyNode,0,sizeof(T_MlogKey));
    iLen = snprintf(pKeyNode->mName, sizeof(pKeyNode->mName),"%s", pKey);
    if(iLen < 0)
    {
        //TODO
    }
    return pKeyNode;
}

/******************************************************************************
 * mlogxInsertKeyNode
 * 功能描述:插入节点 MlogKey
 * 输入参数:
 * 输出参数:
 * 返回结果: 0-成功,其它-失败
 *
 * modification history
 * --------------------
 * 001, 2021-01-10 23:21:03,  written
 * --------------------
 ******************************************************************************/
T_MlogKey *mlogxInsertKeyNode(CHAR *pKey)
{
    T_MlogKey * pt =pKeyRoot;
    T_MlogKey *pKeyNode = mlogxFindKey(pKey);
    if(NULL != pKeyNode)
    {
        return pKeyNode;
    }
    pKeyNode = mlogxInitKeyNode(pKey);
    CHECK_POINTER_RET(pKeyNode, NULL);

    if(pt)
    {
        while (pt->pNext) {
            pt = pt->pNext;
        }
        pt->pNext = pKeyNode;
    }
    else
    {
        pKeyRoot = pKeyNode;
    }

    return pKeyNode;
}

/******************************************************************************
 * mlogxInsertLogNode2KeyNode
 * 功能描述:添加日志节点到KEY
 * 输入参数:
 * 输出参数:
 * 返回结果: 0-成功,其它-失败
 *
 * modification history
 * --------------------
 * 001, 2021-01-10 23:40:52,  written
 * --------------------
 ******************************************************************************/
int mlogxInsertLogNode2KeyNode(T_MlogKey *pMlogKey,T_MlogNode *pLogMsgNode)
{
    CHECK_POINTER_RET(pMlogKey, -1);
    CHECK_POINTER_RET(pLogMsgNode, -1);
    T_MlogNode *pt = pMlogKey->pHeader;
    if(pt)
    {
        while (pt->pNext) {
            pt = pt->pNext;
        }
        pt->pNext = pLogMsgNode;
    }
    else
    {
        pMlogKey->pHeader = pLogMsgNode;
    }
    return 0;
}

/******************************************************************************
 * mlogxShowKeys
 * 功能描述:显示Key列表
 * 输入参数:
 * 输出参数:
 * 返回结果: 0-成功,其它-失败
 *
 * modification history
 * --------------------
 * 001, 2021-01-10 23:31:32,  written
 * --------------------
 ******************************************************************************/
int mlogxShowKeys()
{
    int iNum = 0;
    T_MlogKey * pt = pKeyRoot;
    while (pt) {
        iNum++;
        printf("No:%3d, Name : %s\n", iNum, pt->mName);
        pt = pt->pNext;
    }
    return 0;
}

/******************************************************************************
 * mlogxShowKeysDetail
 * 功能描述:显示Key列表及下面的日志报文
 * 输入参数:
 * 输出参数:
 * 返回结果: 0-成功,其它-失败
 *
 * modification history
 * --------------------
 * 001, 2021-01-10 23:44:16,  written
 * --------------------
 ******************************************************************************/
int mlogxShowKeysDetail()
{
    int iNum = 0;
    int iSubNum = 0;
    T_MlogKey * pt = pKeyRoot;
    while (pt) {
        iNum++;
        printf("No:%3d, Name : %s\n", iNum, pt->mName);

        T_MlogNode *pLogMsgNode = pt->pHeader;
        while (pLogMsgNode) {
            iSubNum++;
            printf("  |-No:%4d, Log : %s\n", iSubNum, pLogMsgNode->pLog);
            pLogMsgNode = pLogMsgNode->pNext;
        }
        pt = pt->pNext;
    }
    return 0;
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
    T_MlogKey *pMlogKey = NULL;

    pMlogKey = mlogxInsertKeyNode(pKey);
    CHECK_POINTER_RET(pMlogKey, -1);

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

    mlogxInsertLogNode2KeyNode(pMlogKey, mlogxRecordLog(pBuf));
    va_end(args);
    FREENODE(pBuf);

    return 0;
}



#ifdef __cplusplus
}
#endif







