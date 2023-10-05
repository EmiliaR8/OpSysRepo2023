#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/pstat.h"

uint
main(int argc, char *argv[]){
     struct rusage rus;
     int begin = uptime();
     printf("Time: %d Ticks\n", begin);
     int fork_child = fork();

     if(fork_child == 0){
     	argv = &argv[1];
	exec(argv[0], argv);
     }
     else{
     	wait2(0,&rus);
	int end = uptime();
	printf("elapsed time: %d cpu time: %d, cpu: %d", end-begin, rus.cputime * 100/end);
     }
     exit(0)

			

}
