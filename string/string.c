// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	char* tmp_dst = destination;
	while (*source != 0) {
		*tmp_dst = *source;
		tmp_dst++;
		source++;
	}
	*tmp_dst = 0; // null-terminating string

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	long unsigned int chars_written = 0;
	long unsigned int i = 0;
	while (i < len) {
		if (source[i] == 0) {
			// destination padding with zeros
			long unsigned int j = i;
			while (chars_written <= len) {
				destination[j] = 0;
				chars_written++;
				j++;
			}
			break;
		}
		destination[i] = source[i];
		chars_written++;
		i++;
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	char* tmp_dst = destination;
	while (*tmp_dst != 0)
		tmp_dst++;
	strcpy(tmp_dst, source);

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	char* tmp_dst = destination;
	while (*tmp_dst != 0)
		tmp_dst++;
	long unsigned int i = 0;

	while (i < len && source[i] != 0) {
		*tmp_dst = source[i];
		tmp_dst++;
		i++;
	}
	*tmp_dst = 0;

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	int res = 0;
	while (!(*str1 == 0 && *str2 == 0)) {
		res = *str1 - *str2;
		if (res != 0)
			break;

		str1++;
		str2++;
	}
	return res;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	int res = 0;
	for (unsigned long int i = 0; i < len; i++) {
		res = str1[i] - str2[i];
		if (res != 0)
			break;
	}
	return res;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	while (*str != 0) {
		if (*str == c)
			return (char*)str;
		str++;
	}

	return c == 0 ? (char*)str : NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	char* res = NULL;
	while (*str != 0) {
		if (*str == c)
			res = (char*)str;
		str++;
	}

	if (c == 0)
		res = (char*)str;

	return res;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	size_t needle_len = strlen(needle);
	while (*haystack != 0) {
		if (!strncmp(haystack, needle, needle_len))
			return (char*)haystack;
		haystack++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	char* res = NULL;
	size_t needle_len = strlen(needle);
	while (*haystack != 0) {
		if (!strncmp(haystack, needle, needle_len))
			res = (char*)haystack;
		haystack++;
	}
	return res;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	for (unsigned long int i = 0; i < num; i++)
		((char*)destination)[i] = ((char*)source)[i];

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	memcpy(destination, source, num);

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	int res = 0;
	for (unsigned long int i = 0; i < num; i++) {
		res = ((char*)ptr1)[i] - ((char*)ptr2)[i];
		if (res != 0)
			return res;
	}
	return res;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	for (unsigned long int i = 0; i < num; i++)
		((unsigned char*)source)[i] = value;

	return source;
}
