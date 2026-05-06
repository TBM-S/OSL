#include <stdio.h>
#include <stdlib.h>

int mutex = 1, full = 0, empty = 10, x = 0;

void producer() {
    --mutex; ++full; --empty;
    printf("Producer produces: item %d\n", ++x);
    ++mutex;
}

void consumer() {
    --mutex; ++empty; --full;
    printf("Consumer consumes: item %d\n", x--);
    ++mutex;
}

int main() {
    int n;
    printf("1. Producer\n2. Consumer\n3. Exit\n");
    while (1) {
        printf("Enter choice: "); scanf("%d", &n);
        switch (n) {
            case 1: mutex && empty ? producer() : printf("Buffer is full\n"); break;
            case 2: mutex && full  ? consumer() : printf("Buffer is empty\n"); break;
            case 3: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
