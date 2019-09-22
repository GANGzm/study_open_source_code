#include <stdio.h>

#include "snprintf.h"

int main(int argc, const char *argv[])
{
	int ret;
	const char *str1 = argv[1];
	const char *str2 = argv[2];
	char buff[10] = {0};

	ret = custom_snprintf(buff, 10, "%s_%s", str1, str2);
	if(ret <= 0) {
		printf("ret=%d \n", ret);
		return 0;
	}
	
	printf("buff=<%s> ret=%d \n", buff, ret);

	return 0;
}


