// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <internal/syscall.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	/* TODO: Implement stat(). */

	// return fstatat(AT_FDCWD, path, buf, AT_EMPTY_PATH);
	long res = syscall(__NR_stat, path, buf);
	if (res < 0) {
		errno = -res;
		return -1;
	}
	return 0;
}
