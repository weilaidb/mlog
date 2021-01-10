#include <stdio.h>
#include "mlogx.h"


int main()
{
    printf("Hello World!\n");
    WORD32 dwLp =  0;
    for(dwLp = 0;dwLp < 10;dwLp++)
    {
        CHECK_RET(mlogxByKey("test1", "world is goohello the world is goohello the world  %s %d\n", "nice day", dwLp));
        CHECK_RET(mlogxByKey("test1", "world is goohello the world is  %s %d", "nice day", dwLp));
    }

    CHECK_RET(mlogxByKey("test2", "hello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the worldhello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goo is goohello the world is goo %s %d\n", "nice day", 3000));
    CHECK_RET(mlogxByKey("test3", "hello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the worldhello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goohello the world is goo is goohello the world is goo %s %d\n", "nice day", 4000));
    mlogxShowKeys();
    mlogxShowKeysDetail();
    return 0;
}
