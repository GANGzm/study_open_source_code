#ifndef SNPRINTF_H
#define SNPRINTF_H

#include <stdio.h>

typedef unsigned char      u8_t;
typedef char               s8_t;
typedef unsigned short     u16_t;
typedef short              s16_t;
typedef unsigned int       u32_t;
typedef int                s32_t;
typedef unsigned long long u64_t;
typedef long long          s64_t;

s32_t custom_snprintf(s8_t *str, size_t size, const s8_t *format, ...);

#endif 

