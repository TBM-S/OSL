#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, total = 0;
    printf("Enter number of requests: "); scanf("%d", &n);
    int req[n];
    printf("Enter request queue:\n");
    for (int i = 0; i < n; i++) scanf("%d", &req[i]);
    printf("Enter initial head position: "); scanf("%d", &head);

    printf("\n===== FCFS Disk Scheduling =====\n");
    for (int i = 0; i < n; i++) {
        int d = abs(req[i] - head);
        printf("Move %d -> %d (Distance: %d)\n", head, req[i], d);
        total += d; head = req[i];
    }
    printf("Total Seek: %d | Avg: %.2f\n", total, (float)total / n);
    return 0;
}
