#include "ARC4.h"

#include <algorithm>
#include <cstring>

ARC4::ARC4(uint32 len) : _x(0), _y(0), _keyLen(len)
{
    std::memset(_state, 0, sizeof(_state));
}

ARC4::ARC4(uint8* seed, uint32 len) : _x(0), _y(0), _keyLen(len)
{
    std::memset(_state, 0, sizeof(_state));
    Setup(seed);
}

ARC4::~ARC4()
{
}

void ARC4::Init(uint8* seed)
{
    Setup(seed);
}

void ARC4::Setup(uint8* seed)
{
    _x = 0;
    _y = 0;

    for (uint32 i = 0; i < 256; ++i)
        _state[i] = static_cast<uint8>(i);

    uint8 j = 0;

    for (uint32 i = 0; i < 256; ++i)
    {
        j = static_cast<uint8>(j + _state[i] + seed[i % _keyLen]);
        std::swap(_state[i], _state[j]);
    }
}

void ARC4::UpdateData(int len, uint8* data)
{
    if (!data || len <= 0)
        return;

    for (int i = 0; i < len; ++i)
    {
        _x = static_cast<uint8>(_x + 1);
        _y = static_cast<uint8>(_y + _state[_x]);

        std::swap(_state[_x], _state[_y]);

        uint8 xorIndex = static_cast<uint8>(_state[_x] + _state[_y]);
        data[i] ^= _state[xorIndex];
    }
}