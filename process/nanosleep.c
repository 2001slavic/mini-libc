#include <time.h>
#include <internal/syscall.h>
#include <errno.h>

int nanosleep(const struct timespec *req, struct timespec *rem) {
    long res = syscall(__NR_nanosleep, req, rem);
    if (res < 0) {
        errno = -res;
        return -1;
    }
    return 0;
}
