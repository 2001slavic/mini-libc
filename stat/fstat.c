// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <errno.h>
#include <internal/syscall.h>

int fstat(int fd, struct stat *st)
{
	/* TODO: Implement fstat(). */

	// return fstatat(fd, "", st, AT_EMPTY_PATH);

	long res = syscall(__NR_fstat, fd, st);
	if (res < 0) {
		errno = -res;
		return -1;
	}
	return 0;
}
