#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid > 0) {
        printf("Parent PID: %d, Child PID: %d\nParent exiting...\n", getpid(), pid);
        exit(0);
    } else if (pid == 0) {
        printf("Child PID: %d, Parent PID: %d\n", getpid(), getppid());
        sleep(5);
        printf("Child woke up. New Parent (init): %d\nChild is now an orphan.\n", getppid());
    } else {
        printf("Fork failed!\n");
        return 1;
    }
    return 0;
}
