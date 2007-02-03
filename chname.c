#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <string.h>
#include <errno.h>

#ifndef CLONE_NEWUTS
	#define CLONE_NEWUTS	0x04000000
#endif

void usage() {
	fprintf(stderr, "Usage: chname <hostname> <program> [args]\n");
}

int main(int argc, char** argv) {

	if (argc < 3) {
		usage();
		exit(1);
	}

	// Use 'syscall' instead of unshare incase glibc doesn't have it.
	// unshare(CLONE_NEWUTS);
	if (syscall(__NR_unshare, CLONE_NEWUTS)) {
		fprintf(stderr, "chname: New utsname namespace failed: %s\n", strerror(errno));
		exit(1);
	}

	if (sethostname(argv[1], strlen(argv[1])+1)) {
		fprintf(stderr, "chname: Set hostname failed: %s\n", strerror(errno));
		exit(1);
	}

	execvp(argv[2], &argv[2]);
	fprintf(stderr, "chname: exec failed: %s\n", strerror(errno));
	return 1;
}
