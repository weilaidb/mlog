#ifndef DEFINEPUB_H
#define DEFINEPUB_H

#define CHECK_POINTER_RET(ptr, retcode) \
do{\
    if(NULL == ptr){\
        return retcode;\
    }\
}while(0)




#define CHECK_RET(op)\
do{\
    int iRet = (op);\
    if(iRet < 0)\
    {\
        mlogxByKey("CHECK_RET", "Error Happened!! Fun(%s) Line:%d ret:%d\n", __FUNCTION__, __LINE__, iRet);\
        return iRet;\
    }\
}while(0)




#endif // DEFINEPUB_H
