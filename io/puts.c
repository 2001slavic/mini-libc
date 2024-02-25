#include <internal/io.h>
#include <stdio.h>
#include <string.h>

#define EOF (-1)

int puts(const char * str)
{
    ssize_t ret = -1;
    size_t str_len = strlen(str);

    ret = write(1, str, str_len);
    if (ret < (ssize_t)str_len)
        return EOF;
    ret = write(1, "\n", 1);
    if (ret < 1)
        return EOF;
    return 0;
}
