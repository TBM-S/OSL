#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid > 0) {
        printf("Parent PID: %d, Child PID: %d\n", getpid(), pid);
        printf("Parent sleeping 10s... (check: ps aux | grep Z)\n");
        sleep(10);
        printf("Parent exiting.\n");
    } else if (pid == 0) {
        printf("Child PID: %d, Parent PID: %d\nChild exiting (becomes zombie)...\n", getpid(), getppid());
        exit(0);
    } else {
        printf("Fork failed!\n");
        return 1;
    }
    return 0;
}
