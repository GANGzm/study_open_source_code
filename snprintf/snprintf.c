#include <stdint.h>
#include <time.h>
#include <stdarg.h>

#include "snprintf.h"

#define SIZEOF_SIZE_T 4

#if (SIZEOF_SIZE_T == 4)
#define SSIZE_MAX INT32_MAX 
#elif (SIZEOF_SIZE_T == 8)
#define SSIZE_MAX INT64_MAX
#endif

#define SIZE_T_CEILING ((size_t) SSIZE_MAX - 16)

static s32_t custom_vsnprintf(s8_t *str, size_t size, const s8_t *format, va_list ap)
{
	s32_t ret;
	
	if(size == 0)
		return -1;

	if(size > SIZE_T_CEILING)
		return -2;

	ret = vsnprintf(str, size, format, ap);
	str[size-1] = '\0';

	if(ret < 0)
		return -3;

	// vsnprintf 返回值为没有截断的字符串长度
	if(ret >= (ssize_t)size)
		return 0;

	return ret;
}

s32_t custom_snprintf(s8_t *str, size_t size, const s8_t *format, ...)
{
	va_list ap;
	s32_t ret;

	va_start(ap, format);
	ret = custom_vsnprintf(str, size, format, ap);
	va_end(ap);

	return ret;
}



