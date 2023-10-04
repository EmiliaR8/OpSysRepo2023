#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[]){
    int start = uptime();
    printf("Time %d ticks\n", start);

    int rc = fork();
    if (rc < 0) {
        printf("fork failed\n");
        exit(1);
    } else if (rc == 0) {
    	argv = &argv[1];
	exec(argv[0], argv);
    } else {
	wait(0);	
    	int finish = uptime();
    	printf("Time %d ticks\n", finish-start);
    }
    exit(0);
}
