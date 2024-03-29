/***************************************************************************
** 版权所有:  WeiLai Copyright (c) 2020-2030  ******************************
** 文件名称:  mlogx.h
** 当前版本:  v1.0
** 作    者:
** 完成日期: 2021-01-10_115227
** 修改记录:
** 修改记录:
** 修改日期:
** 版本号  :
** 修改人  :
** 修改内容:
***************************************************************************/
#ifndef __MLOGX_H__
#define __MLOGX_H__
/*****************************头文件****************************************/
#include  "basetype.h"
#include "definepub.h"

/*****************************宏定义****************************************/
#define MEMGET malloc
#define MEMPUT free
#define NAMEMAX (64)
//释放节点
#define FREENODE(ptr) \
do{\
    if(NULL != ptr)\
    {\
        MEMPUT(ptr);\
        ptr = NULL;\
    }\
}while(0)


/*****************************结构体或类型定义*******************************/
//节点 存储数据
typedef struct T_MlogNode {
    struct T_MlogNode *pNext;     /* next pointer */
    struct T_MlogNode *pPrev;     /* previous pointer */
    CHAR *pLog;     /* record logs */
    BYTE *pMsg;     /* record messages */
}T_MlogNode, *P_MlogNode;

//映射key
typedef struct T_MlogKey {
    struct T_MlogKey *pNext; /* next pointer */
    CHAR mName[NAMEMAX];
    T_MlogNode *pHeader;     /* record header */
}T_MlogKey, *P_MlogKey;


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
int mlogxShowKeys();
int mlogxShowKeysDetail();
int mlogxByKey(CHAR *pKey, const CHAR *fmt, ...);
int getStrOfData(CHAR *pTips, BYTE *pData, WORD16 wLen);
#ifdef __cplusplus
}
#endif





#endif /* mlogx.h */



