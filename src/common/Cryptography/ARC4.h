#ifndef _AUTH_SARC4_H
#define _AUTH_SARC4_H

#include "Define.h"

class TC_COMMON_API ARC4
{
public:
    ARC4(uint32 len);
    ARC4(uint8* seed, uint32 len);
    ~ARC4();

    void Init(uint8* seed);
    void UpdateData(int len, uint8* data);

private:
    void Setup(uint8* seed);

    uint8 _state[256];
    uint8 _x;
    uint8 _y;
    uint32 _keyLen;
};

#endif