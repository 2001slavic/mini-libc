// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	void* mem = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (mem == MAP_FAILED)
		return NULL;
	mem_list_add(mem, size);
	return mem;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	void* mem = malloc(size * nmemb);
	if (!mem)
		return NULL;
	memset(mem, 0, size * nmemb);
	return mem;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	struct mem_list* mem = mem_list_find(ptr);
	if (!mem)
		return;
	munmap(mem->start, mem->len);
	mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	struct mem_list* mem = mem_list_find(ptr);
	if (!mem)
		return malloc(size);
	void* res = mremap(ptr, mem->len, size, 0);
	if (res == MAP_FAILED)
		return ptr;
	mem->len = size;
	return ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */

	return realloc(ptr, size * nmemb);
}
